#pragma once
#include "visualobject.h"
class SnowMan :
	public VisualObject
{
public:
	SnowMan(void);
	virtual void setShader( GLuint shaderProgram );
};

