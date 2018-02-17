#include <iostream>
using namespace std;

int main(){

long long int k, nk=1, d=0;
int n;
cin>>n>>k;
for (int i=1; i<n; i++){
    
    nk *= 10;
    
}
//cout<<nk<<endl;

if (nk%k == 0){

cout<<nk<<endl;
return 0;

}

if (k%2 == 0){

    while (d==0){
    
        if (nk%k == 0) d=nk;
        else nk -= 2;
    
    }

}
else while (d==0){

        if (nk%k == 0) d=nk;
        else nk--;

    }

cout<<d+k<<endl;

return 0;
}