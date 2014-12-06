#include "ChristmasTree.h"
#include "Cone.h"
#include "Ornament.h"
#include "Light.h"
#include "Cylinder.h"

ChristmasTree::ChristmasTree() {
	VisualObject* trunk = new Cylinder(.2f, 0.1f);
	trunk->fixedTransformation = rotate(translate(mat4(1.0f), vec3(0.0f,0.0f,0.0f)),90.0f,vec3(1.0,0.0,0.0));
	trunk->material.setAmbientAndDiffuseMat(vec4(0.4f, 0.2f, 0.0f, 1.0f));
	trunk->material.setSpecularMat(vec4(0.0f, 0.0f, 0.0f, 0.0f));
	trunk->material.setEmissiveMat(vec4(0.2f, 0.2f, 0.2f, 0.5f));
	this->addChild(trunk); 
	
	VisualObject* base = new Cone( 2.0f);
	base->fixedTransformation = rotate(translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f)), -90.0f, vec3(1.0f, 0.0f, 0.0f));
	base->material.setAmbientAndDiffuseMat(vec4(0.0f, 0.6f, 0.0f, 1.0f));
	base->material.setSpecularMat(vec4(0.0f,0.0f,0.0f,0.0f));
	base->material.setEmissiveMat(vec4(.8f, 1.0f, 0.8f, 0.5f));
	this->addChild(base);

	VisualObject* lightbulb = new Light(vec4(1.0f, 1.0f, .5f, 1.0f), .05f);
	lightbulb->modelMatrix = translate(mat4(1.0f), vec3(0.0f, 2.0f, 0.0f));
	this->addChild(lightbulb);

	VisualObject* ornament = new Ornament(glm::vec4(1.0f, 0.0f, 0.0f, 0.4f), 0.1f);
	ornament->modelMatrix=translate(mat4(1.0f), vec3(0.0f, 1.5f ,0.1f));
	this->addChild(ornament);

	VisualObject* ornament2 = new Ornament(glm::vec4(1.0f, 1.0f, 0.0f, 0.4f), 0.1f);
	ornament2->modelMatrix=translate(mat4(1.0f), vec3(0.0f, 1.0f ,0.24f));
	this->addChild(ornament2);

	VisualObject* ornament3 = new Ornament(glm::vec4(1.0f, 0.0f, 1.0f, 0.4f), 0.1f);
	ornament3->modelMatrix=translate(mat4(1.0f), vec3(.3f, 0.8f ,0.0f));
	this->addChild(ornament3);

	VisualObject* ornament4 = new Ornament(glm::vec4(0.0f, 0.0f, 1.0f, 0.4f), 0.1f);
	ornament4->modelMatrix=translate(mat4(1.0f), vec3(0.15f, 1.3f ,0.0f));
	this->addChild(ornament4);

}


void ChristmasTree::setShader( GLuint shaderProgram ) 
{ 
	for (unsigned int i = 0; i < children.size(); i++) {

		children[i]->setShader(shaderProgram);
	}
}
