#include <iostream>

using namespace std;

int main()
{
    const int o = 100000;
    int n, array[o],counter=0,i,num,c=0,j;
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>array[i];
    }
    for (i = 0;i<n;i++)
    {
        if (i = n-1)
        {
            if (array[i]<num)
            {
                while(array[i]<num)
                {
                    array[i]=array[i] +1;
                    counter++;
                }
            }
            if (array[i]>num)
            {
                while(array[i]>num)
                {
                    array[i]=array[i] -1;
                    counter++;
                }
            }
        }
        else
        {
        if (array[i] > array[i+1])
        {
            if(c = 0)
            {
                num = array[i+1];
                while(array[i]>num)
                {
                    array[i] = array[i] -1;
                    counter++;
                }
                c++;
            }
            else
            {
                if(array[i]<num)
                {
                    while(array[i]<num)
                    {
                    array[i] = array[i]+1;
                    counter++;
                    }
                }
                if(array[i]>num)
                {
                    while(array[i]>num)
                    {
                    array[i] = array[i]-1;
                    counter++;
                    }
                }

            }
        }
        }
    }
    cout<<counter;
}
