#include <iostream>
using namespace std;
int main() {
int M, K, a, s=0, c;
cin>>M>>K; c=a;
while (s<K)
{cin>>a;
if (a%2==0) s=s+a;
if (a-M<c) c=a;
if (a==200) break;}
cout<<c<<" "<<s<<endl;
return 0;
}
