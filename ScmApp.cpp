// OOP244 Milestone2
// File: ScmApp.cpp
// Version: 1.0
// Date: 2016/07/24
// Author: Jie Dou
// Description:
// 
/////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <cstring>
#include "ScmApp.h"
#include "Course.h"
#include <fstream>


namespace sict {

	ScmApp::ScmApp() {
		noOfCourses_ = 0;
		for (int i = 0; i < MAX_NO_RECS + 1; i++) {
			courseList_[i] = nullptr;
		}
	}
	ScmApp::ScmApp(const char filename[256]){
		strcpy(filename_, filename);
		noOfCourses_ = 0;
		for (int i = 0; i < MAX_NO_RECS + 1; i++) {
			courseList_[i] = nullptr;
		}
	}
	ScmApp::~ScmApp() {
		for (int i = 0; i < MAX_NO_RECS + 1; i++) {
			courseList_[i] = nullptr;
		}
	}

	// private function

	/*ScmApp::ScmApp(const ScmApp& other) {
		*this = other;
	}
	*/
	void ScmApp::pause() const {
		
		std::cout << "Press Enter to countinue..." << std::endl;
		std::cin.ignore();
		return;
		
	}

	int ScmApp::menu() {

		int i = 0;
		std::cout << "Seneca Course Management Tool" << std::endl;
		std::cout << "1- List courses" << std::endl;
		std::cout << "2- Display the details of a course" << std::endl;
		std::cout << "3- Add a course" << std::endl;
		std::cout << "4- Change the study load of a course" << std::endl;
		std::cout << "5- Load courses from a file" << std::endl;
		std::cout << "6- Save courses to a file" << std::endl;
		std::cout << "0- Exit program" << std::endl;
		std::cin >> i;

		if (i <= 6 && i >= 0) {
			return i;
		} else {
			return -1;
		}
	} 

	void ScmApp::listCourses() const {
		std::cout << std::endl;
		std::cout << " Row" << " | ";
		std::cout << "Code" << " | ";
		std::cout << std::setw(26) << std::setfill(' ');
		std::cout << "Course Title";
		std::cout << std::setw(15) << std::setfill(' ') << " | ";
		std::cout << "Credits" << " | ";
		std::cout << "Study Load" << " | ";
		std::cout << "System" << " | ";
		std::cout << "Lang. Req." << " | " << std::endl;
		std::cout << std::setfill('-') << std::setw(6) << std::right << "|";
		std::cout << std::setfill('-') << std::setw(7) << std::right << "|";
		std::cout << std::setfill('-') << std::setw(41) << std::right << "|";
		std::cout << std::setfill('-') << std::setw(10) << std::right << "|";
		std::cout << std::setfill('-') << std::setw(13) << std::right << "|";
		std::cout << std::setfill('-') << std::setw(9) << std::right << "|";
		std::cout << std::setfill('-') << std::setw(13) << std::right << "|" << std::endl;

		for (int i = 0; i < noOfCourses_ + 1; i++) {// including last bar
			if (courseList_[i] != nullptr) {
				std::cout << std::setfill(' ') << std::setw(4) << std::right << i << " |";
				courseList_[i]->display(cout);
			}
			if (i == DISPLAY_LINES) {
				pause();
			}
		}

		std::cout << "---------------------------------------------------------------------------------------------------" << std::endl;

	}

	int ScmApp::searchACourse(const char* courseCode) const {
		
		for (int i = 0; i < noOfCourses_ ; i++) {
			if (*courseList_[i] == courseCode) {
				
				return i;
			}
			
		}
		return -1;
	}

	void ScmApp::changeStudyLoad(const char* courseCode) {
		int input = 0;
		bool findresult = false;
		for (int i = 0; i < noOfCourses_ + 1 && findresult == false; i++) {
			if (*courseList_[i] == courseCode) {
				findresult = true;
				std::cout << "Please enter the amount of the study load: ";
				std::cin >> input;
				*courseList_[i] += input;

			}
		}
		if (findresult == false) {
			std::cout << "Not Found!" << std::endl;
		}
	} 

