#include<iostream>

using namespace std;

int multi(int a,int b)
{
    if(b==0||a==0)
    {
        return 0;
    }
    if(b==1)
        return a;
    if(b!=0)
    {
        return (a+multi(a,b-1));
    }
}

int main()
{
    int num1,num2;
    int answer;
    cout<<"Enter 2 Numbers : \n";
    cin>>num1>>num2;
    answer=multi(num1,num2);
    cout<<"Value is : "<<answer;
}
