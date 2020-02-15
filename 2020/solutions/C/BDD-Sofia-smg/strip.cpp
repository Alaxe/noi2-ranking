#include<iostream>
using namespace std;
long long kombinacii(long long elementi, long long clas){
    long long pr1=1,pr2=1;
    for(clas;clas>0;clas--){
        if(clas>0 && elementi>0){
            pr1=pr1*clas;
            pr2=pr2*elementi;
            elementi--;
        }
    }
return pr2/pr1;
}
int main (){
    long long n,k;
    cin>>n>>k;
    if(k>n/2){
        k=n-k+1;
    }
    cout<<kombinacii(n-1,k-1);
return 0;
}
