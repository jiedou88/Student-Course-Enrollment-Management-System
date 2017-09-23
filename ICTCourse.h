// OOP244 Milestone2
// File: ICTCourse.h
// Version: 1.0
// Date: 2016/07/30
// Author: Jie Dou
// Description:
// 
/////////////////////////////////////////////

#ifndef SICT_ICTCOURSE_H_
#define SICT_ICTCOURSE_H_

#include <iostream>
#include "Course.h"

namespace sict {
	 
	class ICTCourse : public Course {
		friend class ICTCourseTester;
		char computerSystem_[6 + 1];

		public:
			ICTCourse(const char[], const char*, int, int, const char*);
			ICTCourse();
			const char* getComputerSystem() const;
			void setComputerSystem(const char* value);
			virtual ostream& display(std::ostream&)const;
			fstream& store(fstream& fileStream, bool addNewLine) const;
			fstream& load(fstream& file) ;
			istream& read(istream& is) ;

	};

	std::ostream& operator<<(std::ostream& os, const ICTCourse& other);
	
}



#endif // !