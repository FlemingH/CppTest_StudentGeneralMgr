#include <iostream>  
#include <vector>  
#include <list>  
#include <deque>  
#include <string>  
#include <numeric>  
#include <algorithm>  
#include <sstream>
#include <map>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>
using namespace std;

class Course {
	private:
		string courseId;
		string courseCode;
		string courseName;
		string courseT;
	public:
		
		Course(){	//�޲����Ĺ��캯������idΪ00000000 
			this->courseId = "00000000";
		}
		
		~Course(){}
		
		string toString(){
			return 	"courseId��"	+this->courseId		+","+
					"courseCode��"	+this->courseCode	+","+
					"courseName��"	+this->courseName	+","+
					"courseT��"		+this->courseT;
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
		Score(){	//�޲����Ĺ��캯������markΪ00000000 
			this->mark = "00000000";
		}
		
		~Score(){}
		
		string toString(){
			return 	"s_name��"		+this->s_name		+","+
					"courseName��"	+this->courseName	+","+
					"mark��"		+this->mark;
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
		Student(){	//�޲����Ĺ��캯������idΪ00000000 
			this->s_id = "00000000";
		}
		
		~Student(){}
		
		string toString(){
			return 	"id��"		+this->s_id		+","+
					"name��"	+this->s_name	+","+
					"sex��"		+this->s_sex	+","+
					"class��"	+this->s_class; 
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

class CourseSvc{		//�γ̹���ӿڣ������ࣩ 
	
	public: 
		virtual void addCourse(Course course) = 0;
		virtual int removeCourse(string courseId) = 0;
		virtual void modifyCourse(Course course) = 0;
		virtual Course queryCourse(string courseId) = 0;
	
};

class ScoreSvc{			//�ɼ�����ӿڣ������ࣩ 
	
	public:
		virtual void addScore(Score score) = 0; 
		virtual int removeScore(string s_name, string courseName) = 0;
		virtual void modifyScore(Score course) = 0;
		virtual Score queryScore(string s_name, string courseName) = 0;
	
};

class StudentSvc{		//ѧ������ӿڣ������ࣩ 
	
	public: 
		virtual void addStudent(Student student) = 0;
		virtual int removeStudent(string s_id) = 0;
		virtual void modifyStudent(Student student) = 0;
		virtual Student queryStudent(string s_id) = 0;
	
};

//------------------------------------------------------------------------------

map<string, Course> courseMap;
map<string, string> scoreMap;
map<string, Student> studentMap;

//------------------------------------------------------------------------------

class CourseSvcImpl: public CourseSvc{
	
	public:
		void addCourse(Course course){
			courseMap[course.getCourseId()] = course;
		}
		
		int removeCourse(string courseId){
			//int����ֵΪɾ��״̬��ɾ���ɹ�����1�����򷵻�0��
			int n = courseMap.erase(courseId);
			
			return n; 
		} 
	
		void modifyCourse(Course course){			 
			//ֱ�ӵ���add����������id��������Զ����Ǽ�¼���ﵽ�޸ĵ�Ч�� 	
			this->addCourse(course);
			
		}
	
		Course queryCourse(string courseId){		
			
			Course courseDefault;
			
			map<string, Course>::iterator iter;
			for(iter = courseMap.begin(); iter != courseMap.end(); iter++) {
	    		
	    		if(string(iter->first) == string(courseId)){
	    			return iter->second;
	    			break;
	    		}
	    		
			}
			
			return courseDefault;
		}
	
};

//------------------------------------------------------------------------------

class ScoreSvcImpl: public ScoreSvc{
	
	public:
		void addScore(Score score){
			string info = score.getS_name()+"|"+score.getCourseName();
			scoreMap[info] = score.getMark();
		}
		
		int removeScore(string s_name, string courseName){
			
			string info = s_name+"|"+courseName;
			int n = scoreMap.erase(info);
		
			return 0;
		} 
	
		void modifyScore(Score score){			 
		 	
			this->addScore(score);
			
		}
	
		Score queryScore(string s_name, string courseName){		
			
			Score ScoreDefault;
			string info = s_name+"|"+courseName;
			
			map<string, string>::iterator iter;
			for(iter = scoreMap.begin(); iter != scoreMap.end(); iter++) {
	    		
	    		if(string(iter->first) == string(info)){
	    			ScoreDefault.setS_name(s_name);
	    			ScoreDefault.setCourseName(courseName);
	    			ScoreDefault.setMark(iter->second);
	    			return ScoreDefault;
	    			break;
	    		}
	    		
			}
			
			return ScoreDefault;
		}
	
};

//------------------------------------------------------------------------------

class StudentSvcImpl: public StudentSvc{
	
	public:
		void addStudent(Student student){
			studentMap[student.getS_id()] = student;
		}
		
		int removeStudent(string s_id){
			//int����ֵΪɾ��״̬��ɾ���ɹ�����1�����򷵻�0��
			int n = studentMap.erase(s_id);
			
			return n; 
		} 
	
		void modifyStudent(Student student){			 
			//ֱ�ӵ���add����������id��������Զ����Ǽ�¼���ﵽ�޸ĵ�Ч�� 	
			this->addStudent(student);
			
		}
	
		Student queryStudent(string s_id){		
			
			Student StudentDefault;
			
			map<string, Student>::iterator iter;
			for(iter = studentMap.begin(); iter != studentMap.end(); iter++) {
	    		
	    		if(string(iter->first) == string(s_id)){
	    			return iter->second;
	    			break;
	    		}
	    		
			}
			
			return StudentDefault;
		}
	
};

int main(){
	
	return 0;
}
