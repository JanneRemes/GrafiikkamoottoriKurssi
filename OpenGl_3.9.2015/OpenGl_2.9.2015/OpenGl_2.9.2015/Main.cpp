#include <GL/glut.h>

void renderScene(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.5, 0.0);
	glEnd();

	glutSwapBuffers();
}


int main(int argc, char **argv){
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow(" Lighthous e3D - GLUT Tutorial");

	//registercallbacks
	glutDisplayFunc(renderScene);

	//enter GLUT event processingcycle
	glutMainLoop();

	return 1;
}