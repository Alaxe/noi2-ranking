#include<bits/stdc++.h>

using  namespace  std;
int main()

{


int n,m,G=0;
cin>>n>>m;
for (int i=n;i<=m;i=i+i%10+i/10)
 {
     G=G+1;
 }
 cout<<G<<endl;



   return 0;

}
