///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 2 in homework assignment #5. 
//    2. Implement function GetStudentName.
//    3. Implement function FindMaxProfit.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_5.h") and results ("solution_5.dat") 
//       via Canvas.
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector> 

//you can include standard C++ libraries here
#include <algorithm>

using namespace std;
// This function should return your name.
// The name should match your name in Canvas

void GetStudentName(std::string& your_name)
{
   //replace the placeholders "Firstname" and "Lastname"
   //with you first name and last name 
   your_name.assign("Yiming Dai");
}


//you can use one of the following signatures

//int FindMaxProfit (const std::vector<int>& north, const std::vector<int>& west)
//or 
//int FindMaxProfit (std::vector<int> north, std::vector<int> west)

int FindMaxProfit (const std::vector<int>& north, const std::vector<int>& west)
{  
    int T = north.size();
    int profitN[T];
    int profitW[T];
  
    //base case
    profitN[0] = 0;
    profitW[0] = 0;

    profitN[1] = north[0];
    profitW[1] = west[0];
    
    //
    for (int t = 2; t <= T; t++){
        profitN[t] = max(profitN[t-1] + north[t-1], profitW[t-2] + north[t-1]);
        profitW[t] = max(profitW[t-1] + west[t-1], profitN[t-2] + west[t-1]);
    }

   return max(profitN[T], profitW[T]);
}

