//HEADER
// Header file for classes
//
#ifndef Metrics_HEADER
#define Metrics_HEADER

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>


using namespace std;




class UserInfo
{
private:
    string name;
    
    string bodytype;

 



public:     // public members here - helper functions
    // ************** constructors
    string goal;
    int caloriess;
    int protein;
    char gender;
    int age, BMI;
    float height;
    float weight;
    int activitylevel;

    // parameterized constructor - use user provided values

    void Character();
    //**************  Transformers
    void SetUser(string FirstName, string Lastname, char gender, int height, float weight, int age, string goal, int activitylevel);
    void GoalCalc();
    //**************  observers


    void PrintUser();


};
#endif