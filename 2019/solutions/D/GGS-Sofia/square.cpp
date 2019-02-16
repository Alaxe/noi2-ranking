#include <bits/stdc++.h>
using namespace std;

long long br[45];

bool razlagane(long long num){
int i,inBr[45]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

for(int i=2;i*i<=num;i++){
    while(num%i==0){
        num=num/i;
        inBr[i]++;
    }
}

if(num==i){
    inBr[i]++;
}else{
    inBr[num]++;
}

for(int i=2;i<=43;i++){
    if(inBr[i]>br[i]){
        br[i]=inBr[i];
    }
}

}

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

long long n,nums,ans=1;
cin>>n;

for(int i=0;i<n;i++){
    cin>>nums;
    if(nums>1){
    razlagane(nums);
    }
}

for(int i=2;i<=43;i++){
    if(br[i]%2==1){
        br[i]++;
    }

    for(int j=0;j<(br[i]/2);j++){
        ans=ans*i;
    }

}
cout<<ans<<endl;

return 0;
}
