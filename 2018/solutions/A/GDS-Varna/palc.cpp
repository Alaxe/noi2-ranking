#include<iostream>
#include<string>

void rec( long long int fIndex, long long int lIndex, std::string word, long long int &br){
	if( lIndex > fIndex)
	for( long long int i = fIndex; i < lIndex - 1; i++){
		for( long long int j = i + 1; j < lIndex; j ++){
			if( word[i] == word[j]){
				fIndex = i + 1;
				lIndex = j - 1;
				br += (j - i);
				rec( fIndex, lIndex, word, br);
			}
		}
	}
	return;
}

long long int isItPal( std::string word , long long int &br){

	long long int fIndex, lIndex;
	long long int length = br;

	for( long long int i = 0; i < length - 1; i++){
		for( long long int j = i + 1; j < length; j ++){
			if( word[i] == word[j]){
				fIndex = i + 1;
				lIndex = j - 1;
				br += (j - i);
				rec( fIndex, lIndex, word, br);
			}
		}
	}

	return br;
}

int main(){
	std::string word;
	std::cin >> word;

	long long int br = word.length();

	std::cout << isItPal( word, br) % 1000000007 << '\n';
	return 0;
}
