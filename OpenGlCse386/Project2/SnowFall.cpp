#include "SnowFall.h"
#include "Sphere.h"
#include "WaypointController.h"

SnowFall::SnowFall(float rate) {

	vector<glm::vec3> wp1;
	wp1.push_back(vec3(-0.7f, 3.0f, 2.0f));
	wp1.push_back(vec3(-0.7f, -6.2f, 2.0f));

	VisualObject* flake1 = new Sphere(.1f);
	flake1->fixedTransformation = translate(mat4(1.0f), vec3(-0.7f, 3.0f, 2.0f));
	flake1->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake1->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake1->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake1->addController(new WaypointController(wp1, rate));
	this->addChild(flake1);

	vector<glm::vec3> wp2;
	wp2.push_back(vec3(-0.5f, 3.0f, 2.0f));
	wp2.push_back(vec3(-0.5f, -6.2f, 2.0f));

	VisualObject* flake2 = new Sphere(.1f);
	flake2->fixedTransformation = translate(mat4(1.0f), vec3(-2.0f, 3.0f, 2.0f));
	flake2->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake2->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake2->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake2->addController(new WaypointController(wp2, rate));
	this->addChild(flake2);

	vector<glm::vec3> wp3;
	wp3.push_back(vec3(0.0f, 3.0f, 2.0f));
	wp3.push_back(vec3(0.0f, -6.2f, 2.0f));

	VisualObject* flake3 = new Sphere(.1f);
	flake3->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, 3.0f, 2.0f));
	flake3->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake3->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake3->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake3->addController(new WaypointController(wp3, rate));
	this->addChild(flake3);

	vector<glm::vec3> wp4;
	wp4.push_back(vec3(0.5f, 3.0f, 2.0f));
	wp4.push_back(vec3(0.5f, -6.2f, 2.0f));

	VisualObject* flake4 = new Sphere(.1f);
	flake4->fixedTransformation = translate(mat4(1.0f), vec3(2.0f, 3.0f, 2.0f));
	flake4->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake4->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake4->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake4->addController(new WaypointController(wp4, rate));
	this->addChild(flake4);

	vector<glm::vec3> wp5;
	wp5.push_back(vec3(0.7f, 3.0f, 2.0f));
	wp5.push_back(vec3(0.7f, -6.2f, 2.0f));

	VisualObject* flake5 = new Sphere(.1f);
	flake5->fixedTransformation = translate(mat4(1.0f), vec3(0.7f, 3.0f, 2.0f));
	flake5->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake5->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake5->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake5->addController(new WaypointController(wp5, rate));
	this->addChild(flake5);

}

void SnowFall::setShader( GLuint shaderProgram ) 
{ 
	for (unsigned int i = 0; i < children.size(); i++) {

		children[i]->setShader(shaderProgram);
	}
}