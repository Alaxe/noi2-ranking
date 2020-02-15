#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int b[n];
    for(int i = 1; i <= n; i++)
    {
        b[i] = i;
    }
    for(int i = 0; i < n; i++)
    {
      int br=0;
      for(int z = i+1; z < n; z++)
      {
          if(b[z] > b[i])
          {
              br++;
          }
      }
      int k = i+1;
      int br1;
        do
        {
            br1=0;
            swap(b[i], b[k]);
            for(int j = i+1; j < n; j++)
            {
                if(b[i] == b[j])
                {
                    br1++;
                }
            }
            if(br1 != a[i])
            {
                swap(b[i], b[k]);
            }
        k++;
        }
        while(br1 != a[i]);
    }
    cout<<b[0];
    return 0;
}
