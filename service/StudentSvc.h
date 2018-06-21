//StudentSvc接口
#include "..\domain\Student.h"

class StudentSvc{		//接口（抽象类） 
	
	public: 
		void addStudent(Student student);
		int removeStudent(std::string s_id);
		void modifyStudent(Student student);
		Student queryStudent(std::string s_id);
	
};
