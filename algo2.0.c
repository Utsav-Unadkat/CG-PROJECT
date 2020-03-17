#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

float distance[5][5];
int parent[5][5][2],visit[5][5];
int xs,ys,xe,ye,xb,yb;

void initialize()
{
    int i,j;
    char c='1';
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {  
            distance[i][j]=99.0;
            visit[i][j]=0;
            parent[i][j][0]=99; //x
            parent[i][j][1]=99; //y
        }
    }
    printf("Enter xs: ");
    scanf("%d",&xs);
    printf("Enter ys: ");
    scanf("%d",&ys);
    printf("Enter xe: ");
    scanf("%d",&xe);
    printf("Enter ye: ");
    scanf("%d",&ye);
    distance[ys][xs] = 0;
    while(c=='1')
    {
        printf("Enter xb: ");
        scanf("%d",&xb);
        printf("Enter yb: ");
        scanf("%d",&yb);
        parent[yb][xb][0]=100;
        parent[yb][xb][1]=100;
        visit[yb][xb]=2;
        //printf("%d %d\n", parent[yb][xb][0], parent[yb][xb][1]);
        c=getch();
    }
}

void extract_min(int *x,int *y)
{
    int i,j,min_i,min_j;
    float min_element=100.0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
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

void display()
{
    int i,j;
    printf("visit array \n\n");
    for(i=0;i<5;i++)
    {
        for (j=0;j<5;j++)
        {
            printf("%d ",visit[i][j]);
        }
        printf("\n");
    }
    printf("distance array \n\n");
    for(i=0;i<5;i++)
    {
        for (j=0;j<5;j++)
        {
            printf("%f ",distance[i][j]);
        }
        printf("\n");
    }
    printf("parent array \n\n");
    for(i=0;i<5;i++)
    {
        for (j=0;j<5;j++)
        {
            printf("%d,%d ",parent[i][j][0],parent[i][j][1]);
        }
        printf("\n");
    }
}

void right(int x,int y)
{
    int xp=x,yp=y;
    float old,new;
    if(x<4)
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
    if(x<4 && y<4)
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
    if(y<4)
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
    if(y<4 && x>0)
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
        printf("%d %d---",parent[y][x][0],parent[y][x][1]);
        if (parent[y][x][0]!=100 && parent[y][x][1]!=100)
        {
        old=distance[y][x];
        new = parent_cost(xp,yp) + 1.0;
        printf("%d %d---\n",x,y);
        //printf("%f %f --%d,%d\n",old,new,xp,yp);
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
    if(y>0 && x>0)
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
    if(y>0 && x<4)
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
    int x=xe,y=ye,temp;
    printf("Tracing back : \n");
    while(x!=xs || y!=ys)
    {
        printf("%d,%d \n",parent[y][x][0],parent[y][x][1]);
        temp=parent[y][x][0];
        y=parent[y][x][1];
        x=temp;
    }
}
void main()
{

    initialize();
    //display();
    printf("****\n Algo Begins \n");
    find(xs,ys);
    display();
    trace();
    
}