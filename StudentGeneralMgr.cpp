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
			return 	"ѡ�α�ţ�"+this->courseId		+","+
					"�γ̴��룺"+this->courseCode	+","+
					"�γ����ƣ�"+this->courseName	+","+
					"�ον�ʦ��"+this->courseT;
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
			return 	"ѧ��������"+this->s_name		+","+
					"�γ̣�"	+this->courseName	+","+
					"�ɼ���"	+this->mark;
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
			return 	"ѧ�ţ�"+this->s_id		+","+
					"������"+this->s_name	+","+
					"�Ա�"+this->s_sex	+","+
					"�༶��"+this->s_class; 
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

void avgScore();
void hlScore();

//�ַ����ָ�� 
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

//ģ�庯������string���ͱ���ת��Ϊ���õ���ֵ���ͣ��˷��������ձ������ԣ�  
template <class Type>  
Type stringToNum(const string& str)  
{  
    istringstream iss(str);  
    Type num;  
    iss >> num;  
    return num;      
}  

//------------------------------------------------------------------------------

void zhuCaiDan(){
	
	system("cls"); 
	cout<<"\n\n\n";
	cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                     ��ҳ                        ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                  ��1.ѧ������                   ||"<<endl;  
    cout<<"\t||                  ��2.�γ̹���                   ||"<<endl;  
    cout<<"\t||                  ��3.�ɼ�����                   ||"<<endl;
    cout<<"\t||                  ��4.�ɼ�����                   ||"<<endl;  
    cout<<"\t||                  ��0.�˳�                       ||"<<endl;
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
              	scoreAys();
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
    cout<<"\t||                     ѧ������                    ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                  ��1.���ѧ��                   ||"<<endl;  
    cout<<"\t||                  ��2.��ѯѧ��                   ||"<<endl;  
    cout<<"\t||                  ��3.ȫ��ѧ����Ϣ���           ||"<<endl;  
    cout<<"\t||                  ��4.�޸�ѧ��                   ||"<<endl;  
    cout<<"\t||                  ��5.ɾ��ѧ��                   ||"<<endl;  
    cout<<"\t||                  ��6.���棨�ı��ļ���           ||"<<endl; 
	cout<<"\t||                  ��7.��ȡ���ݣ��ı��ļ���       ||"<<endl;
	cout<<"\t||                  ��0.����                       ||"<<endl;  
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
		cout<<"\n����ѧ����Ϣ��"<<endl;
		
		cout<<"����ѧ�ţ�";
		cin>>s_id;
		
		cout<<"����������"; 
		cin>>s_name; 
		
		cout<<"�����Ա�";
		cin>>s_sex;
		
		cout<<"����༶��";
		cin>>s_class;
	
		student.setS_id(s_id);
		student.setS_name(s_name);
		student.setS_sex(s_sex);
		student.setS_class(s_class);
		
		studentSvc.addStudent(student);
		
		cout<<"�������,�Ƿ��������,�� 0 ������,�����˳���"<<endl;    
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
		
		cout<<"\n\n����Ҫ��ѯѧ����ѧ�ţ�";
		cin>>s_id;
		student = studentSvc.queryStudent(s_id);
		
		if(student.getS_id() == "00000000"){
			cout<<"\n��ѯ��ѧ��������,�Ƿ������ѯ,�� 0 ������,�����˳���";
			flag = getch();
			fflush(stdin);
		} else {
			cout<<"\n"+student.toString()<<endl;
			cout<<"\n��ѯ����,�Ƿ������ѯ,�� 0 ������,�����˳���"<<endl;    
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
		
		cout<<"\n��ѯ����,����������˳���"<<endl;    
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
		
		cout<<"\n����Ҫ�޸�ѧ����ѧ�ţ�";
		cin>>s_id;
		
		student = studentSvc.queryStudent(s_id);
		
		if(student.getS_id() == "00000000"){
			cout<<"\n��Ҫ�޸ĵ�ѧ��������,�Ƿ�����޸�,�� 0 ������,�����˳���";
			flag = getch();
			fflush(stdin);
		} else {
			
			cout<<"\n\n����Ҫ�޸ĵ���Ϣ\n"<<endl;
			
			cout<<"�����޸ĺ��������"; 
			cin>>s_name; 
		
			cout<<"�����޸ĺ���Ա�";
			cin>>s_sex; 
		
			cout<<"�����޸ĺ�İ༶��";
			cin>>s_class;
			
			student.setS_id(s_id);
			student.setS_name(s_name);
			student.setS_sex(s_sex);
			student.setS_class(s_class);
			
			studentSvc.modifyStudent(student); 
			
			cout<<"\n�޸Ľ���,�Ƿ�����޸�,�� 0 ������,�����˳���"<<endl;    
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
		
		cout<<"\n\n����Ҫɾ��ѧ����id��";
		cin>>s_id;
		
		int n = studentSvc.removeStudent(s_id);
		
		if(n == 1){
			cout<<"\nɾ���ɹ�,�Ƿ����ɾ��,�� 0 ������,�����˳���"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		} else {
			cout<<"\nɾ��ʧ��,�Ƿ����ɾ��,�� 0 ������,�����˳���"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		}
			 
	}

	studentMgr();
	
};

//------------------------------------------------------------------------------

void studentFilei(){			//��ȡ���� 
	
	ifstream infile; 
	infile.open("data\\ѧ����Ϣ.txt",ios::in); 
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
		cout<<"��ȡ�ɹ�����������˳�"<<endl;    
        flag = getch();
        break; 
	}
	
	studentMgr();
	
};

