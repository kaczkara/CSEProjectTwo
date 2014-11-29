#include "SnowMan.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Cube.h"

SnowMan::SnowMan( ): VisualObject(  ){
	VisualObject* base = new Sphere( 0.45f);
	base->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));
	base->material.setAmbientAndDiffuseMat(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	this->addChild( base );

	VisualObject* body = new Sphere(0.30f);
	body->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, .70f, 0.0f));
	body->material.setAmbientAndDiffuseMat(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	this->addChild(body);

	VisualObject* head = new Sphere(0.20f);
	head->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, 1.15f, 0.0f));
	body->material.setAmbientAndDiffuseMat(vec4(1.0f, 1.0, 1.0f, 1.0f));
	this->addChild(head);

} // end SnowMan constructor

void SnowMan::setShader( GLuint shaderProgram ) 
{ 
	for (unsigned int i = 0; i < children.size(); i++) {

		children[i]->setShader(shaderProgram);
	}
}


