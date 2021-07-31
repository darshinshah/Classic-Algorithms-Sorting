#include<iostream>
#include<math.h>

using namespace std;

double stacks[100];
int top=-1;
int ctr=0;

void PUSH(double value)
{
    top++;
    stacks[top]=value;
}

double POP()
{
    double value=0;
    value=stacks[top];
    top--;
    return value;
}

int length(double x[])
{
    int i=0;
    while(x[i]!='\0')
    {
        ctr++;
        i++;
    }
    return ctr;
}


int main()
{
    char exp[100];
    double a,b,c;
    int i=0;
    int check3,check4;

    cout<<"Enter the Postfix Expression :  ";
    cin>>exp;

    cout<<"\nGiven Postfix Expression : "<<exp;
    cout<<"\n\n";

    int check1=(int)exp[0];
    int check2=(int)exp[1];

    if(check1<48||check1>57)
    {
        cout<<"\nPostfix Not Possible\n";
    }
    else if(check2<48||check2>57)
    {
        cout<<"\nPostfix Not Possible\n";
    }

    else
    {
    while(exp[i]!='\0')
    {
        cout<<"\nIteration "<<i+1<<": ";

        switch(exp[i])
        {

        case'+':
            {
            a=POP();
            b=POP();
            c=b+a;
            cout<<"Case \"+\" : "<<c<<" is Pushed to Stack";
            PUSH(c);
            break;
            }

        case'-':
            {
            a=POP();
            b=POP();
            c=b-a;
            cout<<"Case \"-\" : "<<c<<" is Pushed to Stack";
            PUSH(c);
            break;
            }

        case'*':
            {
            a=POP();
            b=POP();
            c=b*a;
            cout<<"Case \"*\" : "<<c<<" is Pushed to Stack";
            PUSH(c);
            break;
            }
        case'/':
            {
            a=POP();
            b=POP();
            c=b/a;
            cout<<"Case \"/\" : "<<c<<" is Pushed to Stack";
            PUSH(c);
            break;
            }

            case'^':
            {
            a=POP();
            b=POP();
            c=pow(b,a);
            cout<<"Case \"^\" : "<<c<<" is Pushed to Stack";
            PUSH(c);
            break;
            }
        default:
        {
            cout<<"Case Default : "<<exp[i]-48<<" is Pushed to Stack";
            check3=exp[i];
            if(check3<48||check3>57)
            {
                cout<<"\nPostfix Not Possible ! Error in Postfix !\n";
                break;
            }
            else
            {
            PUSH(exp[i]-48);
            }
        }
       }
        i++;
    }

    cout<<"\n\n";


    cout<<"\nResult After Evaluation : "<<stacks[top];
    cout<<"\n\n";

    }
}
