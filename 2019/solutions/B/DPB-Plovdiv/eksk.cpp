#include<iostream>
#include<list>
#include<queue>
#include<cstring>
#include<set>
using namespace std;
#define IT list<int>::iterator
#define MAXN 200000
list<int> G[MAXN+1],q1,q2;
int N,A,B,n1,n2,i,t1,t2;
int used[MAXN+1];
IT it;
set<int> s1,s2;
int BFS()
{
    q1.push_back(A);
    q2.push_back(B);
    used[A]=1;
    used[B]=2;
    int level=0,b1,b2;
    while(!q1.empty()&&!q2.empty())
    {
         n1=q1.size();
         n2=q2.size();
         for(i=0;i<n1;i++)
         {
             t1=q1.front();
             q1.erase(q1.begin());
             for(it=G[t1].begin();it!=G[t1].end();it++)
                 if(used[*it]==0)used[*it]=1,q1.push_back(*it),s1.insert(*it);
         }
         for(i=0;i<n2;i++)
         {
             t2=q2.front();
             q2.erase(q2.begin());
             for(it=G[t2].begin();it!=G[t2].end();it++)
                 if(used[*it]==0)s2.insert(*it);
             for(it=G[t2].begin();it!=G[t2].end();it++)
                 if(used[*it]==0)used[*it]=2,q2.push_back(*it);
                 else if(s1.find(*it)!=s1.end())
                 {
                      if(s1.size()>=s2.size())
                      {
                             used[*it]=2;
                             q2.push_back(*it);
                             for(IT it2=q1.begin();it2!=q1.end();it2++)
                                 if(*it2==*it)
                                 {
                                     q1.erase(it2);
                                     break;
                                 }
                      }
                      else used[*it]=1;
                 }
         }
         s1.clear();
         s2.clear();
         level++;
    }
    return level;
}
int main()
{
    cin>>N;
    for(i=0;i<N-1;i++)
    {
        cin>>A>>B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    cin>>A>>B;
    for(i=1;i<=N;i++)
        used[i]=0;
    cout<<BFS()<<endl;
    return 0;
}
