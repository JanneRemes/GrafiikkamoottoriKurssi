#include <GL\glew.h>
#include <GL\glut.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>


int winWidth = 400, winHeight = 400;


void init(void)
{
	/* Set the clear color. */
	glClearColor(0, 0, 0, 0);

	/* Setup our viewport. */
	glViewport(0, 0, winWidth, winHeight);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}


//using namespace glm;
//using namespace std;

//void PrintMatrix(const glm::mat4 &m) {
//	for (int i = 0; i<4; i++) {
//		for (int j = 0; j<4; j++) {
//			cout << m[j][i] << " ";
//		}
//		cout << "\n";
//	}
//	cout << "\n";
//}
//
//void PrintVec(const glm::vec4 &v) {
//	for (int i = 0; i<4; i++) {
//		cout << v[i] << "\n";
//	}
//	cout << "\n";
//}
//
//int main(int argc, char **argv) {
//	//Tehtava 1
//	if (false){
//		glm::mat4 A(1, 0, 2, 2, //Sarake 1
//			0, 1, 0, 0, //Sarake 2
//			1, 1, 1, 2, //Sarake 3
//			0, 0, 1, 0);//Sarake 4
//		glm::mat4 B(0, 0, 0, 2, //Sarake 1
//			1, 1, 0, 0, //Sarake 2
//			1, 1, 0, 2, //Sarake 3
//			0, 0, 1, 0);//Sarake 4
//		glm::vec4 c(3, 4, -2, 1);
//
//		glm::vec4 x = (A*B)*c;
//
//		PrintVec(x);
//
//	}
//	//Tehtava 2,3,4
//	if (true) {
//		glm::vec4 p1(0.0, 0.0, 0.0, 1.0);
//		// kierto -> (0,0) skaalaus -> (0,0) siirto -> (3,-1)
//		// kamera -> (0, -3)
//		// projektio -> (0, -1)
//		glm::vec4 p2(1.0, 0.0, 0.0, 1.0);
//		// kierto -> (0,1) skaalaus -> (0,2) siirto -> (3, 1)
//		// kamera -> (0, -1)
//		// projektio -> (0, -1/3)
//		glm::vec3 x_axis(1.0, 0.0, 0.0);
//		glm::vec3 y_axis(0.0, 1.0, 0.0);
//		glm::vec3 z_axis(0.0, 0.0, 1.0);
//
//		cout << "-- 2------------------\n";
//
//		glm::vec3 s(2.0); //skaalaus
//		glm::vec3 t(3, -1, 0.0); //siirto
//		glm::vec3 r = z_axis; //kierto
//
//		glm::mat4 R = glm::rotate(3.14159265f / 2.0f, r);
//		//PrintVec(R*p1);
//		//PrintVec(R*p2);
//
//		glm::mat4 S = glm::scale(s);
//		//PrintVec(S*R*p1);
//		//PrintVec(S*R*p2);
//
//
//		glm::mat4 T = glm::translate(t);
//		//PrintVec(T*S*R*p1);
//		//PrintVec(T*S*R*p2);
//
//		glm::mat4 T_model = T*S*R;
//		PrintVec(T_model*p1);
//		PrintVec(T_model*p2);
//		PrintMatrix(T_model);
//
//		cout << "-- 3------------------\n";
//
//		glm::vec3 cam_pos(3, 2, 0);
//		glm::vec3 cam_up = y_axis;
//		glm::vec3 cam_right = x_axis;
//		glm::vec3 cam_front = -z_axis; //oikeakatinen koordinaatisto
//
//		glm::mat4 T_view = glm::lookAt(cam_pos, cam_pos + cam_front, cam_up);
//		glm::mat4 T_total = T_view*T_model;
//		//PrintMatrix(C);
//
//		PrintVec(T_total*p1);
//		PrintVec(T_total*p2);
//		PrintMatrix(T_total);
//
//		cout << "-- 4------------------\n";
//		float v_width = 8.0; //viewport in camera coord
//		float v_height = 6.0;
//
//		glm::mat4 T_projection = glm::ortho(-0.5f*v_width, 0.5f*v_width, -0.5f*v_height, 0.5f*v_height);
//		PrintMatrix(T_projection);
//
//		T_total = T_projection*T_view*T_model;
//		PrintVec(T_total*p1);
//		PrintVec(T_total*p2);
//		PrintMatrix(T_total);
//	}
//
//	system("PAUSE");
//}


GLfloat nnumber = 3.0;
GLfloat r = 0.0;
GLfloat g = 0.0;
GLfloat b = 0.0;

GLfloat r2 = 0.0;
GLfloat g2 = 0.0;
GLfloat b2 = 0.0;

GLfloat r3 = 0.0;
GLfloat g3 = 0.0;
GLfloat b3 = 0.0;

static int window;
#include <string>;

void renderScene(void){

	if (nnumber >= 3 && nnumber <= 8){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glLoadIdentity();

		glBegin(GL_TRIANGLES);

		GLfloat temp = (2 * 3.14159265359f) / nnumber;

		for (size_t i = 0; i < nnumber; i++)
		{
			glColor3f(r, g, b);
			glVertex3f(0.0f, 0.0f, 0.0f);

			glColor3f(r2, g2, b2);
			glVertex3f(cos(i * temp), sin(i* temp), 0.0f);

			glColor3f(r3, g3, b3);
			glVertex3f(cos((i + 1)*temp), sin((i + 1)*temp), 0.0f);
		}

		glEnd();

		glutSwapBuffers();
	}

}

void menuCallback(int entry){
	if (entry == 1){
		glutDestroyWindow(window);
		exit(0);
	}
	else nnumber = entry;
}

void colorCallbackRGB(int){

	int randomn = (rand() % 3);

	if (randomn == 0)
	{
		r = 0;
		g = 0;
		b = 255;

		r2 = 255;
		g2 = 0;
		b2 = 0;

		r3 = 0;
		g3 = 255;
		b3 = 0;
	}
	if (randomn == 1)
	{
		r = 255;
		g = 0;
		b = 0;

		r2 = 0;
		g2 = 255;
		b2 = 0;

		r3 = 0;
		g3 = 0;
		b3 = 255;
	}
	if (randomn == 2)
	{
		r = 0;
		g = 255;
		b = 0;

		r2 = 0;
		g2 = 0;
		b2 = 255;

		r3 = 255;
		g3 = 0;
		b3 = 0;
	}
	renderScene();
	glutTimerFunc(300, colorCallbackRGB, 0);
	//glutSwapBuffers();
}

int main(int argc, char **argv){
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	window = glutCreateWindow("GLUT Tutorial");

	//registercallbacks
	glutDisplayFunc(renderScene);

	glutTimerFunc(200, colorCallbackRGB, 0);

	glutCreateMenu(menuCallback);
	glutAddMenuEntry("Exit", 1);

	glutAddMenuEntry("3", 3);
	glutAddMenuEntry("4", 4);
	glutAddMenuEntry("5", 5);
	glutAddMenuEntry("6", 6);
	glutAddMenuEntry("7", 7);
	glutAddMenuEntry("8", 8);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	//enter GLUT event processingcycle
	glutMainLoop();

	return 1;
}