//dibuat oleh chessie paquita senjaya
//nim 240121060
#include<iostream>
#include<iomanip>

using namespace std;
int main()
{
	char npeg[20],njab[20];
	float gaji,pajak,pinjaman,gaber=0;
	
	cout<<"nama pegawai:";
	cin>>npeg;
	cout<<"jabatan:";
	cin>>njab;
	cout<<"gaji";
	cin>>gaji;
	pajak=0.15*gaji;
	cout<<"pajak:"<<pajak<<endl;
	cout<<"pinjaman";
	cin>>pinjaman;
	gaber=gaji -(pinjaman+pajak);
	cout<<"gajibersih:"<<gaber<<endl;
	return 0;
		
}