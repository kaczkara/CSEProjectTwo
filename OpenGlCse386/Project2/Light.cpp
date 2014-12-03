#include "Light.h"
#include "Sphere.h";
using namespace glm;
Light::Light(vec4 color, float size) {
	VisualObject* light = new Sphere(size);
	light->material.setAmbientAndDiffuseMat(color);
	light->material.setEmissiveMat(color);
	light->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));
	this->addChild(light);
}

void Light::setShader( GLuint shaderProgram )  { 
	for (unsigned int i = 0; i < children.size(); i++) {

		children[i]->setShader(shaderProgram);
	}
}