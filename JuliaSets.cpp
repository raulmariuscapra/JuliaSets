#include<iostream>
#include<graphics.h>
#include<cmath>

class complex
{
public:
    float real,imag;
    complex(float a=0,float b=0)
    {
        real=a;
        imag=b;
    }
    complex operator+(complex const &x)
    {
        complex y;
        y.real=real+x.real;
        y.imag=imag+x.imag;
        return y;
    }
    complex operator-(complex const &x)
    {
        complex y;
        y.real=real-x.real;
        y.imag=imag-x.imag;
        return y;
    }
    complex operator*(complex const &x)
    {
        complex y;
        y.real=real*x.real-imag*x.imag;
        y.imag=imag*x.real+x.imag*real;
        return y;
    }
    complex operator/(complex const &x)
    {
        complex y;
        y.real=(real*x.real+imag*x.imag)/(x.real*x.real+x.imag*x.imag);
        y.imag=(+imag*x.real-x.imag*real)/(x.real*x.real+x.imag*x.imag);
        return y;
    }
};

complex julia(complex xvechi,complex constanta)
{
    return xvechi*xvechi+constanta;
}

int main()
{
    int i,j,k,iter=255,xmax=800,ymax=800,escape;
    float tal=0.000001;
    complex z,constanta;
    initwindow(xmax,ymax);
    setbkcolor(BLACK);
    cleardevice();
    float x,y;
    std::cin>>x>>y;
    constanta=complex(x,y);
    for(i=0;i<xmax;i++)
    {
        for(j=0;j<ymax;j++)
        {
            z=complex((i-xmax/2.0)/(xmax/3.5),(ymax/2.0-j)/(ymax/3.5));
            escape=0;
            for(k=1;k<iter;k++)
            {
                z=julia(z,constanta);
                if(z.real>2||z.real<-2||z.imag>2||z.imag<-2)
                {
                    escape=k;
                    break;
                }
            }
            if(escape!=0)
            {
                //std::cout<<escape<<std::endl;
                if(escape<15)
                {
                    putpixel(i,j,COLOR(0,0,0));
                }
                else if(escape<20)
                {
                    putpixel(i,j,COLOR(255,255,0));
                }
                else if(escape<25)
                {
                    putpixel(i,j,COLOR(100,255,0));
                }
                else if(escape<30)
                {
                    putpixel(i,j,COLOR(0,255,0));
                }
                else if(escape<40)
                {
                    putpixel(i,j,COLOR(0,255,100));
                }
                else if(escape<50)
                {
                    putpixel(i,j,COLOR(0,255,255));
                }
                else if(escape<60)
                {
                    putpixel(i,j,COLOR(0,100,255));
                }
                else if(escape<70)
                {
                    putpixel(i,j,COLOR(0,0,255));
                }
                else if(escape<80)
                {
                    putpixel(i,j,COLOR(100,0,255));
                }
                else if(escape<90)
                {
                    putpixel(i,j,COLOR(255,0,255));
                }
                else
                {
                    putpixel(i,j,COLOR(255,255,255));
                }
            }
        }
    }/*
    setcolor(WHITE);
    moveto(0,ymax/2);
    lineto(xmax,ymax/2);
    moveto(xmax/2,0);
    lineto(xmax/2,ymax);*/
    getch();
    closegraph();
    return 0;
}
