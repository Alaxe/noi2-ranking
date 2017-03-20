#include<iostream>
using namespace std;
int main()
{
      int M,K,A[200],i,br=0,S=0,k=100000,brk=0;
      cin>>M>>K;
      for(i=0;i<=200;i++)
      {
            cin>>A[i];
            if(A[i]%2==0)S=S+A[i];
            if(A[i]>M)
            {
                  if(A[i]-M<k){k=A[i]-M;brk++;}
                  else if(A[i]-M>k)brk++;
            }
            else if(A[i]<M)
            {
                  if(M-A[i]<k){k=M-A[i];brk++;}
                  else if(M-A[i]>k)brk++;
            }
            if(S>=K){cout<<brk<<" "<<S<<endl;
            return 0;}
      }
      cout<<brk<<" "<<S<<endl;
return 0;
}
