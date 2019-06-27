#include"personal.h"
#include"edu.h"
#include"complex.h"
const int BOYUT=100;
const int liberal_action=14;
const int communist_action=12;
const int capitalist_action=15;
typedef struct{
string a;
string b;	
}d;

d don(d df,int t){  ///what is called the job
	
	if(t==1){df.a="document",df.b="makeDoc";return df; };if(t==2){df.a="slackness",df.b="drinkTea";return df; };if(t==7){df.a="administration",df.b="manageProcess";return df; };if(t==11){df.a="solution",df.b="submitPetition";return df; }
	if(t==3){df.a="project",df.b="research";return df; };if(t==4){df.a="lesson",df.b="giveLesson";return df; };if(t==5){df.a=" seminar",df.b="seeSuccessfulStudent";return df; };if(t==6){df.a="academicPaper",df.b="makePublish ";return df; }
	if(t==8){df.a=" HomeworkTime",df.b="giveHW ";return df;  };if(t==9){df.a="homeworkTimeout",df.b="readHW";return df; };if(t==10){df.a="incident",df.b="receivePetition";return df; }
	
}
void conthesapla(int* dizi){  ///the most helpful person
	for(int g=0;g<liberal_action;g++){
	int t=1+rand()%11;
	if(t==document ){
		dizi[3]+=3;
	}
	if(t==slackness){
		dizi[0]+=(-2);
		dizi[1]+=(-2);
		dizi[2]+=(-2);
		dizi[3]+=(-2);
	}
	if(t==project){
		dizi[1]+=4;
	}
	if(t==lesson){
		dizi[0]+=5;	
	}
	if(t==seminar ){
		dizi[0]+=0;
		dizi[1]+=0;
	}
	if(t==academicPaper ){
		dizi[0]+=5;
		dizi[1]+=5;
	}
	if(t==administration){
		dizi[2]+=2;	
		dizi[3]+=2;
	}
	if(t==HomeworkTime ){
		dizi[0]+=2;
		dizi[1]+=2;
	}
	if(t==incident ){
		dizi[2]+=(-1);
	}

	if(t==solution){ 
		dizi[0]+=(-2);
		dizi[1]+=(-2);
		dizi[2]+=(-2);
		dizi[3]+=(-2);
	}
  }
  
}
double formul(double x){   ///money calculation
	return (x*3)/2-1;
}
bool comp(vector<Employee*>&a,vector<isci>&isci_liste,int sec){   ////check that the person has
	for(int i=0;i<a.size();i++){
		if(a[i]->get_name()==isci_liste[sec].isim && a[i]->get_surname()==isci_liste[sec].soyisim){
			return true;	
		}		
	}
	return false;
}

