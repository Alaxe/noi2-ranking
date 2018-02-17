#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;

int n, m;

int a[100][100];///0 - . 1 - #, 2 - B, 3 - E
char c;
string line;

struct tn
{
	int j;
	int i;
};
tn s;
tn f;

int dist[100][100];
vector <tn> q;
bool used[100][100];


void input();
void bfs();

int main()
{
	input();
	bfs();
	cout << dist[f.i][f.j] << endl;
	/*for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}*/
	return 0;
}

///input()
void input()
{
	cin >> n >> m;
	for(int i = 0;i < n; ++i)
	{
		cin >> line;
		for(int j = 0;j < m; ++j)
		{
			c = line[j];
			switch(c)
			{
				case '.':
					a[i][j] = 0;
					break;
				case '#':
					a[i][j] = 1;
					break;
				case 'B':
					a[i][j] = 2;
					s.j = j;
					s.i = i;
					break;
				case 'E':
					a[i][j] = 3;
					f.j = j;
					f.i = i;
					break;
			}
		}
	}
}

///bfs()
void bfs()
{
	q.push_back(s);

	for(int i = 0;i < n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			if(a[i][j] == 0 || a[i][j] == 2 || a[i][j] == 3)
				dist[i][j] = numeric_limits<int>::max();
		}
	}

	dist[s.i][s.j] = 0;
	used[s.i][s.j] = 1;

	while(!q.empty())
	{
		///Determine the closest vertex
		int pos;
		int mn = numeric_limits<int>::max();
		tn curr;
		for(int i = 0;i < q.size(); ++i)
		{
			if( dist[q[i].i][q[i].j] < mn )
			{
				mn = dist[q[i].i][q[i].j];
				pos = i;
				curr.i = q[i].i;
				curr.j = q[i].j;
			}
		}
		q.erase(q.begin() + pos);

		///down
		if(curr.i != n - 1)
		{
			if(a[curr.i + 1][curr.j] != 1/* # */ && used[curr.i + 1][curr.j] == 0)
			{
				if(dist[curr.i + 1][curr.j] > dist[curr.i][curr.j] + 1)
				{
					tn push;
					push.i = curr.i + 1;
					push.j = curr.j;
					dist[curr.i + 1][curr.j] = dist[curr.i][curr.j] + 1;
					used[curr.i + 1][curr.j] = 1;
					q.push_back(push);
				}
			}
		}

		///up
		if(curr.i != 0)
		{
			if(a[curr.i - 1][curr.j] != 1/* # */ && used[curr.i - 1][curr.j] == 0)
			{
				if(dist[curr.i - 1][curr.j] > dist[curr.i][curr.j] + 1)
				{
					tn push;
					push.i = curr.i - 1;
					push.j = curr.j;
					dist[curr.i - 1][curr.j] = dist[curr.i][curr.j] + 1;
					used[curr.i - 1][curr.j] = 1;
					q.push_back(push);
				}
			}
		}


		///left
		if(curr.j != 0)
		{
			if(a[curr.i][curr.j - 1] != 1/* # */ && used[curr.i][curr.j - 1] == 0)
			{
				if(dist[curr.i][curr.j - 1] > dist[curr.i][curr.j] + 1)
				{
					tn push;
					push.i = curr.i;
					push.j = curr.j - 1;
					dist[curr.i][curr.j - 1] = dist[curr.i][curr.j] + 1;
					used[curr.i][curr.j - 1] = 1;
					q.push_back(push);
				}
			}
		}

		///right
		if(curr.j != m - 1)
		{
			/*if(a[curr.i][curr.j + 1] != 1&& used[curr.i][curr.j +1] == 0)
				cout << 1 << endl;
			else
				cout << 0 << endl;*/
			//cout << curr.i << " " << curr.j <<  " " << dist[curr.i][curr.j] <<  " " << dist[curr.i][curr.j + 1] << " " << used[curr.i][curr.j + 1] << endl;
			if(a[curr.i][curr.j + 1] != 1/* # */ && used[curr.i][curr.j + 1] == 0)
			{
				//cout << curr.i << " " << curr.j <<  " " << dist[curr.i][curr.j] <<  " " << dist[curr.i][curr.j + 1] <<endl;
				if(dist[curr.i][curr.j + 1] > dist[curr.i][curr.j] + 1)
				{
					tn push;
					push.i = curr.i;
					push.j = curr.j + 1;
					dist[curr.i][curr.j + 1] = dist[curr.i][curr.j] + 1;
					used[curr.i][curr.j + 1] = 1;
					q.push_back(push);
				}
				//cout << curr.i << " " << curr.j <<  " " << dist[curr.i][curr.j] <<  " " << dist[curr.i][curr.j + 1] <<endl;
			}
		}
	}
}
