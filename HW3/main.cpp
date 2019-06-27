#include <iostream>
#include"lecturer.h"
#include<fstream>
#include<sstream>
#include<cstring>
#include<vector>
using namespace std;
const int BOYUT=100;
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

void arrangeclassroom1(string dz,vector<lecturer> &hocalar,vector<Course> &kurs,vector<Classroom> &sinif){
		if(kurs.size()!=hocalar.size()*3){
			cout<<"yeterli sayida ders eklenmemis:( -propose komutuyla ders eklemeye devam ediniz"<<endl;
			
		}
		else{	
		int say=0,tut=0;
		int k=0,goz=0,goz1=0;
		string tm,c;
		int sc=0,x;
		Course v2;	
       	istringstream is (dz);
		while (is.good ()) {
        	is >> tm;
        		if(tm=="-arrangeC" || tm=="exit"){
				}
        		else{
        			++sc;
        			c=tm;
					if(sc==1){
						stringstream gk(c);
        				gk>>k;
        				for(int f=0;f<kurs.size();f++){
							if(kurs[f].c_id==k){
								goz1=1;        ///kurs oldugu kontrol
							}
						}
						if(goz1==0){
							cout<<"kurs yoktur:("<<endl;
						}
        				
					}
					if(sc==2){
						for(int m=0;m<sinif.size();m++){
							if(sinif[m].s_no==c){
								tut=m;
								goz=1;             ///sinif oldugu kontrol
							}						
						}
																		
							if(goz==0){
								cout<<"sinif yoktur:("<<endl;
							}
							if(goz==1 && goz1==1){
								kurs[k-1].csnf.push_back(sinif[tut]);
								cout<<kurs[k-1].c_name<<sinif[tut].s_no<<endl;
							}
													
					}
					
					
				}
				
    		}
		}
}

