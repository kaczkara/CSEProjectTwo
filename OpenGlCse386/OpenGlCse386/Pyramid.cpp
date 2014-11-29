#include "Pyramid.h"
#include "Material.h"
#include "vertexStructs.h"
#include "textureCoordinates.h"

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
	vec3 faceNormal = findUnitNormal(v4, v3, v0);
	vec3 rightFace = findUnitNormal(v4, v0, v1);
	vec3 backFace = findUnitNormal(v4, v1, v2);
	vec3 leftFace = findUnitNormal(v4, v2, v3);
	vec3 bottom = vec3(0.0f, -1.0f, 0.0f);

	vector<pntVertexData> norms;	
	/*front*/
	norms.push_back(pntVertexData(v4, faceNormal, getPlanarTextCoords(v4, width, height)));
	norms.push_back(pntVertexData(v3, faceNormal, getPlanarTextCoords(v3, width, height)));
	norms.push_back(pntVertexData(v0, faceNormal, getPlanarTextCoords(v0, width, height)));
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	/*right*/
	norms.push_back(pntVertexData(v4, rightFace, getPlanarTextCoords(v4, width, height)));
	norms.push_back(pntVertexData(v0, rightFace, getPlanarTextCoords(v0, width, height)));
	norms.push_back(pntVertexData(v1, rightFace, getPlanarTextCoords(v1, width, height)));
	indices.push_back(3);
	indices.push_back(4);
	indices.push_back(5);
	/*left*/
	norms.push_back(pntVertexData(v4, leftFace, getPlanarTextCoords(v4, width, height)));
	norms.push_back(pntVertexData(v2, leftFace, getPlanarTextCoords(v2, width, height)));
	norms.push_back(pntVertexData(v3, leftFace, getPlanarTextCoords(v3, width, height)));
	indices.push_back(6);
	indices.push_back(7);
	indices.push_back(8);
	/*back*/
	norms.push_back(pntVertexData(v4, backFace, getPlanarTextCoords(v4, width, height)));
	norms.push_back(pntVertexData(v1, backFace, getPlanarTextCoords(v1, width, height)));
	norms.push_back(pntVertexData(v2, backFace, getPlanarTextCoords(v2, width, height)));
	indices.push_back(9);
	indices.push_back(10);
	indices.push_back(11);
	/*bottom*/
	norms.push_back(pntVertexData(v0, backFace, getPlanarTextCoords(v0, width, height)));
	norms.push_back(pntVertexData(v1, backFace, getPlanarTextCoords(v1, width, height)));
	norms.push_back(pntVertexData(v2, backFace, getPlanarTextCoords(v2, width, height)));
	norms.push_back(pntVertexData(v3, backFace, getPlanarTextCoords(v3, width, height)));
	indices.push_back(12);
	indices.push_back(14);
	indices.push_back(13);

	indices.push_back(14);
	indices.push_back(12);
	indices.push_back(15);
	/**/
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, norms.size() * sizeof(pntVertexData), &norms[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(pntVertexData), 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(pntVertexData),(const GLvoid*)sizeof(vec3));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(pntVertexData), (const GLvoid*)(2 * sizeof(vec3)) );
	glEnableVertexAttribArray(3);

	numberOfIndices = indices.size(); 

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	indices.clear();
	norms.clear();

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