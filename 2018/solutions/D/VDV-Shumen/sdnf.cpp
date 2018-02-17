#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
int n;
cin>>n;
int sum=0;
int pr=1;
int y=n;
while (y!=0)
{pr=pr*y;
y--;
}
while (pr!=0)
{
    sum=sum+pr%10;
    pr=pr/10;
}
cout<<sum<<endl;
    return 0;
}
