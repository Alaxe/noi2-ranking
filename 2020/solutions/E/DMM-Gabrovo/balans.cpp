# include <iostream>
# include <string>
using namespace std;

int main()
{
long long n,br1=0,br2=0,br=0;
string s;
cin>>n;
cin>>s;

for(int i=0;i<n;i++)
{
if(s[i]=='a') br1++;
if(s[i]=='b') br1++;
if(s[i]=='c') br2++;
if(s[i]=='d') br2++;

if(s[i+1]=='a') br1++;
if(s[i+1]=='b') br1++;
if(s[i+1]=='c') br2++;
if(s[i+1]=='d') br2++;



if(br1==br2) br=i+2;
i++;
}
cout<<br<<endl;
return 0;
}
