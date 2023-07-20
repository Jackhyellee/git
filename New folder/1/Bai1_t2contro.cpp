#include<iostream>

using namespace std ;

class Hcn
{
	private :
		int dai , rong ;
	public :
		Hcn(int dai = 0 , int rong = 0 )
		{
			this->dai = dai ;
			this->rong=rong ;
		}
		~Hcn()
		{
		}
		void nhap()
		{
			cout<<"Nhap chieu dai " ; cin>>dai ;
			cout<<"Nhap chieu rong " ; cin>>rong  ;
		}
		
		
		int Chuvi()
		{
			return (dai+rong)*2 ;
		}
		int Dientich()
		{
			return dai*rong ;
		}
		void in()
		{
			cout<<"\n chieu dai   "<<dai;
			cout<<"\n chieu rong "<<rong ;
			cout<<"\n Chu vi la " <<Chuvi();
			cout<<"\n Dien tich la "<<Dientich();
			cout<<endl ;
		}
		
		
 } ;
int main()
{
	Hcn *d ;
	int n ;
	cout<<"\nNhap so hinh chu nhat " ; cin >> n ;
	d = new Hcn[n] ;
	for(int i= 0 ; i<n ;i++)
	{ 
	  cout<<"\nNhap thong tin hinh chu nhat thu "<<i+1<<" la "<<endl ;
	  d[i].nhap() ;
	}
	for(int i= 0 ; i<n ;i++)
	{ 
	  cout<<"\nthong tin hinh chu nhat thu "<<i+1<<" la "<<endl ;
	  d[i].in() ;
	}
	int maxcv=0 ;
	
	for(int i= 0 ; i<n ;i++)
	{
		if(d[maxcv].Chuvi()<d[i].Chuvi())
		maxcv=i ;
	}
	cout<<"\n Hinh chu nhat co chu vi lon nhat la " ;
	d[maxcv].in() ;
	cout<<endl ;
	int mindt =0 ;

	for(int i= 0 ; i<n ;i++)
	{
		if(d[mindt].Dientich()>d[i].Dientich())
		mindt = i;
		
	}
		cout<<"\n Hinh chu nhat co dien tich nho nhat la " ;
	d[mindt].in() ;
	
}
