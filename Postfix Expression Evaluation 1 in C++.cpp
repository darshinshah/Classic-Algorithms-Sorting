#include<iostream>
#include<cmath>
using namespace std;

int stack1[100],top=-1;

void push(int value)
{
    top++;
    stack1[top]=value;
}

int pop()
{
    int value;
    value=stack1[top];
    top--;
    return value;
}

int main()
{
    char pe[100];
    int a,b,c;
    cout<<"Enter the postfix expression to evaluate:";
    cin>>pe;//for taking input in C, we have to use 'for'loop.

    int i=0;
    if(pe[i]>=48 && pe[i]<=57 && pe[i+1]>=48 && pe[i+1]<=57)
    {
        while(pe[i]!='\0')
        {
            switch(pe[i])
            {
            case '+':
                {
                    a=pop();
                    b=pop();
                    c=b+a;
                    push(c);
                    break;
                }
            case '-':
                {

                    a=pop();
                    b=pop();
                    c=b-a;
                    push(c);
                    break;
                }
            case '*':
                {

                    a=pop();
                    b=pop();
                    c=b*a;
                    push(c);
                    break;
                }
            case '/':
                {

                    a=pop();
                    b=pop();
                    c=b/a;
                    push(c);
                    break;
                }
            case '^':
                {
                    a=pop();
                    b=pop();
                    c=pow(b,a);
                    push(c);
                    break;
                }
            default:
                {
                    pe[i] = pe[i] -48;
                    push(pe[i]);
                }
            }
            i++;
        }
        cout<<"\nThe evaluated equation is:"<<stack1[top];
    }
    else
        cout<<"Not possible";

    return 0;
}
