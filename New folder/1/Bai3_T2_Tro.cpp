#include<iostream>

using namespace std;

class TS{
	private:
		string ht;
		float dT, dV;
	public:
		TS(string ht=" ", float dT=0, float dV=0){
			this->ht = ht;
			this->dT = dT;
			this->dV = dV;
		}
		~TS(){	}
		void Nhap(){
			cin.ignore();
			cout<<"Nhap ho ten: ";	 		getline(cin, ht);
			cout<<"Nhap diem thi toan: "; 	cin>>dT;
			cout<<"Nhap diem thi van: "; 	cin>>dV;
		}
		void In(){
			cout<<"Ho ten: "<<ht<<endl;
			cout<<"Diem toan: "<<dT<<endl;
			cout<<"Diem van: "<<dV<<endl;
		}
		friend void TimKiem(TS *p, int &n);
		friend void SapXep(TS *p, int n);
};

int main(){
	TS *p;
	int n;
	do{
		cout<<"Nhap so thi sinh : "; cin>>n;
	}while(n<=0);
	p = new TS[n];
	cout<<"\n\n_NHAP DANH SACH THI SINH_\n";
	for(int i=0; i<n; i++){
		cout<<"\tNhap thong tin thi sinh thu "<<i+1<<endl;
		p[i].Nhap();
	}
	for(int i=0; i<n; i++){
		cout<<"\tThong tin thi sinh thu "<<i+1<<endl;
		p[i].In();
	}
	cout<<"\n\n_TIM KIEM VA XOA BO THI SINH BANG HO TEN_\n";
	TimKiem(p, n);
	cout<<"\n\n_SAP XEP TANG DAN THEO HO TEN_\n";
	SapXep(p, n);
	return 0;
}
void TimKiem(TS *p, int &n){
	string x;
	cout<<"\tNhap ho ten thi sinh: ";	cin>>x;
	int viTri = n+1;
	for(int i=0; i<n; i++)
		if(p[i].ht == x){
			cout<<"Tim thay thi sinh thu "<<i+1<<endl;
			cout<<"\tDiem thi toan: "<<p[i].dT<<endl;
			cout<<"\tDiem thi van: "<<p[i].dV<<endl;
			viTri = i;
		}
	if(viTri > n)
		cout<<"\n>>Khong ton tai thi sinh mang ten '"<<x<<"' trong danh sach"<<endl;
	else{
		cout<<"\nXoa thi sinh ra khoi danh sach"<<endl;
		for(int i=viTri; i<n-1; i++)
			p[i] = p[i+1];
		n--;
	}	
}
void SapXep(TS *p, int n){
	int min;
	for(int i=0; i<n; i++){
		min = i;
		for(int j=i+1; j<n; j++)
			if(p[min].ht > p[j].ht)
				min = j;
		if(min != i)
			swap(p[i], p[min]);
		cout<<"\tThong tin thi sinh thu "<<i+1<<endl;
		p[i].In();
	}
}
