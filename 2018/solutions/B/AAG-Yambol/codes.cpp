#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define pb push_back
#define mp make_pair
using namespace std;
const int N=1e2+5;
const long long INF=1e18+5;

int n,k;
int dig[N];
long long A,B;

int max_diff;
string biggest;

int abs(int x)
{
    if(x < 0)
        return -x;
    return x;
}

int get_ind(long long at,long long jump)
{
   long long odd;

   if(at%jump == 0 && jump > 1)
    at--;

   if(jump*n > INF || jump*n < 0)
    odd=1;
   else
   {
     if(at % (jump*n) == 0)
        odd=at/(jump*n);
     else
        odd=at/(jump*n) + 1;
     odd%=2;
   }

   long long indig;

   if(jump > 1)
    indig=(at/jump + 1)%n;
   else
    indig=(at/jump)%n;

   if(indig == 0)
    indig=n;

   //cerr<<at<<" "<<" "<<jump<<" "<<odd<<endl;

   if(odd)
    return indig;
   else
    return (n-indig+1);

}

long long max_pow;
long long can(int pos,int d) /// is it possible to have digit dig[d] at position pos (leftmost digit is k)
{
    pos--;

    long long jump=1;

    if(pos > max_pow)
        jump=INF;
    else
    {
      for(int i=1;i<=pos;i++)
         jump*=n;
    }

    if(jump == INF)
    {
        if(d == 1)
            return A;
        else
            return 0;
    }

     long long tempA;
     if(A%jump == 0)
        tempA=A-jump + 1;
     else
        tempA=A-(A%jump) + 1;

     while(tempA <= B)
     {
         if(get_ind(tempA,jump) == d)
         {
            if(tempA < A)
                return A;

            return tempA;
         }

         tempA+=jump;

         if(tempA < 0)
            break;
     }

     return 0;

     /// return the index of first number that has the property
}

void corner_maxdiff()
{
    long long i,j;
    int s,prevs=-1;
    long long jump;

    for(i=A;i<=B;i++)
    {
        s=0;

        jump=1;
        for(j=1;j<k;j++)
        {
            jump*=n;
            if(jump > INF || jump < 0)
            {
                jump = INF;
                break;
            }
        }
        for(j=k;j>=1;j--)
        {
            s+=dig[get_ind(i,jump)];
           // cerr<<dig[get_ind(i,jump)];
            jump/=j;
        }
       // cerr<<endl;

        //cerr<<s<<" "<<prevs<<endl;

        if(i > A)
        {
            max_diff=max(max_diff,abs(s-prevs));
        }

        prevs=s;
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int i,j;

   cin>>n>>k>>A>>B;
   for(i=1;i<=n;i++)
       cin>>dig[i];

   if(n == 1)
   {
     max_diff=0;
     for(i=1;i<=k;i++)
     {
         biggest.pb('0' + dig[1]);
     }

     cout<<biggest<<" "<<max_diff<<endl;

     return 0;
   }


   if(B-A >= n)
   {
    for(i=1;i<n;i++)
      max_diff=max(abs(dig[i]-dig[i+1]),max_diff);
   }
   else
   {
       corner_maxdiff();
   }


   long long temp=1;

   if(n == 1)
   {
     max_pow=INF;
   }
   else
   for(i=1;;i++)
   {
       temp*=n;

       if(temp < 0 || temp > INF)
       {
           max_pow=i;
           break;
       }
   }


   long long cur_best,arem;
   for(i=k;i>=1;i--)
   {
       cur_best=-1;
       for(j=1;j<=n;j++)
       {
           if(can(i,j) && dig[j]>cur_best)
           {
               cur_best=dig[j];
               arem=can(i,j);
           }
       }


       A=arem;
       biggest.pb('0' + cur_best);

       //cerr<<A<<" -A"<<endl;
   }

   cout<<biggest<<" "<<max_diff<<endl;

   return 0;
}

/*

3 2 3 5
7 1 5

*/

/*

3 3 10 16
7 1 5

*/

