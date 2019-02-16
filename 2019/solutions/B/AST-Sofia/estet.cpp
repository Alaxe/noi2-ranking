#include <iostream>
using namespace std;

int cut_ascending(int index_end, const int trees[]);
int cut_descending(int index_start, const int trees[], int N);

int main()
{
    int N;
    cin>>N;
    int trees[N], dead_if_1=0, dead_if_2=0;
    int dead_if_3=-1;
    int option3_results[N][2]= {0};
    int cut_off_1_index[N]= {0};
    int start_point_1_index[N]= {0};
    int cut_off_2_index[N]= {0};
    int start_point_2_index[N]= {0};
    /// INPUT
    for(long i=0; i<N; i++)
    {
        cin>>trees[i];
        if(i)
        {

            if(trees[i]<=trees[i-1])
            {
                dead_if_1++;
            }
            if(trees[i]>=trees[i-1])
            {
                dead_if_2++;
            }

        }
        cut_off_1_index[i]=dead_if_1;
        cut_off_2_index[i]=dead_if_2;

    }
    /// OPTION 3
    for(int i=0; i<N; i++)
    {

        int dead_if_3_case=cut_off_1_index[i]+(dead_if_2-cut_off_2_index[i]);
        //cout<<cut_off_1_index[i]<<' '<<dead_if_2-cut_off_2_index[i]<<'\n';
        if(dead_if_3_case<dead_if_3 || dead_if_3==-1)
        {
            dead_if_3=dead_if_3_case;
            //cout<<"Number "<<i+1<<" lowest: "<<cut_off_1_index[i]<<' '<<dead_if_2-cut_off_2_index[i]<<'\n';
        }
    }
    /// OPTION 3
    /// RESULT CHECK
    if(dead_if_1<dead_if_2)
    {
        if(dead_if_1<dead_if_3)
        {
            cout<<N-dead_if_1;
        }
        else
            cout<<N-dead_if_3;
    }
    else if(dead_if_2<dead_if_3)
    {
        cout<<N-dead_if_2;
    }
    else
        cout<<N-dead_if_3;
    cout<<'\n';
    /// RESULT CHECK
    return 0;
}

int cut_ascending(int index_end, const int trees[])
{
    int dead=0;
    for(long i=0; i<index_end; i++)
    {
        if(i)
            if(trees[i]<=trees[i-1])
                dead++;

    }
    return dead;
}

int cut_descending(int index_start, const int trees[], int N)
{
    int dead=0;
    for(long i=index_start; i<N; i++)
    {
        if(i)
            if(trees[i]>=trees[i-1])
                dead++;
    }
    return dead;
}
/**
11
2 4 10 6 8 10 8 5 6 4 2

10
20 15 10 5 7 9 6 16 14 20

*/

/**
___________________________________________________________________ GEN_1
#include <iostream>
using namespace std;
int main(){
int N;
cin>>N;
int trees[N], dead_if_1=0, dead_if_2=0;
int dead_if_3=0;
for(long i=0; i<N; i++){
    cin>>trees[i];
    if(i)
    {
        if(trees[i]<=trees[i-1]) dead_if_1++;
        if(trees[i]>=trees[i-1]) dead_if_2++;
    }
}
if(dead_if_1<=dead_if_2) cout<<N-dead_if_1; else cout<<N-dead_if_2;
cout<<'\n';
return 0;
}
____________________________________________________________________ GEN_1

____________________________________________________________________ GEN_2
#include <iostream>
using namespace std;

int cut_ascending(int index_end, const int trees[]);
int cut_descending(int index_start, const int trees[], int N);

int main()
{
    int N;
    cin>>N;
    int trees[N], dead_if_1=0, dead_if_2=0;
    int dead_if_3=-1;
    int option3_results[N][2]= {0};
    for(long i=0; i<N; i++)
    {
        cin>>trees[i];
        if(i)
        {
            if(trees[i]<=trees[i-1])
            {
                dead_if_1++;

            }
            if(trees[i]>=trees[i-1])
                dead_if_2++;
        }
    }

    if(dead_if_1==0 || dead_if_2==0)
    {
        if(dead_if_1<=dead_if_2)
            cout<<N-dead_if_1;
        else
            cout<<N-dead_if_2;
        return 0;
    }
    for(int i=0; i<N; i++)
    {
        int dead_if_3_case=cut_ascending(i, trees)+cut_descending(i, trees, N);
        if(dead_if_3>dead_if_3_case || dead_if_3==-1)
        {
            dead_if_3=dead_if_3_case;
        }
    }
    if(dead_if_1<dead_if_2)
    {
        if(dead_if_1<dead_if_3)
        {
            cout<<N-dead_if_1;
        }
        else
            cout<<N-dead_if_3;
    }
    else if(dead_if_2<dead_if_3)
    {
        cout<<N-dead_if_2;
    }
    else
        cout<<N-dead_if_3;
    cout<<'\n';
    return 0;
}

int cut_ascending(int index_end, const int trees[])
{
    int dead=0;
    for(long i=0; i<index_end; i++)
    {
        if(i)
            if(trees[i]<=trees[i-1])
                dead++;

    }
    return dead;
}

int cut_descending(int index_start, const int trees[], int N)
{
    int dead=0;
    for(long i=index_start; i<N; i++)
    {
        if(i)
            if(trees[i]>=trees[i-1])
                dead++;
    }
    return dead;
______________________________________________________________ GEN_2

______________________________ OLD VERSION OF OPTION 3 ALGORITHM
   /// OPTION 3
    for(int i=0; i<N; i++)
    {
        int dead_if_3_case=cut_ascending(i, trees)+cut_descending(i, trees, N);
        if(dead_if_3>dead_if_3_case || dead_if_3==-1)
        {
            dead_if_3=dead_if_3_case;
        }
}
______________________________ OLD VERSION OF OPTION 3 ALGORITHM
// OPTION 3




    */

