/**
 * Nome: Vinícius Souza de Oliveira
 * RA: 11201920654
 * Data: 11/10/2022
 * Programa: lab02-ex4-GL_TRIANGLES
 * cmd para execução: (copiar e colar terminal linux) 
 *    gcc -o gl_triangles lab02-ex4-GL_TRIANGLES.cpp -lglut -lGL -lGLU && ./gl_triangles
*/
#include <GL/glut.h>

void display(void)
{
/* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

/* draw white polygon (rectangle) with corners at
 * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)  
 */
   glColor3f (1.0, 1.0, 0.0);
   // in this exemple i'm gonna the Triforce simbol, from The Legend Of Zeld =p
   glBegin(GL_TRIANGLES);
      // first triangle: POWER
      glVertex3f (0.10, 0.10, 0.0);
      glVertex3f (0.50, 0.10, 0.0);
      glVertex3f (0.30, 0.36641, 0.0);
      // second triangle: WISDOM
      glVertex3f (0.50, 0.10, 0.0);
      glVertex3f (0.90, 0.10, 0.0);
      glVertex3f (0.70, 0.36641, 0.0);
      // third triangle: COURAGE
      glVertex3f (0.30, 0.36641, 0.0);
      glVertex3f (0.70, 0.36641, 0.0);
      glVertex3f (0.50, 0.69282, 0.0);
   glEnd();

/* don't wait!  
 * start processing buffered OpenGL routines 
 */
   glFlush ();
}

void init (void) 
{
/* select clearing color 	*/
   glClearColor (0.0, 0.0, 0.0, 0.0);

/* initialize viewing values  */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

/* 
 * Declare initial window size, position, and display mode
 * (single buffer and RGBA).  Open window with "hello"
 * in its title bar.  Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 */
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (400, 400); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Vinicius 11201920654 GL_TRIANGLE");
   init ();
   glutDisplayFunc(display); 
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}
