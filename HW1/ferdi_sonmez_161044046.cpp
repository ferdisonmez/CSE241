#include<iostream>
#define BOYUT 50       /* defined size of the arrays */
using namespace std;
int main(){
	int a[BOYUT]={1,0},b[BOYUT]={0,1},c[BOYUT]={0};	  /*defined size of the arrays */	
	int sayi,i,j,ort,yaz,count=0,yaz1;
	cin>>sayi;					/* enter of number */
	if(sayi<0 || sayi>46){		/* control of certain numbers*/
		cout<<"Error:";			/* error message  */
	}
	else{
		ort=(sayi+1)/2+1;			 /*	middle of the row */
			if(sayi%2==0){
				ort=ort+1;
			}
			for(i=0;i<=sayi;i++){	
				for(j=0;j<=i;j++){
					c[j]=a[j]+b[j];	 /* sum of array coordinates */
					
						if(i==j){		/* The same element as the end of the array is assigned */
							c[j]=c[0];
						}
						if(i==2 && j==1){  	/* coordinate control and assigned */
							c[j]=1;	
						}
						if(i==ort-1 && (i==j)&&(j%2==0)){	/* 	middle of the row and column*/    
							yaz=c[j/2];	
							count=1;
						}
						if(i==ort-1 && (i==j)&&(j%2==1)){	
							yaz1=c[j/2];
							count=2;
						}
							cout<<c[j]<<" ";
							a[j]=b[j];
							b[j]=c[j];					
				}	
				cout<<"\n";	
			}
		cout<<"Biggest number:"<<" "<<c[sayi]<<endl;  		/* Biggest number */
		if(count==1)	       /* if the middle number is single*/
			cout<<"Heart of the pyramid:"<<" "<<yaz;
		else if(count==2)	   /* if the middle number is double*/
			cout<<"heart of the pyramid:"<<" "<<yaz1<<" "<<yaz1;		
}
	return 0;
}
