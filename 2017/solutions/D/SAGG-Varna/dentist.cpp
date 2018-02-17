#include <iostream>
#include <algorithm>
using namespace std;
struct doc
{
    int arr;
    int t;
};
bool cmp (doc a,doc b)
{
    return (a.arr<b.arr);
}
int main ()
{
    doc d[1000];
    int br=0,n=0;
    while (true)
    {
        cin >> d[n].arr>>d[n].t;
        if(cin.eof()) break;
        n++;
    }
    sort (d,d+n,cmp);
    for (int i=0; i<n-1; i++)
    {
        int temp=d[i].arr+d[i].t+br;
        if (temp>d[i+1].arr) br=temp-d[i+1].arr;
        else br=0;
        //cout<<d[i].arr<<" "<<d[i].t<<" "<<temp<<" "<<br<<" "<<d[i+1].arr<<endl;
    }
    cout<<br+d[n-1].t<<endl;
    return 0;
}
