#include "Pyramid.h"
#include "Material.h"
#include "vertexStructs.h"

Pyramid::Pyramid( GLfloat w, GLfloat h){
	width=w;
	height=h;
	numberOfIndices=18;
}

void Pyramid::initialize(){
	setShaderValues();
	vec3 v0, v1, v2, v3, v4;

	GLuint VBO, IBO;

	glGenVertexArrays (1, &vertexArrayObject); 
	glBindVertexArray( vertexArrayObject );

	vector<pncVertexData> v;
	vector<unsigned int> indices;

	// define the colors
	vec4 c0= vec4( 1.0f, 0.5f, 0.5f, 1.0f );
	vec4 c1= vec4( 1.0f, 1.0f, 0.0f, 1.0f );
	vec4 c2= vec4( 0.0f, 0.5f, 1.0f, 1.0f );
	vec4 c3= vec4( 1.0f, 0.0f, 1.0f, 1.0f );
	vec4 c4= vec4( 0.0f, 1.0f, 1.0f, 1.0f);

	v0 = vec3(width/2, -height/2, width/2);
	v1 = vec3(width/2, -height/2, -width/2);
	v2 = vec3(-width/2, -height/2, -width/2);
	v3 = vec3(-width/2, -height/2, width/2);
	v4 = vec3(0.0f, height/2, 0.0f);

	// Front face
	vec3 frontFaceNormal = findUnitNormal(v4, v3, v0);
	vec3 rightFace = findUnitNormal(v4, v0, v1);
	vec3 backFace = findUnitNormal(v4, v1, v2);
	vec3 leftFace = findUnitNormal(v4, v2, v3);
	vec3 bottom = vec3(0.0f, -1.0f, 0.0f);

	/*front*/
	v.push_back(pncVertexData(v4, frontFaceNormal, c0));
	v.push_back(pncVertexData(v3, frontFaceNormal, c0));
	v.push_back(pncVertexData(v0, frontFaceNormal, c0));
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	/*right*/
	v.push_back(pncVertexData(v4, rightFace, c1));
	v.push_back(pncVertexData(v0, rightFace, c1));
	v.push_back(pncVertexData(v1, rightFace, c1));
	indices.push_back(3);
	indices.push_back(4);
	indices.push_back(5);
	/*left*/
	v.push_back(pncVertexData(v4, leftFace, c2));
	v.push_back(pncVertexData(v2, leftFace, c2));
	v.push_back(pncVertexData(v3, leftFace, c2));
	indices.push_back(6);
	indices.push_back(7);
	indices.push_back(8);
	/*back*/
	v.push_back(pncVertexData(v4, backFace, c3));
	v.push_back(pncVertexData(v1, backFace, c3));
	v.push_back(pncVertexData(v2, backFace, c3));
	indices.push_back(9);
	indices.push_back(10);
	indices.push_back(11);
	/*bottom*/
	v.push_back(pncVertexData(v0, bottom, c4));
	v.push_back(pncVertexData(v1, bottom, c4));
	v.push_back(pncVertexData(v2, bottom, c4));
	v.push_back(pncVertexData(v3, bottom, c4));
	indices.push_back(12);
	indices.push_back(14);
	indices.push_back(13);

	indices.push_back(14);
	indices.push_back(12);
	indices.push_back(15);
	/**/
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, v.size() * sizeof(pncVertexData), &v[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(pncVertexData), 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(pncVertexData),(const GLvoid*)(sizeof(vec3) * 2));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(pncVertexData),(const GLvoid*)sizeof(vec3));
	glEnableVertexAttribArray(1);

	numberOfIndices = indices.size(); 

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	v.clear();
	indices.clear();

	VisualObject::initialize();

}

void Pyramid::draw(){
	glUseProgram(shaderProgram);
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, value_ptr(modelAndFixed));
	glBindVertexArray( vertexArrayObject );
	material.setShaderMaterialProperties();
	glDrawElements( GL_TRIANGLES, numberOfIndices, GL_UNSIGNED_INT,0);
	VisualObject::draw();
}

void Pyramid::setShaderValues(){
	glUseProgram(shaderProgram);
	modelLocation = glGetUniformLocation(shaderProgram, "modelMatrix");
	assert(modelLocation != 0xFFFFFFFF);

	material.setUpMaterial( getUniformLocation( shaderProgram, "object.ambientMat"),
		getUniformLocation( shaderProgram, "object.diffuseMat"),
		getUniformLocation( shaderProgram, "object.specularMat"),
		getUniformLocation( shaderProgram, "object.specularExp"),
		getUniformLocation( shaderProgram, "object.emissiveMat" ),
		getUniformLocation( shaderProgram, "object.textureMapped"));
}