#ifndef EDUSYS_H
#define EDUSYS_H
#include"personal.h"
#include"unvrsty.h"


template<class T>
class edusys{
	
	public:
	virtual University<T>* foundUni(int Unitype)=0;   ///new university established

	virtual Employee* givejob(Employee *x,string name,string surname,int Emptype)=0; ///new employees created
	
};
template<class T>
class CommunistEducation:public edusys<T>{
		public:
			University<T>* foundUni(int Unitype){   ///new university established

			University<T> *rtr=new ComUni<T>;
			rtr->typ=Unitype;
			return rtr;       ///new university return 
	
	}

	Employee* givejob(Employee *x,string name,string surname,int Emptype){  ///new employees created
		x->set_name(name);
		x->set_surname(surname);
		return x;

	}
	
	
};
template<class T>
class LiberalEducation:public edusys<T>{
		public:
		University<T>* foundUni(int Unitype){   ///new university established

			University<T> *rtr=new LibUni<T>();
			rtr->typ=Unitype;
		return rtr;       ///new university return 
	
		}

	Employee* givejob(Employee *x,string name,string surname,int Emptype){  ///new employees created
		x->set_name(name);
		x->set_surname(surname);
		return x;

	}
	
	
};
template<class T>
class CapitalistEducation:public edusys<T>{
	
		public:
		University<T>* foundUni(int Unitype){   ///new university established

		University<T> *rtr=new CapUni<T>();
		rtr->typ=Unitype;
		return rtr;       ///new university return 
	
	}

	Employee* givejob(Employee *x,string name,string surname,int Emptype){  ///new employees created
		x->set_name(name);
		x->set_surname(surname);
		return x;

	}
	
	
};



#endif
