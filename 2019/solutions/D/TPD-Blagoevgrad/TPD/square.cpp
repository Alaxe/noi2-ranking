#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int main()
{
/*long long n,a[10000];
cin>>n;
for (int i=0;i<n;i++){
    cin>>a[i];
}
  while ()
*/
 long long n,umno=1,broiche;
 cin>>n;
 for (int i=0;i<n;i++){
    cin>>a[i];
 }

 for (int i=0;i<n;i++){
     umno*=a[i];
 }
 for (int j=0;j<n;j++){
   for (int i=0; ;i++){
    if ((i*i)%a[j]!=0) break;
    else if ((i*i)%a[j]==0);
   }
  broiche=j;
 }
 if (n==1) {cout<<a[0]; return 1;}
cout<<broiche;
cout<<endl;

return 0;
}


