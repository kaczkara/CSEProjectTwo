#pragma once
#include "visualobject.h"
using namespace glm;
class Light : public VisualObject {
public:
	Light(vec4 color, float size);
	void setShader( GLuint shaderProgram );
};
