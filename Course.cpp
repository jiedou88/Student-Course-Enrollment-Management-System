// OOP244 Milestone1
// File: Course.cpp
// Version: 1.0
// Date: 2016/07/24
// Author: Jie Dou
// Description:
// 
/////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Course.h"



namespace sict {

	// constructors implementation here

	Course::Course() {
		courseCode_[0] = '\0';
		courseTitle_ = nullptr;
		credits_ = -1;
		studyLoad_ = -1;
	}

	Course::Course(const char code[], const char* title, int credit, int load) {
        
		credits_ = credit;

		studyLoad_ = load;

		strcpy(courseCode_, code);
		if (title) {
			int i = strlen(title) + 1;
			courseTitle_ = new char[i];
			strcpy(courseTitle_, title);
		}
    }

	Course::Course(const Course& other) {
		*this = other;
	}

	Course::~Course() {
		delete [] courseTitle_;
		courseTitle_ = nullptr;
	}

	// setter functions are here

	void Course::setCourseCode(const char code[]) {
		if (strlen(code) <= MAX_COURSECODE_LEN) {
			strcpy(courseCode_, code);
		}
		else {
			courseCode_[0] = '\0';
		}
	}

	void Course::setCourseTitle(const char* title) {
		if (title != nullptr) {
			int i = strlen(title);
			courseTitle_ = new char[i + 1];
			strcpy(courseTitle_, title);
		}
		else {
			courseTitle_ = nullptr;
		}
	}

	void Course::setCredits(int credit) {
		credits_ = credit;
	}

	void Course::setStudyLoad(int load) {
		studyLoad_ = load;
	}

	// Getter functions are here

	const char* Course::getCourseCode() const {
		return courseCode_;
	}

	const char* Course::getCourseTitle() const {
		return courseTitle_;
	}

	const int Course::getCredits() const {
		return credits_;
	}

	const int Course::getStudyLoad() const {
		return studyLoad_;
	}

	// Empty state checker

	bool Course::isEmpty() const{

		
		if (courseCode_[0] == '\0' || courseTitle_ == nullptr || courseTitle_[0] == '\0' || credits_ == -1 || studyLoad_ == -1 || credits_ == 0 || studyLoad_ == 0) {
			
			return true;
		}
		else {
			return false;
		}
		
		
	}

	// member operators

	bool Course::operator==(const char* code) {
		if (strcmp(courseCode_, code) == 0) {
			return true;
		} else {
		
			return false;
		}
	}

	int Course::operator+=(int load) {
		studyLoad_ = studyLoad_ + load;
		return studyLoad_;
	}

	Course& Course::operator=(const Course& other) {
		if (this != &other) {
			if (other.courseTitle_ != nullptr) {

				int i = strlen(other.courseTitle_) + 1;

				if (courseTitle_ != nullptr) {
					delete[] courseTitle_;
				}
				courseTitle_ = new char[i];
				strcpy(courseTitle_, other.courseTitle_);
			}
			else {
				courseTitle_ = nullptr;
			}

			std::size_t i = 0;
			for (i = 0; i <= strlen(other.courseCode_); i++) {
				courseCode_[i] = other.courseCode_[i];
			}
			courseCode_[i + 1] = '\0';

			credits_ = other.credits_;

			studyLoad_ = other.studyLoad_;
		}
		
		return *this;
		
	}

	ostream& Course::display(std::ostream& os) const {

		os << std::setfill(' ') << std::left << std::setw(6) << getCourseCode() << "|";
		os << std::setfill(' ') << std::left << std::setw(40) << getCourseTitle() << "|";
		os << std::setfill(' ') << std::setw(9) << std::right << getCredits() << "|";
		os << std::setfill(' ') << std::setw(12) << std::right << getStudyLoad() << "|";

		return os;
	}

	std::ostream& operator<<(std::ostream& os, const Course& course) {

	    course.display(os);

		return os;
	}
	fstream& Course::store(fstream& fileStream, bool addNewLine) const{
		fileStream << getCourseCode()<<","
				   << getCourseTitle() << ","
			       << getCredits() << ","
			       << getStudyLoad();
		if (addNewLine){
			fileStream << endl;
		}
		return fileStream;
	}
	fstream& Course::load(fstream& file){

		return file;
	}
	istream& Course::read(istream& is){
		std::cout << "Course Code: ";
		char code[MAX_COURSECODE_LEN + 1];
		is.ignore();
		is.getline(code, 7);
		setCourseCode(code);

		std::cout << "Course Title: ";
		char course_title[200];
		is.getline(course_title, 200);
		setCourseTitle(course_title);

		std::cout << "Course Credit: ";
		int credit = 0;
		is >> credit;
		setCredits(credit);

		std::cout << "Study Load: ";
		int load = 0;
		is >> load;
		setStudyLoad(load);

		return is;
	}
}