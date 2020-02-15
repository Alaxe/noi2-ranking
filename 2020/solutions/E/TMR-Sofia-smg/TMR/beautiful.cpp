#include <iostream>
#include <string>
using namespace std;

int main(){

int i,br,n,old,neww;
br=0;
old=0;
neww=0;
cin >> n;
for (i=0;i<n;i++){
        if (i==1){
            br++;
        }
        else if (i==2){
            br++;
        }
        else if (i==3){
            br++;
        }
        else if (i==4){
            br++;
        }
        else if (i==5){
            br++;
        }
        else if (i==6){
            br++;
        }
        else if (i==7){
            br++;
        }
        else if (i==8){
            br++;
        }
        else if (i==9){
            br++;
        }
        old=i%10;
        i=i/10;
        neww=i%10;
        i=i/10;
        if (old==neww){
            br++;
        }
        old=0;
        neww=0;
}
}
