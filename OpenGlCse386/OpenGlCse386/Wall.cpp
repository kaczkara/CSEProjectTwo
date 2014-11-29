#include "Wall.h"
#include "vertexStructs.h"


Wall::Wall( float height, float width, int rows, int columns)
	: VisualObject(), height(height), width(width), rows(rows), columns(columns)
{

}


Wall::~Wall(void)
{
} 

void Wall::setShaderValues()
{
	// This program will stay in effect for all draw calls until it is 
	// replaced with another or explicitly disabled (and the 
	// fixed function pipeline is enabld) by calling glUseProgram with NULL
    glUseProgram(shaderProgram);

	modelLocation = glGetUniformLocation(shaderProgram, "modelMatrix");
	assert(modelLocation != 0xFFFFFFFF);

	material.setUpMaterial( getUniformLocation( shaderProgram, "object.ambientMat"),
						 getUniformLocation( shaderProgram, "object.diffuseMat"),
						 getUniformLocation( shaderProgram, "object.specularMat"),
						 getUniformLocation( shaderProgram, "object.specularExp"),
						 getUniformLocation( shaderProgram, "object.emissiveMat" ),
						 getUniformLocation( shaderProgram, "object.textureMapped") );

}


// Construct visual object display list.
void Wall::initialize()
{
	setShaderValues();

	// vector containers to hold  data
	vector<pntVertexData> v; // vertex positions
	vector<unsigned int> indices; // indices
	GLuint VBO, IBO; // Identifiers for buffer objects

	vec3 n = vec3( 0.0f, 0.0f, 1.0f);

	vec3 v0 = vec3( -width/2, 0.0f, 0.0f); 
	vec3 v1 = vec3( width/2, 0.0f, 0.0f); 
	vec3 v2 = vec3( width/2, height, 0.0f); 
	vec3 v3 = vec3( -width/2, height, 0.0f); 

	vec2 t0 = vec2(-width/2, -height/2);
	vec2 t1 = vec2( width/2, -height/2);
	vec2 t2 = vec2( width/2, height/2);
	vec2 t3 = vec2( -width/2, height/2);

	v.push_back( pntVertexData( v0, n, t0) ); // 0
	v.push_back( pntVertexData( v1, n, t1) ); // 1
	v.push_back( pntVertexData( v2, n, t2) ); // 2
	v.push_back( pntVertexData( v3, n, t3) ); // 3

	indices.push_back( 0 );
	indices.push_back( 1 );
	indices.push_back( 2 );
	indices.push_back( 0 );
	indices.push_back( 2 );
	indices.push_back( 3 );

	glGenVertexArrays (1, &vertexArrayObject);
	glBindVertexArray( vertexArrayObject );

	// Create the buffer to hold interleaved data and bind the data to them
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // Buffer for vertex data
	glBufferData(GL_ARRAY_BUFFER, v.size() * sizeof(pntVertexData), &v[0], GL_STATIC_DRAW); //Buffering vertex data

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(pntVertexData), 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(pntVertexData), (const GLvoid*)sizeof(vec3) );
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(pntVertexData), (const GLvoid*)(2 * sizeof(vec3)) );
	glEnableVertexAttribArray(3);

	// Generate a buffer for the indices
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0] , GL_STATIC_DRAW);

	// store the number of indices for later use
	indiceCount = indices.size();
 
	v.clear();
	indices.clear();

	VisualObject::initialize();

} // end initialize

// Preform drawing operations
void Wall::draw()
{
	glUseProgram(shaderProgram);

	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, value_ptr(modelAndFixed));

	material.setShaderMaterialProperties();

	// Draw wall
	glBindVertexArray(vertexArrayObject);
    glDrawElements(GL_TRIANGLES, indiceCount, GL_UNSIGNED_INT, 0);

	// Draw all children
	VisualObject::draw();

} // end draw
