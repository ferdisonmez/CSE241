#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<sstream>
#include<cstring>
const int BOYUT=100;
using namespace std;
namespace hw2{
	
typedef struct{
	int saatler[2];
	string gun;
}gunler;
typedef struct{
	int id,code,credit,total,hours[10];
	string name,lecture_dates[5];
	vector<gunler>hg;
}Course;

typedef struct{
	int id,capacity,student_inroom;
	string c_no;
}Classroom;

class Student{
	private:	
		string name,surname;
		int student_no,level,krdhak;
			
	public:
	void set_name(string y){
		this->name=y;
	}
	void set_surname(string x){
		this->surname=x;
	}
	void set_student_no(int c){
		student_no=c;
	}
	void set_level(int b){
		level=b;
	}
	void set_krdhak(int a){
		krdhak=a;
	}
	string get_name(){
		return this->name;
	}
	string get_surname(){
		return surname;
	}
	int get_student_no(){
		return student_no;
	}
	int get_level(){
		return level;
	}
	int get_krdhak(){
		return krdhak;
	}
	vector<Course>ders;
	friend  int enrollcourse(Course x);
	friend	int disenroll(Course y);
	friend	string extraSchedule();
	friend	void enterclassroom(Classroom k);
	friend	void quitclassroom(Classroom q);	
};


		
	int enrollcourse(Course x,Student &a){  //// will be registered to the course will return the remaining credit
	int hesap=0,f=0;
	a.ders.push_back(x);
	
		
	if(a.get_krdhak()-x.credit>=0){
		hesap=a.get_krdhak()-x.credit;
	}
	else{
		cout<<"credits overlap"<<endl;
		hesap=a.get_krdhak();
	}
	
	return hesap;	
}

int disenroll(Course y,Student & b){  //The lesson is to return the remaining output
	int hesap=0,kalankrd=0;
	int temp=0;
	b.ders.erase(b.ders.begin()+y.id-1);
		
			if(b.get_level()==1)
        		kalankrd=20;
        	else if(b.get_level()==2)
        		kalankrd=21;
        	else if(b.get_level()==3)
        		kalankrd=22;
        	else{
        		kalankrd=23;
			}
	hesap=b.get_krdhak()+y.credit;
	if(hesap>kalankrd){
			hesap=kalankrd;	
	}	
	return hesap;		
}

string extraSchedule(Student x){ 
	int i;
	ostringstream convert;
	
	string temp;
	for(i=0;i<x.ders.size();i++){
		convert.str("");
		convert <<x.ders[i].credit;
		
		temp+=x.ders[i].name +" "+ convert.str()+" ";
		
	}
	return temp;
}

void enterclassroom(Classroom &k){ 	// student enroll

		k.student_inroom++;		
}

void quitclassroom(Classroom &q){ 		//student disenroll
		q.student_inroom--;		
}
void kayit(string dizi,vector<Student> &ogrenci){ /// -ns student enroll 
	   	   
		string tm,c;
		int sc=0,e,yx=0,hk=0;
		Student v1;	
		int counter;
       istringstream is (dizi);
		while (is.good ()) {
        	is >> tm;
        		if(tm=="-ns" || tm=="exit"){
				}
        		else{
        			c=tm;
        			++sc;
        			if(sc==1){
        			v1.set_name(c);	
        			c.clear();
					}
					else if(sc==2)
					v1.set_surname(c);
					else if(sc==3){
						v1.set_student_no(atoi(c.c_str()));						
					}					
					else if(sc==4){
					v1.set_level(atoi(c.c_str()));
						if(v1.get_level()>4 || v1.get_level()<0){
							cout<<"Hatali sinif girdiniz:("<<endl;
						}
						else{
							if(v1.get_level()==1)
        						v1.set_krdhak(20);
        					else if(v1.get_level()==2)
        						v1.set_krdhak(21);
        					else if(v1.get_level()==3)
        						v1.set_krdhak(22);
        					else{
        						v1.set_krdhak(23);
							}
							for(yx=0;yx<ogrenci.size();yx++){
								if(ogrenci[yx].get_student_no()==v1.get_student_no()){
									hk=2;
								}	
							}
							if(hk==2){
								cout<<"Ayni ogrenci numarasina sahip ogrenci vardir"<<endl;
							}
							else{
								ogrenci.push_back(v1);
								
							}
								
						}
						
					}
										
							
				}
				
    		}
    			
		counter=0;		
}

void nokayit(string dizi,vector<Student> &ogrenci,Classroom sinif[],Course kurs[]){ ////-e the student will register for the course
		                           
		string tm,c;
		int al=0;
		int ver=0,h=0,counter=0;
		int tut=0,gx=0,sayilan=0;	
       istringstream is (dizi);
		while (is.good ()) {
        	is >> tm;
        		if(tm=="-e" || tm=="exit"){
				}
        		else{
        			c=tm;
        			++al;
        			if(al==1){
        				for(h=0;h<ogrenci.size();h++){    /// search number of student number
        					if(ogrenci[h].get_student_no()==atoi(c.c_str())){ 
								tut=h;          			
        						ver=1;
							}	
						}
						if(ver!=1)
							cout<<"NO STUDENT!!!"<<endl;	
					}
					else if(al==2 && ver==1){   //// search lessons code
					
						for(gx=0;gx<ogrenci[tut].ders.size();gx++)
							{
								if(ogrenci[tut].ders[gx].id==atoi(c.c_str())){
								sayilan=1;	
								}
								
							}
						if(sayilan==1){
							cout<<"Ders daha once eklenmis:"<<endl;
						}
							
						else{
							
							if(sinif[1].capacity==sinif[1].student_inroom){
								cout<<"Sinif kapasitesi yetersiz:"<<endl;
							}
							else{
								ogrenci[tut].set_krdhak(enrollcourse(kurs[atoi(c.c_str())],ogrenci[tut]));
								enterclassroom(sinif[1]);
							}							
						}								
					}
        					
				}        
    		}
    		
		counter=0;		
}

void owithno(string dizi,vector<Student> &ogrenci){ ////-o and number enter
		       
		string tm,c;
		int krd=0,counter=0;
		int kalankrd=0;	
       istringstream is (dizi);
		while (is.good ()) {
        	is >> tm;
        		if(tm=="-o" || tm=="exit"){
				}
        		else{
        			c=tm;
        			for(int h=0;h<ogrenci.size();h++){
        				if(ogrenci[h].get_student_no()==atoi(c.c_str()))
        				{
        					if(ogrenci[h].get_level()==1)
        						kalankrd=20;
        					else if(ogrenci[h].get_level()==2)
        						kalankrd=21;
        					else if(ogrenci[h].get_level()==3)
        						kalankrd=22;
        					else{
        						kalankrd=23;
							}
        					cout<<ogrenci[h].get_name();
        					cout<<" "<<ogrenci[h].get_surname()<<" "<<extraSchedule(ogrenci[h])<<"Total credit="<<ogrenci[h].get_krdhak()<<" ";
        					cout<<"Credit right="<<kalankrd<<endl;
						}
					}
        			
				}
    
    		}
			counter=0;
		} 

void ynlzno(string dizi,vector<Student> &ogrenci){ /// -o all student information
		  
    		int kalankrd=0,counter=0;
    		for(int g=0;g<ogrenci.size();g++){
    						if(ogrenci[g].get_level()==1)
        						kalankrd=20;
        					else if(ogrenci[g].get_level()==2)
        						kalankrd=21;
        					else if(ogrenci[g].get_level()==3)
        						kalankrd=22;
        					else{
        						kalankrd=23;
							}
							cout<<ogrenci[g].get_name();
        					cout<<" "<<ogrenci[g].get_surname()<<" "<<extraSchedule(ogrenci[g])<<"Total credit="<<ogrenci[g].get_krdhak()<<" ";
        					cout<<"Credit right="<<kalankrd<<endl;
        					
		
    		}    		
    	counter=0;	
}

void dosyano(string dizi,vector<Student> &ogrenci,ofstream &dosya){	/// -o -f no file.txt write information in file 
	    	  					
    	string tm,c;
		int ar=0,counter=0;
		int kalankrd=0;
		dosya.open("file.txt");	
       istringstream is (dizi);
		while (is.good ()) {
        	is >> tm;
        		if(tm=="-o" || tm=="-f" || tm=="file.txt"){
				}
        		else{
        			c=tm;
        			ar=atoi(c.c_str());
        			for(int k=0;k<ogrenci.size();k++){
        				
        				if(ogrenci[k].get_student_no()==ar){
        					if(ogrenci[k].get_level()==1)
        						kalankrd=20;
        					else if(ogrenci[k].get_level()==2)
        						kalankrd=21;
        					else if(ogrenci[k].get_level()==3)
        						kalankrd=22;
        					else{
        						kalankrd=23;
							}
        					
        				dosya<<ogrenci[k].get_name();
        					dosya<<" "<<ogrenci[k].get_surname()<<" "<<extraSchedule(ogrenci[k])<<"Total credit="<<ogrenci[k].get_krdhak()<<" ";
        					dosya<<"Credit right="<<kalankrd<<endl;	
        		 	
						}
        					
					}
      		
				}
    		}
			counter=0;
			dosya.close();	
		}
				
void alldosya(string dizi,vector<Student> &ogrenci,ofstream &hepdosya){ /// -o -f file.txt all student information write the file

    	int kalankrd=0,counter=0;
    	hepdosya.open("file.txt");
    	for(int k=0;k<ogrenci.size();k++){
    						if(ogrenci[k].get_level()==1)
        						kalankrd=20;
        					else if(ogrenci[k].get_level()==2)
        						kalankrd=21;
        					else if(ogrenci[k].get_level()==3)
        						kalankrd=22;
        					else{
        						kalankrd=23;
							}    		
    						hepdosya<<ogrenci[k].get_name();
        					hepdosya<<" "<<ogrenci[k].get_surname()<<" "<<extraSchedule(ogrenci[k])<<"Total credit="<<ogrenci[k].get_krdhak()<<" ";
        					hepdosya<<"Credit right="<<kalankrd<<endl;		
	
    		}
			counter=0;
			hepdosya.close();   		
}
void derscikar(string dizi,vector<Student> &ogrenci,Classroom sinif[],Course kurs[]){  ////-de disenroll course
		   
		string tm,c;
		int al=0,counter=0;
		int ver=0,h=0;
		int tut=0,gx=0,sayilan=0;	
       istringstream is (dizi);
		while (is.good ()) {
        	is >> tm;
        		if(tm=="-de" || tm=="exit"){
				}
        		else{
        			c=tm;
        			++al;
        			if(al==1){
        				for(h=0;h<ogrenci.size();h++){    /// search student number
        					if(ogrenci[h].get_student_no()==atoi(c.c_str())){ 
								tut=h;          			
        						ver=1;
							}	
						}
						
					}
					else if(al==2 && ver==1){   //// ders kodunu bulup kurs biligileri
								for(gx=0;gx<ogrenci[tut].ders.size();gx++)
							{
								if(ogrenci[tut].ders[gx].id==atoi(c.c_str())){
								sayilan=1;	
								}
								
							}
						if(sayilan==1){
							ogrenci[tut].set_krdhak(disenroll(kurs[atoi(c.c_str())],ogrenci[tut]));
							quitclassroom(sinif[1]);
						}
							
						else{
							cout<<"Dersi almadiginiz icin cikaramazsiniz:"<<endl;
						}
						
					}
        					
				}
        
    		}
		counter=0;	
}
	
		
}
#endif
