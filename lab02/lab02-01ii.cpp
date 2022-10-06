/*
* Meu Primeiro Programa: lab02-01ii.cpp
* Vinicius Souza de Oliveira, RA 11201920654, data 04/10/22
*/

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

// Função callback chamada para fazer o desenho
void Desenha(void)
{
//Limpa a janela de visualização com a cor de fundo especificada
glClear(GL_COLOR_BUFFER_BIT);
//Executa os comandos OpenGL
glFlush();
}
// Inicializa parâmetros de rendering
void Inicializa (void)
{
// Define a cor de fundo da janela de visualização como preta
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
// Programa Principal
int main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutCreateWindow("Meu Primeiro Programa");
glutDisplayFunc(Desenha);
Inicializa();
glutMainLoop();
return 0;
}
