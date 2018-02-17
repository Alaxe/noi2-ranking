#include<iostream>
#include<string.h>

std::stringsubstractStrings( std::stringstring1, std::stringstring2){

	std::stringsum;

	for( long long int i = string1.length() - 1; i >= 0 ; i --){
		if(string1[i] > string2[i]) sum += string1[i] - string2[i];
		else {
			string1[i - 1] --;
			if( string1[i] < '9')string1[i]++;
			else if( string1[i] == '9') string1[i]='A';
				 else if( string1[i] >= 'A') string1[i]++;
			sum += string1[i] - string2[i];
		}
	}

	return sum;
}

std::stringrot( std::stringnumber){
	std::stringnumber2 = number;
	number2[number.length() - 1] = number[0];
	for( long long int i = 0; i < number.length() - 1; i++){
		number2[i] = number[i + 1];

	}

	return number2;
}

std::stringtoBase( long long int number, int base){

	std::stringnewNumber;
	std::stringnewNumber2;

	while( number > 0){
		switch(number % base){
			case 0: { newNumber += '0'; newNumber2 += '0';};break;
			case 1: { newNumber += '1'; newNumber2 += '1';};break;
			case 2: { newNumber += '2'; newNumber2 += '2';};break;
			case 3: { newNumber += '3'; newNumber2 += '3';};break;
			case 4: { newNumber += '4'; newNumber2 += '4';};break;
			case 5: { newNumber += '5'; newNumber2 += '5';};break;
			case 6: { newNumber += '6'; newNumber2 += '6';};break;
			case 7: { newNumber += '7'; newNumber2 += '7';};break;
			case 8: { newNumber += '8'; newNumber2 += '8';};break;
			case 9: { newNumber += '9'; newNumber2 += '9';};break;
			case 10: { newNumber += 'A'; newNumber2 += 'A';};break;
			case 11: { newNumber += 'B'; newNumber2 += 'B';};break;
			case 12: { newNumber += 'C'; newNumber2 += 'C';};break;
			case 13: { newNumber += 'D'; newNumber2 += 'D';};break;
			case 14: { newNumber += 'E'; newNumber2 += 'E';};break;
			case 15: { newNumber += 'F'; newNumber2 += 'F';};break;
			default : break;
		}
		number /= base;
	}
	for( int i = 0, j = newNumber.length() - 1; i < newNumber.length(); i++, j--){
		newNumber2[i] = newNumber[j];
	}
	return newNumber2;
}

int main(){

	bool check = 1;
	int base;
	long long int number;

	cin >> base;

	std::stringM ;
	std::stringnumber2 = toBase( number, base);
	std::stringnumber3 = substractStrings( rot( number2), number2);

	std::cin >> M;

	long long int m = M[M.length() - 1] - '0';

	long long int multyplier = 10;

	for( long long int i = M.length() - 2; i >= 0; i--){
		m += 10 * (M[i] - '0');
		multyplier *= 10;
	}

	for( int k = 12; k <= m * 10; k++){
		number = k;
		for( int i = 0; i < number3.length(); i++){
				if( strcmp( number3[i], M[i]));
				else check = 0;
		}
		if( check) std::cout << number2 << '\n';
		else std::cout << check << '\n';
	}
	return 0;
}
