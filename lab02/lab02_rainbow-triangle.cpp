/**
 * Nome: Vinícius Souza de Oliveira
 * RA: 11201920654
 * Data: 11/10/2022
 * Programa: rainbow_triangle
 * cmd para execução: (copiar e colar terminal linux) 
 *    gcc -o output lab02-rainbow-triangle.cpp -lglut -lGL -lGLU -lm && ./output
*/

#include <GL/glut.h>

void display(void)
{
/* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

   glBegin(GL_TRIANGLES);
      glColor3f( 1.f, 0.f, 0.f );
      glVertex3f( 0.2f, 0.2f, 0.f );
      glColor3f( 0.f, 1.f, 0.f );
      glVertex3f( 0.8f, 0.2f, 0.f );
      glColor3f( 0.f, 0.f, 1.f );
      glVertex3f( 0.2f, 0.8f, 0.f );
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
   glutInitWindowSize (250, 250); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Vinícius Oliveira - 11201920654");
   init ();
   glutDisplayFunc(display); 
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}
