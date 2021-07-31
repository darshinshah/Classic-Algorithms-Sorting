#include<iostream>
#include<string>

using namespace std;

void move(int n, char source, char dest, char temp)
{
    if (n==1)
    {
        cout<<"Move Disc From "<<source<<" to "<<dest<<"\n";
    }
    else
    {
        move(n-1,source,temp,dest);
        cout<<"Move Disc From "<<source<<" to "<<dest<<"\n";
        move(n-1,temp,dest,source);
    }
}

int main ()
{
    int n;
    cout<<"Enter No of Discs"<<" \n";
    cin>>n;
    move(n,'A','C','B');
}
