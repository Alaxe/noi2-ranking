#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int w, h, n, x, prevx, prevy, y, minw=1100000001, out;
bool used[134217728];
long long ans;

struct MyStruct
{
    int x, y1, y2;
};

vector<MyStruct> v;
MyStruct currv;

bool cmp(MyStruct ff, MyStruct ss)
{
    return ff.x>ss.x;
}

int main ()
{
    //freopen("i2.txt", "r", stdin);
    scanf("%d %d", &w, &h);
    scanf("%d", &n);
    scanf("%d %d", &prevx, &prevy);
    for(int i=1; i<n; ++i)
    {
        scanf("%d %d", &x, &y);
        if(x==prevx)
        {
            minw=min(x, minw);
            currv.x=x;
            currv.y1=min(y, prevy);
            currv.y2=max(y, prevy);
            v.push_back(currv);
        }
        prevx=x;
        prevy=y;
    }
    ans=h*minw*1LL;
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<(int)v.size(); ++i)
    {
        out=0;
        for(int j=v[i].y1; j<v[i].y2; ++j)
        {
            if(!used[j])
            {
                used[j]=true;
                out++;
            }
        }
        ans+=1LL*out*(v[i].x-minw);
    }
    printf("%lld\n", (w*h*1LL)-ans);
    return 0;
}