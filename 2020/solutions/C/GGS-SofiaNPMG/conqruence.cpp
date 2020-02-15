#include<bits/stdc++.h>
using namespace std;

long long br[30];

void otgMalak(string num){
long long x[30],mini=-1;

for(int i=0;i<='Z'-'A';i++){
        x[i]=0;
    for(int j=i-1;j>=0;j--){
        if(br[j]>0){
            x[i]=i-j-1;
            j=-1;
            if(x[i]<0)x[i]=0;
        }
    }
    if(mini==-1 && br[i]>0)mini=i;
}

char znak;
long long we=0;
for(int i=0;i<num.size();i++){
        we=0;
        if(x[num[i]-'A']==0)we=1;
        while(x[num[i]-'A'-we]>0  && num[i]-'A'-we>0){
        num[i]-=x[num[i]-'A'-we];
        we++;
        }
    cout<<char(num[i]-mini);
}
cout<<endl;

}


void otgGolqm(string num){
  long long x[30],maxi=-1;

for(int i='Z'-'A';i>=0;i--){
        x[i]=0;
    for(int j=i+1;j<='Z'-'A';j++){
        if(br[j]>0){
            x[i]=j-i-1;
            j='Z'-'A'+3;
            if(x[i]<0)x[i]=0;
        }
    }
    if(maxi==-1 && br[i]>0)maxi='Z'-'A'-i;
}

char znak;
long long we=0;
for(int i=0;i<num.size();i++){
    we=0;
    if(x[num[i]-'A']==0)we=1;

    while(x[num[i]-'A'+we]>0 && num[i]-'A'+we<'Z'-'A'){
        num[i]+=x[num[i]-'A'+we];
        we++;
    }
    cout<<char(num[i]+maxi);
}
cout<<endl;

}

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

string num;
cin>>num;
for(int i=0;i<num.size();i++)br[num[i]-'A']++;
otgMalak(num);
otgGolqm(num);

return 0;
}

