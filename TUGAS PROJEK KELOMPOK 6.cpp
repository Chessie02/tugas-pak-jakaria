#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Komputer {
    string kode;
    string jenis;
    string merek;
    int hdd;
    int ram;
    float ukuranLayar;
    string keyboard;
    string mouse;
    double harga;
    int stok;
};
vector<Komputer> dataKomputer;
void tambahKomputer() {
    Komputer k;
    cout << "Masukkan Kode Komputer: ";
    cin >> k.kode;
    cout << "Masukkan Jenis Komputer: ";
    cin >> k.jenis;
    cout << "Masukkan Merek Komputer: ";
    cin >> k.merek;
    cout << "Masukkan Kapasitas HDD (GB): ";
    cin >> k.hdd;
    cout << "Masukkan Kapasitas RAM (GB): ";
    cin >> k.ram;
    cout << "Masukkan Ukuran Layar (Inci): ";
    cin >> k.ukuranLayar;
    cout << "Masukkan Tipe Keyboard: ";
    cin >> k.keyboard;
    cout << "Masukkan Tipe Mouse: ";
    cin >> k.mouse;
    cout << "Masukkan Harga Per Unit: ";
    cin >> k.harga;
    cout << "Masukkan Jumlah Stok: ";
    cin >> k.stok;
    dataKomputer.push_back(k);
    cout << "Data berhasil ditambahkan!\n";
}
void editKomputer() {
    string kode;
    cout << "Masukkan Kode Komputer yang ingin diedit: ";
    cin >> kode;
    for (auto &k : dataKomputer) {
        if (k.kode == kode) {
            cout << "Masukkan Data Baru:\n";
            cout << "Masukkan Jenis Komputer: ";
            cin >> k.jenis;
            cout << "Masukkan Merek Komputer: ";
            cin >> k.merek;
            cout << "Masukkan Kapasitas HDD (GB): ";
            cin >> k.hdd;
            cout << "Masukkan Kapasitas RAM (GB): ";
            cin >> k.ram;
            cout << "Masukkan Ukuran Layar (Inci): ";
            cin >> k.ukuranLayar;
            cout << "Masukkan Tipe Keyboard: ";
            cin >> k.keyboard;
            cout << "Masukkan Tipe Mouse: ";
            cin >> k.mouse;
            cout << "Masukkan Harga Per Unit: ";
            cin >> k.harga;
            cout << "Masukkan Jumlah Stok: ";
            cin >> k.stok;
            cout << "Data berhasil diupdate!\n";
            return;
        }
    }
    cout << "Data tidak ditemukan!\n";
}
void hapusKomputer() {
    string kode;
    cout << "Masukkan Kode Komputer yang ingin dihapus: ";
    cin >> kode;
    for (auto it = dataKomputer.begin(); it != dataKomputer.end(); ++it) {
        if (it->kode == kode) {
            dataKomputer.erase(it);
            cout << "Data berhasil dihapus!\n";
            return;
        }
    }
    cout << "Data tidak ditemukan!\n";
}
void lihatKomputer() {
    cout << left << setw(10) << "Kode" << setw(10) << "Jenis" << setw(10) << "Merek"
         << setw(10) << "HDD" << setw(10) << "RAM" << setw(15) << "Layar"
         << setw(10) << "Keyboard" << setw(10) << "Mouse" << setw(15) << "Harga"
         << setw(10) << "Stok" << endl;
    for (const auto &k : dataKomputer) {
        cout << left << setw(10) << k.kode << setw(10) << k.jenis << setw(10) << k.merek
             << setw(10) << k.hdd << setw(10) << k.ram << setw(15) << k.ukuranLayar
             << setw(10) << k.keyboard << setw(10) << k.mouse << setw(15) << k.harga
             << setw(10) << k.stok << endl;
    }
}
void cetakKomputer() {
    cout << "Fitur cetak masih dalam pengembangan.\n";
}
int main() {
    int pilihan;
    do {
        cout << "\nMenu CRUD Data Komputer:\n";
        cout << "1. Tambah Data Komputer\n";
        cout << "2. Edit Data Komputer\n";
        cout << "3. Hapus Data Komputer\n";
        cout << "4. Lihat Data Komputer\n";
        cout << "5. Cetak Data Komputer\n";
        cout << "6. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahKomputer();
                break;
            case 2:
                editKomputer();
                break;
            case 3:
                hapusKomputer();
                break;
            case 4:
                lihatKomputer();
                break;
            case 5:
                cetakKomputer();
                break;
            case 6:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    return 0;
}
