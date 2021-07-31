#include<iostream>
using namespace std;

void quick(int a[],int low,int high,int n);
void swap(int* a,int* b);
int partition(int a[],int low,int high,int n);
void showdata(int a[],int n);
void takedata(int a[],int n);

void swap(int* a,int* b)
{
int temp=(*a);
(*a)=(*b);
(*b)=temp;
}

void quick(int a[],int low,int high,int n)
{
    if(low<high)
    {
    int p=partition(a,low,high,n);
    quick(a,low,p-1,n);
    quick(a,p+1,high,n);
    }
}


int partition(int a[],int low,int high,int n)
{
    int pivot=a[low];
    cout<<"pivot is : "<<pivot<<"\n";
    int i=low;
    int j=high;
    while(i<=j)
    {
    while(a[i]<=pivot)
    i++;
    while(a[j]>pivot)
    j--;
    if(i<j)
    {
        swap(&a[i],&a[j]);
    }
    }
        swap(&a[low],&a[j]);
        showdata(a,n);
        return j;
}

void takedata(int a[],int n)
{
    cout<<"Enter The Data : ";
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
}

void showdata(int a[],int n)
{
    cout<<"The data is : ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"---->";
    }
    cout<<"END\n";
}

int main()
{
    int no;
    int a[100];
    cout<<"Enter The No of Elements you want in the array : ";
    cin>>no;
    takedata(a,no);
    showdata(a,no);
    cout<<"\n\n";
    quick(a,0,no,no);
    showdata(a,no);
}
