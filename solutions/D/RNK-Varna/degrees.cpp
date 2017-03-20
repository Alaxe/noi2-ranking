#include<iostream>
using namespace std;
int main ()
{
unsigned long long n,nt;
int br,i=0,j=0;
cin >> n;
nt=n;
for(br=0;nt>0;br++)nt/=10;
int c[16]={1,1,1,2,2,2,3,3,3,4,4,4,4,5,5,5};
while(j<=br)
{
    j+=c[i];
    i++;
}
cout << i-1 << endl;
return 0;
}
