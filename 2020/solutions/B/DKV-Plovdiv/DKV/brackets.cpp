#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

struct commands{
	commands(){}

	bool multiplication = false;
	bool sum = false;
	int first = 0;
	int last = 0;
	bool minusInFront = false;

};

void findbrackets(std::string& text, int index){
	int opperandsCount = 0;
	while (text[index] != '(' && text[index] != ')'){
		if (text[index] == '&')
			++opperandsCount;
		if (opperandsCount == 2){

		}
		++index;
	}
	if (text[index] == '('){

	}
	else if (text[index] == ')'){

	}

}

int main(){
	std::string text;
	std::cin >> text;
	std::stack<commands> stack;
	stack.push(commands());
	std::vector<int> indecies;

	for (int i = 0; i < text.size(); ++i){
		if (text[i] == '+' || text[i] == '-'){
			stack.top().sum = true;
			
			if (text[i] == '-' && text[i + 1] == '('){
				commands newCmd;
				newCmd.first = i + 1;
				newCmd.minusInFront = true;
				stack.push(newCmd);
				++i;
			}			
		}
		else if (text[i] == '*' || text[i] == '/') {
			if (text[i + 1] == '('){
				commands newCmd;
				newCmd.first = i + 1;
				newCmd.multiplication = true;
				stack.push(newCmd);
				++i;
			}
		}
		else if (text[i] == ')'){
			stack.top().last = i;
			commands currentCmd = stack.top();
			if (currentCmd.sum == false){
				indecies.push_back(currentCmd.first);
				indecies.push_back(currentCmd.last);
			}
			else{
				if (text.length() > i + 1 && text[i + 1] == '*' || text[i + 1] == '/')
				{
					
				}
				else if (currentCmd.minusInFront == false && currentCmd.multiplication == false){
					indecies.push_back(currentCmd.first);
					indecies.push_back(currentCmd.last);
				}
			}
			stack.pop();
		}
		else if (text[i] == '('){
			commands newCmd;
			newCmd.first = i;
			stack.push(newCmd);
		}
		
	}

	std::sort(indecies.begin(), indecies.end());
	for (int i = indecies.size() - 1; i >= 0; --i){
		text.replace(indecies[i], 1, "");
	}
	std::cout << text << std::endl;
	return 0;
}