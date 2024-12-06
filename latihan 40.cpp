#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

void gotoxy (int x, int y){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {static_cast<short>(x), static_cast<short>(y)};
	SetConsoleCursorPosition(hConsole, position);
}

struct data{ew
	char nik[15];
	char nama [30];
	float gaji ;
}pgw[50] ;

void menu();
void isi();
void tambah();
void baca();

int main()
{
	char pil='0';
	while (pil != '4')
	{
		menu();
		pil = getche();
		switch(pil)
		{case '1':
			isi();break;
			case '2':
				tambah();break;
				case'3':
					baca();break;
					case'4':
						break ;
		}
	}
}
void menu()
{
	system("cls");
	gotoxy (25,5);cout <<"Menu Data Karyawan";
	gotoxy (25,6);cout <<"----------------------------------------------";
	gotoxy (25,7);cout <<"[1] Mengisi / Membuat File Baru";
	gotoxy (25,8);cout <<"[2] Menambah Data";
	gotoxy (25,9);cout <<"[3] Membaca Data";
	gotoxy (25,10);cout <<"[4] Selesai";
	gotoxy (25,11);cout <<"---------------------------------------------";
	gotoxy (25,12);cout <<"PILIHAN : ";
}
void isi()
{
	FILE *coba;
	char gj[10];
	float atof();
	int i, n=0;
	while(1)
	{
		system("cls");
		gotoxy (35,5);cout <<"Memasukkan Data Pegawai";
		gotoxy (35,6);cout <<"------------------------------------------";
		gotoxy (35,7);cout <<"NIK : ";
		gets(pgw[n].nik);
		if (strlen(pgw[n].nik)==0)
		break;
		gotoxy (35,8);cout <<"Nama : ";
		gets(pgw[n].nama);
		gotoxy (35,9);cout <<"Gaji : ";
		cin >> pgw[n].gaji;
		gotoxy (35,6);cout <<"-------------------------------------------";
		n++;		
	}
	coba =fopen("c:\Pegawai.Dat","wb");
	for (i=0 ; i<n ;++i)
	{fwrite(&pgw[i], sizeof(pgw [i]),1,coba);
	}
	fclose(coba);
}
void tambah()
{
	FILE *coba;
	char gj[10];
	float atof();
	int i, n =0;
	while(1)
	{
		system("cls");
		gotoxy (35,5);cout <<"Menambah Data Pegawai";
		gotoxy (35,6);cout <<"------------------------------------------";
		gotoxy (35,7);cout <<"NIK : ";
		gets(pgw[n].nik);
		if (strlen(pgw[n].nik)==0)
		break;
		gotoxy (35,8);cout <<"Nama : ";
		gets(pgw[n].nama);
		gotoxy (35,9);cout <<"Gaji : ";
		cin >> pgw[n].gaji ;
		gotoxy (35,10);cout <<"----------------------------------";
		n++ ;
	}
	coba= fopen("c:\Pegawai.Dat", "ab");
	for (i=0 ;i<n ; ++i)
	{
		fwrite(&pgw[i], sizeof(pgw[i]),1,coba);
	}
	fclose(coba);
}
void baca()
{
	FILE *coba;
	int i=0, n= 0;
	system("cls");
	coba = fopen("C:\Pegawai.Dat", "rb");
	if (coba==NULL)
	{
		gotoxy (20,10);cout <<"FILE PEGAWAI.Dat belum ada";
		gotoxy (20,12);cout <<"Tekan Sembarang Tombol";
		getch();
		return;
	}
	gotoxy (5,1);cout <<"LAPORAN DATA PEGAWAI STMIK PELITA NUSANTARA";
	gotoxy (5,2);cout <<"-------------------------------------------------------";
	gotoxy (5,3);cout <<" NO   NIK           NAMA                    GAJI";
	gotoxy (5,4);cout <<"-------------------------------------------------------";
	while( (fread( &pgw[n], sizeof(pgw[n]),1, coba))==1)
	{
		i++;
		gotoxy(6,4+i);cout <<i;
		gotoxy(10,4+i);cout <<pgw[n].nik;
		gotoxy(19,4+i);cout <<pgw[n].nama;
		gotoxy(50,4+i);cout <<pgw[n].gaji;
	}
	gotoxy(5,5+i);cout<<"-------------------------------------------------------";
	getch();
	fclose(coba);
}
