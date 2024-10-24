#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    cout << fixed << setprecision(2);
    const int maxpgw = 20;
    string namapegawai[maxpgw], golongan[maxpgw], kode[maxpgw], 			jabatan[maxpgw];
    float gaji[maxpgw], tunjangan[maxpgw], pinjaman[maxpgw], pajak[maxpgw], totlgajikotor[maxpgw], totlgajibersih[maxpgw];
    char lagi;
    int pgw = 0;
    float total_biaya = 0;

    cout << " gaji pt .telkom-----------------------------------------------\n";

    do {
        cout << "Pegawai ke-" << pgw + 1 << endl;
        cout << "Nama Pegawai              : ";
        cin >> namapegawai[pgw]; 
        cout << "Golongan                  : ";
        cin >> golongan[pgw];
        cout << "Kode Jabatan              : ";
        cin >> kode[pgw];

        if (golongan[pgw] == "la") {
            gaji[pgw] = 500000;
        } else if (golongan[pgw] == "llb") {
            gaji[pgw] = 750000;
        } else if (golongan[pgw] == "llla") {
            gaji[pgw] = 1000000;
        } else if (golongan[pgw] == "lb") {
            gaji[pgw] = 1500000;
        } else if (golongan[pgw] == "llb") {
            gaji[pgw] = 1750000;
        } else if (golongan[pgw] == "lllb") {
            gaji[pgw] = 2500000;
        } else {
  cout << "Golongan tidak valid!" << endl;
            continue;
        }

        if (kode[pgw] == "Dir") {
            jabatan[pgw] = "direktur";
            tunjangan[pgw] = 4500000;
        } else if (kode[pgw] == "Sek") {
            jabatan[pgw] ="sekretaris";
            tunjangan[pgw] = 3000000;
        } else if (kode[pgw] == "Wak"){
            jabatan[pgw] ="wakil direktur";
            tunjangan[pgw] = 3750000;
        } else if (kode[pgw] == "Stf") {
            jabatan[pgw] = "Staf Administrasi";
            tunjangan[pgw] = 2000000;
        } else {
            cout << "Kode jabatan tidak valid!" << endl;
            continue;
        }

        cout << "Pinjaman : "; 
        cin >> pinjaman[pgw];

        pajak[pgw] = gaji[pgw] * 0.05;
        totlgajikotor[pgw] = gaji[pgw] + tunjangan[pgw];
        totlgajibersih[pgw] =totlgajikotor[pgw] - pinjaman[pgw] - pajak[pgw];
        
        cout << left;
        cout << setw(20) << "Jabatan: " << jabatan[pgw] << endl;
        cout << setw(20) << "Gaji: " << gaji[pgw] << endl;
        cout << setw(20) << "Tunjangan: " << tunjangan[pgw] << endl;
        cout << setw(20) << "Pinjaman: " << pinjaman[pgw] << endl;
        cout << setw(20) << "Pajak: " << pajak[pgw] << endl;
        cout << setw(20) << "Total Kotor: " << totlgajikotor[pgw] << endl;
        cout << setw(20) << "Total Bersih: " << totlgajibersih[pgw] << endl;
        cout << "--------------------------------------------------------\n";
        
        total_biaya += totlgajibersih[pgw];

        pgw++;
        
        cout << "Lanjut? [Y/T]: "; 
        cin >> lagi;
        cout << endl;

    } while (lagi == 'y' || lagi == 'Y' );
    
    cout << left;
    cout << setw(5) << "No"
         << setw(15) << "Nama"
         << setw(10) << "Golongan"
         << setw(15) << "Jabatan"
         << setw(15) << "Gaji"
         << setw(15) << "Tunjangan"
         << setw(15) << "Pinjaman"
         << setw(15) << "Pajak"
         << setw(15) << "Gaji Kotor"
         << setw(15) << "Gaji Bersih" << endl;

    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < pgw; i++) {
        cout << setw(5) << i + 1
             << setw(15) << namapegawai[i]
             << setw(10) << golongan[i]
             << setw(15) << jabatan[i]
             << setw(15) << gaji[i]
             << setw(15) << tunjangan[i]
             << setw(15) << pinjaman[i]
             << setw(15) << pajak[i]
             << setw(15) << totlgajikotor[i]
             << setw(15) << totlgajibersih[i] << endl;
    }

    cout << endl;
    cout << "Total biaya yang dibayar perusahaan ke semua pegawai: Rp " << total_biaya << endl;
    cout << endl;

    return 0;
}
