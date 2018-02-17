#include<iostream>
using namespace std;

string s;
int p[160001];
int k=1;

void next()
{
  int c=0;
  for(int i=0;i<k;i++)
  {
    int v=2*p[i];
    p[i] = (v+c)%10;
    c=(v+c)/10;
  }
  if(c>0){p[k]=c;k++;}
}

int main()
{
  cin >> s;
  int L=s.size();
  p[0]=2;
  int i=1;
  while(1)
  {
    L = L-k;
    if(L==0) {cout << i << endl; return 0;}
    next();
    i++;
  }
}
