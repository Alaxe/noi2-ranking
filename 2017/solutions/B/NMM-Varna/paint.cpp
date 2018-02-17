#include <iostream>
#define maxn 11000
using namespace std;
struct rectangle
{
    int x,y;
    int width, height;
    int surface;
    int coloredSurface;
    int containsSize;
    int contains[maxn];

} r[maxn];

int isInside(rectangle a, rectangle b){

    if(a.x <b.x && a.y < b.y && a.x + a.width > b.x && a.y + a.height > b.y){
        return 1;
        /// b is inside a
    }
    else if(a.x > b.x && a.y > b.y && b.x + b.width > a.x && b.y + b.height > a.y){
        return -1;
        /// a is inside b
    }

    return 0;
    /// apparently nothing :)
}
void calculateColoredSurface(int n){

        if(r[n].containsSize == 0){
                r[n].coloredSurface = r[n].surface;
        }
        else for(int i = 0; i < r[i].containsSize; i++){
                if(r[r[n].contains[i]].containsSize == 0){
                    r[n].coloredSurface -= r[r[n].contains[i]].surface;
                }
                else{

                calculateColoredSurface(r[n].contains[i]);
                r[n].coloredSurface -= r[r[n].contains[i]].coloredSurface;
                }
        cout<<n<<" "<<r[n].contains[i]<<" "<<r[n].coloredSurface<<endl;
        }
}

int main()
{
    cin>>r[0].width>>r[0].height;
    r[0].containsSize = 0;
    r[0].surface = r[0].width * r[0].height;
    r[0].coloredSurface = r[0].surface;
    r[0].x = 0;
    r[0].y = 0;
    r[0].containsSize = 0;
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>r[i].x>>r[i].y;
        cin>>r[i].width>>r[i].height;
        r[i].surface = r[i].width * r[i].height;
        r[i].coloredSurface = r[i].surface;
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            switch(isInside(r[i], r[j])){
            case 1:
                r[i].contains[r[i].containsSize] = j;
                r[i].containsSize ++;
                //r[i].coloredSurface -= r[j].surface;
                break;
            case -1:
                r[j].contains[r[j].containsSize] = i;
                r[j].containsSize ++;
                //r[j].coloredSurface -= r[i].surface;
                break;
            case 0:
                break;
            }
        }
    }
    calculateColoredSurface(0);

    for(int i = 0; i <= n; i++)
    {
        cout<<r[i].coloredSurface<<" "<<r[i].containsSize<<endl;
    }
    return 0;

}

/*
11 7
3
2 1 5 5
8 2 2 3
3 2 3 2

*/
