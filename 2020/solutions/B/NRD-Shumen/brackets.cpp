#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;
string s;
int used[200008];
void read()
{
    cin>>s;
}
void solve()
{
    int sz=s.size();
    for(int i=0; i<sz; i++)
    {
        if(s[i]=='(')
        {
            int br=1;
            int br1=0;
            int b=i;
            int e;
            for(int j=i+1; j<sz; j++)
            {

                if(s[j]=='(')
                {
                    br++;
                }
                else if(s[j]==')')
                {
                   br1++;
                }
               if(br==br1)
               {
                   e=j;
                   break;
               }
            }
            int l=0;
            for(int j=b-1;j>=0;j--)
            {
                if(s[j]!='&' && s[j]!='(')
                {
                    if(s[j]=='+')
                    {
                        if(e+1>sz)
                        {
                            used[b]=1;
                            used[e]=1;
                        }
                        for(int k=e+1;k<sz;k++)
                        {
                            if(s[k]!='&' && s[k]!=')')
                            {
                                if(s[k]=='+')
                                {
                                    used[b]=1;
                                    used[e]=1;
                                    l=1;
                                    break;
                                }
                            }
                        }
                    }
                }
                if(l==1) break;
            }
        }
    }
    for(int i=0;i<sz;i++)
    {
        if(used[i]==0)
        {
            cout<<s[i];
        }
    }
    cout<<endl;
}
int main()
{
    read();
    solve();

    return 0;
}
