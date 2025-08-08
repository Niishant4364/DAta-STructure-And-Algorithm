#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int st[MAX],top=-1;
void push(int st[],int);
int pop(int st[]);
void display(int st[]);
int peek(int st[]);

int main(void)
{
    int option,val;
    
    do{
        printf("\n Enter 1 to push the elements on the stack");
        printf("\n Enter 2 to pop the elemtn of the stack ");
        printf("\n Enter 3 to peek ");
        printf("\n Enter 4 to display");
        printf("\n Enter 5 to exit");
        scanf("%d",&option);
        switch(option)
        {
           case 1:
           printf("\n Enter the number to be pushed on the stack: ");
           scanf(" %d",&val);
           push(st,val);
           break;
           case 2:
            printf("\n The value popped is %d",pop(st));
            break;
            case 3:
            display(st);
            break;
            case 4:
            printf("\n The topmost element of the stack is %d",peek(st));
            break;


        }  
}while(option!=5);
}
void push(int st[],int val){
    if(top==MAX-1){
        printf("\n Stack OVERFLOW!");
        
    }else{
        st[++top]=val;
    }
}

int pop(int st[])
{

    if(top==-1)
    {
        printf("\n Stack UNDERFLOW!");
        return -1;
    }
    else return st[top--];
}
void display(int st[])
{

    if(top==-1)
    printf("\n Stack is empty.");
    else{
        for(int i=5;i>0;i--)
        {
            printf("\n st[%d]",st[i]);
            printf("\n");
        }
    }
}
int peek(int st[])
{
    if(top==-1)
    printf("\n Stack is empty. ");
    else return st[top];
}