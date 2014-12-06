#include "WaypointController.h"
#include <vector>

WaypointController::WaypointController( vector<vec3> wps, GLfloat r){
	//waypoints.size= wps.size();
	waypoints=wps;
	speed=r;
	waypointNum=0;
	position=waypoints.at(0);
	velocity=vec3(0.0f, 0.0f, 0.0f);//*speed;
	updateVeolcityForWaypoint();
}
GLfloat WaypointController::distanceToTargetWaypoint(){
	if(waypointNum+1<waypoints.size()){
		vec3 tmp =waypoints.at(waypointNum+1)-position;
		return dot(tmp,tmp);
	}
	vec3 tmp =waypoints.at(0)-position;
	return dot(tmp,tmp);
}
int WaypointController::getNextWaypointIndex(){
	if(waypointNum+1<waypoints.size()){
		waypointNum++;
		return waypointNum;//+1;
	}
	waypointNum=0;
	return 0;
}
void WaypointController::updateVeolcityForWaypoint(){
	if(waypointNum+1<waypoints.size()){
		//waypointNum++;
		velocity = normalize(waypoints.at(waypointNum+1)-position)*speed;
	}else{
		//waypointNum=0;
		velocity = normalize(waypoints.at(0)-position)*speed;
	}
	//waypointNum=getNextWaypointIndex();
	//velocity = vec3(1.0f, 0.0f, 0.0f)*speed;
}
void WaypointController::update(float elapsedTimeSeconds){
	if ( distanceToTargetWaypoint() < (speed * elapsedTimeSeconds)) {
		position = waypoints[getNextWaypointIndex()];
		//updateVeolcityForWaypoint();
	}
	updateVeolcityForWaypoint();
	position = position + velocity * elapsedTimeSeconds;
	target->modelMatrix = translate(mat4(1.0f), position);
} // end update
