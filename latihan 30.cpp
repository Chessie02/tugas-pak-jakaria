#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    string golongan;
    string kodeJabatan;
    double gaji;
    double tunjangan;
    double pinjaman;
    double pajak;
};

double getGajiGolongan(string golongan) {
    if (golongan == "Ia") return 500000;
    else if (golongan == "Ib") return 750000;
    else if (golongan == "IIa") return 1000000;
    else if (golongan == "IIb") return 1250000;
    else if (golongan == "IIIa") return 1750000;
    else if (golongan == "IIIb") return 2500000;
    else return 0;
}

double getTunjanganJabatan(string kodeJabatan) {
    if (kodeJabatan == "Dir") return 500000;
    else if (kodeJabatan == "Sek") return 300000;
    else if (kodeJabatan == "WDK") return 375000;
    else if (kodeJabatan == "STA") return 200000;
    else return 0;
}

double htgPajak(double gaji) {
    return gaji * 0.05;
}

int main() {
    Employee emp;
    
    
    cout << "Masukkan Nama Pegawai: ";
    getline(cin, emp.name);
    cout << "Masukkan Golongan (Ia, Ib, IIa, IIb, IIIa, IIIb): ";
    cin >> emp.golongan;
    cout << "Masukkan Kode Jabatan (Dir, Sek, WDK, STA): ";
    cin >> emp.kodeJabatan;
    cout << "Masukkan Pinjaman: ";
    cin >> emp.pinjaman;
    
    // Calculate Gaji, Tunjangan, and Pajak
    emp.gaji = getGajiGolongan(emp.golongan);
    emp.tunjangan = getTunjanganJabatan(emp.kodeJabatan);
    emp.pajak = htgPajak(emp.gaji);
    
    // Calculate total gaji kotor and gaji bersih
    double totalGajiKotor = emp.gaji + emp.tunjangan;
    double totalGajiBersih = totalGajiKotor - emp.pinjaman - emp.pajak;
    
    // Display results
    cout << "\n===== Slip Gaji =====" << endl;
    cout << "Nama Pegawai: " << emp.name << endl;
    cout << "Golongan: " << emp.golongan << endl;
    cout << "Kode Jabatan: " << emp.kodeJabatan << endl;
    cout << "Gaji: Rp " << emp.gaji << endl;
    cout << "Tunjangan: Rp " << emp.tunjangan << endl;
    cout << "Pinjaman: Rp " << emp.pinjaman << endl;
    cout << "Pajak: Rp " << emp.pajak << endl;
    cout << "Total Gaji Kotor: Rp " << totalGajiKotor << endl;
    cout << "Total Gaji Bersih: Rp " << totalGajiBersih << endl;

    return 0;
}
