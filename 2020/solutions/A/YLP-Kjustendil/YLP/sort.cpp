#include<iostream>
using namespace std;
int main()
{
    int n, x, v;
    int difference=0;
    int count=0;
    int p=0;
    double average=0;
    cout<<"n=";
    cin>>n;
    int A[n];
    for(int i=0; i<=n-1; i++)
    {
         cin>>x;
         A[i]=x;
    }
    for(int f=0; f<=n-2; f++)
    {
        if(A[f]>A[f+1])
        {
        difference++;
       v=f;
        }
    }
    if(difference==1)
    {
    while(A[v]>A[v+1])
    {
        A[v]--;
        count++;

    }
    while(A[v]<A[v+1])
    {
        A[v]++;
        count++;
    }
    cout<<count;
    return 0;
    }

    else
    {
    while(A[p]<A[p+1])
    {
        p++;
        if(A[p]>A[p+1])
            {
                for(int j=p; j<=n-1; j++)
                    {
                        average+=A[j];
                    }
            average=average/n;
            for(int k=p; k<=n-1; k++)
                {
                    while(A[k]!=average)
                    {
                        if(A[k]>average) A[k]--;
                        else A[k]++;
                        count++;
                        if(A[k]==average) break;
                    }
                }
            }
    }
    int average1=0;
    if(A[0]>A[1])
    {
        for(int j=0; j<=n-1; j++)
                    {
                        average1+=A[j];
                    }
            average1=average1/n;
            for(int k=0; k<=n-1; k++)
                {
                    while(A[k]!=average1)
                    {
                        if(A[k]>average1) A[k]--;
                        else A[k]++;
                        count++;
                        if(A[k]==average1) break;
                    }
                }
    }

    }
    cout<<count;

}

