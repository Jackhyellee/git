#include<iostream>
using namespace std ;

class Phanso 
{
	private :
	 int ts , ms ;
	public :
	
	Phanso(int ts=0 , int ms=0 )
	{
		this->ts=ts ;
		this->ms=ms ;
		
	}
	~Phanso(){
	}
	void nhap()
	{
		cout<<"Tu so la "; cin>>ts;
		cout<<"Mau so la "; cin>>ms;
		//cout<<endl ;
	}
	void in()
	{
		cout<<ts<<"/"<<ms<<endl ;
		
	}
 
	int ucln(int a , int b )
	{
		if(a==0||b==0)
		return a+b ;
		while (a!=b)
		{
			if(a>b) 
			a=a-b ;
			else 
			b=b-a ;
		}
		return a ;
	}
	int bcnn(int a , int b )
	{
		return (a*b)/ucln(a,b) ;
	}
	
	void rutgon()
	{
		int rg=ucln(ts,ms)    ;
		ts=ts/rg ;
		ms=ms/rg ;
	}
     Phanso Tongps(Phanso a1 )	
     {
     	Phanso t ;
     	int mc = bcnn(a1.ms,this->ms) ;
     	t.ts = mc/a1.ms*a1.ts + mc/this->ms*this->ts ;
     	t.ms= mc ;
     	return t  ;
	 }
	Phanso Tichps(Phanso a2 )	
	{
		Phanso t1 ;
		t1.ts=this->ts*a2.ts ;
		t1.ms=this->ms*a2.ms ;
		return t1 ;
	}
}     ;
int main()
{
	int n ;
	cout<<"Nhap so phan so la " ; cin >> n ;
	Phanso p[n] , Tong ;
	
    for (int i=0 ; i<n ; i++)
    {
    	cout<<"\nphan so thu "<<i+1<<endl ;
    	p[i].nhap() ;
	}
	 for (int i=0 ; i<n ; i++)
    {
    	cout<<"Phan so thu "<<i+1<<"la " ;
    	p[i].in() ;
    	cout<<"Phan so thu "<<i+1<<" sau khi rut gon la " ;
    	p[i].rutgon() ;
    	p[i].in() ;
	    cout<<endl ;
	}
	cout<<endl ;
	Phanso ps1=p[0];
	for (int i=0 ; i<n ; i++)
	{
		 ps1=ps1.Tongps(p[i]) ;
	}
	cout<<"Tong cac phan so la " ;
	ps1.rutgon() ;
	ps1.in() ;
	cout<<endl ;
	Phanso ps2=p[0];
	for (int i=0 ; i<n ; i++)
	{
		 ps2=ps2.Tichps(p[i]) ;
	}
	cout<<"Tich cac phan so la " ;
	ps2.rutgon() ;
	ps2.in() ;
	
}
