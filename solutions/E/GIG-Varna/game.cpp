#include<iostream>
using namespace std;
int main()
{
    int k,m,ch1,ch2,i,s=0,nb,n1=1,n=2;
    cin>>m>>k;
    cin>>ch1;
    if(ch1==(m+1)||ch1==(m-1))
    nb=ch1;
    if(ch1%2==0)s+=ch1;
    if(ch1>k)cout<<n1<<" "<<s<<endl;
    if(ch1==m)cout<<n1<<" "<<s<<endl;
    for(i=2;;i++)
    {
        if(ch1>k)break;
        if(ch1==m)break;
        if(i==200)break;
        if(s>k)break;
        cin>>ch2;
        if(ch2==(m+1)||ch2==(m-1))
            {
            if(i>n1&&i>n){nb=ch2;n=i;}
            }
        if(ch1==m)cout<<n1<<" "<<s<<endl;
        if(ch2%2==0)s+=ch2;
    }
    if(ch1<k)cout<<n<<" "<<s<<endl;
    return 0;
}
