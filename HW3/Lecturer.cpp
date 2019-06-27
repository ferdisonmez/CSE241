#include <iostream>
#include<sstream>
#include<string>
#include<cstring>
#include<vector>
#include"Lecturer.h"
using namespace std;

	string lecturer::get_name(){
		return this->name;
	}
	string lecturer::get_surname(){
		return this->surname;
	}
	string lecturer::get_title(){
		return this->title;
	}
	string lecturer::get_courses(){
		return this->courses;
	}
	string lecturer::get_profession(){
		return this->profession;
	}
	int lecturer::get_personal_id(){
		return this->personal_id;
	}

	void lecturer::set_name(string fname){
		this->name=fname;
	}

	void lecturer::set_surname(string fsurname){
		this->surname=fsurname;
	}
	void lecturer::set_title(string ftitle){
		this->title=ftitle;
	}
	void lecturer::set_courses(string fcourses){
		this->courses=fcourses;
	}
	void lecturer::set_profession(string fprofession){
		this->profession=fprofession;
	}
	
	void lecturer::set_personal_id(int fpersonal_id){
		this->personal_id=fpersonal_id;
	}
	
void lecturer::proposeCourse(string dz,vector<Course>&kurs){
		int say=0,sayx=0;
		string tm,c;
		int sc=0,x;
		Course v2;	
       istringstream is (dz);
		while (is.good ()) {
        	is >> tm;
        		if(tm=="-propose" || tm=="exit"){
				}
        		else{
        			++sc;
        			c=tm;
        			if(sc==2){
        			v2.c_name=c;	
					}
					if(sc==3){
						int k;
						stringstream gk(c);
        				gk>>k;
        				v2.c_code=k;
					}
					if(sc==4){
						int x;
						stringstream g(c);
        				g>>x;
        				v2.c_credit=x;
					}
					if(sc==5){
							int y;
						stringstream gy(c);
        				gy>>y;
        				v2.c_total_hours=y;
					}
					if(sc==6){
						v2.c_field=c;
					}
					
				}
    		}
    		if(al_ders.size()==0){
    			say=0;
			}
			else{
			
    			for(int h=0;h<al_ders.size();h++){
					if(v2.c_name==al_ders[h].c_name){  ////looking at the lesson with just the name control
						say=1;
						cout<<"ders onceden alinmis:"<<endl;				
					}		
				}
			}
			for(int d=0;d<alan.size();d++){
				if(v2.c_field==alan[d]){
					sayx=1;	
				}
				if(ders_sayisi<3 && v2.c_field==alan[d] && say!=1){
					ders_sayisi++;
					al_ders.push_back(v2);
					kurs.push_back(v2);
					break;
				}
		}
		if(sayx==0 && say==0){
			cout<<"Field and profession mismatch!!!"<<endl;
		}
}

void lecturer::assignCourse(string dz,vector<Course> &kurs){/// -assign ve p_id c_id 
	string tm,c;
		int sc=0,x,tut=0,goz=0,goz1=0;	
       istringstream is (dz);
		while (is.good ()) {
        	is >> tm;
        		if(tm=="-assign" || tm=="exit"){
				}
        		else{
        			++sc;
        			c=tm;
						if(sc==2){
							stringstream g(c);
        					g>>x;
        					for(int v=0;v<kurs.size();v++){
        						if(kurs[v].c_id==x){
        						tut=v;
								goz=1;		
								}						
							}
							for(int t=0;t<alan.size();t++){
        						if(kurs[tut].c_field==alan[t]){
        						cout<<"alanlar eslesti:"<<endl;	
        						goz1=1;	
								}	
							}
								if(goz1==0){
									cout<<"Field and profession mismatch!!!"<<endl;
								}
																	
        						if(goz==0){
									cout<<"Kurs yoktur:"<<endl;	
								}	  
						}
					if(goz1==1 && goz==1 && ders_sayisi<3){
						al_ders.push_back(kurs[tut]);
						cout<<"ders eklendi"<<endl;
					}
    		}
	
	}
}

/////finish

	
