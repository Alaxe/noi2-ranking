#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>

struct Container{
	std::vector<std::vector<int>> usedItems;
	int weigth;
};

bool different(std::vector<int> firstContainer, std::vector<int> secondContainer){
	for (int i = 0; i < firstContainer.size(); ++i){
		if (std::find(secondContainer.begin(), secondContainer.end(), firstContainer[i]) != secondContainer.end())
			return false;
	}
	return true;
}

void findBestItems(
	std::vector<int>& items,
	std::map<int, std::vector<std::vector<int>>>& usedItems,
	std::vector<int> currentItems,
	int maxWeigth,
	int currentWeigth,
	int currentIndex){
	if (currentIndex < 0 || currentWeigth == maxWeigth){
		if (currentWeigth > 0)
			usedItems[currentWeigth].push_back(currentItems);
		return;
	}

	for (int i = currentIndex; i >= 0; --i){
		if (currentWeigth + items[i] <= maxWeigth){
			currentItems.push_back(i);
			findBestItems(items, usedItems, currentItems, maxWeigth, currentWeigth + items[i], i - 1);
			currentItems.erase(currentItems.end() - 1);
		}
		else{
			if (currentWeigth > 0)
				usedItems[currentWeigth].push_back(currentItems);
		}
	}

}

int main(){
	int n, W1, W2, maxSum = INT_MIN;
	std::cin >> n >> W1 >> W2;
	std::vector<int> items(n);
	for (int i = 0; i < n; ++i){
		std::cin >> items[i];
	}
	std::map<int, std::vector<std::vector<int>>> usedItemsFirst;
	std::map<int, std::vector<std::vector<int>>> usedItemsSecond;
	std::sort(items.begin(), items.end());
	findBestItems(items, usedItemsFirst, std::vector<int>(), W1, 0, items.size() - 1);
	findBestItems(items, usedItemsSecond, std::vector<int>(), W2, 0, items.size() - 1);

	if (usedItemsSecond.empty()){
		for (auto firstPair : usedItemsFirst){
			if (firstPair.first > maxSum)
				maxSum = firstPair.first;
		}
	}
	else if (usedItemsFirst.empty()){
		for (auto firstPair : usedItemsFirst){
			if (firstPair.first > maxSum)
				maxSum = firstPair.first;
		}
	}
	else{
		for (auto firstPair : usedItemsFirst){
			for (auto secondPair : usedItemsSecond){
				if (firstPair.first + secondPair.first > maxSum){
					for (int i = 0; i < firstPair.second.size(); ++i){
						for (int j = 0; j < secondPair.second.size(); ++j){
							if (different(firstPair.second[i], secondPair.second[j]))
							{
								maxSum = firstPair.first + secondPair.first;
								goto label;
							}
						}
					}
				}
			label:
				int a;
			}
		}
	}



	std::cout << maxSum << std::endl;
	return 0;
}