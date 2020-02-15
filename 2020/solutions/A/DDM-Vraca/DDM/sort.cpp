#include<iostream>

int main()
{
	int n, answer = 0;
	std::cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++){
		std::cin>>arr[i];
	}
	
	for(int i = 1; i < n; i++){
		if(arr[i] > arr[i - 1]){
			if(arr[i] > arr[i + 1]){
				answer = answer + arr[i] - arr[i + 1];
				arr[i] = arr[i] - (arr[i] - arr[i + 1]);
			}
		}else {
			answer = answer + arr[i - 1] - arr[i];
			arr[i] = arr[i] + (arr[i-1] - arr[i]);
		}
		
	}
	
	std::cout<<answer;

	return 0;
}
