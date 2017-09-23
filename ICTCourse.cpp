// OOP244 Milestone2
// File: ICTCourse.cpp
// Version: 1.0
// Date: 2016/07/30
// Author: Jie Dou
// Description:
// 
/////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <iomanip>
#include "ICTCourse.h"
#include "general.h"

namespace sict {

	ICTCourse::ICTCourse() : Course() {

		strcpy(computerSystem_, "matrix");
	}

	ICTCourse::ICTCourse(const char code[], const char* title, int credit, int load, const char* other) : Course(code, title, credit, load) {

		strcpy(computerSystem_, other);
	}

	const char* ICTCourse::getComputerSystem() const {
		const char* computerSystem = computerSystem_;
		return computerSystem;
	}

	void ICTCourse::setComputerSystem(const char* value) {

		strncpy(computerSystem_, value, 6);
		computerSystem_[6] = '\0';
	}

	ostream& ICTCourse::display(std::ostream& os) const {

		Course::display(os);
		os << std::left << std::setw(8) << computerSystem_ << "|";
		os << std::right << std::setw(13) << std::setfill(' ') << "|"<<endl;
		return os;
	}

	std::ostream& operator << (std::ostream& os, const ICTCourse& course) {

		course.display(os);
		return os;
	}
	fstream& ICTCourse::store(fstream& fileStream, bool addNewLine) const{
		fileStream << TYPE_ICT<<","; 
		Course::store(fileStream, false);
		fileStream << "," << getComputerSystem();
		if (addNewLine){
			fileStream << endl;
		}
		return fileStream;
	}
	fstream& ICTCourse::load(fstream& file){
		
		char courseCode[6 + 1];
		char courseTitle[100];
		int credits;
		int studyLoad;
		char computerSystem[6 + 1];
		//read field one by one 
		// string line order: code,title,credits,studyLoad,system
		
		file.getline(courseCode, 7, ',');
		file.getline(courseTitle, 100, ',');
		file >> credits;
		file.ignore(1, ',');
		file >> studyLoad;
		file.ignore(1, ',');
		file.getline(computerSystem, 7);
		setCourseCode(courseCode);
		setCourseTitle(courseTitle);
		setCredits(credits);
		setStudyLoad(studyLoad);
		setComputerSystem(computerSystem);
		return file;
	}
	istream& ICTCourse::read(istream& is){
	Course::read(is);
		std::cout << "Computer System: ";
		char system_[6 + 1];
		is.ignore();
		is.getline(system_, 7);
		setComputerSystem(system_);
		return is;
	}

}   