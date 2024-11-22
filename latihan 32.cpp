#include <iostream>
#include<conio.h>
using namespace std;
float hitung(int s);
int main()
{
	float volume,sisi;
	cout<<"\n menghitung volume kubus";
	cout<<"\nsisi kubus:";
	cin>>sisi;
	volume=hitung(sisi);
	cout<<"\n volume kubus yaitu:"<<volume;
	
}
float hitung(int s)
{return(s*s*s);
}
