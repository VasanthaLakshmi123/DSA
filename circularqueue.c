/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*#include <stdio.h>

int main()
{
    printf("Hello World");

    return 0;
}*/
#include <stdio.h>
#include<stdlib.h>
#define MAX 5
int cq[MAX],front=-1,rear=-1;
void insertion();
void deletion();
void display();

int main()
{
    int ch;
    while(1){
    printf("\n\nenter 1 for insertion\n2 for deletion\n3 for display\n4 for exit\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:insertion();break;
        case 2:deletion();break;
        case 3:display();break;
        case 4:exit(1);
    }

    }
    return 0;
}
void insertion(){
    int x;
    printf("enter a value ");
    scanf("%d",&x);
    if((rear+1)%MAX==front){
        printf("cq is full\n");
        return ;
        
    }
    rear=(rear+1)%MAX;
    if(front==-1){
        front=0;
    }
    cq[rear]=x;
    printf("%d is inserted",x);
}
void deletion(){
    int x;
    if(front==-1||rear==-1){
        printf("cq is empty");
        return;
    }
    x=cq[front];
    if(front==rear){
        front=rear=-1;
    }
    front=(front+1)%MAX;
    printf("%d is deleted",x);
    
}
void display(){
    if(front==-1||rear==-1){
        printf("cq is empty\n");
        return;
    }
    int i;
    for( i=front;i!=rear;i=(i+1)%MAX){
        printf("%d\n",cq[i]);
    }
    printf("%d",cq[i]);
}
