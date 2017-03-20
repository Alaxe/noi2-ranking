#include<bits/stdc++.h>
using namespace std;
long long t,br,i,j,fst;
struct dentist
{
    long long st,tz,end;
};
dentist m[1000000];
bool cmp (dentist a, dentist b)
{
    return a.st<b.st;
}
int main()
{
    for (br=0;;br++)
    {
        cin>>m[br].st>>m[br].tz;
        m[br].end=m[br].st+m[br].tz;
        if (cin.eof()) break;
    }
    sort (m,m+br,cmp);
    fst=m[br-1].st;
    for (i=0;i<br-1;i++)
    {
        if (m[i].end>m[i+1].st)
        {
            t=m[i].end-m[i+1].st;
            m[i+1].st=m[i].end;
            m[i+1].end=m[i+1].st+m[i+1].tz;
        }
    }
    cout<<m[br-1].end-fst<<endl;
    return 0;
}
/**
55 15
185 22
130 10

22
////////
0 30
720 10
715 20
714 25

49
*/
