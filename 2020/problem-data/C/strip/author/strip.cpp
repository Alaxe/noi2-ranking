//Task: strip
//Author: Kinka Kirilova-Lupanova

#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long> > f; 
int n, k; 
long long sol(int left, int filled) 
{ if (left + filled > n) return 0; 
  if (filled == 1) 
  if (left == k - 1) return  1;
  else return 0; 
  if (f[left][filled] < 0) 
     f[left][filled] = sol(left+1, filled-1)+sol(left, filled-1); 
  return f[left][filled]; 
} 
int main()
{cin >> n >> k; 
 f.resize(n + 1, vector<long long>(n + 1, - 1)); 
 cout << sol(0, n)<<endl; 
}
