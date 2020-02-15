#include<bits/stdc++.h>
using namespace std;
int main(){
long long a,c,i,s1=0,s2=0;
char b[1000000];
cin>>a;
cin>>b;
for(i=0;i<a;i++){
  if(b[i]=='a'||b[i]=='b'){
    s1++;
  }else{
      s2++;
  }
}
while(s1!=s2&&a>0){
    if(b[a]=='a'||b[a]=='b'){
    s1--;
     }else{
      s2--;
     }
    b[a-1]='/0';
     a--;

}
cout<<a;
}
