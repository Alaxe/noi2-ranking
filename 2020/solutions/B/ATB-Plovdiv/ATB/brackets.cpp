#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
string s;
ll i,n;
int main()
{ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>s;
n=s.size();
for(i=0;i<n;i++)if(s[i]!=')'&&s[i]!='(')cout<<s[i];
cout<<endl;
return 0;
}
