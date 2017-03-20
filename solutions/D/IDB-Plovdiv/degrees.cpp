#include <iostream>
#include <cstring>
using namespace std;
int main ()
{
    string a;
    long long len,k,num,num2;
    bool x=false;
    cin>>a;
    len=a.size();
    if(len==1)cout<<1<<endl;
    else
    {
        long long a2[160000];
        for(int m=0; m<len; m++)
        {
            if(a[m]=='0')a2[m]=0;
            if(a[m]=='1')a2[m]=1;
            if(a[m]=='2')a2[m]=2;
            if(a[m]=='3')a2[m]=3;
            if(a[m]=='4')a2[m]=4;
            if(a[m]=='5')a2[m]=5;
            if(a[m]=='6')a2[m]=6;
            if(a[m]=='7')a2[m]=7;
            if(a[m]=='8')a2[m]=8;
            if(a[m]=='9')a2[m]=9;
        }
        int n=0;
        for(int i=2,c=1,j=0;j<len;j+=c)
        {
            i*=2;
            if(i<10)c=1;
            if(i>10&&i<100)c=2;
            if(i>100&&i<1000)c=3;
            if(i>1000&&i<10000)c=4;
            if(i>10000&&i<100000)c=5;
            if(i>100000&&i<1000000)c=6;
            n++;
        }
        cout<<n<<endl;
    }

    return 0;
}

