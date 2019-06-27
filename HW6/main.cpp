#include "personal.h"
#include"complex.h"
const int BOYUT=100;
const int action_number=50;
int main()
{
	srand(time(NULL));
    vector<isci>EMPListe1;
    vector<isci>MARMARA_Liste;
    vector<isci>KOC_Liste;
    vector<isci>GTU_Liste;
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
        EMPListe1.push_back(v1);          ///store class Emplooye in vector
        i++;
        j=0;
       
    }

	int tx=1;
	int iv=0;
	cout<<"**********************************"<<endl;
	cout<<"****** MARMARA UNIVERSITY  *****"<<endl;	
	cout<<"**********************************"<<endl;
	if(tx==1){
 
    	while (iv<10)
    	{ 	
  			MARMARA_Liste.push_back(EMPListe1[iv]);     
    			iv++;	
    	}
	
	University<double> *a;  
	YOK<double> b;
	a=b.foundUni(tx); ///new university established
	a->typ=1;
	a->ad=MARMARA;	///university name

	for(int l=0;l<MARMARA_Liste.size();l++)
	{	
			cout<<"MARMARA requests ";
			int y=rand()%3;
			string h="\0";
			if(y==0){
			h="Lecturer";
			Employee* x=new lecturer();  ///object of derived class
			x->set_unvan(h);
			a->kisiler.push_back(b.givejob(x,MARMARA_Liste[l].isim,MARMARA_Liste[l].soyisim,y));///a new person is hired	
			}
			if(y==1){
			Employee* x=new researchAssistant();   ///object of derived class	
			h="ResearchAssistant";
			x->set_unvan(h);
			a->kisiler.push_back(b.givejob(x,MARMARA_Liste[l].isim,MARMARA_Liste[l].soyisim,y));///a new person is hired	
			}	
			if(y==2){
			Employee* x=new secretary();   ///object of derived class	
			h="Secretary";
			x->set_unvan(h);
			a->kisiler.push_back(b.givejob(x,MARMARA_Liste[l].isim,MARMARA_Liste[l].soyisim,y));///a new person is hired	
			}
				
			if(y==3){
			Employee* x=new officer();    ///object of derived class	
			h="Officer";
			x->set_unvan(h);
			a->kisiler.push_back(b.givejob(x,MARMARA_Liste[l].isim,MARMARA_Liste[l].soyisim,y));///a new person is hired	
			}
				
			cout<<h<<endl;
			cout<<"YOK give job to "<<MARMARA_Liste[l].isim<<" "<<MARMARA_Liste[l].soyisim<<" as "<<h<<endl;
			MARMARA_Liste[l].job=h;
			
			cout<<"MARMARA"<<" employs "<<MARMARA_Liste[l].isim<<" "<<MARMARA_Liste[l].soyisim<<" as "<<h<<endl;
			cout<<endl;
			h="\0";

	}
	cout<<"****************************"<<endl;
	cout<<"***/MARMARA---ACTIONS/******"<<endl;
	cout<<"****************************"<<endl;
	int ac=0;
	a->set_contribution(0);
	while(ac<action_number){
		
	for(int k=0;k<a->kisiler.size();k++){
		int t=1+rand()%11;
		if(a->kisiler[k]->get_unvan()=="Lecturer" && (t==lesson || t==seminar || t==academicPaper || t==HomeworkTime || t==slackness ||t==solution)){
		lecturer* bb=(lecturer*) a->kisiler[k];  //cast operation
		a->contribute(bb->work(t));
		cout<<" contribution of uni is "<<a->get_contribution()<<endl;  ///The contribution is printed
		ac++;	
		}
		if(a->kisiler[k]->get_unvan()=="ResearchAssistant" && (t==project || t==seminar || t==academicPaper || t==homeworkTimeout ||t==slackness ||t==solution)){
		researchAssistant* ba=(researchAssistant*) a->kisiler[k];//cast operation
		a->contribute(ba->work(t));
		cout<<" contribution of uni is "<<a->get_contribution()<<endl;///The contribution is printed
		ac++;
		}
		if(a->kisiler[k]->get_unvan()=="Secretary" && (t==administration || t==incident ||t==slackness ||t==solution)){
		secretary* ba=(secretary*) a->kisiler[k];//cast operation
		a->contribute(ba->work(t));
		cout<<" contribution of uni is "<<a->get_contribution()<<endl;///The contribution is printed
		ac++;
		}
		if(a->kisiler[k]->get_unvan()=="Officer" && (t==document || t==administration || t==slackness ||t==solution )){
		officer* ba=(officer*) a->kisiler[k];//cast operation
		a->contribute(ba->work(t));
		cout<<" contribution of uni is "<<a->get_contribution()<<endl;///The contribution is printed
		ac++;	
		}
		if(ac==action_number){
			break;
		}
		
	}
	
}
	for(int m=0;m<MARMARA_Liste.size();m++){  ///places received from memory are cleaning
		delete a->kisiler[m];
	}
	delete a;		
	tx++;
	}
	

