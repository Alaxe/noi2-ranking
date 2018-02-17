#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
long long po(int a,int b){
  long long ba=a;
  for(int i=1;i<b;i++){
     ba=ba*a;
  }
  return ba;
}
vector<int> a;
int main(){
    string b;
    getline(cin,b);
    long long sbor=-1;
    for(int i=1;sbor<=b.length();i++){
      for(int j=0;j<3;j++){
          a.push_back(i);
          sbor+=i;
          if(b.length()==sbor){
            cout<<a.size()-1;
            return 0;
          }
      }
     if(i%3==1){
        sbor+=i;
        a.push_back(i);
        if(b.length()==sbor){
          cout<<a.size()-1;
          return 0;
        }
     }
  }
  return 0;
}
