#include<iostream>
#include<iomanip>
using namespace std ;

class Sv
{
	private :
		int sbd ;
		string hoten ;
		float dtoan , dhoa , dly ;
	public :
		Sv()
		{
			sbd = 0 ;
			hoten = " " ;
			dtoan = 0;
			dhoa = 0 ;
			dly = 0 ;
		}
		Sv(int sbd ,string hoten ,float dtoan ,float dhoa ,float dly )
		{
			this->sbd=sbd ;
			this->hoten=hoten ;
			this->dtoan=dtoan ;
			this->dhoa =dhoa  ;
			this->dly =dly ;
		}
		~Sv(){
		}
	
	     
	     float Tongd()
	     {
	     	return dtoan+ dly + dhoa ;
		 }
	    void nhap()
	    {
	    	cout<<"Nhap so bao danh " ; cin>>sbd ;
	    	cin.ignore() ;
	    	cout<<"Nhap ho ten "; getline(cin,hoten) ;
	    	cout<<"Nhap diem toan " ; cin>> dtoan ; 
	    	cout<<"Nhap diem hoa " ; cin>> dhoa ;
	    	cout<<"Nhap diem ly " ; cin>> dly ;
	
		}
		 
		 void in()
		 {
	cout<<setw(5)<<sbd<<"\t"<<setw(25)<<hoten<<"\t"<<setw(7)<<dtoan<<"\t"<<setw(10)<<dhoa<<"\t"<<setw(12)<<dly<<"\t"<<setw(9)<<"\t"<<Tongd()<<endl    ;
		 }	
		
} ;
void tieude()
{
	cout<<setw(5)<<"So bao danh"<<"\t"<<setw(20)<<"Ho ten"<<"\t"<<setw(7)<<"Diem toan"<<"\t"<<setw(7)<<"Diem hoa"<<"\t"<<setw(9)<<"Diem ly"<<"\t"<<setw(11)<<"Tong diem "<<endl    ;
}
int main()
{
	int n ;
	cout<<"Nhap so sinh vien " ; cin>>n ;
	Sv s[n]  ;
	

	for(int i=0 ;i<n;i++)
	{
		cout<<"Nhap sinh vien thu "<<i+1<<endl;
		s[i].nhap() ;
	}
	cout<<"Danh sach sinh vien trung tuyen la "<<endl ;
	tieude() ;
	for(int i=0 ;i<n;i++)
	{
		if(s[i].Tongd()>20)
		s[i].in() ;
	}
 
	int cs, s2 ;
	s2 = s[0].Tongd() ;
	for(int i=0 ;i<n;i++)
	{
	    if(s2<s[i].Tongd())	
	    s2 = s[i].Tongd() ;
	       cs=i ;
	}
	cout<<"Sinh vien la thu khoa la "<<endl;
	tieude() ;
	s[cs].in() ;
	
	
	
	
	
} 




