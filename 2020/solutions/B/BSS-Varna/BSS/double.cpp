#include<bits/stdc++.h>
using namespace std;
int n,w1,w2,a[205],used[205],used2[205],s[205],s1[205],used3[205],used4[205],s3[205],s4[205];
bool m[205][205],M[205][205];
vector<int> v[205],v1[205];
int main()
{
    cin>>n>>w1>>w2;
    if(w1>w2)swap(w1,w2);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[1][a[i]]=1;
        M[1][a[i]]=1;
        if(v[a[i]].size()==0)v[a[i]].push_back(a[i]);
        if(v1[a[i]].size()==0)v1[a[i]].push_back(a[i]);
        s[a[i]]=1;
        s3[a[i]]=1;
        s1[a[i]]=1;
        s4[a[i]]=1;
        used2[a[i]]++;
        used4[a[i]]++;
    }
    sort(a,a+n);
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=w1;j++)
        {
            if(m[i-1][j]==0)continue;
            for(int g=0;g<v[j].size();g++)
            {
                used[v[j][g]]++;
            }

            for(int g=0;g<n;g++)
            {
                ///cout<<i<<' '<<j<<' '<<s1[j+a[g]]<<' '<<j+a[g]<<' '<<used[a[g]]<<endl;
                if((s1[j+a[g]]<i && s1[j+a[g]]!=0) || a[g]+j>w1 || used2[a[g]]-used[a[g]]==0)continue;
                m[i][j+a[g]]=1;
                ///cout<<i<<' '<<j+a[g]<<endl;
                v[j+a[g]]=v[j];
                v[j+a[g]].push_back(a[g]);
                s1[a[g]+j]=i;
                s[a[g]+j]=s[j]+1;
            }
            for(int g=0;g<v[j].size();g++)
            {
                used[v[j][g]]--;
            }
        }
        if(m[i][w1]==1)break;
    }
    for(int i=w1;i>=0;i--)
    {
        if(s[i]==0)w1--;
        else break;
    }
    for(int i=0;i<v[w1].size();i++)
    {
        used4[v[w1][i]]--;
        if(used4[v[w1][i]]==0)
            {
                M[1][v[w1][i]]=0;
                v1[a[i]].pop_back();
            }
    }
    int maxi=0;
    ///cout<<w1<<endl;
    for(int i=2;i<=n-v[w1].size();i++)
    {
        for(int j=1;j<=w2;j++)
        {
            if(M[i-1][j]==0 || v1[j].size()==0)continue;
            for(int g=0;g<v1[j].size();g++)
            {
                ///cout<<v1[j][g]<<endl;
                used3[v1[j][g]]++;
            }

            for(int g=0;g<n;g++)
            {
                ///cout<<i<<' '<<j<<' '<<s1[j+a[g]]<<' '<<j+a[g]<<' '<<used4[a[g]]<<' '<<used3[a[g]]<<endl;
                if((s4[j+a[g]]<i && s4[j+a[g]]!=0) || a[g]+j>w2 || used4[a[g]]-used3[a[g]]<=0)continue;
                M[i][j+a[g]]=1;
                if(maxi<j+a[g]){maxi=j+a[g];if(w1<maxi+w1)w1=maxi+w1;}
                v1[j+a[g]]=v1[j];
                v1[j+a[g]].push_back(a[g]);
                /**for(int I=0;I<v1[j+a[g]].size();I++)
                {
                    cout<<v1[j+a[g]][I]<<' ';
                }*/
                s4[a[g]+j]=i;
                s3[a[g]+j]=s[j]+1;
            }
            for(int g=0;g<v1[j].size();g++)
            {
                used3[v[j][g]]--;
            }
        }
        ///if(M[i][w2]==1)break;
    }
    cout<<w1<<endl;
    cout<<endl;
}
/**
5 10 14
5 6 7 8 4

5 20 15
5 5 5 19 5
*/

