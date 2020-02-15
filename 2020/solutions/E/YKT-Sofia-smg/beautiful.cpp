#include <iostream>
using namespace std;
int main(){
int brStr;
cin>>brStr;
int naiMnStr=0,x;
if(brStr>9){
    naiMnStr=9;
    for(int i=10;i<=brStr;i++){
            x=i;
        while(x>0){
            if(x%10==x%100/10){
                naiMnStr++;
            }
            x/=10;
        }
    }
}else{
    naiMnStr=brStr;
}
cout<<naiMnStr<<endl;
return 0;
}
