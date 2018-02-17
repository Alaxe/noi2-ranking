#include <iostream>
#define intt unsigned long long int
using namespace std;
intt a[9999999];
intt d=1;
intt n,br=0;
void f(int d)
{
     for(intt i=1; i<=n; i++)
        {
            for(intt j=i; j<=n; j++)
            {
                if(a[i]+d==a[j])br++;
            }
        }
}
int main()
{

    cin>>n;
    intt ch=0;
    for(intt i=1; i<=n; i++)
    {
        cin>>a[i];
        if(ch<a[i])
            ch=a[i];
    }

    for(intt i1=1; i1<=ch; i1++)
    {
       f(d);
        d++;
    }
    ////////////////////////////////////////////
       //permutation with reperirion
       ///////////////////////////////////////////////
    cout<<br<<endl;
    return 0;
}
/*
6
1 9 1 9 2 3

*/