	void ScmApp::addACourse(int type) {
		
		int i = noOfCourses_;
		
		if (i <= MAX_NO_RECS) {
			if (type == 1) {//add ICTcourse
				courseList_[i] = new ICTCourse;
				courseList_[i]->read(cin);
				/*
				std::cout << "Course Code: ";
				char code[MAX_COURSECODE_LEN + 1];
				std::cin.ignore();
				std::cin.getline(code, 7);
				courseList_[i]->setCourseCode(code);

				std::cout << "Course Title: ";
				char course_title[200];
				std::cin.getline(course_title, 200);
				courseList_[i]->setCourseTitle(course_title);

				std::cout << "Course Credit: ";
				int credit = 0;
				std::cin >> credit;
				courseList_[i]->setCredits(credit);

				std::cout << "Study Load: ";
				int load = 0;
				std::cin >> load;
				courseList_[i]->setStudyLoad(load);

				std::cout << "Computer System: ";
				char system_[6 + 1];
				std::cin.ignore();
				std::cin.getline(system_, 7);
				((ICTCourse*)courseList_[i])->setComputerSystem(system_);
				*/
				noOfCourses_++;
			}
			else if (type == 2) {// add GenEdcourse
				courseList_[i] = new GenEdCourse;
				courseList_[i]->read(cin);
				/*
				std::cout << "Course Code: ";
				char code[MAX_COURSECODE_LEN + 1];
				std::cin.ignore();
				std::cin.getline(code, 7);
				courseList_[i]->setCourseCode(code);

				std::cout << "Course Title: ";
				char course_title[200];
				std::cin.getline(course_title, 200);
				courseList_[i]->setCourseTitle(course_title);

				std::cout << "Course Credit: ";
				int credit = 0;
				std::cin >> credit;
				courseList_[i]->setCredits(credit);

				std::cout << "Study Load: ";
				int load = 0;
				std::cin >> load;
				courseList_[i]->setStudyLoad(load);

				std::cout << "Language Requirement: ";
				int langreq = 0;
				std::cin >> langreq;
				((GenEdCourse*)courseList_[i])->setLangLevel(langreq);
*/
				noOfCourses_++;
			}
		}
	} 

	int ScmApp::run() {
		
		int input = -2;
		char searchCode[MAX_COURSECODE_LEN + 1];
		input = menu();
		while (input != 0) {
			
			if (input == 1) {
				
				listCourses();
				std::cout << std::endl;
				//input = menu();

			} else if (input == 2){

				std::cout << "Please enter the course code: ";
				std::cin.ignore();
				std::cin.getline(searchCode, 7);
				int index = searchACourse(searchCode);
				if (index != -1) {
					std::cout << *courseList_[index];
				}
				else {
					std::cout << "Not found!";
				}
				searchCode[0] = '\0';
				std::cout << std::endl;
				//input = menu();

			} else if (input == 3) {
				std::cout << "Please enter the course type (1-ICT or 2-GenEd): ";
				int temp = 0;
				std::cin >> temp;
				addACourse(temp);
				std::cout << std::endl;
				//input = menu();

			}else if (input == 4) {

				std::cout << "Please enter the course code: ";
				std::cin.ignore();
				std::cin.getline(searchCode, 7);
                changeStudyLoad(searchCode);
	            searchCode[0] = '\0';
			    std::cout << std::endl;
			    //input = menu();

			}else if (input == 5){
				loadRecs();
			}else if (input == 6){
				saveRecs();
			}else if (input <0 || input>6) {
				std::cout << "===Invalid Selection, try again===";
				std::cout << std::endl;
				//input = menu();
			}

			if (input == 0) {
				std::cout << "Goodbye!!";
				
			}
			input = menu();
		}
		return 0;
	} 
	//use store function load courses from a file
	void ScmApp::loadRecs(){
		int readIndex=0;
		
		//cout << "Please enter the file name " << endl;
		fstream dataFile_(filename_);
		if (!dataFile_.is_open()){
			cout << "loadRecs():File can not open: " << filename_ << endl;
		}
		else{
			for (int i = 0; i < noOfCourses_; i++){
				if (courseList_[i] != nullptr){
					delete courseList_[i];
					courseList_[i] = nullptr;
				}
			}

			while (dataFile_ && !dataFile_.eof()){
				char objectType = ' ';
				dataFile_ >> objectType;
				if (objectType=='I'){
					courseList_[readIndex] = new ICTCourse;
				}
				else if (objectType == 'G'){
					courseList_[readIndex] = new GenEdCourse;
				}
				else{ 
					dataFile_.ignore(1, ',');
					courseList_[readIndex] = new Course;
				}
				dataFile_.ignore(1, ',');
				courseList_[readIndex]->load(dataFile_);
				readIndex++;
			}
			noOfCourses_ = readIndex;
			dataFile_.close();
		}
	}
	void ScmApp::saveRecs(){
		//cout << "saveRecs" << endl;
		fstream dataFile_(filename_);
		if (!dataFile_.is_open()){
			cout << "saveRecs():File can not open: " << filename_ << endl;
		}
		else{
			for (int i = 0; i < noOfCourses_; i++){
				courseList_[i]->store(dataFile_, true);
			}
		}
		dataFile_.close();
	}
	


}