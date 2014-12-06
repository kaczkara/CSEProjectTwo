#include "SnowFall.h"
#include "Sphere.h"

SnowFall::SnowFall(float rate) {

	VisualObject* flake = new Sphere(.1);

}

void SnowFall::setShader( GLuint shaderProgram ) 
{ 
	for (unsigned int i = 0; i < children.size(); i++) {

		children[i]->setShader(shaderProgram);
	}
}