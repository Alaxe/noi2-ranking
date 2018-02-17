#include<bits/stdc++.h>
using namespace std;
string t[102];
bool used[102][102],bomb;
int m,n,rb,cb,mini;
void backtrack(int r, int c, int br)
{
	if(used[r][c] || r<0 || r>m-1 || c<0 || c>n-1 || (t[r][c]=='#' && bomb)) return ;
	used[r][c]=1;
	if(t[r][c]=='#')
    {
        bomb=true;
        backtrack(r+1,c,br+3);
        backtrack(r-1,c,br+3);
        backtrack(r,c+1,br+3);
        backtrack(r,c-1,br+3);
        bomb=false;
        used[r][c]=0;
        return ;
    }
    else if(t[r][c]=='E')
    {
        if(br<mini) mini=br;
    }
	backtrack(r+1,c,br+1);
	backtrack(r-1,c,br+1);
	backtrack(r,c+1,br+1);
	backtrack(r,c-1,br+1);
	used[r][c]=0;
	return ;
}
int main()
{
	cin >> m >> n;
	for(int i=0; i<m; i++)
    {
        cin >> t[i];
        for(int j=0; j<t[i].size(); j++)
        {
            if(t[i][j]=='B') {rb=i; cb=j;}
        }
    }
    mini=9999999;
    backtrack(rb,cb,0);
    if(mini!=9999999) cout << mini << endl;
    else cout << -1 << endl;
	return 0;
}
/**
6 7
.....B.
.#####.
.#...#.
.#E#.#.
.###.#.
.......

3 3
B##
###
##E

2 3
B##
##E

2 2
B#
#E

4 4
B...
....
.#..
...E
*/
