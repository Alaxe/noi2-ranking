#include<iostream>
using namespace std;
int m,n;
int map[10000][20000];

int findFirstWay(int path[]){
	for(int i = 0; i < m; i++){
		if(path[i] == 1) return i;
	}
}


bool findAnswer(int f){
	int first = findFirstWay(map[f]);
	int sec = findFirstWay(map[first]);
	map[f][first] = 0;
	map[first][f] = 0;
	int ans1 = findFirstWay(map[f]);
	int ans2 = findFirstWay(map[sec]);

	if((map[first][ans1] == map[sec][ans1]) || (map[first][ans2] == map[sec][ans2])) {
			map[f][first] = 1;
			map[first][f] = 1;
			return true;
	}
	map[f][first] = 1;
	map[first][f] = 1;
	return false;
}

int main()
{
	int answer = 0;
	cin>>n>>m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			map[i][j] = 0;
		}
	}
	
	for(int i = 0; i < m; i++){
		pair<int, int> coordinates;
		cin>>coordinates.first;
		cin>>coordinates.second;
		map[coordinates.first - 1][coordinates.second - 1] = 1;
		map[coordinates.second - 1][coordinates.first - 1] = 1;
	}

	
	for(int i = 0; i < n; i++){
		if(findAnswer(i)) answer++;
		if(answer %2 == 0) answer++;
	}
	
	cout<<answer;
	
}
