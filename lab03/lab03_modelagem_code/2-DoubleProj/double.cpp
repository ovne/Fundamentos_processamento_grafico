/*
 *  double.c
 *  This is a simple double buffered program.
 *  Pressing the left mouse button rotates the rectangle.
 *  Pressing the middle mouse button stops the rotation.
 *  Modificado em 17/10/2022 Vinicius Oliveira - 11201920654
 */

/**
 * Questoes propostas:
 * 
 * - Execute o programa
   - Verifique no código a implementação dos seguintes conceitos:
   . Buffer Duplo
   . Desenho de um objeto
   . Desenho do mesmo objeto Rotacionado
   . Guarda da Matriz na Pilha. Por que isso deve ser feito?
      -> Para que o estado atual do ebjeto seja armazanado e recuperado depois.
   . Uso do mouse para parar e iniciar a animação.
   - Responda:
   . Qual o valor do angulo de Rotação: R(theta) em cada apresentação?
      -> utiliza o valor da variavel spin que inicia em 0 e eh incrementado em 2 ate 360
   . Por que a animação (mudança do desenho na tela) ocorre no programa?
      -> a funcao spinDisplay() incrementa o valor de spin mas tbm chama outra funcao
      glutPostRedisplay() que 'redesenha' a tela (com novo valor de spin) enquando o botão do
      nao eh precionado.

*/

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

static GLfloat spin = 0.0;

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix(); // guarda matriz na pilha de execucao
   glRotatef(spin, 0.0, 0.0, 1.0); // rotaciona a forma no valor de spin graus
   glColor3f(1.0, 1.0, 1.0);
   glRectf(-25.0, -25.0, 25.0, 25.0);
   glPopMatrix(); // busca a matriz na pilha de execucao

   glutSwapBuffers();
}

void spinDisplay(void)
{
   spin = spin + 2.0; // incrementa o valor de spin em 2 ate zerar no limite de 360
   if (spin > 360.0)
      spin = spin - 360.0;
   glutPostRedisplay();
}

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void reshape(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void mouse(int button, int state, int x, int y) 
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}
   
/* 
 *  Request double buffer display mode.
 *  Register mouse input callback functions
 */
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); // em GLUT_DOUBLE eh configurado o buffer duplo(?)
   glutInitWindowSize (250, 250); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Equipe Atomos");
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape); 
   glutMouseFunc(mouse);
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}
