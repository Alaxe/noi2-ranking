///FINAL FAST (i think)
#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
pair < int , int > points[1024];
vector< pair < double , double > > in;
int maxbr;
int n;
pair < double , double > find_f( pair< int , int > x , pair< int , int > y)
{
    pair<double,double>func;
    if(x.first == y.first)
        return make_pair( 0 , 0 );
    func.first = double( x.second-y.second ) / double( x.first-y.first );
    func.second = double( func.first*x.first ) - double( x.second );
    return func;
}
int main()
{
    ios::sync_with_stdio(false);
    maxbr = 1;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> points [i].first >> points [i].second;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j!=i)
            {
                in.push_back( find_f( points[i] , points[j] ) );
            }
        }
        sort( in.begin() , in.end() );
        int br = 1;
        int lin = in.size();
        //cout << in [0].first << " "<< in [0].second << endl;
        for(int k=1; k<lin; k++)
        {
            //cout << in [k].first << " " << in [k].second << endl;
            if(in[k] == in[k-1])
                br++;
            else
            {
                if(br > maxbr)
                    maxbr = br;
                br = 1;
            }
        }
        //cout << "------\n";
        if(br > maxbr)
            maxbr = br;
        in.clear();
    }
    cout << maxbr + 1 << endl;
    return 0;
}
/**
6
0 0
2 1
-2 -1
-2 -2
6 3
-2 3
*/
