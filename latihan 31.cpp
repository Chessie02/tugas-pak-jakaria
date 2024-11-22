#include <iostream>
#include<conio.h>
using namespace std;
void hitung();//mendeklarisan fungsi yg tidak menghasilkan nilai
int main()
{
	cout<<"\n menghitung volume kubus";
	hitung();//memanggil fungsi hitung;
	return 0;
}
	void hitung()
	{float sisi,volume;
	cout<<"\n sisi kubus:";
	cin>>sisi;
	volume = sisi *sisi *sisi ;
	cout<<"\n volume kubus yaitu:"<<volume;
}
	
