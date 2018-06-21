//成绩类
#pragma once 
#include "stdafx.h"

class Score{
	private:
		std::string s_name;
		std::string courseName;
		std::string mark;
	public:
		Score(){	//无参数的构造函数，令mark为00000000 
			this->mark = "00000000";
		}
		
		~Score(){}
		
		std::string toString(){
			return 	"s_name："		+this->s_name		+","+
					"courseName："	+this->courseName	+","+
					"mark："		+this->mark;
		}
		
		void setS_name(std::string s_name){
			this->s_name = s_name;
		} 
		
		void setCourseName(std::string courseName){
			this->courseName = courseName;
		}
		
		void setMark(std::string mark){
			this->mark = mark;
		}
		
		std::string getS_name(){
			return this->s_name;
		}
		
		std::string getCourseName(){
			return this->courseName;
		}
		
		std::string getMark(){
			return this->mark;
		}
}; 
