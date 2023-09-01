
#include <stdio.h>
#include<stdlib.h>
#define MAX 5
int q[MAX],front=-1,rear=-1;
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
    if(rear==MAX-1){
        printf("q is full\n");
        return ;
        
    }
    ++rear;
    if(front==-1){
        front=0;
    }
    q[rear]=x;
    printf("%d is inserted",x);
}
void deletion(){
    int x;
    if(front==-1||rear==-1){
        printf("q is empty");
        return;
    }
    x=q[front];
    if(front==rear){
        front=rear=-1;
    }
    ++front;
    printf("%d is deleted",x);
    
}
void display(){
    if(front==-1||rear==-1){
        printf("q is empty\n");
        return;
    }
    for(int i=front;i<=rear;i++){
        printf("%d\n",q[i]);
    }
}
