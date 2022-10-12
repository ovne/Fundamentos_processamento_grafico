/**
 * Nome: Vinícius Souza de Oliveira
 * RA: 11201920654
 * Data: 11/10/2022
 * Programa: lab02-ex4-GL_QUAD_STRIP
 * cmd para execução: (copiar e colar terminal linux) 
 *    gcc -o gl_quad_strip lab02-ex4-GL_QUAD_STRIP.cpp -lglut -lGL -lGLU && ./gl_quad_strip
*/
#include <GL/glut.h>
   
void display(void)
{
/* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

/* draw white polygon (rectangle) with corners at
 * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)  
 */
   glColor3f (1.0, 1.0, 1.0);
   glBegin(GL_QUAD_STRIP);
      // 1st quad
      glVertex3f (0.10, 0.10, 0.0);
      glVertex3f (0.33, 0.15, 0.0);
      glVertex3f (0.33, 0.80, 0.0);
      glVertex3f (0.13, 0.73, 0.0);
      // 2nd quad
      glColor3f (1.0, 1.0, 0.0);
      glVertex3f (0.60, 0.50, 0.0);
      glVertex3f (0.90, 0.50, 0.0);
      glVertex3f (0.90, 0.80, 0.0);
      glVertex3f (0.60, 0.80, 0.0);
   glEnd();
   /* OBS.: A maneira como os poligonos foram conectados me é estranha..
   vale a pena pesquisar o por que.*/

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
   glutCreateWindow ("Vinicius 11201920654 GL_QUAD_STRIP");
   init ();
   glutDisplayFunc(display); 
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}
