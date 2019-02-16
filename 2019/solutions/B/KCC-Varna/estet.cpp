#include<bits/stdc++.h>
using namespace std;
int h[100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,maxi1=1,maxi2=1,maxi3=1;
    cin >> n;
    cin >> h[0];
    int br=1;
    for(int i=1; i<n; i++)
    {
        cin >> h[i];
        if(h[i]>h[i-1]) br++;
        else
        {
            if(br>maxi1) maxi1=br;
            br=1;
        }
    }
    if(br>maxi1) maxi1=br;
    br=1;

    for(int i=1; i<n; i++)
    {
        if(h[i]<h[i-1]) br++;
        else
        {
            if(br>maxi2) maxi2=br;
        }
    }
    if(br>maxi2) maxi1=br;
    br=1;

    bool flag=false;
    if(h[1]>h[0]) {br++; flag=true;}
    for(int i=2; i<n; i++)
    {
        if(h[i]>h[i-1])
        {
            if(flag) br++;
            else
            {
                if(br>maxi3) maxi3=br;
                br=2;
                flag=true;
            }
        }
        else if(h[i]<h[i-1])
        {
            flag=false;
            br++;
        }
    }
    if(br>maxi3) maxi3=br;
    cout << max(maxi1,max(maxi2,maxi3)) << endl;
    return 0;
}
/**
Input:
4
2 1 5 3
Output:
3

Input:
3
1 5 5
Output:
2
*/
