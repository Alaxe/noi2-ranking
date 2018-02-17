#include <iostream>
using namespace std;
string masiv[100][100];
int masiv1[100][100];
int main()
{
    int n,br=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>masiv[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
                if(masiv[i][j]=="AS")masiv1[i][j]=1;
                if(masiv[i][j]=="AC")masiv1[i][j]=1;
                if(masiv[i][j]=="AD")masiv1[i][j]=1;
                if(masiv[i][j]=="AH")masiv1[i][j]=1;
                if(masiv[i][j]=="2S")masiv1[i][j]=2;
                if(masiv[i][j]=="2D")masiv1[i][j]=2;
                if(masiv[i][j]=="2H")masiv1[i][j]=2;
                if(masiv[i][j]=="2C")masiv1[i][j]=2;
                if(masiv[i][j]=="3C")masiv1[i][j]=3;
                if(masiv[i][j]=="3S")masiv1[i][j]=3;
                if(masiv[i][j]=="3D")masiv1[i][j]=3;
                if(masiv[i][j]=="3H")masiv1[i][j]=3;
                if(masiv[i][j]=="4C")masiv1[i][j]=4;
                if(masiv[i][j]=="4S")masiv1[i][j]=4;
                if(masiv[i][j]=="4D")masiv1[i][j]=4;
                if(masiv[i][j]=="4H")masiv1[i][j]=4;
                if(masiv[i][j]=="5C")masiv1[i][j]=5;
                if(masiv[i][j]=="5S")masiv1[i][j]=5;
                if(masiv[i][j]=="5D")masiv1[i][j]=5;
                if(masiv[i][j]=="5H")masiv1[i][j]=5;
                if(masiv[i][j]=="6C")masiv1[i][j]=6;
                if(masiv[i][j]=="6S")masiv1[i][j]=6;
                if(masiv[i][j]=="6D")masiv1[i][j]=6;
                if(masiv[i][j]=="6H")masiv1[i][j]=6;
                if(masiv[i][j]=="7C")masiv1[i][j]=7;
                if(masiv[i][j]=="7S")masiv1[i][j]=7;
                if(masiv[i][j]=="7D")masiv1[i][j]=7;
                if(masiv[i][j]=="7H")masiv1[i][j]=7;
                if(masiv[i][j]=="8C")masiv1[i][j]=8;
                if(masiv[i][j]=="8S")masiv1[i][j]=8;
                if(masiv[i][j]=="8D")masiv1[i][j]=8;
                if(masiv[i][j]=="8H")masiv1[i][j]=8;
                if(masiv[i][j]=="9C")masiv1[i][j]=9;
                if(masiv[i][j]=="9S")masiv1[i][j]=9;
                if(masiv[i][j]=="9D")masiv1[i][j]=9;
                if(masiv[i][j]=="9H")masiv1[i][j]=9;
                if(masiv[i][j]=="TC")masiv1[i][j]=10;
                if(masiv[i][j]=="TS")masiv1[i][j]=10;
                if(masiv[i][j]=="TD")masiv1[i][j]=10;
                if(masiv[i][j]=="TH")masiv1[i][j]=10;
                if(masiv[i][j]=="JC")masiv1[i][j]=11;
                if(masiv[i][j]=="JS")masiv1[i][j]=11;
                if(masiv[i][j]=="JD")masiv1[i][j]=11;
                if(masiv[i][j]=="JH")masiv1[i][j]=11;
                if(masiv[i][j]=="QC")masiv1[i][j]=12;
                if(masiv[i][j]=="QS")masiv1[i][j]=12;
                if(masiv[i][j]=="QD")masiv1[i][j]=12;
                if(masiv[i][j]=="QH")masiv1[i][j]=12;
                if(masiv[i][j]=="KC")masiv1[i][j]=13;
                if(masiv[i][j]=="KS")masiv1[i][j]=13;
                if(masiv[i][j]=="KD")masiv1[i][j]=13;
                if(masiv[i][j]=="KH")masiv1[i][j]=13;
        }
    }
    int i=0,g=n-1;
    while(i<=n&&g>0)
    {
        if(masiv1[g-1][i]>masiv1[g][i+1])
        {
            br=br+masiv1[g-1][i];
            g--;
        }
        else
        {
            br=br+masiv1[g][i+1];
            i++;
        }
    }
    cout<<br+masiv1[n-1][0];
    return 0;
}
