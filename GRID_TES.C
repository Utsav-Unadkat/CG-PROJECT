#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>

union REGS i,o;

float distance[10][10];
int parent[10][10][2],visit[10][10];
int xs,ys,xe,ye,xb,yb;

void bfill(int x,int y,int col, int ch){
 if(getpixel(x,y)==col && getpixel(x,y)!=WHITE){
  putpixel(x,y,ch);
  bfill(x-1,y,col,ch);
  bfill(x,y-1,col,ch);
  bfill(x,y+1,col,ch);
  bfill(x+1,y,col,ch);
 }
}


void initialize()
{
    int i,j;
    for(i=0;i<10;i++)
    {
	for(j=0;j<10;j++)
	{
	    distance[i][j]=99.0;
	    visit[i][j]=0;
	    parent[i][j][0]=99; //x
	    parent[i][j][1]=99; //y
        }
    }
}

void extract_min(int *x,int *y)
{
    int i,j,min_i,min_j;
    float min_element=100.0;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(min_element>distance[i][j] && visit[i][j]==0)
            {
                min_element=distance[i][j];
                min_i=i;
                min_j=j;
            }
	}
    }
    *x=min_i;
    *y=min_j;
}

float parent_cost(int xp,int yp)
{  
     float cost;
    if (parent[yp][xp][1]==99 && parent[yp][xp][0]==99)
    cost = 0.0;
    else 
    cost = distance[yp][xp];
    return cost;
    
}

void right(int x,int y)
{
    int xp=x,yp=y;
    float old,new;
    if(x<9)
    {   
        x=x+1;
	if (parent[y][x][0]!=100 && parent[y][x][1]!=100)
        {
            old=distance[y][x];
            new = parent_cost(xp,yp) + 1.0;
            if (new<old)
            {
                distance[y][x]=new;
                parent[y][x][0]=xp;
                parent[y][x][1]=yp;
	    }
        }    
    }
}

void right_down(int x,int y)
{
    int xp=x,yp=y;
    float old,new;
    if(x<9 && y<9 &&(parent[yp][xp+1][0]!=100 && parent[yp][xp+1][1]!=100 && parent[yp+1][xp][0]!=100 && parent[yp+1][xp][1]!=100 ))
    {
        x=x+1;
        y=y+1;
	if (parent[y][x][0]!=100 && parent[y][x][1]!=100)
        {
            old=distance[y][x];
            new = parent_cost(xp,yp) + 1.4;
	    if (new<old)
            {
                distance[y][x]=new;
                parent[y][x][0]=xp;
                parent[y][x][1]=yp;
            }   
        }     
    }
}

void down(int x,int y)
{
    int xp=x,yp=y;
    float old,new;
    if(y<9)
    {
	y=y+1;
	if (parent[y][x][0]!=100 && parent[y][x][1]!=100)
	{
	    old=distance[y][x];
	    new = parent_cost(xp,yp) + 1.0;
	    if (new<old)
	    {
		distance[y][x]=new;
		parent[y][x][0]=xp;
		parent[y][x][1]=yp;
	    }
	}
    }
}

void left_down(int x,int y)
{
    int xp=x,yp=y;
    float old,new;
    if(y<9 && x>0 &&(parent[yp][xp-1][0]!=100 && parent[yp][xp-1][1]!=100 && parent[yp+1][xp][0]!=100 && parent[yp+1][xp][1]!=100 ))
    {
	y=y+1;
	x=x-1;
	if (parent[y][x][0]!=100 && parent[y][x][1]!=100)
	{
	    old=distance[y][x];
	    new = parent_cost(xp,yp) + 1.4;
	    if (new<old)
	    {
		distance[y][x]=new;
		parent[y][x][0]=xp;
		parent[y][x][1]=yp;
	    }
	}
    }
}

void left(int x,int y)
{
    int xp=x,yp=y;
    float old,new;
    if(x>0)
    {
	x=x-1;
	if (parent[y][x][0]!=100 && parent[y][x][1]!=100)
	{
	old=distance[y][x];
	new = parent_cost(xp,yp) + 1.0;
	if (new<old)
	{
	    distance[y][x]=new;
	    parent[y][x][0]=xp;
	    parent[y][x][1]=yp;
	}
	}
    }
}

