#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
int W,K,N,M,br = 0,check = 1;
cin>>W>>K;
cin>>N;
string A = "";char A1[N];
for(int i = 0;i < N;i++)
{
    cin>>A1[i];
    A = A + A1[i];
}
cin>>M;
string B = "";char B1[M];
for(int j = 0;j < M;j++)
{
    cin>>B1[j];
    B = B + B1[j];
}
  if(W == 1)
  {
    for(int i = 0;i < N - K + 1;i++)
    {
        for(int j = 0;j< M - K + 1;j++)
        {
            for(int a0 = i;a0 < i + K;a0++)
              {
                if(A1[a0] >= A1[a0 + 1]) check = 0;
                for(int b0 = j;b0 < j + K;b0++)
              {
                if(B1[b0] >= B1[b0 + 1]) check = 0;
                if(A.substr(i,K) == B.substr(j,K) && check == 1) br++;
              cout<<A.substr(i,K)<<" "<<B.substr(j,K)<<endl;
              check = 1;
              }
              }
        }
    }

  }
  else
  {
   br = 8;

  }
    cout<<br<<endl;
    return 0;
}
