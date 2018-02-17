#include <iostream>
using namespace std;
int backup [9999998];
long long k,n,curwin,mul,add,mod,curcon,bindex,write,cnt,maxmax,fun,wini;
int main ()
{
   cin>>n>>k;
   cin>>curwin>>mul>>add>>mod;
   bindex=-1;
   fun=curwin;
   for(int i =0;i<n;i++)
   {

       curcon=((curcon*mul)+add)%mod;
       if(curcon<=curwin)
       backup[write]=curcon;
       if(cnt==k+1)
       {
           for(int i=bindex;i<=write;i++)
            {if(backup[i]>maxmax)
            {maxmax=backup[i];
            wini=i;}
            }
           curwin=maxmax;
           bindex=wini;
       }
        if(curcon>curwin)
        {
        curwin=curcon;
        bindex=write;//moje bi bez +1
        write--;
        cnt=0;
        }
        if(write-bindex>=k-2)
        bindex++;
        write++;
        cnt++;
        fun+=curwin;
   }
   cout<<fun;
}
