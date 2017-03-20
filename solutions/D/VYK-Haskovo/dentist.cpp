#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct in
{
    int minn;
    int time;
};

int i=0;
bool flag=true;
int m,time=0,sum=0,j=0,br=0,l=0;
in a[1000];

bool cmp (in x, in y)
{
    if (x.minn<y.minn) return true;
    return false;
}

int suv (int time)
{
    for (int j=0;j<i;j++)
    {
        if (a[j].minn==time) return j;
    }
    return i+1;
}

int main ()
{
    queue <int> st;

    while (cin>>a[i].minn>>a[i].time)
    {
        i++;
    }
    sort (a,a+i,cmp);
    while (flag==true)
    {

        for (int j=i-1;j>=0;j--)
        {
            if (a[j].minn==time) {st.push(a[j].time);}
        }

         if (!st.empty())
            {
                if(sum+1==st.front()) {sum=0;st.pop();}
                else sum++;
            }
        if (a[i-1].minn<=time) {br++;}
        if (st.empty() && time>a[i-1].minn) {break;}
        time++;
    }
    cout<<br<<"\n";
    return 0;
}
