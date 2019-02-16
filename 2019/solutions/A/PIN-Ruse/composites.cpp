#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

long long n, x, k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin>>n;

  x = n;
  while(true) {
    if(x%6==2) {
      k = x / 6;
      break;
    }

    ++x;
  }

  while(k%5!=4) ++k;
  
  cout<<6ll*k + 2<<endl;

  return 0;
}
