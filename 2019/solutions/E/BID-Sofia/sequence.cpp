#include<iostream>
using namespace std;
int main(){
    long long n,red,mqsto,krainomqsto=1,sbor=1;
    cin>>n;
    if(n==1)cout<<"1\n";
    else{
        red=n;
        mqsto=red;
        while(red-1>1){
            krainomqsto=krainomqsto+2;
            sbor=krainomqsto+sbor;
            red--;
        }
        cout<<sbor+mqsto<<endl;
    }
    return 0;
}
