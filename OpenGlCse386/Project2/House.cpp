#include "House.h"
#include "Wall.h"
#include "Pyramid.h"

House::House(vec4 color) {

	// Front Wall Front
	VisualObject* wall1 = new Wall(4.0f, 6.0f); 
	wall1->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, -3.0f, -2.0f)); 
	wall1->material.setAmbientAndDiffuseMat(vec4(0.0f, 0.0f, 1.0f, 1.0f));
	wall1->material.setEmissiveMat(vec4(0.0f, 0.0f, 1.0f, 1.0f));
	addChild(wall1);

	// Front Wall Back
	VisualObject* wall2 = new Wall(4.0f, 6.0f);  
	wall2->fixedTransformation = rotate(translate(mat4(1.0f), vec3(0.0f, -3.0f, -2.0f)), 180.0f, vec3(0.0f, 1.0f, 0.0f)); 
	wall2->material.setAmbientAndDiffuseMat(color);
	wall2->material.setEmissiveMat(color);
	addChild(wall2);

	// Left Wall Front
	VisualObject* wall3 = new Wall(4.0f, 6.0f); 
	wall3->fixedTransformation = rotate(translate(mat4(1.0f), vec3(-3.0f, -3.0f, -5.0f)), -90.0f, vec3(0.0f, 1.0f, 0.0f)); 
	wall3->material.setAmbientAndDiffuseMat(color);
	wall3->material.setEmissiveMat(color);
	addChild(wall3);

	// Left Wall Back
	VisualObject* wall4 = new Wall(4.0f, 6.0f); 
	wall4->fixedTransformation = rotate(translate(mat4(1.0f), vec3(-3.0f, -3.0f, -5.0f)), 90.0f, vec3(0.0f, 1.0f, 0.0f)); 
	wall4->material.setAmbientAndDiffuseMat(color);
	wall4->material.setEmissiveMat(color);
	addChild(wall4);

	//// Right Wall Front
	VisualObject* wall5 = new Wall(4.0f, 6.0f); 
	wall5->fixedTransformation = rotate(translate(mat4(1.0f), vec3(3.0f, -3.0f, -5.0f)), 90.0f, vec3(0.0f, 1.0f, 0.0f)); 
	wall5->material.setAmbientAndDiffuseMat(color);
	wall5->material.setEmissiveMat(color);
	addChild(wall5);

	//// Right Wall Back
	VisualObject* wall6 = new Wall(4.0f, 6.0f);  
	wall6->fixedTransformation = rotate(translate(mat4(1.0f), vec3(3.0f, -3.0f, -5.0f)), -90.0f, vec3(0.0f, 1.0f, 0.0f)); 
	wall6->material.setAmbientAndDiffuseMat(color);
	wall6->material.setEmissiveMat(color);
	addChild(wall6);

	// Back Wall Front
	VisualObject* wall7 = new Wall(4.0f, 6.0f); 
	wall7->fixedTransformation = translate(mat4(1.0f), vec3(0.0f, -3.0f, -8.0f)); 
	wall7->material.setAmbientAndDiffuseMat(color);
	wall7->material.setEmissiveMat(color);
	addChild(wall7);

	// Back Wall Back
	VisualObject* wall8 = new Wall(4.0f, 6.0f); 
	wall8->fixedTransformation = rotate(translate(mat4(1.0f), vec3(0.0f, -3.0f, -8.0f)), 180.0f, vec3(0.0f, 1.0f, 0.0f)); 
	wall8->material.setAmbientAndDiffuseMat(color);
	wall8->material.setEmissiveMat(color);
	addChild(wall8);

	VisualObject* pyramid0 = new Pyramid(6.0f, 4.0f);
	pyramid0->setShader(shaderProgram);
	pyramid0->material.setAmbientAndDiffuseMat(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
	pyramid0->material.setEmissiveMat(vec4(0.0f, 0.0f, 1.0f, 1.0f));
	pyramid0->modelMatrix = translate(mat4(1.0f), vec3(0.0f, 3.0f, -5.0f));
	addChild( pyramid0 );

}

void House::setShader( GLuint shaderProgram ) 
{ 
	for (unsigned int i = 0; i < children.size(); i++) {

		children[i]->setShader(shaderProgram);
	}
}
