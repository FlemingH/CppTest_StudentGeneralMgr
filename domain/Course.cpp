//课程类
#pragma once 
#include "stdafx.h"

class Course {
	private:
		std::string courseId;
		std::string courseCode;
		std::string courseName;
		std::string courseT;
	public:
		Course(){	//无参数的构造函数，令id为00000000 
			this->courseId = "00000000";
		}
		
		~Course(){}
		
		std::toString(){
			return 	"courseId："	+this->courseId		+","+
					"courseCode："	+this->courseCode	+","+
					"courseName："	+this->courseName	+","+
					"courseT："		+this->courseT;
		}
		
		void setCourseId(std::string courseId){
			this->courseId = courseId;
		}
		
		void setCourseCode(std::string courseCode){
			this->courseCode = courseCode;
		}
		
		void setCourseName(std::string courseName){
			this->courseName = courseName;
		}
		
		void setCourseT(std::string courseT){
			this->courseT = courseT;
		}
		
		std::string getCourseId(){
			return this->courseId;
		}
		
		std::string getCourseCode(){
			return this->courseCode;
		}
		
		std::string getCourseName(){
			return this->courseName;
		}
		
		std::string getCourseT(){
			return this->courseT;
		}
		
}; 
