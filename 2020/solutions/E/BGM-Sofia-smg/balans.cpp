#include<iostream>
#include<cstring>
using namespace std;
int main () {
long long n,broi,i,broiab=0,broicd=0;
cin>>n;
char redica[1000000];
cin>>redica;
broi=strlen(redica);
for(i=0;i<=broi;i++){
    if(redica[i]=='a' || redica[i]=='b'){
        broiab++;
    }
    if(redica[i]=='c' || redica[i]=='d'){
        broicd++;
    }
}
if(broiab==0 || broiab==1 || broicd==0 || broicd==1){
    cout<<0;
}else{
   if(broiab>=broicd){
    cout<<broicd*2;
   }
   else{
    cout<<broiab*2;
   }
}
return 0;
}
