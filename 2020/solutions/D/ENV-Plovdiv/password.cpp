#include<bits/stdc++.h>
using namespace std;
int main()
{
string a;
char sim='a';
long long i,br;
cin>>a;
for(i=1;i<a.size();i++)
{
    //if(a[i]==a[i-1]) br++;
    if(a[i]==a[i-1])
    {
        if(a[i]==a[i+1]||a[i]==a[i-2])
        {
            if(a[i+1]!=sim) a[i+1]=sim;
            else a[i+1]=sim+1;
        }

    }
    //if(br>a.size()/2) {a[i]=sim;sim++;}
}
for(i=0;i<a.size();i++)
{
    cout<<a[i];
}
return 0;
}
