#include<iostream>
using namespace std;
#define maxPoints 1001
struct point{
    short x;
    short y;
};

struct functionOfPoint{
    float a;
    float b;
};

point points[maxPoints];
functionOfPoint functionOfPoints[maxPoints][maxPoints];
int coutnAAndB[maxPoints*10][maxPoints*10];
int maxCount=0,lastCount=0;
void setAAndBFunction(int firstIndex,int secondIndex, float a,float b)
{
     functionOfPoints[firstIndex][secondIndex].a=a;
     functionOfPoints[firstIndex][secondIndex].b=b;
     a=a*10;
     b=b*10;
     coutnAAndB[int(a)][int(b)]+=1;
     lastCount=coutnAAndB[int(a)][int(b)];
}
void cinPoint(int index)
{
    cin>>points[index].x>>points[index].y;
}

void initializerFunctionPoints(int x,int y)
{
    functionOfPoints[maxPoints][maxPoints].a=0;
    functionOfPoints[maxPoints][maxPoints].b=0;
}
void searchFunction(int firstIndex, int secondIndex)
{
    int firstPointX,firstPointY,secondPointX,secondPointY;
    firstPointX=points[firstIndex].x;
    firstPointY=points[firstIndex].y;
    secondPointX=points[secondIndex].x;
    secondPointY=points[secondIndex].y;
    float a,b;
    for(a=0;a<=maxPoints/2;a+=0.1)
    {
        for(b=0;b<=maxPoints/2;b+=0.1)
        {
            if((firstPointX*a+b==firstPointY)&&(secondPointX*a+b==secondPointY))
            {
                setAAndBFunction(firstIndex,secondIndex, a, b);
                break;
            }
            else if((firstPointX*(-a)+b==firstPointY)&&(secondPointX*(-a)+b==secondPointY))
            {
                setAAndBFunction(firstIndex,secondIndex, (-a), b);
                break;
            }
            else if((firstPointX*a-b==firstPointY)&&(secondPointX*a-b==secondPointY))
            {
                setAAndBFunction(firstIndex,secondIndex, a,(-b));
                break;
            }
            else if((firstPointX*(-a)-b==firstPointY)&&(secondPointX*(-a)-b==secondPointY))
            {
                setAAndBFunction(firstIndex,secondIndex, (-a), (-b));
                break;
            }
        }
    }

    if(maxCount<=lastCount)maxCount=lastCount;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cinPoint(i);
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            initializerFunctionPoints(i,j);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            searchFunction(i,j);
        }
    }
    int count=1,sum=0;
    do
    {
        sum+=count;
        count++;
    }while(sum<maxCount);
    cout<<count;
}
