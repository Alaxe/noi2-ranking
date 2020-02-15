#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    string res;
    for(int i=0; i<s.size(); i++)
        if(s[i]!='(' && s[i]!=')')
            res+=s[i];
    cout<<res<<endl;
    return 0;
}
//&+((((&/&))))/&











