#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<string>
using namespace std;

string t;
long long n,m,ans=0;
long long a[1024],countz=0;

void rec(long long numby, long long position, long long br){
    if(br==0){
       if(numby%n==0){ans++;}
        return;
    }

    for(int i=position+1;i<=countz;i++){
            rec((10*numby+a[i]),i,br-1);
    }
}


int main(){
cin>>t;
cin>>n>>m;
    countz=t.size();
    for(int i=0;i<t.size();i++){
        a[i+1]=t[i]-'0';
    }

///     works  a[i] - array with elements  , 1-countz

    for(int i=1;i<=countz;i++){

      rec(0,0,i);
    }
    cout<<ans%m<<endl;

return 0;
}
