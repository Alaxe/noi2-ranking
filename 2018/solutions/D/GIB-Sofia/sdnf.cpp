#include<iostream>
#include<cmath>
#include<numeric>
#include<cstring>
using namespace std;

long factorial (long a){
    if (a > 1){
        return (a * factorial (a-1));
    }else{
        return (1);
    }
}

int main(){
int n;
cin>>n;
string result=factorial(n);
cout<<accumulate(result.begin(),result.end(),0);
return 0;
}
