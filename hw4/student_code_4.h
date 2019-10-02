 ///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 1 in homework assignment #4. 
//    2. Implement function GetStudentName.
//    3. Implement functions ProblemA and ProblemB.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_4.h") and results ("solution_4.dat") 
//       via Canvas.
///////////////////////////////////////////////////////////////////////////////

//required libraries
#include <string>
#include <vector> 

//you can include standard C++ libraries here
#include <unordered_set>
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


int ProblemA (std::vector<int> X)
{
    unordered_set<int> p;
    int right = 0;
    int max_k = 1;
    
    for (right = 0; right < X.size(); right++){
        if (p.find(X[right]) == p.end()){
            p.insert(X[right]);
        }
        else{
            p.clear();
            p.insert(X[right]);
            max_k++;
        }
    }
    return max_k;
}

int ProblemB (std::vector<int> X)
{  
    sort(X.begin(), X.end());
    unordered_set<int> p;
    int left = 0, right = 0;
    int max_k = 0;
    
    for (right = 0; right < X.size(); right++){
        if (p.find(X[right]) == p.end()){
            p.clear();
            left = right;
            p.insert(X[right]);
        }
        else{
//            p.insert(X[right]);
            max_k = max(max_k, right - left + 1);
        }
    }
    return max_k;
    
}
