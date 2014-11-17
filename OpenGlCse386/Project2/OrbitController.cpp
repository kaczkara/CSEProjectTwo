#include "OrbitController.h"

OrbitController::OrbitController(vec3 pos, vec3 oAx, vec3 tAx, GLfloat r){

	position=pos;
	orbitAxis=oAx;
	tumbleAxis=tAx;
	rate=r;
}
void OrbitController::update(float elapsedTimeSeconds){
	static float rotation = 0.0f;
	rotation += elapsedTimeSeconds * rate;
	target->modelMatrix=rotate(translate(rotate(mat4(1.0f),-1*fmod(rotation, 360.0f),orbitAxis),position),fmod(rotation, 360.0f),tumbleAxis);
}