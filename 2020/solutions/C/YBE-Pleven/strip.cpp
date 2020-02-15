#include <iostream>
#include <cstdio>
using namespace std;

int n,k;
int pr[20]={0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int a[50];

int main()
{
int i,j;
    //cin>>n>>k;
    scanf("%d%d", &n, &k);
    n--; k--;
    //cout<<pr[1]<<endl;
    for(i=n;i>=n-k+1;i--){
        int ch=i;
        for(j=1;j<=15;j++){
            if(ch == 1)break;
            if(ch%pr[j] == 0){
                ch=ch/pr[j];
                a[pr[j]]++;
                j--;
            }
        }
    }
    //long long Ans=1;
    //for(i=1;i<=50;i++){
     //   for(j=1;j<=a[i];j++)Ans*=i;
   // }
   // cout<<Ans<<endl;
  //  for(i=1;i<=50;i++)
      //  if(a[i]!=0)cout<<i<<" "<<a[i]<<endl;
    for(i=2;i<=k;i++){
        int ch=i;
        for(j=1;j<=15;j++){
            if(ch == 1)break;
            if(ch%pr[j] == 0){
                ch=ch/pr[j];
                a[pr[j]]--;
                j--;
            }
        }
    }
   // cout<<endl;
    // for(i=1;i<=50;i++)
     //   if(a[i]!=0)cout<<i<<" "<<a[i]<<endl;
    long long Ans = 1;
    for(i=1;i<=50;i++){
        for(j=1;j<=a[i];j++)Ans*=i;
    }
    cout<<Ans<<endl;
    //printf("%d\n", Ans);




    return 0;
}
