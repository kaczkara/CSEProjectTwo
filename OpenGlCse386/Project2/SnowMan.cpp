#include "SnowMan.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cone.h"

SnowMan::SnowMan( ): VisualObject(  ){
	VisualObject* base = new Sphere( 0.5f);
	base->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, 0.0f, 0.0f));
	base->material.setAmbientAndDiffuseMat(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	this->addChild( base );

	VisualObject* body = new Sphere(0.35f);
	body->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, .75f, 0.0f));
	body->material.setAmbientAndDiffuseMat(vec4(1.0f, 1.0f, 1.0f, 1.0f));
	this->addChild(body);

	// VisualObject* 
	/*VisualObject * fuselage = new Cylinder( 4.0f);
	fuselage->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, 0.0f, -2.0f));
	fuselage->material.setAmbientAndDiffuseMat(vec4( 0.1f, 0.1, 0.9f, 1.0f)); 
	this->addChild( fuselage );

	VisualObject * nose = new Cone();
	nose->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, 0.0f, 2.0f));
	nose->material.setAmbientAndDiffuseMat(vec4( 1.0f, 1.0, 0.0f, 1.0f)); 
	this->addChild(nose);

	VisualObject * engine = new Cone();
	engine->fixedTransformation = translate(mat4(1.0f), vec3(1.0f, 0.0f, -2.0f));
	engine->material.setAmbientAndDiffuseMat(vec4( 1.0f, 1.0, 0.0f, 1.0f)); 
	this->addChild(engine);

	VisualObject * engine2 = new Cone();
	engine2->fixedTransformation = translate(mat4(1.0f), vec3(-1.0f, 0.0f, -2.0f));
	engine2->material.setAmbientAndDiffuseMat(vec4( 1.0f, 1.0, 0.0f, 1.0f)); 
	this->addChild(engine2);

	VisualObject * bubble = new Sphere( 0.5f);
	bubble->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, 0.5f, 0.0f));
	bubble->material.setAmbientAndDiffuseMat(vec4( 1.0f, 0.0, 0.0f, 1.0f)); 
	this->addChild(bubble);
	*/
} // end SnowMan constructor

void SnowMan::setShader( GLuint shaderProgram ) 
{ 
	for (unsigned int i = 0; i < children.size(); i++) {

		children[i]->setShader(shaderProgram);
	}
}


