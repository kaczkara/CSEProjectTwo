#include "OpenGLApplicationBase.h"
#include "glutbase.h"
#include "Floor2.h"
#include "Pyramid.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cube.h"
#include "Cone.h"
#include "OrbitController.h"
#include "SpinnerController.h"
#include "WaypointController.h"
#include "SharedGeneralLighting.h"
#include "SnowMan.h"
#include "Wall.h"
#include "LightPole.h"
#include "ChristmasTree.h"
#include "House.h"
#include "Ornament.h"
#include "font.h"

//static void SpecialKeyboardCB(int Key, int x, int y);
class ProjectTwo : public OpenGLApplicationBase{
public: 
	ProjectTwo (){
		floor = new Wall(10, 10);
		floor->fixedTransformation = translate(rotate(mat4(1.0), -90.0f, vec3(1.0f, 0.0f, 0.0f)), vec3(0.0f, -5.0f, 0.0f));
		floor->material.setTextureMapped(true);
		floor->material.setupTexture("snow.bmp");

		house = new House(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
		house->modelMatrix = translate(mat4(1.0), vec3(0.0f, 0.0f, -2.0f));
		pyramid0 = new LightPole();
		pyramid0->modelMatrix = translate(mat4(1.0), vec3(0.0f, -3.0, -2.0f));
		snowman = new SnowMan();
		snowman->modelMatrix=translate(mat4(1.0f), vec3(0.0f,-2.8f, 0.0));
		//snowman->addController(new SpinnerController(glm::vec3(3.0f, 0.0f, 0.f), glm::vec3(1.0f, 0.0f, 0.0f)));

		tree = new ChristmasTree();
		tree->modelMatrix = translate(mat4(1.0f), vec3(-2.0f, -2.8f ,0.0f));
		/*cylinder->material.setAmbientAndDiffuseMat(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
		cylinder->addController(new SpinnerController(glm::vec3(-3.0f, 0.0f, 0.0f),  glm::vec3(0.0f, 0.0f, 1.0f)));

		cone = new Cone();
		cone->material.setAmbientAndDiffuseMat(glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
		cone->addController(new OrbitController(glm::vec3(10.f, 0.f, 0.f), glm::vec3(0.f, -1.f, 0.f), glm::vec3(1.f, 0.f, 0.f),35));
		*/
		//cube = new Cube();
		vector<glm::vec3> waypoints;
		waypoints.push_back(glm::vec3(-3.5f, -2.5f, 3.5f));
		waypoints.push_back(glm::vec3(3.5f, -2.5f, 3.5f));
		waypoints.push_back(glm::vec3(3.5f, -2.5f, -3.5f));
		waypoints.push_back(glm::vec3(-3.5f, -2.5f, -3.5f));
		//cube->material.setAmbientAndDiffuseMat(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
		//cube->addController(new WaypointController(waypoints, 1.5f));
		addChild(floor);
		
		addChild(snowman);
		addChild(tree);
		//addChild(cone);
		//addChild(cube);
		addChild(house);

		// Create array of ShaderInfo structs that specifies the vertex and 
		// fragment shaders to be compiled and linked into a program. 
		ShaderInfo shaders[] = { 
			{ GL_VERTEX_SHADER, "pcVsUniViewProj.vert" }, 
			{ GL_FRAGMENT_SHADER, "pfixed-function-shared-lighting-phong.frag"}, 
			{ GL_NONE, NULL } // signals that there are no more shaders 
		};
		// Read the files and create the OpenGL shader program. 
		GLuint shaderProgram = BuildShaderProgram(shaders);
		projectionAndViewing.setUniformBlockForShader(shaderProgram);
		generalLighting.setUniformBlockForShader( shaderProgram );
		floor->setShader(shaderProgram);
		pyramid0->setShader(shaderProgram);
		snowman->setShader(shaderProgram);
		tree->setShader(shaderProgram);
		//cone->setShader(shaderProgram);
		//cube->setShader(shaderProgram);
		house->setShader(shaderProgram);

		setupLighting(shaderProgram);

		/*VisualObject* transparent;
		transparent = new Cube(2.0, 2.0, 2.0);
		transparent ->setShader(shaderProgram);
		transparent->material.setAmbientAndDiffuseMat(glm::vec4(1.0f, 1.0f, 0.0f, 0.5f));
		transparent->fixedTransformation = translate(mat4(1.0f), vec3(3.0f, 0.f, 0.0f));
		*/
		/*VisualObject* ornament = new Ornament(glm::vec4(1.0f, 0.0f, 0.0f, 0.3f), 0.1f);
		ornament ->setShader(shaderProgram);*/

		//addChild(transparent);
		addChild(pyramid0);
		//addChild(ornament);

		view = 0;
		rotationX=0.0f;
		rotationY=0.0f;
		rotationZ=-12.0f;
		//floor->set();
		//pyramid0->setShaderValues();

	}
	
	void setupLighting(GLuint shaderProgram) {
		/// ***** Ambient Light **************
		generalLighting.setEnabled( GL_LIGHT_ZERO, true );
		generalLighting.setAmbientColor( GL_LIGHT_ZERO, vec4(0.9f, 0.9f, 0.9f, 1.0f));
		// ***** Directional Light ****************
		generalLighting.setEnabled( GL_LIGHT_ONE, false );
		generalLighting.setDiffuseColor( GL_LIGHT_ONE, vec4(0.75f, 0.75f, 0.75f, 1.0f) );
		generalLighting.setSpecularColor( GL_LIGHT_ONE, vec4(1.0f, 1.0f, 1.0f, 1.0f) );
		generalLighting.setPositionOrDirection( GL_LIGHT_ONE, vec4(1.0f, 1.0f, 1.0f, 0.0f) );
		// ***** Positional Light ***************
		generalLighting.setEnabled( GL_LIGHT_TWO, false );
		generalLighting.setDiffuseColor( GL_LIGHT_TWO, vec4(0.5f, 0.5f, 0.5f, 1.0f) );
		generalLighting.setSpecularColor( GL_LIGHT_TWO, vec4(1.0f, 1.0f, 1.0f, 1.0f) );
		generalLighting.setPositionOrDirection( GL_LIGHT_TWO, vec4(1.0f, 3.0f, 1.0f, 1.0f) );
		// ***** Spot Light **************
		generalLighting.setEnabled( GL_LIGHT_THREE, false );
		generalLighting.setIsSpot( GL_LIGHT_THREE, true );
		generalLighting.setDiffuseColor( GL_LIGHT_THREE, vec4(1.0f, 1.0f, 1.0f, 1.0f) );
		generalLighting.setSpecularColor( GL_LIGHT_THREE, vec4(1.0f, 1.0f, 1.0f, 1.0f) );
		generalLighting.setPositionOrDirection( GL_LIGHT_THREE, vec4(0.0f, 8.0f, 0.0f, 1.0f) );
		generalLighting.setSpotDirection( GL_LIGHT_THREE, vec3(0.0f, -1.0f, 0.0f) );
		generalLighting.setSpotCutoffCos( GL_LIGHT_THREE, cos(glm::radians(15.0f)) );

	} // end setupLighting
	void setViewPoint( ) {
		glm::mat4 viewMatrix;
		switch (view) {
		case 0:
			viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3( 0.0f, 0.0f, -12 ));
			projectionAndViewing.setViewMatrix(viewMatrix);
			break;
		case 1: 
			viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3( 0.0f, 0.0f, -10.0f ));
			projectionAndViewing.setViewMatrix(viewMatrix);
			break;
		case 2:
			viewMatrix = glm::rotate(glm::translate(glm::mat4(1.0f), glm::vec3( 0.0f, 0.0f, -10.0f )),45.0f,glm::vec3(1.0f, 0.0f, 0.0f));
			projectionAndViewing.setViewMatrix(viewMatrix);
			break;
		case 3:
			viewMatrix = glm::rotate(glm::rotate(glm::translate(glm::mat4(1.0f), glm::vec3( 0.0f, 0.0f, -10.0f )),90.0f,glm::vec3(1.0f, 0.0f, 0.0f)),90.0f,glm::vec3(0.0f, 1.0f, 0.0f));
			projectionAndViewing.setViewMatrix(viewMatrix);
			break;
		case 4:
			viewMatrix=glm::lookAt(glm::vec3( 0.0f, 0.0f, 10.0f ),glm::vec3( 0.0f, 0.0f, 0.0f ),glm::vec3( 0.0f, 1.0f, 0.0f ));
			projectionAndViewing.setViewMatrix(viewMatrix);
			break;
		case 5:
			viewMatrix=glm::lookAt(glm::vec3( 0.0f, 7.07f, 7.07f ),glm::vec3( 0.0f, 0.0f, 0.0f ),glm::vec3( 0.0f, 1.0f, 0.0f ));
			projectionAndViewing.setViewMatrix(viewMatrix);
			break;
		case 6:
			viewMatrix=glm::lookAt(glm::vec3( 0.0f, 10.0f, 0.0f ),glm::vec3( 0.0f, 0.0f, 0.0f ),glm::vec3( 1.0f, 0.0f, 0.0f ));
			projectionAndViewing.setViewMatrix(viewMatrix);
			break;
		case 7:
			glm::mat4 transView = glm::translate(glm::mat4(1.0f), glm::vec3( 0.0f, 0.0f,rotationZ ));
			glm::mat4 rotateViewX = glm::rotate(glm::mat4(1.0f), rotationX, glm::vec3(1.0f, 0.0f, 0.0f)); 
			glm::mat4 rotateViewY = glm::rotate(glm::mat4(1.0f), rotationY, glm::vec3(0.0f, 1.0f, 0.0f));
			projectionAndViewing.setViewMatrix( transView * rotateViewX * rotateViewY );
			break;
		}
	}
	virtual void initialize(){
		glClearColor(0.9f, 0.9f, 0.9f, 0.0f);
		glFrontFace(GL_CCW);
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
		glEnable( GL_DEPTH_TEST );
		setUpMenus();
		glutSpecialFunc(SpecialKeyboardCB);
		VisualObject::initialize();
		floor->modelMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -3.0f, 0.0f));
	} // end initialize
	virtual void draw(){
		setViewPoint();
		screenTextOutput (430, 700, "Merry Christmas!", glm::vec4(1.0f, 0.0f, 1.0f, 1.0f),  GLUT_BITMAP_TIMES_ROMAN_24);
		VisualObject::draw();
	}
	SharedGeneralLighting generalLighting;
	VisualObject* floor;
	VisualObject* pyramid0;
	VisualObject* snowman;
	VisualObject* house;
	VisualObject* tree;
	Cube* cube;
	Cone* cone;
	GLint view;
	GLfloat rotationX;
	GLfloat rotationY;
	GLfloat rotationZ;
	friend void viewMenu(int value);
	friend static void SpecialKeyboardCB(int Key, int x, int y);
	void setUpMenus();
	void KeyboardCB(unsigned char Key, int x, int y);
