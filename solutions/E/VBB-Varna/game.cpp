#include<iostream>
using namespace std;
int main()
{
    int m,k,a,br=0,s=0,raz,minraz=10000000;
    cin>>m>>k;
    for (int i=1; ;i++)
    {
        cin>>a;

        raz=m-a;
        if (raz<minraz) {minraz=raz;br++;}
        if (a%2==0) s+=a;
        if (s>k) break;
    }
    cout<<br<<" "<<s;
}
