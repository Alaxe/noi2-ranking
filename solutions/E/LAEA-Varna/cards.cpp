#include <iostream>
using namespace std;
int main() {
int N, a, b, a1, b1, br=0;
cin>>N;
for (int i=1; i<=N; i++)
{cin>>a>>b; a1=a; b1=b;
if (a<=a1&&b<=b1) br++;
else if (a<=b1&&a<=a1) br++;}
cout<<br<<endl;
return 0;
}
