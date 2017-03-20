#include<iostream>
using namespace std;
int main ()
{
    int A[1000];
    int i, N, d;
    int br=0;
    do{cin>>N;}
    while (N<1|| N>1000);
    for(i=0; i<=N-1; i++) cin>>A[i];
    for( i=0; i<=N-1; i++)
    {
        d=A[i]-A[1]/N-1;
        for( i=0; i<=N-1; i++)
        {
         br++;
        }

    }
    cout<<br;
}
