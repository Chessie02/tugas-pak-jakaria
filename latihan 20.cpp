#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	const int maxbarang=60;
	string nbarang[maxbarang];
	int harga[maxbarang];
	float jumlahjual[maxbarang];
	float totalharga[maxbarang];
	int jumlahbarang=0;
	char lagi;
	
	 do{
		cout<<"masukan nama barang ke-"<<jumlahbarang+1<<":";
		cin>> nbarang[jumlahbarang];
		cout<<"masukan jumlah harga:"<<nbarang[jumlahbarang]<<":";
		cin>> harga[jumlahbarang];
		cout<<"masukan jumlah jual:"<<nbarang[jumlahbarang]<<":";
		cin>> jumlahjual[jumlahbarang];
		totalharga[jumlahbarang]=harga[jumlahbarang]*jumlahjual[jumlahbarang];
		jumlahbarang++;
		
	//setw mengatue jarak
	//left rata sebelum kiri
		cout<<"apakah anda ingin input data lagi? (Y/T):";
	}while(lagi=='y'|| lagi=='Y');
	cout<<"\n=========================================\n";
	cout<< setw(15)<< left<<"nama"
		<< setw(15)<< "harga"
		<< setw(16)<< "jumlahjual"
		<< setw(15)<< "totalharga"<<endl;
	cout<<"\n=========================================\n";
	for(int i=0; i<jumlahbarang; i++){
		cout<< setw(15)<< left<<nbarang[i]
			<< setw(15)<< harga[1]
			<< setw(15)<< jumlahjual[1]
			<< setw(15)<< totalharga[i]<<endl;
}
	cout<<"\n==========================================\n";
	  return 0;

}
