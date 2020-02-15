#include<iostream>
 using namespace std;
 int main(){
 long long n,sum=0,l,d;
 cin>>n;
if(n<=9){
    for(int c=1;c<=n;c++){
        sum++;
    }
}
else{
sum=9;
for(int i=10;i<=n;i++){
    for(int d=1;d>0;d*=10){
        for(int m=10;m>0;m*=10){
            if(i/(d)%10==i/(m)%10){
                sum++;
            }
            m=0;
        }
        d=0;
    }
}
}

 cout<<sum;
}