protected:
	GLuint createViewMenu();
}; // end uniqueidLab3
ProjectTwo* labClassPtr;
static void SpecialKeyboardCB(int Key, int x, int y){
	switch (Key) {
	case GLUT_KEY_RIGHT:
		labClassPtr->rotationY++;
		break;
	case GLUT_KEY_LEFT:
		labClassPtr->rotationY--;
		break;
	case GLUT_KEY_UP:
		labClassPtr->rotationX++;
		break;
	case GLUT_KEY_DOWN:
		labClassPtr->rotationX--;
		break;
	default:
		break;
	}
}
void ProjectTwo::KeyboardCB(unsigned char Key, int x, int y){
	bool lightOn;
	switch (Key) {
	case 'w':
		labClassPtr->rotationZ++;
		break;
	case 's':
		labClassPtr->rotationZ--;
		break;
	case 'a':
		lightOn = labClassPtr->generalLighting.getEnabled(GL_LIGHT_ZERO);
		generalLighting.setEnabled( GL_LIGHT_ZERO, !lightOn);
		break;
	case 'd':
		lightOn = labClassPtr->generalLighting.getEnabled( GL_LIGHT_ONE);
		generalLighting.setEnabled(  GL_LIGHT_ONE, !lightOn);
		break;
	case 'p':
		lightOn = labClassPtr->generalLighting.getEnabled( GL_LIGHT_TWO);
		generalLighting.setEnabled(  GL_LIGHT_TWO, !lightOn);
		break;
	case 'f':
		lightOn = labClassPtr->generalLighting.getEnabled( GL_LIGHT_THREE);
		generalLighting.setEnabled(  GL_LIGHT_THREE, !lightOn);
		break;
	case '0':
		if (pyramid0->getParent() == NULL ) {
			this->addChild(pyramid0);
		}
		else {
			pyramid0->detachFromParent();
		}
		break;
	case '3':
		if (cube->getParent() == NULL ) {
			this->addChild(cube);
		}
		else {
			cube->detachFromParent();
		}
		break;
	case '4':
		if (cone->getParent() == NULL ) {
			this->addChild(cone);
		}
		else {
			cone->detachFromParent();
		}
		break;
	case '5':
		if (floor->getParent() == NULL ) {
			this->addChild(floor);
		}
		else {
			floor->detachFromParent();
		}
		break;
	default:
		OpenGLApplicationBase::KeyboardCB(Key,x,y);
		break;
	}
}
GLuint ProjectTwo::createViewMenu(){
	GLuint menuId = glutCreateMenu(viewMenu);
	// Specify menu items and their integer identifiers
	glutAddMenuEntry("Default", 0);
	glutAddMenuEntry("View 1", 1);
	glutAddMenuEntry("View 2", 2);
	glutAddMenuEntry("View 3", 3);
	glutAddMenuEntry("View 4", 4);
	glutAddMenuEntry("View 5", 5);
	glutAddMenuEntry("View 6", 6);
	glutAddMenuEntry("View 7", 7);
	return menuId;
}

