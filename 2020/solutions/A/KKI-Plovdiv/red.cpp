#include<bits/stdc++.h>
using namespace std;
typedef map<int, int> mii;
typedef map<string, int> msi;

mii a, b;
msi a_prime, b_prime;
int w, k;

string popem(string source)
{
    return source.erase(0,source.find(",") + 1);
}

void readw1(int k)
{
    int n, prev_cnt = 0;
    string curr, prev;
    string cache;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>curr;
        cache += cache!="" ? "," + curr : curr;
        if(i >= k)
            cache = popem(cache);

        if(curr > prev)
        {
            prev_cnt++;
            if(prev_cnt >= k)
            {
                if(a_prime.find(cache) == a_prime.end())
                    a_prime[cache] = 1;
                else
                    a_prime[cache] += 1;
            }
        }
        else
             prev_cnt = 1;
        prev=curr;
    }
    cache = "";
    prev_cnt = 0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>curr;
        cache += cache!="" ? "," + curr : curr;
        if(i >= k)
            cache = popem(cache);

        if(curr > prev)
        {
            prev_cnt++;
            if(prev_cnt >= k)
            {
                if(b_prime.find(cache) == b_prime.end())
                    b_prime[cache] = 1;
                else
                    b_prime[cache] += 1;
            }
        }
        else
             prev_cnt = 1;
        prev=curr;
    }
}

void readw2(int k)
{
    int n, curr, prev, prev_cnt = 1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>curr;

        if(a.find(curr) == a.end())
            a[curr] = 0;

        if(curr==prev)
        {
            prev_cnt++;
            if(prev_cnt >= k)
                a[curr]++;
        }
        else
            prev_cnt = 1;
        prev=curr;

    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>curr;

        if(b.find(curr) == b.end())
            b[curr] = 0;

        if(curr==prev)
        {
            prev_cnt++;
            if(prev_cnt >= k)
                b[curr]++;
        }
        else
            prev_cnt = 1;
        prev=curr;
    }
}

void read(int w, int k)
{
    switch(w)
    {
    case 1:
        readw1(k);
        break;
    case 2:
        readw2(k);
        break;
    }

}

void solvew1()
{
    int result = 0;
    for(sub:a_prime)
    //cout<<"{"<<sub.first<<"} --- "<<sub.second<<endl;
        if(b_prime.find(sub.first) != b_prime.end())
            result += sub.second * b_prime[sub.first];

    cout<<result<<endl;
}

void solvew2()
{
    int result = 0;
    for(sub:a)
        if(sub.second > 0)
            if(b.find(sub.first) != b.end())
                if(b[sub.first] > 0)
                    result += sub.second * b[sub.first];


    cout<<result<<endl;
}


void solve(int w)
{
    switch(w)
    {
    case 1:
        solvew1();
        break;
    case 2:
        solvew2();
        break;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>w>>k;
    read(w, k);
    solve(w );

    return 0;
}
/*
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6

1 3
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
