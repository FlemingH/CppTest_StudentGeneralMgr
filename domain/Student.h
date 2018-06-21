//学生类

class Student{
	private:
		std::string s_id;
		std::string s_name;
		std::string s_sex;
		std::string s_class;
	public:
		Student(){	//无参数的构造函数，令id为00000000 
			this->s_id = "00000000";
		}
		
		~Student(){}
		
		std::string toString(){
			return 	"id："		+this->s_id		+","+
					"name："	+this->s_name	+","+
					"sex："		+this->s_sex	+","+
					"class："	+this->s_class; 
		}
		
		void setS_id(std::string s_id){
			this->s_id = s_id;
		} 
		
		void setS_name(std::string s_name){
			this->s_name = s_name;
		}
		
		void setS_sex(std::string s_sex){
			this->s_sex = s_sex;
		}
		
		void setS_class(std::string s_class){
			this->s_class = s_class
		}
		
		std::string getS_id(){
			return this->s_id;
		} 
		
		std::string getS_name(){
			return this->s_name;
		} 
		
		std::string getS_sex(){
			return this->s_sex;
		} 
		
		std::string getS_class(){
			return this->s_class;
		} 
};
