#ifndef ___Ornament_H___
#define ___Ornament_H___

#include "visualobject.h"

class Ornament : public VisualObject
{
	public:
		Ornament(vec4 color, float size);

	protected:
		virtual void setShader( GLuint shaderProgram );
};

#endif // ___Ornament_H___