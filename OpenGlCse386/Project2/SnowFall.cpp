#include "SnowFall.h"
#include "Sphere.h"
#include "WaypointController.h"

SnowFall::SnowFall(float rate) {

	vector<glm::vec3> wp1;
	wp1.push_back(vec3(-0.7f, 2.5f, 0.0f));
	wp1.push_back(vec3(-0.7f, -6.2f, 2.0f));

	VisualObject* flake1 = new Sphere(.1f);
	flake1->fixedTransformation = translate(mat4(1.0f), vec3(-0.7f, 2.0f, 0.0f));
	flake1->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake1->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake1->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake1->addController(new WaypointController(wp1, rate));
	this->addChild(flake1);

	vector<glm::vec3> wp2;
	wp2.push_back(vec3(-2.0f, 3.0f, 2.0f));
	wp2.push_back(vec3(-0.5f, -6.2f, 2.0f));

	VisualObject* flake2 = new Sphere(.1f);
	flake2->fixedTransformation = translate(mat4(1.0f), vec3(-2.0f, 2.0f, 2.0f));
	flake2->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake2->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake2->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake2->addController(new WaypointController(wp2, rate));
	this->addChild(flake2);

	vector<glm::vec3> wp3;
	wp3.push_back(vec3(0.0f, 3.5f, -2.0f));
	wp3.push_back(vec3(0.0f, -6.2f, 2.0f));

	VisualObject* flake3 = new Sphere(.1f);
	flake3->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, 2.0f, -2.0f));
	flake3->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake3->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake3->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake3->addController(new WaypointController(wp3, rate));
	this->addChild(flake3);

	vector<glm::vec3> wp4;
	wp4.push_back(vec3(2.0f, 4.0f, 1.0f));
	wp4.push_back(vec3(0.5f, -6.2f, 2.0f));

	VisualObject* flake4 = new Sphere(.1f);
	flake4->fixedTransformation = translate(mat4(1.0f), vec3(2.0f, 2.0f, 1.0f));
	flake4->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake4->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake4->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake4->addController(new WaypointController(wp4, rate));
	this->addChild(flake4);

	vector<glm::vec3> wp5;
	wp5.push_back(vec3(0.7f, 4.5f, -3.0f));
	wp5.push_back(vec3(0.7f, -6.2f, 2.0f));

	VisualObject* flake5 = new Sphere(.1f);
	flake5->fixedTransformation = translate(mat4(1.0f), vec3(0.7f, 2.0f, -3.0f));
	flake5->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake5->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake5->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake5->addController(new WaypointController(wp5, rate));
	this->addChild(flake5);

	vector<glm::vec3> wp6;
	wp6.push_back(vec3(-0.7f, 5.0f, 2.0f));
	wp6.push_back(vec3(-0.7f, -6.2f, 2.0f));

	VisualObject* flake6 = new Sphere(.1f);
	flake6->fixedTransformation = translate(mat4(1.0f), vec3(-0.7f, 4.0f, -1.0f));
	flake6->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake6->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake6->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake6->addController(new WaypointController(wp6, rate));
	this->addChild(flake6);

	vector<glm::vec3> wp7;
	wp7.push_back(vec3(-0.5f, 6.0f, 2.0f));
	wp7.push_back(vec3(-0.5f, -6.2f, 2.0f));

	VisualObject* flake7 = new Sphere(.1f);
	flake7->fixedTransformation = translate(mat4(1.0f), vec3(-2.0f, 4.0f, -1.0f));
	flake7->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake7->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake7->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake7->addController(new WaypointController(wp7, rate));
	this->addChild(flake7);

	vector<glm::vec3> wp8;
	wp8.push_back(vec3(0.0f, 6.5f, 2.0f));
	wp8.push_back(vec3(0.0f, -6.2f, 2.0f));

	VisualObject* flake8 = new Sphere(.1f);
	flake8->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, 4.0f, 3.0f));
	flake8->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake8->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake8->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake8->addController(new WaypointController(wp8, rate));
	this->addChild(flake8);

	vector<glm::vec3> wp9;
	wp9.push_back(vec3(0.5f, 7.0f, 2.0f));
	wp9.push_back(vec3(0.5f, -6.2f, 2.0f));

	VisualObject* flake9 = new Sphere(.1f);
	flake9->fixedTransformation = translate(mat4(1.0f), vec3(2.0f, 4.0f, 3.0f));
	flake9->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake9->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake9->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake9->addController(new WaypointController(wp9, rate));
	this->addChild(flake9);

	vector<glm::vec3> wp10;
	wp10.push_back(vec3(0.7f, 7.5f, 2.0f));
	wp10.push_back(vec3(0.7f, -6.2f, 2.0f));

	VisualObject* flake10 = new Sphere(.1f);
	flake10->fixedTransformation = translate(mat4(1.0f), vec3(0.7f, 4.0f, -2.0f));
	flake10->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake10->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake10->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake10->addController(new WaypointController(wp10, rate));
	this->addChild(flake10);

	vector<glm::vec3> wp11;
	wp11.push_back(vec3(0.7f, 8.0f, 2.0f));
	wp11.push_back(vec3(0.7f, -6.2f, 2.0f));

	VisualObject* flake11 = new Sphere(.1f);
	flake11->fixedTransformation = translate(mat4(1.0f), vec3(0.7f, 2.0f, -3.0f));
	flake11->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake11->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake11->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake11->addController(new WaypointController(wp11, rate));
	this->addChild(flake11);

	vector<glm::vec3> wp12;
	wp12.push_back(vec3(-0.7f, 8.5f, 2.0f));
	wp12.push_back(vec3(-0.7f, -6.2f, 2.0f));

	VisualObject* flake12 = new Sphere(.1f);
	flake12->fixedTransformation = translate(mat4(1.0f), vec3(-0.7f, 4.0f, -1.0f));
	flake12->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake12->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake12->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake12->addController(new WaypointController(wp12, rate));
	this->addChild(flake12);

	vector<glm::vec3> wp13;
	wp13.push_back(vec3(-0.5f, 9.0f, 2.0f));
	wp13.push_back(vec3(-0.5f, -6.2f, 2.0f));

	VisualObject* flake13 = new Sphere(.1f);
	flake13->fixedTransformation = translate(mat4(1.0f), vec3(-2.0f, 4.0f, -1.0f));
	flake13->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake13->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake13->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake13->addController(new WaypointController(wp13, rate));
	this->addChild(flake13);

	vector<glm::vec3> wp14;
	wp14.push_back(vec3(0.0f, 9.5f, 2.0f));
	wp14.push_back(vec3(0.0f, -6.2f, 2.0f));

	VisualObject* flake14 = new Sphere(.1f);
	flake14->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, 4.0f, 3.0f));
	flake14->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake14->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake14->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake14->addController(new WaypointController(wp14, rate));
	this->addChild(flake14);

	vector<glm::vec3> wp15;
	wp15.push_back(vec3(0.5f, 10.0f, 2.0f));
	wp15.push_back(vec3(0.5f, -6.2f, 2.0f));

	VisualObject* flake15 = new Sphere(.1f);
	flake15->fixedTransformation = translate(mat4(1.0f), vec3(2.0f, 4.0f, 3.0f));
	flake15->material.setAmbientAndDiffuseMat(vec4(.8f, .8f, .9f, 1.0f));
	flake15->material.setEmissiveMat(vec4(.8f, .8f, .9f, .8f));
	flake15->material.setSpecularMat(vec4(1.0f, 1.0f, 1.0f, .8f));
	flake15->addController(new WaypointController(wp15, rate));
	this->addChild(flake15);
}

void SnowFall::setShader( GLuint shaderProgram ) 
{ 
	for (unsigned int i = 0; i < children.size(); i++) {

		children[i]->setShader(shaderProgram);
	}
}
