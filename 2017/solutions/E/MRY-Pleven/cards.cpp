#include<iostream>
using namespace std;
int main()
{
    long long n,a,b,p,p2,br,br2,br3;
    cin>>n;
    cin>>a>>b;
    p=a*b;
    br=0;
    br2=0;
    br3=0;
    for(int i=1;i<=n*2-1;i++)
    {
        cin>>a>>b;
        p2=a*b;
        if(p2<=p)
        {
            br++;
            p=p2;
        }
        else
        {
            br3++;
        }
        if(br3==2)
        {
            br2++;
        }

        p=p2;
        p2=0;
    }
    if(br>br2)
    {
        br2=0;
    }
    else
    {
        br=br2;
        br2=0;
    }
    cout<<br<<endl;
    return 0;
}
