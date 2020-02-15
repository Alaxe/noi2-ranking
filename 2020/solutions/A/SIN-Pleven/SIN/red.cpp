#include<iostream>
#include<vector>
#include<cstdio>
#include<deque>
#include<set>
#include<map>
using namespace std;
int w, k, m , n, ans;
map<deque<int> , int> setsA, setsB;
int main ()
{
    scanf("%d%d",&w,&k);
    scanf("%d",&n);

    deque<int> dq;
    for (int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        if (dq.empty())
        {
            dq.push_back(x);
        }
        else
        {
            if (w==1)
            {
                if (x <= dq.back())
                {
                    dq.clear();
                }
            }
            else
            {
                if (x != dq.back())
                {
                    dq.clear();
                }
            }
            dq.push_back(x);
            if (dq.size() == k)
            {
                setsA[dq]++;
                dq.pop_front();
            }
        }
    }
    dq.clear();
    scanf("%d",&m);
    for (int i=0; i<m; i++)
    {
        int x;
        scanf("%d",&x);
        if (dq.empty())
        {
            dq.push_back(x);
        }
        else
        {
            if (w==1)
            {
                if (x <= dq.back())
                {
                    dq.clear();
                }
            }
            else
            {
                if (x != dq.back())
                {
                    dq.clear();
                }
            }
            dq.push_back(x);
            if (dq.size() == k)
            {
                setsB[dq]++;
                dq.pop_front();
            }
        }
    }

    if (setsA.size() < setsB.size())
    {
        for (map<deque<int>, int>::iterator it = setsA.begin(); it != setsA.end(); it++)
        {
            ans += setsA[it->first]*setsB[it->first];
        }
    }
    else
    {
        for (map<deque<int>, int>::iterator it = setsB.begin(); it != setsB.end(); it++)
        {
            ans += setsA[it->first]*setsB[it->first];
        }
    }
    printf("%d", ans);
    //cout<<setsA.size()<<endl;
    //cout<<setsB.size()<<endl;

    return 0;
}
/**
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6

1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7
*/
