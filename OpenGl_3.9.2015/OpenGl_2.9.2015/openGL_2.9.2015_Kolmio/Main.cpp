#include <GL/glut.h>

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
	window=glutCreateWindow("GLUT Tutorial");

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