#include <iostream>

using namespace std;

int main()
{
    int N,K;
    cin>>N;
    cin>>K;
    if (K==1)
    {
        cout<<"1"<<endl;

    }
    if (K==2)
    {
        cout<<N-1<<endl;

    }
    if (K>2&&K<N)
    {
        cout<<"2"<<endl;
    }
    if (K==N)
    {
        cout<<"1"<<endl;
    }

    return 0;
}
