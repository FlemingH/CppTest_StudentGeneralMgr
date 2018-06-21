//CourseSvc接口 
#include "..\domain\Course.h"

class CourseSvc{		//接口（抽象类） 
	
	public: 
		void addCourse(Course course);
		int removeCourse(std::string courseId);
		void modifyCourse(Course course);
		Course queryCourse(std::string courseId);
	
};
