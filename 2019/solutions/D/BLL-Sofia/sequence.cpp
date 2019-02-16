#include<iostream>
using namespace std;
int main(){
long long n,k,i,i1,broisreshtaniqNa=0,el=2,vajenEl;
cin>>n>>k;
if(n==1){
    broisreshtaniqNa++;
}
for(i=2;broisreshtaniqNa<k;i++){
    for(i1=1;i1!=i;i1++){
        if(n==i1){
            broisreshtaniqNa++;
        }
        if(broisreshtaniqNa==k and n==i1){
            vajenEl=el;
        }
        el++;
    }
    for( ;i1>0;i1--){
        if(n==i1){
            broisreshtaniqNa++;
        }
        if(broisreshtaniqNa==k and n==i1){
            vajenEl=el;
        }
        el++;
    }
}
if(n==1 and k==1){
    cout<<1<<endl;
}else{
    cout<<vajenEl<<endl;
}
return 0;
}
