#include "personal.h"
const int BOYUT=100;
const int arraysize=50;
typedef enum    ///functions defined as enum
{
	document=1,slackness,project,lesson,seminar,academicPaper,administration,HomeworkTime,homeworkTimeout,incident,solution
}action;

int main(){
	srand(time(NULL));
    vector<Employee>EMPListe1;
    vector<Employee>EMPListe;
    ifstream file1;
    file1.open("personnellist.txt");  ///read file
    string line2,str2;
    int i=0,j=0,x=0;
    string array2[BOYUT][BOYUT];
    while (getline(file1,line2))    ///read text line by line 
    {
    	Employee v1;
        stringstream linestream(line2);
        string item2;
        while (getline(linestream,item2,' '))  ///seperate text space by space
        {	
        	array2[i][j]=item2;	
        	j++;
        }
        stringstream geek(array2[i][0]); 
        geek>>x;
        v1.set_pid(x);
        v1.set_unvan(array2[i][1]);
        v1.set_name(array2[i][2]);
        v1.set_surname(array2[i][3]);
        EMPListe1.push_back(v1);          ///store class Emplooye in vector
        i++;
        j=0;
       
    }
    int tx=0;
    int iv=0;
    while (iv<10)
    {
    	int sav=0;
    	tx=1+rand()%25;
    	for (int j=0;j<EMPListe.size();++j)
    	{
    		if(EMPListe1[tx].get_pid()==EMPListe[j].get_pid()){   /// check that there is one element
    			sav=1;
    			break;
    		}
    	}
    	if(sav==0){
    		EMPListe.push_back(EMPListe1[tx]);       ///elements are added to the vector
    		iv++;
    	}
    
    }

    int t=0,say=0;
	for(int a=0;a<arraysize;a++){   ///The loop will turn until 10 Emplooye
		t=1+rand()%11;
		
		for(int k=0;k<EMPListe.size();k++){  ///The loop will turn until vector size

			if(t==document && EMPListe[k].get_unvan()=="Officer"){
				Officer* b = (Officer*) &EMPListe[k];  ///type Emplooye converted to type officer
				b->makeDoc();         ///call function
				cout<<b->get_name();
				cout<<" Document "<<"Happiness of "<<b->get_happiness()<<" contribution of uni is "<<b->emp->get_contribution()<<endl;
				
				break;
			}
			if(t==slackness){
				EMPListe[k].drinkTea();          ///call function
				cout<<EMPListe[k].get_name();
				cout<<" slackness "<<"Happiness of "<<EMPListe[k].get_happiness()<<" contribution of uni is "<<EMPListe[k].emp->get_contribution()<<endl;
			
			break;
			}
			if(t==project && EMPListe[k].get_unvan()=="ResearchAssistant" ){
			ResearchAssistant* ba=(ResearchAssistant*) &EMPListe[k];  ///type Emplooye converted to type ResearchAssistant
				
				ba->research();       ///called function
				cout<<ba->get_name();
				cout<<" research "<<"Happiness of "<<ba->get_happiness()<<" contribution of uni is "<<ba->emp->get_contribution()<<endl;
			
			break;
			}
			if(t==lesson && EMPListe[k].get_unvan()=="Lecturer" ){
			Lecturer* bb=(Lecturer*) &EMPListe[k];      ///////type Emplooye converted to type lecturer
				
				bb->giveLesson();        ///called function
				cout<<bb->get_name();
				cout<<" lesson "<<"Happiness of "<<bb->get_happiness()<<" contribution of uni is "<<bb->emp->get_contribution()<<endl;
			
			break;
			}
			
			if(t==seminar &&  (EMPListe[k].get_unvan()=="Lecturer" || EMPListe[k].get_unvan()=="ResearchAssistant" ) ){
			AcademicPersonnel* bbx=(AcademicPersonnel*) &EMPListe[k];     ///type Emplooye converted to type AcademicPersonnel
				
				bbx->seeSuccessfulStudent();      ///called function
				cout<<bbx->get_name();
				cout<<" seminar "<<"Happiness of "<<bbx->get_happiness()<<" contribution of uni is "<<bbx->emp->get_contribution()<<endl;
		
			break;
			}
			if(t==academicPaper  && (EMPListe[k].get_unvan()=="Lecturer" || EMPListe[k].get_unvan()=="ResearchAssistant" )  ){
			AcademicPersonnel* bbxx=(AcademicPersonnel*) &EMPListe[k];  ///type Emplooye converted to type AcademicPersonnel
				
				bbxx->makePublish();
				cout<<bbxx->get_name();
				cout<<" academicPaper "<<"Happiness of "<<bbxx->get_happiness()<<" contribution of uni is "<<bbxx->emp->get_contribution()<<endl;
			
			break;
			}
			if(t==administration  && (EMPListe[k].get_unvan()=="Officer" || EMPListe[k].get_unvan()=="Secretary" )){
			AdministrativePersonnel* bn=(AdministrativePersonnel*) &EMPListe[k];   ///type Emplooye converted to type AdministrativePersonnel
				
				bn->manageProcess();  ///called function
				cout<<bn->get_name();
				cout<<" administration "<<"Happiness of "<<bn->get_happiness()<<" contribution of uni is "<<bn->emp->get_contribution()<<endl;

			
			break;
			}
			if(t==HomeworkTime  && EMPListe[k].get_unvan()=="Lecturer"){
				Lecturer* bc=(Lecturer*) &EMPListe[k];   ///type Emplooye converted to type lecturer 
				
				bc->giveHW();
				cout<<bc->get_name();
				cout<<" HomeworkTime "<<"Happiness of "<<bc->get_happiness()<<" contribution of uni is "<<bc->emp->get_contribution()<<endl;
			
			break;
			}
			if(t==homeworkTimeout  && EMPListe[k].get_unvan()=="ResearchAssistant"){
				ResearchAssistant* bx=(ResearchAssistant*) &EMPListe[k];       ///type Emplooye converted to type ResearchAssistant				
				bx->research();
				cout<<bx->get_name();
				cout<<" homeworkTimeout "<<"Happiness of "<<bx->get_happiness()<<" contribution of uni is "<<bx->emp->get_contribution()<<endl;

			
			break;
			}
			if(t==incident  && EMPListe[k].get_unvan()=="Secretary"){
				Secretary* bxx=(Secretary*) &EMPListe[k];   ///type Emplooye converted to type Secretary				
				bxx->receivePetition();
				cout<<bxx->get_name();
				cout<<" incident "<<"Happiness of "<<bxx->get_happiness()<<" contribution of uni is "<<bxx->emp->get_contribution()<<endl;

		
			break;
			}
			if(t==solution) {	
				EMPListe[k].submitPetition();
				cout<<EMPListe[k].get_name();
				cout<<" solution "<<"Happiness of "<<EMPListe[k].get_happiness()<<" contribution of uni is "<<EMPListe[k].emp->get_contribution()<<endl;

			
			break;
			}

		}
	}
	delete Employee::emp;
	return 0;
}