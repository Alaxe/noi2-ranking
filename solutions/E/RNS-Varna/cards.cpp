#include<iostream>
using namespace std;
int main()
{
    long A[100000],B[100000],N,br=0,max=0;
    cin>>N;
    for(int i=0;i<N;i++)cin>>A[i]>>B[i];
    for(int k=0;k<N-1;k++)
    {
        if((A[k]==A[k+1])||(A[k]==B[k+1])||(B[k]==A[k+1])||(B[k]==B[k+1]))br++;
        else {if(max<br)max=br;br=0;}

    }
    if(br!=0)cout<<br;
    else cout<<max;

}

