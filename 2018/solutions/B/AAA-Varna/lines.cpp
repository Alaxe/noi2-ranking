#include <iostream>
#include <algorithm>
//#define sortarr
#define endl '\n'
#define MAX 2
using namespace std;
///
int n;
struct point
{
    int x,y;
} arr[104];
int answ;
int arrx [204];
int arry [204];
int i;
int a;
double rel [104];

///
#ifdef sortarr
bool cmp (point a, point b)
{
    if (a.x<b.x) return true;
    if (a.x==b.x)
    {
        if (a.y<b.y) return true;
        else return false;
    }
    return false;
}
#endif // sortarr

int main ()
{
    ///
    ios::sync_with_stdio(0);
    cin.tie(0);
    ///
    answ=MAX;
    cin>>n;

    for (i=0; i<n; i++)
    {
        cin>>arr[i].x>>arr[i].y;
    }
#ifdef sortarr
    sort (arr, arr+n, cmp);
#endif
    int br=0;
    for (i=-100; i<=100; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (arr[j].x==i) arrx[br]++;
            if (arr[j].y==i) arry[br]++;
        }
        br++;
    }

    sort (arrx, arrx+br);
    sort (arry, arry+br);
    answ=max(arrx[br-1], arry[br-1]);
    br=0;
    for (int j=0; j<n; j++)
    {
        if (arr[j].y!=0 && arr[j].x!=0)
        {
            rel[j]=arr[j].x/arr[j].y;


        }
        else if (arr[j].y==0 && arr[j].x==0) {
		rel[j]=99999;
		br++;
        }
    }
int br1=0;
    for (int j=0; j<n; j++) {
	if (rel[j]!=99999) {
		br1=count (rel, rel+n, rel[j]);
		if (br1+br>answ) answ=br1+br;
	}
    }

    if (answ<MAX) answ=MAX;
    cout<<answ<<endl;
}
/*
6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3
*/
