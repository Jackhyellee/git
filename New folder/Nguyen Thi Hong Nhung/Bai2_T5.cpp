#include<iostream>
using namespace std ;

class Nguoi
{
	protected :
	string hoten ;
	int nam ;
	public:
		Nguoi()
		{
			hoten=" " ;
			nam = 0 ;
		}
		Nguoi(string hoten ,int nam)
		{
			this->hoten = hoten ;
			this->nam = nam ;
		}
		~Nguoi(){
		}
		
		friend istream& operator >> (istream& is , Nguoi &d)
		{
			fflush(stdin) ;
			cout<<"Nhap ho ten " ; getline(is,d.hoten) ;
			cout<<"Nhap nam sinh  " ; is>>d.nam ;
			return is ;
			
		}
		
		friend ostream& operator << (ostream& os , Nguoi &d)
		{
			os<<"Ho ten "<<d.hoten<<endl ;
			os<<"Ho ten "<<d.nam<<endl ;
			return os  ;
		}
	} ;
	class Sinhvien
	{	
	
		public  :
	string hk ;
	float diem ;
	public:
		Sinhvien()
		{
			hk=" " ;
			diem = 0 ;
		}
		Sinhvien(string hk ,int diem)
		{
			this->hk = hk ;
			this->diem = diem ;
		}
		~Sinhvien(){
		}
		
		friend istream& operator >> (istream& is , Sinhvien &s)
		{
			fflush(stdin) ;
			cout<<"Nhap hanh kiem " ; getline(is, s.hk) ;
			cout<<"Nhap diem  " ; is>>s.diem ;
			return is ;
			
		}
		
		friend ostream& operator << (ostream& os , Sinhvien &s)
		{
			os<<"Hanh kiem "<<s.hk<<endl ;
			os<<"Diem "<<s.diem<<endl ;
			return os  ;
		}
		
	}  ;
class Svtc : public Nguoi , public Sinhvien
{
	private :
		float hphi ;
	public :
		Svtc()
		{
			hphi = 0 ;
		}
		Svtc(string hoten ,int nam ,string hk ,int diem , float hphi) : Nguoi( hoten , nam ) , Sinhvien( hk , diem )
		{
			this->hphi  = hphi  ;
		}
		~Svtc() {
}

	friend istream& operator >> (istream& is ,  Svtc&sv)
		{
			is>>( Nguoi&)sv ;
			is>>( Sinhvien&)sv ;
			cout<<"Nhap hoc phi  " ; is>>sv.hphi;
			return is ;
			
		}
		float Tinhhb()
		{
			if(hk=="Tot"&&diem>=8.0)
			return 5 ;
			else if(hk=="Tot"&&diem>=7.0)
			return 3 ;
			else if (hk=="Kha"&&diem>=7.0)
			return 2 ;
			else 
			return 0 ;
		}
		friend ostream& operator << (ostream& os ,  Svtc&sv)
		{
			os<<( Nguoi&)sv ;
			os<<( Sinhvien&)sv ;
			os<<"Hoc phi "<<sv.hphi<<endl ;
			return os  ;
		}

} ;
int main()
{
	int n ;
	cout<<"Nhap so sinh vien " ; cin >>n ;
	Svtc sv[n];
	for (int i=0 ; i<n ; i++ )
	{
		cout<<"Nhap thong tin sinh vien thu "<<i+1<<endl ;
		cin>>sv[i];
		cout<<endl ;
	}
	for (int i=0 ; i<n ; i++ )
	{
		cout<<" Thong tin sinh vien thu "<<i+1<<endl ;
		cout<<sv[i];
		cout<<endl ;
	}
	cout<<"Nhung sinh vien dat hoc bong la "<<endl ;
		for (int i=0 ; i<n ; i++ )
		{
			if(sv[i].Tinhhb()!= 0)
			{
			cout<<sv[i] ;
			cout<<"Hoc bong la (trieu dong) : "<<sv[i].Tinhhb() ;
			cout<<endl ;
		}
		}
	
	cout<<"Sinh vien theo thu tu tang dan cua diem la "<<endl ;
		for (int i=0 ; i<n ; i++ )
		{
		
		for (int j=i+1 ; j<n ; j++ )
		if(sv[i].diem>sv[j].diem)
		{
			swap(sv[i],sv[j]) ;
		}
		cout<<sv[i] ;
		cout<<endl ;
}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	







