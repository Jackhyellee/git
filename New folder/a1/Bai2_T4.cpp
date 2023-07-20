#include<iostream>
#include<iomanip>
using namespace std ;

typedef struct Birth 
{
   int d, m , y ;	
}Date ;
class Mydate
{
	public  :
		int d , m , y ;
	public :
		Mydate()
		{
			d= 0 ;
			m = 0 ;
			y = 0 ;	
		}
		
		Mydate(int d , int m , int y)
		{
			this->d=d;
			this->m=m ;
			this->y = y ;
		}
		~Mydate() {
		}
		void in()
		{
			cout<<setw(3)<<d<<"/"<<setw(3)<<m<<"/"<<setw(5)<<y;
		}
			
} ;
class Person : public Mydate 
{
	private :
		string name , address ;
		int phone ;
	public :
		Person()
		{
			name = " ";
			address = " " ;
			phone = 0 ;
		}
		Person(Date a , string name ,string address , 	int phone ) : Mydate (a.d , a.m , a.y)
		{
			this->name = name ;
			this->address = address  ;
			this->phone = phone ;
		}
		~Person(){
		}
		void Nhap()
		{
			cout<<"Nhap ngay sinh " ; cin>>d ;
			cout<<"Nhap thang sinh " ; cin>>m ;
			cout<<"Nhap nam sinh " ; cin>>y ;
			fflush(stdin);
			cout<<"Nhap ten " ; getline(cin,name);
			cout<<"Nhap dia chi " ; getline(cin,address);
			cout<<"Nhap so dien thoai " ; cin>>phone ;
		}
		void in1()
		{
			Mydate::in() ;
	cout<<setw(27)<<name ;
	cout<<setw(30)<<address;
	cout<<setw(17)<<phone<<endl ;
			
		}
	friend bool operator > (Person e , Person d )
	{
		return e.y>d.y ;
	}
	
} ;
void tieude()
{
	cout<<setw(14)<<"Ngay sinh" ;
	cout<<setw(27)<<"Ho ten";
	cout<<setw(30)<<"Dia chi" ;
	cout<<setw(17)<<"So dien thoai"<<endl ;
}
int main()
{
	
	int n ;
	cout<<"Nhap so nguoi " ; cin>>n ;
	Person p[n] ;
	for(int i = 0 ; i<n; i++)
	{
		cout<<"Nhap nguoi thu "<<i+1<<endl ;
		p[i].Nhap() ;
	}
	cout<<endl;
	cout<<"Danh sach nguoi vua nhap "<<endl ;
	tieude() ;
	for(int i = 0 ; i<n; i++)
	{	
	p[i].in1() ;
	}
	
	
	cout<<endl ;
	cout<<"Danh sach nguoi theo chieu tang dan cua nam sinh la "<<endl ;
	cout<<endl ;
	tieude() ;
	for(int i = 0 ; i<n; i++)
	{
	{
		for(int j = i+1 ; j<n; j++)
		if(p[i]>p[j])
		swap(p[i],p[j]) ;
	}
	p[i].in1() ;
}
cout<<"Danh sach nguoi theo chieu giam dan cua nam sinh la "<<endl ;
	cout<<endl ;
	tieude() ;
	for(int i = 0 ; i<n; i++)
	{
	{
		for(int j = i+1 ; j<n; j++)
		if(p[i].y<p[j].y)
		swap(p[i],p[j]) ;
	}
	p[i].in1() ;
}
}
