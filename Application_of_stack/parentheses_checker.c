#include<stdio.h>
#include<string.h>

#define MAX 10
struct stack{
    int stak[MAX];
    int top;

};
void push(struct stack *s,char x)
{
 if(s->top==MAX-1) printf("\nStack Overflow");
 else s->stak[++s->top]=x;
}
char pop(struct stack *s)
{
    if(s->top==-1) printf("\nStack Underflow!");
    else return s->stak[s->top--];

}

int main(void)
{
    struct stack s;
    s.top=-1;
    char temp,exp[MAX];
    int flag=1;
    printf("\nEnter an expression: ");
    fgets(exp,sizeof(exp),stdin);
    for(int i=0;i<strlen(exp);++i)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        push(&s,exp[i]);
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        if(s.top==-1) flag=0;
        else{
            temp=pop(&s);
            if(exp[i]==')' && (temp=='{' || temp=='[')) flag=0;
            if(exp[i]=='}' && (temp=='(' || temp=='[') ) flag=0;
            if(exp[i]==']' && (temp=='(' || temp=='{') ) flag=0;
            


        }
        


    }
if(s.top>=0) flag=0;
        if(flag==1) printf("\n valid expression");
        else printf("\nInvalid expression");
        
}