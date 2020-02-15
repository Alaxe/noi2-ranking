#include<cstring>
#include<iostream>
using namespace std;
char niz[5001];
int arr[26];
int main()
{
    cin >> niz;
    int len = strlen(niz), podred = 0, br = 0;
    for(int i = 0; i < len-2; i++)
    {
        if(niz[i] == niz[i+1] && niz[i] == niz[i+2])
        {
            if(niz[i] != 'a'+(podred%26)) niz[i+2] = char('a'+(podred%26));
            else
            {
                podred++;
                niz[i+2] = 'a'+(podred%26);
            }
            podred++;
        }
        arr[niz[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(arr[i] > len/2)
        {
            for(int j = 0; br < arr[i]-len/2; j++)
            {
                if(niz[j] - 'a' == i)
                {
                    niz[j] = niz[j]+(podred%26);
                    br++;
                    podred++;
                }
            }
        }
    }
    cout << niz << endl;
    return 0;
}
