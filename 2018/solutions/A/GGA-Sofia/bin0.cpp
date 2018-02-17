#include<iostream>
using namespace std;
int pascalTriangleRow(int row,int index)
{
    if(index > row)
    {
        return 0;
    }
    row=row+2;
    int triangle[row][row];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<row;j++)
        {
            triangle[i][j] = 0;
        }
    }

    for(int i=0;i<row;i++)
    {
        triangle[i][0] = 1;
    }

    int x=0;
    for(int i=0;i<row;i++)
    {
        triangle[i+1][i] = 1;
        x++;
    }

    for(int i=1;i<row;i++)
    {
        for(int j=1;j<i;j++)
        {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    cout<<"";
    /*   for(int i=0;i<row;i++)
    {
        for(int j=0;j<i;j++)
        {
            //cout<<triangle[i][j]<<" ";
        }
        cout<<"";
    }
    */
    return triangle[row-1][(index+1)%(row-1)];
}
bool isAPowerOfTwo(int number)
{
    while(number)
    {
        if(number==1)
        {
            return 1;
        }
        if(number%2==0)
        {
            number/=2;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
int numberOfZeroesInBinary(unsigned long long number)
{
    int counter=0;
    while(number)
    {
        if(number%2==0)
        {
            number/=2;
            counter++;
        }
        if(number%2==1)
        {
            number/=2;
        }
    }
    return counter;
}
int main()
{
    unsigned long long s,t,z;
    cin>>s>>t>>z;
    int copyOfS = s;
    //s = 8; t=23; z=2;
    if(isAPowerOfTwo(s)&&isAPowerOfTwo(t))
    {
        int tcounter = 0;
        while(t)
        {
            t/=2;
            tcounter++;
        }
        int scounter = 0;
        while(s)
        {
            s/=2;
            scounter++;
        }
        //cout<<counter;
        if(numberOfZeroesInBinary(copyOfS)==z)
        {
            cout<<pascalTriangleRow(tcounter-1, z) - pascalTriangleRow(scounter-1, z)+1;
        }
        else
        {
            cout<<pascalTriangleRow(tcounter-1, z) - pascalTriangleRow(scounter-1, z);
        }
    }
    else
    {
    int counter = 0;
    for(int i=t;i>=s;i--)
    {
        if(numberOfZeroesInBinary(i)==z)
        {
            counter++;
        }
    }
    cout<<counter;
    }
}

