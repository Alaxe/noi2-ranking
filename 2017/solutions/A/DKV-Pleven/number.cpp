#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
 long long m,n,firstnum,lastnum,cnt,add,guess;
 cnt=0;
 cin>>m>>n;
 firstnum=sqrt(m);
 lastnum=sqrt(n);
 if(firstnum*(firstnum+1)<m)
    firstnum++;
 if(lastnum*(lastnum+1)>n)
    lastnum--;
 cout<<lastnum-firstnum+1;
 return 0;
}
