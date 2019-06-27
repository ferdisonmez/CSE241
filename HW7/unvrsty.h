#ifndef UNVRSTY_H
#define UNVRSTY_H
#include"edu.h"
template<class T>  ///template class created
class University{ 
private:
	T contribution;

public:
	int typ;
	int ad;
	vector<Employee*>kisiler;   ////Employe pointer store in vector
	
	T  get_contribution(){
		return contribution;
	}
	void set_contribution(T v){
		contribution=v;
	}
	virtual T contribute(T a)=0;
		

};

template<class T>
class ComUni:public University<T>{
	private:
	T contribution;
	public:
		vector<Employee*>ComUni_kisiler;   ////Employe pointer store in vector
	
		T contribute(T a){
			return this->contribution=(contribution+a);
		}
	
	
	
};

template<class T>
class LibUni:public University<T>{
	private:
	T contribution;	
	public:
	
		vector<Employee*>LibUni_kisiler;   ////Employe pointer store in vector
		
		T contribute(T a){
			return this->contribution=(contribution+a);
		}
	
};

template<class T>
class CapUni:public University<T>{
	private:
	T contribution;
	public:
	
		vector<Employee*>CapUni_kisiler;   ////Employe pointer store in vector
	
		T contribute(T a){
			return this->contribution=(contribution+a);
		}
	
};


#endif
