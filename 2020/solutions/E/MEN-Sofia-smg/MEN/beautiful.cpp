#include<iostream>
using namespace std;

int brc(int a){

int b=a,c=0;
while(b>0){
    c++;
    b/=10;
}
return c;
}

int main(){

unsigned long long a,br=0,r=1;
cin>>a;

for(int i=1;i<=a;){
    for(int j=1;j<brc(i);j++){
        r*=10;
        r+=1;
    }
    i+=r;
    br++;
}
cout<<br<<endl;

return 0;
}
