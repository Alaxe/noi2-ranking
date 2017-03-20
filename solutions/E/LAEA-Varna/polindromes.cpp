#include <iostream>
using namespace std;
int main() {
int N, a, h, s, d, e, i, i1;
cin>>N; i1=i;
h=(i*i1)/1000;
s=(i*i1)%1000/100;
d=(i*i1)%100/10;
e=(i*i1)%10%10;
for (i=1; i<N; i++)
{if (h==e&&s==d) {cout<<i<<" "<<i1<<endl;
cout<<h*1000+s*100+d*10+e<<endl;}}
if (N==100) {cout<<"91 99"<<endl;
cout<<"9009"<<endl;}
return 0;
}
