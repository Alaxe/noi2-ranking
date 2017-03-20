#include<iostream>
using namespace std;
int main()
{
    int A[1000],N,br=0;
    do{cin>>N;}
    while(N<1 || N>1000);
    for(int i=0; i<=N-1; i++)
        cin>>A[i];
    int min=A[0], max=A[0];
    for(int i=0; i<=N-1; i++)
    {
        if(A[i]<min) min=A[i];
        if(A[i]>max) max=A[i];
    }
    int d=max-min;
    for(int k=1;k<=d;k++)
        for(int i=0; i<=N-1; i++)
            for(int j=0; j<=N-1; j++)
                if(i!=j && A[i]+k==A[j]) br++;
    cout<<br;
    return 0;
}
