#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=200;
vector <int> a2;
int a[maxn];
int n, m1, m2, pomagach=0, k1, k2;
int maxm1, maxm2, sum=0;
void restart()
{
   a2.clear();
   for(int i=0; i<n; ++i)
   {
      a2.push_back(a[i]);
   }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
cin >> n >> m1 >> m2;
if(m1<m2){swap(m1, m2);}
k1=m1;
k2=m2;
for(int i=0; i<n; ++i)
{
    cin >> a[i];
    a2.push_back(a[i]);
}
sort(a, a+n);
sort(a2.begin(), a2.end());
while(true)
{
    if(a2[0]>k1 && a2[0]>k2 || a2.empty())
    {
        cout << sum;
        break;
    }
    if(a2[0]>k1 && a2[0]<=k2)
    {
     pomagach=0;
       for(int i=a2.size()-1; i>=0; --i)
       {
           if(pomagach<2 && a2[i]<=k2)
           {
               pomagach=2;
               maxm2=a2[i];
               sum+=a2[i];
               a2.erase(a2.begin()+i);
               k2-=maxm2;
           }
       }
    }
    if(a2[0]<=k1)
    {
       pomagach=0;
       for(int i=a2.size()-1; i>=0; --i)
       {
           if(pomagach<1 && a2[i]<=k1)
           {
               pomagach=1;
               maxm1=a2[i];
               sum+=a2[i];
               a2.erase(a2.begin()+i);
               k1-=maxm1;
           }
       }
    }
}



return 0;
}
