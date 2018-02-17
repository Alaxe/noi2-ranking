#include <iostream>
#include <string>

using namespace std;

void input();
void reversing();
void check();
void removeletter();
void summary();

string input1, testSubject;
string reversed;
int correctValues=0;
int n=0; //number of letters to be removed from the word

int number=1;//later used to write values in the array
string alreadyTested[100];

int main()
{

    input();

    // testing for palynogram? before letters are deleted
    input1 = testSubject;
    reversing();
    check();

    while(n<input1.length()) {
    input1 = testSubject;
    //removeletter();
    reversing();
    check();
    }

    summary();

    return 0;
}

void input() {
cin >> input1;
}

void reversing() {
//reversed = reverse(testSubject);
return;
}

void check() {
if (testSubject == reversed) {correctValues++;}
}

void removeletter() {

//should remove 1 letter at a time from the test subject and remove another one in the next cycle
for (int i=1; i < n; i++) {
    for (int numberLetterintheWord = 1; numberLetterintheWord < testSubject.length(); numberLetterintheWord++) {
       string removeTest = ""; //should be with removed numberletterintheword letter
       bool moveForward = true;
       for (int testingArrayNum = 1; testingArrayNum < 100 ; testingArrayNum++) {
          if (removeTest==alreadyTested[testingArrayNum]) {moveForward = false;}
       }
       if (moveForward) {
          removeTest = testSubject;
          alreadyTested[number]= testSubject;
          number++;
       }
     //if all of them are in the records, remove the first letter and move onto the second tick of the for cycle
    }
}

if (true) { //if there are no other letter combinations that could be removed, increase the number of deleted letters
    n++;
}
return;
}

void summary() {
cout << endl;
cout << correctValues;
}
