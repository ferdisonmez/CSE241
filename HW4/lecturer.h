#ifndef LECTURER_H
#define LECTURER_H
#include <iostream>
#include<vector>
#include<cstring>
#include<fstream>       ////-propose 7 depp 521 1 1 PROG dersini ekleyin sonra diðer iþlemlere devam edin
#include<sstream>
#include<cstdlib>
#include<string>
using namespace std;

class mektep{
	private:
		int ogrnci_id;
		int krs_id;
		string krs_name,ogrnci_name;
	public:
		int att;
		mektep():ogrnci_id(0),ogrnci_name(""),krs_id(0),krs_name(""),att(0){ ///default constructor	
		}
		mektep(const mektep &n){  ///copy constructor
			ogrnci_id=n.ogrnci_id;
			krs_id=n.krs_id;
			krs_name=n.krs_name;
			ogrnci_name=n.ogrnci_name;
			att=n.att;
		}
		mektep& operator=(const mektep &x){ ///assignment operator overloaded
			ogrnci_id=x.ogrnci_id;
			krs_id=x.krs_id;
			krs_name=x.krs_name;
			ogrnci_name=x.ogrnci_name;
			x.att;
		}
		~mektep(){ ///destructor
		}
		string get_ogrnci_name(){
			return ogrnci_name;
		}
		void set_ogrnci_name(string b){
			ogrnci_name=b;
		}
			
		string get_krs_name(){
			return this->krs_name;
		}
		void set_krs_name(string a){
			this->krs_name=a;
		}
		int get_ogrnci_id(){
			return ogrnci_id;
		}
		void set_ogrnci_id(int x){
			this->ogrnci_id=x;
		}
		int get_krs_id(){
			return this->krs_id;
		}
		void set_krs_id(int y){
			this->krs_id=y;
		}
};
typedef struct{
	mektep ptr;
}s_level;
typedef enum{
	Mon=0,Tue,Wed,Thu,Fri
}day;
typedef struct{
	int saat_bas,saat_bit;
	day gun;
}gunler;

typedef struct{
	int s_id,student_inroom,capacity;
	string s_no;
	s_level *array;
}Classroom;

typedef struct{
	int c_id,c_code,c_credit,c_total_hours;
	string c_name,c_tur,c_field;
	vector<gunler>lecture_date;
	vector<Classroom>csnf;
}Course;


class Student{
	private:	
		string name,surname;
		int student_no,level,krdhak;
			
	public:
		
	Student():name(),surname(),student_no(0),level(0),krdhak(0){ ders=vector<Course>(); } ///default constructor
	
	Student(const Student &n){  ///copy constructor
		name=n.name;
		surname=n.surname;
		student_no=n.student_no;
		level=n.level;
		krdhak=n.krdhak;
		ders=n.ders;
	}
	Student& operator=(const Student &x){ ///assignment operator overloaded
		if(this!=&x){
		name=x.name;
		surname=x.surname;
		student_no=x.student_no;
		level=x.level;
		krdhak=x.krdhak;
		ders=x.ders;	
			
		}
		return *this;
	}
	~Student(){  ///destructor
		
	}	
	
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


class lecturer{
private:
	string name,surname,title,courses,profession;
	int personal_id;

public:

	lecturer():name(""),surname(""),title(""),courses(""),profession(""),personal_id(0){ ///default constructor
		al_ders=vector<Course>();
		alan=vector<string>();
	}
	
	lecturer(const lecturer &n){  ///copy constructor
		name=n.name;
		surname=n.surname;
		title=n.title;
		courses=n.courses;
		profession=n.profession;
		personal_id=n.personal_id;
		al_ders=n.al_ders;
		alan=n.alan;
	}
	
