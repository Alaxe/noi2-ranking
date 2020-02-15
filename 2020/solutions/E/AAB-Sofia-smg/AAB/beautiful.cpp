#include<iostream>
using namespace std;
int main(){
int N,tr,br=0;
cin>>N;
for(int i=1;i<=N;i++){
        tr=0;
if(i<10){
    br++;
}
    for(int z=1;z<i;z++){
       if(i%10==i/10%10){
        tr++;
        if(tr==i-1){

            br++;
        }
       }

    }
}



cout<<br;

return 0;
}
