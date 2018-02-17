#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int r[10]={0, 0, 1, 0, 0, 1, 0, 0, 0, 1};

int main()
{
    string a;
    cin>>a;

    int s=a.size();

    if(s<=3)
    {
        cout<<a.size()<<endl;
        return 0;
    }

    int ans=3;
    s-=3;

    int p=0;
    int rn=2;

    while(s>0)
    {
        s-=rn;

        rn+=r[p];

        if(p==9)
            p=0;

        ans++; p++;
    }

    cout<<ans<<endl;
    return 0;
}