	lecturer& operator=(const lecturer &t){  ////assignment operator overloaded
		if(this!=&t){
			name=t.name;
			surname=t.surname;
			title=t.title;
			courses=t.courses;
			profession=t.profession;
			personal_id=t.personal_id;
			al_ders=t.al_ders;
			alan=t.alan;
		}
		return *this;
		
	}
	~lecturer(){ ///destructor
		
	}
	
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

int enrollcourse(Course x,Student &a){  //// will be registered to the course will return the remaining credit
	int hesap=0,f=0;
	a.ders.push_back(x);
	
		
	if(a.get_krdhak()-x.c_credit>=0){
		hesap=a.get_krdhak()-x.c_credit;
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
	b.ders.erase(b.ders.begin()+y.c_id-1);
		
			if(b.get_level()==1)
        		kalankrd=20;
        	else if(b.get_level()==2)
        		kalankrd=21;
        	else if(b.get_level()==3)
        		kalankrd=22;
        	else{
        		kalankrd=23;
			}
	hesap=b.get_krdhak()+y.c_credit;
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
		convert <<x.ders[i].c_credit;
		
		temp+=x.ders[i].c_name +" "+ convert.str()+" ";
		
	}
	return temp;
}

void enterclassroom(string dz,vector<Student>&ogrenci,vector<Course>kurs,vector<Classroom>&sinif){ 	// student enter classroom
		
		string tm,c,isim;
		int sc=0,x,goz=0,goz1=0,n=0,tut=0,tut1=0,i=0;
		int student_id,week=0,glx=0,classroom_id=0;	
       	istringstream is (dz);
		while (is.good ()) {
        	is >> tm;
        		if(tm=="-enter" || tm=="exit"){
				}
        		else{
        			++sc;
        			c=tm;
        			if(sc==1){
        				stringstream gkl(c);
        				gkl>>x;
        				
        				for(int d=0;d<ogrenci.size();d++){
        					if(ogrenci[d].get_student_no()==x){
        						isim=ogrenci[d].get_name();
        						goz=1;
        						student_id=x;  ////match student_id
        						break;
							}	
						}
						
						if(goz==0){
							cout<<"ogrenci yok"<<endl;
						}
						if(goz==1){ ///if ogrenci_id correct 
																					
						}	
					} ///sc-1
					
				if(sc==2){
					stringstream gl(c);
        				gl>>glx;
					for(n=0;n<sinif.size();n++){
						if(sinif[n].s_id==glx){
							classroom_id=glx; ///match class number
							goz1=1;
							break;
						}	
					}
					if(goz1==0){
						cout<<"classroom_id yanlis girdiniz:"<<endl;
					}
					
				}
				
				if(sc==3){
					stringstream hour(c);
        				hour>>week;
        			if(week>40 || week<0){
        				cout<<"Saat olarak input yalis girilmistir"<<endl;
					}
					
			else{
				
					if(sinif[classroom_id-1].student_inroom==0){
						sinif[classroom_id-1].array=new s_level[sinif[classroom_id-1].capacity];
					}
				
				day t;
				int temp=0;
					if(week>0 && week<=8){
						t=Mon;	
						temp=week;
					}
					
					if(week>8 && week<=16){
						t=Tue;
						temp=week-8;
					}
					
					if(week>16 && week<=24){
						t=Wed;
						temp=week-16;
					}
					
					if(week>24 && week<=32){
						t=Thu;
						temp=week-24;
					}
					
					if(week>32 && week<=40){
						t=Fri;
						temp=week-32;
					}
					
				for(int r=0;r<kurs.size();r++){
					int ax=9;
					if(kurs[r].lecture_date[0].saat_bas!=9){
						ax=kurs[r].lecture_date[0].saat_bas;
					}
					
					if(kurs[r].csnf[0].s_id==classroom_id && goz==1 && goz1==1 && kurs[r].lecture_date[0].gun==t && kurs[r].lecture_date[0].saat_bas<ax+temp && kurs[r].lecture_date[0].saat_bit>ax+temp){
						
						sinif[classroom_id-1].array[sinif[classroom_id-1].student_inroom].ptr.set_ogrnci_id(student_id);
						
						sinif[classroom_id-1].array[sinif[classroom_id-1].student_inroom].ptr.set_krs_id(kurs[r].c_id);
						cout<<"buda:((("<<endl;
						sinif[classroom_id-1].array[sinif[classroom_id-1].student_inroom].ptr.set_krs_name(kurs[r].c_name);
						sinif[classroom_id-1].array[sinif[classroom_id-1].student_inroom].ptr.set_ogrnci_name(isim);
						sinif[classroom_id-1].array[sinif[classroom_id-1].student_inroom].ptr.att++;
						sinif[classroom_id-1].student_inroom++;
						sinif[classroom_id-1].capacity--;
					}
									
				}

				for(int y=0;y<sinif.size();y++){
					for(int l=0;l<sinif[y].student_inroom;l++){
					cout<<"ogrenci_id="<<sinif[y].array[l].ptr.get_ogrnci_id()<<" kurs_id="<<sinif[y].array[l].ptr.get_krs_id()<<" kurs_name="<<sinif[y].array[l].ptr.get_krs_name()<<endl;
					}
					
				}
					
			 }
	}
				
				
										
			 }
    	}

						
}

void quitclassroom(string dz,vector<Student>&ogrenci,vector<Classroom>&sinif){ //student disenroll
		
		string tm,c;
		int sc=0,x,goz=0,goz1=0,n=0,tut=0,tut1=0,i=0;
		int student_id,week=0,glx=0,index=0;	
       	istringstream is (dz);
		while (is.good ()) {
        	is >> tm;
        		if(tm=="-quit" || tm=="exit"){
				}
        		else{
        			++sc;
        			c=tm;
        			if(sc==1){
        				stringstream gkl(c);
        				gkl>>x;
        				
        				for(int d=0;d<ogrenci.size();d++){
        					if(ogrenci[d].get_student_no()==x){
        						goz=1;
        						student_id=x;  ////mahch student number
        						break;
							}	
						}
						if(goz==0){
							cout<<"ogrenci yok"<<endl;
						}
						if(goz==1){
						
						for(int y=0;y<sinif.size();y++){
							for(int l=0;l<sinif[y].student_inroom;l++){
								if(sinif[y].array[l].ptr.get_ogrnci_id()==student_id){
									index=y;
									break;
								}
							}
						}
						sinif[index].student_inroom--;
						sinif[index].capacity++;
						cout<<"Siniiftan cikmistir"<<endl;
						}
				}

				
		}
	}
}///quit function
void attendance(string dz,vector<Course>kurs,vector<Classroom>&sinif){
		string tm,c;
		int sc=0,x,goz=0,goz1=0,n=0,tut=0,tut1=0,i=0;
		int student_id,week=0,glx=0,classroom_id=0,sav=0;	
       	istringstream is (dz);
		while (is.good ()) {
        	is >> tm;
        		if(tm=="-attendance" || tm=="exit"){
				}
        		else{
        			++sc;
        			c=tm;
        			if(sc==1){
        				stringstream gkl(c);
        				gkl>>x;    ///course_id
        				 x=x-1;      				
										
					int l=0;
						while(l<sinif[x].student_inroom){
							for(int k=l+1;k<=sinif[x].student_inroom;k++){
								
								if(sinif[x].array[l].ptr.get_ogrnci_id()==sinif[x].array[k].ptr.get_ogrnci_id()){
								sinif[x].array[k].ptr.att=sinif[x].array[k].ptr.att+sinif[x].array[l].ptr.att;
								
								cout<<sinif[x].array[l].ptr.get_ogrnci_name()<<" "<<sinif[x].array[l].ptr.att<<endl;
								l=k;	
								}
								else{
									cout<<sinif[x].array[l].ptr.get_ogrnci_name()<<" "<<sinif[x].array[l].ptr.att<<endl;
								}
							
													
							}
																	
						l++;															
						}
							
					}
	
	
			}
		    
		}
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
	
bool bulstr(string str) 
{ 
    char ch=','; 
    int l = str.length(); 
    for (int i = 0; i < l; i++) { 
        if(ch==str.at(i)) 
         return 1;
    } 
    return 0;
}
void kisit(vector<lecturer> &hocalar,vector<Course> &kurs,int x,int y){
	
	int tut=0,tut1=0;
	
		
			for(int j=x;j<y;j++){
				 
					for(int k=j+1;k<y;k++)	
					{
						for(int h=0;h<hocalar.size();h++){
							for(int m=0;m<hocalar[h].al_ders.size();m++){
								if(kurs[j].c_name==hocalar[h].al_ders[m].c_name){
									tut=h;
									break;
								}
								
							}
							
						}
							for(int a=0;a<hocalar.size();a++){
							for(int b=0;b<hocalar[a].al_ders.size();b++){
								if(kurs[k].c_name==hocalar[a].al_ders[b].c_name){
									tut1=a;
									break;
								}
								
							}
							
						}
																				
						if(kurs[j].lecture_date[0].gun==kurs[k].lecture_date[0].gun && hocalar[tut].get_name()==hocalar[tut1].get_name() ){
	
							if(kurs[j].lecture_date[0].saat_bas==kurs[k].lecture_date[0].saat_bas && (kurs[j].c_total_hours+kurs[k].c_total_hours)<8 ){
								kurs[k].lecture_date[0].saat_bas=kurs[j].lecture_date[0].saat_bit;
								kurs[k].lecture_date[0].saat_bit=kurs[k].lecture_date[0].saat_bas+kurs[k].c_total_hours;
												
							}
						else if(kurs[j].lecture_date[0].saat_bas==kurs[k].lecture_date[0].saat_bas && kurs[k].c_total_hours>4 ){
							kurs[k].lecture_date[0].gun=Fri;
						}
						else if((kurs[j].c_total_hours+kurs[k].c_total_hours)==8 ){
							kurs[k].lecture_date[0].saat_bas=9;
							kurs[k].lecture_date[0].saat_bit=kurs[k].lecture_date[0].saat_bas+kurs[k].c_total_hours;
							kurs[k].lecture_date[0].gun=Thu;						
						}
						
						}
						
					}
																				
			}
									
}

void atama(vector<lecturer> &hocalar,vector<Course> &kurs){
	
	hocalar[0].al_ders.push_back(kurs[17]);
	++hocalar[0].ders_sayisi;			
	int sav=0;
	int v;
	for(int g=0;g<kurs.size();g++){
		for(int t=0;t<hocalar.size();t++){
			for(int n=0;n<hocalar[t].alan.size();n++){
			
				for(int j=0;j<t;j++){				
					for(v=0;v<hocalar[j].al_ders.size();v++){
						if(kurs[g].c_name==hocalar[j].al_ders[v].c_name)
						sav=1;						
					}
				}
					if(kurs[g].c_field==hocalar[t].alan[n] && hocalar[t].al_ders.size()<3 && sav!=1){
					hocalar[t].ders_sayisi++;	
					hocalar[t].al_ders.push_back(kurs[g]);
																														
					}
					
				sav=0;				
			}
		}
	}
	cout<<"------------OTOMATIK ASSIGN-------------"<<endl;
		for(int a=0;a<hocalar.size();a++){
			for(int b=0;b<hocalar[a].al_ders.size();b++){
				
					cout<<hocalar[a].al_ders[b].c_name<<" "<<hocalar[a].get_name()<<" "<<hocalar[a].get_surname()<<endl;		
			}
		}			
}

void arrangeclassroom3(string dz,vector<lecturer> &hocalar,vector<Course> &kurs,vector<Classroom> &sinif){
	
		if(kurs.size()!=hocalar.size()*3){
			cout<<"yeterli sayida ders eklenmemis:( -propose komutuyla ders eklemeye devam ediniz"<<endl;
		}
		else{
			cout<<"-------------ARRANGEC-----------------"<<endl;				
			int sav=0;
			int y=0;
			int tut=0;                   
			for(int k=0;k<4;k++){
				
				for(int m=0;m<sinif.size();m++){
				
					while(y<kurs.size()){
					
						if(kurs[y].csnf.size()==0){
							kurs[y].csnf.push_back(sinif[m]);
						y++;
							break;
						}
						y++;
					}
					
				}
			}
		
			for(int r=0;r<kurs.size();r++){
				for(int x=0;x<kurs[r].csnf.size();x++){
					cout<<kurs[r].c_name<<" "<<kurs[r].csnf[x].s_no<<endl;
					break;
				}
				
			}
		
		}	
		
}

void assign2(string dz,vector<lecturer> &hocalar,vector<Course> &kurs,vector<Classroom> &sinif){
			if(kurs.size()==hocalar.size()*3){
				atama(hocalar,kurs);
				cout<<"kurs sayisi yeterli ve atamalar yapildi"<<endl;	
			}
			
			else{
				cout<<"Lutfen elemantary ders girmeye devam edin ve"<<endl;
				for(int t=0;t<hocalar.size();t++){
					
						if(hocalar[t].ders_sayisi<=2){
							cout<<hocalar[t].get_personal_id()<<" id numarasina sahip "<<hocalar[t].get_name()<<" hocaya ders atayiniz alanlari=";
							for(int j=0;j<hocalar[t].alan.size();j++){
								cout<<hocalar[t].alan[j]<<" ";
							}
							cout<<endl;
							break;	
						}
				}
				
			}
}

void propose(string dz,vector<lecturer> &hocalar,vector<Course> &kurs,vector<Classroom> &sinif){
		string tm,c;
		int sc=0,x,goz=0;	
       	istringstream is (dz);
		while (is.good ()) {
        	is >> tm;
        		if(tm=="-propose" || tm=="exit"){
				}
        		else{
        			++sc;
        			c=tm;
        			if(sc==1){
        				stringstream g(c);
        				g>>x;
        				
        			for(int g=0;g<hocalar.size();g++){
        				if(hocalar[g].get_personal_id()==x){
        					goz=1;
						}	
					}	
        				if(goz==1 && hocalar[x-1].ders_sayisi<3){
        					hocalar[x-1].proposeCourse(dz,kurs);	
						}
							
						else if(goz==0)
						{
							cout<<"Hoca yoktur:";
						}
        			
					}
					
				}
    		}
	
}

void timetable(string dz,vector<lecturer> &hocalar,vector<Course> &kurs,vector<Classroom> &sinif){
		int s=0;
			for(int l=0;l<kurs.size();l++){
				s+=kurs[l].csnf.size();
			}
		if(s!=21){
			//	cout<<"Bu fonksiyondan once -arrangeC fonksiyonu ile siniflari atayiniz:"<<endl;
			}
		else{
			cout<<"----------TIMETABLE-------------"<<endl;
			string a;		
			int m=0,h=0,g=0,sav=0;
			int tut=0,tut1=0;
				while(g<5){
																
					while(h<kurs.size()){
							
						for(int m=0;m<sinif.size();m++){
																							
									if(kurs[h].lecture_date.size()==0){
										
										gunler v3;
										v3.saat_bas=9;
										v3.saat_bit=9+kurs[h].c_total_hours;
																									
										if(g==0){
											v3.gun=Mon;												
										}
										else if(g==1){
											v3.gun=Tue;										
										}
										else if(g==2){
											v3.gun=Wed;											
										}
										else if(g==3){
											v3.gun=Thu;											
										}
										else if(g==4){
											v3.gun=Fri;											
										}
																																																	
										kurs[h].lecture_date.push_back(v3);																													
											
									}
									
									
								
														
								h++;
								if(h==kurs.size()){
									kisit(hocalar,kurs,h-3,h);
									break;
								}										
						}
							
							if(h%6==0){
								kisit(hocalar,kurs,h-6,h);
								g++;
								sav=1;
								break;
							}								
					}
					if(sav==1){	
					sav=0;
					}
					else{
					g++;	
					}
				
				}
				
									for(int h=0;h<kurs.size();h++){
										
									
										if(kurs[h].lecture_date[0].gun==0){
											a="Mon";
												
										}
										else if(kurs[h].lecture_date[0].gun==1){
											a="Tue";
										
										}
										else if(kurs[h].lecture_date[0].gun==2){
											a="Wed";
											
										}
										else if(kurs[h].lecture_date[0].gun==3){
											a="Thu";
											
										}
										else if(kurs[h].lecture_date[0].gun==4){
											a="Fri";
					
										}
																						
							cout<<kurs[h].c_name<<" "<<kurs[h].lecture_date[0].saat_bas<<" "<<kurs[h].lecture_date[0].saat_bit<<" "<<kurs[h].csnf[0].s_no<<" "<<a<<endl;
								
							}
														
		}
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




#endif
