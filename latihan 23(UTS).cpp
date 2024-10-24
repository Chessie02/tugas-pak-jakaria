#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	
	cout <<fixed << setprecision (0);
	const int maxmhs= 360 ;
	float bayarawal[maxmhs],									jumlahcicilan[maxmhs],										besarcicilan[maxmhs],bayaran[maxmhs],		uangkuliah[maxmhs],terbayar[maxmhs],			sisauangkuliah[maxmhs];
	string nama[maxmhs],npm[maxmhs],				kode[maxmhs],jurusan[maxmhs]; 
	char lagi;
	int nomhs =0;
	float totalkuliah =0;
	
	
	cout <<"-----------PEMBAYARAN UANG KULIAH MAHASISWA PENUSA-----------" <<endl;
	cout <<"-------------------------------------------------------------" <<endl;
	cout <<endl;
	
	do{
		
		cout<<"Mahasiswa Ke-  "<<nomhs +1 <<endl;
		cout<<"Nama Mahasiswa            :";
		cin >>nama[nomhs];
		cout<<"NPM                       :";
		cin >>npm[nomhs];
		cout<<"Kode                  	  :";
		cin >>kode[nomhs];
		
		if(kode [nomhs] == "SI"){
			jurusan	 [nomhs] = "Sistem Informasi";
			bayarawal [nomhs] = 2100000 ;
			jumlahcicilan [nomhs] = 7 ;
			besarcicilan [nomhs] = 300000;
		}
		else if(kode [nomhs] == "TI"){
			jurusan  [nomhs]    = "Teknik Informatika";
			bayarawal [nomhs]  = 2500000 ;
			jumlahcicilan [nomhs] = 7 ;
			besarcicilan [nomhs] = 300000;
		}
		else if(kode [nomhs] == "KA"){
			jurusan  [nomhs] = "Komputer Akuntansi";
			bayarawal [nomhs] = 1700000 ;
			jumlahcicilan [nomhs] = 6 ;
			besarcicilan [nomhs] = 200000;
		}
		else if(kode [nomhs] == "MI"){
			jurusan  [nomhs] = "Manajemen Informatika";
			bayarawal [nomhs] = 1500000 ;
			jumlahcicilan [nomhs] = 6 ;
			besarcicilan [nomhs] = 250000;
		}
		
		
		cout<<"Jurusan                      								:"<<jurusan[nomhs]<<endl;
		cout<<"Pembayaran Awal              						:Rp"<<bayarawal[nomhs]<<endl;
		cout<<"Jumlah Cicilan               							:"<<jumlahcicilan[nomhs]<<endl;
		cout<<"Besar Cicilan                								:Rp"<<besarcicilan[nomhs]<<endl;
		cout<<"Pembayaran Ke                                           		:";
		cin >>bayaran[nomhs];
		
		
uangkuliah [nomhs]= bayarawal [nomhs] + (jumlahcicilan [nomhs]*									besarcicilan[nomhs]);
terbayar [nomhs] = bayarawal [nomhs] + 			(bayaran [nomhs] * besarcicilan [nomhs]);	sisauangkuliah [nomhs] = uangkuliah 				[nomhs] - terbayar [nomhs];
		
		totalkuliah += sisauangkuliah [nomhs];
		
		
		cout<<"Uang Kuliah                  							:Rp"<<uangkuliah[nomhs]<<endl;
		cout<<"Uang Kuliah Terbayar                            		  :Rp"<<terbayar[nomhs]<<endl;
	cout<<"Sisa Uang Kuliah yang Harus Di  Bayar		 		  :Rp"  <<sisauangkuliah[nomhs]<<endl;
		
		nomhs++;
		
		cout<< endl;	
	
		cout<< "Masih Ingin Menghitung Uang Kuliah Mahasiswa? [Y/T] :" ;
		cin >>lagi;
		cout<<endl;
		
	} while (lagi == 'Y' || lagi == 'y');
	
	cout<<left;
	cout<<  setw(5) << "No"
         << setw(8)     << "Nama"
         << setw(5)     << "Kode"
         << setw(23)   << "Jurusan"
         << setw(10)   << "UKT"
         << setw(15)   << "Awal Bayar"
         << setw(8)     << "Cicilan"
         << setw(15)   << "Besar Cicilan"
         << setw(12)   << "Cicilan ke"
         << setw(10)   << "Terbayar" 
		 << setw(20)   << "Sisa Harus Di Bayar"<< endl;
		 
	cout<< "------------------------------------------------------------------------------------------------------------------------------" << endl;
	
	
	for (int i = 0; i < nomhs; i++){
		cout<<  setw(5) << i + 1
         << setw(8) 	<< nama[i]
         << setw(5)	 << kode[i]
         << setw(23)   << jurusan[i]
         << setw(10)   << uangkuliah[i]
         << setw(15)   << bayarawal[i]
         << setw(8)      << jumlahcicilan[i]
         << setw(15)    << besarcicilan[i]
         << setw(12)    << bayaran[i]
         << setw(10)    << terbayar[i] 
		 << setw(20)    << sisauangkuliah[i] << endl;
		
	}
	cout<<"Total Uang Yang Harus Di Bayar Oleh Mahasiswa                                                                    :Rp" <<totalkuliah <<endl;
	return 0;
}