/*
 * robot.c
 * This program shows how to composite modeling transformations
 * to draw translated and rotated hierarchical models.
 * Interaction:  pressing the s and e keys (bracoRot and antebracoRot)
 * alters the rotation of the robot arm.
 */
 

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

static int bracoRot=0, antebracoRot = 0;
static int dedo1A = 0, dedo2A = 0, dedo3A=0; 

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glPushMatrix();
      glTranslatef(-2.0, 0.0, 0.0); // pos final obj
      glRotatef((GLfloat) bracoRot, 0.0, 0.0, 1.0);
      glTranslatef(1.0, 0.0, 0.0); // ponto de rotacao
      glPushMatrix();
         glScalef(2.0, 1.0, 1.0);
         glutWireCube(1.0);
      glPopMatrix();

      glTranslatef(1.0, 0.0, 0.0); // pos final obj
      glRotatef((GLfloat) antebracoRot, 0.0, 0.0, 1.0);
      glTranslatef(1.0, 0.0, 0.0); // ponto de rotacao
      glPushMatrix();
         glScalef(2.0, 1.0, 1.0);
         glutWireCube(1.0);
      glPopMatrix();

      glTranslatef(1.25, -0.4, 0.0); // pos final obj
      glRotatef((GLfloat)dedo1A, 0.0, 0.0, 1.0);
      glTranslatef(0.0, 0.0,  0.0); // ponto de rotacao
      glPushMatrix();
         glScalef(1.0, 0.5, 0.5);
         glutWireCube(0.5);
      glPopMatrix();

      glTranslatef(0.0, 0.8, 0.33); // pos final obj
      glRotatef((GLfloat)dedo2A, 0.0, 0.0, 1.0);
      glTranslatef(0.0,0.0,0.0);
      glPushMatrix();
         glScalef(1.0, 0.5, 0.5);
         glutWireCube(0.5);
      glPopMatrix();

      glTranslatef(-0.5, 0.0, -0.5);
      glRotatef((GLfloat)dedo3A, 0.0, 0.0, 1.0);
      glTranslatef(0.0,0.0,-0.5);
      glPushMatrix();
         glScalef(1.0, 0.5, 0.5);
         glutWireCube(0.5);
      glPopMatrix();


   glPopMatrix(); 
   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(85.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -5.0);
   glLoadIdentity();
   gluLookAt (
      5.0, 1.0, 5.0, //eye
      0.0, 0.0, 0.0, //center
      0.0, 1.0, 0.0 //up vector
   );
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'w':
      case 'W':
         bracoRot = (bracoRot + 5) % 360;
         glutPostRedisplay();
         break;
      case 's':
      case 'S':
         bracoRot = (bracoRot - 5) % 360;
         glutPostRedisplay();
         break;
      case 'q':
      case 'Q':
         antebracoRot = (antebracoRot + 5) % 360;
         glutPostRedisplay();
         break;
      case 'E':
      case 'e':
         antebracoRot = (antebracoRot - 5) % 360;
         glutPostRedisplay();
         break;
      case 'n':
      case 'N':
         dedo1A = (dedo1A + 5) % 360;
         glutPostRedisplay();
         break;
      case 'm':
      case 'M':
         dedo1A = (dedo1A - 5) % 360;
         glutPostRedisplay();
         break;
      case 'h':
         dedo2A = (dedo2A - 5) % 360;
         glutPostRedisplay();
         break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (680, 680); 
   glutInitWindowPosition (100.0, 100.0);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
