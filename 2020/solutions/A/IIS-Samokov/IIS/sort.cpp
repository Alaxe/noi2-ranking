#include <iostream>

using namespace std;

int main()
{
    int n,i,j,br=0,sum=0;
    cout<<"Vavedi broy na chislata ot masiva n: ";
    cin>>n;
    int arr[n];
    for(i=0; i<n; i++)
    {
        cout<<"Vavedi chislo nomer "<<i<<" ot masiva: ";
        cin>>arr[i];
        sum=sum+arr[i];
    }
    for(i=0;i<n;i++)
    {
        if (arr[i+1]>arr[i] && arr[i+2]<arr[i+1])
        {
            while (arr[i]<arr[i+1])
            {
                arr[i+1]=arr[i+1]-1;
                br++;
            }
        }
        if (arr[i+1]<arr[i] && arr[i+2]<arr[i+1])
        {
            while (arr[i]>arr[i+1])
            {
                arr[i+1]=arr[i+1]+1;
                br++;
            }
        }
        if (arr[i+1]<arr[i] && arr[i+2]>arr[i+1])
        {
            while (arr[i]>arr[i+1])
            {
                arr[i+1]=arr[i+1]+1;
                br++;
            }
        }
    }
    cout<<"Broy na operaciite: "<<br;
    return 0;
}
