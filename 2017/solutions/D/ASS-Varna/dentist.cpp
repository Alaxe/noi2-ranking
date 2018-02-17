#include<bits/stdc++.h>
using namespace std;
struct pac
{
    int dosh;
    int prod;
};
pac a[1000];
bool cmp(pac a, pac b)
{
return a.dosh<b.dosh;
}
int main()
{
    int n=0,i=0,kud=0;
    while(1)
    {
    cin>>a[i].dosh>>a[i].prod;
    i++;n++;
    if (cin.eof()) break;
    }
    sort(a,a+n,cmp);
    kud=a[0].dosh;
    for (i=0;i<n;i++)
    {
    if (kud<a[i].dosh) kud=a[i].dosh;
    kud+=a[i].prod;
    }
    cout<<kud-a[n-1].dosh<<endl;
    return 0;
}
/**
Input:
55 15
185 22
130 10
Ouput:
22
------------
Input:
0 30
720 10
715 20
714 25
Ouput:
49
*/
