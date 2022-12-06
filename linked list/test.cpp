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
void Clip(int c, float* x, float* y, float m, float k)
{
std::cout<<"Enterred clipping"<<std::endl;
    int x_random, y_random;
    if(c & top){
        x_random = (ymax - k)/m;
        y_random = ymax;
        std::cout<<"Inside top"<< std::endl;
        if(y_random == m*x_random + k)
        {
            *x = x_random;
            *y = y_random;
        }
    }
    if(c & bottom){
        x_random = (ymin - k)/m;
        y_random = ymin;
        
        std::cout<<"Inside bottom"<<std::endl;
        if(y_random == m*x_random + k)
        {
            *x = x_random;
            *y = y_random;
        }
    }
    if(c & right){
        x_random = xmax;
        y_random = m*xmax + k;
        
        std::cout<<"Inside right"<< std::endl;
          if(y_random == m*x_random + k)
        {
            *x = x_random;
            *y = y_random;
        }
    
    }
    if(c & left){
        x_random = xmin;
        y_random = m * xmin + k;
        
        std::cout<<"Inside left"<< std::endl;
           if(y_random == m*x_random + k)
        {
            *x = x_random;
            *y = y_random;
        }
       
    }
    std::cout<<"Left clipping"<<std::endl;
}
void Cohen(float x1, float y1, float x2, float y2){
   std::cout<<"("<<x1<<","<<y1<<","<<x2<<","<<y2<<")"<< std::endl;
    
    int c1 = getCode(x1, y1);
    int c2 = getCode(x2, y2);
    std::cout<<"c1 :: "<<c1<<"c2 :: "<<c2<< std::endl;
    float m = (y2 - y1)/(x2 - x1);
    float k = y1 - m*x1;
    std::cout<<"m :: "<<m<<"const c :: "<<k<< std::endl;
    if(c1 | c2 == 0){
        Line(x1,y1,x2,y2);
    }
    else if(c1 & c2 == 0){
        if(c1 != 0){
            //Clip
            Clip(c1,&x1,&y1,m,k);
        }
        if(c2 != 0){
            //Clip
            Clip(c2,&x2,&y2,m,k);
        }
        std::cout<<"("<<x1<<","<<y1<<","<<x2<<","<<y2<<")"<< std::endl;
        std::cout<<"------------------------------"<< std::endl;
        Line(x1,y1,x2,y2);
    }
}
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