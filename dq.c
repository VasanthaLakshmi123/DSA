
#include <stdio.h>
#include<stdlib.h>
#define MAX 5
int dq[MAX],front=-1,rear=-1;
void insertf();
void insertr();
void deletef();
void deleter();
void display();

int main()
{
    int ch;
    while(1){
    printf("\n\nenter 1 for insertf\n2 for deletef\n3 for insertr\n4 for deleter\n5 for display\n6 for eixt\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:insertf();break;
        case 2:deletef();break;
        case 3:insertr();break;
        case 4:deleter();break;
        case 5:display();break;
        case 6:exit(1);
    }

    }
    return 0;
}
void insertf(){
    int x;
    printf("enter a value ");
    scanf("%d",&x);
    if(front==0&&rear==MAX-1){
        printf("dq is full\n");
        return;
        
    }
   else if(front==-1&&rear==-1){
       ++front;
       dq[front]=x;
    if(rear==-1){
        rear=0;
    }
   }else if(front!=0){
    --front;
    dq[front]=x;
   }
   else if(front==0&&rear!=MAX-1){
       int i;
       for(i=rear;i>=front;i--){
           dq[i+1]=dq[i];
       }
       dq[i+1]=x;
       ++rear;
   }
    printf("%d is inserted",x);
}
void deletef(){
    int x;
    if(front==-1||rear==-1){
        printf("q is empty");
        return;
    }
    x=dq[front];
    if(front==rear){
        front=rear=-1;
    }
    else{
    ++front;
    }
    printf("%d is deleted",x);
    
}
void insertr(){
    int x;
    int i;
    printf("enter a value ");
    scanf("%d",&x);
    if(front==0&&rear==MAX-1){
        printf("dq is full\n");
        return ;
        
    }
   else if(front==-1&&rear==-1){
       ++rear;
       dq[rear]=x;
    if(front==-1){
        front=0;
    }
   }else if(rear!=MAX-1){
    ++rear;
    dq[rear]=x;
   }
   else if(front!=0&&rear==MAX-1){
     
       for(i=front;i<=rear;i++){
           dq[i-1]=dq[i];
       }
       dq[i-1]=x;
       --front;
   }
    printf("%d is inserted",x);
}
void deleter(){
    int x;
    if(front==-1&&rear==-1){
        printf("q is empty");
        return;
    }
    x=dq[rear];
    if(front==rear){
        front=rear=-1;
    }
    --rear;
    printf("%d is deleted",x);
    
}
void display(){
    int i;
    if(front==-1||rear==-1){
        printf("q is empty\n");
        return;
    }
    for(i=front;i<=rear;i++){
        printf("%d\n",dq[i]);
    }
}
