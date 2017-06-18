#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>


float Color1=1.0, Color2=1.0, Color3=1.0;

void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 27:             // ESCAPE key
	  exit (0);
	  break;

  case 'r':
	 Color1=1.0, Color2=0.0, Color3=0.0;
	 break;
  case 'g':
	 Color1=0.0, Color2=1.0, Color3=0.0;
     break;
  case 'b':
      Color1=0.0, Color2=0.0, Color3=1.0;
	  break;
  }
  glutPostRedisplay();
}

void Init(int w, int h)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glViewport(0,0, (GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION); // projection related
    glLoadIdentity();
    gluOrtho2D( (GLdouble)w, 0.0, (GLdouble)h, 0.0); // not now ...

}
static void display(void)
{

  int i=0;
  glColor4f(Color1,Color2, Color3,1);
  glPointSize(10);
  glBegin(GL_POINTS);
  for( i=0;i<=100;i++)
  {
        //Creating a square
        glVertex2f(100, 200+i); // right arm
        glVertex2f(100+i,200);  // top arm
        glVertex2f(200,200+i);  // left arm
        glVertex2f(100+i,300);  // bottom arm

  }
  glEnd();
  glFlush();
}


int main(int argc, char *argv[])
{

    glutInit(&argc, argv); // the glutInit() call initializes the GLUT library and also processes any command line options related to glut.
    glutInitWindowSize(640,480); //assign initial window size
    glutInitWindowPosition(10,10); // assign initial window position
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // check resource link

    glutCreateWindow("GLUT Shapes");// name to the window and create the window itself

    //setting window properties
    Init(640, 480);

    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);


    glutMainLoop();

    return 1;
}

