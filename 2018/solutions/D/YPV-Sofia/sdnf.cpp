#include<iostream>
#include<string>
using namespace std;
string mul(long long a,string b){
    int answer[10000];
    for(int i=0;i<10000;i++){
        answer[i]=0;
    }
    string num1,num2;
    for(int i=b.size()-1;i>=0;i--) num2+=b[i];
    while(a){
        num1+=(a%10)+'0';
        a/=10;
    }
    for(int i=0;i<num1.size();i++){
        for(int j=0;j<num2.size();j++){
            answer[i+j]+=(num1[i]-'0')*(num2[j]-'0');
        }
    }
    string otgowor;
    int prenos=0;
    for(int i=0;i<num1.size()+num2.size();i++){
        otgowor+='0'+((answer[i]+prenos)%10);
        prenos=(answer[i]+prenos)/10;
    }
    if(prenos) otgowor+=prenos+'0';
    string otgowor1;
    for(int i=otgowor.size();i>=0;i--){
        if(otgowor[i]>='0' and otgowor[i]<='9')
            otgowor1+=otgowor[i];
    }
    return otgowor1;
}
int main(){
    int num;
    cin>>num;
    string result="1";
    for(int i=1;i<=num;i++){
        result=mul(i,result);
    }
    int sum=0;
    for(int i=0;i<result.size();i++){
        sum+=result[i]-'0';
    }
    cout<<sum<<endl;
return 0;
}
