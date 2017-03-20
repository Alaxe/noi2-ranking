#include<iostream>
using namespace std;
int main()
{
      int n,A[100000],br=1,i,j,m=1000000,k=1000000,brn=0;
      cin>>n;
      for(i=0,j=0;i<n,j<n;i++,j++)
      {
      cin>>A[i]>>A[j];
      if((A[i]>=m)&&(A[j]>=k))br++;
      m=A[i];
      k=A[j];
      if((A[i]<m)&&(A[j]<k)){if(br>=brn){brn=br;
      return br;}
      else return br;}
      }
      if(brn>br)cout<<brn<<endl;
      else cout<<br<<endl;
return 0;
}
