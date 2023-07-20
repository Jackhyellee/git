#include<iostream>
#include<iomanip>
using namespace std ;

class MAYBAY
{
	public:
		string mamb , thsx ;
		int dongia , sl ;
	public :
		XEDAP(string mamb = " " ,string thsx  = " " ,int dongia = 0 ,int sl = 0)
		{
			this->mamb=mamb ;
			this->thsx=thsx;
			this->dongia=dongia ;
			this->sl=sl ;
			
		}
		~MAYBAY(){
		}
		friend istream&  operator >> (istream& is , MAYBAY &m)
		{
			fflush(stdin);
			cout<<"Nhap ma may bay "; getline(cin,m.mamb) ;
			cout<<"Nhap ten hang san xuat may bay "; getline(cin,m.thsx) ;
			cout<<"Nhap don gia " ; cin >>m.dongia ;
			cout<<"Nhap so luong " ; cin >>m.sl ;
			return is ;
	
		}
		float thanhtien()
		{
			return (float) ((dongia*sl) + (dongia*sl)*0.1) ;
		}
		friend ostream&  operator << (ostream& os , MAYBAY &m)
		{
			os<<setw(10)<<m.mamb ;
			os<<setw(25)<<m.thsx ;
			os<<setw(15)<<m.dongia ;
			os<<setw(10)<<m.sl ;
			os<<setw(15)<<m.thanhtien()<<endl ;
			return os ;
			
		}
		bool operator == (MAYBAY &m1)
		{
			this->dongia==m1.dongia ;
		}
};
void tieude()
{
	        cout<<setw(10)<<"Ma may bay" ;
			cout<<setw(25)<<"Ten hang san xuat" ;
			cout<<setw(15)<<"Don gia" ;
			cout<<setw(10)<<"So luong" ;
			cout<<setw(15)<<"Thanh tien"<<endl ;
}
void menu()
{
	cout<<"=============================================================================="<<endl ;
	cout<<"1.Nhap danh sach may bay "<<endl ;
	cout<<"2.In danh sach may bay "<<endl ;
	cout<<"3.Thong tin may bay co thanh tien lon hon 5000000 "<<endl ;
	cout<<"4.Danh sach may bay co ma hang la MAYB 0107 va xoa  "<<endl ;
	cout<<"5.Danh sach may bay cua hang BOEING va chen "<<endl ;
	cout<<"6.Sap xep danh sach may bay theo thu tu tang dan cua hang san xuat"<<endl ;
	cout<<"=============================================================================="<<endl ;
}

void nhap1(MAYBAY m[],int &n)
{
	cout<<"Nhap so may bay " ;cin>>n ;
	for(int i=0 ; i<n;i++)
	{
		cout<<"Nhap may bay thu "<<i+1<<endl ;
		cin>>m[i];
	}
}
void in1(MAYBAY m[],int n)
{
	tieude();
	for(int i=0 ; i<n;i++)
	{
		cout<<m[i];
	}
	
}

void thanhtienmb(MAYBAY m[],int n)
{
	tieude() ;
	for(int i=0 ; i<n;i++)
	{
		if(m[i].thanhtien()>5000000)
		cout<<m[i];
	}
}
void timvaxoamb(MAYBAY m[],int &n)
{
	int dem1 = 0 ;
	int vc ;
	for(int i=0 ; i<n;i++)
	{
		if(m[i].mamb == "MAYB 0107")
		vc=i ;
		dem1++;
		
	}
	if(dem1==0)
	cout<<"Khong tim thay may bay tren "<<endl ;
	else 
		for(int j=vc ; j<n;j++)	
		m[j]=m[j+1] ;
		n-- ;
	
	cout<<"Da xoa may bay tren "<<endl ;
	cout<<"Moi chon lai lua chon 2 "<<endl ;
	
}
void timvachenmb(MAYBAY m[],int &n)
{
	int dem = 0 ;
	int k ;
	for(int i=0 ; i<n;i++)
	{
		if(m[i].thsx  == "BOEING")
		dem++ ;
	}
	if(dem!=0)
	{
	cout<<"Da co may bay tren "<<endl ;
}
	else 
	{
		cout<<"Chon vi tri can chen "; cin>>k ;
		for(int j=n ; j>k;j--)
		{

		m[j]=m[j-1] ;
		n++ ;
	}
	cin>>m[k] ;
}
	cout<<"Da chen may bay tren "<<endl ;
	cout<<"Moi chon lai lua chon 2 "<<endl ;
}

void sxtd(MAYBAY m[],int n)
{
	for(int i=0 ; i<n-1 ;i++)
		for(int j=i+1 ; j<n;j++)
		{
			if(m[i].thsx>m[j].thsx)
			swap(m[i],m[j]) ;
		}
		cout<<"Da sap xep may bay theo thu tu tang dan cua hang san xuat "<<endl ;
		cout<<"Moi chon lai lua chon 2 "<<endl ;
}
int main()
{
	MAYBAY m[30] ;
	int n , lc ;
	while (lc=1)
	{
		system("cls") ;
		menu();
		cout<<"Moi chon lua chon " ; cin>>lc ;
		switch(lc)
		{
			case 1 :
				nhap1(m,n) ;
				break ;
			case 2 :
				in1(m,n);
				system("pause")   ;
				break ;
			case 3 :
				thanhtienmb(m,n);
				system("pause")   ;
				break ;
			case 4 :
				timvaxoamb(m , n) ;
				system("pause")   ;
				break ;
			case 5 :
				timvachenmb(m , n);
				system("pause")   ;
			
				break ;		
			case 6 :
				sxtd(m , n) ;
				system("pause")   ;
				break ;		
				
		}
	}
	
}
