#include<iostream>
using namespace std;

const int max_len=10002;
const int n_max=1002;

string str;
int n;
long long int m;

long long int T[max_len][n_max];

int main()
{
    cin >> str;
    cin >> n;
    cin >> m;
    int L = str.length();

    T[0][(str[0]-'0')%n] = (T[0][(str[0]-'0')%n] + 1)%m;

    for (int i=1; i<L; i++)
    {
      T[i][(str[i]-'0')%n] = (T[i][(str[i]-'0')%n] + 1)%m;
      for (int j=0; j<n; j++)
      {
       T[i][j] = (T[i][j]+T[i-1][j])%m;
       T[i][(j*10 + (str[i]-'0'))%n] =  (T[i][(j*10 + (str[i]-'0'))%n] + T[i-1][j])%m;
      }
    }
    cout <<  T[L-1][0]%m << endl;
}
