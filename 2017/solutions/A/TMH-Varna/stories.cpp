#include <iostream>

using namespace std;

long long int N,K,First,Mul,Add,Mod;

int powers[30];
int height_tree;
int arr[33554434];
int pyramid[33554434];
long long int Helper;
long long int result;

int power_2_height_tree;

int lefta;

void Initialize_Powers()
{
    powers[0]=1;
    for(int a=1;a<25;a++)
    {
        powers[a]=powers[a-1]*2;
    }

    ///for(int a=0;a<25;a++)
    ///{
    ///    cout<<a<<" = "<<powers[a]<<endl;
    ///}
}

void Get_Height()
{
    int a;
    N--;
    for(a=0;a<25;a++)
    {
        if(N<powers[a])
        {
            height_tree=a;
            break;
        }
    }
    N++;
    ///cout<<height_tree<<endl;
}

void Initialize_Arr()
{
    arr[0]=First;
    for(int a=1;a<N;a++)
    {
        Helper=((long long int)arr[a-1]*Mul+Add)%Mod;
        arr[a]=(int)Helper;
    }

    ///for(int a=0;a<N;a++)
    ///{
    ///    cout<<arr[a]<<" ";
    ///}
}

int power(int a,int b)
{
    int result=a;
    for(int x=1;x<b;x++)
    {
        result*=a;
    }
    return result;
}

int max(int a,int b)
{
    if(a>b) return a;
    return b;
}

void Initialize_Pyramid()
{
    for(int a=0;a<N;a++)
    {
        pyramid[a+power_2_height_tree-1]=arr[a];
    }
    for(int a=power_2_height_tree-2; a>=0;a--)
    {
        pyramid[a]=max(pyramid[a*2+1], pyramid[a*2+2]);
    }

    ///for(int a=0;a<power(2,height_tree+1);a++)
    ///{
    ///    cout<<a<<" = "<<pyramid[a]<<endl;
    ///}
}

int Most(int search_x, int search_y, int real_x, int real_y,int index)
{
    if(search_x<=real_x && search_y>=real_y)
    {
        return pyramid[index];
    }
    int h1=0;
    int h2=0;
    if(search_x<=(real_x+(real_y-real_x)/2)) h1=Most(search_x,search_y,real_x,real_x+(real_y-real_x)/2,index*2+1);
    if(search_y>=(real_x+(real_y-real_x)/2+1)) h2=Most(search_x,search_y,real_x+(real_y-real_x)/2+1,real_y,index*2+2);
    return max(h1,h2);

}

int main()
{
    Initialize_Powers();

    cin>>N>>K;
    cin>>First>>Mul>>Add>>Mod;

    Get_Height();
    Initialize_Arr();

    power_2_height_tree=power(2,height_tree);

    Initialize_Pyramid();

    for(int a=0;a<N;a++)
    {
        lefta=a-K+1;
        if(lefta<0) lefta=0;
        result+=Most(lefta,a,0,power_2_height_tree-1, 0);
        ///cout<<Most(lefta,a,0,power(2,height_tree)-1, 0)<<endl;
    }

    cout<<result<<endl;

    return 0;
}
