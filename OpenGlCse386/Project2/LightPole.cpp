#include "LightPole.h"
#include "Cylinder.h"
#include "Sphere.h"

LightPole::LightPole(void) {
	VisualObject* pole = new Cylinder(1.0f, 0.05f);
	pole->fixedTransformation = rotate(translate(mat4(1.0f), vec3(0.0f,1.0f,0.0f)),90.0f,vec3(1.0,0.0,0.0));
	pole->material.setAmbientAndDiffuseMat(vec4(0.0f, 0.0f, 0.0f, 1.0f));
	this->addChild(pole); 

	VisualObject* top = new Sphere();
	top->fixedTransformation = translate(mat4(1.0f), vec3(0.0, 1.5, 0.0f));
	top->material.setAmbientAndDiffuseMat(vec4(1.0f, 1.0f, 0.0f, 0.2f));
	this->addChild(top);
}


void LightPole::setShader( GLuint shaderProgram ) 
{ 
	for (unsigned int i = 0; i < children.size(); i++) {

		children[i]->setShader(shaderProgram);
	}
}
