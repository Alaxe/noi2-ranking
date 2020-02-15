#include <bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n, W1, W2,b;
int sum;
sum=0;
cin>>n>>W1>>W2;
if (W1<W2){
    int l = W1;
    W1=W2;
    W2=l;
}
int masiv[n-1];
for(int i = 0; i<n; i++){
    cin>>masiv[i];
}
for (int j = 0; j<n; j++){
    for (int k = 0; k<n-j; k++){
        int s = masiv[j];
        masiv[j]=masiv[k];
        masiv[k]=s;
    }
}
while (W1>masiv[n-1]){
        for(int i = 0; i<n; i++){
        if((W1-masiv[i])>=0){
        sum=sum+masiv[i];
        W1-=masiv[i];
        masiv[i]=0;}

        }

}
while (W2>masiv[n-1]){
for(int i = 0; i<n; i++){
        if((W2-masiv[i])>=0){
        sum=sum+masiv[i];
        W2-=masiv[i];
        masiv[i]=0;}

        }


}
cout<<sum;
return 0;}
