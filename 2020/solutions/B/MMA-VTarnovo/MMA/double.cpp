#include <iostream>
using namespace std;
int main()
{int n,a[200],W1,W2,i,m,br,s,k,p;
cin>>n>>W1>>W2;
if(W1<W2) {s=W1,k=W2;} 
else {s=W2,k=W1;}
for(i=0;i<n;i++) cin>>a[i];
for(i=0;i<n;i++)
{
if(a[i]+a[i+1]<a[i]+a[i+2]) {m=a[i]+a[i+2]; n--;}
else m=a[i]+a[i+1];
   if(m<a[i+1]+a[i+2]) {m=a[i+1]+a[i+2]; n-- ;} 

}
if(m+a[0]+a[2]<W1+W2) m=m+a[0]+a[2];
cout<<m<<endl;
}
