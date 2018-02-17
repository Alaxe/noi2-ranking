#include <iostream>
using namespace std;
int main ()
{
    string str;
    int n,m, fac,siz,ans;
    fac=1;
    ans=0;
    cin>>str;
    siz=str.size();
    cin>>n>>m;
    for(int i = 0;i<str.size();i++)
        {fac*=siz;
        siz--;}
        ans=fac%m;
        if(ans!=0)
            ans++;
        cout<<ans;
    return 0;
}
