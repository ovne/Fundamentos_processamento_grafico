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

GLdouble PI = 3.1415926535897;
GLint vertex_points ;

void display(void)
{
   /* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

   // 1st: circle
   vertex_points = 10000;
   glBegin(GL_LINE_LOOP);
      glColor3f( 0.0, 0.0, 0.0);
      for (int i = 0; i < vertex_points; i++) {
         GLdouble angle = (2 * PI * i) / vertex_points;
         glVertex2f(cos(angle), sin(angle));
      }
   glEnd();


   // 2nd: hexagon
   vertex_points = 6;
   glBegin(GL_POLYGON);
      glColor3f( 1.0, 0.0, 0.0);
      for (int i = 0; i < vertex_points; i++) {
         GLdouble angle = (2 * PI * i) / vertex_points;
         glVertex2f(cos(angle), sin(angle));
      }
   glEnd();

   // 3rd: square
   vertex_points = 4;
   glBegin(GL_QUADS);
      glColor3f( 0.0, 1.0, 0.0);

      glVertex2f(0.63, 0.63);
      glVertex2f(-0.63, 0.63);
      glVertex2f(-0.63, -0.63);
      glVertex2f(0.63, - 0.63);
   glEnd();

   // 4th: small circle
   vertex_points = 10000;
   glBegin(GL_POLYGON);
      glColor3f( 0.0, 1.0, 1.0);
      for (int i = 0; i < vertex_points; i++) {
         GLdouble angle = (2 * PI * i) / vertex_points;
         glVertex2f(cos(angle)*0.63, sin(angle)*0.63);
      }
   glEnd();

   // 5th: axes lines
   glBegin(GL_LINES);
      glColor3f(0.0, 0.0, 0.0);

      glVertex2f(-1.0, 0.0);
      glVertex2f(1.0, 0.0);
      glVertex2f(0.0, 1.0);
      glVertex2f(0.0, -1.0);
   glEnd();

   // 6th: triangle
   glBegin(GL_TRIANGLES);
      glColor3f(1.0, 0.0, 1.0);
      /** Para inclinacao de 45 graus sin() é igual a cos(), de forma que obtemos as
       * coordenadas limite para o triangulo subinscrito a partir do raio do circulo externo.
       * x=0.63cos(45) == y=0.63sen(45) == 0.445477...
      */
      GLdouble radius_cords_45angle = 0.445477;
      glVertex2f(-radius_cords_45angle, radius_cords_45angle);
      glVertex2f(-radius_cords_45angle, -radius_cords_45angle);
      glVertex2f(radius_cords_45angle, -radius_cords_45angle);
   glEnd();

   glFlush ();
}

void init (void) 
{
/* select clearing color 	*/
   glClearColor (1.0, 1.0, 1.0, .0);

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
   glutInitWindowSize (600,600); 
   glutInitWindowPosition (0 , 0);
   glutCreateWindow ("Vinicius Oliveira - 11201920654");
   init ();
   glutDisplayFunc(display); 
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}
