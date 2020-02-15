#include <iostream>
#include <vector>

int numObjects, max1, max2;
 std::vector<bool> taken;
int* objects;

int maxSum = INT_MIN;


int combinations(std::vector<bool> free, int currentIndex,  int currentWeight, int weight1 ){

    if(free[currentIndex]){

            if(currentWeight + objects[currentIndex] == max2){
                currentWeight += objects[currentIndex];
                if(currentWeight + weight1 > maxSum){
                maxSum = currentWeight + weight1;
                }
            return 0;
            }
        if(currentWeight + objects[currentIndex] > max2){
                return 0;
            }
        else{
        currentWeight += objects[currentIndex];
        }
        if(currentWeight + weight1 > maxSum){
                maxSum = currentWeight + weight1;
            }
    }
        for(int i = currentIndex + 1; i < numObjects; ++i){
            combinations(free, i, currentWeight, weight1);
        }
}


void SecondContainer(std::vector<bool> free, int weight1){
    int currentWeight = 0;
   for(int i = 0; i < numObjects; ++i){
        combinations(free, i , currentWeight, weight1);
    }

}

 void FirstContainer(int currentIndex, std::vector<bool> free, int currentWeight){

        if(currentWeight + objects[currentIndex] == max1){
            currentWeight += objects[currentIndex];
            free[currentIndex] = false;
            SecondContainer(free, currentWeight);
        }
    if(currentWeight + objects[currentIndex] > max1){
            SecondContainer(free, currentWeight);
        }else{
            free[currentIndex] = false;
            currentWeight += objects[currentIndex];
        }
        if(currentWeight > maxSum){
            maxSum = currentWeight;
             }

     for(int i = currentIndex + 1; i < numObjects; ++i){


        FirstContainer(i, free, currentWeight);
     }
 }


int main()
{

    std::cin >> numObjects >> max1 >> max2;

    objects = new int[numObjects];
    for(int i = 0; i < numObjects; i++){
        std::cin >> objects[i];
        taken.push_back(true);
    }


for(int i = 0; i < numObjects; ++i){

        FirstContainer( i, taken, 0);
}
    std::cout << maxSum;


    return 0;
}
