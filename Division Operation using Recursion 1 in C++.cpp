#include<iostream>

using namespace std;

int div(int a,int b,int ctr=0)
{
    if(a<b)
    {
        return ctr;
    }
    else
    {
        ctr++;
        return div(a-b,b,ctr);
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
