//CourseSvc�ӿ� 
#include "..\domain\Course.h"

class CourseSvc{		//�ӿڣ������ࣩ 
	
	public: 
		void addCourse(Course course);
		int removeCourse(std::string courseId);
		void modifyCourse(Course course);
		Course queryCourse(std::string courseId);
	
};
