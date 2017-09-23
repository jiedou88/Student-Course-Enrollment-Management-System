// OOP244 Milestone1
// File: ScmApp.h
// Version: 1.0
// Date: 2016/07/24
// Author: Jie Dou
// Description:
// 
/////////////////////////////////////////////

#ifndef SICT_SCMAPP_H_
#define SICT_SCMAPP_H_

#include <iostream>
#include "general.h"
#include "Course.h"
#include "ICTCourse.h"
#include "GenEdCourse.h"

namespace sict {

	class ScmApp {
		friend class ScmAppTester;
		Course* courseList_[MAX_NO_RECS];
		int noOfCourses_;
		char filename_[256];
		fstream dataFile_;
	public:
		// no argument constructor
		ScmApp();
		ScmApp(const char filename[256]);
		~ScmApp();
		int run();
	private:

		ScmApp(const ScmApp&)=delete;
		void pause() const;
		int menu();
		void listCourses() const;
		int searchACourse(const char* courseCode) const;
		void changeStudyLoad(const char* courseCode);
		void addACourse(int);
		void loadRecs();
		void saveRecs();
	};
}

#endif // !SICT_SCMAPP_H_
