#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
unsigned short mx[100000000];
unsigned short mx2[100000000];
int s;
int a;
int b,c,ob,oa;
int main()
{
    int n,m;
    cin>>n>>m;
    cin>>c;
    for(int i=0; i<c; i++)
    {
        // cout<<a<<" "<<b<<endl;
        cin>>a>>b;

        if(oa==a)
        {
            for(int j=min(b,ob); j<=max(b,ob)-1; j++)
            {
                if(mx[j]<a)
                {
                    if(a>50000) mx2[j]=a-50000;
                    else mx[j]=a;
                }

            }
        }

        oa=a;
        ob=b;
    }
    for(int i=0; i<n; i++)
    {
        if(mx2[i]) s+=m-50000-mx2[i];
        else s+=m-mx[i];
    }
    cout<<s<<endl;
    return 0;
}
/*15 10
16
6 0
6 2
11 2
11 6
8 6
8 4
9 4
9 5
10 5
10 3
6 3
6 7
12 7
12 8
9 8
9 10
*/
