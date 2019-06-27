#ifndef PERSONAL_H
#define PERSONAL_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

class University{      ///define class University
private:
	int contribution;

public:
	int get_contribution(){
		return contribution;
	}
	void set_contribution(int v){
		contribution=v;
	}

};

class Employee{   ///define class Employee (base class)

private:
	int pid;
	string name;
	string surname;
	int happiness;
	string unvan;
	

public:
	static University *emp;   ///define static pointer 
	Employee():pid(0),name(""),surname(""),happiness(0),unvan(""){
		
		emp->set_contribution(emp->get_contribution());
	}
	Employee(const Employee &n){   ///copy constructor
		pid=n.pid;
		name=n.name;
		surname=n.surname;
		happiness=n.happiness;
		emp=n.emp;
		unvan=n.unvan;
	}
	Employee& operator =(const Employee &n){ ///assignment operator overloaded
		if(this !=&n){
		pid=n.pid;
		name=n.name;
		surname=n.surname;
		happiness=n.happiness;
		emp=n.emp;
		unvan=n.unvan;
		}
		return *this;
	}
	
	
	string get_unvan(){
		return unvan;
	}
	void set_unvan(string h){
		unvan=h;
	}
	int get_pid(){
		return pid;
	}
	void set_pid(int x){
		pid=x;
	}
	string get_name(){
		return name;
	}
	void set_name(string a){
		name=a;
	}
	string get_surname(){
		return surname;
	}
	void set_surname(string b){
		surname=b;
	}
	int get_happiness(){
		return happiness;
	}
	void set_happiness(int y){
		happiness=y;
	}


	
	void drinkTea(){
		happiness=happiness+5;
		emp->set_contribution(emp->get_contribution()-2);
	}

	void submitPetition(){
		happiness=happiness+1;
		emp->set_contribution(emp->get_contribution()-2);
	}

};
University *Employee::emp = new University;   ///only one field to the same pointer will change the value

class AcademicPersonnel:public Employee{   ///Derived class
public:
	void seeSuccessfulStudent(){
		set_happiness(get_happiness()+10);
		emp->set_contribution(emp->get_contribution()+0);
	}
	void makePublish(){
		set_happiness(get_happiness()+2);
		emp->set_contribution(emp->get_contribution()+5);
	}

};


class AdministrativePersonnel:public Employee{         ///Derived class
public:
 	void manageProcess(){
 		set_happiness(get_happiness()-1);
		emp->set_contribution(emp->get_contribution()+2);

 	}

};


class Lecturer:public AcademicPersonnel{        ///Derived class
public:
	void giveLesson(){
		set_happiness(get_happiness()+1);
		emp->set_contribution(emp->get_contribution()+5);
	}
	void giveHW(){
		set_happiness(get_happiness()-2);
		emp->set_contribution(emp->get_contribution()+1);
	}

}; 


class ResearchAssistant:public AcademicPersonnel{        ///Derived class
public:
	void research(){
		set_happiness(get_happiness()+3);
		emp->set_contribution(emp->get_contribution()+4);
	}
	void readHW(){
		set_happiness(get_happiness()-3);
		emp->set_contribution(emp->get_contribution()+2);
	}

};


class Secretary:public AdministrativePersonnel{    ///Derived class
public:
	void receivePetition(){
		set_happiness(get_happiness()-1);
		emp->set_contribution(emp->get_contribution()-1);
	}


};


class Officer:public AdministrativePersonnel{    ///Derived class
public:

	void makeDoc(){
		this->set_happiness(this->get_happiness()-2);

		emp->set_contribution(emp->get_contribution()+3);

	}


};

#endif
