#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n, br1=0, br2=0, maxi=0;
    cin >> n;
    cin >> s;
    for (int i=0; i<n; i++)
    {
        if (s[i]=='a')  br1++;
        if (s[i]=='b')  br1++;
        if (s[i]=='c')   br2++;
        if (s[i]=='d')  br2++;
        if (br1==br2)
        {
        if (br1+br2>maxi)  maxi=br1+br2;
        }
    }
    if (maxi==0) { cout << 0 <<endl; return 0;}
    cout << maxi <<endl;
}