//------------------------------------------------------------------------------

void studentFileo(){			//д������(д��֮ǰ����ļ�)
	
	ofstream ofile;
	ofile.open("data\\ѧ����Ϣ.txt", ios::out | ios::trunc );
	
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
		cout<<"д��ɹ�����������˳�"<<endl;    
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
    cout<<"\t||                     �γ̹���                    ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                  ��1.��ӿγ�                   ||"<<endl;  
    cout<<"\t||                  ��2.��ѯ�γ�                   ||"<<endl;  
    cout<<"\t||                  ��3.���пγ���Ϣ���           ||"<<endl;  
    cout<<"\t||                  ��4.�޸Ŀγ�                   ||"<<endl;  
    cout<<"\t||                  ��5.ɾ���γ�                   ||"<<endl;  
    cout<<"\t||                  ��6.���棨�ı��ļ���           ||"<<endl; 
	cout<<"\t||                  ��7.��ȡ���ݣ��ı��ļ���       ||"<<endl;
	cout<<"\t||                  ��0.����                       ||"<<endl;  
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
		cout<<"\n����γ���Ϣ��"<<endl;
		
		cout<<"����ѡ�α�ţ�";
		cin>>courseId;
		
		cout<<"����γ̴��룺"; 
		cin>>courseCode; 
		
		cout<<"����γ����ƣ�";
		cin>>courseName;
		
		cout<<"�����ο���ʦ��";
		cin>>courseT;
	
		course.setCourseId(courseId);
		course.setCourseCode(courseCode);
		course.setCourseName(courseName);
		course.setCourseT(courseT); 
		
		courseSvc.addCourse(course);
		
		cout<<"�������,�Ƿ��������,�� 0 ������,�����˳���"<<endl;    
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
		
		cout<<"\n\n����Ҫ��ѯ�γ̵�ѡ�α�ţ�";
		cin>>courseId;
		course = courseSvc.queryCourse(courseId);
		
		if(course.getCourseId() == "00000000"){
			cout<<"\n��ѯ�Ŀγ̲�����,�Ƿ������ѯ,�� 0 ������,�����˳���";
			flag = getch();
			fflush(stdin);
		} else {
			cout<<"\n"+course.toString()<<endl;
			cout<<"\n��ѯ����,�Ƿ������ѯ,�� 0 ������,�����˳���"<<endl;    
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
		
		cout<<"\n��ѯ����,����������˳���"<<endl;    
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
		
		cout<<"\n����Ҫ�޸Ŀγ̵�ѡ�α�ţ�";
		cin>>courseId;
		
		course = courseSvc.queryCourse(courseId);
		
		if(course.getCourseId() == "00000000"){
			cout<<"\n��Ҫ�޸ĵĿγ̲�����,�Ƿ�����޸�,�� 0 ������,�����˳���";
			flag = getch();
			fflush(stdin);
		} else {
			
			cout<<"\n\n����Ҫ�޸ĵ���Ϣ\n"<<endl;
			
			cout<<"�����޸ĺ�Ŀγ̴��룺"; 
			cin>>courseCode; 
		
			cout<<"�����޸ĺ�Ŀγ����ƣ�";
			cin>>courseName;
		
			cout<<"�����޸ĺ���ο���ʦ��";
			cin>>courseT;
			
			course.setCourseId(courseId);
			course.setCourseCode(courseCode);
			course.setCourseName(courseName);
			course.setCourseT(courseT);
			
			courseSvc.modifyCourse(course);
			
			cout<<"\n�޸Ľ���,�Ƿ�����޸�,�� 0 ������,�����˳���"<<endl;    
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
		
		cout<<"\n\n����Ҫɾ���γ̵�ѡ�α�ţ�";
		cin>>courseId;
		
		int n = courseSvc.removeCourse(courseId);
		
		if(n == 1){
			cout<<"\nɾ���ɹ�,�Ƿ����ɾ��,�� 0 ������,�����˳���"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		} else {
			cout<<"\nɾ��ʧ��,�Ƿ����ɾ��,�� 0 ������,�����˳���"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		}
			 
	}

	courseMgr();
	
};

//------------------------------------------------------------------------------ 

void courseFilei(){			//��ȡ���� 
	
	ifstream infile; 
	infile.open("data\\�γ���Ϣ.txt",ios::in); 
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
		cout<<"��ȡ�ɹ�����������˳�"<<endl;    
        flag = getch();
        break; 
	}
	
	courseMgr();
	
};

