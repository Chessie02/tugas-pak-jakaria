#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>

using namespace std;

void buatfile();
void tulisfile();
void tambahfile();
void bacafile();

int main() 
{
	int pilihan;
	
	do
	{
		cout<< "\n===[ Menu Pemberkasan ]===\n";
		cout<< "1. Buat Berkas Baru\n";
		cout<< "2. Tulis Isi Berkas\n";
		cout<< "3. Tambahkan Tulisan Ke Berkas\n";
		cout<< "4. Tampilkan isi Berkas\n";
		cout<< "5. Keluar\n";
		cout<< "Pilihan Menu (1-5): ";
		cin >> pilihan;
		
		switch (pilihan)
		{
			case 1:
				buatfile();
				break;
			case 2:
				tulisfile();
				break;
			case 3:
				tambahfile();
				break;
			case 4:
				bacafile();
				break;
			default:
				cout<<"Keluar dari program\n";
				break;
		}
	}
	while(pilihan !=5);
	
	return 0;
}
void buatfile()
{
	string berkas;
	cout <<"Masukkan nama file baru: ";
	cin >> berkas;
	
	ofstream gas(berkas.c_str());
	if(gas.is_open())
	{
		gas.close();
		cout <<"File \""<<berkas<<"\"berhasil di buat\n";
		
	}
	else cout <<"File\""<<berkas<<"\"tidak berahsil dinuat\n";
}
void tulisfile()
{
	string berkas, teks;
	cout <<"Masukkan nama file: ";
	cin >> berkas;
	
	ofstream gas(berkas.c_str(),ios::out);//menimmpa isi file
	if(gas.is_open())
	{
		cin.ignore();
		cout<< "Masukkan tulisan yang ingin di input ke dalam file \n";
		getline(cin,teks);
		gas<<teks<<endl;
		gas.close();
		cout<< "Tulisan berhasil di imput kedalam berkas\""<<berkas<<"\"\n";
	}
	else cout << "Tulisan pada berkas\""<<berkas<<"\"tidak berhasil ditambahkan\n";
}
void tambahfile()
{
	string berkas,teks;
	cout <<"Masukkan nama file untuk ditambahkan: ";
	cin >>berkas;
	
	ofstream gas(berkas.c_str(),ios::in);//
	if(gas.is_open())
	{
		cin.ignore();
		cout <<"Masukkan tulisan yang ingin di input ke file\n";
		getline(cin,teks);
		gas<<teks<<endl;
		gas.close();
		cout<<"Tuliskan beerhasil diinput kendalam berkas\""<<berkas<<"\"\n";
	}
	else cout <<"Tuliskan pada Berkas\""<<berkas<<"\"tidak berhasil di tambahkan \n";
}
void bacafile()
{
	string berkas,baris;
	cout <<"Masukkan nama file untuk ditampilkan: ";
	cin >>berkas;
	
	ifstream gas(berkas.c_str());
	if(gas.is_open())
	{
		cout <<"isi berkas\""<<berkas<<"\"berhasil dibuat\n";
		while(getline(gas,baris) )cout <<baris<<endl;
		gas.close();
	}
	else cout <<"berkas\""<<berkas<<"\"tidak berhasil dibuat\n";
}
