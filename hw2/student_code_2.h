///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 2 in Homework Assignment #2. 
//    2. Implement function GetStudentName.
//    3. Implement function FindMaxSchedule.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_2.h") and results ("solution_2.dat") 
//       via Canvas.
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector> 

//you can include standard C++ libraries here
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <queue>
using namespace std;

// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name 
   your_name.assign("Yiming Dai");
}

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

//you can use one of the following signatures

//int FindMaxSchedule (const std::vector<std::pair<int,int>>& intervals)
//or 
//int FindMaxSchedule(std::vector<std::pair<int, int>> intervals)

int FindMaxSchedule(std::vector<std::pair<int, int>> intervals)
{  
//   //your code goes here
    int count = 0;
    int t = 0; //finish time
    int n = intervals.size();
    
    sort(intervals.begin(), intervals.end(), cmp);
    for (int i = 0; i < n; i++){
        if(t <= intervals[i].first){
            count++;
            t = intervals[i].second;
        }
    }
    return count;
//    return -1;
}

