#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std  ;

class XEDAP
{
	public :
	string maxd , tenhangsx ;
	int dongia , sl ;
	public :
	XEDAP(string maxd =" " ,string tenhangsx = " ",int dongia =0,int sl=0)
	{
		
		this->maxd=maxd ;
		this->tenhangsx=tenhangsx ;
		this->dongia =dongia ;
		this->sl = sl ;
}
     ~XEDAP(){
	 }
	 void nhap()
	 {
	 	fflush(stdin);
	 	cout<<"Nhap ma xe dap " ; getline(cin,maxd);
	 	cout<<"Nhap hang san xuat xe dap " ; getline(cin, tenhangsx);
	 	cout<<"Nhap don gia " ; cin>>dongia ;
	 	cout<<"Nhap so luong xe "; cin >>sl ;
	 	
	 }
	 
	 void in()
	 {
	 	cout<<setw(15)<<maxd ;
	 	cout<<setw(30)<<tenhangsx ;
	 	cout<<setw(15)<<dongia ;
	 	cout<<setw(9)<<sl<<endl ;
	 }
	 friend istream& operator >>(istream& is ,XEDAP &x )
	 {
	 	ifstream fcin ;
	 	fcin.open("baitapppp.inp") ;
	 	fflush(stdin);
	 	cout<<"Nhap ma xe dap " ; getline(fcin,x.maxd);
	 	cout<<"Nhap hang san xuat xe dap " ; getline(fcin, x.tenhangsx);
	 	cout<<"Nhap don gia " ; fcin>>x.dongia ;
	 	cout<<"Nhap so luong xe "; fcin >>x.sl ;
	 	return is ;
	 	fcin.close() ;
	 }
	 float Thanhtien()
	{
		return (float)((dongia*sl) + (dongia*sl)*0.1 )  ;
	}
	 friend ostream& operator << (ostream& os ,XEDAP &x )
	 {
	 	os<<setw(15)<<x.maxd ;
	 	os<<setw(30)<<x.tenhangsx ;
	 	os<<setw(15)<<x.dongia ;
	 	os<<setw(9)<<x.sl ;
		os<<setw(15)<<x.Thanhtien()<<endl ;
	 	return os ;	
	 	
	 }
	 
    bool operator < (XEDAP &x1)
    {
    	return this->dongia < x1.dongia ;
	}

} ;
void tieude()
{
		cout<<setw(15)<<"Ma xe dap" ;
	 	cout<<setw(30)<<"Ten hang san xuat" ;
	 	cout<<setw(15)<<"Don gia" ;
	 	cout<<setw(9)<<"So luong" ;
		cout<<setw(15)<<"Thanh tien" <<endl ;
	 	
}
void menu()
{   
	cout<<"======================================================"<<endl ;
	cout<<"1.Nhap danh sach xe dap "<<endl ;
	cout<<"2.In danh sach xe dap "<<endl ;
	cout<<"3.Thong tin xe dap co thanh tien > 200 la "<<endl ;
	cout<<"4.Danh sach xe dap co ma la 'XED 0105' va xoa " <<endl ;
	cout<<"5.Thong tin xe dap co ten hang 'XUANHOA' va chen  "<<endl ;
	cout<<"6.Sap xep danh sach theo thu tu tang dan cua hang san xuat "<<endl ;
	cout<<"======================================================"<<endl ;
}
void nhap1(XEDAP x[],int &n)
{
	ifstream fcin ;
	//fcin.open("baitapppp.inp") ;
	cout<<"Nhap so xe dap " ; fcin >> n ;
	for (int i=0 ; i<n ;i++)
	{
		cout<<"Nhap xe dap thu " <<i+1<<endl ;
		cin>>x[i] ;
	}
	cout<<endl ;
	//fcin.close() ;
}
void in1(XEDAP x[],int n)
{
	tieude() ;
	for (int i=0 ; i<n ;i++)
	{
		cout<<x[i] ;
	}
	cout<<endl ;
}
void timgia(XEDAP x[],int n)
{
	tieude();
	for (int i=0 ; i<n ;i++)
	{
		if(x[i].Thanhtien()>200)
		cout<<x[i] ;
	}
}
void timvaxoa(XEDAP x[],int &n)
{
	int dem = 0 ;
	int k ;
	for (int i=0 ; i<n ;i++)
	{
		if(x[i].maxd == "XED 0105")
		k= i ;
		dem++ ;
		
	}
	if(dem==0)
	cout<<"Khong tim thay xe dap "<<endl ;
	else 
	for (int j=k ; j<n ;j++)
	{
		x[j]=x[j+1];
		n-- ;
	}
	cout<<"Da xoa xe dap co ma la XED 0105 "<<endl ;
	cout<<"Moi chon lua chon 2 "<<endl ;
	
}

void timvachen(XEDAP x[],int &n)
{
	int d=0 ;
	int vc ;
		for (int i=0 ; i<n ;i++)
	{
		if(x[i].tenhangsx == "XUANHOA")
		d++ ;
		
	}
	if(d!=0)
	cout<<"Da co xe dap hang XUANHOA "<<endl ;
	else
	{
	 
	cout<<"Chon vi tri can chen tu 0 den "<<n<<" " ;
	cin>>vc ;
	for (int j=n ; j>vc ;j--)
	{
		x[j]=x[j-1];
		n++ ;
	}
	cin>>x[vc] ;
}
	cout<<"Da chen vao vi tri "<<vc<<endl ;
	cout<<"Moi chon lua chon 2 "<<endl ;
}
void sxtd(XEDAP x[],int n)
{
	for (int i=0 ; i<n-1 ;i++)
	for (int j=i+1 ; j<n ;j++)
	{
		if(x[i].tenhangsx >x[j].tenhangsx )
		swap(x[i],x[j]) ;
	}
	cout<<"Da sap  xep tang dan "<<endl ;
	cout<<"Moi chon lua chon 2 "<<endl ;
	
}
int main()
{
    int n ;
	int chon , luachon ;
	XEDAP x[30]  ;
	//nhap1(x,n) ;
	while(chon=1)
	{
		system("cls") ;
		menu() ;
		cout<<"Nhap lua chon " ; cin>>luachon ;
		switch(luachon){
			case 1 :
			//	system("cls") ;
	            nhap1(x,n) ;
	            
				break ;
			case 2 :
				system("cls") ;
				in1(x,n) ;
				system("pause") ;
				break ;
				
			case 3 :
				system("cls") ;
				timgia(x , n) ;
				system("pause") ;
				break ;
			case 4 :
				system("cls") ;
				timvaxoa(x,n ) ;
				system("pause") ;
		    	break ;
			case 5 :
				system("cls") ;
				timvachen(x,n);
				system("pause") ;
				break ;
			case 6 :
				system("cls") ;
				sxtd(x,n) ;
				system("pause") ;
				break ;
		
			default :
				break ;
			
				
		}
	}
	  
}



