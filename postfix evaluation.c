#include <stdio.h>
#include<math.h>
//#include<ctype.h>
#define MAX 5
int s[MAX],top=-1;
void push(int x);
int pop();

int main()
{
    char a[50];
    int i,n1,n2,z;
    printf("enter postfix expression");
    scanf("%s",a);
    for(i=0;a[i]!='\0';i++){
    if(isdigit(a[i])){
    push(a[i]-48);
    }
    else{
    n1=pop();
    n2=pop();
    switch(a[i]){
    case '+':push(n2+n1);break;
    case '-':push(n2-n1);break;
    case '*':push(n2*n1);break;
    case '%':push(n2%n1);break;
    case '/':push(n2/n1);break;
    case '^':z=pow(n2,n1);push(z);break;
    }
    }
    }
    printf("%d",s[top]);
    return 0;
}
void push(int x){
    if(top==MAX-1){
        printf("stack full");
        return;
    }
    ++top;
    s[top]=x;
}
int pop()
{
    int x;
    if(top==-1){
        printf("stack empty");
        return 0;
    }
    x=s[top];
    --top;
    return x;
}
