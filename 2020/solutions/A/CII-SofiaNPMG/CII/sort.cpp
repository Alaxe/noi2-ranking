#include<iostream>
using namespace std;
int a[100000];
int r[100000];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(i>0)
            r[i]=a[i]-a[i-1];
    }
    for(int i=1; i<n; i++)
    {
        if(r[i]<0)
        {
            cout<<(0-r[i])<<endl;
            return 0;
        }
    }
}
/**
TWO THOUSAND MEN AND FIFTY THOUSAND TONS OF STEEL
SET THE COURSE FOR THE ATLANTIC WITH THE ALLIES ON THEIR HEELS
SIGN OF POWER
SHOW OF FORCE
RAISE THE ANCHOR
BATTLESHIP'S PLOTTING ITS COURSE
PRIDE OF A NATION
A BEAST MADE OF STEEL
BISMARCK IN MOTION
KING OF THE OCEAN
HE WAS MADE TO RULE THE WAVES ACROSS THE SEVEN SEAS
TO LEAD THE WAR MACHINE
TO RULE THE WAVES AND LEAD THE KRIEGSMARINE
THE TERROR OF THE SEAS
THE BISMARCK AND THE KRIEGSMARINE
*/
