// OOP244 Milestone2
// File: GenEdCourse.cpp
// Version: 1.0
// Date: 2016/07/30
// Author: Jie Dou
// Description:
// 
/////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <iomanip>
#include "GenEdCourse.h"

namespace sict {

	GenEdCourse::GenEdCourse() : Course() {
		langLevel = 0;
	}

	GenEdCourse::GenEdCourse(const char code[], const char* title, int credit, int load, int langlevel_) : Course(code, title, credit, load) {
		langLevel = langlevel_;
	}

	int GenEdCourse::getLangLevel() const {
		return langLevel;
	}

	void GenEdCourse::setLangLevel(int lv) {
		langLevel = lv;
	}

	ostream& GenEdCourse::display(std::ostream& os) const {

		Course::display(os);
		os << std::right << std::setw(9) << std::setfill(' ') << "|";
		os << std::right << std::setw(12) << langLevel << "|"<<endl;
		return os;
	}

	std::ostream& operator<<(std::ostream& os, const GenEdCourse& course) {

		course.display(os);
		return os;
	}
	fstream& GenEdCourse::store(fstream& fileStream, bool addNewLine) const{
		fileStream << TYPE_GEN << ",";
		Course::store(fileStream, false);
		fileStream << "," << getLangLevel();
		if (addNewLine){
			fileStream << endl;
		}
		return fileStream;
	}
	fstream& GenEdCourse::load(fstream& file){
		char courseCode[6 + 1];
		char courseTitle[100];
		int credits = 0 ;
		int studyLoad = 0;
		int langLevel = 0;
		//read field one by one 
		// string order: code,title,credits,studyLoad,system
		
		file.getline(courseCode, 7, ',');
		file.getline(courseTitle, 100, ',');
		file >> credits;
		file.ignore(1, ',');
		file >> studyLoad;
		file.ignore(1, ',');
		file>>langLevel;
		setCourseCode(courseCode);
		setCourseTitle(courseTitle);
		setCredits(credits);
		setStudyLoad(studyLoad);
		setLangLevel(langLevel);
		return file;
	}
	istream& GenEdCourse::read(istream& is){
	Course::read(is);
		std::cout << "Language Requirement: ";
		int langreq = 0;
		std::cin >> langreq;
		setLangLevel(langreq);
		return is;
	}
}