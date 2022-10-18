/*
 *  model.c
 *  This program demonstrates modeling transformations
 *  Modificado em 17/10/2022 por Vinicius Souza Oliveira - 11201920654
 * 
*/

/**
 * Questões propostas:
 * 
 * - Verifique no código a implementação dos seguintes conceitos:
   . Desenho de um objeto (triangulo)
   . Desenho do mesmo objeto Transladado
   . Desenho do mesmo objeto Escalonado
   . Desenho do mesmo objeto Rotacionado
   . Matriz Indentidade. Por que ela foi carregada?
      -> Para carregar os valores inalterados da matriz identidade antes de aplicar a 
      transformacao. Assim, não ocorre de ter transformacoes consecutivas na forma, quando
      isto nao eh a intencao.
   . Tecla para saída da execução do programa.
   -> tecla escape ('esc')
   - Responda: quais os valores dos argumentos das transformações realizadas?
      Translação: T(-20.0, 0.0)
      Escalonamento: S(1.5, 0.5, 1.0) escolana nas 3 dimensoes
      Rotação: R(90 graus)
*/
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void draw_triangle(void)
{
   glBegin (GL_LINE_LOOP);
   glVertex2f(0.0, 25.0);
   glVertex2f(25.0, -25.0);
   glVertex2f(-25.0, -25.0);
   glEnd();
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);

   glLoadIdentity (); // Matriz identidade é carregada pela 1a vez
   glColor3f (1.0, 1.0, 1.0);
   draw_triangle (); // o triangulo é desenhado pela 1a vez sem transformacao

   glEnable (GL_LINE_STIPPLE); // seta linha pontilhada para o cortorno da forma
   glLineStipple (1, 0xF0F0);
   glLoadIdentity (); // matriz identidade eh carregada outra vez
   glTranslatef (-20.0, 0.0, 0.0); // dessa vez a transformação de tranlacao eh aplicada
   draw_triangle (); // o forma eh desenhada ja tranformada

   glLineStipple (1, 0xF00F);
   glLoadIdentity ();
   glScalef (1.5, 0.5, 1.0); // segunda transformacao sobre a matriz id, dessa vez escalonamento
   draw_triangle ();

   glLineStipple (1, 0x8888);
   glLoadIdentity ();
   glRotatef (90.0, 0.0, 0.0, 1.0); // 3a transformacao, rotacao de 90 graus
   draw_triangle ();
   glDisable (GL_LINE_STIPPLE);

   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   if (w <= h)
      glOrtho (-50.0, 50.0, -50.0*(GLfloat)h/(GLfloat)w,
         50.0*(GLfloat)h/(GLfloat)w, -1.0, 1.0);
   else
      glOrtho (-50.0*(GLfloat)w/(GLfloat)h,
         50.0*(GLfloat)w/(GLfloat)h, -50.0, 50.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27: // caso a funcao de teclado identifique a acao na tecla 'Esc' finaliza o programa.
         exit(0);
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Equipe Atomos");
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc (keyboard);
   glutMainLoop();
   return 0;
}
