#include <iostream>

using namespace std;

int main()
{
    int n,m,i,e,o,S1,S2,S3,S4,S[1000],N,x[1101],y[1001],h[1101],w[1101],T,a[1001],b[1001];
    cin>>n>>m;
    cin>>N;
    for (o=0;o<N;o++)
    {
        cin>>x[o];
        cin>>y[o];
        cin>>w[o];
        cin>>h[o];
    }
    x[N+1]=0;
    y[N+1]=0;
    h[N+1]=0;
    w[N+1]=0;
    cin>>T;
    for (i=0;i<T;i++)
    {
        cin>>a[i];
        cin>>b[i];
    }
    for (e=0;e<T-1;e++)
    {S[e]=w[e]*h[e]; }
    S[T]=m*n;
    S1=S[1];
    S2=S[0]-S[1];
    S3=S[T]-S[0]-S[1];
    S4=S[1];
    cout<<S1<<endl;
    cout<<S2<<endl;
    cout<<S3<<endl;
    cout<<S4<<endl;
    return 0;
}
