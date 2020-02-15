#include <iostream>
using namespace std;

bool imaLi[27];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    //for (int i=-256;i<255;++i) cout<<i<<' '<<char(i)<<'\n';
    for (long long i=0;i<s.size();++i)
    {
        imaLi[s[i]-'A']=1;
    }
    for (long long i=0;i<s.size();++i)
    {
        char bukva='A';
        for (int j=0;j<s[i]-'A';++j)
        {
            if (imaLi[j]) bukva++;
        }
        cout<<bukva;
    }
    cout<<'\n';
    for (long long i=0;i<s.size();++i)
    {
        char bukva='Z';
        for (int j=25;j>s[i]-'A';--j)
        {
            if (imaLi[j]) bukva--;
        }
        cout<<bukva;
    }
    cout<<'\n';

    return 0;
}
