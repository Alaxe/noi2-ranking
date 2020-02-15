#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int br, br2, br3, br4, br5;
int N, U,U1;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

cin>>N>>U;
int masiv2[N];
int masiv[N];
if (U%2==1) U1=(U/2)-1;
else U1=U/2;
for (int i = 0; i<N; i++){
    cin>>masiv2[i];
}

if(N == 4){
   for (int i = 0; i<U1; i++){
    for (int j = i+1; j<U1; j++){
        br=i;
        br2=j;}}
        cout<<br<<" "<<br2<< " "<<br2<<" "<<br<<endl;
   }
   else if( N==5){
   for (int i = 0; i<U1-1; i++){
   for (int m = i+1; m<U1; m++){
    for (int j = m+1; j<U1; j++){
        br=i;
        br2=m;
        br3 = j;}}}
        cout<<br<<" "<<br2<< " "<<br3<<" "<<br2<<" "<<br<<endl;
   }
    else if(N==6){
   for (int i = 0; i<U1-1; i++){
   for (int m = i+1; m<U1; m++){
    for (int j = m+1; j<U1; j++){
        br=i;
        br2=m;
        br3 = j;}}}
        cout<<br<<" "<<br2<< " "<<br3<<" "<< br3<<" "<<br2<<" "<<br<<endl;
   }
return 0;}

