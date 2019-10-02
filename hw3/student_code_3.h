///////////////////////////////////////////////////////////////////////////////
// You need to 
//    1. Read Problem 2 in homework assignment #3. 
//    2. Implement function GetStudentName.
//    3. Implement function FindMaxSchedule.
//    4. Compile your code as explained in the PDF file.
//    5. Run the executable.
//    6. Test and debug your code.
//    7. Submit your code ("student_code_3.h") and results ("solution_3.dat") 
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


//your goal is to implement the following function
bool cmp(double a, double b){
    return a > b;
}

double FindBestAssignment (std::vector<double> a,std::vector<double> b,
                           std::vector<double> r)
//a: slot; b, r : ads
{  
    double max_revenue = 0;
    map <int, int> f;
    //you code goes here
    int n1 = a.size();
    int n2 = b.size();
    std::vector<double> c(n2, 0);
    
    
    double temp;
    for (int j = 0; j < n2; j++){
        temp = b[j] * r[j];
        c[j] = temp;
    }

    sort(a.begin(), a.end(), cmp);
    sort(c.begin(), c.end(), cmp);


    for (int i = 0; i < n1; i++){
        max_revenue = max_revenue + a[i] * c[i];
    }

    return max_revenue;
}
