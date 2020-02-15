#include <iostream>
using namespace std;
int main()
{
int n,n1,m,br=0,br2=0;
cin>>n;n1=n;
while(n1)
{
br++;
n1=n1/10;

}
cout<<br;
return 0;
}
