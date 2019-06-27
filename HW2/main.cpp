#include"student.h"
using namespace hw2;
void sinif_fill(ifstream& file,Classroom sinif[],string array[][BOYUT]){
	
	
	file.open("courses_classrooms.txt");
    string line;
    int i=0,j=0;
    
    while (getline(file, line))
    {
        stringstream linestream(line);
        string item;
        while (getline(linestream,item,' '))
        {			
        	array[i][j]=item;    	
        	j++;
        }
        i++;
        j=0;
    }
    int u=1;
    for(int y=10;y<16;y++){     ///// class has been taken and struct has been created 1 started
    	sinif[u].id=atoi(array[y][0].c_str());
    	sinif[u].c_no=array[y][1];
    	sinif[u].capacity=atoi(array[y][2].c_str());
    	u++;
	}
		
}
void kurs_fill(string array[][BOYUT],Course kurs[]){
	string w;
	char a[BOYUT],b[BOYUT],c[BOYUT][BOYUT];
	int k,l=0,p=0,i=0;
    for(i=1;i<9;i++){
    	
    	for( k=0;k<array[i][5].length();k++){
    		a[k]=array[i][5].c_str()[k];      	
		}
    	a[k]='\0';
     int q=0;	
   	 l=0,p=0;
    		while(a[l]!='\0'){
    			l++;
    			if(a[l]==','){
    			p=l++;	
				}	
    			if(a[l]=='_' ){
    				while(p<l){
    				c[i][q]=a[p];	
					p++;
					q++;	
					}	
    			if(a[l]=='_')
				l++;		
				}			
	  	}
	  	int m=0;
	  	while(a[m]!='\0'){
	  		if((a[m]=='_' || a[m]=='-' || a[m]==',') ){
	  			a[m]=' ';
			  }	  
	  		m++;
		  }
		  w=a;		
		  int y=0,x=0;
		  string tmps;
    	istringstream is (w);
    	while (is.good ()) {
        	is >> tmps;
        	if(atoi(tmps.c_str())!=0)
        	{
        		kurs[i].hours[y]=atoi(tmps.c_str());
				y++;	
			}
			else{
				kurs[i].lecture_dates[x]=tmps;	
				x++;
			}      
    	}   	  	
	  	kurs[i].id=atoi(array[i][0].c_str());
		kurs[i].name=array[i][1];
		kurs[i].code=atoi(array[i][2].c_str());
		kurs[i].credit=atoi(array[i][3].c_str());
		kurs[i].total=atoi(array[i][4].c_str());	
	}
		
}
int bosluk_say(string dizi,int say){
		
		int sayac=0;
		while(dizi.c_str()[sayac]!='\0'){
			
			if(dizi.c_str()[sayac]==' '){
				say++;
			}
			sayac++;
		}
	return say;
}

int main(){
	vector<Student>ogrenci;	
	Classroom sinif[BOYUT];  /// keeps class information in file
	Course kurs[BOYUT];     ///course information in the file is kept
	ofstream dosya;
	ofstream hepdosya;
	
    string dizi;
    ifstream file;
    string array[BOYUT][BOYUT];
   	sinif_fill(file,sinif,array);
   	kurs_fill(array,kurs);
    
 
	int sayac=0;
	int counter=0;
	
	while(dizi!="exit"){   ///big loops
	int say=0;	
	string b;
	cout<<"(input)";
	getline(cin,dizi);
	say=bosluk_say(dizi,say);	
    string tmps;
    istringstream is (dizi);
    while (is.good ()) {
        	is >> tmps;
       		 b=tmps;     
        
			if(b=="-ns" && say==4){   ///-ns 
				counter=1;
				break;
			}
			if(b=="-e" && say==2){   /// number and code
				counter=2;
				break;
			}
			if(b=="-o" && say==1){   /// -o and number
				counter=3;
				break;
			}
			if(b=="-o" && say==0 && b!="exit"){   /// -o all student of the information
				counter=4;
				break;
			}
			if(b=="-o" && say==3){   /// -o -f no file.txt 
				counter=5;
				break;
			}
			if(b=="-o" && say==2){   /// -o -f file.txt 
				counter=6;
				break;
			}
			if(b=="-de" && say==2){
				counter=7;
				break;
			}		
			if(b =="-list"){   /// show lessons 
			
				for(int f=1;f<9;f++){
				cout<<kurs[f].id<<"-"<<kurs[f].name<<endl;				
				}
			}         
    	}  
    	
    	
    	if(counter==1){
    		kayit(dizi,ogrenci);
		}
		if(counter==2){
			nokayit(dizi,ogrenci,sinif,kurs);
		}
		if(counter==3){
			owithno(dizi,ogrenci);
		}
		if(counter==4 && b!="exit"){
		  ynlzno(dizi,ogrenci);
		}
		if(counter==5){
			dosyano(dizi,ogrenci,dosya);
		}
		if(counter==6){
			alldosya(dizi,ogrenci,hepdosya);
		}
		if(counter==7){
			derscikar(dizi,ogrenci,sinif,kurs);
		}
	
	 }  ///big loops
	
	return 0;
}


