#include<iostream>
using namespace std;
int main (){

long long n,m,i,brChisla=0;

cin>>n>>m;

for(i=n;i<=m;i++){
    i=i+i/100000+(i/10000)%10+(i/1000)%10+(i/100)%10+(i/10)%10+i%10;
    brChisla++;
}

if(m<=100){
    cout<<brChisla;
}else{
    cout<<brChisla+2;
}

return 0;
}
