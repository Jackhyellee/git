#include<iostream>
#include<iomanip>

using namespace std;

class MayIn{
	protected:
		string shieu;
		int sluong;
	public:
		MayIn(string shieu=" "){
			this->shieu = shieu;
			sluong = 0;
		}
		~MayIn(){	}
		void Nhap()
		{
			fflush(stdin);
			cout<<"Nhap so hieu " ; getline(cin ,shieu);
			cout<<"Nhap so luong " ; cin>>sluong ;
	 	}
		void NhapKho(int q){
			sluong += q;
		}
		void XuatKho(int q){
			if(sluong > q){
				sluong -= q;
			}
			else{
				sluong = 0;
			}
			
			
		}
		void In(){
			cout<<"May in "<<shieu<<", so luong con trong kho: "<<sluong<<endl;
		}
};
class MayInLaser : public virtual MayIn{
	protected:
		int dpi;
		MayInLaser(int dpi){this->dpi = dpi;}
	public:
		MayInLaser(string shieu=" ", int dpi=0):MayIn(shieu){
			this->dpi = dpi;
		}
		
		~MayInLaser(){	}
			void Nhap1()
		{
			MayIn::Nhap() ;
			cout<<"Nhap dpi " ; cin>>dpi;
	 	}
		void In(){
			cout<<"May in laser "<<shieu<<" (dpi:"<<dpi<<"), so luong con trong kho: "<<sluong<<endl;
		}
};
class MayInMau : public virtual MayIn{
	protected:
		int bangmau;
		MayInMau(int bangmau){this->bangmau = bangmau;}
	public:
		MayInMau(string shieu=" ", int bangmau=0):MayIn(shieu){
			this->bangmau = bangmau;
		}
		~MayInMau(){	}
			void Nhap2()
		{
			MayIn::Nhap() ;
			cout<<"Nhap bang mau " ; cin>>bangmau ;
	 	}
		void In(){
			cout<<"May in mau "<<shieu<<" (bang mau:"<<bangmau<<"), so luong con trong kho: "<<sluong<<endl;
		}
		
};
class MayInLM : public MayInLaser, public MayInMau{
	public:
		MayInLM(string shieu=" ", int dpi=0, int bangmau=0):
		MayIn(shieu), MayInLaser(dpi), MayInMau(bangmau)
		{	}
		~MayInLM(){	}
		
			void Nhap3()
		{
			MayInLaser::Nhap1() ;
			cout<<"Nhap bang mau " ; cin>>bangmau ;
			
	 	}
		void In(){
			cout<<"May in laser mau "<<shieu<<" (dpi:"<<dpi<<", bang mau:"<<bangmau<<"), so luong con trong kho: "<<sluong<<endl;
		}
		
};

int main(){
	MayIn m1 ;
	cout<<"May in "<<endl ;
	m1.Nhap() ;
	
	cout<<"May inlaser "<<endl ;
	MayInLaser m2 ;
	m2.Nhap1() ;
	cout<<"May in mau "<<endl ;
	MayInMau m3 ;
	m3.Nhap2() ;
	cout<<"May in laser mau "<<endl ;
	MayInLM m4 ;
	m4.Nhap3() ;
	
	m1.NhapKho(3);
	m2.NhapKho(7);
	m3.NhapKho(10);
	m1.XuatKho(5);
	m4.NhapKho(9);
	m3.XuatKho(6);
	m2.XuatKho(10);
	m1.NhapKho(37);
	
	cout<<"\n_SO LUONG MAY IN CON TRONG KHO_\n";
	m1.In();
	m2.In();
	m3.In();
	m4.In();
	
	
	
	return 0;
}
