#include<iostream>
using namespace std;

string s;
bool perm[128];
long long ans,n;

bool check_pal();
void print();

void rec(int i, bool x)
{
    //cout<<n<<endl;
    perm[i]=x;
    if(i==n)
    {
        if(check_pal())ans++;
        return ;
    }
    rec(i+1,1);
    rec(i+1,0);
}

bool check_pal()
{
    for(int l=1,r=n;;)
    {
        //cout<<l<<" "<<r<<endl;
        if(l>=r)break;

        if(perm[l]==1)
        {
            if(perm[r]==1)
            {
                if(s[l-1]==s[r-1])
                {
                    l++;
                    r--;
                }
                else return false;
            }
            if(perm[r]==0)
            {
                r--;
            }
        }
        else
            if(perm[r]==1)
            {
                if(perm[l]==0)
                {
                    l++;
                }
            }
        else
        {
            l++;r--;
        }

    }
    //print();
    return true;
}

void print()
{
    for(int i=1;i<=n;i++)
    {
        cout<<perm[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    cin>>s;
    n=s.size();
    rec(1,1);
    rec(1,0);
    cout<<ans-1<<endl;
}
