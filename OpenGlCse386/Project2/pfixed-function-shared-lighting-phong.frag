// Specifying version of GLSL. If the compiler does not support 
// this version of higher, an error will occur.
#version 330

#pragma optimize(off)
#pragma debug(on)

// Declare default precision - eliminates warnings (but can cause an error on some machines)
precision mediump float;

// Structure for holding general light properties
struct GeneralLight {
  
	vec4 ambientColor;		// ambient color of the light
	vec4 diffuseColor;		// diffuse color of the light
    vec4 specularColor;		// specular color of the light

	// Either the position or direction
	// if w = 0 then the light is directional and direction specified 
	// is the negative of the direction the light is shinning
	// if w = 1 then the light is positional
    vec4 positionOrDirection;    
					  
	// spotlight attributes
    vec3 spotDirection;		// the direction the cone of light is shinning    
	int isSpot;				// 1 if the light is a spotlight  
    float spotCutoffCos;	// Cosine of the spot cutoff angle
    float spotExponent;		// For gradual falloff near cone edge

	// attenuation coefficients
    float constant; 
    float linear;
    float quadratic;

	int enabled;			// 1 if light is "on"

};

// Structure for material properties
struct Material {
	vec4 ambientMat;

	vec4 diffuseMat;

	vec4 specularMat;

	float specularExp;

	vec4 emissiveMat;

	bool textureMapped;
};

const int MaxLights = 8;

layout (std140) uniform LightBlock {
 GeneralLight lights[MaxLights];
};


uniform Material object;
// Sampler to determine interpolated texture coordinates for the fragment
uniform sampler2D gSampler;

layout (std140) uniform worldEyeBlock
{
	vec3 worldEyePosition;
};

// Vertex attributes passed in by the vertex shader
in vec2 TexCoord0;
in vec3 Normal0;
in vec3 WorldPos0;

// Output color for the fragment (pixel)
out vec4 FragColor;

vec4 calcSpot (GeneralLight spLight, Material object){
	vec4 totalSpotLight = vec4(0.0f,0.0f,0.0f,1.0f);
	vec3 LightToPixel = normalize(WorldPos0 - spLight.positionOrDirection.xyz); 
	float spotCosFactor = dot(LightToPixel, spLight.spotDirection); 
	if( spotCosFactor > spLight.spotCutoffCos ) {
		vec3 directionToSpotLight = - LightToPixel;
		// Diffuse
		float DiffuseFactor = max(dot(Normal0, directionToSpotLight), 0.0f); 
		vec4 diffuseTerm = DiffuseFactor * object.diffuseMat * spLight.diffuseColor;
		// Specular
		vec3 VertexToEye = normalize(worldEyePosition - WorldPos0);
		vec3 LightReflect = normalize(reflect(-directionToSpotLight, Normal0));
		float SpecularFactor = max(dot(VertexToEye, LightReflect), 0.0f);
		SpecularFactor = pow(SpecularFactor, object.specularExp);
		vec4 specularTerm = SpecularFactor * object.specularMat * spLight.specularColor; 
		totalSpotLight = diffuseTerm + specularTerm;
		// Traditional method for attenuating illumination
		// near the edges of the cone
		//float falloff = pow( spotCosFactor, 50.0f );
		// Alternative method for attenuating illumination
		// near the edges of the cone
		float falloff = 1.0f - (1.0f - spotCosFactor) /(1.0f - spLight.spotCutoffCos);
		totalSpotLight = falloff * totalSpotLight;
	}
	
	return totalSpotLight;
}

vec4 calcDir(GeneralLight directLight, Material object) {
	vec4 totalDirectionLight = vec4(0.0f,0.0f,0.0f,1.0f);
	// Diffuse
	float DiffuseFactor = max(dot(Normal0, directLight.positionOrDirection.xyz),0.0f);
	totalDirectionLight = DiffuseFactor * object.diffuseMat * directLight.diffuseColor;
	// Specular
	vec3 VertexToEye = normalize(worldEyePosition - WorldPos0);
	vec3 LightReflect = normalize( reflect(-directLight.positionOrDirection.xyz, Normal0));
	float SpecularFactor = max(dot(VertexToEye, LightReflect), 0.0f);
	SpecularFactor = pow( SpecularFactor, object.specularExp);
	vec4 specularTerm = SpecularFactor * object.specularMat * directLight.specularColor;
	totalDirectionLight += specularTerm;

	return totalDirectionLight;
}

vec4 calcPos (GeneralLight posLight, Material object){
	vec4 totalPositionalLight = vec4(0.0f,0.0f,0.0f,1.0f);
	// Point Light
	// Find a unit vector that points at the 
	// light source
	vec3 directionToPosLight = normalize(posLight.positionOrDirection.xyz - WorldPos0 );
	// Diffuse
	float DiffuseFactor = max(dot(Normal0, directionToPosLight), 0.0f); 
	vec4 diffuseTerm = DiffuseFactor *  object.diffuseMat * posLight.diffuseColor;
	// Specular
	vec3 VertexToEye = normalize(worldEyePosition - WorldPos0);
	vec3 LightReflect = normalize( reflect(-directionToPosLight, Normal0) );
	float SpecularFactor = max( dot( VertexToEye, LightReflect ), 0.0f);
	SpecularFactor = pow(SpecularFactor, object.specularExp);
	vec4 specularTerm = SpecularFactor * object.specularMat * posLight.specularColor;
	totalPositionalLight = diffuseTerm + specularTerm; 
	return totalPositionalLight;
}

vec4 calcLight( GeneralLight light, Material object)
{
	vec4 totalLight = vec4(0.0f,0.0f,0.0f,1.0f);
	if(light.enabled == 1){
		if(light.isSpot ==1){
		 totalLight += calcSpot(light, object);
		} else if (light.positionOrDirection.w == 0) {
			totalLight +=  calcDir(light, object);
		} else {
			totalLight += calcPos(light, object);
		}
		totalLight += object.ambientMat * light.ambientColor;
	}
	
	return totalLight;
}

const vec4 fogColor = vec4(0.0f, 0.0f, 0.0f, 0.0f);
const float fogEnd = 20.0f;
const float fogStart = 1.0f;
const float fogDensity = 0.1f;
float distanceFromViewPoint;
float linearFogFactor() {
	distanceFromViewPoint = distance(worldEyePosition, WorldPos0);
	return max((fogEnd - distanceFromViewPoint)/(fogEnd - fogStart), 0.0f);
}
float exponentialFogFactor() {
	distanceFromViewPoint = distance(worldEyePosition, WorldPos0);
	return exp( -(fogDensity * distanceFromViewPoint));
}
float exponentialTwoFogFactor() {
	distanceFromViewPoint = distance(worldEyePosition, WorldPos0);
	return exp( - pow((fogDensity * distanceFromViewPoint),2));
}

void main() {
	Material texturedMaterial = object;
	if (object.textureMapped == true) {
		texturedMaterial.ambientMat = texture2D(gSampler, TexCoord0.st);
		texturedMaterial.diffuseMat = texture2D(gSampler, TexCoord0.st);
		texturedMaterial.specularMat = texture2D(gSampler, TexCoord0.st);
	}
	FragColor = object.emissiveMat;

	for (int i = 0; i < MaxLights; i++)  {
	
		FragColor += calcLight( lights[i], texturedMaterial);
	}
	float fogFactor =  linearFogFactor();
	FragColor = fogFactor * FragColor + (1-fogFactor) * fogColor;
	FragColor.a = object.diffuseMat.a;
}