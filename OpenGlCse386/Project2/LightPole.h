#pragma once
#include "visualobject.h"
class LightPole : public VisualObject {
public:
	LightPole(void);
	virtual void setShader( GLuint shaderProgram );
};