cout<<endl;
cout<<"**********************************"<<endl;
cout<<"****** KOC  UNIVERSITY ***********"<<endl;
cout<<"**********************************"<<endl;	
	if(tx==2){

	
	cout<<"KOC-Linguistic uni "<<endl;
    while (iv<20)
    {	
    		KOC_Liste.push_back(EMPListe1[iv]);       
    		iv++;
    }
	
	University<int> *ax;
	YOK<int> b;
	ax=b.foundUni(tx);
	ax->typ=2;
	ax->ad=KOC;

	for(int l=0;l<KOC_Liste.size();l++)
	{	
			cout<<"KOC requests ";
			int y=rand()%3;
			string h="\0";
			if(y==0){
			h="Lecturer";
			Employee* x=new lecturer();///object of derived class
			x->set_unvan(h);
			ax->kisiler.push_back(b.givejob(x,KOC_Liste[l].isim,KOC_Liste[l].soyisim,y));///a new person is hired	
			}
			if(y==1){
			Employee* x=new researchAssistant();///object of derived class	
			h="ResearchAssistant";
			x->set_unvan(h);
			ax->kisiler.push_back(b.givejob(x,KOC_Liste[l].isim,KOC_Liste[l].soyisim,y));///a new person is hired	
			}	
			if(y==2){
			Employee* x=new secretary();///object of derived class	
			h="Secretary";
			x->set_unvan(h);
			ax->kisiler.push_back(b.givejob(x,KOC_Liste[l].isim,KOC_Liste[l].soyisim,y));///a new person is hired	
			}
				
			if(y==3){
			Employee* x=new officer();	///object of derived class
			h="Officer";
			x->set_unvan(h);
			ax->kisiler.push_back(b.givejob(x,KOC_Liste[l].isim,KOC_Liste[l].soyisim,y));///a new person is hired	
			}
				
			cout<<h<<endl;
			cout<<"YOK give job to "<<KOC_Liste[l].isim<<" "<<KOC_Liste[l].soyisim<<" as "<<h<<endl;
	
			
			cout<<"KOC"<<" employs "<<KOC_Liste[l].isim<<" "<<KOC_Liste[l].soyisim<<" as "<<h<<endl;
			cout<<endl;
			h="\0";

	}
	cout<<"****************************"<<endl;
	cout<<"********/KOC---ACTIONS/*******"<<endl;
	cout<<"****************************"<<endl;
	
		int ac=0;
	ax->set_contribution(0);
	while(ac<action_number){
		
	for(int k=0;k<ax->kisiler.size();k++){
		int t=1+rand()%11;
		
		if(ax->kisiler[k]->get_unvan()=="Lecturer" && (t==lesson || t==seminar || t==academicPaper || t==HomeworkTime || t==slackness ||t==solution)){
		lecturer* bb=(lecturer*) ax->kisiler[k]; //cast operation
		ax->contribute(bb->work(t));
		cout<<" contribution of uni is "<<ax->get_contribution()<<endl;///The contribution is printed
			ac++;
			
		}
		else if(ax->kisiler[k]->get_unvan()=="ResearchAssistant" && (t==project || t==seminar || t==academicPaper || t==homeworkTimeout ||t==slackness ||t==solution)){
		researchAssistant* ba=(researchAssistant*) ax->kisiler[k]; //cast operation
		ax->contribute(ba->work(t));
		cout<<" contribution of uni is "<<ax->get_contribution()<<endl;///The contribution is printed
		ac++;
		
		}
		else if(ax->kisiler[k]->get_unvan()=="Secretary" && (t==administration || t==incident ||t==slackness ||t==solution)){
		secretary* ba=(secretary*) ax->kisiler[k];//cast operation
		ax->contribute(ba->work(t));
		cout<<" contribution of uni is "<<ax->get_contribution()<<endl;///The contribution is printed
		ac++;
		
		}
		else if(ax->kisiler[k]->get_unvan()=="Officer" && (t==document || t==administration || t==slackness ||t==solution )){
		officer* ba=(officer*) ax->kisiler[k];//cast operation
		ax->contribute(ba->work(t));
		cout<<" contribution of uni is "<<ax->get_contribution()<<endl;///The contribution is printed
		ac++;
			
		}
		else if(ac==action_number){
			break;
		}
	
	}
	
}
	for(int m=0;m<KOC_Liste.size();m++){  ///places received from memory are cleaning
		delete ax->kisiler[m];
	}
	delete ax;			
	tx++;
	}
	
