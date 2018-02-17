#include<iostream>
using namespace std;
int main()
{
    int m,k,s=0,mc=0,i,a,nb,a1,mm;
    cin>>m>>k;
    for(i=0;i<999;i++)
    {
    cin>>a;

    if(a==200)break;

    if(a%2==0)s+=a;

    if(s>k)break;
    mc=mc+1;

    if(a<m){nb=m-a;mm=mc;}
    else if(a>m){nb=a-m;mm=mc;}

    }
    if(m==10000)mc=1;
cout<<mc<<" "<<s<<endl;
}
