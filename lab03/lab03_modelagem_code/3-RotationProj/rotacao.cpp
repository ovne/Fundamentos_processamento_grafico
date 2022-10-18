/*
 *  rotacao.cpp
 *  Este programa originalmente denominado exemplo1.c foi obtido 
 *  na p�gina Web do Prof. Samuel Nunes, por ser bastante didatico:
 *  http://w3.ualg.pt/~srnunes/CG/index.html
 *  e foi adaptado por Celso Kurashima para a disciplina BC1515
 *  Modificado em 17/10/2022 - Vinicius Oliveira 11201920654
 */


/**
 * Questoes propostas:
 * 
 * - Execute o programa
    - Verifique no código a implementação dos seguintes conceitos:
    . Buffer Duplo
    . Uso das teclas para mudança de cor do desenho.
    . Por que não fez a guarda da Matriz na Pilha?
        ->
    - Responda:
    . Qual o valor do angulo de Rotação: R(theta) em cada apresentação?
        -> theta varia de 0 a 360 a cada 1 grau
*/
/* Inclui os headers do OpenGL, GLU, e GLUT */
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


/**********************************************************************/
/*                        Declara��o de fun��es                       */
/**********************************************************************/
void init_glut(const char *window_name, int *argcp, char **argv);
void display_callback(void);
void reshape_callback(int w, int h);
void animate_callback(void);
void keyboard_callback(unsigned char key, int x, int y);
void keyboard_callback_special(int key, int x, int y);
void menu_callback(int value);


/**********************************************************************/
/*                                                                    */
/*                       Fun��o principal (main)                      */
/*                                                                    */
/**********************************************************************/

int main(int argc, char **argv){

   /* inicia o GLUT e alguns par�metros do OpenGL */
   init_glut("Equipe Atomos", &argc, argv);

   /* fun��o de controlo do GLUT */
   glutMainLoop();

   return 0;
}


/**********************************************************************/
/*                                                                    */
/*                         Defini��o de fun��es                       */
/*                                                                    */
/**********************************************************************/

/*
 * inicia o GLUT e alguns par�metros do OpenGL
 */
void init_glut(const char *nome_janela, int *argcp, char **argv){

    /* inicia o GLUT */
    glutInit(argcp,argv);

    /* inicia o display usando RGB e double-buffering */
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // buffer duplo definido
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow(nome_janela);

    /* define as func�es de callback */
    glutKeyboardFunc(keyboard_callback);
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutSpecialFunc(keyboard_callback_special);
    glutIdleFunc(animate_callback);

    /* define a c�r com a qual a tela ser� apagado */
    glClearColor(0.0,0.0,0.0,0.0);

    /* define a cor de desenho inicial (azul) */
    glColor3f(0.0, 0.0, 1.0);

    return;
}


/*
 * fun��o para controlar o display (desenhar na tela em cada frame)
 */
void display_callback(void){
    static GLfloat angulo = 0.0f; /* por ter sido declarada como "static" dentro *
                                   * de uma funcaoo, esta variavel tem "memoria"  */

    /* Apaga o ecra e reinicia a matriz */
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    /* faz variar o angulo entre 0 e 360 graus */
    angulo++;
    if (angulo >= 360.0) angulo -= 360.0;

    /* desenha um triangulo rodado de acordo com "angulo" */
    glRotatef(angulo, 0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5, -0.289);
        glVertex2f( 0.5, -0.289);
        glVertex2f( 0.0,  0.577);
    glEnd();

    /* troca os buffers, mostrando o que acabou de ser desenhado */
    glutSwapBuffers();
    return;
}


/*
 * Processa o reshape da janela
 */
void reshape_callback(int w, int h){

   /* define a zona da janela onde se vai desenhar.*/
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);

   /* muda para o modo GL_PROJECTION e reinicia a projecao */
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();

   /* adapta a projecao ortogonal de acordo com as dimensoes da janela */
   if (h > w){
      gluOrtho2D(-1.0, 1.0, (GLfloat)-h/(GLfloat)w, (GLfloat)h/(GLfloat)w);
   }else{
      gluOrtho2D((GLfloat)-w/(GLfloat)h, (GLfloat)w/(GLfloat)h, -1.0, 1.0);
   }

   /* muda para o modo GL_MODELVIEW (nao pretendemos alterar a projecao *
    * quando estivermos a desenhar na tela)                              */
   glMatrixMode (GL_MODELVIEW);
   return;
}


/*
 * Fun��o necess�ria para a anima��o
 */
void animate_callback(void){
    glutPostRedisplay(); /* Manda redesenhar o ecra em cada frame */
    return;
}


/*
 * Controlo das teclas normais
 */
void keyboard_callback(unsigned char key, int x, int y){
    if (key==27) exit(0); /* Esc: sai do programa */
    return;
}


/*
 * Controlo das teclas especiais (Cursores, F1 a F12, etc...)
 */
void keyboard_callback_special(int key, int x, int y){
    switch(key){
        case 1:
            glColor3f(0.0, 0.0, 1.0);      /* F1: muda a cor para azul */
            break;

        case 2:
            glColor3f(0.0, 1.0, 0.0);      /* F2: muda a cor para verde */
            break;

        case 3:
            glColor3f(1.0, 0.0, 0.0);      /* F2: muda a cor para vermelho */
            break;

        default: /* isto aqui n�o faz nada, mas evita warnings :P */
            break;
    }

    return;
}

