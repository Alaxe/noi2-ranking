#include<bits/stdc++.h>
using namespace std;
int t,i,n,j,a,mx,mxi,k;
vector <int> s[100001],c[100001];
queue <int> q;
bool used[100001];
int main()
{
    cin>>t;
    for(i=0; i<t; i++)
    {
        mx=0;
        cin>>n;
        for(j=0; j<n; j++)
        {
            cin>>a;
            s[j].push_back(a-1);
            s[a-1].push_back(j);
        }
        for(j=0; j<n; j++)
        {
            if(s[j].size()>mx)
            {
                mx=s[j].size();
                mxi=j;
            }
        }
        used[mxi]=true;
        mx=s[mxi].size();
        for(j=0; j<s[mxi].size(); j++)
        {
            c[s[mxi][j]].push_back(j+1);
            q.push(s[mxi][j]);
        }
        while(!q.empty())
        {
            int tp=q.front();
            q.pop();
            //if(used[tp])continue;
            used[tp]=true;
            for(j=0; j<s[tp].size(); j++)
            {
                int sys=s[tp][j];
                //cout<<tp<<" "<<sys<<"\n";
                if(used[sys]==false)
                {
                    int i1=0,i2=0;
                    if(!c[sys].size())
                    {
                        for(k=1;;k++)
                        {
                            while(i1+1<c[tp].size())
                            {
                                if(c[tp][i1]>=k)break;
                                i1++;
                            }
                            //cout<<i1<<" "<<i2<<" B ";
                            if(c[tp][i1]!=k )break;
                            //cout<<"A ";
                        }
                    }
                    else
                    {
                        for(k=1;;k++)
                        {
                            while(i1+1<c[tp].size())
                            {
                                if(c[tp][i1]>=k)break;
                                i1++;
                            }
                            while(i2+1<c[sys].size())
                            {
                                //cout<<"D";
                                if(c[sys][i2]>=k)break;
                                i2++;
                            }
                            //cout<<i1<<" "<<i2<<" B ";
                            if(c[tp][i1]!=k && c[sys][i2]!=k)break;
                            //cout<<"A ";
                        }
                    }
                    c[tp].push_back(k);
                    sort(c[tp].begin(),c[tp].end());
                    c[sys].push_back(k);
                    sort(c[sys].begin(),c[sys].end());
                    if(mx<k)mx=k;
                    q.push(sys);
                    //cout<<tp<<" "<<sys<<" "<<k<<"\n";
                }
            }
        }
        cout<<mx<<"\n";
        for(j=0;j<n;j++)
        {
            s[j].clear();
            c[j].clear();
        }
        memset(used,0,100001);
    }
    return 0;
}
/*
2
4
4 1 2 3
5
4 1 2 3 4

1
5
4 1 2 3 4
*/
