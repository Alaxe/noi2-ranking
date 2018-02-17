#include<iostream>
using namespace std;
unsigned long long nachini(long long a, long long b)
{
     long long otg =1;
     long long otgore = b;
     long long otdolu = 1;
    for(long long i =0 ;i<a; i++)
    {
        otg = (otg*otgore)/otdolu;
        otgore--;
        otdolu++;
    }
    return otg;
}
string to_bin( long long a)
{
    string str="";
    while(a>0)
    {
        str+=(a%2)+'0';
        a/=2;
    }
    return str;
}
long long pomalko(string A2,long long z)
{
    long long nuli =0 ;
    long long curr=0;
    //cout<<A2<<endl;
    for(long long  i=A2.size()-2;i>=0;i--)
    {
        //cout<<"nuli "<<nuli<<endl;
        if(A2[i]=='0') nuli++;
        if(A2[i]=='1')
        {
            if(z-nuli-1>0)
            {
              //  cout<<z<<" z "<<nuli<<endl;
                //cout<<(z-nuli-1)<<" i:"<<i<<" "<<nachini(z-nuli-1,i)<<endl;
                curr+=nachini(z-nuli-1,i);
            }
            else if(z-nuli-1==0)
            {
                //cout<<"curr\n";
                curr++;
            }
        }
        if(i==0 && nuli==z) curr++;
    }
    //cout<<curr<<endl;
    return curr;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    //unsigned long long k = 1000000000000000000;
    // cout<<k;
     long long a, b, z, otg = 0;
    cin>>a>>b>>z;
   // cout<<to_bin(a)<<endl<<to_bin(b)<<endl<<to_bin(z)<<endl;
    string A2 = to_bin(a), B2 = to_bin(b);
    for(long long i=A2.size()+1; i<B2.size();i++)
    {
        //cout<<"bitove "<<i<<endl;
        otg += nachini(z,i-1);
    }
    //cout<<"otg sled for "<<otg<<endl;
    otg+=pomalko(B2,z);
    //cout<<"otg "<<otg<<endl;
    otg+=nachini(z,A2.size()-1)-pomalko(A2,z);
    long long k=0;
    for(long long i=0;i<A2.size();i++)
    {
        if(A2[i]=='0') k++;
    }
    if(k==z)
        otg++;
    cout<<otg<<endl;


    return 0;
}
