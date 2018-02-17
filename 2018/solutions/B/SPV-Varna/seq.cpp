#include<bits/stdc++.h>
#include<queue>
#define endl '\n'

using namespace std;

int br=0;
int arr[273];
/*
int rec(int num){

    if(num<=1) return 0;
    br++;
    return rec(num-1)+rec(num-1);
}
*/

int rec(int num, int maxN){

    if(num<=1) return 0;

    for(int i=maxN; i>0; i--){
        int sum = num;

        while(sum>0){
            if(sum<i){
                if(arr[sum]){
                    br = br + arr[sum];
                }else{
                    rec(sum, maxN);
                }
                sum = 0;
            }else{
                if(arr[i]){
                    br = br + arr[i];
                }else{
                    rec(i, maxN);
                }
                sum = sum - i;
            }

        }
    }
}

int main(){

arr[1] = 1;
arr[2] = 2;
arr[3] = 3;

int n, m;
cin>>n>>m;

rec(n, m);
cout<<br/m<<endl;
}
