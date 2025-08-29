//university management system
#include <iostream>
using namespace std;

//  Function to calculate percentage based on FSC marks
float calculatePercentage(float fscMarks) {
    // Assuming total marks for FSC is 1100
    float totalMarks = 1100; 
    // Total marks for FSC
    return (fscMarks / totalMarks) * 100;
}

int main() {
    // Admin 
    string username = "admin";
    string password = "admin123";
    
    // Available Courses Names
    string courses[5] = {
    "Computer Science",
    "Software Engineering",
    "Data Science",
    "Computer Engineering",
    "Artificial intelligence"};
    //seat capacity 
    int seats[5] = {
        5, 
        4, 
        6, 
        1, 
        3};
    //eligibility criteria
    float eligibilityCriteria[5] = {
        90.0,
        80.0,
        75.0, 
        70.0,
        65.0};
    
    // Variables for students details
    string studentName, studentEmail, chosenCourse;
    float studentmarks, fscMarks;
    
    // Program initial interface
    int choice;
    cout << "Select an option:" << endl ;
    cout << "1. Admin Login" << endl;
    cout << "2. Student Admission" << endl;
    cout << "Enter choice:";
    cin >> choice;
    if (choice == 1) {
        // Admin login section
        string enterusername, enterpassword;
        int loginAttempts = 0;
        
        while (loginAttempts < 3) {
            cout << "Enter Admin Username: ";
            cin >> enterusername;
            cout << "Enter Admin Password: ";
            cin >> enterpassword;
            
            if (enterusername == username && enterpassword == password) {
                cout << "login successfully" << endl;
                
                for (int i = 0; i < 5; i++) {
                    cout << (i + 1) << ". " << courses[i] 
                    <<" (Seats: " << seats[i] << ")"
                    << "( Eligibility Criteria: " << eligibilityCriteria[i] << "% )" << endl;
                }
                break;
            } else {
                loginAttempts++;
                if (loginAttempts < 2) {
                    cout << "Invalid login info." << endl;
                } else {
                    cout << "Too many incorrect attempts. try again later." << endl;
                }
            }
        }
    } 
    else if (choice == 2) {
        // Student admission section
        cout << "Give details for admission." << endl;
        // Collecting student details
        cout << "Student Name: ";
        cin >> studentName;
        cout << "Student Email Address: ";
        cin >> studentEmail;
        // Collecting marks for FSC
        cout << "Enter your FSC Marks (out of 1100): ";
        cin >> fscMarks;
        // Calculate percentage
        studentmarks = calculatePercentage(fscMarks);
        cout << "Your calculated percentage is: " << studentmarks << "%" << endl;
        
        //Available courses
        cout << "Courses available for admission:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << (i + 1) << ". " << courses[i] << endl;
        }
        //slect course
        int courseChoice;
        cout << "Select the course by entering the number (1-4): ";
        cin >> courseChoice;
        
        if (courseChoice < 1 || courseChoice > 5) {
            cout << "select from given 4 courses." << endl;
        } else {
            // Check eligibility and seat availability
            int selectedCourse = courseChoice - 1;
            if (seats[selectedCourse] > 0) {
                if (studentmarks >= eligibilityCriteria[selectedCourse]) {
                    seats[selectedCourse]--;
                    cout << "Congratulations" << studentName << " You got admission in  " 
                         << courses[selectedCourse] << "." << endl;

                } else {
                    cout << "Low Aggregate" 
                         << "(" << courses[selectedCourse] <<",Minimum eligibility is ( " 
                         << eligibilityCriteria[selectedCourse] << "%)"  << ")" 
                << endl;
                }
            } else {
                cout << "there are no available seats."
                      << endl;
            }
        }
    } 
    else {
        cout << "only two interface available, slect from it." << endl;}
    return 0;
}