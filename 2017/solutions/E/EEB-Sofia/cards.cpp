#include <iostream>
using namespace std;
int main(){
long long N;
cin>>N;
long long a[N+1], b[N+1], i, broi=0, broiS=0;
for(i=0; i<N; i++){
    cin>>a[i];
    cin>>b[i];
    if(a[i]<b[i]){
        swap(a[i], b[i]);
    }
}
a[N]=0;
b[N]=0;
for(i=0; i<N; i++){
    if(a[i]>=a[i+1] && b[i]>=b[i+1]){
        broi++;
    }else{
        if(N-i<=broi){
            cout<<broi+1<<endl;
            return 0;
        }else{
            if(broi>=broiS){
                broiS=broi;
            }
            broi=0;
        }
    }
}
if(broi>=broiS){
cout<<broi<<endl;
}else{
cout<<broiS<<endl;
}
return 0;
}
