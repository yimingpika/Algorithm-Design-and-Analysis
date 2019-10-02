///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 2 in homework assignment #6. 
//    2. Implement function GetStudentName.
//    3. Implement function FindMonotonePrediction.
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
#include <queue>
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

int FindMonotonePrediction (const std::vector<int>& y, int M)
{
    int n = y.size();
    vector<vector<int> > cost(n, vector<int>(M+1, 0));
    
    int inf = 0x7FFFFFFF;
    //base case
    for (int j = 0; j <= M; j++){
        cost[0][j] = (j - y[0]) * (j - y[0]);
    }

    for (int i = 1; i < n; i++){
        cost[i][0] = y[i] * y[i] + cost[i-1][0];
    }
    
    
    for (int i = 1; i < n; i++){
        for (int j = 1; j <= M; j++){
            cost[i][j] = min(cost[i][j-1] - (j - 1 - y[i]) * (j - 1 - y[i]) + (j - y[i]) * (j - y[i]), cost[i-1][j] + (j - y[i]) * (j - y[i]));
        }
    }
    
    int ans = inf;
    for(int j = 0; j <= M; j++){
        ans = min(ans, cost[n-1][j]);
    }
    
    return ans;
}
