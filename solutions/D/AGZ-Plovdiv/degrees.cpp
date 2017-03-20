#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin>>a;
    long long br=a.size();
    if(br%2==0)cout<<br/2<<endl;
    else if(br%2!=0)cout<<br-2<<endl;


    return 0;
}
