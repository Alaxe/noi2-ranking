#include <iostream>
#include <set>
#define N 1001
#define S 2000100
#define M 1000050
using namespace std;
//set <int> s;
//set <int>::iterator it;
int a[N];
int b[S];

int main()
{
    int i,n,siz,j,minx=S,maxx=0,br=0;
    cin>>n;
   // s.insert(0);
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
        for(j=minx; j<=maxx; j++)
        {
            if(b[j]>0 && b[j]<i)
            {
                //cout<<j<< endl;
                if(b[j+a[i]]==0)
                {
                    br++;
                    b[j+a[i]]=i;
                    if(j+a[i]<minx) minx=a[i]+j;
                    if(a[i]+j>maxx) maxx=a[i]+j;
                }
            }
        }
        if(a[i]+M<minx) minx=a[i]+M;
        if(a[i]+M>maxx) maxx=a[i]+M;
        if(b[a[i]+M]==0)
        {
            br++;
            b[a[i]+M]=i;
        }
        /*for(it=s.begin(),j=1,siz=s.size(); j<=siz; it++,j++)
        {
          //  cout<<*it<<" "<<j<< endl;
            s.insert(*it+a[i]);
        }*/
    }
    //for(i=1; i<=1000000000; i++) a[1]=i;
    //cout<<s.size()<< endl;
    cout<<br<< endl;
    return 0;
}
/*
5
1 -2 0 7 7
*/
