#include  <bits/stdc++.h>
using  namespace  std;
int main()
{
 int n,k,br=1;
 unsigned long long ch=1;
 cin>>n>>k;
 if (n/10<=k/10)
 {
 while (br!=n)
 {br++;
  ch*=10;
  }
  while (ch%k!=0)
 {ch++;

          }

cout<<ch<<endl;

 }

 else cout<<"NO";

 return 0;
}
