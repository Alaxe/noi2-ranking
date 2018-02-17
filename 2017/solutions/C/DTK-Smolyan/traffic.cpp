#include<iostream>
using namespace std;
int n,m,id,jd;
short mas[640][640];
void intit(int i)
{
    cin>>n>>m;
    char ch;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ch;
            if(ch=='#')
            {
                mas[i][j]=0;
                id=i;
                jd=j;
            }
            else if(ch=='*')mas[i][j]=-1;
            else mas[i][j]=ch-'A';
        }
        cin.get(ch);
    }
}
int main()
{
    intit(0);
    int sum=0,i,minsum=0;
    bool flag=1,flagns=1,flag2;
    i=id;
    char s;
    do
    {
        for(int j=jd;j<m;j++)
        {
            if ((i==0)||(i==n)||(j==0)||(j==m))
            {
                flag=0;
                break;
            }
            if(mas[i][j+1]!=-1)
            {
                sum+=mas[i][j];
                mas[i][j]=0;
            }
            else
            {
                if(mas[i-1][j]!=-1)i--;
                else
                {
                    if(mas[i][j-1]!=-1)j--;
                    for(j;j>0;j--)
                    {
                        if ((i==0)||(i==n)||(j==0)||(j==m))
                        {
                            flag=0;
                            break;
                        }
                        if(mas[i][j-1]!=-1)
                        {
                            sum+=mas[i][j];
                            mas[i][j]=0;
                        }
                        else
                        {
                            if(mas[i-1][j]!=-1)i--;
                            else
                            {

                            }
                        }
                    }
                    if(flag==0)break;
                }
            }
        }
        if(flagns=0)break;
    }while(flag==0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<mas[i][j]<<" ";
        }
        cout<<endl;
    }
    if(flag==0)minsum=sum;
    cout<<sum;

}
/*
8 12
NY****AZ**A*
*SH*D**CHMW*
*CJ**G**LZO*
*JMS****NGG*
*JKPKN#YORC*
************
KJWWGDPLQMXL
TGLAKBQCRQSD
*/
