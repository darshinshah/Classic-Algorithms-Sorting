#include<iostream>
using namespace std;

void mergesort(int x[],int low,int high);
void mergearray(int x[],int low,int mid,int high,int maxi);

void display(int x[],int maxi)
{
    for(int i=0;i<maxi;i++)
    {
        cout<<x[i]<<"----->";
    }
    cout<<"END";
}

void mergesort(int x[],int low,int high,int maxi)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(x,low,mid,maxi);
        mergesort(x,mid+1,high,maxi);
        mergearray(x,low,mid,high,maxi);
    }

}

void mergearray(int x[],int low,int mid,int high,int maxi)
{
    int i=low;
    int j=mid+1;

    int temp[maxi];
    int k=0;

    while((i<=mid) && (j<=high))
    {
        if(x[i]>x[j])
        {
            temp[k]=x[j];
            j++;
        }
        else
        {
            temp[k]=x[i];
            i++;
        }
        k++;
    }

    if(i>mid)
    {
        while(j<=high)
        {
            temp[k]=x[j];
            j++;
            k++;
        }
    }

    else
    {
        while(i<=mid)
        {
            temp[k]=x[i];
            i++;
            k++;
        }

    }
    int b =0;
    for(int m=low;m<=high;m++)
    {
        x[m]=temp[b];
        b++;

    }
    cout<<"\n";

    display(x,maxi);
    cout<<"\n";
}


int main()
{
    int array1[100];
    int maxi;
    cout<<"How many Elements you want in the Array : ";
    cin>>maxi;

    cout<<"Enter The Data For The Array\n";
    for(int i=0;i<maxi;i++)
    {
        int value;
        cin>>value;
        array1[i]=value;
    }

    cout<<"\n\n";
    display(array1,maxi);

    cout<<"\n\n";
    cout<<"The Passes Are : ";

   mergesort(array1,0,maxi-1,maxi);

    cout<<"\n\n";
    cout<<"Sorted Array is : ";
    display(array1,maxi);
    cout<<"\n\n\n";
}
