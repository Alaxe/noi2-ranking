#include<iostream>
using namespace std;
int main()
{
    int M,K,a,sum,raz1,raz2,num1,num,num2;
    cin>>M>>K;
    sum = 0;
    cin>>a;
    if(K>=a){
    raz1 = K-a;}
    if(a>=K){
    raz1 = a-K;}
    num = 1;
    num1 = 1;
    if((a>K)&&(a%2 == 0)){cout<<"1 "<<a<<endl;};
    do
    {
    cin>>a;
    num = num++;
     if(a%2==0){sum = sum+a;};
     if(K>=a){raz2 = K-a;};
     if(a>=K){raz2 = a-K ;};
     if(raz2<=raz1){raz1 = raz2; num1 = num;};
    }
    while(sum<K);
    num2 = num1+1;
    cout<<num2<<" "<<sum<<endl;
    return 0;
}
