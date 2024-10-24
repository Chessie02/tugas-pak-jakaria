//dibuat oleh chessie paquita senjaya
//nim 240121060

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	float penjualan,komisi,total_komisi=0;
	
	cout<<"masukan jumlah penjualan:";
	cin>>penjualan;
	if(penjualan<=500000){
		komisi=penjualan+0.1;//komisi 10%
	}else{
		komisi 0.1 untuk 500.000 pertama;sisa 0.		15;
		komisi=500000*0.1 +(penjualan-500000)*		0.15;
}
		cout<<"total komisi yang 									diperoleh:Rp"<<komisi<<endl;
		return 0;		
}