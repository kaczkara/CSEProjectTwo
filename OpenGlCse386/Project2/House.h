#ifndef ___House_H___
#define ___House_H___

#include "visualobject.h"

class House : public VisualObject
{
	public:
		House(vec4 color);

	protected:
		virtual void setShader( GLuint shaderProgram );
};

#endif // ___House_H___