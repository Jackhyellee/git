#include<iostream>


using namespace std ;

class DaThuc
{
	private:
		int a, b, c, d;
		
	public:
		DaThuc(int a1 = 0, int b1 = 0, int c1 = 0, int d1 = 0){
			a = a1;
			b = b1;
			c = c1;
			d = d1;
		}
		~DaThuc(){
		}
		
		friend istream& operator >> (istream &is, DaThuc &dt)
		{
			cout<<"Nhap he so bac 3: "; is>>dt.a;
			cout<<"Nhap he so bac 2: "; is>>dt.b;
			cout<<"Nhap he so bac 1: "; is>>dt.c;
			cout<<"Nhap he so bac 0: "; is>>dt.d;
			
			return is;	
		}
		
		friend ostream& operator << (ostream &os, DaThuc &dt)
		{
			cout <<"(" << dt.a <<")" <<"X^3" << " + " << "(" << dt.b << ")" << "x^2" << " + " << "(" << dt.c << ")" << "X" << " + " << "(" << dt.d << ")" << endl;
			
			return os;	
		}
		
		DaThuc operator + (DaThuc &dt)
		{
			DaThuc tong;
			tong.a = this->a + dt.a;
			tong.b = this->b + dt.b;
			tong.c = this->c + dt.c;
			tong.d = this->d + dt.d;
			
			return tong;
		}
		
		DaThuc operator - (DaThuc &dt)
		{
			DaThuc hieu;
			hieu.a = this->a - dt.a;
			hieu.b = this->b - dt.b;
			hieu.c = this->c - dt.c;
			hieu.d = this->d - dt.d;
			
			return hieu;
		}
};

int main()
{
	DaThuc dt1, dt2;
	
	cout<<"NHAP DA THUC THU NHAT: \n";
	cin>>dt1;	cout<<endl;
	cout<<"NHAP DA THUC THU HAI: \n";
	cin>>dt2;	cout<<endl;
	
	cout<<"Da thuc 1 la: "; cout<<dt1;
	cout<<"\nDa thuc 2 la: "; cout<<dt2;
	
	DaThuc dt3, dt4;
	dt3 = dt1 + dt2;
	dt4 = dt1 - dt2;
	cout<<"\nTong 2 da thuc la: "; cout<<dt3;
	cout<<"\nHieu 2 da thuc la: "; cout<<dt4;
	cout<<endl;
	return 0;	
}
