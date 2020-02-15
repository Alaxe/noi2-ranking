#include<iostream>
#include<stack>
using namespace std;
int u,v,n,ans,higtest;
stack<int>hights;
stack<int>uBetween;
int main(){
ios_base::sync_with_stdio(NULL);
cin.tie(NULL);
cout.tie(NULL);
cin>>n>>u>>v;
for(int i=0;i<n;i++){
    int input;
    cin>>input;
    int ucount=0;
    if(input<=higtest){
        while(input>hights.top()){
            hights.pop();
            ucount+=uBetween.top();
            uBetween.pop();

        }
    }else higtest=input;
    hights.push(input);
    uBetween.push(ucount+1);
}
while(hights.size()>1) {
    int now=hights.top();
    hights.pop();
    ans+=uBetween.top()*u*v*min(now,hights.top());
    uBetween.pop();
}
cout<<ans;
return 0;
}

