#include<iostream>
using namespace std;
long long n,redica[1024],memo[1024][1024],kolko=0;
bool dali[1024][1024],minati[1024][1024];
long long dinami4no(long long ot,long long d){
    if(dali[ot][d]==1){
        return memo[ot][d];
    }
    dali[ot][d]=1;
for(long long i=ot+1;i<n;i++){
if(redica[i]-d==redica[ot]){
    memo[ot][d]+=(dinami4no(i,d)+1)%123456789012345;
}
}
//cout<<ot<<" "<<d<<" : "<<memo[ot][d]<<"\n";
return memo[ot][d];
}
int main(){
cin.tie(NULL);
ios::sync_with_stdio(false);
cin>>n;
for(long long i=0;i<n;i++){
    cin>>redica[i];
}
for(long long i=0;i<n;i++){
    for(long long r=i+1;r<n;r++){
        if((redica[r]-redica[i])>0 and minati[i][redica[r]-redica[i]]==0){
                minati[i][redica[r]-redica[i]]=1;
            kolko+=dinami4no(i,redica[r]-redica[i]);
            kolko=kolko%123456789012345;
            //cout<<"\n"<<" "<<i<<" "<<r<<" "<<kolko<<"\n";
        }
    }
}
cout<<kolko;
return 0;
}
