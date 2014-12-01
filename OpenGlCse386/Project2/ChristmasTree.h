#pragma once
#include "visualobject.h"
class ChristmasTree :
	public VisualObject
{
public:
	ChristmasTree(void);
	virtual void setShader( GLuint shaderProgram );
};

