#include <iostream>
using namespace std;
int main (){
long long n,k,kolkoEGoliamo,proverca,koiEDelitelia;
bool imaLiDeitel=false;
kolkoEGoliamo=1;
cin>>n>>k;
while(n>0){
    kolkoEGoliamo=kolkoEGoliamo*10;
    n=n-1;
}

for(proverca=kolkoEGoliamo/10;proverca<kolkoEGoliamo;proverca=proverca+1){
    if(proverca%k==0 && proverca!=k){
        imaLiDeitel=true;
        koiEDelitelia=proverca;
        proverca=kolkoEGoliamo;
    }
}
if(imaLiDeitel==true){
    cout<<koiEDelitelia<<"\n";
}else{
cout<<"NO\n";
}
return 0;
}
