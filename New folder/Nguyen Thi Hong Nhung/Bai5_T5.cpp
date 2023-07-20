#include<iostream>
#include<string.h>

using namespace std;

class Person{
	protected:
		string name, address;
		int phone;
	public:
		Person(){
			name = " ";
			address = " ";
			phone = 0;
		}
		Person(string name, string address, int phone){
			this->name = name;
			this->address = address;
			this->phone = phone;
		}
		~Person(){	}
};
class Officer: public virtual Person{
	protected:
		float salary;
		Officer(float salary){this->salary = salary;}
	public:
		Officer(){
			salary = 0;
			
		}
		Officer(string name, string address, int phone, float salary):Person(name,address,phone){
			this->salary = salary;
			
		}
		~Officer(){	}
};
class Student: public virtual Person{
	protected:
		float fee;
		Student(float fee){this->fee = fee;}
	public:
		Student(){
			fee = 0;
			
		}
		Student(string name, string address, int phone, float fee):Person(name,address,phone){
			this->fee = fee;
		}
		~Student(){	}
};
class OffStudent: public Officer, public Student{
	public:
		OffStudent(){	}
		OffStudent(string name, string address, int phone, float salary, float fee):
		Person(name,address,phone), Officer(salary), Student(fee)
		{	}
		~OffStudent(){	}
		void OutScreen(){
			cout<<"\tName: "<<name;
			cout<<"\n\tAddress: "<<address;
			cout<<"\n\tPhone: "<<phone;
			cout<<"\n\tSalary: "<<salary;
			cout<<"\n\tFee: "<<fee<<endl;
		}
		bool operator==(float s){
			return(this->salary == s);
		}
		bool operator>(OffStudent &o){
			return(this->name > o.name);
		}
		friend void SX(OffStudent o[], int n);
};

int main(){
	int m, i, dem = 0;
	cout<<"Nhap so doi tuong offstudent : ";	cin>>m;
	OffStudent ofs[m];
	
	string n, add;
	int p;
	float s,f;
	cout<<"\n_NHAP VAO DANH SACH OFFSTUDENT_\n\n";
	for(i=0; i<m; i++){
		cout<<"Nhap thong tin doi tuong thu "<<i+1<<endl;
		fflush(stdin);
		cout<<"\tName: ";		getline(cin, n);
		cout<<"\tAddress: ";	getline(cin, add);
		cout<<"\tPhone: ";	cin>>p;
		cout<<"\tSalary: ";	cin>>s;
		cout<<"\tFee: ";		cin>>f; 
		ofs[i] = OffStudent(n, add, p, s, f);
	}
	
	cout<<"\n_DANH SACH DOI TUONG OFFSTUDENT_\n\n";
	for(i=0; i<m; i++){
		cout<<"Thong tin cua doi tuong thu "<<i+1<<endl;
		ofs[i].OutScreen();
		cout<<"\n";
	}
	
	
	cout<<"\n_DOI TUONG CO LUONG 5 TRIEU_\n\n";
	for(i=0; i<m; i++)
		if(ofs[i] == 5){
			ofs[i].OutScreen();
			cout<<endl;
			dem++;
		}
	if(dem == 0)
		cout<<"Khong co doi tuong nao co luong 5 trieu trong danh sach\n\n";
		
	cout<<"\n_DANH SACH TANG DAN THEO TEN_\n\n";
	SX(ofs, m);
	for(i=0; i<m; i++){
		cout<<"Thong tin cua doi tuong thu "<<i+1<<endl;
		ofs[i].OutScreen();
		cout<<"\n";
	}
	return 0;
}
void SX(OffStudent o[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(o[i] > o[j])
				swap(o[i], o[j]);
		}
	}
}
