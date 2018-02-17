#include<iostream>
#include<cmath>
using namespace std;
int main(){
bool nam=false;
long  long n,k,chislo,stg;
cin>>n>>k;
stg=0;
for(long long br=0;br<n;br++){
    stg=stg+pow(10,br)*9;
}

for(chislo=pow(10,n-1);nam==false && chislo<=stg;chislo++){
            if(chislo%k==0){
                        cout<<chislo;
                        nam=true;
            }
}
if(chislo>stg){
   cout<<"NO";
}


return 0;
}