//------------------------------------------------------------------------------

void courseFileo(){			//д������(д��֮ǰ����ļ�)
	
	ofstream ofile;
	ofile.open("data\\�γ���Ϣ.txt", ios::out | ios::trunc );
	
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
		cout<<"д��ɹ�����������˳�"<<endl;    
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
    cout<<"\t||                     �ɼ�����                    ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                  ��1.��ӳɼ�                   ||"<<endl;  
    cout<<"\t||                  ��2.��ѯ�ɼ�                   ||"<<endl;
    cout<<"\t||                  ��3.�޸ĳɼ�                   ||"<<endl;  
    cout<<"\t||                  ��4.ɾ���ɼ�                   ||"<<endl;  
    cout<<"\t||                  ��5.���棨�ı��ļ���           ||"<<endl; 
	cout<<"\t||                  ��6.��ȡ���ݣ��ı��ļ���       ||"<<endl;
	cout<<"\t||                  ��0.����                       ||"<<endl;  
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
		cout<<"\n����ɼ���"<<endl;
		
		cout<<"����ѧ��������";
		cin>>s_name;
		
		cout<<"����γ����ƣ�"; 
		cin>>courseName; 
		
		cout<<"����÷֣�";
		cin>>mark;
	
		score.setS_name(s_name);
		score.setCourseName(courseName);
		score.setMark(mark);
		
		scoreSvc.addScore(score);
		
		cout<<"�������,�Ƿ��������,�� 0 ������,�����˳���"<<endl;    
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
		
		cout<<"\n\n����ѧ��������";
		cin>>s_name;
		cout<<"\n����γ����ƣ�";
		cin>>courseName;
		
		score = scoreSvc.queryScore(s_name, courseName);
		
		if(score.getMark() == "00000000"){
			cout<<"\n��ѯ�ĳɼ�������,�Ƿ������ѯ,�� 0 ������,�����˳���";
			flag = getch();
			fflush(stdin);
		} else {
			cout<<"\n�ɼ��ǣ�"+score.getMark()<<endl;
			cout<<"\n��ѯ����,�Ƿ������ѯ,�� 0 ������,�����˳���"<<endl;    
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
		
		cout<<"\n����Ҫ�޸ĳɼ���ѧ��������";
		cin>>s_name;
		cout<<"\n����Ҫ�޸ĳɼ��Ŀγ̣�"; 
		cin>>courseName;
		
		score = scoreSvc.queryScore(s_name, courseName);
		
		if(score.getMark() == "00000000"){
			cout<<"\n��Ҫ�޸ĵĳɼ�������,�Ƿ�����޸�,�� 0 ������,�����˳���";
			flag = getch();
			fflush(stdin);
		} else {
			
			cout<<"\n\n�����޸ĺ�ķ�����";
			cin>>mark;
			
			score.setS_name(s_name);
			score.setCourseName(courseName);
			score.setMark(mark); 
			
			scoreSvc.modifyScore(score);
			
			cout<<"\n�޸Ľ���,�Ƿ�����޸�,�� 0 ������,�����˳���"<<endl;    
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
		
		cout<<"\n\n����Ҫɾ���ɼ���ѧ��������";
		cin>>s_name;
		cout<<"\n����Ҫɾ���ɼ��Ŀγ����ƣ�";
		cin>>courseName; 
		
		int n = scoreSvc.removeScore(s_name, courseName);
		
		if(n == 1){
			cout<<"\nɾ���ɹ�,�Ƿ����ɾ��,�� 0 ������,�����˳���"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		} else {
			cout<<"\nɾ��ʧ��,�Ƿ����ɾ��,�� 0 ������,�����˳���"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		}
			 
	}

	scoreMgr();
	
};

//------------------------------------------------------------------------------

void scoreFilei(){			//��ȡ���� 
	
	ifstream infile; 
	infile.open("data\\�ɼ���Ϣ.txt",ios::in); 
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
		cout<<"��ȡ�ɹ�����������˳�"<<endl;    
        flag = getch();
        break; 
	}
	
	scoreMgr();
	
};

//------------------------------------------------------------------------------

