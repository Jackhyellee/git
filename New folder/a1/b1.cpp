#include<iostream>
#include<iomanip>
using namespace std ;

class TS
{ 
private :
	string ht ;
	float diemtoan , diemvan ;
public :
	TS()
	{
		ht = " " ;
		diemtoan = 0 ;
		diemvan = 0 ;
	}
	TS(string ht , 	float diemtoan , float diemvan)
	{
		this->ht=ht ;
		this->diemtoan = diemtoan ;
		this->diemvan = diemvan ;
	}
	~TS(){ 
	}
	void nhap()
	{
		cin.ignore();
		cout<<"Nhap ten thi sinh " ; getline(cin,ht) ;
		cout<<"Nhap diem toan " ; cin>>diemtoan ;
		cout<<"Nhap diem van " ; cin >>diemvan ;
	}
	
	
	void in()
	{
		cout<<setw(27)<<ht<<setw(10)<<diemtoan<<setw(15)<<diemvan ;
	}
	
	
	
	
	
};
void Tieude()
	{
		cout<<setw(30)<<"Ho ten "<<setw(15)<<"Diem toan "<<setw(10)<<"Diem van "<<endl ;
	}
int main()
{
	TS d[30] , d1 ;
	int n ;
	cout<<"Nhap so thi sinh " ; cin>>n ;
	for(int i=0 ;i<n;i++)
	{
		cout<<"Nhap thi sinh thu "<<i+1<<endl;
		d[i].nhap() ;
	}
		cout<<" thi sinh vua nhap la "<<endl;
		
	Tieude() ;
	
	for(int i=0 ;i<n;i++)
	{
		
		d[i].in() ;
		cout<<endl ;
	}
	cout<<"\nNhap thong tin mot thi sinh " <<endl ;
	d1.nhap() ;
	int chisod ;
	for(int i=0 ;i<n;i++)
	{
		if(d1.nhap()==d[i].in() )
		chisod = i ;
		
	}
	if(chisod>=0){
	
	cout<<"\nThi sinh vua nhap co trong danh sach o vi tri thu "<<chisod<<endl ;
	d[chisod].in() ;
}
	else 
	{
	
	cout<<"\nThi sinh vua nhap khong co trong danh sach  "<<endl ;
       }
	
	
	
	
}
