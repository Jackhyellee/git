#include<iostream>
using namespace std;

class PS{
	private:
		int ts, ms;
	public:
		PS(int ts=0, int ms=1){
			this->ts=ts;
			this->ms=ms;
		}
		~PS(){	}
		void Nhap(){
			cout<<"Nhap tu so: ";	cin>>ts;
			cout<<"Nhap mau so: ";	cin>>ms;
		}
		int UCLN(){
			int min, ucln = 1;
			if(ts>ms)	min=ms;
			else	min=ts;
			for(int i=1; i<=min; i++)
				if(ts%i==0 && ms%i==0)
					ucln = i;
			return ucln;
		}
		PS psRutGon(){
			PS ps;
			int uc = UCLN();
			ps.ts = this->ts/uc;
			ps.ms = this->ms/uc;
			return ps;
		}
		void HienThi(){
			if(ms == 1)
				cout<<ts<<endl;
			else
				cout<<ts<<"/"<<ms<<endl; 
		}
		int BCNN(){
			int max = ts*ms, bcnn;
			for(int i=max; i>=1; i--)
				if(i%ts==0 && i%ms==0)
					bcnn = i;
			return bcnn;
		}
		PS psTong(PS ps){
			PS psTong;
			psTong.ts = this->ts*ps.ms + this->ms*ps.ts;
			psTong.ms = this->ms*ps.ms;
			return psTong;  
		}
		PS psTich(PS ps){
			PS psTich;
			psTich.ts = this->ts*ps.ts;
			psTich.ms = this->ms*ps.ms;
			return psTich;
		}
};

int main(){
	PS *p; 
	int n;
	do{
		cout<<"Nhap so phan so :";	cin>>n;
	}while(n<=0);
	p = new PS[n]; 
	for(int i=0; i<n; i++){
		cout<<"\tNhap phan so thu "<<i+1<<endl;
		p[i].Nhap(); 
	}
	for(int i=0; i<n; i++){
		cout<<"Phan so "<<i+1<<":\t";
		p[i].HienThi();
	}
	cout<<"\n_________________________________\n";
	PS tong, tich(1, 1);
	for(int i=0; i<n; i++)
		tong = tong.psTong(p[i]);
	cout<<"Phan so tong: \t";
	tong = tong.psRutGon();
	tong.HienThi();
	for(int i=0; i<n; i++)
		tich = tich.psTich(p[i]);
	cout<<"Phan so tich: \t";
	tich = tich.psRutGon();
	tich.HienThi();
	return 0;
}
