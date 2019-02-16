#include <iostream>
using namespace std;
int main(){
	
	bool m[100][100] = {0};
	int n, x, y, d;
	int xMax = 0, yMax = 0;
	int t;
	int startingX[100];
	int scores[100];
	int beatlePosition[2][100];
	bool floor = false;
	int findPath(int beatleX, int beatleY, bool matrix[100][100], int yMax, int xMax);
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>x;
		cin>>y;
		cin>>d;
		for(int j = 0; j < d; j++){
			m[y][x] = true;
			x++;	
		}
		
		if(x + d > xMax){
			xMax = x + d;
		}
		
		if(y > yMax){
			yMax = y + 1;
		}
	}
	
	cin>>t;
	
	for(int i = 0; i < t; i++){
		cin>>startingX[i];	
	}

for(int i = 0; i < t; i++){
	cout<<findPath(startingX[i], yMax,m, yMax, xMax)<<endl ;

}
}

int findPath(int beatleX, int beatleY, bool m[100][100], int yMax, int xMax){
	bool floor = false;
	int i = 0, br = 0;
	int puti = 0;
	
	int score[100] = {0};
	int finalScore = 0;
	int posiTions[100][2] = {0};
	bool nadqsno[100] = {0};
	bool alreadyHit[100] = {0};
	
	posiTions[0][0] = beatleY;
	posiTions[0][1] = beatleX;
	
	do
	{
		floor = false;
		while(!floor){
			
			if(m[posiTions[i][0]][posiTions[i][1]] && !alreadyHit[i]){
				br++;
				posiTions[br][0] = posiTions[i][0];
				posiTions[br][1] = posiTions[i][1];
				nadqsno[br] = true;
				nadqsno[i] = false;
				alreadyHit[i] = true;
				alreadyHit[br] = true;
				score[br] = score[i];
				score[i]++;
				score[br]++;
			}
			if(m[posiTions[i][0]][posiTions[i][1]] && alreadyHit[i]){
				if(!nadqsno[i]){
					posiTions[i][1]--;
				}
				if(nadqsno[i]){
					posiTions[i][1]++;
				}
			}
			if(!m[posiTions[i][0]][posiTions[i][1]]){
				posiTions[i][0]--;
				alreadyHit[i] = false;
			}
			if(posiTions[i][0] == 0){
			floor = true;
			puti++;
			}
			
		}
		i++;	
	} while(br > puti - 1) ;



	finalScore = score[0];
	for(int j = 0; j <= br; j++){
		if(score[j] < finalScore){
			finalScore = score[j];
		}
	}
	return finalScore;
}

