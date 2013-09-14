//============================================================================
// Name        : Algorithms2_Week1_1.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Algorithms2_Week1_1.h"

int main()
{
   int const NUM_OF_JOBS = 10000;
   PROJECT_STRUCT data[NUM_OF_JOBS];
   long answer;
   const char *inname =
      "C:/Users/asnyder/git/Algorithms2_Week1_1/src/jobs.txt";
   ReadFile(inname, data);
   answer = ComputeOptimalScheduleLength(data, NUM_OF_JOBS);
   cout << "Weighted completion time: " << answer << endl;
}
