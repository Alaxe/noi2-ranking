#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int otg[t];
    for(int p=0;p<t;p++)
    {
        int n;
        cin>>n;
        int mas[n],mas2[n];
        for(int i=0;i<n;i++)
        {
            cin>>mas[i];
            mas2[i]=i;
        }
        int minch;
        for(int i=0;i<n-1;i++)
        {
            minch=i;
            minch=mas[i];
            for(int j=i+1;j<n;j++)
            {
                if(minch>mas[j])
                {
                    minch=j;
                    minch=mas[j];
                }
            }
            swap(mas[minch],mas[i]);
            swap(mas2[minch],mas2[i]);
        }
        int max=0,summax;
        for(int i=0;i<n;i++)
        {
            summax=1;
            for(int j=i+1;j<n;j++)
            {
                if(mas[i]==mas[j])summax++;
                if(mas2[i]==mas2[j])summax++;
            }
            if(max<summax)max=summax;
        }
        if(max+1>n)max--;
        otg[p]=max+1;
    }
    for(int i=0;i<t;i++)
    {
        cout<<otg[i]<<endl;
    }
}
/*
2
4
4 1 2 3
5
4 1 2 3 4
*/
