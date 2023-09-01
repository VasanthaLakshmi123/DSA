
#include <stdio.h>
#include<stdlib.h>
void addFirst();
void addLast();
void deleteFirst();
void deleteLast();
int listSize();
void insert(int pos);
void deletePos(int pos);
void reverseData();
void display();
struct node
{
    int data;
    struct node *addr;
};
typedef struct node node;
node *head=NULL,*tail=NULL,*temp;
node *createNode(){
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL){
        printf("node is not created\n");
        return 0;
    }
    printf("enter");
    scanf("%d",&temp->data);
    temp->addr=NULL;
    return temp;
}
int main()
{
    int ch;
    while(1){
        printf("\n1 for addFirst\n2 for addLast\n3 for deletFirst\n4 for deleteLast\n5 for listsize\n6 for insert\n7 for display\n8for exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:addFirst();break;
            case 2:addLast();break;
            case 3:deleteFirst();break;
            case 4:deleteLast();break;
            case 5:listSize();break;
            case 6:int pos;printf("enter position\n");scanf("%d",&pos);insert(pos);break;
            case 7:int p;printf("enter position\n");scanf("%d",&p);deletePos(p);break;
            
            case 8:display();break;
            case 9:exit(1);
            case 10:reverseData();
        }
    }
}
void addFirst(){
    node *t;
    t=createNode();
    if(head==NULL){
        head=t;
        tail=t;
    }
    else{
        t->addr=head;
        head=t;
    }
}
void addLast(){
    node *t;
    
    if(head==NULL){
        head=createNode();
        tail=head;
    }
    else{
        t=createNode();
        tail->addr=t;
        tail=t;
    
    }
}
void deleteFirst(){
    if(head==NULL||tail==NULL){
        printf("list is empty\n");
        return;
    }
    if(head==tail){
        head=tail=-1;
    }
    else{
        head=head->addr;
    }
}
void deleteLast(){
    node *th,*prev;
    if(head==NULL||tail==NULL){
        printf("list is empty\n");
        return;
    }
    if(head==tail){
        head=tail=-1;
    }
    else{
        th=head;
        while(th->addr!=NULL){
            prev=th;
            th=th->addr;
        }
        prev->addr=NULL;
        tail=prev;
    }
    
    
}
void display(){
    temp=head;
 
    printf("%u",temp);
    while(temp!=NULL){

        printf("->||%d-%u\n",temp->data,temp->addr);
        temp=temp->addr;
        
    }
    
}
int listSize(){
    int count=0;
    node *th;
    th=head;
    while(th!=NULL){
        ++count;
        th=th->addr;
    }
    printf("list has %d nodes",count);
    return count;
}

void insert(int pos){
    node *th,*t;
    int  count=listSize();
    if(pos<=0){
        addFirst();
        return;
    }
    else if(pos>=count)
    {
        addLast();
        return;
    }
    else{
        t=createNode();
        th=head;
        while(pos>1){
            th=th->addr;
            pos--;
        }
        t->addr=th->addr;
        th->addr=t;
        
    }
}
void deletePos(int p){
    node *th,*prev;
    int count=listSize();
    if(head==NULL||tail==NULL){
        printf("list is empty\n");
        return;
    }
    else if(p<=0){
        deleteFirst();
        return;
    }
    else if(p>=count){
        deleteLast();
        return;
    }
    else{
        th=head;
        while(p>=1){
            prev=th;
            th=th->addr;
            --p;
            
        }
       prev->addr=th->addr;
        
            
    }

}
void reverseData(){
    node *th,*prev;
    if(head==NULL||tail==NULL){
        printf("list is empty\n");
        return;
    }
    if(head==tail){
        printf("%d",head->data);
    }
  else{
     th=head;
        while(th->addr!=NULL){
            prev=th;
            th=th->addr;
        }
        while(th!=head){
        printf("%d",th);
        th=prev;
        }
  }
}


