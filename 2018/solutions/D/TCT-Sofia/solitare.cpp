#include <iostream>
using namespace std;

int main(){
  long long n, i, j;
  cin>>n;
  class card{
    public: long long value;
    public: long long maxValue;
    public: char writenValue;
    public: char color;
  };
  card solitare[n+1][n+1];
  for(i=0;i<n+1;i++){
    for(j=0;j<n+1;j++){
      if(i==n){
        solitare[i][j].maxValue=0;
      }
      else{
        if(j==0){
          solitare[i][j].maxValue=0;
        }else{
          cin>>solitare[i][j].writenValue;
          cin>>solitare[i][j].color;
          if(solitare[i][j].writenValue>='0'&&solitare[i][j].writenValue<='9'){
          solitare[i][j].value=solitare[i][j].writenValue-'0';
          }
          if(solitare[i][j].writenValue=='A'){
            solitare[i][j].value=1;
          }
          if(solitare[i][j].writenValue=='T'){
            solitare[i][j].value=10;
          }
          if(solitare[i][j].writenValue=='J'){
            solitare[i][j].value=11;
          }
          if(solitare[i][j].writenValue=='Q'){
            solitare[i][j].value=12;
          }
          if(solitare[i][j].writenValue=='K'){
            solitare[i][j].value=13;
          }
        }
      }
    }
  }
  for(i=n-1;i>=0;i--){
    for(j=1;j<n+1;j++){
      solitare[i][j].maxValue=max(solitare[i][j].value+solitare[i+1][j].maxValue,solitare[i][j].value+solitare[i][j-1].maxValue);
    }
  }
  cout<<solitare[0][n].maxValue;

}
