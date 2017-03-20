#include<iostream>
using namespace std;
int main()
{
int a;
cin>>a;
int stot=a/100;
int des=a/10%10;
int ed=a%10;
cout<<ed<<des<<stot<<endl;
return 0;
}
