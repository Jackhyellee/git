#include<iostream>

using namespace std;

const int dMax = 70;

class STUDENT{
	protected:
		string msv, ht, gt;
	public:
		STUDENT(string msv=" ", string ht=" ", string gt=" "){
			this->msv =msv;
			this->ht = ht;
			this->gt = gt;
		}
		~STUDENT(){	}
		friend istream& operator>>(istream& is, STUDENT &sv){
			fflush(stdin);
			cout<<"\tNhap ma sinh vien: ";	getline(is, sv.msv);
			cout<<"\tNhap ho ten sinh vien : ";		getline(is, sv.ht);
			cout<<"\tNhap gioi tinh: ";	getline(is, sv.gt);
			return is;
		}
		friend ostream& operator<<(ostream& os, STUDENT &sv){
			os<<"\tMa sinh vien: "<<sv.msv<<endl;
			os<<"\tHo ten: "<<sv.ht<<endl;
			os<<"\tGioi tinh: "<<sv.gt<<endl;
			return os;
		}
};
class MONHOC{
	protected:
		string mm, tm;
	public:
		MONHOC(string mm=" ", string tm=" "){
			this->mm = mm;
			this->tm =tm;
		}
		~MONHOC(){	}
		friend istream& operator>>(istream& is, MONHOC &mh){
			cout<<"\tMa mon: ";	getline(is, mh.mm);
			cout<<"\tTen mon: ";	getline(is, mh.tm);
			return is;
		}
		friend ostream& operator<<(ostream& os, MONHOC &mh){
			os<<"\tMa mon: "<<mh.mm<<endl;
			os<<"\tTen mon: "<<mh.tm<<endl;
			return os;
		}
};
class DIEMMH: public STUDENT, public MONHOC{
	private:
		float diemthi;
	public:
		DIEMMH(string msv=" ", string ht=" ", string gt=" ", string mm=" ", string tm=" ", float diemthi=0):
		STUDENT(msv,ht,gt), MONHOC(mm,tm){
			this->diemthi = diemthi;
		}
		~DIEMMH(){	}
		bool operator==(string x){
			return(this->gt == x);
		}
		friend istream& operator>>(istream& is, DIEMMH &d){
			is>>(STUDENT&)d;
			is>>(MONHOC&)d;
			cout<<"\tNhap diem thi: ";	is>>d.diemthi;
			return is;
		}
		friend ostream& operator<<(ostream& os, DIEMMH &d){
			os<<(STUDENT&)d;
			os<<(MONHOC&)d;
			os<<"\tNhap diem thi: "<<d.diemthi<<endl;
			return os;
		}
		friend float TBD(DIEMMH d[], int n);
		friend void TDT(DIEMMH d[], int n);
		bool operator<(DIEMMH &d){
			return(this->diemthi < d.diemthi);
		}
		friend void ToanMin(DIEMMH d[], int n);
};

int main(){
	int n, i, j;
	cout<<"Nhap so doi tuong : ";	cin>>n;
	DIEMMH d[n];
	
	
	cout<<"_NHAP DANH SACH QUAN LI CAC DOI TUONG DIEM MON HOC_\n";
	
	for(i=0; i<n; i++){
		cout<<"\nNhap doi tuong thu "<<i+1<<endl;
		cin>>d[i];
	}
	
	
	cout<<"\n_DANH SACH CAC DOI TUONG DIEM MON HOC_\n";
	for(i=0; i<n; i++){
		cout<<"\nThong tin doi tuong thu "<<i+1<<endl;
		cout<<d[i];
	}
	
	cout<<"\n_DANH SACH CAC DOI TUONG GIOI TINH NAM_\n";
	for(i=0; i<n; i++){
		if(d[i] == "nam"){
			cout<<d[i];
		}
	}
	
	cout<<"\n_TRUNG BINH DIEM CAC MON HOC TRONG DANH SACH_";
	cout<<"Trung binh diem thi: "<<TBD(d, n)<<endl;
	
	
	cout<<"\n_TIM DOI TUONG BANG TEN SINH VIEN_";
	TDT(d, n);
	
	
	cout<<"\n_DOI TUONG CO DIEM MON TOAN NHO NHAT_\n";

	ToanMin(d, n);
	
	cout<<"\n_DANH SACH THEO CHIEU GIAM DAN DIEM THI_\n";
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(d[i]<d[j])
				swap(d[i],d[j]);
	for(i=0; i<n; i++){
		cout<<"\nThong tin doi tuong thu "<<i+1<<endl;
		cout<<d[i];
	}
	return 0;
}
float TBD(DIEMMH d[], int n){
	int sum = 0;
	for(int i=0; i<n; i++)
		sum += d[i].diemthi;
	return((float)sum/n);
}
void TDT(DIEMMH d[], int n){
	int dem = 0;
	string x;
	fflush(stdin);
	cout<<"Nhap ten sinh vien muon tim: ";	getline(cin, x);
	for(int i=0; i<n; i++)
		if(d[i].ht == x){
			cout<<"\n";
			cout<<d[i];
			dem++;
		}
	if(dem == 0)
		cout<<"\nKhong ton tai doi tuong ten '"<<x<<"' trong danh sach";
}
void ToanMin(DIEMMH d[], int n){
	int dem = 0;
	DIEMMH toanMin;
	toanMin.diemthi = dMax + 1;	//lon hon diem lon nhat
	for(int i=0; i<n; i++){
		if(d[i].tm == "Toan"){
			dem ++;
			if(d[i] < toanMin)//ham <
			toanMin = d[i];
		}
	}
	if(dem != 0)
		cout<<toanMin;
	else
		cout<<"Khong co doi tuong co ten mon la 'Toan' trong danh sach";
	
	
	
}
