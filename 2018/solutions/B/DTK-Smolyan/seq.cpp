#include<iostream>
using namespace std;
int n,m;
#define MaxN 207
int masiv[MaxN],ednPosition,lastMasiv[MaxN];
void initializerMasiv(int begin,int firtsElementValue)
{
    masiv[0]=firtsElementValue;
    int sum=firtsElementValue;
    for(int i=begin;i<n;i++)
    {
        if(sum>=n)break;
        masiv[i]=1;
        sum++;
    }
}

bool sumRavnoN()
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=masiv[i];
    }
    if((sum==n)&&(masiv[0]<=m))return true;
    else return false;
}
bool chekingWhitLastMasiv()
{
    bool flag;
    for(int i=0;i<n;i++)
    {
        if(masiv[i]!=lastMasiv[i])
        {
            flag=false;
            break;
        }
        else flag=true;
    }
    return flag;
}

bool longThanLeft()
{
    bool flag=false;
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(masiv[j]>masiv[i])
            {
                flag=true;
                break;
            }
        }
        if(flag==true)break;
    }

    if(flag==false)flag=chekingWhitLastMasiv();
    return flag;
}

void moveElementsLeft(int begin)
{
    for(int i=begin;i<n-1;i++)
    {
        masiv[i]=masiv[i+1];
    }
}

int main()
{
    cin>>n>>m;
    if(n<m)m=n;
    initializerMasiv(1,1);
    int countSeq=1,myPosition=0;
    ednPosition=n;
    bool flagLongerNumber;
    for(int i=0;i<n;i++)
    {
        lastMasiv[i]=0;
    }
    do
    {
        masiv[myPosition]+=masiv[myPosition+1];
        myPosition++;
        moveElementsLeft(myPosition);
        masiv[n-1]=0;
        ednPosition--;
        flagLongerNumber=true;
        if(sumRavnoN()==true)countSeq++;
        if((longThanLeft()==true)||(myPosition==ednPosition))
        {
            myPosition=1;
            initializerMasiv(myPosition,masiv[0]+1);

            if((chekingWhitLastMasiv()==false)&&(sumRavnoN()==true))countSeq++;
            for(int i=0;i<n;i++)
            {
                lastMasiv[i]=masiv[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            lastMasiv[i]=masiv[i];
        }
    }while(masiv[0]<m);
    cout<<countSeq;

}
