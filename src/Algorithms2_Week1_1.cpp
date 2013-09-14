//============================================================================
// Name        : Algorithms2_Week1_1.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Algorithms2_Week1_1.h"
using namespace std;

void ReadFile(const char * inName, PROJECT_STRUCT * data)
{
   ifstream infile(inName);
   std::string line;

   if (!infile)
   {
      cout << "There was a problem opening file " << inName << " for reading." << endl;
   }
   else
   {
      int numJobs, weight, length, count = 0;

      if (infile.good())
      {
         getline(infile, line);
         //get # of jobs from first line
         if (line.empty() == false)
         {
            stringstream stream(line);
            stream >> numJobs;
            //TODO: handle num jobs here
         }
      }

      while (infile.good())
      {
         getline(infile, line);

         size_t locationOfSpace = line.find(' ');
         stringstream tempStreamWeight(line.substr(0, locationOfSpace));
         tempStreamWeight >> weight;

         line = line.substr(locationOfSpace + 1);
         stringstream tempStreamLength(line);
         tempStreamLength >> length;

         data[count].diff = weight - length;
         data[count].weight = weight;
         data[count].length = length;
         data[count].scheduled = false;
         count++;
      }
      infile.close();
   }
}

int ScheduleMaxDifferenceJob(PROJECT_STRUCT * data, int size)
{
   int maxIndexSoFar = 0;
   int maxSoFar = data[maxIndexSoFar].diff;
   int weightOfMaxSoFar = data[maxIndexSoFar].weight;

   for (int i = 1; i < size; i++)
   {
      if ((data[i].diff > maxSoFar) && (data[i].scheduled == false))
      {
         maxIndexSoFar = i;
         maxSoFar = data[maxIndexSoFar].diff;
         weightOfMaxSoFar = data[maxIndexSoFar].weight;
      }
      else if ((data[i].diff == maxSoFar) && (data[i].scheduled == false))
      {
         //higher weight wins
         if (data[i].weight > weightOfMaxSoFar)
         {
            maxIndexSoFar = i;
            maxSoFar = data[maxIndexSoFar].diff;
            weightOfMaxSoFar = data[maxIndexSoFar].weight;
         }
      }
   }

   data[maxIndexSoFar].scheduled = true;
   return maxIndexSoFar;
}
