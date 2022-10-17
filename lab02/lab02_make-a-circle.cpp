/**
 * Nome: Vinícius Souza de Oliveira
 * RA: 11201920654
 * Data: 11/10/2022
 * Programa:
 * cmd para execução: (copiar e colar terminal linux) 
 *    gcc -o output lab02_make-a-circle.cpp -lglut -lGL -lGLU -lm && ./output
*/


#include <GL/glut.h>
#include <math.h>


void display(void)
{
   /* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

   GLdouble PI = 3.1415926535897;
   GLint circle_points = 1000;  
   glBegin(GL_LINE_LOOP);
      for (int i = 0; i < circle_points; i++) {
         GLdouble angle = (2 * PI * i) / circle_points;
         glVertex2f(cos(angle), sin(angle));
      }
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
   //glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
   glOrtho(0.0, 0.0, 0.0, 0.0, -5.0, 0.0);
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
