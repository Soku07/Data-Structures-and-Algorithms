#include <iostream>
#include <GL/glut.h>

int xmin = 300, xmax = 600, ymin = 300,ymax = 600;
int top = 8, bottom = 4, right = 2, left = 1;
void Line(float x1, float y1, float x2, float y2){

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2i(x1,y1);
    glVertex2i(x2,y2);
	glEnd();
	glFlush();
}


int getCode(int x, int y){

    int code = 0;
    if(x < xmin){
        code = code | left;
    }
    if(x > xmax){
        code = code | right;

    }
    if(y < ymin){
        code = code | bottom;
    }
    if(y > ymax)
    {
        code = code  | top; 
    }
    return code;
}
void Clip(int c1,int c2,float* x1, float* y1,float* x2, float* y2 ){
    int c;
    float m = (y2-y1)/(x2-x1);
    int x = *x1, y = y1;
    float x_random, y_random;
    if(c1){
        c = c1;
        
    }
    if(c2){
        c = c2;
       
    }
    if(c & left){
        x_random = xmin;
        y_random = y + m*(xmin - x);
    }
     if(c & right){
        x_random = xmax;
        y_random = y + m*(xmax - x);
    }
    if(c & top){
        y_random = ymax;
        x_random = x + (ymax - y)/m;
    }
    if(c & bottom){
        y_random = ymin;
        x_random = x + (ymin - y)/m;
    }
    if(c == c1){
        *x1 = x_random;
        *y1 = y_random; 
    }
    else
    {
        *x2 = x_random;
        *y2 = y_random;
    }
    

}
void Cohen(float x1, float y1, float x2, float y2){
   std::cout<<"("<<x1<<","<<y1<<","<<x2<<","<<y2<<")"<< std::endl;
    
    int c1, c2;
    float m = (y2 - y1)/(x2 - x1);
    while(1){
        c1 = getCode(x1,y1);
        c2 = getCode(x2,y2);
        if(c1 | c2 == 0){
            break;
        }
        else if(c1 & c2 == 0){
            Clip(c1,c2,&x1,&y1,&x2,&y2);
        }

    }
    Line(x1,y1,x2,y2);
	
void myInit(void){

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,800,0,800);

}

void DrawViewPort(){

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin,ymin);
    glVertex2i(xmax,ymin);
    glVertex2i(xmax,ymax);
    glVertex2i(xmin,ymax);
    glEnd();
    glFlush();
}

void primitives()
{
	DrawViewPort();
	Cohen(400,400,500,500);
	Cohen(100,400,400,500);
}

int main(int argc, char** v)
{
    glutInit(&argc, v);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Line Clipping");
    myInit();
    glutDisplayFunc(primitives);
    glutMainLoop();
    return 0;
}