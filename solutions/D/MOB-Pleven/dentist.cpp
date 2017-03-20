#include<iostream>
#include<algorithm>
using namespace std;
struct dentist{
int t;
int o;

}t[50000];
bool cmp(dentist a,dentist b)
{
    if(a.t>b.t)return 0;
    else return 1;
}
int main()
{
    int i=0;
while( cin>>t[i].t>>t[i].o)
{
    i++;
}
sort(t,t+i,cmp);
//cout<<t[0].t<<' '<<t[0].o;
int razl=0;
int a;
for(int j=0;j<i-1;j++)
{
    a=t[j].t+t[j].o;
    if(a+razl<t[j+1].t)razl=0;
    else razl=(a+razl)-t[j+1].t;
}
cout<<razl+t[i-1].o<<endl;
return 0;
}
/*
0 30
720 10
715 20
714 25
*/
/*
55 15
185 22
130 10
*/
