#include <GL/glut.h>

GLfloat angle=0.0;
GLfloat speed=5.0;
static int window;

void renderScene(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();
  glRotatef(angle, 0, 0, 1);
 
  glBegin(GL_TRIANGLES);
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(-0.5,-0.5,0.0);
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(0.5,0.0,0.0);
  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(0.0,0.5,0.0);
  glEnd();
  
  glutSwapBuffers();
}

void timerCallback(int) {
  angle+=speed;
  glutTimerFunc(50, timerCallback, 0);
  renderScene();
}

void kbCallback(unsigned char key, int, int) {
  speed=-speed;
}

void menuCallback(int entry) {
  if(entry==1) {
    glutDestroyWindow(window);
    exit(0);
  }
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(320,320);
  window=glutCreateWindow("GLUT Tutorial");
  
  glutDisplayFunc(renderScene);
  glutTimerFunc(50, timerCallback, 0);
  glutKeyboardFunc(kbCallback);

  glutCreateMenu(menuCallback);
  glutAddMenuEntry("Quit", 1);
  glutAttachMenu(GLUT_LEFT_BUTTON);
 
  glutMainLoop();
}
