#include<iostream>
#include<vector>
using namespace std;
int n, w1, w2, a, val, val2, val3;
vector<int> b;
//int solve(int s1, int s2, vector<int> nums){
//    int maxVal=0, lastIndex=-1;
//    for(int i=0;i<nums.size();i++){
//        if(nums[i]>200)continue;
//        val=nums[i];
//        nums[i]=201;
//        val2=val3=-1;
//        if(nums[i]<=s1){
//            val2 = solve(s1 - val, s2, nums);
//            maxVal+=val;
//        }
//        if(nums[i]<=s2){
//            val3 = solve(s1, s2 - val, nums);
//            maxVal+=val;
//        }
//        if(val2==-1 && val3==-1)return maxVal;
//        nums[i]=val;
//        if(val3>maxVal){
//            maxVal=val3;
//            lastIndex=i;
//        }
//        if(val2>maxVal){
//            maxVal=val2;
//            lastIndex=i;
//        }
//    }
//    if(lastIndex>-1)nums[lastIndex]=201;
//}

int minLeft(int w, vector<int> nums){
    int lastIndex=-1, minVal=w;
    for(int i=0;i<n;i++){
        if(nums[i]<=w){
            val=nums[i];
            nums[i]=201;
            val2=minLeft(w-val, nums);
            if(val2<minVal){
                minVal=val2;
                lastIndex=i;
            }
            nums[i]=val;
        }
    }
    if(lastIndex>-1){
        b[lastIndex]=201;
    }
    return minVal;
}
int main(){
    cin>>n>>w1>>w2;
    for(int i=0;i<n;i++){
        cin>>a;
        b.push_back(a);
    }
    cout<<w1-minLeft(w1, b)+w2-minLeft(w2, b);
    return 0;
}
