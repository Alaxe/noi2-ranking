#include <iostream>

using namespace std;

long long N, K, FIRST, MUL, ADD, MOD;

long long days [10000000];
int br;

long long getter (long long f)
{
return (f*MUL + ADD)%MOD;

}

long long finder (long long a)
{
    long long n;
    n=days[a-K+1]; br=1;
 for (long long i=a-K+2; i<a+1; i++)
 {
     
 
    
    if (days[i]>=n) {n=days[i]; br=i-a+K-1;}
    
 }
    return n;
}

int main ()
{

cin>>N>>K>>FIRST>>MUL>>ADD>>MOD;
long long max=FIRST,bord=K;
long long sum=FIRST;
days[0]=FIRST;
bord--;
for(long long i=1; i<N; i++)
{
FIRST=getter(FIRST);
days[i]=FIRST;
if (bord==0) {max=finder (i); bord=br; }
else {if (max<FIRST) {max=FIRST; bord=K;} }

sum=sum+max;
bord--;
}

cout<<sum;

return 0;
}