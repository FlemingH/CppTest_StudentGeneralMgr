#include <iostream>
#include <string>
using namespace std;

class Course {
	private:
		string courseId;
		string courseCode;
		string courseName;
		string courseT;
	public:
		
		Course(){	//无参数的构造函数，令id为00000000 
			this->courseId = "00000000";
		}
		
		~Course(){}
		
		string toString(){
			return 	"courseId："	+this->courseId		+","+
				"courseCode："	+this->courseCode	+","+
				"courseName："	+this->courseName	+","+
				"courseT："	+this->courseT;
		}
		
		void setCourseId(string courseId){
			this->courseId = courseId;
		}
		
		void setCourseCode(string courseCode){
			this->courseCode = courseCode;
		}
		
		void setCourseName(string courseName){
			this->courseName = courseName;
		}
		
		void setCourseT(string courseT){
			this->courseT = courseT;
		}
		
		string getCourseId(){
			return this->courseId;
		}
		
		string getCourseCode(){
			return this->courseCode;
		}
		
		string getCourseName(){
			return this->courseName;
		}
		
		string getCourseT(){
			return this->courseT;
		}
		
}; 

//------------------------------------------------------------------------------

class Score{
	private:
		string s_name;
		string courseName;
		string mark;
	public:
		Score(){	//无参数的构造函数，令mark为00000000 
			this->mark = "00000000";
		}
		
		~Score(){}
		
		string toString(){
			return 	"s_name："		+this->s_name		+","+
				"courseName："		+this->courseName	+","+
				"mark："		+this->mark;
		}
		
		void setS_name(string s_name){
			this->s_name = s_name;
		} 
		
		void setCourseName(string courseName){
			this->courseName = courseName;
		}
		
		void setMark(string mark){
			this->mark = mark;
		}
		
		string getS_name(){
			return this->s_name;
		}
		
		string getCourseName(){
			return this->courseName;
		}
		
		string getMark(){
			return this->mark;
		}
}; 

//------------------------------------------------------------------------------

class Student{
	private:
		string s_id;
		string s_name;
		string s_sex;
		string s_class;
	public:
		Student(){	//无参数的构造函数，令id为00000000 
			this->s_id = "00000000";
		}
		
		~Student(){}
		
		string toString(){
			return 	"id："		+this->s_id		+","+
				"name："	+this->s_name		+","+
				"sex："		+this->s_sex		+","+
				"class："	+this->s_class; 
		}
		
		void setS_id(string s_id){
			this->s_id = s_id;
		} 
		
		void setS_name(string s_name){
			this->s_name = s_name;
		}
		
		void setS_sex(string s_sex){
			this->s_sex = s_sex;
		}
		
		void setS_class(string s_class){
			this->s_class = s_class;
		}
		
		string getS_id(){
			return this->s_id;
		} 
		
		string getS_name(){
			return this->s_name;
		} 
		
		string getS_sex(){
			return this->s_sex;
		} 
		
		string getS_class(){
			return this->s_class;
		} 
};

//------------------------------------------------------------------------------

class CourseSvc{		//课程管理接口（抽象类） 
	
	public: 
		virtual void addCourse(Course course) = 0;
		virtual int removeCourse(string courseId) = 0;
		virtual void modifyCourse(Course course) = 0;
		virtual Course queryCourse(string courseId) = 0;
	
};

class ScoreSvc{			//成绩管理接口（抽象类） 
	
	public:
		virtual void addScore(Score score) = 0; 
		virtual int removeScore(string s_name, string courseName) = 0;
		virtual void modifyScore(Score course) = 0;
		virtual Score queryScore(string s_name, string courseName) = 0;
	
};

class StudentSvc{		//学生管理接口（抽象类） 
	
	public: 
		virtual void addStudent(Student student) = 0;
		virtual int removeStudent(string s_id) = 0;
		virtual void modifyStudent(Student student) = 0;
		virtual Student queryStudent(string s_id) = 0;
	
};

//------------------------------------------------------------------------------

int main(){
	return 0;
}
