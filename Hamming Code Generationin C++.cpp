#include<iostream>
#include<cmath>

using namespace std;

void accept(int arr[],int len)
{
    cout<<"Enter The Message Code :- ";
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
    for(int j=1;j<=len;j++)
    {
        cout<<arr[j]<<" ";
    }
}


int isParityBit(double i)
{
    while(i>=1)
    {
        if((i/2) == 1)
        {
            return 1;
        }
        i=i/2;
    }
    return 0;
}

int GenerateIntermediateCode(int arr[],int hamm[],int len)
{
    hamm[1]=2; //since 2 raised to 0 is a parity bit
    int temp=len;
    int i=2; //maps to hamming
    int j=1; //maps to array
    while(len!=0)
    {
        if(isParityBit(i))
        {
            hamm[i]=2;
            i++;
        }
        else
        {
            hamm[i]=arr[j];
            i++;
            j++;
            len--;
        }
    }
    return (i-1);
}


void GenerateHamming(int arr[],int len,int pn)
{
    int start=0;
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
            if(arr[start]!=0)
                {
                arr[start]=0;
                }

        }
        else
        {
            if(arr[start]!=1)
            {
                arr[start]=1;
            }

        }

    }


}




int main()
{
    int length;
    int hamminglength;
    int array1[100];
    int hamming[100];
    int ParityNumber;
    cout<<"Enter The Length Of the Message : ";
    cin>>length;
    accept(array1,length);
    cout<<"\n\n";
    cout<<"\n\nThe Message is :- ";
    display(array1,length);
    hamminglength=GenerateIntermediateCode(array1,hamming,length);
    ParityNumber=ceil(log(hamminglength)/log(2));

    //display(hamming,hamminglength);

    GenerateHamming(hamming,hamminglength,ParityNumber);
    cout<<"\n\nHamming Code is :- \n\n";
    display(hamming,hamminglength);



}
