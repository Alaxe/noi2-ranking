
#include <iostream>

using namespace std;

int main()
{
    int n,W1,W2;
    int a[n];
    int j,i;
    cin>>n,W1,W2;
    for (int i=1; i<=n; i++)
    cin>> a[i];

    if (W1<W2) swap(W1,W2);

    for (int i=1; i<=n; i++)
    for(int j=i+1; j<=n; j++)

    if (a[i]<a[j])

    swap(a[i],a[j]);
    int start_W1=0,start_W2=0;
    int end_W1=W1,end_W2=W2;

    for (int i=1; i<=n; i++)
    {
   if (a[i]<=end_W1-start_W1+a[i])
    {
    start_W1=start_W1+a[i];
    end_W1=end_W1-a[i];
    }

    else

    if(a[i]<=end_W2-start_W2)
    {
        start_W2=start_W2+a[i];
        end_W2=end_W2-a[i];
    }

    }

    cout<<start_W1<<" "<<start_W2<<endl;
    cout<<end_W1<<" "<<end_W2;


    return 0;
}
