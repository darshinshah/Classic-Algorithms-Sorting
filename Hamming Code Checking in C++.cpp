#include<iostream>
#include<cmath>

using namespace std;

void accept(int arr[],int len)
{
    cout<<"Enter The Hamming Code :- ";
    for(int i=1;i<=len;i++)
    {
        int temp=0;
        cin>>temp;
        if(temp==0 || temp==1)
        {

        }
        else
        {
            cout<<"Bit No not accepted";
            break;
        }
        arr[i]=temp;
    }
}

void display(int arr[],int len)
{
    cout<<"The Hamming Code is :-  ";
    for(int j=1;j<=len;j++)
    {
        cout<<arr[j]<<" ";
    }
}

void CheckHamming(int arr[],int len,int pn)
{
    int start=0;
    int sum=0;
    cout<<"\nThe Number of Parity Bits in the code is :- "<<pn;


	for(int i=0; i<pn; i++)
    {
        start=pow(2,i);
		cout<<"\nThe Bit Parity For "<<start<<" Position"<<" is Calculated";
        int ctr=0;

        for(int j=start; j<=len; j=j+(2*start))
        {
            for(int k = j; (k < j+start) && (k <= len); k++)
            {
                if(k==start)
                {
                    continue;
                }
                else if(arr[k]==1)
                {
                    ctr++;
                }
            }
		}

        if(ctr%2==0) //even detected, even = 0
        {
            if(arr[start]==1)
                {
                cout<<"\nError Even ";
                sum=sum+start;
                }

        }
        else
        {
            if(arr[start]==0)
            {
                cout<<"\nError Odd";
                sum=sum+start;
            }

        }

    }
cout<<"\n\nError is at Position : "<<sum;

}

int main()
{
    int length;
    int array1[100];
    int ParityNumber=0;
    cout<<"Enter The Length Of the Code : ";
    cin>>length;
    ParityNumber=ceil(log(length)/log(2));
    accept(array1,length);
    cout<<"\n\n";
    display(array1,length);
    CheckHamming(array1,length,ParityNumber);
}
