#include<iostream>
#include<string>
using namespace std;
string a;

bool bal(int ka){

int br=0,bra=0;
for(int i=0;i<=ka;i++){
    if(a[i]=='a'||a[i]=='b'){
        br++;
    }else if(a[i]=='c'||a[i]=='d') bra++;
}
if(bra==br) return true;
else return false;
}


int main(){

int b,t=0,be=0;
cin>>b;
cin>>a;
for(int i=0;i<b;i++){
        if(bal(i)) t=i+1; else t=0;
        if(be<t) be=t;
}
cout<<be<<endl;

return 0;
}

