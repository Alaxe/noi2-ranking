#include<iostream>
using namespace std;

long long n,m,br,num,i;

int main(){
    cin>>m>>n;
    i=1;
    num=i*i+i;
    if(m==1 || m==2)br++;
    do{
        i++;
        num=i*i+i;
        if(num>=m && num<=n)br++;
    }while(num<=n);
    cout<<br<<endl;
    return 0;
}
