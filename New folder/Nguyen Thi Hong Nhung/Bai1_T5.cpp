#include<iostream>
using namespace std ;

class Monhoc 
{
	protected :
		string tenmon ;
		int sotiet ;
	public :
	Monhoc()
	{
		tenmon = " ";
		sotiet = 0 ;
	}
	Monhoc(string tenmon ,int sotiet )
	{
		this->tenmon = tenmon ;
		this->sotiet = sotiet  ;
	}
	~Monhoc(){
	}
	void in()
	{
		cout<<"Ten mon "<<tenmon<<endl ;
		cout<<"So tiet "<<sotiet<<endl ;
	}
	
};
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
		void in1()
		{
			cout<<"Ho ten "<<hoten<<endl;
			cout<<"Nam sinh "<<hoten<<endl;
			
		}

} ;
class Giaovien : public Monhoc , public Nguoi
{
	
	private :
	string bomon ;
	public :
	Giaovien ()
	{
		bomon = " " ;
	}	
	Giaovien (string tenmon ,int sotiet ,string hoten ,int nam,string bomon  ) : Monhoc(tenmon , sotiet) , Nguoi( hoten , nam)
	{
		this->bomon = bomon ;
	}
	~Giaovien(){
	}
	void nhap()
	{
		fflush(stdin);
		cout<<"Nhap ten mon " ; getline(cin ,tenmon ) ;
		cout<<"Nhap ho ten " ; getline(cin ,hoten ) ;
		cout<<"Nhap bo mon " ; getline(cin ,bomon ) ;
		cout<<"Nhap so tiet " ; cin>>sotiet ;
		cout<<"Nhap nam sinh " ; cin>>nam ;
		cout<<endl ;
	
		}
	void in2()	
	{
		Monhoc::in() ;
		Nguoi::in1() ;
		cout<<"Bo mon "<<bomon<<endl ;
	}

} ;
int main()
{
	Giaovien g ;
	cout<<"Nhap thong tin giao vien "<<endl ;
	g.nhap() ;
	cout<<"Thong tin giao vien la "<<endl ;
	g.in2() ;
	
	
}
