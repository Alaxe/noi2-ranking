#include<iostream>
using namespace std;
int main(){
long long n,sbor_dc=0,sbor_ab=0;
char niz[1000001];
cin>>n>>niz;
for(long long g=n-1;g>=0;g--){
    if(niz[g]=='a'||niz[g]=='b'){
        sbor_ab++;
    }
    if(niz[g]=='c'||niz[g]=='d'){
        sbor_dc++;
    }
}
while(sbor_ab!=sbor_dc){

        if(niz[n-1]=='a'||niz[n-1]=='b'){
            sbor_ab--;
        }
        if(niz[n-1]=='d'||niz[n-1]=='c'){
            sbor_dc--;
        }
        n--;

}
cout<<n<<endl;
return 0;
}
