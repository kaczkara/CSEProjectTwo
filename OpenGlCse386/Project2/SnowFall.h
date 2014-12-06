#ifndef ___SnowFall_H___
#define ___SnowFall_H___

#include "visualobject.h"

class SnowFall : public VisualObject
{
	public:
		SnowFall(float rate);

	protected:
		virtual void setShader( GLuint shaderProgram );
};

#endif // ___SnowFall_H___