void viewMenu(int value){
	labClassPtr-> view = value;
	cout << "View point " << value << endl;

} // end figureMenu
void ProjectTwo::setUpMenus(){
	// Create polygon submenu
	GLuint menu0id = createViewMenu();
	GLuint menu1id = createPolygonMenu();
	GLuint menu2id = createFrontFaceMenu();
	GLuint menu3id = createPointSizeMenu();
	GLuint menu4id = createLineWidthMenu();
	GLuint menu5id = createAntiAliasingMenu();
	// Create main menu
	topMenu = glutCreateMenu(mainMenu);
	glutAddSubMenu("View", menu0id); // Attach polygon Menu
	glutAddSubMenu("Polygon Mode", menu1id); // Attach polygon Menu
	glutAddSubMenu("Rendered Polygon Face", menu2id); //Attach culling menu
	glutAddSubMenu("Point Size", menu3id); //attach point size menu
	glutAddSubMenu("Line Width", menu4id); //attach line width menu
	glutAddSubMenu("Anti-Aliasing", menu5id); //attach anti-aliasing menu
	glutAddMenuEntry("Quit", 1); // Specify identifier for "Quit"	
	glutAttachMenu(GLUT_RIGHT_BUTTON); // Attach menu to right mouse button
}
// Update scene objects inbetween frames

int main(int argc, char** argv){
	GLUTBaseInit(argc, argv); 
	GLUTBaseCreateWindow( "CSE 386 Lab 8" );
	ProjectTwo pApp;
	labClassPtr=&pApp;
	GLUTBaseRunApplication(&pApp);
} // end main
