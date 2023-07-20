#include<iostream>
#include<iomanip>


using namespace std;

class NGUOI{
	private:
		string ht, nn, qt ;
		int tuoi;
	public:
		NGUOI(){
			ht = " ";
			nn = " ";
			qt = " ";
			tuoi = 0;
		}
		NGUOI(string ht, int tuoi, string nn, string qt){
			this->ht = ht;
			this->tuoi = tuoi;
			this->nn = nn;
			this->qt = qt;
		}
		~NGUOI(){	}
		void Nhap(){
			cin.ignore();
			cout<<"Ho ten: ";		getline(cin, ht);
			cout<<"Nghe nghiep: ";	getline(cin, nn);
			cout<<"Quoc tich: ";	getline(cin, qt);
			cout<<"Tuoi: ";			cin>>tuoi;
		}
		void In(){
			cout<<"|"<<left<<setw(20)<<ht;
			cout<<"|"<<setw(5)<<tuoi;
			cout<<"|"<<setw(15)<<nn;
			cout<<"|"<<right<<setw(21)<<qt<<"|"<<endl;
			cout<<"+"<<setfill('-')<<setw(65)<<"+"<<setfill(' ')<<endl;
		}
		friend void nghebs(NGUOI ng[] , int n) ;
		
};
void TieuDe();
void nghebs(NGUOI ng[] , int n)
{
	TieuDe();
	for(int i=0; i<n; i++)
	{
		if(ng[i].nn=="bac si")
		
		ng[i].In() ;
	}
	
}
int main(){
		NGUOI *ng;
	int n;
	cout<<"Nhap so nguoi la : ";		cin>>n;
	ng = new NGUOI[n] ;
	for(int i=0; i<n; i++){
		cout<<"\tNhap thong tin cua nguoi thu "<<i+1<<endl;
		ng[i].Nhap();
	}
	TieuDe();
	for(int i=0; i<n; i++)
		ng[i].In();
	cout<<"\tDanh sach thong tin nguoi co nghe nghiep la bac si la "  <<endl ;
	nghebs(ng , n)	;
	
	
	
} 

void TieuDe(){
	cout<<"+"<<setfill('-')<<setw(65)<<"+"<<setfill(' ')<<endl;
	cout<<"|"<<left<<setw(20)<<"Ho ten";
	cout<<"|"<<setw(5)<<"Tuoi";
	cout<<"|"<<setw(15)<<"Nghe nghiep";
	cout<<"|"<<right<<setw(21)<<"Quoc tich"<<"|"<<endl;
	cout<<"+"<<setfill('-')<<setw(65)<<"+"<<setfill(' ')<<endl;
}
