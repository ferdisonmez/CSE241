#include"lecturer.h"

int main ()
{
	const int BOYUT=100;
	vector<lecturer>hocalar;
	vector<Course>kurs;
	vector<Classroom>sinif;
	vector<Student>ogrenci;
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
	for(int g=1;g<19;g++){
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
	for(int u=20;u<26;u++){
		Classroom v3;
		sscanf(Ar[u][0].c_str(),"%d",&d);
		v3.s_id=d;
		v3.s_no=Ar[u][1];
		sscanf(Ar[u][2].c_str(),"%d",&f);
		v3.capacity=f;
		v3.student_inroom=0;
		sinif.push_back(v3);
	}
	atama(hocalar,kurs);
		
	string dz;
	int say=0,sayac=0,counter=0;
	cout<<"LUTFEN HERHANGI BIR OGRENCI EKLEYINIZ:(example:-ns Murat Boz 111 4)"<<endl;
	cout<<"LUTFEN ELEMENTARY DERSLERI UNUTMAYINIZ!!!"<<endl;
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
        
        	if(b=="-ns" && say==4){   ///-ns 
				counter=9;
				break;
			}
			if(b=="-propose" && say==6){   ///-porposeCourse  
				counter=1;
				break;
			}
			
			if(b=="-enter" && say==3){   ///-enter student_id classroom_id  
				counter=2;
				break;
			}
			if(b=="-quit" && say==1){   ///-quit student_id 
				counter=11;
				break;
			}
			if(b=="-attendance" && say==1){   ///-attendance course_id  
				counter=4;
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
		if(counter==11){
			quitclassroom(dz,ogrenci,sinif);
			counter=0;
		}
		
		if(counter==1){	   ////-propose p_id ... add lessons		
			propose(dz,hocalar,kurs,sinif);
			counter=3; 	
		}
	
	
		if(counter==3){       /// -assign  all information assined          
			assign2(dz,hocalar,kurs,sinif);
			counter=8;	
		}
		
		if(counter==8){     ///-arrangeC courses are assigned to automatic classes
			arrangeclassroom3(dz,hocalar,kurs,sinif);
			counter=5;
		}
		
                  	
		if(counter==5){      ////timetable 	
		timetable(dz,hocalar,kurs,sinif);
		counter=0;	
		}
		if(counter==2){   /// -enter student_id classroom_id hour_of_week	 	
		enterclassroom(dz,ogrenci,kurs,sinif);
		counter=0;	
		}
		
		if(counter==4){
		attendance(dz,kurs,sinif);
		counter=0;	
		}				
			
				
		if(counter==9){
    		kayit(dz,ogrenci);
    		counter=0;
		}

	  		
	}//big loops
	
	
    return 0;
}
