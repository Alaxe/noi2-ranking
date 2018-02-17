#include <iostream>
using namespace std;
int main() {
long long m,k,nums[99999],sum=0,on=1,backup;
cin >>m>>k;
while(1) {
if(sum > k) {
    break;
}
cin >>nums[on];
if(nums[on] % 2 == 0) {
    sum += nums[on];
}
if(nums[on] == m-1 || nums[on] == m+1 || nums[on] == m) {
backup = on;
}
on++;
}
cout <<nums[backup]<<" "<<sum<<endl;
return 0;
}