int main() {
	
	srand(time(NULL));
    vector<isci>Liste;
    vector<isci>isci_liste;
    vector<isci>broker_liste;
    ifstream file1;
    file1.open("personnellist.txt");  ///read file
    string line2,str2;
    int i=0,j=0,x=0;
    string array2[BOYUT][BOYUT];
    while (getline(file1,line2))    ///read text line by line 
    {
    	isci v1;
        stringstream linestream(line2);
        string item2;
        while (getline(linestream,item2,' '))  ///seperate text space by space
        {	
        	array2[i][j]=item2;	
        	j++;
        }
        
        v1.isim=array2[i][0];
        v1.soyisim=array2[i][1];
        v1.yap_is=array2[i][2];
        Liste.push_back(v1);          ///store class Emplooye in vector
        i++;
        j=0;
       
    }
    for(int j=0;j<Liste.size();j++){
    	if(Liste[j].yap_is=="W"){
    		isci_liste.push_back(Liste[j]);	///fill isci_list
		}
		if(Liste[j].yap_is=="B"){
    		broker_liste.push_back(Liste[j]); ///fill broker_list
		}
	}
    
    string sec="";
    int tx=1;
    while(sec!="exit"){
    if(sec!="exit")
    cout<<"Egitim sistemini seciniz:"<<endl;
    cin>>sec;
    	  
if(sec=="L" || sec=="l"){
    		
    cout<<"**********************************"<<endl;
	cout<<"****** LIBERAL UNIVERSITY  *****"<<endl;	
	cout<<"**********************************"<<endl;
	
	University<int> *n;       ///university established
	LiberalEducation<int> b;
	n=b.foundUni(tx);
	LibUni<int>* a=dynamic_cast<LibUni<int>*> (n);
	int dizi[4]={0};
	int index=0;
	conthesapla(dizi); 
	int sayi=dizi[0];
	for(int i=1;i<4;i++){
		if(dizi[i]>sayi){
			sayi=dizi[i];
			index=i;
		}
	}
	 string h="\0"; 
	 int l=rand()%isci_liste.size(); ///choose random number
	if(index==0){
		cout<<"I see that there is an opportunity for being (liblecturer)in the university.So I am liblecturer."<<endl;				
	}
	if(index==1){
		cout<<"I see that there is an opportunity for being (libResearchAssistant)in the university. So I am libResearchAssistant ."<<endl;
	}
	if(index==2){
	cout<<"I see that there is an opportunity for being (libsecretary)in the university. So I am libsecretary."<<endl;
	}
	if(index==3){
		cout<<"I see that there is an opportunity for being (libOfficer)in the university.So I am libOfficer."<<endl;
	}
	
		if(index==0){
			h="Lecturer";
			Employee* x=new libLec();  ///object of derived class
			x->set_unvan(h);
			
			for(int g=0;g<liberal_action;g++){
			int t=1+rand()%11; ///random numbers selected
				d dz;
				dz=don(dz,t);
				cout<<"Liberal University has "<<dz.a<<" ";	
				if(t==lesson || t==seminar || t==academicPaper || t==HomeworkTime || t==slackness ||t==solution){  //it is determined what the object can do
				int cn=x->work(t);
				a->set_contribution(a->get_contribution()+cn);
					cout<<x->get_name()<<" "<<x->get_surname()<<" did work "<<dz.b;
					cout<<" My happiness is "<<x->get_happiness()<<"  I contribute "<<a->get_contribution()<<" to university"<<endl;	
				}
				else{
					cout<<"I cannot do that"<<endl;
				}
				
			}
			cout<<"After all my happiness is "<<x->get_happiness()<<" My money is "<<a->get_contribution()<<" Contribution of university is "<<a->get_contribution()<<endl;
		}
		
			
		if(index==1){
			Employee* y=new libResAssist();///object of derived class	
			h="ResearchAssistant";
			y->set_unvan(h);
		
			for(int g=0;g<liberal_action;g++){
				int t=1+rand()%11; ///random numbers selected
				d dz;
				dz=don(dz,t);
				cout<<"Liberal University has "<<dz.a<<" ";
				if(t==project || t==seminar || t==academicPaper || t==homeworkTimeout ||t==slackness ||t==solution){  //it is determined what the object can do
					int cn=y->work(t);
					a->set_contribution(a->get_contribution()+cn);
					cout<<y->get_name()<<" "<<y->get_surname()<<" did work "<<dz.b;
					cout<<" My happiness is "<<y->get_happiness()<<"  I contribute "<<a->get_contribution()<<" to university"<<endl;	
				}
				else{
					cout<<"I cannot do that"<<endl;
					}
			
			}
			cout<<"After all my happiness is "<<y->get_happiness()<<" My money is "<<a->get_contribution()<<" Contribution of university is "<<a->get_contribution()<<endl;
		}	
		if(index==2){
			Employee* z=new libSec();///object of derived class	
			h="Secretary";
			z->set_unvan(h);
			
			for(int g=0;g<liberal_action;g++){
			int t=1+rand()%11; ///random numbers selected
				d dz;
				dz=don(dz,t);
				cout<<"Liberal University has "<<dz.a<<" ";
				if(t==administration || t==incident ||t==slackness ||t==solution){ //it is determined what the object can do
				int cn=z->work(t);
					a->set_contribution(a->get_contribution()+cn);
					cout<<z->get_name()<<" "<<z->get_surname()<<" did work "<<dz.b;
					cout<<" My happiness is "<<z->get_happiness()<<"  I contribute "<<a->get_contribution()<<" to university"<<endl;
				}
				else{
					cout<<"I cannot do that"<<endl;
				}
	
			}
			cout<<"After all my happiness is "<<z->get_happiness()<<" My money is "<<a->get_contribution()<<" contribution of university is "<<a->get_contribution()<<endl;
		}
		if(index==3){
			Employee* v=new libOff();	///object of derived class
			h="Officer";
			v->set_unvan(h);
			
			for(int g=0;g<liberal_action;g++){
			int t=1+rand()%11; ///random numbers selected
				d dz;
				dz=don(dz,t);
				cout<<"Liberal University has "<<dz.a<<" ";
				if(t==document || t==administration || t==slackness ||t==solution ){ //it is determined what the object can do
				int cn=v->work(t);
					a->set_contribution(a->get_contribution()+cn);
					cout<<v->get_name()<<" "<<v->get_surname()<<" did work "<<dz.b;
					cout<<" My happiness is "<<v->get_happiness()<<"  I contribute "<<a->get_contribution()<<" to university"<<endl;
				}
				else{
					cout<<"I cannot do that"<<endl;
				}
	
			}
			
			cout<<"After all my happiness is "<<v->get_happiness()<<" My money is "<<a->get_contribution()<<" contribution of university is "<<a->get_contribution()<<endl;
		}
			
			
    		
}///liberal sistem
    	
else if(sec=="Com" || sec=="com" || sec=="COM"){
    cout<<"**********************************"<<endl;
	cout<<"****** COMMUNIST UNIVERSITY  *****"<<endl;	
	cout<<"**********************************"<<endl;
	
	University<double> *n;  
	CommunistEducation<double> b;
	n=b.foundUni(tx);
	ComUni<double>* a=dynamic_cast<ComUni<double>*> (n);
	
	int y=0;	
	string h="\0";
	for(int y=0;y<4;y++){
		int l=rand()%19;
		cout<<"Communist University requests ";
		if(y==0){
			h="Lecturer";
			Employee* x=new comLec();  ///object of derived class
			x->set_unvan(h);
			a->ComUni_kisiler.push_back(b.givejob(x,isci_liste[l].isim,isci_liste[l].soyisim,y));///a new person is hired		
		}
		if(y==1){
			Employee* yv=new libResAssist();///object of derived class	
			h="ResearchAssistant";
			yv->set_unvan(h);
			a->ComUni_kisiler.push_back(b.givejob(yv,isci_liste[l].isim,isci_liste[l].soyisim,y));///a new person is hired
		
		}
		if(y==2){	
			Employee* z=new libSec();///object of derived class	
			h="Secretary";
			z->set_unvan(h);
			a->ComUni_kisiler.push_back(b.givejob(z,isci_liste[l].isim,isci_liste[l].soyisim,y));///a new person is hired	
		
		}
		if(y==3){
				Employee* v=new libOff();	///object of derived class
				h="Officer";
				v->set_unvan(h);
				a->ComUni_kisiler.push_back(b.givejob(v,isci_liste[l].isim,isci_liste[l].soyisim,y));///a new person is hired	
		
		}
	
		cout<<h<<endl;
		cout<<"YOK give job to "<<isci_liste[l].isim<<" "<<isci_liste[l].soyisim<<" as "<<h<<endl;
			
		cout<<"Liberal University"<<" employs "<<isci_liste[l].isim<<" "<<isci_liste[l].soyisim<<" as "<<h<<endl;
		cout<<endl;
		isci_liste.erase(isci_liste.begin()+l);
	}
	int g=0;
	for(int i=0;i<a->ComUni_kisiler.size();i++){
		if(a->ComUni_kisiler[i]->get_unvan()=="Lecturer"){
			
			while(g<3){
				int t=1+rand()%11;
				d dz;
				dz=don(dz,t);
				cout<<"Communist University has "<<dz.a<<" ";	
				if(t==lesson || t==seminar || t==academicPaper || t==HomeworkTime || t==slackness ||t==solution){ //it is determined what the object can do
				int cn=a->ComUni_kisiler[i]->work(t);
				a->set_contribution(a->get_contribution()+cn);
					cout<<a->ComUni_kisiler[i]->get_name()<<" "<<a->ComUni_kisiler[i]->get_surname()<<" did work "<<dz.b;
					cout<<" My happiness is "<<a->ComUni_kisiler[i]->get_happiness()<<"  I contribute "<<a->get_contribution()<<" to university"<<endl;
					g++;	
				}
				else{
					cout<<"I cannot do that"<<endl;
				}
				
			}
		}
		g=0;
		if(a->ComUni_kisiler[i]->get_unvan()=="ResearchAssistant"){
			
			while(g<3){
				int t=1+rand()%11;
				d dz;
				dz=don(dz,t);
				cout<<"Communist University has "<<dz.a<<" ";	
				if(t==project || t==seminar || t==academicPaper || t==homeworkTimeout ||t==slackness ||t==solution){  //it is determined what the object can do
				int cn=a->ComUni_kisiler[i]->work(t);
				a->set_contribution(a->get_contribution()+cn);
					cout<<a->ComUni_kisiler[i]->get_name()<<" "<<a->ComUni_kisiler[i]->get_surname()<<" did work "<<dz.b;
					cout<<" My happiness is "<<a->ComUni_kisiler[i]->get_happiness()<<"  I contribute "<<a->get_contribution()<<" to university"<<endl;
					g++;	
				}
				else{
					cout<<"I cannot do that"<<endl;
				}
				
			}
		}
		g=0;
		if(a->ComUni_kisiler[i]->get_unvan()=="Secretary"){
			
			while(g<3){
				int t=1+rand()%11;
				d dz;
				dz=don(dz,t);
				cout<<"Communist University has "<<dz.a<<" ";	
				if(t==administration || t==incident ||t==slackness ||t==solution){ //it is determined what the object can do
				int cn=a->ComUni_kisiler[i]->work(t);
				a->set_contribution(a->get_contribution()+cn);
					cout<<a->ComUni_kisiler[i]->get_name()<<" "<<a->ComUni_kisiler[i]->get_surname()<<" did work "<<dz.b;
					cout<<" My happiness is "<<a->ComUni_kisiler[i]->get_happiness()<<"  I contribute "<<a->get_contribution()<<" to university"<<endl;
					g++;	
				}
				else{
					cout<<"I cannot do that"<<endl;
				}
				
			}
		}
		g=0;
		if(a->ComUni_kisiler[i]->get_unvan()=="Officer"){
			
			while(g<3){
				int t=1+rand()%11; ///
				d dz;
				dz=don(dz,t);
				cout<<"Communist University has "<<dz.a<<" ";	
				if(t==document || t==administration || t==slackness ||t==solution ){ //it is determined what the object can do
				int cn=a->ComUni_kisiler[i]->work(t);
				a->set_contribution(a->get_contribution()+cn);
					cout<<a->ComUni_kisiler[i]->get_name()<<" "<<a->ComUni_kisiler[i]->get_surname()<<" did work "<<dz.b;
					cout<<" My happiness is "<<a->ComUni_kisiler[i]->get_happiness()<<"  I contribute "<<a->get_contribution()<<" to university"<<endl;
					g++;	
				}
				else{
					cout<<"I cannot do that"<<endl;
				}
				
			}
		}
		
	
	}

	   		
}
		
else if(sec=="Cap" || sec=="cap"){
    cout<<"**********************************"<<endl;
	cout<<"****** CAPITALIST UNIVERSITY  *****"<<endl;	
	cout<<"**********************************"<<endl;
	
	University<complex> *n;  
	CapitalistEducation<complex> b;
	n=b.foundUni(tx);
	CapUni<complex>* a=dynamic_cast<CapUni<complex>*> (n);
	
	
	
	brokerLec* brokerlec=new brokerLec;    ///object of derived class
	brokerResAssist* brokerass=new brokerResAssist; ///object of derived class
	brokerSec* brokersec=new brokerSec; ///object of derived class
	brokerOff* brokeroff=new brokerOff; ///object of derived class
	
	brokerlec->next=brokerass; ///objects linked together by list
	brokerass->next=brokersec;
	brokersec->next=brokeroff; ///objects linked together by list
	brokeroff->next=NULL;
	int sec=-1;
	string h="\0";
	int g=0,cn=0;
	for(int i=0;i<4;i++){
		int l=rand()%broker_liste.size(); ///choose random number
		cout<<"Capitalist University requests ";
	if(i==0){
			h="BrokerLecturer";
			brokerlec->set_unvan(h);
			a->CapUni_kisiler.push_back(b.givejob(brokerlec,broker_liste[l].isim,broker_liste[l].soyisim,i));///a new person is hired
		for(int j=0;j<2;j++){
			
				if(j==0){
					for(;;){
						sec=rand()%isci_liste.size(); ///choose random number
						if(0==comp(a->CapUni_kisiler,isci_liste,sec)){
						break;
						}	
					}	
				h="workerLecturer";
				Employee* x=new workerLec();  ///object of derived class
				x->set_unvan(h);
				a->CapUni_kisiler.push_back(b.givejob(x,isci_liste[sec].isim,isci_liste[sec].soyisim,sec));///a new person is hired
					brokerlec->sol=x;
					while(g<2){
						int t=rand()%11; ///choose random number
						
						if(t==lesson || t==seminar || t==academicPaper || t==HomeworkTime || t==slackness ||t==solution){
							cn=brokerlec->sol->work(t);
							cout<<brokerlec->sol->get_name()<<" "<<brokerlec->sol->get_surname()<<" did work ";
						g++;
						complex c1;     ///a new value is defined
						c1.set_int_real(cn);
						c1.set_int_imag(0);
						c1.set_double_real(cn);
						c1.set_double_imag(0);
						a->set_contribution(a->get_contribution()+c1);
					cout<<" My happiness is "<<brokerlec->sol->get_happiness()<<"  I contribute "<<a->get_contribution()<<" to university"<<endl;
						}
					}
					
				}
			
				if(j==1){
					g=0;
					cn=0;
					for(;;){
						sec=rand()%isci_liste.size(); ///choose random number
						if(0==comp(a->CapUni_kisiler,isci_liste,sec)){
						break;
						}	
					}
				h="workerLecturer";
				
				Employee* x=new workerLec();  ///object of derived class
				x->set_unvan(h);
				a->CapUni_kisiler.push_back(b.givejob(x,isci_liste[sec].isim,isci_liste[sec].soyisim,sec));///a new person is hired
					brokerlec->sag=x;
					while(g<2){
					int t=rand()%11;
					if(t==lesson || t==seminar || t==academicPaper || t==HomeworkTime || t==slackness ||t==solution){
							cn=brokerlec->sag->work(t);
							cout<<brokerlec->sag->get_name()<<" "<<brokerlec->sag->get_surname()<<" did work ";
						g++;
					complex c1;     ///a new value is defined
					c1.set_int_real(cn);
					c1.set_int_imag(0);
					c1.set_double_real(cn);
					c1.set_double_imag(0);
					a->set_contribution(a->get_contribution()+c1);
					cout<<" My happiness is "<<brokerlec->sag->get_happiness()<<"  I contribute "<<a->get_contribution()<<" to university"<<endl;
						}
					}
				
				}
								
		}
		
		complex hesap=a->get_contribution();
		hesap.set_int_real(formul(hesap.get_int_real()));
		hesap.set_int_imag(0);
		hesap.set_double_real(formul(hesap.get_double_real()));
		hesap.set_double_imag(formul(hesap.get_double_real()));
		cout<<"******Lecturer broker money "<<hesap<<endl;
	}
		
	
		if(i==1){
			h="BrokerResearchassistant";
			brokerass->set_unvan(h);
			a->CapUni_kisiler.push_back(b.givejob(brokerass,broker_liste[l].isim,broker_liste[l].soyisim,i));///a new person is hired	
		for(int j=0;j<2;j++){
			
				if(j==0){
					g=0;
					for(;;){
						sec=rand()%isci_liste.size(); ///choose random number
						if(0==comp(a->CapUni_kisiler,isci_liste,sec)){
						break;
						}	
					}
					h="workerResearchassistant";
					Employee* x=new workerResAssist();  ///object of derived class
					x->set_unvan(h);
					a->CapUni_kisiler.push_back(b.givejob(x,isci_liste[sec].isim,isci_liste[sec].soyisim,sec));///a new person is hired
					brokerass->sol=x;
					while(g<2){
						int t=rand()%11;
						if(t==project || t==seminar || t==academicPaper || t==homeworkTimeout ||t==slackness ||t==solution){
							cn=brokerass->sol->work(t);
							cout<<brokerass->sol->get_name()<<" "<<brokerass->sol->get_surname()<<" did work ";
						g++;
						complex c1;     ///a new value is defined
						c1.set_int_real(cn);
						c1.set_int_imag(0);
						c1.set_double_real(cn);
						c1.set_double_imag(0);
						a->set_contribution(a->get_contribution()+c1);
					cout<<" My happiness is "<<brokerass->sol->get_happiness()<<"  I contribute "<<a->get_contribution()<<" to university"<<endl;
						}
					}
						
				}
			
				if(j==1){
					g=0;
					for(;;){
						sec=rand()%isci_liste.size();
						if(0==comp(a->CapUni_kisiler,isci_liste,sec)){
						break;
						}	
					}
					h="workerResearchassistant";
					Employee* x=new workerResAssist();  ///object of derived class
					x->set_unvan(h);
					a->CapUni_kisiler.push_back(b.givejob(x,isci_liste[sec].isim,isci_liste[sec].soyisim,sec));///a new person is hired
					brokerass->sag=x;
					while(g<2){
						int t=rand()%11; ///choose random number
						if(t==project || t==seminar || t==academicPaper || t==homeworkTimeout ||t==slackness ||t==solution){
							cn=brokerass->sag->work(t);
							cout<<brokerass->sag->get_name()<<" "<<brokerass->sag->get_surname()<<" did work ";
						g++;
						complex c1;     ///a new value is defined
						c1.set_int_real(cn);
						c1.set_int_imag(0);
						c1.set_double_real(cn);
						c1.set_double_imag(0);
						a->set_contribution(a->get_contribution()+c1);
					cout<<" My happiness is "<<brokerass->sag->get_happiness()<<"  I contribute "<<a->get_contribution()<<" to university"<<endl;
						}
					}
						
				}
				
		}	
			
		complex hesap=a->get_contribution();
		hesap.set_int_real(formul(hesap.get_int_real()));
		hesap.set_int_imag(0);
		hesap.set_double_real(formul(hesap.get_double_real()));
		hesap.set_double_imag(formul(hesap.get_double_real()));
		cout<<"******ResearchAssistant broker money "<<hesap<<endl;		
	}
		
		
		if(i==2){
			h="BrokerSecretary";
			brokersec->set_unvan(h);
			a->CapUni_kisiler.push_back(b.givejob(brokersec,broker_liste[l].isim,broker_liste[l].soyisim,i));///a new person is hired	
			
			for(int j=0;j<2;j++){
			
				if(j==0){
					g=0;
					for(;;){
						sec=rand()%isci_liste.size(); ///choose random number
						if(0==comp(a->CapUni_kisiler,isci_liste,sec)){
						break;
						}	
					}
					h="workerResearchassistant";
					Employee* x=new workerSec();  ///object of derived class
					x->set_unvan(h);
					a->CapUni_kisiler.push_back(b.givejob(x,isci_liste[sec].isim,isci_liste[sec].soyisim,sec));///a new person is hired
					brokersec->sol=x;
					while(g<2){
						int t=rand()%11;
						if(t==project || t==seminar || t==academicPaper || t==homeworkTimeout ||t==slackness ||t==solution){
							cn=brokersec->sol->work(t);
							cout<<brokersec->sol->get_name()<<" "<<brokersec->sol->get_surname()<<" did work ";
						g++;
						complex c1;     ///a new value is defined
						c1.set_int_real(cn);
						c1.set_int_imag(0);
						c1.set_double_real(cn);
						c1.set_double_imag(0);
						a->set_contribution(a->get_contribution()+c1);
					cout<<" My happiness is "<<brokersec->sol->get_happiness()<<"  I contribute "<<a->get_contribution()<<" to university"<<endl;
						}
					}
						
				}
			
				if(j==1){
					g=0;
					for(;;){
						sec=rand()%isci_liste.size();
						if(0==comp(a->CapUni_kisiler,isci_liste,sec)){
						break;
						}	
					}
					h="workerResearchassistant";
					Employee* x=new workerResAssist();  ///object of derived class
					x->set_unvan(h);
					a->CapUni_kisiler.push_back(b.givejob(x,isci_liste[sec].isim,isci_liste[sec].soyisim,sec));///a new person is hired
					brokersec->sag=x;
					while(g<2){
						int t=rand()%11; ///choose random number
						if(t==project || t==seminar || t==academicPaper || t==homeworkTimeout ||t==slackness ||t==solution){
							cn=brokersec->sag->work(t);
							cout<<brokersec->sag->get_name()<<" "<<brokersec->sag->get_surname()<<" did work ";
						g++;
						complex c1;     ///a new value is defined
						c1.set_int_real(cn);
						c1.set_int_imag(0);
						c1.set_double_real(cn);
						c1.set_double_imag(0);
						a->set_contribution(a->get_contribution()+c1);
					cout<<" My happiness is "<<brokersec->sag->get_happiness()<<"  I contribute "<<a->get_contribution()<<" to university"<<endl;
						}
					}
						
				}
			
				
			}
		complex hesap=a->get_contribution();
		hesap.set_int_real(formul(hesap.get_int_real()));
		hesap.set_int_imag(0);
		hesap.set_double_real(formul(hesap.get_double_real()));
		hesap.set_double_imag(formul(hesap.get_double_real()));
		cout<<"******Secretary broker money "<<hesap<<endl;		
		}
		
		
		if(i==3){
			h="BrokerOfficer";
			brokeroff->set_unvan(h);
			a->CapUni_kisiler.push_back(b.givejob(brokeroff,broker_liste[l].isim,broker_liste[l].soyisim,i));///a new person is hired	
			
			for(int j=0;j<2;j++){
			
				if(j==0){
					g=0;
					for(;;){
						sec=rand()%isci_liste.size(); ///choose random number
						if(0==comp(a->CapUni_kisiler,isci_liste,sec)){
						break;
						}	
					}
					h="workerOfficer";
					Employee* x=new workerSec();  ///object of derived class
					x->set_unvan(h);
					a->CapUni_kisiler.push_back(b.givejob(x,isci_liste[sec].isim,isci_liste[sec].soyisim,sec));///a new person is hired
					brokeroff->sol=x;
					while(g<2){
						int t=rand()%11;
						if(t==project || t==seminar || t==academicPaper || t==homeworkTimeout ||t==slackness ||t==solution){
							cn=brokeroff->sol->work(t);
							cout<<brokeroff->sol->get_name()<<" "<<brokeroff->sol->get_surname()<<" did work ";
						g++;
						complex c1;     ///a new value is defined
						c1.set_int_real(cn);
						c1.set_int_imag(0);
						c1.set_double_real(cn);
						c1.set_double_imag(0);
						a->set_contribution(a->get_contribution()+c1);
					cout<<" My happiness is "<<brokeroff->sol->get_happiness()<<"  I contribute "<<a->get_contribution()<<" to university"<<endl;
						}
					}
						
				}
				
			}	
			
		complex hesap=a->get_contribution();
		hesap.set_int_real(formul(hesap.get_int_real()));
		hesap.set_int_imag(0);
		hesap.set_double_real(formul(hesap.get_double_real()));
		hesap.set_double_imag(formul(hesap.get_double_real()));
		cout<<"******Officer broker money "<<hesap<<endl;	
		}
		
			
	}
			  		
}
else{
	if(sec=="exit"){
	}
else
	cout<<"Wrong input please try again!!!"<<endl;
}
	
}
	cout<<"Sistemden cikis yapiliyor..."<<endl;
	
	return 0;
}
