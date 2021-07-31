#include<iostream>

using namespace std;

int div(int a,int b)
{
    if(a==0)
    {
        return 0;
    }
    if(a!=0)
    {
        return (1 + div(a-b,b));
    }
}

int main()
{
    int num1,num2;
    int answer;
    cout<<"Enter 2 Numbers : \n";
    cin>>num1>>num2;
    answer=div(num1,num2);
    cout<<"Value is : "<<answer;
}
