#pragma once
#include "controller.h"
using namespace glm;
class OrbitController :public Controller{
public:
	OrbitController(vec3 pos = vec3(0.0f, 0.0f, 0.0f), vec3 oAx = vec3(1.0f, 0.0f, 0.0f), vec3 tAx = vec3(1.0f,0.0f,0.0f),GLfloat r = 10.0f);
	virtual void update(float elapsedTimeSeconds);
protected:
	// Position at which the object is spinning in place
	vec3 position; 
	// axis of rotation
	vec3 orbitAxis; 
	vec3 tumbleAxis;
	// rate and direction of rotation
	GLfloat rate; 
};

