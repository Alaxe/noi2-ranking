#include<iostream>

bool toBin( long long int num, int z){

	while( num > 0){
		if( num % 2 == 0)z--;
		if(z <= -1) return false;
		num /= 2;
	}
	if( z == 0) return true;
	return false;
}

int main(){

	long long int s, t, z;
	int br = 0;

	std::cin >> s >> t >> z;

	for( long long int i = s; i <= t; i++){
		if( toBin( i, z)) br++;
	}
	std::cout << br << '\n';
	return 0;
}
