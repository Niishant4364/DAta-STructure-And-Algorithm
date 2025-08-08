#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct stack{
    int info;
    struct stack *next;
};
void push(struct stack **top_node,int value){
struct stack *node;
node=(struct stack *)malloc(sizeof(struct stack));

node->info=value;


node->next=*top_node;
*top_node=node;


}
int pop(struct stack **top_node)
{
    int x;
    struct stack *temp;
    if(*top_node==NULL)
    {
        printf("\nStack is empty");
        return 0;

    }
    else{
        temp=*top_node;
        x=temp->info;
        *top_node=temp->next;
        free(temp);
        return x;

    }

}
void display(struct stack **top_node)
{
    struct stack *temp;;

    if(*top_node==NULL)
    printf("STack is empty");
    else{
        temp=*top_node;
        while (temp->next!=NULL)
        {
            printf("\nThe items are : %d",temp->info);
            temp= temp->next;
            /* code */
        }
        
    }

}
int peek(struct stack **top){
    struct stack *top_node=*top;
    if(*top==NULL) return 0;
    else return top_node->info;
}
int main(void)
{
    struct stack *top=NULL;
    
    int x,option;
    char ch='y';

    printf("\n1.Push");
    printf("\n2.Pop");
    printf("\n3.display");
    while(ch=='y' || ch=='Y')
    {
        printf("\nEnter the option: ");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            /* code */
            printf("\nEnter the vlaue to push : ");
            scanf("%d",&x);
            push(&top,x);
            break;
        case 2:
        printf("\nthe popped number is %d ",pop(&top));
        break;
        case 3:
            display(&top);
            break;
            case 4:
           printf("\n %d ", peek(&top));
            break;
        default:
            printf("\nINVALID!");
        }

         printf("\n Do you want to continue(Y/N)? \t");
         scanf(" %c",&ch);
    }
   
}