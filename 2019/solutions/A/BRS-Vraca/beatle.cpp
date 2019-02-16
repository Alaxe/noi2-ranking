#include <iostream>
using namespace std;
int main(){
	
	bool matrix[100][100] = {0};
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
		//cout<<"x"<<i<<"=";
		cin>>x;
		//cout<<"y"<<i<<"=";
		cin>>y;
		//cout<<"d"<<i<<"=";
		cin>>d;
		for(int j = 0; j < d; j++){
			matrix[y][x] = true;
			x++;	
		}
		
		if(x + d > xMax){
			xMax = x + d;
		}
		
		if(y > yMax){
			yMax = y + 1;
		}
	}
	/*
	for(int i = yMax; i >= 0; i--){
		for(int j = 0; j < xMax; j++){
			if(matrix[i][j]){
				cout<<"_";
			}
			if(!matrix[i][j]){
				cout<<".";
			}
		}
		cout<<endl;
	}
	*/
	//cout<<"T"<<endl;
	cin>>t;
	
	for(int i = 0; i < t; i++){
		cin>>startingX[i];	
	}
	
	
	
	//cout<<"rezili"<<endl;
	for(int i = 0; i < t; i++){
		//scores[i] = findPath(startingX[i], yMax, matrix, yMax, xMax);
		cout<<findPath(startingX[i], yMax, matrix, yMax, xMax)<<" "<<endl;	
		//cout<<"round"<<endl;
	}
	
	
	
	//for(int j = 0; j < d; j++)
}


int findPath(int beatleX, int beatleY, bool matrix[100][100], int yMax, int xMax){
	bool floor = false;
	
	int i = 0;
	
	int br = 0;
	int timesFloorHits = 0;
	
	int score[100] = {0};
	int finalScore = 0;
	int positions[100][2] = {0};
	bool goesRight[100] = {0};
	bool collided[100] = {0};
	
	positions[0][0] = beatleY;
	positions[0][1] = beatleX;
	
	
	while(br > timesFloorHits - 1){
		floor = false;
		while(!floor){
			
			/*for(int z = yMax; z >= 0; z--){
				for(int j = 0; j <= xMax; j++){
					//cout<<"kur"<<endl;
					
					if(positions[i][0] == z && positions[i][1] == j){
						cout<<"a";
					}else{
						if(matrix[z][j]){
						cout<<"_";
						}
						if(!matrix[z][j]){
							cout<<".";
						}
					}
				}
				cout<<endl;
			}
			cout<<endl;
			*/
			
			if(matrix[positions[i][0]][positions[i][1]] && !collided[i]){
				br++;
				positions[br][0] = positions[i][0];
				positions[br][1] = positions[i][1];
				goesRight[br] = true;
				goesRight[i] = false;
				collided[i] = true;
				collided[br] = true;
				score[br] = score[i];
				score[i]++;
				score[br]++;
			}
			if(matrix[positions[i][0]][positions[i][1]] && collided[i]){
				if(!goesRight[i]){
					positions[i][1]--;
				}
				if(goesRight[i]){
					positions[i][1]++;
				}
			}
			if(!matrix[positions[i][0]][positions[i][1]]){
				positions[i][0]--;
				collided[i] = false;
			}
			if(positions[i][0] == 0){
			floor = true;
			timesFloorHits++;	
			}
			/*if(positions[i][0] < 0){
			cout<<"br"<<br<<endl;
			cout<<"TimesFloor"<<timesFloorHits<<endl;
			break;
			}
			cout<<score[i]<<endl;
			*/
		}
		i++;	
	}
	finalScore = score[0];
	for(int j = 0; j <= br; j++){
		if(score[j] < finalScore){
			finalScore = score[j];
		}
	}
	//cout<<finalScore<<endl;
	return finalScore;
}

