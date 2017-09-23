// OOP244 Milestone1
// File: Course.h
// Version: 1.0
// Date: 2016/07/24
// Author: Jie Dou
// Description:
// 
/////////////////////////////////////////////

#ifndef  SICT_COURSE_H_
#define  SICT_COURSE_H_

#include "general.h"
#include <iostream>
#include "Streamable.h"

namespace sict {

	class Course:public Streamable {

		friend class CourseTester;
		char courseCode_[MAX_COURSECODE_LEN + 1];
		char* courseTitle_;
		int credits_;
		int studyLoad_;

	public:
  
  //  constructors and destructor

		Course();
		Course(const char[], const char*, int, int);
		Course(const Course&);
		virtual ~Course();

  //  setter functions

		void setCourseCode(const char[]);
		void setCourseTitle(const char*);
		void setCredits(int);
		void setStudyLoad(int);

  //  getter functions

		const char* getCourseCode() const;
		const char* getCourseTitle() const;
		const int getCredits() const;
		const int getStudyLoad() const;

  //  Empty state checker

		bool isEmpty() const;

  //  Member operators

		bool operator==(const char*);
		int operator+=(int);
		Course& operator=(const Course&);

  // display function 

	    ostream& display(std::ostream&)const;
		fstream& store(fstream& fileStream, bool addNewLine) const;
		fstream& load(fstream& file);
		istream& read(istream& is);
	
	};

	std::ostream& operator<<(std::ostream& os, const Course& other);
}


#endif // ! SICT_COURSE_H_
