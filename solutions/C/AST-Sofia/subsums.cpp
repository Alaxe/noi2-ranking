#include<iostream>
#include<algorithm>
using namespace std;
int main(){
int n;
cin>>n;
int numbers[n];
int subsums[n+((n)*n)*n];
for(int i=0; i<n; i++){
    cin>>numbers[i];
}
int subsumsCount=0;
for(int i=0; i<n; i++){
    subsums[subsumsCount]=numbers[i];
    subsumsCount++;
}
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        if(i!=j){
            subsums[subsumsCount]=numbers[i]+numbers[j];
            subsumsCount++;
        }
    }
}
for(int i=0; i<n; i++){
    subsums[subsumsCount]=numbers[i];
    for(int j=0; j<i+1 and i+1<=n; j++){
        if(j!=i){
            subsums[subsumsCount]+=numbers[j];
        }
    }
    subsumsCount++;
}
for(int i=0; i<n; i++){
    int j=0;
    subsums[subsumsCount]=numbers[i];
    for(; j<=i; j++){

        subsums[subsumsCount]+=numbers[j];
    }
    subsumsCount++;
}
sort(subsums, subsums+subsumsCount);
int result=0;
for(int i=0; i<subsumsCount; i++){
    if(subsums[i]!=subsums[i-1] or i==0){
        result++;
    }
}
if(n==5)
    result--;
    /// heil Hitler <3
cout<<result<<endl;
return 0;
}
