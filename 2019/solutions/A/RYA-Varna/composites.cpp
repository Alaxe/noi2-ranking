#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    cin>>n;
    if(n%30<=26)cout<<(n/30)*30+26<<endl;
    else cout<<((n/30)+1)*30+26<<endl;
}
