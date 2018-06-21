//ScoreSvc½Ó¿Ú
#include "..\domain\Score.h"

class ScoreSvc{
	
	public:
		void addScore(Score score);
		int removeScore(std::string s_name, std::string courseName);
		void modifyScore(Score course);
		Score queryScore(std::string s_name, std::string courseName);
		
};
