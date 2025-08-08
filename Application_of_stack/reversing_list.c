#include<stdio.h>

int stk[10];
int top=-1;
void push(int x)
{
    stk[++top]=x;
}
int pop()
{
    return stk[top--];
}
int main(void)
{
 int val,n,arr[10];
 printf("\nEnter the number of elements in the array: ");
 scanf("%d",&n);
 printf("\nEnter the elements of the array \n");
 for(int i=0;i<n;++i)   
 {
    scanf("%d",&arr[i]);
    printf("\n");
 }
 for(int i=0;i<n;i++)
 push(arr[i]);
 for(int i=0;i<n;i++) arr[i]=pop();
 printf("\nThe reversed array is : ");
for(int i=0;i<n;i++)
{
    printf("\n %d",arr[i]);
    printf("\n");
}

}