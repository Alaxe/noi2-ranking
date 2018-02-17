#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,i=2;
    long long int p=0;
    string str;
    cin>>str;
    n=str.size();
    if(n==1||n==2||n==3)cout<<n;
    if(n>=5)
    {
        while(n>3)
        {
            n=n-i;
            p++;
            if(n==3)break;
            n=n-i;
            p++;
            if(n==3)break;
            n=n-i;
            p++;
            if(n==3)break;
            i++;
            n=n-i;
            p++;
            if(n==3)break;
            n=n-i;
            p++;
            if(n==3)break;
            n=n-i;
            p++;
            if(n==3)break;
            i++;
            n=n-i;
            p++;
            if(n==3)break;
            n=n-i;
            p++;
            if(n==3)break;
            n=n-i;
            p++;
            if(n==3)break;
            n=n-i;
            p++;
            if(n==3)break;
            i++;
        }
        cout<<p+3;
    }
}
