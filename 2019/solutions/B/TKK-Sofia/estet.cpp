#include<iostream>
#include<algorithm>
using namespace std;

const int Max_N=100000;
int current_array [Max_N];
int currentarray [Max_N];

int recursion_up(int ar [],int siz){
if(siz==2){
if(ar[0]<ar[1]){
return 0;
}
return 1;
}
int second_counter=0;
int third_counter=0;
for(int counter=0;counter<siz-1;counter++){
currentarray[counter]=ar [counter];
if(ar [siz-1]>ar[counter]){
current_array[second_counter]=ar[counter];
second_counter++;
}else{
third_counter++;
}
}
return min(recursion_up(current_array,siz-1-third_counter)+third_counter,recursion_up(currentarray,siz-1)+1);
}

int spisyk [Max_N];
int n,adding,current,result=100001;

int main(){
ios_base::sync_with_stdio(false);
cin>>n;
for(int counter=0;counter<n;counter++){
cin>>adding;
spisyk[counter]=adding;
}
for(int coun=0;coun<n;coun++){
int current_price;
if(coun==0 or coun==n-1){
current_price=recursion_up(spisyk,n);
}else{
for(int f=0;f<=coun;f++){
current_array[f]=spisyk[f];
}
for(int j=coun;j<n;j++){
currentarray[j-coun]=spisyk[j];
}
current_price=recursion_up(current_array,coun)+recursion_up(currentarray,n-coun);
}
if(current_price<result){
result=current_price;
}
}
cout<<n-result;
return 0;
}
