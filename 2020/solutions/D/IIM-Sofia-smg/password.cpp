#include<iostream>
#include<cstring>
using namespace std;
char arr[5000];
int main (){
cin>>arr;
int n=strlen(arr);
int tekbrednakvi=0;
int brnasimbol=0;
///o.k cout<<n<<endl;
for(long long i=0;i<n;i++){
    for(long long i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            tekbrednakvi++;
        }
        cout<<tekbrednakvi<<endl;
    }
    tekbrednakvi=0;
}
return 0;
}
