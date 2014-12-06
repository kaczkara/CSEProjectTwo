#include "Ornament.h"
#include "Sphere.h"

Ornament::Ornament(vec4 color, float size){
	VisualObject* ornament = new Sphere( size);
	ornament->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, 0.0f, 4.0f));
	ornament->material.setAmbientAndDiffuseMat(color);
	ornament->material.setEmissiveMat(color);
	this->addChild(ornament);
}

void Ornament::setShader( GLuint shaderProgram ) 
{ 
	for (unsigned int i = 0; i < children.size(); i++) {

		children[i]->setShader(shaderProgram);
	}
}