# include <iostream>
# include <cstdio>
using namespace std;
string s;
int main()
{
    cin>>s;
long long n=s.size();
long long i=1,br=1,l=1;
while(l<=n)
{
if(s[l]<s[l-i]){i++;}
br++;
l+=i;
}
printf("%lld\n",br-1);
//cout<<br-1<<endl;
}
