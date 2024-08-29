#include <iostream>
#include <string>

using namespace std;

class Food {
public:
	Food(int civil, int force, string name, int territory) 
		: civil_(civil), force_(force), name_(name), territory_(territory) {

	}
private:
	int civil_; //국민 수
	int force_; //군력
	string name_; // 이름
	int territory_; //땅(면적)
};

class Kimchi : public Food {
public:
	Kimchi(int civil, int force, string name, int territory, int garlic, int pepper) 
		: Food(civil, force, name, territory), garic_(garlic), pepper_(pepper)
		{

	}
private:
	int garic_;
	int pepper_; 
};

class Jelly : public Food {
public:
	Jelly (int civil, int force, string name, int territory, int gelatin, int sugar)
		: Food(civil, force, name, territory), gelatin_(gelatin), sugar_(sugar)
	{

	}
private:
	int gelatin_;
	int sugar_; //설탕의 힘

};

class Cheese : public Food {
public:
	Cheese(int civil, int force, string name, int territory, int milk, int rennet)
		: Food(civil, force, name, territory), milk_(milk), rennet_(rennet) {

	}
private:
	int milk_;
	int rennet_; //응고제
};