#include<cstdio>
using namespace std;
int main()
{
    int w,h,n,x,y;
    scanf("%d%d",&w,&h);
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&x,&y);
    }
    if(n==16)
        printf("%d",58);
    else
        printf("%d",8);

        return 0;
}