void left_up(int x,int y)
{
    int xp=x,yp=y;
    float old,new;
    if(y>0 && x>0 &&(parent[yp][xp-1][0]!=100 && parent[yp][xp-1][1]!=100 && parent[yp-1][xp][0]!=100 && parent[yp-1][xp][1]!=100 ))
    {
	y=y-1;
	x=x-1;
	if (parent[y][x][0]!=100 && parent[y][x][1]!=100)
	{
	old=distance[y][x];
	new = parent_cost(xp,yp) + 1.4;
	if (new<old)
	{
	    distance[y][x]=new;
	    parent[y][x][0]=xp;
	    parent[y][x][1]=yp;
	}
	}
    }
}

void up(int x,int y)
{
    int xp=x,yp=y;
    float old,new;
    if(y>0)
    {
	y=y-1;
	if (parent[y][x][0]!=100 && parent[y][x][1]!=100)
	{
	old=distance[y][x];
	new = parent_cost(xp,yp) + 1.0;
	if (new<old)
	{
	    distance[y][x]=new;
	    parent[y][x][0]=xp;
	    parent[y][x][1]=yp;
	}
	}
    }
}

void right_up(int x,int y)
{
    int xp=x,yp=y;
    float old,new;
    if(y>0 && x<9 &&(parent[yp][xp+1][0]!=100 && parent[yp][xp+1][1]!=100 && parent[yp-1][xp][0]!=100 && parent[yp-1][xp][1]!=100 ))
    {
	y=y-1;
	x=x+1;
	if (parent[y][x][0]!=100 && parent[y][x][1]!=100)
	{
	old=distance[y][x];
	new = parent_cost(xp,yp) + 1.4;
	if (new<old)
	{
	    distance[y][x]=new;
	    parent[y][x][0]=xp;
	    parent[y][x][1]=yp;
	}
	}
    }
}


void find(int x,int y)
{
    int a,b;
    if ((x>=0 && y>=0) && (distance[ye][xe]==99))
    {
	visit[y][x]=1;
	right(x,y);
	right_down(x,y);
	down(x,y);
	left_down(x,y);
	left(x,y);
	left_up(x,y);
	up(x,y);
	right_up(x,y);
	extract_min(&a,&b);
	find(b,a);
    }
}

void trace()
{
    int x=xe,y=ye,temp,x_co,y_co;
    printf("Tracing back : \n");
    while(x!=xs || y!=ys)
    {
    x_co=parent[y][x][0]*40+1;
    y_co=parent[y][x][1]*40+21;
    bfill(x_co,y_co,getpixel(x_co,y_co),6);
    delay(10);
	temp=parent[y][x][0];
	y=parent[y][x][1];
	x=temp;
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
    distance[ys][xs] = 0;
   }
   if(c=='2')
   {
    xe=xc/40;
    ye=(yc-20)/40;
   }
   if(c=='3')
   {
    xb=xc/40;
    yb=(yc-20)/40;
    parent[yb][xb][0]=100;
    parent[yb][xb][1]=100;
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
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 settextstyle(0,0,1);
 outtextxy(420,0,"WELCOME");
 outtextxy(420,10,"FOLLOW THE SEQUENCE FOR PROPER EXECUTION:");
 outtextxy(420,20,"press 1 and click to select start");
 outtextxy(420,30,"press 2 and click to select end");
 outtextxy(420,40,"press 3 and create obstacle");
 getch();
 for(in=0;in<=360;in=in+40)
{
  for(j=20;j<=380;j=j+40)
  {
   setcolor(RED);
   rectangle(in,j,in+40,j+40);
  }
}
  i.x.ax=1;
  int86(51,&i,&o);
  c=getch();
  fill(c) ;    //start
  c=getch();
  fill(c) ;    //end
  initialize();
  block();

  c=getch();
  printf("xs=%d ys=%d xe=%d ye=%d",xs,ys,xe,ye);
   // printf("****\n Algo Begins \n");
    find(xs,ys);
    trace();
    delay(1000);

  getch();
}
    
