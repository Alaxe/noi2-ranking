#include <iostream>
#include <set>
using namespace std;

int main(){

int n;
cin>>n;
int arr[n];

for(int i=0; i<n; i++){
    cin>>arr[i];
}
int ans=0;
for(int d=1; d<=3; d++){
   multiset <int> nums;
   int otg = 0;
    for(int i=0; i<n; i++){
        //cout<<arr[i]<<" "<<d<<" ";
        int anss = arr[i]-d;
        //cout<<anss<<endl;
        //ans+=nums.count(anss);
        otg = nums.count(anss);
        ans+=otg;
        //cout<<ans<<endl;
        nums.insert(arr[i]);
    }
    //cout<<"d: "<<d<<" "<<otg<<endl;

}
cout<<ans<<endl;
return 0;

}
