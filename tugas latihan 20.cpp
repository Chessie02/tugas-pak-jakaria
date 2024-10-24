#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout <<fixed << setprecision(2);
    const int maxbarang = 100;
    string namabarang[maxbarang];
    int harga[maxbarang]; 
    float jumlahjual[maxbarang];
    float totalharga[maxbarang];
    float diskon[maxbarang];
    float totalbayar[maxbarang];
	float  totalpendapatan =0 ; 
    int jumlahbarang = 0;
    char lagi;

    do{
        cout << "Masukkan nama barang ke-  " << jumlahbarang + 1 << " : ";
        cin >> namabarang[jumlahbarang];
        cout << "Harga barang  " << namabarang[jumlahbarang] <<" : ";
        cin >> harga[jumlahbarang];
        cout << "Jumlah barang terjual  " << namabarang[jumlahbarang] << " : ";
        cin >> jumlahjual[jumlahbarang];

        totalharga[jumlahbarang] = harga[jumlahbarang] * jumlahjual[jumlahbarang];

        
        diskon[jumlahbarang] = totalharga[jumlahbarang] * 0.10;
		 
        totalbayar[jumlahbarang] = totalharga[jumlahbarang] - diskon[jumlahbarang];
        
        totalpendapatan +=totalbayar[jumlahbarang];

        jumlahbarang++;

        cout << "Apakah anda ingin lanjut input data lagi? (Y/T): ";
        cin >> lagi; 
    } while (lagi == 'y' || lagi == 'Y');

    cout << "\n=========================================================================================\n";
    cout << setw(15) << left << "Nama barang"
         << setw(15) << "Harga"
         << setw(15) << "Jumlah jual"
         << setw(15) << "Total harga"
         << setw(15) << "Diskon"
         << setw(15) << "Total bayar" << endl;
    cout << "===========================================================================================\n";

    for (int i = 0; i < jumlahbarang; i++) {
        cout << setw(15) << left << namabarang[i]
             << setw(15) << harga[i]
             << setw(15) << jumlahjual[i]
             << setw(15) << totalharga[i]
             << setw(15) << diskon[i]
             << setw(15) << totalbayar[i] << endl; 
    }

    cout << "========================================================================================\n";
    return 0;
}