cout<<endl;
cout<<"**********************************"<<endl;
cout<<"** GEBZE TEKNICAL UNIVERSITY ****"<<endl;
cout<<"**********************************"<<endl;
	
	if(tx==3){

    while (iv<30)
    {	
    		GTU_Liste.push_back(EMPListe1[iv]);       
    		iv++;
    }
	
	University<complex> *aw;
	YOK<complex> b;
	aw=b.foundUni(tx);
	aw->typ=2;
	aw->ad=GTU;

	for(int l=0;l<GTU_Liste.size();l++)
	{	
			cout<<"GTU requests ";
			int y=rand()%3;
			string h="\0";
			if(y==0){
			h="Lecturer";
			Employee* x=new lecturer();///object of derived class
			x->set_unvan(h);
			aw->kisiler.push_back(b.givejob(x,GTU_Liste[l].isim,GTU_Liste[l].soyisim,y));///a new person is hired	
			}
			if(y==1){
			Employee* x=new researchAssistant();///object of derived class	
			h="ResearchAssistant";
			x->set_unvan(h);
			aw->kisiler.push_back(b.givejob(x,GTU_Liste[l].isim,GTU_Liste[l].soyisim,y));///a new person is hired	
			}	
			if(y==2){
			Employee* x=new secretary();///object of derived class	
			h="Secretary";
			x->set_unvan(h);
			aw->kisiler.push_back(b.givejob(x,GTU_Liste[l].isim,GTU_Liste[l].soyisim,y));///a new person is hired	
			}
				
			if(y==3){
			Employee* x=new officer();	///object of derived class
			h="Officer";
			x->set_unvan(h);
			aw->kisiler.push_back(b.givejob(x,KOC_Liste[l].isim,KOC_Liste[l].soyisim,y));///a new person is hired	
			}
				
			cout<<h<<endl;
			cout<<"YOK give job to "<<GTU_Liste[l].isim<<" "<<GTU_Liste[l].soyisim<<" as "<<h<<endl;
			
			cout<<"GTU"<<" employs "<<GTU_Liste[l].isim<<" "<<GTU_Liste[l].soyisim<<" as "<<h<<endl;
			cout<<endl;
			h="\0";

	}
	cout<<"****************************"<<endl;
	cout<<"********/GTU---ACTIONS/*******"<<endl;
	cout<<"****************************"<<endl;
	int ac=0;
		
	while(ac<action_number){
		
	for(int k=0;k<aw->kisiler.size();k++){
		int t=1+rand()%11;
		if(aw->kisiler[k]->get_unvan()=="Lecturer" && (t==lesson || t==seminar || t==academicPaper || t==HomeworkTime || t==slackness ||t==solution)){
			lecturer* bb=(lecturer*) aw->kisiler[k]; //cast operation
			double z=bb->work(t);
			complex c1;///a new value is defined
			c1.set_int_real(z);
			c1.set_int_imag(1);
			c1.set_double_real(z);
			c1.set_double_imag(1);
		aw->contribute(c1);
		cout<<" contribution of uni is "<<aw->get_contribution()<<endl;///The contribution is printed
			ac++;	
		}
		if(aw->kisiler[k]->get_unvan()=="ResearchAssistant" && (t==project || t==seminar || t==academicPaper || t==homeworkTimeout ||t==slackness ||t==solution)){
			researchAssistant* ba=(researchAssistant*) aw->kisiler[k];//cast operation
			double z=ba->work(t);
			complex c1;     ///a new value is defined
			c1.set_int_real(z);
			c1.set_int_imag(1);
			c1.set_double_real(z);
			c1.set_double_imag(1);
		aw->contribute(c1);
		cout<<" contribution of uni is "<<aw->get_contribution()<<endl;///The contribution is printed
		ac++;
		}
		if(aw->kisiler[k]->get_unvan()=="Secretary" && (t==administration || t==incident ||t==slackness ||t==solution)){
			secretary* ba=(secretary*) aw->kisiler[k];//cast operation
		
			double z=ba->work(t);
			complex c1; ///a new value is defined
			c1.set_int_real(z);
			c1.set_int_imag(1);
			c1.set_double_real(z);
			c1.set_double_imag(1);
			aw->contribute(c1);
		cout<<" contribution of uni is "<<aw->get_contribution()<<endl;///The contribution is printed
		ac++;
		}
		if(aw->kisiler[k]->get_unvan()=="Officer" && (t==document || t==administration || t==slackness ||t==solution )){
			officer* ba=(officer*) aw->kisiler[k];//cast operation
		double z=ba->work(t);
			complex c1; ///a new value is defined
			c1.set_int_real(z);
			c1.set_int_imag(1);
			c1.set_double_real(z);
			c1.set_double_imag(1);
		aw->contribute(c1);
		cout<<" contribution of uni is "<<aw->get_contribution()<<endl;///The contribution is printed
		ac++;	
		}
		if(ac==action_number){
			break;
		}
		
	}
	
}
	for(int m=0;m<GTU_Liste.size();m++){  ///places received from memory are cleaning
		delete aw->kisiler[m];
	}
	delete aw;			
	tx++;
	}

	return 0;
}