void assign1(string dz,vector<lecturer> &hocalar,vector<Course> &kurs,vector<Classroom> &sinif){
		string tm,c;
		int sc=0,x;	
       istringstream is (dz);
		while (is.good ()) {
        	is >> tm;
        		if(tm=="-assign" || tm=="exit"){
				}
        		else{
        			++sc;
        			c=tm;
        			if(sc==1){
        				stringstream g(c);
        				g>>x;
        				hocalar[x-1].assignCourse(dz,kurs);
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
int main ()
{
	vector<lecturer>hocalar;
	vector<Course>kurs;
	vector<Classroom>sinif;
	int x=0;
    ifstream file;
    file.open("lecturers.txt");
    string line;
    int i=0,j=0;
    string array[BOYUT][BOYUT];
    while (getline(file,line))       ///lecturer dosyasý okunup bilgiler dolduruldu
    {
    	lecturer v1;
        stringstream linestream(line);
        string item;
        while (getline(linestream,item,' '))
        {	
        	array[i][j]=item;	
        	j++;
        }
        stringstream geek(array[i][0]);    ///string int cevrildi
        geek>>x;
        v1.set_personal_id(x);
        v1.set_name(array[i][1]);
        v1.set_surname(array[i][2]);
        v1.set_profession(array[i][3]); 
        string str=array[i][4];
        int k=0;        
        	stringstream al(str);
        	string fer;
        	while (getline(al,fer,','))
        	{
        		
        		v1.alan.push_back(fer);	       ////lecturer field write in vector  	
        	}	
        hocalar.push_back(v1);           ///new lecturer setup
        i++;
        j=0;
    }
    int y,tutgz=0;
    ifstream file1;
    file1.open("courses_classrooms.txt");
    string dizz,dizi,Ar[BOYUT][BOYUT];
    int l=0,m=0;
    while (getline(file1,dizz))       ///lecturer file read 
    {	
        stringstream lin(dizz);
        while (getline(lin,dizi,' '))
        {		
			Ar[l][m]=dizi;
			if(dizi=="CLASSROOMS"){
				tutgz=l;
			}	
        	m++;				
        }
    	l++;
    	m=0; 	
	}
	int a,b,c,d,f;
	for(int g=1;g<tutgz;g++){
		Course v2;
		sscanf(Ar[g][0].c_str(),"%d",&y);
		v2.c_id=y;
		sscanf(Ar[g][2].c_str(),"%d",&a);
		v2.c_code=a;
		sscanf(Ar[g][3].c_str(),"%d",&b);
		v2.c_credit;
		sscanf(Ar[g][4].c_str(),"%d",&c);
		v2.c_total_hours=c;
		v2.c_name=Ar[g][1];
		v2.c_field=Ar[g][5];
        kurs.push_back(v2);
	}
	for(int u=tutgz+1;u<l;u++){
		Classroom v3;
		sscanf(Ar[u][0].c_str(),"%d",&d);
		v3.s_id=d;
		v3.s_no=Ar[u][1];
		sscanf(Ar[u][2].c_str(),"%d",&f);
		v3.student_inroom=f;
		sinif.push_back(v3);
	}
	atama(hocalar,kurs);
		
	string dz;
	int say=0,sayac=0,counter=0;
	while(dz!="exit"){		
	string b;
	cout<<"(input)";
	getline(cin,dz);
		say=0;
		sayac=0;
		while(dz.c_str()[sayac]!='\0'){
			
			if(dz.c_str()[sayac]==' '){
				say++;
			}
			sayac++;
		}
	int gozle=-1;
	gozle=bulstr(dz);	
	string tmps;
    istringstream is (dz);
    while (is.good ()) {
        	is >> tmps;
       		 b=tmps;     
        
        
			if(b=="-propose" && say==6){   ///-porposeCourse  
				counter=1;
				break;
			}
			if(b=="-assign" && say==2){   ///-assign no course_id
				counter=2;
				break;
			}
			if(b=="-assign"){   /// -assign
				counter=3;
				break;
			}
		
			
			if(b=="-timetable" && say==1){   /// -timetable course_id 
				counter=4;
				break;
			}
			
			if(b=="-timetable"){   /// -timetable all program arrangement
				counter=5;
				break;
			}
			
			
			if(b=="-arrangeC" && say==2 && gozle==0){   /// -arrangeC course_id class_id
				counter=6;
				break;
			}
			if(b=="-arrangeC" && say==2 && gozle ){ ///-arrangeC course_id class_id1,class_id2
				counter=7;
				break;
			}
			if(b=="-arrangeC" && say==0){
				counter=8;
				break;
			}
			
			else{
				if(b=="exit")
				cout<<"sistemden cikis yapiliyor...";
				else{
					cout<<"imput seklini yanlis girdiniz:("<<endl;
				break;
				}
				
			}		
			         
    	}
	
		if(counter==1){	   ////-propose p_id ... add lessons		
			propose(dz,hocalar,kurs,sinif);
			counter=0; 	
		}
	
		if(counter==2){		  /// -assign ve p_id c_id assign course
		
			assign1(dz,hocalar,kurs,sinif);
			counter=0;	
		}
		
	
		if(counter==3){       /// -assign  all information assined          
			assign2(dz,hocalar,kurs,sinif);
			counter=0;	
		}
		
		if(counter==4){      ////-timetable course_id 
			int s=0;
			for(int l=0;l<kurs.size();l++){
				s+=kurs[l].csnf.size();
			}
		if(s!=21){
				cout<<"Bu fonksiyondan once -arrangeC fonksiyonu ile siniflari atayiniz:"<<endl;
			}
			
		else{
				
		string tm,c;
		int sc=0,x,goz=0;	
       	istringstream is (dz);
		while (is.good ()) {
        	is >> tm;
        		if(tm=="-timetable" || tm=="exit"){
				}
        		else{
        			++sc;
        			c=tm;
        			if(sc==1){
        				stringstream gkl(c);
        				gkl>>x;
        				
        				for(int d=0;d<kurs.size();d++){
        					if(kurs[d].c_id==x){
        						goz=1;
							}	
						}
						if(goz==0){
							cout<<"Yanlis kurs_id girdiniz:"<<endl;
						}
						if(goz==1){
							
								if(kurs[x-1].lecture_date.size()==0){
									gunler vx;
									vx.saat_bas=9;
									vx.saat_bit=9+kurs[x].c_total_hours;
									vx.gun=Fri;
									kurs[x-1].lecture_date.push_back(vx);
										
								}
																				
						}
						
					}
					
					
				}
    		}
		}
		counter=0;	     
		}                     
		
		if(counter==5){      ////timetable 
			
			int s=0;
			for(int l=0;l<kurs.size();l++){
				s+=kurs[l].csnf.size();
			}
		if(s!=21){
				cout<<"Bu fonksiyondan once -arrangeC fonksiyonu ile siniflari atayiniz:"<<endl;
			}
		else{
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
		counter=0;	
		}
		

		if(counter==6){           /// -arrangeC course_id class_id
			arrangeclassroom1(dz,hocalar,kurs,sinif);
			counter=0;		
		}

		if(counter==7){       ///-arrangeC course_id class_id1, class_id2
			int s=0;
			for(int l=0;l<kurs.size();l++){
				s+=kurs[l].csnf.size();
			}
		
		if(kurs.size()!=hocalar.size()*3 || s!=21){
			cout<<"Lutfen -timetable komutunu giriniz ve tekrar deneyiniz:"<<endl;
		}
		
		else{
					
		int say=0,tut=0;
		int k=0,goz=0,goz1=0;
		string tm,c;
		int sc=0,x,atama1=0,atama2=0;
		Course v2;	
        istringstream is (dz);
		while (is.good ()) {
        	is >> tm;
        		if(tm=="-arrangeC" || tm=="exit"){
				}
        		else{
        			++sc;
        			c=tm;
					if(sc==1){
						stringstream gk(c);
        				gk>>k;
        				for(int f=0;f<kurs.size();f++){
							if(kurs[f].c_id==k){
								goz1=1;        			///check course
							}
						}
						if(goz1==0){
							cout<<"kurs yoktur:("<<endl;
						}
        				
					}
					if(sc==2){
						int a=0,say1=0,say2=0;
						string myText(c);
						string str1,str2;
    					istringstream iss(myText);
    					string token;
    					while (getline(iss, token,','))
    						{
    							if(a==0){
    								str1=token;
    								a++;
								}
								if(a==1){
									str2=token;
								}
							
    						}
    						for(int g=0;g<sinif.size();g++){
    							if(sinif[g].s_no==str1){
    								say1=1;
								}
								if(sinif[g].s_no==str2){
									say2=1;
								}
							}
							if(say1==1 && say2==1){    ///the program is applied if the course is correct
								for(int k=0;k<kurs.size();k++){
									if(kurs[k].csnf[0].s_no==str1 ||kurs[k].csnf[0].s_no==str2 ){
										atama1=1;
									}
								}
								if(atama1==1){
									cout<<"Siniflara baska dersler atandi"<<endl;
								}
							
								
							}
							else{
								
								cout<<"class_id yanlis girilmistir komutu tekrar deneyiniz:(";
							}																					
					}
						
				}
				
    		}
    	}
				
		counter=0;	
		}


		if(counter==8){     ///-arrangeC courses are assigned to automatic classes
			arrangeclassroom3(dz,hocalar,kurs,sinif);
			counter=0;
		}

	  		
	}//big loops
	
	
    return 0;
}
