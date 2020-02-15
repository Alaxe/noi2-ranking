#include<bits/stdc++.h>
using namespace std;
int max(int a,int b) {return(a>b)?a:b;}
int knackSack(int W,int wt[],int n)
{
      if(n==0||W==0) return 0;
  if(wt[n-1]>W) {return knackSack(W,wt,n-1);}
  else {
    return max(wt[n-1]+knackSack(W-wt[n-1],wt,n-1),knackSack(W,wt,n-1));}
}
int main()
{
    int n,W,W1;
    cin>>n>>W>>W1;

    int wt[n-1],a;
    for(int i=0;i<n;i++)
        {cin>>wt[i];
        }
    //sort
   a= knackSack(W,wt,n);
   int b=knackSack(W1,wt,n);
   cout<<a+b<<endl;

   return 0;

}

