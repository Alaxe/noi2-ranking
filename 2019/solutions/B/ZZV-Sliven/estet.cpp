#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a [n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    int max=1;
    for (int i=0;i<n-1;i++) {
        int count=2;
        if (a[i]<a[i+1]) {
            for (int j=i+1;j<n-1;j++){
                if (a[j]<a[j+1])
                    count++;
                else if (a[j]>a[j+1]) {
                    count++;
                    for (int k=j+1;k<n-1;k++) {
                        if (a[k]>a[k+1]) count++;
                        else break;
                    }
                    break;
                }
            }
        }
        else if (a[i]>a[i+1]) {
            for (int j=i+1;j<n-1;j++) {
                if (a[j]>a[j+1]) count++;
                else break;
            }
        }
        if (count>max) max=count;
    }
    cout<<max;
}
