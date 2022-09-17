#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cmath>
#include <GL/gl.h> 
#include <GL/glut.h>
using namespace std;
double x[13]={0,-1.0135,-2.4335,-3.4015,-3.1595,-2.06,0,1.94,2.78,3.2,2.34,0.91,0};
double y[13]={2,3.1336,3.3016,2.1136,1.0136,0,-1.6044,0,0.9696,2.0476,3.2796,3.1036,2};
//double x[13] = { 0, -1.7, -3.4, -2.8, -2, -1, 0, 1, 2, 2.8, 3.4, 1.7 ,0}; //3-B
//double y[13] = {2, 4, 3, 1.2, 0, -1, -2, -1, 0, 1.2, 3, 4, 2}; //3-B
double t[13],l[13],cxy[14][4],sum,sxy[4][8][2];
//Horner’s Algorithm
double NT(int fx,double v){
	double rt=cxy[12][fx];
	for(int i=11;i>=0;--i){
		if(fx<2)
			rt=rt*(v-t[i])+cxy[i][fx];
		else
			rt=rt*(v-i)+cxy[i][fx];
	}
	return rt;
}
//wrong but work
double NTD(int ba,int fx,double v){
	double rt=cxy[ba][fx];
	for(int i=1;i<=ba;++i){
		rt=rt*(v-(ba-i))+cxy[ba-i][fx];
	}
	return rt;
}
//ac
double NNTD(int l,int ba,int fx,double v){
	double rt=sxy[l][3][fx];
	for(int i=2;i>=0;--i){
		rt=rt*(v-(i+l))+sxy[l][i][fx];
	}
	return rt;
}
//S'
double Sixy(int it,int l,int fx,double v){
	double rt=sxy[l][0][fx];
	rt+=sxy[l][1][fx]*v;
	rt+=sxy[l][2][fx]*2*v-(it*2+1);
	rt+=sxy[l][3][fx]*3*v*v-((it+1)*6)*v;
	if(it==0){
		rt+=2;
	}
	else if(it==1){
		rt+=11;
	}
	else if(it==2){
		rt+=26;
	}
	else{
		rt+=47;
	}
	return rt;
}
//draw
void myDisplay() {
	
	glBegin(GL_LINES);
	glColor3f(0.8,0.8,0.8);
	for (float i = -20; i < 20; ++i) {
		glVertex2f(-1.0, i/20);
		glVertex2f(1.0, i/20);
		glVertex2f(i/20, 1.0);
		glVertex2f(i/20, -1.0);
	}
	glEnd();
	
	//畫單位點
	glPointSize(3);    //點的大小
	glBegin(GL_POINTS); //選擇畫點
	glColor3f(0, 0, 0);
	for (float i = -20; i < 20; i++) {
		glVertex2f(0.0, i / 20);
		glVertex2f(i / 20, 0.0);
	}
	glEnd();
	//draw heart
    glColor3f(0, 0, 1);
    glPolygonMode(GL_FRONT, GL_LINE);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 12; ++i) 
        glVertex2f(x[i] / 5, y[i] / 5);
    glEnd();
    //draw Chord-length
    glBegin(GL_LINE_STRIP);
    for(double i=0;i<t[12];i+=t[12]/40){
    	double xx=NT(0,i)/5,yy=NT(1,i)/5;
    	glColor3f(0, 0.8, 0);
    	glVertex2f(xx,yy);
	}
	glEnd();
	//draw Uniform
	glBegin(GL_LINE_STRIP);
    for(double i=0;i<t[12];i+=t[12]/40){
    	double xx=NT(2,i)/5,yy=NT(3,i)/5;
    	glColor3f(0.8, 0, 0);
    	glVertex2f(xx,yy);
	}
	glEnd();
	
	
	//draw 4.A
	/*
	glBegin(GL_LINE_STRIP);
    for(double i=0;i<=2;i+=0.05){
    	double xx=NTD(3,2,i)/5,yy=NTD(3,3,i)/5;
    	glColor3f(0, 0, 0);
    	glVertex2f(xx,yy);
	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
    for(double i=2;i<=3;i+=0.05){
    	double xx=NTD(4,2,i)/5,yy=NTD(4,3,i)/5;
    	glColor3f(0, 0, 0);
    	glVertex2f(xx,yy);
	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
    for(double i=3;i<=4;i+=0.05){
    	double xx=NTD(5,2,i)/5,yy=NTD(5,3,i)/5;
    	glColor3f(0, 0, 0);
    	glVertex2f(xx,yy);
	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
    for(double i=4;i<=6;i+=0.05){
    	double xx=NTD(6,2,i)/5,yy=NTD(6,3,i)/5;
    	glColor3f(0, 0, 0);
    	glVertex2f(xx,yy);
	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
    for(double i=0;i<=2;i+=0.05){
    	double xx=NTD(3,2,i)/5,yy=NTD(3,3,i)/5;
    	glColor3f(0, 0, 0);
    	glVertex2f(-xx,yy);
	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
    for(double i=2;i<=3;i+=0.05){
    	double xx=NTD(4,2,i)/5,yy=NTD(4,3,i)/5;
    	glColor3f(0, 0, 0);
    	glVertex2f(-xx,yy);
	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
    for(double i=3;i<=4;i+=0.05){
    	double xx=NTD(5,2,i)/5,yy=NTD(5,3,i)/5;
    	glColor3f(0, 0, 0);
    	glVertex2f(-xx,yy);
	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
    for(double i=4;i<=6;i+=0.05){
    	double xx=NTD(6,2,i)/5,yy=NTD(6,3,i)/5;
    	glColor3f(0, 0, 0);
    	glVertex2f(-xx,yy);
	}
	glEnd();
    */
    //4.A end
    //4.A 
    glBegin(GL_LINE_STRIP);
    for(double i=0;i<=2;i+=0.05){
    	double xx=NNTD(0,3,0,i)/5,yy=NNTD(0,3,1,i)/5;
    	glColor3f(0, 0, 0);
    	glVertex2f(xx,yy);
	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
    for(double i=2;i<=3;i+=0.05){
    	double xx=NNTD(1,3,0,i)/5,yy=NNTD(1,3,1,i)/5;
    	glColor3f(0, 0, 0);
    	glVertex2f(xx,yy);
	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
    for(double i=3;i<=4;i+=0.05){
    	double xx=NNTD(2,3,0,i)/5,yy=NNTD(2,3,1,i)/5;
    	glColor3f(0, 0, 0);
    	glVertex2f(xx,yy);
	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
    for(double i=4;i<=6;i+=0.05){
    	double xx=NNTD(3,3,0,i)/5,yy=NNTD(3,3,1,i)/5;
    	glColor3f(0, 0, 0);
    	glVertex2f(xx,yy);
	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
    for(double i=0;i<=2;i+=0.05){
    	double xx=NNTD(0,3,0,i)/5,yy=NNTD(0,3,1,i)/5;
    	glColor3f(0, 0, 0);
    	glVertex2f(-xx,yy);
	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
    for(double i=2;i<=3;i+=0.05){
    	double xx=NNTD(1,3,0,i)/5,yy=NNTD(1,3,1,i)/5;
    	glColor3f(0, 0, 0);
    	glVertex2f(-xx,yy);
	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
    for(double i=3;i<=4;i+=0.05){
    	double xx=NNTD(2,3,0,i)/5,yy=NNTD(2,3,1,i)/5;
    	glColor3f(0, 0, 0);
    	glVertex2f(-xx,yy);
	}
	glEnd();
	
	glBegin(GL_LINE_STRIP);
    for(double i=4;i<=6;i+=0.05){
    	double xx=NNTD(3,3,0,i)/5,yy=NNTD(3,3,1,i)/5;
    	glColor3f(0, 0, 0);
    	glVertex2f(-xx,yy);
	}
	glEnd();
    //4.A end
    glFlush();
}

int main(int argc, char **argv){
	//distance of 2 points
	for(int i=0;i<12;++i){
		l[i]=sqrt((x[i]-x[(i+1)])*(x[i]-x[(i+1)])+(y[i]-y[(i+1)])*(y[i]-y[(i+1)])); 
	}
	//distance sum
	for(int i=0;i<13;++i){
		t[i]=sum;
		sum+=l[i];
	}
	cout << "1.A\n";
	cout << "i :";
	for(int i=0;i<=12;++i)
		cout << fixed  <<  setprecision(2) << setw(5) << i << '|';
	cout << "\nt :";
	for(int i=0;i<=12;++i)
		cout << fixed  <<  setprecision(2) << setw(5) << t[i] << '|';
	cout << "\nx :";
	for(int i=0;i<=12;++i)
		cout << fixed  <<  setprecision(2) << setw(5) << x[i] << '|';
	cout << "\ny :";
	for(int i=0;i<=12;++i)
		cout << fixed  <<  setprecision(2) << setw(5) << y[i] << '|';
	cout << "\n1.B\n";
	cout << "i :";
	for(int i=0;i<=12;++i)
		cout << fixed  <<  setprecision(2) << setw(5) << i << '|';
	cout << "\nt :";
	for(int i=0;i<=12;++i)
		cout << fixed  <<  setprecision(2) << setw(5) << i << '|';
	cout << "\nx :";
	for(int i=0;i<=12;++i)
		cout << fixed  <<  setprecision(2) << setw(5) << x[i] << '|';
	cout << "\ny :";
	for(int i=0;i<=12;++i)
		cout << fixed  <<  setprecision(2) << setw(5) << y[i] << '|';
	cout << "\n\n2.A\n Chord-length X Chord-length Y    Uniform X      Uniform Y\n";
	for(int ca=0;ca<4;++ca){
		for(int i=0;i<=12;++i){
			if(ca%2==0)
				cxy[i][ca]=x[i];
			else
				cxy[i][ca]=y[i];
		}
		for(int k=1;k<=12;++k){
			for(int j=12;j>=k;--j){
				if(ca>1)
					cxy[j][ca]=(cxy[j][ca]-cxy[j-1][ca])/k;
				else
					cxy[j][ca]=(cxy[j][ca]-cxy[j-1][ca])/(t[j]-t[j-k]);
			}
		}
	}
	
	for(int ca=0;ca<=12;++ca){
		for(int i=0;i<4;++i)
			cout << fixed  <<  setprecision(10)  << setw(14) << cxy[ca][i] << " ";
		cout << "\n";
	}
	//4.A si
	cout << "\n4.A\n";
	for(int ta=0;ta<4;++ta){
		for(int i=0;i<=3;++i){
			sxy[ta][i][0]=x[i+ta];
			sxy[ta][i][1]=y[i+ta];
		}
		for(int k=1;k<=3;++k){
			for(int j=3;j>=k;--j){
				sxy[ta][j][0]=(sxy[ta][j][0]-sxy[ta][j-1][0])/(k);
				sxy[ta][j][1]=(sxy[ta][j][1]-sxy[ta][j-1][1])/(k);
			}
		}
		cout << "S" << ta << "cx:";
		for(int i=0;i<=3;++i){
			cout << setw(14) << sxy[ta][i][0] << " ";
		}
		cout << "\n";
		cout << "S" << ta << "cy:";
		for(int i=0;i<=3;++i){
			cout << setw(14) << sxy[ta][i][1] << " ";
		}
		cout << "\n";
	}
	
	cout << "\n4.B  t  =" << setw(10) << "2" << setw(14) << "3" << setw(16) << "4\n";
	for(int ca=0;ca<4;++ca){
		cout << "S" << ca << """'x(t) = ";
		for(int i=2;i<=4;++i){
			cout << setw(14) << Sixy(ca,ca,0,i) << " ";
		}
		cout << "\n";
		cout << "S" << ca << """'y(t) = ";
		for(int i=2;i<=4;++i){
			cout << setw(14) << Sixy(ca,ca,1,i) << " ";
		}
		cout << "\n";
	}
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowPosition(400, 200);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Heart");
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(&myDisplay);
    glutMainLoop();
    return 0;
} 
