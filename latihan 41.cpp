#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Struct untuk menyimpan data
struct Data {
    int nik;
    string nama;
    int gaji;
};

// Fungsi untuk menambahkan data (Create)
void addData(const string &filename) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cout << "Error: Tidak dapat membuka file!" << endl;
        return;
    }

    Data data;
    cout << "Masukkan NIK : ";
    cin >> data.nik;
    cin.ignore(); // Membersihkan buffer
    cout << "Masukkan Nama : ";
    getline(cin, data.nama);
    cout << "Masukkan Gaji : ";
    cin >> data.gaji;

    file << data.nik << "," << data.nama << "," << data.gaji << endl;
    file.close();
    cout << "Data berhasil ditambahkan!" << endl;
}

// Fungsi untuk membaca semua data (Read)
void readData(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Tidak dapat membuka file!" << endl;
        return;
    }

    string line;
    cout << "Data dalam file:" << endl;
    cout << "NIK\t\t\tNama\t\t\tGaji" << endl;
    while (getline(file, line)) {
        stringstream ss(line);
        string nik, nama, gaji;
        getline(ss, nik, ',');
        getline(ss, nama, ',');
        getline(ss, gaji, ',');

        cout << nik << "\t\t\t" << nama << "\t\t\t" << gaji << endl;
    }
    file.close();
}

// Fungsi untuk memperbarui data (Update)
void updateData(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Tidak dapat membuka file!" << endl;
        return;
    }

    vector<Data> dataList;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Data data;
        string nik, gaji;
        getline(ss, nik, ',');
        getline(ss, data.nama, ',');
        getline(ss, gaji, ',');
        data.nik = stoi(nik);
        data.gaji = stoi(gaji);
        dataList.push_back(data);
    }
    file.close();

    int targetId;
    cout << "Masukkan NIK data yang ingin diperbarui: ";
    cin >> targetId;
    cin.ignore();

    bool found = false;
    for (auto &data : dataList) {
        if (data.nik == targetId) {
            found = true;
            cout << "Masukkan Nama baru: ";
            getline(cin, data.nama);
            cout << "Masukkan Gaji baru: ";
            cin >> data.gaji;
            break;
        }
    }

    if (!found) {
        cout << "Data dengan NIK " << targetId << " tidak ditemukan!" << endl;
        return;
    }

    ofstream outFile(filename, ios::trunc);
    for (const auto &data : dataList) {
        outFile << data.nik << "," << data.nama << "," << data.gaji << endl;
    }
    outFile.close();
    cout << "Data berhasil diperbarui!" << endl;
}

// Fungsi untuk menghapus data (Delete)
void deleteData(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Tidak dapat membuka file!" << endl;
        return;
    }

    vector<Data> dataList;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Data data;
        string nik, gaji;
        getline(ss, nik, ',');
        getline(ss, data.nama, ',');
        getline(ss, gaji, ',');
        data.nik = stoi(nik);
        data.gaji = stoi(gaji);
        dataList.push_back(data);
    }
    file.close();

    int targetId;
    cout << "Masukkan NIK data yang ingin dihapus: ";
    cin >> targetId;

    bool found = false;
    for (auto it = dataList.begin(); it != dataList.end(); ++it) {
        if (it->nik == targetId) {
            found = true;
            dataList.erase(it);
            break;
        }
    }

    if (!found) {
        cout << "Data dengan NIK " << targetId << " tidak ditemukan!" << endl;
        return;
    }

    ofstream outFile(filename, ios::trunc);
    for (const auto &data : dataList) {
        outFile << data.nik << "," << data.nama << "," << data.gaji << endl;
    }
    outFile.close();
    cout << "Data berhasil dihapus!" << endl;
}

// Fungsi untuk mencetak data ke printer
void printDataToPrinter(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Tidak dapat membuka file!" << endl;
        return;
    }

    // Membuat file sementara untuk mencetak
    ofstream tempFile("temp_print.txt");
    string line;

    while (getline(file, line)) {
        tempFile << line << endl; // Salin isi file ke file sementara
    }

    file.close();
    tempFile.close();

    // Menjalankan perintah sistem untuk mencetak file sementara
    int status = system("notepad /p temp_print.txt"); // Menggunakan Notepad untuk mencetak (Windows)
    if (status == 0) {
        cout << "Data berhasil dikirim ke printer!" << endl;
    } else {
        cout << "Error: Gagal mencetak data!" << endl;
    }

    // Menghapus file sementara
    remove("temp_print.txt");
}


// Fungsi utama
int main() {
    string filename = "datapeg.dat";
    int choice;

    do {
        cout << "\nMenu Pengolahan Data Pegawai:" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Lihat Data" << endl;
        cout << "3. Perbarui Data" << endl;
        cout << "4. Hapus Data" << endl;
        cout << "5. Cetak Data ke Printer" << endl; 
        cout << "6. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addData(filename);
                break;
            case 2:
                readData(filename);
                break;
            case 3:
                updateData(filename);
                break;
            case 4:
                deleteData(filename);
                break;
            case 5:
                printDataToPrinter(filename);
                break;
			case 6:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak ada!" << endl;
        }
    } while (choice != 6);

    return 0;
}
