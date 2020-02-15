#include <bits/stdc++.h>
using namespace std;

long long n, w1, w2;
long long a[200], b[200];
bool used[200];
bool used2[200];
int ans=0, ans2=0, curr, index;
bool l=false;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>w1>>w2;
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a, a+n);
    if(w1>w2)
        swap(w1, w2);

    l=false;
    curr = w1;
    index = 0;
    if(w1<a[0]) ans+=0;
    else
    {
        while(curr>0)
        {
            if(index>=n) break;
            if(curr>=a[index])
            {
                used[index]=true;
                curr -= a[index];
                index++;
                l=1;
            }
            else
                for(int i=0; i<n; i++)
                    if((curr+a[i])>=a[index]&&used[i])
                    {
                        used[index]=true;
                        used[i]=false;
                        curr += a[i];
                        curr -= a[index];
                        index++;
                        l=1;
                        break;
                    }
            if(!l) break;
        }
        ans+=(w1-curr);
    }

    int j=0;
    for(int i=0; i<n; i++)
    {
        if(!used[i])
        {
            b[j]=a[i];
            j++;
        }
    }

    l=false;
    curr = w2;
    index = 0;
    if(w2<b[0]) ans+=0;
    else
    {
        while(curr>0)
        {
            if(index>=j) break;
            if(curr>=b[index])
            {
                used2[index]=true;
                curr -= b[index];
                index++;
                l=1;
            }
            else
                for(int i=0; i<j; i++)
                    if((curr+b[i])>=b[index]&&used2[i])
                    {
                        used2[index]=true;
                        used2[i]=false;
                        curr += b[i];
                        curr -= b[index];
                        index++;
                        l=1;
                        break;
                    }
            if(!l) break;
        }
        ans+=(w2-curr);
    }

    cout<<ans<<endl;
    return 0;
}

