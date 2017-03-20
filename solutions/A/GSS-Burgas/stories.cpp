#include<iostream>
#include<vector>
using namespace std;

vector<long long>q;
long long n,k,first,mul,add,mod,sum,index,fun;

int main(){
    cin>>n>>k;
    cin>>first>>mul>>add>>mod;
    q.resize(n+1);
    q[0]=first;
    for(long long i=1;i<n;i++){
        q[i]=(q[i-1]*mul+add)%mod;
    }
    sum=q[0];
    fun=q[0];
    for(long long i=1;i<n;i++){
        if(q[i]>fun && index+k>=i){
                sum+=q[i];
                fun=q[i];
                index=i;
        }
        else{
            if(index+k<=i){
                fun=q[i];
                index=i;
                for(long long j=i-1;j>i-k;j--){
                    if(fun<q[j]){
                        fun=q[j];
                        index=j;
                    }
                }
            }
        sum+=q[index];
        }
    }
    cout<<sum<<endl;
    return  0;
}
