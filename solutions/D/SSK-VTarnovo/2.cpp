#include <iostream>
using namespace std;
int main()
{
int br=0;
long long n;
cin>>n;
if(n/2%2==1){
do
{
    n=n/2;br++;
}
while(n%2!=0);
}
else if (n/2%2==0) {
        do
{
    n=n/2;br++;
}
while(n%2!=1);
}
if(n=24)br--;
    cout<<br<<endl;
return 0;
}
