#pragma once
#include "controller.h"
//#include <vector>

using namespace glm;
class WaypointController : public Controller{
public:
	// Constructor sets the position of the object,
	// the axis about which it will rotate, and the rate and direction
	// of rotation.
	WaypointController( vector<vec3> wps, GLfloat r);
	virtual void update(float elapsedTimeSeconds);
	GLfloat distanceToTargetWaypoint();
	int getNextWaypointIndex();
	void updateVeolcityForWaypoint();
protected:
	// Position at which the object is spinning in place
	vec3 position;
	GLint waypointNum;
	vector<vec3> waypoints;
	vec3 velocity;
	// rate and direction of rotation
	GLfloat speed; 
};