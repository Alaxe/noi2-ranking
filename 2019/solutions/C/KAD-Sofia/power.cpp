#include<bits/stdc++.h>
#define N 10005
using namespace std;
int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
vector<int>possible_numbers;
bool used[50],used2[50];
unsigned long long rez=1;
bool check(unsigned long long num,int num2){
    if(num%num2==0) return true;
    else return false;
}
bool check2(unsigned long long num){
    for(int i=0;i<possible_numbers.size();i++){
        if(!check(num,possible_numbers[i])){
            return false;
        }
    }
    return true;
}
unsigned long long calc_power(unsigned long long num,int k){
    if(k==1) return num;
    if(k%2==0){
        int curr=calc_power(num,k/2);
        return curr*curr;
    }else{
        return calc_power(num,k-1)*num;
    }
}
void calc_rez(int num){
    int i=0;
    while(num>1){
        if(num%primes[i]==0){
            num/=primes[i];
            if(!used2[primes[i]]){
                rez*=primes[i];
                used2[primes[i]]=true;
            }
        }else{
            i++;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,left,right,max1=-1,max2=-1;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(!used[a]){
            possible_numbers.push_back(a);
            used[a]=true;
            calc_rez(a);
        }
    }
    bool j=false;
    if(rez%2==0) j=true;
    //cout<<rez<<endl;
    while(true){
        unsigned long long curr_num=calc_power(rez,k);
        if(check2(curr_num)) break;
        rez++;
        if(j) rez++;
    }
    cout<<rez<<endl;
return 0;
}
