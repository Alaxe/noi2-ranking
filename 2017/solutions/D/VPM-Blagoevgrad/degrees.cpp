#include<bits/stdc++.h>
using namespace std ;
int main()
{
    ios_base::sync_with_stdio(0);
    /*unsigned long long a=2,a1;
    cout<<1<<" "<<a<<" "<<1<<endl;
    for(int i=2;i<=55;i++)
    {
        int p=0;
        a=a*2;
        a1=a;
        cout<<i<<" "<<a<<" ";
        while(a1!=0)
        {
            p++;
            a1=a1/10;
        }
        cout<<p<<endl;
    }*/
    string a;
    cin>>a;
    int i=3,k=a.size(),br=3,n=1;
    if(a=="2")cout<<1<<endl;
    else if(a=="24")cout<<2<<endl;
    else if(a=="248")cout<<3<<endl;
    else
    {
        while(1>0)
        {
            i++;
            if(i%10==4 or i%10==7 or i%10==0)n++;
            br+=n;
            if(br==k)
            {
                cout<<i<<endl;
                return 0;
            }
        }
    }


    return 0;
}
