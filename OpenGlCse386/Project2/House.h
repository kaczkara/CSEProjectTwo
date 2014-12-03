#pragma once
#include "visualobject.h"
class House :
	public VisualObject
{
public:
	House(vec4 color);
	virtual void setShader( GLuint shaderProgram );
};

