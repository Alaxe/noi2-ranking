#include<bits/stdc++.h>
using namespace std;
int main()
{string s,t="";
long long e=0,f=0,i,j,n;
cin>>s;
n=s.size();
for(i=0;i<n;i++)if(s[i]=='9')e++;
if(e==n)
{cout<<"1";
for(i=0;i<n-1;i++)cout<<"0";
cout<<"1"<<endl;
}
else{
for(i=0;i<n;i++){if(i<n/2)t=t+s[i];
else t=t+s[n-i-1];
}
if(s<t)cout<<t<<endl;
else{
for(i=n/2;i>=0;i--)
{if(f==0){
if(t[i]!='9'){t[i]++;t[n-1-i]=t[i];f=1;}
else{
int y=i;
while(t[y]=='9')
{y--;
}
t[y]++;
t[n-y-1]=t[y];
for(int r=y+1;r<=n/2;r++){t[r]='0';t[n-r-1]='0';}
}
f=1;
}
}
cout<<t<<endl;
}
}
return 0;
}
/*
6 7
.....B.
.#####.
.#...#.
.#E#.#.
.###.#.
.......

5 5
...B.
.####
.####
...E.
.....
*/
