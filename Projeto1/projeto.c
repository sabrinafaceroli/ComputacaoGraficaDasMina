//#include <OpenGL/gl.h>
//#include <OpenGl/glu.h>
#include<GL/glut.h>
#include <math.h>

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

// Estrutura de dados
typedef struct coordinates{
    double x,y;
} coordinates;

// vetores
coordinates trianglesCoord[3];
coordinates oldPositions[3];
coordinates dis[3];
coordinates mouse;
double speed[3];

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glOrtho(-SCREEN_WIDTH/2, SCREEN_WIDTH/2, -SCREEN_HEIGHT/2, SCREEN_HEIGHT/2, -100, 100);
    
    // Desenhando
    
    //vermelho
    glColor3f(1,0,0);
    glTranslated(trianglesCoord[0].x, trianglesCoord[0].y, 0);

     //glutSolidTeapot(10);


    //Define os vértices de um triângulo
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(20.0f, 0.0f);
    glVertex2f(0.0f, 20.0f);
    glEnd();
    glLoadIdentity();
    glOrtho(-SCREEN_WIDTH/2, SCREEN_WIDTH/2, -SCREEN_HEIGHT/2, SCREEN_HEIGHT/2, -100, 100);
    
    
    // Desenhando
    //verdao <3
    glColor3f(0,1,0);
    glTranslated(trianglesCoord[1].x, trianglesCoord[1].y, 0);
    // Define os vértices de um triângulo
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(20.0f, 0.0f);
    glVertex2f(0.0f, 20.0f);
    glEnd();
    glLoadIdentity();
    glOrtho(-SCREEN_WIDTH/2, SCREEN_WIDTH/2, -SCREEN_HEIGHT/2, SCREEN_HEIGHT/2, -100, 100);
    
    
    // Desenhando
    //azul
    glColor3f(0,0,1);
    glTranslated(trianglesCoord[2].x, trianglesCoord[2].y, 0);
    // Define os vértices de um triângulo
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(20.0f, 0.0f);
    glVertex2f(0.0f, 20.0f);
    glEnd();
    
    glFlush();
    glutSwapBuffers();
}

void position(int btn, int state, int x, int y){
    //orginal
    int i;
    mouse.x = x - SCREEN_WIDTH/2;
    mouse.y = -y + SCREEN_HEIGHT/2;
    for (i = 0; i < 3; i++){
        dis[i].x = mouse.x - trianglesCoord[i].x;
        dis[i].y = mouse.y - trianglesCoord[i].y;
        oldPositions[i] = trianglesCoord[i];
    }   
}

void move(){
    int i;
    
    // se clicou pelo menos uma vez
    for(i = 0; i < 3; i++){
        if(dis[i].x != 0 && dis[i].y != 0){
            if(
                trianglesCoord[i].x >= SCREEN_WIDTH/2 ||
                trianglesCoord[i].y >= SCREEN_HEIGHT/2 ||
                trianglesCoord[i].x <= (-1)*SCREEN_WIDTH/2 ||
                trianglesCoord[i].y <= (-1)*SCREEN_HEIGHT/2
            ){ 
                trianglesCoord[i] = oldPositions[i];
            }
            else{
                double radian = atan2(dis[i].y, dis[i].x);
                trianglesCoord[i].x += cos(radian) * speed[i];
                trianglesCoord[i].y += sin(radian) * speed[i];
            }
    }

    }
    
}

void update(int value){
    move();
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

    //Seta o metodo de projecao da matriz (nao tem nenhuma projecao inicial, estamos trabalhando em 2D)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv){

// inicializando as coordenadas dos triangulos
    trianglesCoord[0].x=0;
    trianglesCoord[0].y=0;

    trianglesCoord[1].x=50; 
    trianglesCoord[1].y=50;

    trianglesCoord[2].x=100;
    trianglesCoord[2].y=100;

    speed[0] = 5;
    speed[1] = 10;
    speed[2] = 15;

    glutInit(&argc, argv);
    init();
    glutMainLoop();
    return 0;
}
