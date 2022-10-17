/**
 * Nome: Vinícius Souza de Oliveira
 * RA: 11201920654
 * Data: 11/10/2022
 * Programa: exe 5.1
 * cmd para execução: (copiar e colar terminal linux) 
 *    gcc -o output lab02_exe5.1.cpp -lglut -lGL -lGLU -lm && ./output
*/


#include <GL/glut.h>
#include <math.h>


void display(void)
{
   /* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

   glBegin(GL_TRIANGLES);
      glColor3f(.89, 1.0, 1.0);
      glVertex3f(0.13, 0.73, 0.0); // p1
      glVertex3f(0.26, 0.33, 0.0); // p2
      glVertex3f(0.54, 0.61, 0.0); // p5

      glVertex3f(0.26, 0.33, 0.0); // p2
      glVertex3f(0.95, 0.42, 0.0); // p3
      glVertex3f(0.54, 0.61, 0.0); // p5

      glVertex3f(0.95, 0.42, 0.0); // p3
      glVertex3f(0.84, 0.88, 0.0); // p4
      glVertex3f(0.54, 0.61, 0.0); // p5
   glEnd();


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
   //glOrtho(0.0, 0.0, 0.0, 0.0, -5.0, 0.0);
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
   glutInitWindowSize (400,400); 
   glutInitWindowPosition (0 , 0);
   glutCreateWindow ("Vinícius Oliveira - 11201920654");
   init ();
   glutDisplayFunc(display); 
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}
