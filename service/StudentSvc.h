//StudentSvc�ӿ�
#include "..\domain\Student.h"

class StudentSvc{		//�ӿڣ������ࣩ 
	
	public: 
		void addStudent(Student student);
		int removeStudent(std::string s_id);
		void modifyStudent(Student student);
		Student queryStudent(std::string s_id);
	
};
