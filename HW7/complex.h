#ifndef COMPLEX_H
#define COMPLEX_H
class complex{
	private:
		int int_real;
		int int_imag;
		double double_real;
		double double_imag;
		
	public:
		int get_int_real(){
		return int_real;
		}
		void set_int_real(int a){
			int_real=a;
		}
		
		int get_int_imag(){
		return int_imag;	
		}
		void set_int_imag(int b){
			int_imag=b;
		}
	   
		double get_double_real(){
			return double_real;
		}
		void set_double_real(double x){
			double_real=x;
		}
		
		double get_double_imag(){
			return double_imag;
		}
		void set_double_imag(double y){
			double_imag=y;
		}
	
		complex operator + (const complex  &obj){ ///+ operator overloaded
			complex res;
			res.int_real=int_real+obj.int_real;
			res.int_imag=int_imag+obj.int_imag;
			
			res.double_real=double_real + obj.double_real;
			res.double_imag=double_imag + obj.double_imag;
			
			return res;
		}
		complex operator - (complex const &obj){ ///- operator overloaded
			complex res;
			res.int_real=int_real-obj.int_real;
			res.int_imag=int_imag-obj.int_imag;
			
			res.double_real=double_real - obj.double_real;
			res.double_imag=double_imag - obj.double_imag;
			
			return res;
		}
		
		complex& operator =(const complex &t){ ///assignment operator overloaded
			if(this!=&t){
			this->int_real=t.int_real;
			this->int_imag=t.int_imag;
			
			this->double_real=t.double_real;
			this->double_imag=t.double_imag;
			}
			
			
			return *this;
			
		}
		complex operator ++(){  ///prefix ++
			complex temp;
			++int_real;
			++int_imag;
			++double_real;
			++double_imag;
			temp.int_real=int_real;
			temp.int_imag=int_imag;
			temp.double_real=double_real;
			temp.double_imag=double_imag;
			return temp;
		}
		complex operator ++(int){  ///postfix ++
			complex temp;
			int_real++;
			int_imag++;
			double_real++;
			double_imag++;
			temp.int_real=int_real;
			temp.int_imag=int_imag;
			temp.double_real=double_real;
			temp.double_imag=double_imag;
			return temp;
		}
	friend ostream & operator <<(ostream &out,const complex &c);
	
};
ostream & operator <<(ostream &out,const complex &c){  ///<< operator overloaded
	out<<c.int_real;
	out<<" "<<c.int_imag<<"i";
	out<<" / " <<c.double_real<<" "<<c.double_imag<<"i";
	return out;
}



#endif
