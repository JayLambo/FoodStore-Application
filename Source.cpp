
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include "Metrics.h" 
#include "HashTable.h"
#include <ctype.h>
#include <sstream>
#include <unordered_map>
#include <fstream>

using namespace std;
void initializer();
void loadUserInfo();
int calculateheight(string);
bool testcaseheight(string);
string getgoal();
int poundcheck();
bool testcasegoal(string);
char getgender();
int getheight();
unordered_map<string, int> Food;


string init_check;
ifstream inFile;
ofstream outFile;
string useUserInfo;
int main()
{
    
    inFile.open("UserInfo.txt");
    if (!inFile) {
        cout << "Error Opening File" << endl;
    }
    
    inFile >> init_check;
    if (init_check == "Y") {
        cout << "User Info found, press 1 if you would like to ignore the save data, otherwise save data will be loaded." << endl;
        cin >> useUserInfo;
        if (useUserInfo == "1") {
            initializer();
        }
        else {
            loadUserInfo();
            
           

        }
    }

    else {
        initializer();
    }
  
    
}

void initializer() {
    int age;
    int calories, protein;
    bool Check = 0;
    int activitylevel = -1;
    string FirstName;
    string LastName, goal, goalperiod;
    int height;
    float weight;
    ifstream inFile;
    ofstream outFile;
    char gender;
    FoodTable Diet;
    Diet.PopulateTable();
    cout << "Hello! Welcome to your personalized meal tracker and food database!" << endl;
    cout << "Before we start, we need your biometrics for a more personalized experience!" << endl;
    cout << "What is your first name? " << endl;
    cin >> FirstName;
    cout << "What is your last name? " << endl;
    cin >> LastName;
    gender = getgender();
    cout << "What is your age?" << endl;
    cin >> age;
    height = getheight();
    cout << "What is your weight in lbs? " << endl;
    cin >> weight;
    goal = getgoal();
    while (activitylevel > 5 || activitylevel < 1) {
        cout << "What is your activity level on a scale of 1-5? 1 for sedentary/office work, 2 for light exercise a few times a week" << endl;
        cout << "3 for moderate exercise for 3-5 days a week, 4 for heavy exercise multiple times a week, and 5 for heavy exercise every day/ multiple times a day" << endl;
        cin >> activitylevel;

        if ((activitylevel > 5 || activitylevel < 0)) {
            cout << endl;
            cout << "Error reading activity level. Please follow the instructions and try again." << endl;
            cout << endl;
        }
    }
    UserInfo main_user;
    main_user.SetUser(FirstName, LastName, gender, height, weight, age, goal, activitylevel);
    main_user.PrintUser();
    main_user.GoalCalc();
    calories = main_user.caloriess;
    protein = main_user.protein;
    Diet.Daily(calories, protein);
    

}

void loadUserInfo(){
    string none, goal;
    string FirstName, LastName, name;
    int age, height, activitylevel, calories, protein;
    char none1;
    char gender;
    FoodTable Diet;
    Diet.PopulateTable();
    float weight;
  
    inFile >> FirstName >> LastName;
    inFile >> gender;
    inFile >> age;
    inFile >> height;
    inFile >> weight;
    inFile >> goal;
    inFile >> activitylevel;
    inFile.close();
    UserInfo main_user;
    main_user.SetUser(FirstName, LastName, gender, height, weight, age, goal, activitylevel);
    main_user.GoalCalc();
    calories = main_user.caloriess;
    protein = main_user.protein;
   
    Diet.Daily(calories, protein);

    
}

int calculateheight(string a) {
    int feet = a[0] - 48;
    
    int inches = a[2] - 48;
   
    int height = (feet * 12) + inches;
    return height;
}


bool testcasegoal(string a) {
    int count = 0;
    while (a[count]) {
        count++;
    }
    if (count != 1) {
        return false;
    }

   
    
    if (a == "") {
        return false;
    }

    if (a[0] == 'G' || a[0] == 'L') {
        return true;
    }
    if (a[0] != 'G' || a[0] != 'L') {
        return false;
    }
}

bool testcasegoalperiod(string a) {
    int count = 0;
    while (a[count]) {
        count++;
    }
    if (count < 2) {
        return false;
    }
    int p;
    string f;
    stringstream new2(a);
    new2 >> p >> f;
   
    if (f == "D" || f == "M" || f == "Y") {
        return true;
    }
    if (f != "D" || f != "M" || f != "Y") {
        return false;
    }
    if (a == "") {
        return false;
    }

    if (!isdigit(a[0])) {
        return false;
    }

    else {
        return true;
    }
}

bool testcaseheight(string a) {
    int count = 0;
    while (a[count]) {
        count++;
    }
    if (count <3 || count>4){
        return false;
    }
    if (a[3]) {
        if (!isdigit(a[3])) {
            return false;
        }
    }
    if (a[1] != ',') {
        return false;
    }
    if (a == "") {
        return false;
    }
    
    else {
        return true;
    }
}

int getheight() {
    string Height;
    bool Check = false;
    while (Check != true) {
        cout << "What is your height in inches? Please use the format 'feet,inches', for example : 5,6" << endl;
        cin >> Height;
        Check = testcaseheight(Height);
      
        if (Check == false) {
            cout << "Error recording height. Please follow the instructions and try again."<<endl;
            cout << endl;
        }
        else {
            return calculateheight(Height);
        }
    }
}

string getgoal() {
    string goal, goalperiod;
    int pounds;
    bool Check = false;
    while (Check != true) {
        cout << "Do you want to gain weight or lose weight? Type G for gain and L for lose " << endl;
        cin >> goal;
        Check = testcasegoal(goal);

        if (Check == false) {
            cout << "Error recording goal. Please follow the instructions and try again." << endl;
            cout << endl;
        }

    }
    
    pounds = poundcheck();
   
    string pound = to_string(pounds);
    Check = false;
    while (Check != true) {
        cout << "In what time period? Please use the format (number)Y for number of years, (number)M for number of months, and (number)D for number of days!" << endl;
        cout << "For example, two months is 2M, three years is 3Y, and 10 days is 10D"<<endl;
        cin >> goalperiod;
        Check = testcasegoalperiod(goalperiod);

        if (Check == false) {
            cout << "Error recording goal period. Please follow the instructions and try again." << endl;
            cout << endl;
        }
    }
    return goal + pound +'-'+ goalperiod;

}
int poundcheck(){
    bool check = false;
    string pounds;
    while (check != true) {
        cout << "By how many pounds? " << endl;
        cin >> pounds;
        if (!isdigit(pounds[0])) {
            check = false;
            cout << "Invalid Value, try again" << endl;
        }
        else {
            int x = 0;
            stringstream degree(pounds);
            degree >> x;
            return x;
        }
    }
}

char getgender() {
    string gender;
    char g;
    cout << "Are you male or female? " << endl;
    cin >> gender;
    if (gender == "Male" || gender == "male" || gender == "m" || gender == "M") {
        g = 'M';

    }
    else if (gender == "Female" || gender == "female" || gender == "f" || gender == "F") {
        g = 'F';
    }
    else {
        cout << "Error reading gender. Please use M or F format." << endl;
            g = getgender();
    }
    return g;
}