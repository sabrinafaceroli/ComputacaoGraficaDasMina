#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <math.h>

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

// Estrutura de dados
typedef struct coordinates{
    double x,y;
} coordinates;

// Vetores
coordinates pos;
coordinates dis;
coordinates oldPosition;
coordinates mouse;

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glOrtho(-SCREEN_WIDTH/2, SCREEN_WIDTH/2, -SCREEN_HEIGHT/2, SCREEN_HEIGHT/2, -100, 100);
    
    // Desenhando
    
    //vermelho
    glColor3f(1,0,0);
    glTranslated(pos.x, pos.y, 0);
    // Define os vértices de um triângulo
    glBegin(GL_TRIANGLES);
    glVertex2f(125.0f, -190.0f);
    glVertex2f(126.0f, -150.0f);
    glVertex2f(119.0f,  -160.0f);
    glEnd();
    
    
    // Desenhando
    //verdao <3
    glColor3f(0,1,0);
    glTranslated(pos.x-15, pos.y-5, 0);
    // Define os vértices de um triângulo
    glBegin(GL_TRIANGLES);
    glVertex2f(125.0f, -190.0f);
    glVertex2f(126.0f, -150.0f);
    glVertex2f(119.0f,  -160.0f);
    glEnd();
    
    
    // Desenhando
    //azul
    glColor3f(0,0,1);
    glTranslated(pos.x-20, pos.y-10, 0);
    // Define os vértices de um triângulo
    glBegin(GL_TRIANGLES);
    glVertex2f(125.0f, -190.0f);
    glVertex2f(126.0f, -150.0f);
    glVertex2f(119.0f,  -160.0f);
    glEnd();
    
    glFlush();
    glutSwapBuffers();
}

void position(int btn, int state, int x, int y){
    //orginal
    mouse.x = x - SCREEN_WIDTH/2;
    mouse.y = -y + SCREEN_HEIGHT/2;
    dis.x = mouse.x - pos.x;
    dis.y = mouse.y - pos.y;
    oldPosition = pos;
}

void move(double speed){
    
    // se clicou pelo menos uma vez
    if(dis.x != 0 && dis.y != 0){
        if(
           pos.x >= SCREEN_WIDTH/2 ||
           pos.y >= SCREEN_HEIGHT/2 ||
           pos.x <= (-1)*SCREEN_WIDTH/2 ||
           pos.y <= (-1)*SCREEN_HEIGHT/2
           ){ pos = oldPosition;
        }
        else{
            double radian = atan2(dis.y, dis.x);
            pos.x += cos(radian) * speed;
            pos.y += sin(radian) * speed;
        }
    }
}

void update(int value){
    move(20);
    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

void init(){
    
    //Configuracoes
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    //Define o tamanho da janela
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    //Define o nome da janela
    glutCreateWindow("CG das Mina");
    // Define cor de fundo da cena
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // Pinta a tela com a cor definida acima
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    glutDisplayFunc(display);
    glutMouseFunc(position);
    glutTimerFunc(25, update, 0);
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    init();
    glutMainLoop();
    return 0;
}
