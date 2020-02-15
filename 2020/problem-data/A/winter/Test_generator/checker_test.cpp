/* the checker has three arguments:
   - first - state of checking with three possible values:
              = 0 - checks the solution file according the answer file
              = 1 - generates solution file with name from the third argument using the first solution
              = 2 - generates solution file with name from the third argument using the second solution
              = 3 - generates solution file with name from the third argument using the third solution
              = 4 - generates solution file with name from the third argument using the fourth solution
   - second - name of the input file
   - third - name of the file to be checked or generated
   - fourth - name of the answer file (optional - only for the first option)
    */
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<time.h>
#include "1sol.cpp"
#include "2sol.cpp"
#include "3sol.cpp"
#include "4sol.cpp"
using namespace std;
int main (int argc, char** argv) {
    FILE *in1,*out1,*ans1,*out=stdout,*err=stderr;
    double beg_time,end_time;
    int state,num1,num2;
    if (argc<3) {
       fprintf(out,"0\n");
       fprintf(err,"The checker needs arguments!\n");
       return 0;
       }
    state=atoi(argv[1]);
    if ((state==0)&&(argc<4)) {
       fprintf(out,"0\n");
       fprintf(err,"For the first option the checker needs input_file, output_file and answer_file\n");
       return 0;
       }
    if ((state!=0)&&(argc<3)) {
       fprintf(out,"0\n");
       fprintf(err,"For the %d option the checker needs input_file and output_file\n",state);
       return 0;
       }
    in1=fopen(argv[2],"rt");
    if (!in1) {
       fprintf(out,"0\n");
       fprintf(err,"Could not open input file!\n");
       return 0;
       }
    if (atoi(argv[1])==1) {
       beg_time=clock();
       first_sol::solution(argv[2],argv[3]);
       end_time=clock();
       printf("first solution working time: %.2f s\n",(end_time-beg_time)/CLOCKS_PER_SEC);
       return 0;
       }
    if (atoi(argv[1])==2) {
       beg_time=clock();
       second_sol::solution(argv[2],argv[3]);
       end_time=clock();
       printf("second solution working time: %.2f s\n",(end_time-beg_time)/CLOCKS_PER_SEC);
       return 0;
       }
    if (atoi(argv[1])==3) {
       beg_time=clock();
       third_sol::solution(argv[2],argv[3]);
       end_time=clock();
       printf("third solution working time: %.2f s\n",(end_time-beg_time)/CLOCKS_PER_SEC);
       return 0;
       }
    if (atoi(argv[1])==4) {
       beg_time=clock();
       fourth_sol::solution(argv[2],argv[3]);
       end_time=clock();
       printf("fourth solution working time: %.2f s\n",(end_time-beg_time)/CLOCKS_PER_SEC);
       return 0;
       }
    out1=fopen(argv[3],"rt");
    if (!out1) {
       fprintf(out,"0\n");
       fprintf(err,"Could not open output file!\n");
       return 0;
       }
    ans1=fopen(argv[4],"rt");
    if (!ans1) {
       fprintf(out,"0\n");
       fprintf(err,"Could not open answer file!\n");
       return 0;
       }
    fscanf(ans1,"%d",&num1);
    if (fscanf(out1,"%d",&num2)==EOF) {
       fprintf(out,"0\n");
       fprintf(err,"No output!\n");
       return 0;
       }
    if (num1!=num2) {
       cout << num1 << " " << num2 << endl ;
       fprintf(out,"0\n");
       fprintf(err,"Wrong answer!\n");
       return 0;
       }
    fprintf(out,"1\n");
    fprintf(err,"OK!\n");
    return 0;
}
