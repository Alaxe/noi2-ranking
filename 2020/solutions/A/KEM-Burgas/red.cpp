#include<iostream>
using namespace std;
int main()
{
    int N,M,W,K;
    cin>>W>>K;
    cin>>N;
    int A[N],max=0;
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
        if(A[i]>max) max=A[i];
    }
    cin>>M;
    int B[M];
    for(int i=0;i<M;i++)
    {
        cin>>B[i];
        if(A[i]>max) max=B[i];
    }
    int RA[max],RB[max];
    for(int i=0;i<max;i++)
    {
        RA[i]=0;
        RB[i]=0;
    }
    for(int i=0;i<N-K;i++)
    {
        bool b=true;
        for(int j=1;j<K;j++)
        {
            if(A[i]!=A[i+j]) b=false;
        }
        if(b) RA[A[i]-1]++;
    }
    for(int i=0;i<M-K;i++)
    {
        bool b=true;
        for(int j=1;j<K;j++)
        {
            if(B[i]!=B[i+j]) b=false;
        }
        if(b) RB[B[i]-1]++;
    }
    int S=0;
    for(int i=0;i<max;i++)
    {
        S+=RA[i]*RB[i];
    }
    cout<<S<<endl;
    return 0;
}
