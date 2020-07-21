#include "Metrics.h"
#include <cmath>


void UserInfo::SetUser(string FirstName, string LastName, char gender1, int height1, float weight1, int age1, string goal1, int activitylevel1) {
	name = FirstName + " " + LastName;
	age = age1;
	height = height1;
	weight = weight1;
	goal = goal1;
	BMI = (weight / (pow(height,2)))* 703;
	activitylevel = activitylevel1;
	gender = gender1;
}

void UserInfo::GoalCalc() {

	char goaltype; //L15-100M
	float BMR;
	int goalgl;
	int timep;
	int goalperiod;
	int count = 1;
	int count2;
	int totalcalories;
	string goaltime;
	goaltype = goal[0];
	for (int i = 1; i < goal.length(); i++) {
		if (isdigit(goal[i])) {
			count++;
		}
		else {
			i = goal.length();
		}
	}
	goalgl = stoi(goal.substr(1, count));

	goaltime = goal.substr(count + 1, goal.length());
	timep = goal.length();
	timep--;
	goalperiod = stoi(goal.substr(count + 1, timep));
	
	if (goaltime[goaltime.length()-1] == 'Y') {
		goalperiod = goalperiod * 365;

	}
	else if (goaltime[goaltime.length()-1] == 'M') {
		goalperiod = goalperiod * 30;
	}

	else if (goaltime[goaltime.length()-1] == 'D') {
		goalperiod;
	}

	if (gender == 'M') {
		BMR = (88.4 + (13.4 * (weight / 2.205))) + ((4.8 * (height * 2.54)) - (5.68 * age));
	}
	else if (gender == 'F') {
		BMR = (447.6 + (9.25 * (weight / 2.205))) + (3.10 * (height * 2.54)) - (4.33 * age);
	}
	
	if (activitylevel == 1) {
		BMR = BMR * 1.2;
	}
	else if (activitylevel == 2) {
		BMR = BMR * 1.375;
	}
	else if (activitylevel == 3) {
		BMR = BMR * 1.55;
	}
	else if (activitylevel == 4) {
		BMR = BMR * 1.725;
	}
	else if (activitylevel == 5) {
		BMR = BMR * 1.9;
	}
	if (goaltype == 'G') {
		totalcalories = ((BMR * goalperiod) + (3500 * goalgl)) / goalperiod;
		caloriess = totalcalories;
		protein = weight * 0.7;
		cout << "You need to eat " << totalcalories << " calories and "<<protein<<"g of protein a day!" << endl;
		cout << endl;
	}
	else if (goaltype == 'L') {
		totalcalories = ((BMR * goalperiod) - (3500 * goalgl)) / goalperiod;
		caloriess = totalcalories;
		protein = weight * 0.5;
		cout << "You need to eat " << totalcalories << " calories and " << protein << "g of protein a day!" << endl;
		if (totalcalories < 1200) {
			cout << "WARNING! This is a dangerously low daily calorie intake. Edit your goal period and try again." << endl;
			cout << endl;
		}
	}
}

void UserInfo::PrintUser() {
	ifstream inFile;
	ofstream outFile;
	outFile.open("UserInfo.txt");
	outFile << 'Y' << endl;
	outFile << name << endl;
	outFile << gender << endl;
	outFile << age << endl;
	outFile << height << endl;
	outFile << weight << endl;
	outFile << goal << endl;
	outFile<< activitylevel<< endl;
	
	
};