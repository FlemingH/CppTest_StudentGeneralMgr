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
		
		Course(){	//无参数的构造函数，令id为00000000 
			this->courseId = "00000000";
		}
		
		~Course(){}
		
		string toString(){
			return 	"选课编号："+this->courseId		+","+
					"课程代码："+this->courseCode	+","+
					"课程名称："+this->courseName	+","+
					"任课教师："+this->courseT;
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
			return 	"学生姓名："+this->s_name		+","+
					"课程："	+this->courseName	+","+
					"成绩："	+this->mark;
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
			return 	"学号："+this->s_id		+","+
					"姓名："+this->s_name	+","+
					"性别："+this->s_sex	+","+
					"班级："+this->s_class; 
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
			//int返回值为删除状态（删除成功返回1，否则返回0）
			int n = courseMap.erase(courseId);
			
			return n; 
		} 
	
		void modifyCourse(Course course){			 
			//直接调用add方法，不改id的情况下自动覆盖记录，达到修改的效果 	
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
		
			return n;
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
			//int返回值为删除状态（删除成功返回1，否则返回0）
			int n = studentMap.erase(s_id);
			
			return n; 
		} 
	
		void modifyStudent(Student student){			 
			//直接调用add方法，不改id的情况下自动覆盖记录，达到修改的效果 	
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

//------------------------------------------------------------------------------

void studentMgr();
void courseMgr();
void scoreMgr();
void scoreAys(); 

void studentAdd(); 
void studentQuery();
void studentQueryAll();
void studentModify();
void studentRemove();
void studentFileo();
void studentFilei();

void courseAdd(); 
void courseQuery();
void courseQueryAll();
void courseModify();
void courseRemove();
void courseFileo();
void courseFilei();

void scoreAdd(); 
void scoreQuery();
void scoreModify();
void scoreRemove();
void scoreFileo();
void scoreFilei();

//字符串分割函数 
void Tokenize(const string& str, vector<string>& tokens, const string& delimiters)
{
  // Skip delimiters at beginning.
  string::size_type lastPos = str.find_first_not_of(delimiters, 0);
  // Find first "non-delimiter".
  string::size_type pos     = str.find_first_of(delimiters, lastPos);
  while (string::npos != pos || string::npos != lastPos)
  {
    // Found a token, add it to the vector.
    tokens.push_back(str.substr(lastPos, pos - lastPos));
    // Skip delimiters.  Note the "not_of"
    lastPos = str.find_first_not_of(delimiters, pos);
    // Find next "non-delimiter"
    pos = str.find_first_of(delimiters, lastPos);
  }
}

void zhuCaiDan(){
	
	system("cls"); 
	cout<<"\n\n\n";
	cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                     首页                        ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                  ◆1.学生管理                   ||"<<endl;  
    cout<<"\t||                  ◆2.课程管理                   ||"<<endl;  
    cout<<"\t||                  ◆3.成绩管理                   ||"<<endl;
    cout<<"\t||                  ◆4.成绩分析                   ||"<<endl;  
    cout<<"\t||                  ◆0.退出                       ||"<<endl;
	cout<<"\t||                                                 ||"<<endl;
	cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
	cout<<"\t-----------------------------------------------------"<<endl; 
	
	char x;      
    bool flag = true;  
    while(flag)  
    {                      
        x = getch();  
        system("cls");  
        fflush(stdin);  
        switch(x)  
        {  
            case '1':  
				studentMgr(); 
                break;  
            case '2':  
           		courseMgr();
                break;  
            case '3':  
            	scoreMgr();
                break;  
            case '4':  
              	//scoreAys();
                break;  
			case '0':
				exit(0);
            default: 
				zhuCaiDan();  
                break;  
        }  
	} 
	
};

//------------------------------------------------------------------------------

void studentMgr(){
	
	system("cls"); 
	cout<<"\n\n\n";
	cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                     学生管理                    ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                  ◆1.添加学生                   ||"<<endl;  
    cout<<"\t||                  ◆2.查询学生                   ||"<<endl;  
    cout<<"\t||                  ◆3.全体学生信息浏览           ||"<<endl;  
    cout<<"\t||                  ◆4.修改学生                   ||"<<endl;  
    cout<<"\t||                  ◆5.删除学生                   ||"<<endl;  
    cout<<"\t||                  ◆6.保存（文本文件）           ||"<<endl; 
	cout<<"\t||                  ◆7.读取数据（文本文件）       ||"<<endl;
	cout<<"\t||                  ◆0.返回                       ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
	cout<<"\t-----------------------------------------------------"<<endl; 
	
	char x;      
    bool flag = true;  
    while(flag)  
    {                      
        x = getch();  
        system("cls");  
        fflush(stdin);  
        switch(x)  
        {  
            case '1':  
				studentAdd();
                break;  
            case '2':  
           		studentQuery();
                break;  
            case '3':  
            	studentQueryAll();
                break;  
            case '4':  
              	studentModify();  
                break;  
            case '5':  
                studentRemove();
                break; 
			case '6':
				studentFileo(); 
				break;
			case '7':
				studentFilei();
				break;
			case '0':
				zhuCaiDan();
            default: 
				studentMgr(); 
                break;  
        }  
	} 
	
};

//------------------------------------------------------------------------------

void studentAdd(){
	Student student;
	StudentSvcImpl studentSvc;
	string s_id;
	string s_name;
	string s_sex;
	string s_class;
	
	char flag='0';
	while(flag == '0'){
		cout<<"\n输入学生信息："<<endl;
		
		cout<<"输入学号：";
		cin>>s_id;
		
		cout<<"输入姓名："; 
		cin>>s_name; 
		
		cout<<"输入性别：";
		cin>>s_sex;
		
		cout<<"输入班级：";
		cin>>s_class;
	
		student.setS_id(s_id);
		student.setS_name(s_name);
		student.setS_sex(s_sex);
		student.setS_class(s_class);
		
		studentSvc.addStudent(student);
		
		cout<<"输入结束,是否继续输入,按 0 键继续,否则退出。"<<endl;    
        flag = getch();                                         
        fflush(stdin);
	}
	
	studentMgr();
	
}; 

//------------------------------------------------------------------------------

void studentQuery(){
	
	string s_id;
	Student student;
	StudentSvcImpl studentSvc;
	
	char flag='0';
	while(flag == '0'){
		
		cout<<"\n\n输入要查询学生的学号：";
		cin>>s_id;
		student = studentSvc.queryStudent(s_id);
		
		if(student.getS_id() == "00000000"){
			cout<<"\n查询的学生不存在,是否继续查询,按 0 键继续,否则退出。";
			flag = getch();
			fflush(stdin);
		} else {
			cout<<"\n"+student.toString()<<endl;
			cout<<"\n查询结束,是否继续查询,按 0 键继续,否则退出。"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		}
		
	}
	
	studentMgr();
	
};

//------------------------------------------------------------------------------

void studentQueryAll(){
		
	char flag;
	while(true){
		
		map<string, Student>::iterator iter;
		for(iter = studentMap.begin(); iter != studentMap.end(); iter++) {
			cout<<"\n"+iter->second.toString()<<endl;   		
		}
		
		cout<<"\n查询结束,输入任意键退出。"<<endl;    
        flag = getch();                                         
        break; 
	} 
	
	studentMgr(); 
	
};

//------------------------------------------------------------------------------

void studentModify(){
	
	string s_id;
	string s_name;
	string s_sex;
	string s_class;
	
	Student student;
	StudentSvcImpl studentSvc;
	
	char flag='0';
	while(flag == '0'){
		
		cout<<"\n输入要修改学生的学号：";
		cin>>s_id;
		
		student = studentSvc.queryStudent(s_id);
		
		if(student.getS_id() == "00000000"){
			cout<<"\n想要修改的学生不存在,是否继续修改,按 0 键继续,否则退出。";
			flag = getch();
			fflush(stdin);
		} else {
			
			cout<<"\n\n输入要修改的信息\n"<<endl;
			
			cout<<"输入修改后的姓名："; 
			cin>>s_name; 
		
			cout<<"输入修改后的性别：";
			cin>>s_sex; 
		
			cout<<"输入修改后的班级：";
			cin>>s_class;
			
			student.setS_id(s_id);
			student.setS_name(s_name);
			student.setS_sex(s_sex);
			student.setS_class(s_class);
			
			studentSvc.modifyStudent(student); 
			
			cout<<"\n修改结束,是否继续修改,按 0 键继续,否则退出。"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		}
		
	} 
	
	studentMgr();
	
};

//------------------------------------------------------------------------------ 

void studentRemove(){
	
	string s_id;	
	StudentSvcImpl studentSvc;
	
	char flag='0';
	while(flag == '0'){
		
		cout<<"\n\n输入要删除学生的id：";
		cin>>s_id;
		
		int n = studentSvc.removeStudent(s_id);
		
		if(n == 1){
			cout<<"\n删除成功,是否继续删除,按 0 键继续,否则退出。"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		} else {
			cout<<"\n删除失败,是否继续删除,按 0 键继续,否则退出。"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		}
			 
	}

	studentMgr();
	
};

//------------------------------------------------------------------------------

void studentFilei(){			//读取数据 
	
	ifstream infile; 
	infile.open("data\\学生信息.txt",ios::in); 
	string s;
	
	string s_id;
	string s_name;
	string s_sex;
	string s_class;
	
	Student student;
	StudentSvcImpl studentSvc;
	
	char flag='0';
	while(true){
		
		while(getline(infile,s)){
			
			istringstream ss(s);
			
			ss>>s_id;
			ss>>s_name;
			ss>>s_sex;
			ss>>s_class;
			
			student.setS_id(s_id);
			student.setS_name(s_name);
			student.setS_sex(s_sex);
			student.setS_class(s_class);
			
			studentSvc.addStudent(student);
		}
		
		infile.close();
		cout<<"读取成功，按任意键退出"<<endl;    
        flag = getch();
        break; 
	}
	
	studentMgr();
	
};

//------------------------------------------------------------------------------

void studentFileo(){			//写入数据(写入之前清空文件)
	
	ofstream ofile;
	ofile.open("data\\学生信息.txt", ios::out | ios::trunc );
	
	char flag='0';
	while(true){
	
		map<string, Student>::iterator iter;
		for(iter = studentMap.begin(); iter != studentMap.end(); iter++) {
			
			ofile<<	iter->second.getS_id() 		+ "\t"<<
					iter->second.getS_name() 	+ "\t"<<
					iter->second.getS_sex() 	+ "\t"<<
					iter->second.getS_class() 	+ "\t"<<endl;   		
		
		}
	
		ofile.close();
		cout<<"写入成功，按任意键退出"<<endl;    
        flag = getch();
       	break; 
	}
	
	studentMgr(); 
	
};

//------------------------------------------------------------------------------

void courseMgr(){
	
	system("cls"); 
	cout<<"\n\n\n";
	cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                     课程管理                    ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                  ◆1.添加课程                   ||"<<endl;  
    cout<<"\t||                  ◆2.查询课程                   ||"<<endl;  
    cout<<"\t||                  ◆3.所有课程信息浏览           ||"<<endl;  
    cout<<"\t||                  ◆4.修改课程                   ||"<<endl;  
    cout<<"\t||                  ◆5.删除课程                   ||"<<endl;  
    cout<<"\t||                  ◆6.保存（文本文件）           ||"<<endl; 
	cout<<"\t||                  ◆7.读取数据（文本文件）       ||"<<endl;
	cout<<"\t||                  ◆0.返回                       ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
	cout<<"\t-----------------------------------------------------"<<endl; 
	
	char x;      
    bool flag = true;  
    while(flag)  
    {                      
        x = getch();  
        system("cls");  
        fflush(stdin);  
        switch(x)  
        {  
            case '1':  
				courseAdd();
                break;  
            case '2':  
           		courseQuery();
                break;  
            case '3':  
            	courseQueryAll();
                break;  
            case '4':  
              	courseModify();  
                break;  
            case '5':  
                courseRemove();
                break; 
			case '6':
				courseFileo(); 
				break;
			case '7':
				courseFilei();
				break;
			case '0':
				zhuCaiDan();
            default: 
				courseMgr(); 
                break;  
        }  
	} 
	
}; 

//------------------------------------------------------------------------------

void courseAdd(){
	CourseSvcImpl courseSvc;
	Course course;
	string courseId;
	string courseCode;
	string courseName;
	string courseT;
	
	char flag='0';
	while(flag == '0'){
		cout<<"\n输入课程信息："<<endl;
		
		cout<<"输入选课编号：";
		cin>>courseId;
		
		cout<<"输入课程代码："; 
		cin>>courseCode; 
		
		cout<<"输入课程名称：";
		cin>>courseName;
		
		cout<<"输入任课老师：";
		cin>>courseT;
	
		course.setCourseId(courseId);
		course.setCourseCode(courseCode);
		course.setCourseName(courseName);
		course.setCourseT(courseT); 
		
		courseSvc.addCourse(course);
		
		cout<<"输入结束,是否继续输入,按 0 键继续,否则退出。"<<endl;    
        flag = getch();                                         
        fflush(stdin);
	}
	
	courseMgr();
	
}; 

//------------------------------------------------------------------------------

void courseQuery(){
	
	string courseId;
	Course course;
	CourseSvcImpl courseSvc;
	
	char flag='0';
	while(flag == '0'){
		
		cout<<"\n\n输入要查询课程的选课编号：";
		cin>>courseId;
		course = courseSvc.queryCourse(courseId);
		
		if(course.getCourseId() == "00000000"){
			cout<<"\n查询的课程不存在,是否继续查询,按 0 键继续,否则退出。";
			flag = getch();
			fflush(stdin);
		} else {
			cout<<"\n"+course.toString()<<endl;
			cout<<"\n查询结束,是否继续查询,按 0 键继续,否则退出。"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		}
		
	}
	
	courseMgr();
	
};

//------------------------------------------------------------------------------

void courseQueryAll(){
		
	char flag;
	while(true){
		
		map<string, Course>::iterator iter;
		for(iter = courseMap.begin(); iter != courseMap.end(); iter++) {
			cout<<"\n"+iter->second.toString()<<endl;   		
		}
		
		cout<<"\n查询结束,输入任意键退出。"<<endl;    
        flag = getch();                                         
        break; 
	} 
	
	courseMgr();
	
};

//------------------------------------------------------------------------------

void courseModify(){
	
	string courseId;
	string courseCode;
	string courseName;
	string courseT;
	
	Course course; 
	CourseSvcImpl courseSvc;
	
	char flag='0';
	while(flag == '0'){
		
		cout<<"\n输入要修改课程的选课编号：";
		cin>>courseId;
		
		course = courseSvc.queryCourse(courseId);
		
		if(course.getCourseId() == "00000000"){
			cout<<"\n想要修改的课程不存在,是否继续修改,按 0 键继续,否则退出。";
			flag = getch();
			fflush(stdin);
		} else {
			
			cout<<"\n\n输入要修改的信息\n"<<endl;
			
			cout<<"输入修改后的课程代码："; 
			cin>>courseCode; 
		
			cout<<"输入修改后的课程名称：";
			cin>>courseName;
		
			cout<<"输入修改后的任课老师：";
			cin>>courseT;
			
			course.setCourseId(courseId);
			course.setCourseCode(courseCode);
			course.setCourseName(courseName);
			course.setCourseT(courseT);
			
			courseSvc.modifyCourse(course);
			
			cout<<"\n修改结束,是否继续修改,按 0 键继续,否则退出。"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		}
		
	} 
	
	courseMgr();
	
};

//------------------------------------------------------------------------------

void courseRemove(){
	
	string courseId;	
	CourseSvcImpl courseSvc;
	
	char flag='0';
	while(flag == '0'){
		
		cout<<"\n\n输入要删除课程的选课编号：";
		cin>>courseId;
		
		int n = courseSvc.removeCourse(courseId);
		
		if(n == 1){
			cout<<"\n删除成功,是否继续删除,按 0 键继续,否则退出。"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		} else {
			cout<<"\n删除失败,是否继续删除,按 0 键继续,否则退出。"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		}
			 
	}

	courseMgr();
	
};

//------------------------------------------------------------------------------ 

void courseFilei(){			//读取数据 
	
	ifstream infile; 
	infile.open("data\\课程信息.txt",ios::in); 
	string s;
	
	string courseId;
	string courseCode;
	string courseName;
	string courseT;
	
	Course course; 
	CourseSvcImpl courseSvc;
	
	char flag='0';
	while(true){
		
		while(getline(infile,s)){
			
			istringstream ss(s);
			
			ss>>courseId;
			ss>>courseCode;
			ss>>courseName;
			ss>>courseT;
			
			course.setCourseId(courseId);
			course.setCourseCode(courseCode);
			course.setCourseName(courseName);
			course.setCourseT(courseT);
			
			courseSvc.addCourse(course);
		}
		
		infile.close();
		cout<<"读取成功，按任意键退出"<<endl;    
        flag = getch();
        break; 
	}
	
	courseMgr();
	
};

//------------------------------------------------------------------------------

void courseFileo(){			//写入数据(写入之前清空文件)
	
	ofstream ofile;
	ofile.open("data\\课程信息.txt", ios::out | ios::trunc );
	
	char flag='0';
	while(true){
	
		map<string, Course>::iterator iter;
		for(iter = courseMap.begin(); iter != courseMap.end(); iter++) {
			
			ofile<<	iter->second.getCourseId() 		+ "\t"<<
					iter->second.getCourseCode()	+ "\t"<<
					iter->second.getCourseName() 	+ "\t"<<
					iter->second.getCourseT() 		+ "\t"<<endl;   		
		
		}
	
		ofile.close();
		cout<<"写入成功，按任意键退出"<<endl;    
        flag = getch();
       	break; 
	}
	
	courseMgr();
	
}; 

//------------------------------------------------------------------------------ 

void scoreMgr(){
	
	system("cls"); 
	cout<<"\n\n\n";
	cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                     成绩管理                    ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                  ◆1.添加成绩                   ||"<<endl;  
    cout<<"\t||                  ◆2.查询成绩                   ||"<<endl;
    cout<<"\t||                  ◆3.修改成绩                   ||"<<endl;  
    cout<<"\t||                  ◆4.删除成绩                   ||"<<endl;  
    cout<<"\t||                  ◆5.保存（文本文件）           ||"<<endl; 
	cout<<"\t||                  ◆6.读取数据（文本文件）       ||"<<endl;
	cout<<"\t||                  ◆0.返回                       ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
	cout<<"\t-----------------------------------------------------"<<endl; 
	
	char x;      
    bool flag = true;  
    while(flag)  
    {                      
        x = getch();  
        system("cls");  
        fflush(stdin);  
        switch(x)  
        {  
            case '1':  
				scoreAdd();
                break;  
            case '2':  
           		scoreQuery();
                break;
            case '3':  
              	scoreModify();  
                break;  
            case '4':  
                scoreRemove();
                break; 
			case '5':
				scoreFileo(); 
				break;
			case '6':
				scoreFilei();
				break;
			case '0':
				zhuCaiDan();
            default: 
				scoreMgr();
                break;  
        }  
	} 
	
};

//------------------------------------------------------------------------------

void scoreAdd(){
	ScoreSvcImpl scoreSvc;
	Score score;
	string s_name;
	string courseName;
	string mark;
	
	char flag='0';
	while(flag == '0'){
		cout<<"\n输入成绩："<<endl;
		
		cout<<"输入学生姓名：";
		cin>>s_name;
		
		cout<<"输入课程名称："; 
		cin>>courseName; 
		
		cout<<"输入得分：";
		cin>>mark;
	
		score.setS_name(s_name);
		score.setCourseName(courseName);
		score.setMark(mark);
		
		scoreSvc.addScore(score);
		
		cout<<"输入结束,是否继续输入,按 0 键继续,否则退出。"<<endl;    
        flag = getch();                                         
        fflush(stdin);
	}
	
	scoreMgr();
	
}; 

//------------------------------------------------------------------------------

void scoreQuery(){
	
	string s_name;
	string courseName; 
	Score score;
	ScoreSvcImpl scoreSvc;
	
	char flag='0';
	while(flag == '0'){
		
		cout<<"\n\n输入学生姓名：";
		cin>>s_name;
		cout<<"\n输入课程名称：";
		cin>>courseName;
		
		score = scoreSvc.queryScore(s_name, courseName);
		
		if(score.getMark() == "00000000"){
			cout<<"\n查询的成绩不存在,是否继续查询,按 0 键继续,否则退出。";
			flag = getch();
			fflush(stdin);
		} else {
			cout<<"\n成绩是："+score.getMark()<<endl;
			cout<<"\n查询结束,是否继续查询,按 0 键继续,否则退出。"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		}
		
	}
	
	scoreMgr();
	
};

void scoreModify(){
	
	string s_name;
	string courseName;
	string mark;
	
	Score score;
	ScoreSvcImpl scoreSvc;
	
	char flag='0';
	while(flag == '0'){
		
		cout<<"\n输入要修改成绩的学生姓名：";
		cin>>s_name;
		cout<<"\n输入要修改成绩的课程："; 
		cin>>courseName;
		
		score = scoreSvc.queryScore(s_name, courseName);
		
		if(score.getMark() == "00000000"){
			cout<<"\n想要修改的成绩不存在,是否继续修改,按 0 键继续,否则退出。";
			flag = getch();
			fflush(stdin);
		} else {
			
			cout<<"\n\n输入修改后的分数：";
			cin>>mark;
			
			score.setS_name(s_name);
			score.setCourseName(courseName);
			score.setMark(mark); 
			
			scoreSvc.modifyScore(score);
			
			cout<<"\n修改结束,是否继续修改,按 0 键继续,否则退出。"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		}
		
	} 
	
	scoreMgr();
	
};

//------------------------------------------------------------------------------

void scoreRemove(){
	
	string s_name;
	string courseName;
	ScoreSvcImpl scoreSvc;
	
	char flag='0';
	while(flag == '0'){
		
		cout<<"\n\n输入要删除成绩的学生姓名：";
		cin>>s_name;
		cout<<"\n输入要删除成绩的课程名称：";
		cin>>courseName; 
		
		int n = scoreSvc.removeScore(s_name, courseName);
		
		if(n == 1){
			cout<<"\n删除成功,是否继续删除,按 0 键继续,否则退出。"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		} else {
			cout<<"\n删除失败,是否继续删除,按 0 键继续,否则退出。"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		}
			 
	}

	scoreMgr();
	
};

//------------------------------------------------------------------------------

void scoreFilei(){			//读取数据 
	
	ifstream infile; 
	infile.open("data\\成绩信息.txt",ios::in); 
	string s;
	
	string s_name;
	string courseName;
	string mark;
	
	Score score; 
	ScoreSvcImpl scoreSvc;
	
	char flag='0';
	while(true){
		
		while(getline(infile,s)){
			
			istringstream ss(s);
			
			ss>>s_name;
			ss>>courseName;
			ss>>mark;
			
			score.setS_name(s_name);
			score.setCourseName(courseName);
			score.setMark(mark);
			
			scoreSvc.addScore(score);
		}
		
		infile.close();
		cout<<"读取成功，按任意键退出"<<endl;    
        flag = getch();
        break; 
	}
	
	scoreMgr();
	
};

//------------------------------------------------------------------------------

void scoreFileo(){			//写入数据(写入之前清空文件)
	
	ofstream ofile;
	ofile.open("data\\成绩信息.txt", ios::out | ios::trunc );
	vector<string>tokens;
	string mark;
	
	char flag='0';
	while(true){
	
		map<string, string>::iterator iter;
		for(iter = scoreMap.begin(); iter != scoreMap.end(); iter++) {
			
			Tokenize(iter->first, tokens, "|");
	
			ofile<<	tokens[0]	+ "\t"<<
					tokens[1]	+ "\t"<<
					iter->second+ "\t"<<endl;   		
		
		}
	
		ofile.close();
		cout<<"写入成功，按任意键退出"<<endl;    
        flag = getch();
       	break; 
	}
	
	scoreMgr();
	
}; 

//------------------------------------------------------------------------------

int main(){
	
	zhuCaiDan();
	
	return 0;
}
