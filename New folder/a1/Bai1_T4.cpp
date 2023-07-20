#include<iostream>
using namespace std ;

class Benhnhan
{
	public :
		string ten , quequan ;
		int nam ; 
	
		Benhnhan(string ten =" ", string quequan = " ", int nam = 0)
		{
			this->ten = ten ;
			this->quequan = quequan ;
			this->nam = nam ;
		}
		void Nhap()
		{
			cin.ignore();
			cout<<"Nhap ho ten benh nhan " ; getline(cin,ten) ;
			cout<<"Nhap que quan " ; getline(cin , quequan) ;
			cout<<"Nhap nam sinh " ; cin>>nam ;
		}
		void In()
		{
			cout<<"Ho ten "<<ten<<endl ;
			cout<<"Que quan "<<quequan<<endl;
			cout<<"Nam sinh "<<nam<<endl ;
		}
		
};
class Benhan: public Benhnhan
{
	public :
		string tenbenhan ;
		float tienvienphi ;
	
		Benhan(string ten , string quequan , int nam ,string tenbenhan,	float tienvienphi) : Benhnhan(ten , quequan , nam )
		{
			this->tenbenhan=tenbenhan ;
			this->tienvienphi = tienvienphi ;
		}
		Benhan()
		{
			tenbenhan = " " ;
			tienvienphi = 0 ;
			
		}
		void Nhap1()
		{
			Benhnhan :: Nhap() ;
			cin.ignore()   ;
			cout <<"Nhap ten benh an " ; getline(cin , tenbenhan) ;
			cout<<"Nhap tien vien phi " ; cin>>tienvienphi ;
			
		}	
		int Tuoi()
		{
			return 2023 - this->nam ;
		}
		void In1()
		{
			Benhnhan ::In() ;
			cout<<"Ten benh an "<<tenbenhan <<endl ;
			cout<<"Tien vien phi "<<tienvienphi<<endl ;
			cout<<"Tuoi "<<Tuoi() <<endl ;
		}
				
};
int main()
{
	int n ;
	cout<<"Nhap so benh an " ; cin >> n ;
	Benhan b[n];
	for(int i=0 ; i<n ; i++)
	{
		cout<<"Benh an thu "<<i+1<<endl;
		b[i].Nhap1() ;
	}
	cout<<endl ;
	cout<<"Sap xep theo so tuoi giam dan la "<<endl ;
	cout<<endl ;
	for(int i=0 ; i<n ; i++)
	{
	for(int j=i+1 ; j<n ; j++)
	{
		if(b[i].Tuoi()<b[j].Tuoi())
		swap(b[i],b[j]) ;
		
	}
	b[i].In1() ;
}
	cout<<endl ;
	cout<<"Benh an co tuoi cua benh nhan lon hon 50 "<<endl ;
		for(int i=0 ; i<n ; i++)
		{
			if(b[i].Tuoi()>50)
			b[i].In1() ;
		}
	cout<<endl ;
	cout<<"Benh an co vien phi cao nhat la "<<endl ;
	int vpcn ;
     b[vpcn]=b[0] ;
		for(int i=0 ; i<n ; i++)
		{
			if (b[vpcn].tienvienphi<b[i].tienvienphi)
			vpcn =i ;
		}
	b[vpcn].In1() ;
}
