#include "SnowMan.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Cube.h"

SnowMan::SnowMan( ): VisualObject(  ){
	VisualObject* base = new Sphere( 0.225f);
	base->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));
	base->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	base->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	base->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	this->addChild(base);

	VisualObject* body = new Sphere(0.15f);
	body->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, .30f, 0.0f));
	body->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	body->material.setEmissiveMat(vec4(.8f, .8f, .9f, 1.0f));
	this->addChild(body);

	VisualObject* head = new Sphere(0.10f);
	head->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, 0.50f, 0.0f));
	head->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	head->material.setEmissiveMat(vec4(.8f, .8f, .9f, 1.0f));
	this->addChild(head);

} // end SnowMan constructor

void SnowMan::setShader( GLuint shaderProgram ) 
{ 
	for (unsigned int i = 0; i < children.size(); i++) {

		children[i]->setShader(shaderProgram);
	}
}


