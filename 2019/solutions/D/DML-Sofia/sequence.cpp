#include<iostream>
using namespace std;
long long kolko(int red,int n){

    int sum=0,poweche=0;
for(int i=1;i<red+1;i++){
        poweche=2*i-1;
    sum=sum+poweche;

}

return sum;
}
int main(){
long long  n,k,red,sum;
cin>>n>>k;
if(k==1 && n==1){
    cout<<1;
}else{
red=k-1;
if(red>1){
        if(red%2==0){
red=red/2;
        }else{
        red=red/2+1;
        }

}else{
red=1;
}
red=red+n;

if((k-1)%2==0){
    sum=kolko(red,n);
    sum=sum-(n-1);
}else{
sum=kolko(red-1,n);


sum=sum+n;
}
cout<<sum;
}
cout<<endl;
return 0;
}
