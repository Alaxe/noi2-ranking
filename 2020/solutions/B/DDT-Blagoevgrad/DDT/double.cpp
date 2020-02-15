#include<iostream>
#include<vector>

using namespace std;
vector<int> numbers;
int maxf=0, W1, W2;

void fillb(int n, int A, int B, vector<bool> &nums)
{
   maxf=max(maxf, A+B);
   for(int i=0; i<n; i++)
    {
       if(!nums[i])
        {
           nums[i]=true;
           if(A+numbers[i]<=W1)
            fillb(n, A+numbers[i], B, nums);
           if(B+numbers[i]<=W2)
            fillb(n, A, B+numbers[i], nums);
           fillb(n, A, B, nums);
           nums[i]=false;
        }
    }
}


int main()
{
   int n;
   cin >> n >> W1 >> W2;

   vector<bool> nums;
   for(int i=0; i<n; i++)
    {
       int a;
       cin >> a;
       numbers.push_back(a);
       nums.push_back(false);
    }
    fillb(n, 0, 0, nums);

   cout << maxf;

   return 0;
}