void scoreFileo(){			//д������(д��֮ǰ����ļ�)
	
	ofstream ofile;
	ofile.open("data\\�ɼ���Ϣ.txt", ios::out | ios::trunc );
	string mark;
	
	char flag='0';
	while(true){
	
		map<string, string>::iterator iter;
		for(iter = scoreMap.begin(); iter != scoreMap.end(); iter++) {
			
			vector<string>tokens;
			Tokenize(iter->first, tokens, "|");
	
			ofile<<	tokens[0]	+ "\t"<<
					tokens[1]	+ "\t"<<
					iter->second+ "\t"<<endl;   		
		
		}
	
		ofile.close();
		cout<<"д��ɹ�����������˳�"<<endl;    
        flag = getch();
       	break; 
	}
	
	scoreMgr();
	
}; 

//------------------------------------------------------------------------------

void scoreAys(){
	
	system("cls"); 
	cout<<"\n\n\n";
	cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                     �ɼ�����                    ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t-----------------------------------------------------"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                                                 ||"<<endl;  
    cout<<"\t||                  ��1.ƽ����                     ||"<<endl;  
    cout<<"\t||                  ��2.���/�ͷ�                  ||"<<endl;
	cout<<"\t||                  ��0.����                       ||"<<endl;  
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
				avgScore(); 
                break;  
            case '2':  
           		hlScore();
                break;
			case '0':
				zhuCaiDan();
            default: 
				scoreAys();
                break;  
        }  
	} 
	
};

//------------------------------------------------------------------------------

void avgScore(){
	
	string courseName;
	vector<string>tokens;
	
	char flag='0';
	while(flag == '0'){
		stringstream ss;
		float sum = 0; 
		int count = 0; 
		
		cout<<"\n����Ҫ��ѯƽ���ֵĿγ����ƣ�";
		cin>>courseName; 
		
		map<string, string>::iterator iter;
		for(iter = scoreMap.begin(); iter != scoreMap.end(); iter++) {
	    		
	    	Tokenize(iter->first, tokens, "|");
	    	if(tokens[1] == courseName){
	    		sum = sum + stringToNum<float>(iter->second);
	    		count++;
	    	} 
	    	
		}
		 
		if(count == 0){
			cout<<"\n��ѯʧ��,�Ƿ������ѯ,�� 0 ������,�����˳���"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		} else {
			float avg = sum/count;
			string res;
		    ss << avg;
		    ss >> res;
			cout<<"\n"+courseName+"��ƽ�����ǣ�"+res<<endl;		
			cout<<"��ѯ�ɹ�,�Ƿ������ѯ,�� 0 ������,�����˳���"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		}
			 
	}
	
	scoreAys();
	
};

//------------------------------------------------------------------------------

void hlScore(){
	
	string courseName;
	vector<string>tokens; 
	
	char flag='0';
	while(flag == '0'){
		
		stringstream ss1;
		stringstream ss2;
		float max = 0;
		float min = 0; 
		int count = 0;
		
		cout<<"\n����Ҫ��ѯ���/�ͷֵĿγ����ƣ�";
		cin>>courseName; 
		
		map<string, string>::iterator iter;
		
		for(iter = scoreMap.begin(); iter != scoreMap.end(); iter++) {
			
			Tokenize(iter->first, tokens, "|");
	    	
			if(tokens[1] == courseName){
				max = stringToNum<float>(iter->second);
				min = stringToNum<float>(iter->second);
				break;
			}
			
		}
		
		for(iter = scoreMap.begin(); iter != scoreMap.end(); iter++) {
	    		
	    	Tokenize(iter->first, tokens, "|");
	    	
			if(tokens[1] == courseName){
	    		

	    		if(stringToNum<float>(iter->second) > max){
	    			max = stringToNum<float>(iter->second);
	    		}
	    		
	    		if(stringToNum<float>(iter->second) < min){
	    			min = stringToNum<float>(iter->second);
	    		} 
	    		
	    		count++; 
	    	} 
	    	
		}
		
		if(count == 0){
			cout<<"\n��ѯʧ��,�Ƿ������ѯ,�� 0 ������,�����˳���"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		} else {
			
			string res1;
			string res2;
		    
		    ss1 << max;
		    ss1 >> res1;
			ss2 << min;
			ss2 >> res2;
		
			cout<<"\n"+courseName+"����߷��ǣ�"+res1+"����ͷ��ǣ�"+res2<<endl;		
			cout<<"��ѯ�ɹ�,�Ƿ������ѯ,�� 0 ������,�����˳���"<<endl;    
        	flag = getch();                                         
        	fflush(stdin);
		}
			 
	}
	
	scoreAys();
	
};

int main(){
	
	zhuCaiDan();
	
	return 0;
}
