#include<bits/stdc++.h>
using namespace std;
deque<int> open;
map<int,int> del;
bool flag;
int last_open_idx,closed,incapability,isopened,powerful;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin>>a;
    int sz = a.size();
    for(int i=0; i<sz; i++)
    {
        if(a[i]=='(')
        {
            open.push_back(i);
        }
        else if(a[i]==')')
        {
            incapability = 0;
            isopened = 0;
            powerful=0;
            flag = 1;
            last_open_idx = open.back();
            open.pop_back();
            for(int j=last_open_idx+1; j<i; j++)
            {
                if(a[j]=='(')
                {
                    isopened++;
                }
                else if(a[j]==')')
                {
                    isopened--;
                }
                else if(a[j]=='+' || a[j]=='-')
                {
                    if(isopened==0)
                    {
                        incapability = 1;
                        break;
                    }
                }
                else if(a[j]=='*' || a[j]=='/')
                {
                    powerful++;
                }
            }
            if(last_open_idx>0)
            {
                if(a[last_open_idx-1] == '-')
                {
                    if(incapability==1 || powerful==0)
                    {
                        flag = 0;
                    }
                }
                if(a[last_open_idx-1] == '/')
                {
                    flag = 0;
                }
                if(a[last_open_idx-1] == '*')
                {
                    if(incapability==1 || powerful==0)
                    {
                        flag = 0;
                    }
                }
            }
            if(i<sz)
            {
                if(a[i+1]=='/')
                {
                    if(incapability==1 || powerful==0)
                    {
                        flag = 0;
                    }
                }
                if(a[i+1]=='*')
                {
                    if(incapability==1 || powerful==0)
                    {
                        flag = 0;
                    }
                }
            }
            if(flag == 1)
            {
                del[i]=1;
                del[last_open_idx]=1;
            }
        }
    }
    for(int i=0; i<sz; i++)
    {
        if(del[i]!=1)
        {
            cout<<a[i];
        }
    }
    cout<<endl;
}
