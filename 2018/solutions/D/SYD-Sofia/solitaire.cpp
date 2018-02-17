#include<iostream>
using namespace std;
int n,answer=0;
char table[100][100],a;
int read(char a)
{
    if(a=='A')
    {
        return 1;
    }
    else if (a=='2')
    {
        return 2;
    }
    else if( a=='3')
    {
        return 3;
    }
    else if( a=='4')
    {
        return 4;
    }
    else if( a=='5')
    {
        return 5;
    }
    else if( a=='6')
    {
        return 6;
    }
    else if( a=='7')
    {
        return 7;
    }
    else if( a=='8')
    {
        return 8;
    }
    else if( a=='9')
    {
        return 9;
    }
    else if (a=='T')
    {
        return 10;
    }
    else if (a=='J')
    {
        return 11;
    }
    else if (a=='Q')
    {
        return 12;
    }
    else
    {
        return 13;
    }
}
void solitare(int curr1, int curr2, int currsum)
{

    if(curr1==0 and curr2 == n-1)
    {
        if (currsum>answer)
        {
            answer = currsum;
            return;
        }
        return;
    }
    else
    {
        if(curr1>0)
        {

            solitare(curr1-1 , curr2 , currsum+read(table[curr1-1][curr2]));
        }
        if(curr2<n-1)
        {

            solitare(curr1 , curr2+1 , currsum+read(table[curr1][curr2+1]));
        }
        return;
    }


}
int main()
{


    cin>>n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            cin>>table[i][j];
            cin>>a;
        }

    solitare(n-1 , 0, read(table[n-1][0]));
    cout<<answer;
    return 0;
}
/*
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D


*/
