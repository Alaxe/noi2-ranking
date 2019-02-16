#include<iostream>
using namespace std;

int main()
{
int a,b;
cin>>a>>b;
int x;
while (x<b)
{
for (x=a;x<=b;x++)
{
for(int y=1;y<=x;y++)
{int z;
if (x%y==0) z++;
int z1;
if (z%2==1) z1++;
}
}

cout<<x;
}

}
