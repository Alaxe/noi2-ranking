#include <iostream>
#define maxheight 450000000
using namespace std;
int paint[maxheight];
int main()
{
    int width, height;
    cin>>width>>height;
    int n;
    cin>>n;
    int x,y,prevX, prevY;
    cin>>prevX>>prevY;
    int depth = prevX;
    for(int i = 1; i < n; i++)
    {
        cin>>x>>y;
        if(prevX == x)
        {
            if(prevY<y)
            {

                for(int i = prevY; i < y; i++)
                {
                    if(paint[i]<depth)
                    {
                        paint[i] = depth;
                    }
                    //cout<<"paint "<<i << " is "<< paint[i]<<endl;
                }
            }
            else
            {

                for(int i = prevY-1; i >= y; i--)
                {
                    if(paint[i]<depth)
                    {
                        paint[i] = depth;
                    }
                    //cout<<"paint "<<i << " is "<< paint[i]<<endl;
                }
            }
        }
        else
        {
            depth = x;
            //cout<<"depth is "<<depth<<endl;
        }
        prevX = x;
        prevY = y;

    }
    unsigned long long result = 0;
    for(int i = 0 ; i < height; i++)
    {
        //cout<<paint[i]<<" ";
        result += (width - paint[i]);
    }
    cout<<result<<endl;
    return 0;

}
