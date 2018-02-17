#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
using namespace std;
long long i,br=1,n1,v1;
struct tel{
 int n,v;
};
int fff(tel p1,tel p2){
    if(p1.n<p2.n){
        return true;
    }
    else return false;
}
tel k,a[1000001],kr;


int main()
{
 //   cin>>a[1].n;
   while(cin>>a[br].n && cin>>a[br].v){
        br++;

   }
  // cout<<a[1].n<<" "<<a[2].n<<endl;
   sort(a+1,a+br+1,fff);
  kr.v=a[1].n+a[1].v;
 // cout<<a[1].n<<" "<<a[1].v<<endl<<" "<<kr.v<<endl;
  for(i=2;i<=br;i++){
    if(a[i].n>kr.v){
        kr.v=a[i].n+a[i].v;
    }
    else{
        kr.v+=a[i].v;
    }
 // cout<<kr.v<<endl;
  }
 cout<<kr.v-a[br].n<<endl;
    return 0;
}
/*
0 30
720 10
715 20
714 25
*/
