#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>


union REGS i,o;

int xs,ys,xe,ye;


void bfill(int x,int y,int col, int ch){
 if(getpixel(x,y)==col && getpixel(x,y)!=WHITE){
  putpixel(x,y,ch);
  bfill(x-1,y,col,ch);
  bfill(x,y-1,col,ch);
  bfill(x,y+1,col,ch);
  bfill(x+1,y,col,ch);
 }
}

void fill(char c)
{
 int xc,yc,ch;
 while(!kbhit()){
  i.x.ax=3;
  int86(51,&i,&o);
  if(o.x.bx==1)
  {
   xc=o.x.cx;
   yc=o.x.dx;
   i.x.ax=2;
   int86(51,&i,&o);
   bfill(xc,yc,BLACK,c);
   i.x.ax=1;
   int86(51,&i,&o);
   if (c=='1')
   {
    xs=xc/40;
    ys=(yc-20)/40;
   }
   if(c=='2')
   {
    xe=xc/40;
    ye=(yc-20)/40;
    printf("%d %d ",xe,ye);
   }
   break;
  }
 }
}

void block()
{
 char c;
 c=getch();
 if(c=='3')
 {
  fill(c);
  block() ;
 }
}

void main()
{
 int gd=DETECT,gm;
 int in,j,xc,yc;
 char c='1';
 printf("WELCOME\n");
 printf("FOLLOW THE SEQUENCE FOR PROPER EXECUTION:\n");
 printf("_______________\n");
 printf("press 1 and click to select start");
 printf("\npress 2 and click to select end");
 printf("\npress 3 and create obstacle");
 getch();
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 for(in=0;in<=160;in=in+40)
{
  for(j=20;j<=180;j=j+40)
  {
   setcolor(RED);
   rectangle(in,j,in+40,j+40);
  }
}
  i.x.ax=1;
  int86(51,&i,&o);
  c=getch();
  fill(c) ;  //start
  c=getch();
  fill(c) ;        //end
  block();

  c=getch();
  printf("xs=%d ys=%d xe=%d ye=%d",xs,ys,xe,ye);

  if(c=='0')
  printf("hi");
  else
  printf("LOL");
  getch();
}



