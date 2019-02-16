#include <iostream>
using namespace std;
int main()
{
long long a[1000000], b=1, n, m=1, p=0;
cin>>n;
while(1)
{
    if(m<b)a[p]=m;
        else
        {
            if(b==m)a[p]=m;
            while(1)
            {
            m--;
            if(m!=0)a[p]=m;
                else {
                        b++;
                        break;
                     }
            }
        }

    if(a[p]==n)
    {
        if(p==0)cout<<p+1<<endl;
            else cout<<p-1<<endl;
        break;
    }
    p++;
    m++;
}
return 0;
 }
