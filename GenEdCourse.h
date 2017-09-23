// OOP244 Milestone2
// File: GenEdCourse.h
// Version: 1.0
// Date: 2016/07/30
// Author: Jie Dou
// Description:
// 
/////////////////////////////////////////////

#ifndef SICT_GENEDCOURSE_H_
#define SICT_GENEDCOURSE_H_
#include <iostream>
#include "Course.h"


namespace sict {

	class GenEdCourse : public Course {
		friend class GenEdCourseTester;
		int langLevel;

	public:

		GenEdCourse();
		GenEdCourse(const char[], const char*, int, int, int);

		int getLangLevel() const;
		void setLangLevel(int);
		
		ostream& display(std::ostream&)const;
		fstream& store(fstream& fileStream, bool addNewLine) const;
		fstream& load(fstream& file);
		istream& read(istream& is);
		

	};

	std::ostream& operator<<(std::ostream& os, const GenEdCourse& other);
}


#endif 
