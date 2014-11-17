#ifndef ___CUBE_H___
#define ___CUBE_H___

#include "VisualObject.h"

class Cube : public VisualObject
{
	public:

		/**
		 * Constructor for the Cube class. Created a visual object in the shape of a cube. Vertex
		 * positions are expressed relative to an origin that is located in the center of the cube.
		 * @param OpenGLApp - reference to the OpenGLApplicationBase object that holds the projection
		 *        and viewing transformations
		 * @param w - width of the cube. Default is 1 unit.
		 */
		Cube( GLfloat w = 1.0f, GLfloat h = 1.0f, GLfloat d = 1.0f );

		/**
		 * Builds shader program and initializes vertex array object that will be used to render the 
		 * the object.
		 */
		virtual void initialize();

		/*
		 * Renders the object using the visual object using the vertex array object that was created by
		 * the initialize method.
		 */
		virtual void draw();

	protected:

		/**
		 * Builds the shader program.
		 */
		void setShaderValues();
		
		int numberOfIndices; // number of indices to be used during indexed rendering.
		
		GLuint ShaderProgram; // Identifier for the shader program

		const GLfloat width; // width for the cube
		const GLfloat height;
		const GLfloat depth;

};

#endif // ___CUBE_H___