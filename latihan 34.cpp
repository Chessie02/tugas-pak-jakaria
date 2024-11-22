#include <iostream>
#include<conio.h>
using namespace std;

float gaji_pk(char gol),pajak(float gaji);
float tunjangan(float gaji,char status,int anak);
void garis();
int main()
{
	int anak;
	char golong,stat;
	float gaji,gajipokok,tnj,pjk;
	while(1)
{
/*cetak judul program*/
cout<<"\n\n program untuk menhitung gaji karyawan";
cout<<"\n\n untuk menghentikan program ketik x pada golongan\n";

garis();
/*input data*/
cout <<"\n golongan karyawan(A-C & x untuk selesai):";
golong =getche();
if(golong =='X'||golong=='x')
break;
cout<<"\n status karyawan(n=nikah & b=belum):";
stat=getche();
if(stat=='N'||stat=='n')
{
cout<<"\n\t jumlah anak:";
cin>>anak;
}else
cout<<"\n\t";
/*menghitung gaji bersih*/
gajipokok=gaji_pk(golong);
tnj=tunjangan(gajipokok,stat,anak);
pjk=pajak(gajipokok);
gaji=gajipokok+tnj-pjk;

/*cetak output*/
cout<<"\n\n";
cout<<"\ngaji pokok=rp. "<<gajipokok+tnj;
cout<<"\ntunjangan =rp. "<<tnj;
cout<<"\n------------------------------------------+";
cout<<"\ntotal=rp. "<<gajipokok+tnj;
cout<<"\npajak=rp. "<<pjk;
cout<<"\n------------------------------------------+";
cout<<"\ngajibersih=rp. "<<gaji;
cout<<"\n------------------------------------------+";
cout<<"\n\n tekan sembarang tombol";
getch() ;
}
}
void garis()/*menggambar garis*/
{
cout<<"\n";
for(int i=1;i<=50;++i)
cout<<"\xB1";
}
/*menghitung gaji pokok*/
float gaji_pk(char gol)
{
	switch(gol)
	
{ 
 case'A':
 case'a':
 return(50000.00);
 case'B':
 case'b':
 return(100000.00);
 case'C':
 case'c':
 return(150000.00);
 defaul:
return(0.00);
}
}
/*menghitung tunjangan*/
float tunjangan(float gaji,char status,int anak)
{
	float ta,ti;
	if(status=='B'||status =='b')
{
	ta=0;
	ti=0;
}
else if(status=='N'||status=='n')	
{
ta=0.15*gaji;
ti=anak>3?3*.1*gaji :anak*.1*gaji;
}
return(ta+ti);
}	
/*menghitung pajak*/
float pajak(float gaji)
	
{
	float pjk;
	pjk=gaji<= 96000?0:.15*(gaji-96000);
	return(pjk);
	
}
