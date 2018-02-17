#include <iostream>
#include <vector>
#define my_int unsigned long long int
using namespace std;
my_int b,m1,m2,m3,m4;
my_int vec[10001];
my_int answer,formula;
my_int rot(my_int n)
{
    my_int k,c=1,m=n,j=1,result[10001];
    while(m!=0)
    {
        k=n/c%10;
        c=c*10;
        m=m/10;
        vec[j]=k;
        j++;
    }
    j--;c=c/10;my_int jj=1;
    result[0]=0;
    for(my_int i=j-1;i>=1;i--)
    {
        result[jj]=result[jj-1]+vec[i]*c;
        c=c/10;jj++;
    }
    return result[j-1]+vec[j];
}
my_int search_(my_int M)
{
    answer=0;
      if(b==10)
        {
            for(my_int i=10;i<=1000000;i++)
            {
                formula=rot(i)-i;
                if(formula==M)
                {
                    answer=i;
                    i=1000000;
                }
            }
        }
    return answer;
}
int main()
{
    cin>>b;
    cin>>m1>>m2>>m3>>m4;
    cout<<search_(m1)<<endl;
    cout<<search_(m2)<<endl;
    cout<<search_(m3)<<endl;
    cout<<search_(m4)<<endl;


    return 0;
}
/*
10
216
1318
2349
44444
*/
