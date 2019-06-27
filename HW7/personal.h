#ifndef PERSONAL_H
#define PERSONAL_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <ctime>
#include<cstdlib>
#include <vector>
using namespace std;
typedef enum   
{
	document=1,slackness,project,lesson,seminar,academicPaper,administration,HomeworkTime,homeworkTimeout,incident,solution
}action;
typedef struct{
	string isim;	
	string soyisim;
	string yap_is;
	
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

class lecturer:public Employee{        ///Derived class
public:
	 virtual double work(int x);
		
	void giveLesson()
	{
		
		set_happiness(get_happiness()+1);	
	}
	void giveHW()
	{
	
		set_happiness(get_happiness()-2);
	}
	void seeSuccessfulStudent()
	{
	
		set_happiness(get_happiness()+10);
	}
	void makePublish()
	{
		
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

////LIBERAL

class libLec:public lecturer{
		
};
class libResAssist:public researchAssistant{
	
};
class libSec:public secretary{
		
};

class libOff:public officer{
		
};

///////COMMUNIST

class comLec:public lecturer{
	
};
class comResAssist:public researchAssistant{
	
};
class comSec:public secretary{
	
};
class comOff:public officer{
			
};

//////CAPITALIST
class workerLec:public lecturer{
		
};
class brokerLec:public lecturer{
	public:
		Employee* next;
		Employee* sol;
		Employee* sag;
};
class brokerResAssist:public researchAssistant{
	public:
		Employee* next;
		Employee* sol;
		Employee* sag;
};
class workerResAssist:public researchAssistant{
	
};


class brokerSec:public secretary{
	public:
		Employee* next;
		Employee* sol;
		Employee* sag;
};
class workerSec:public secretary{
		
};

class brokerOff:public officer{
	public:
		Employee* next;
		Employee* sol;
		Employee* sag;	
};
class workerOff:public officer{
		
};

double officer::work(int t){   ///officer work
			if(t==document){
				makeDoc(); ///called function
				
				return 3;  //return contribution value				
			}
			if(t==administration  ){
					
				manageProcess();  ///called function
				return 2;//return contribution value			
			}
			if(t==slackness){
				drinkTea();          ///call function
				return -2.0;//return contribution value				
			}
			if(t==solution) { ///called function	
				submitPetition();
				return -2.0;//return contribution value	
			}

		
	
}
double researchAssistant::work(int t){   ///researchassistant work
		if(t==project ){			
				research();  ///called function     

			return 4.0;//return contribution value	
			}
			if(t==seminar){
					
				seeSuccessfulStudent(); ///called function     
				return 0;//return contribution value	
			}
			if(t==academicPaper   ){				
				makePublish();
			return 5.0;//return contribution value	
			}
			if(t==homeworkTimeout  ){
								
				readHW();
			return 2.0;//return contribution value	
			}
				if(t==slackness){
				drinkTea();          ///call function
				return -2.0;//return contribution value				
			}
			if(t==solution) {	
				submitPetition();
				return -2.0;//return contribution value	
			}
			
}
double lecturer::work(int t){   ///lecturer work

			
			if(t==lesson){
			
				giveLesson();        
			return 5.1; //return contribution value	
			}
			if(t==seminar){
		
				seeSuccessfulStudent();     
			return 0;//return contribution value	
			}
			if(t==academicPaper   ){
						
				makePublish();
			return 5.1;	//return contribution value			
			}
			if(t==HomeworkTime ){
							
				giveHW();
			return 1.1;//return contribution value	
			}
				if(t==slackness){
				drinkTea();          ///call function
				return -2.1;//return contribution value				
			}
			if(t==solution) {	
				submitPetition();
			return -2.1;   //return contribution value	
			}			
}
double secretary::work(int t){   ///secretary work
	
			if(t==administration){
				
				manageProcess();  ///called function
				return 2.0;//return contribution value	
			}
			if(t==incident ){
								
				receivePetition();
			return -1.0;//return contribution value	
			}
				if(t==slackness){
				drinkTea();          ///call function
				return -2.0;//return contribution value				
			}
			if(t==solution) {	
				submitPetition();
			return -2.0;//return contribution value	
			}

								
}

#endif
