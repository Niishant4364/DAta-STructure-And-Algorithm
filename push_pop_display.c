#include<stdio.h>
#define MAXSISZE 5


//Stack operation -> push(); pop(); display();
struct stack{
    int items[MAXSISZE];
    int top;
};


void push(struct stack *s,int item){
    if(s->top==MAXSISZE-1)
    printf("The stack is overflow");
    else{
        s->items[++s->top]=item;
        
    }

}
int pop(struct stack *s)
{
    if(s->top==-1){
             printf("The stack is underflow"); return 0;
    }
   

    else{
        return s->items[s->top--];
    }
}

void display(struct stack *s)
{
     printf("The current items in the stack are : \n");
    for(int i=0;i<=s->top;i++)
    {
       
        printf("%d\n",s->items[i]);
        
    }
}
int main(void)
{   
   struct stack s;
    char choice;
    char ch='y';
    int x;  //declaring the value 
    s.top=-1;
    

    while(ch=='y')
    {
        printf("\nEnter 1. to push the value into the stack : ");
        printf("\n Enter 2. to pop the value of the stack : ");
        printf("\n Enter 3, to display the items of the stack : ");
        printf("\n Enter the choice : ");
        scanf(" %c",&choice);
        switch(choice)
        {
        case '1':
            /* code */
           
            printf("\nEnter the value to push into the stack : ");
            scanf(" %d",&x);
            push(&s,x);
          
           
            break;
        case '2':
            int p=pop(&s);
            printf("%d",p);
            break;
        case '3':
        display(&s);
        break;
        default:
        printf("\nYou entered out of the number. Try again....\n");
            
        }
        printf("\nDo you want to continue : y/n");
        scanf(" %c",&ch);
    } }


