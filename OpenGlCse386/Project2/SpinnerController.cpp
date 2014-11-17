#include "SpinnerController.h"

SpinnerController::SpinnerController( vec3 pos, vec3 ax, GLfloat r ){
	position=pos;
	axis=ax;
	rate=r;
}

void SpinnerController::update(float elapsedTimeSeconds){
	static float rotation = 0.0f;
	rotation += elapsedTimeSeconds * rate;
	target->modelMatrix = rotate( translate(mat4(1.0f),position), fmod(rotation, 360.0f),axis); 
}