#include <iostream>

using namespace std;

int pokok(int jamKerja) {
    return jamKerja * 2000;
}

int lembur(int jamKerja) {
    if (jamKerja > 7) {
        return (jamKerja - 7) * 2000 * 1.5;
    } else {
        return 0;
    }
}

int makan(int jamKerja) {
    if (jamKerja >= 8 && jamKerja <= 10) {
        return 1500;
    } else if (jamKerja > 10) {
        return 2500;
    } else {
        return 0;
    }
}

int jasa(int jamKerja) {
    if (jamKerja >= 9) {
        return 3000;
    } else {
        return 0;
    }
}

int main() {
    int jamKerja;

    cout << "Masukkan jumlah jam kerja: ";
    cin >> jamKerja;

    int gajiPokok = pokok(jamKerja);
    int gajiLembur = lembur(jamKerja);
    int uangMakan = makan(jamKerja);
    
    int uangJasa = jasa(jamKerja);

    int totalGaji = gajiPokok + gajiLembur + uangMakan + uangJasa;

    cout << "\nRincian Gaji:" << endl;
    cout << "Gaji Pokok: Rp " << gajiPokok << endl;
    cout << "Gaji Lembur: Rp " << gajiLembur << endl;
    cout << "Uang Makan: Rp " << uangMakan << endl;
    cout << "Uang Jasa: Rp " << uangJasa << endl;
    cout << "\nTotal Gaji: Rp " << totalGaji << endl;

    return 0;
}
