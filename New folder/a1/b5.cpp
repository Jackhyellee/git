#include<iostream>
#include<iomanip>
using namespace std ;

class Nguoi
{
	private :
		string ht , ngheng, quoct ;
		int tuoi ;
	public :
	Nguoi()	
	{
		ht = " " ;
		ngheng = " " ;
		quoct = " " ;
		tuoi  = 0 ;
		
	}
	Nguoi(string ht ,string ngheng,string quoct,int tuoi)
	{
		this->ht = ht ;
		this->ngheng =ngheng ;
		this->quoct = quoct ;
		this->tuoi =tuoi ;
	}
	~Nguoi(){
	}
	
	void nhap()
	{
		cin.ignore() ;
		cout<<"Nhap ho ten " ; getline(cin,ht) ;
		cout<<"Nhap nghe nghiep " ; getline(cin,ngheng) ;
		cout<<"Nhap quoc tich " ; getline(cin, quoct) ;
		cout<<"Nhap tuoi " ; cin>>tuoi ;
		
	}
	void in()
	{
		cout<<setw(25)<<ht<<"\t" ;
		cout<<setw(20)<<ngheng<<"\t" ;
		cout<<setw(20)<<quoct<<"\t" ;
		cout<<setw(5)<<tuoi<<"\t" ;
	}	
}

void tieude()
{
	    cout<<setw(25)<<"Ho ten"<<"\t" ;
		cout<<setw(20)<<"Nghe nghiep"<<"\t" ;
		cout<<setw(20)<<"Quoc tich"<<"\t" ;
		cout<<setw(5)<<"Tuoi"<<"\t" ;
}
int main()
{
	Nguoi *s ;
	s = new Nguoi[n] ;
	Nguoi s[30] ;
		int n ;
	cout<<"Nhap so nguoi " ; cin>>n ;
	for(int i=0 ;i<n;i++)
	{
		cout<<"Nhap nguoi thu "<<i+1<<endl;
		s[i].nhap() ;
	}
}







