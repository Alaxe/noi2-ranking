#include<bits/stdc++.h>
using namespace std;
long long e,minnn,minn,d[11000],f[11000],nv,kv,i,j,n,m;
vector<int>a[11000];
string s[120];
long long BFS(vector<int>a[11000])
{queue<int>q;
q.push(nv);
d[kv]=-1;
d[nv]=1;
f[nv]=1;
while(q.empty()==false)
{for(int y=0;y<a[q.front()].size();y++)if(f[a[q.front()][y]]==0&&a[q.front()][y]!=1000002){q.push(a[q.front()][y]);f[a[q.front()][y]]=1;d[a[q.front()][y]]=d[q.front()]+1;}
q.pop();
}
return d[kv];
}
int main()
{cin>>n>>m;
for(i=0;i<n;i++)cin>>s[i];
for(i=0;i<n;i++)
for(j=0;j<m;j++)
{if(s[i][j]!='#')
{if(i-1>=0&&s[i-1][j]!='#')a[i*m+j].push_back((i-1)*m+j);
if(i+1<n&&s[i+1][j]!='#')a[i*m+j].push_back((i+1)*m+j);
if(j-1>=0&&s[i][j-1]!='#')a[i*m+j].push_back(i*m+j-1);
if(j+1<m&&s[i][j+1]!='#')a[i*m+j].push_back(i*m+j+1);
}
if(s[i][j]=='B')nv=i*m+j;
if(s[i][j]=='E')kv=i*m+j;
}
minnn=BFS(a);
minn=123456789;
for(i=0;i<n;i++)
for(j=0;j<m;j++){
if(s[i][j]=='#'){
memset(f,0,sizeof(f));
if(i-1>=0&&s[i-1][j]!='#'){a[i*m+j].push_back((i-1)*m+j);a[(i-1)*m+j].push_back(i*m+j);}
if(i+1<n&&s[i+1][j]!='#'){a[i*m+j].push_back((i+1)*m+j);a[(i+1)*m+j].push_back(i*m+j);}
if(j-1>=0&&s[i][j-1]!='#'){a[i*m+j].push_back(i*m+j-1);a[i*m+j-1].push_back(i*m+j);}
if(j+1<m&&s[i][j+1]!='#'){a[i*m+j].push_back(i*m+j+1);a[i*m+j+1].push_back(i*m+j);}
e=BFS(a);
if(e>0&&e+1<minn)minn=e+1;
if(i-1>=0&&s[i-1][j]!='#')a[(i-1)*m+j].pop_back();
if(i+1<n&&s[i+1][j]!='#')a[(i+1)*m+j].pop_back();
if(j-1>=0&&s[i][j-1]!='#')a[i*m+j-1].pop_back();
if(j+1<m&&s[i][j+1]!='#')a[i*m+j+1].pop_back();
a[i*m+j].clear();
}
}
if(minn>minnn)minn=minnn;
if(minn==123456789)minn=-1;
cout<<minn<<endl;
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
#####
#####
...E.
.....

3 3
B..
..E
...
*/
