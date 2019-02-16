#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<stack>
#include<string>

using namespace std;

int a[10005];

bool del(int ch,int n)
{
    for(int i = 0;i < n;i++)
    {
        if(ch % a[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}
int mnoj[50];

int main()
{
    int n,k,c = 1,c1 = 1;
    bool br = 0;
    cin>>n>>k;
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }

    for(int i = 2;i <= 43;i++)
    {
        br = 0;
        for(int j = 0;j < n;j++)
        {
            if(a[j] % i == 0)
            {
                br = 1;
                a[j] /= i;
            }
        }

        if(br == 1)
        {
            mnoj[i]++;
            i--;
        }
    }

    for(int i = 2;i < 44;i++)
    {
        if(mnoj[i] > 0)
        {
            mnoj[i] = mnoj[i] + k - (mnoj[i] % k);
            mnoj[i] /= k;
            for(int j = 0;j < mnoj[i];j++)
            {
                c *= i;
            }
        }
    }
    cout<<c<<endl;
}
