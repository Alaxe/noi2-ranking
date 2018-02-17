#include<iostream>
using namespace std;
long long otgovori[1000][1000];
long long obshto[1000];
int chisla[1000];
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
int n=0,d=0;
long long h=123456789012345,result=0;
cin>>n;
for(int i=0;i<n;i++){
    cin>>chisla[i];
    if(i>0){
        for(int j=i-1;j>=0;j--){
            if(chisla[i]>chisla[j]){
                d=chisla[i]-chisla[j];
                if(otgovori[j][d]==0){
                    otgovori[i][d]++;
                    obshto[i]++;
                    obshto[i]=obshto[i]%h;
                }else{
                otgovori[i][d]=otgovori[j][d]+1;
                otgovori[i][d]=otgovori[i][d]%h;
                obshto[i]+=otgovori[i][d];
                obshto[i]=obshto[i]%h;
                }
            }
        }
    }
}

for(int i=0;i<n;i++){
    result=result+obshto[i];

    result=result%h;
}
cout<<result<<"\n";
return 0;
}
