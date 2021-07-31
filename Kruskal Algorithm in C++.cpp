#include<iostream>
using namespace std;
int i,j,k,a,b,u,v,n,nEdges=1;
int mini,minicost=0,cost[100][100],parent[100]={};

int search(int i)
    {
        while(parent[i])
        i=parent[i];
        return i;
    }
    int unionPossible(int i,int j)
    {
        if(i!=j)
        {
        parent[j]=i;
        return 1;
        }
        return 0;
    }
int main()
{
    cout<<"\nEnter the number of vertices:";
    cin>>n;
    cout<<"\nEnter the cost adjacency matrix:\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j==i)
            {
                cout<<"\n"<<i<<" "<<j<<"\n";
                cost[i][j]=100;
                break;
            }
            cout<<"Enter value for:"<<i<<" "<<j<<"\n";
            cin>>cost[i][j];
            cost[j][i]=cost[i][j];
            if(cost[i][j]==0)
            {
                cost[i][j]=100;
                cost[j][i]=100;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<cost[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"The edges of Minimum Cost Spanning Tree are\n";
    while(nEdges < n)
    {
        for(i=1,mini=100;i<=n;i++)
        {
            for(j=1;j <= n;j++)
            {
                if(cost[i][j] < mini)
                {
                    mini=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=search(u);
        v=search(v);
        if(unionPossible(u,v))
        {
        cout<<"Edge ("<<a<<","<<b<<") = "<<nEdges++<<"\n";
        minicost +=mini;
        }
        cost[a][b]=cost[b][a]=100;
    }
    cout<<"\nMinimum cost = \n"<<minicost;
    return 0;
}
