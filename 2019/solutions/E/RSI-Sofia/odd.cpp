#include<iostream>
using namespace std;
int main (){

long long a,b,i,n=1,brDeliteli=0,brChislaSNechetenBrDeliteli=0;

cin>>a>>b;

for(i=a;i<=b;i++){
    while(n<=i){
        if(i%n==0){
            brDeliteli++;
        }
        n++;
    }
    if(brDeliteli%2==1){
        brChislaSNechetenBrDeliteli++;
    }
    n=1;
    brDeliteli=0;
}

cout<<brChislaSNechetenBrDeliteli;

return 0;
}
