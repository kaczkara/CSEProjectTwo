#ifndef ___PYRAMID_H___
#define ___PYRAMID_H___

#include "VisualObject.h"
#include "BuildShaderProgram.h"

class Pyramid : public VisualObject {
public:

	/**
	* Constructor for the Pyramid class. Created a visual object in the shape of a pyramid. Vertex
	* positions are expressed relative to an origin that is located in the center of the pyramid.
	* @param OpenGLApp - reference to the OpenGLApplicationBase object that holds the projection
	*        and viewing transformations
	* @param w - width of the base of the pyramid. Default is 1 unit.
	* @param h - height of the pyramid. Default is 1 unit.
	*/
	Pyramid( GLfloat w = 1.0f, GLfloat h = 1.0f);

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
	void setShaderValues();

protected:

	int numberOfIndices; // number of indices to be used during indexed rendering.

	GLfloat height; // height for the pyramid
	GLfloat width; // width for the pyramid

};

#endif // ___PYRAMID_H___