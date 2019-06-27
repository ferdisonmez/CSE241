#ifndef LECTURER_H
#define LECTURER_H
#include<vector>
#include<cstring>
using namespace std;
typedef enum{
	Mon=0,Tue,Wed,Thu,Fri
}day;
typedef struct{
	int saat_bas,saat_bit;
	day gun;
}gunler;
typedef struct{
	int s_id,student_inroom;
	string s_no;
}Classroom;
typedef struct{
	int c_id,c_code,c_credit,c_total_hours;
	string c_name,c_tur,c_field;
	vector<gunler>lecture_date;
	vector<Classroom>csnf;
}Course;
class lecturer{
private:
	string name,surname,title,courses,profession;
	int personal_id;

public:
	
	string get_name();
	string get_surname();
	string get_title();
	string get_courses();
	string get_profession();
	int get_personal_id();

	void set_name(string fname);
	void set_surname(string fsurname);
	void set_title(string ftitle);
	void set_courses(string fcourses);
	void set_profession(string fprofession);
	void set_personal_id(int fpersonal_id);

	vector<Course>al_ders;
	vector<string>alan;
	int ders_sayisi;
	void proposeCourse(string,vector<Course>&b);
	void assignCourse(string,vector<Course>&a);
	
};

#endif
