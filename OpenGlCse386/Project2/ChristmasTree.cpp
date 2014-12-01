#include "ChristmasTree.h"


ChristmasTree::ChristmasTree(void) {



}


void ChristmasTree::setShader( GLuint shaderProgram ) 
{ 
	for (unsigned int i = 0; i < children.size(); i++) {

		children[i]->setShader(shaderProgram);
	}
}
