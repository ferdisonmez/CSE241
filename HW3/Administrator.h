#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
using namespace std;

class yonetici{
	private:
		int p_id,password;
	public:
	int get_pid();
	void set_pid(int);
	
	int get_password();
	void set_password(int);
	
	void arrangeclassroom();
	void arrangeTimeTable();
	
};

#endif
