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

typedef enum  
{
	Research=1,Linguistic,Technical=3
}Uni;

typedef enum 
{
	MARMARA=1,KOC,GTU
}Unisim;

typedef enum    
{
	Lecturer=1,ResearchAssistant,Secretary,Officer=4
}memur;

typedef enum   
{
	document=1,slackness,project,lesson,seminar,academicPaper,administration,HomeworkTime,homeworkTimeout,incident,solution
}action;

typedef struct 
{
	string isim;
	string soyisim;
	string job;

}isci;



class Employee{   ////abstract class 

private:
	int pid;
	string name;
	string surname;
	int happiness;
	string unvan;
	

public:

	Employee():pid(0),name(""),surname(""),happiness(0),unvan(""){
		
	}
	Employee(const Employee &n){   ///copy constructor
		pid=n.pid;
		name=n.name;
		surname=n.surname;
		happiness=n.happiness;
		
		unvan=n.unvan;
	}
	Employee& operator =(const Employee &n){ ///assignment operator overloaded
		if(this !=&n){
		pid=n.pid;
		name=n.name;
		surname=n.surname;
		happiness=n.happiness;
		
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

	virtual double work(int x)=0;  ////abstract class 
	void drinkTea(){
		happiness=happiness+5;
		
	}

	void submitPetition(){
		happiness=happiness+1;
	
	}

};

template<class T>  ///template class created
class University{ 
private:
	T contribution;

public:
	int typ;
	int ad;
	vector<Employee*>kisiler;   ////Employe pointer store in vector
	
	T  get_contribution(){
		return contribution;
	}
	void set_contribution(T v){
		contribution=v;
	}
	T contribute(T a){
		return this->contribution=(contribution+a);
	}

};



template <class T>
class YOK{
public:
	University<T>* foundUni(int Unitype){   ///new university established

		University<T> *rtr=new University<T>;
		rtr->typ=Unitype;
		return rtr;       /////new university return 
	
	}

	Employee* givejob(Employee *x,string name,string surname,int Emptype){  ///new employees created
		x->set_name(name);
		x->set_surname(surname);
		return x;


	}

};



class lecturer:public Employee{        ///Derived class
public:
	double work(int x);
		
	void giveLesson(){
		set_happiness(get_happiness()+1);
		
	}
	void giveHW(){
		set_happiness(get_happiness()-2);

	}
	void seeSuccessfulStudent(){
		set_happiness(get_happiness()+10);
	
	}
	void makePublish(){
		set_happiness(get_happiness()+2);

	}


}; 


class researchAssistant:public Employee{        ///Derived class
public:
	double work(int x);
		
	
	void research(){
		set_happiness(get_happiness()+3);

	}
	void readHW(){
		set_happiness(get_happiness()-3);

	}
	void seeSuccessfulStudent(){
		set_happiness(get_happiness()+10);
	
	}
	void makePublish(){
		set_happiness(get_happiness()+2);

	}

};


class secretary:public Employee{    ///Derived class
public:
	double work(int x);
		
	
	void receivePetition(){
		set_happiness(get_happiness()-1);
	}
	 void manageProcess(){
 		set_happiness(get_happiness()-1);
 	}


};


class officer:public Employee{    ///Derived class
public:
	double work(int x);
		
	void makeDoc(){
		this->set_happiness(this->get_happiness()-2);
	}
	 void manageProcess(){
 		set_happiness(get_happiness()-1);

 	}

};

		
double officer::work(int t){
			if(t==document){
				makeDoc(); ///called function
				cout<<get_name()<<" "<<get_surname();
				cout<<" Document "<<"Happiness of "<<get_happiness();
				return 3;  //return contribution value				
			}
			if(t==administration  ){
					
				manageProcess();  ///called function
				cout<<get_name()<<" "<<get_surname();
				cout<<" administration "<<"Happiness of "<<get_happiness();
				return 2;//return contribution value			
			}
			if(t==slackness){
				drinkTea();          ///call function
				cout<<get_name()<<" "<<get_surname();
				cout<<" slackness "<<"Happiness of "<<get_happiness();
				return -2.0;//return contribution value				
			}
			if(t==solution) { ///called function	
				submitPetition();
				cout<<get_name()<<" "<<get_surname();
				cout<<" solution "<<"Happiness of "<<get_happiness();
				return -2.0;//return contribution value	
			}

		
	
}
double researchAssistant::work(int t){
		if(t==project ){			
				research();  ///called function     
				cout<<get_name()<<" "<<get_surname();
				cout<<" research "<<"Happiness of "<<get_happiness();
			return 4.0;//return contribution value	
			}
			if(t==seminar){
					
				seeSuccessfulStudent(); ///called function     
				cout<<get_name()<<" "<<get_surname();
				cout<<" seminar "<<"Happiness of "<<get_happiness();
				return 0;//return contribution value	
			}
			if(t==academicPaper   ){				
				makePublish();
				cout<<get_name()<<" "<<get_surname();
				cout<<" academicPaper "<<"Happiness of "<<get_happiness();
			return 5.0;//return contribution value	
			}
			if(t==homeworkTimeout  ){
								
				research();
				cout<<get_name()<<" "<<get_surname();
				cout<<" homeworkTimeout "<<"Happiness of "<<get_happiness();
			return 2.0;//return contribution value	
			}
				if(t==slackness){
				drinkTea();          ///call function
				cout<<get_name()<<" "<<get_surname();
				cout<<" slackness "<<"Happiness of "<<get_happiness();
				return -2.0;//return contribution value				
			}
			if(t==solution) {	
				submitPetition();
				cout<<get_name()<<" "<<get_surname();
				cout<<" solution "<<"Happiness of "<<get_happiness();
				return -2.0;//return contribution value	
			}
			
}
double lecturer::work(int t){
			if(t==lesson){
			
				giveLesson();        
				cout<<get_name()<<" "<<get_surname();
				cout<<" lesson "<<"Happiness of "<<get_happiness();
			return 5.1; //return contribution value	
			}
			if(t==seminar){
		
				seeSuccessfulStudent();     
				cout<<get_name()<<" "<<get_surname();
				cout<<" seminar "<<"Happiness of "<<get_happiness();
			return 0;//return contribution value	
			}
			if(t==academicPaper   ){
						
				makePublish();
				cout<<get_name()<<" "<<get_surname();
				cout<<" academicPaper "<<"Happiness of "<<get_happiness();
			return 5.1;	//return contribution value			
			}
			if(t==HomeworkTime ){
							
				giveHW();
				cout<<get_name()<<" "<<get_surname();
				cout<<" HomeworkTime "<<"Happiness of "<<get_happiness();
			return 1.1;//return contribution value	
			}
				if(t==slackness){
				drinkTea();          ///call function
				cout<<get_name()<<" "<<get_surname();
				cout<<" slackness "<<"Happiness of "<<get_happiness();
				return -2.1;//return contribution value				
			}
			if(t==solution) {	
				submitPetition();
				cout<<get_name()<<" "<<get_surname();
				cout<<" solution "<<"Happiness of "<<get_happiness();
			return -2.1;   //return contribution value	
			}			
}
double secretary::work(int t){
	
			if(t==administration){
				
				manageProcess();  ///called function
				cout<<get_name()<<" "<<get_surname();
				cout<<" administration "<<"Happiness of "<<get_happiness();
				return 2.0;//return contribution value	
			}
			if(t==incident ){
								
				receivePetition();
				cout<<get_name()<<" "<<get_surname();
				cout<<" incident "<<"Happiness of "<<get_happiness();
			return -1.0;//return contribution value	
			}
				if(t==slackness){
				drinkTea();          ///call function
				cout<<get_name()<<" "<<get_surname();
				cout<<" slackness "<<"Happiness of "<<get_happiness();
				return -2.0;//return contribution value				
			}
			if(t==solution) {	
				submitPetition();
				cout<<get_name()<<" "<<get_surname();
				cout<<" solution "<<"Happiness of "<<get_happiness();
			return -2.0;//return contribution value	
			}

		
						
}
	

#endif

