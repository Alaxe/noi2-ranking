#include <iostream>

using namespace std;

int main()
{
int n,br=0,i=1,j=0;
cin>>n;
if (n==3) br=(n*(n+1)/2+n-1)-1;
if (n>3) br=(n*(n+1)/2+n-1);
if (n<3 || n>4)
{
for (i=1; j<=i/2 && j!=n; i+=2)
    for (j=0; j<=i/2; j++)
        br++;
}
cout<<br<<endl;
return 0;
}
