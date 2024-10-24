#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int minpenjualan = 500000;
	int komisi = 0, penjualan = 0;
	
	cout<<"Total penjualan sales : ";
	cin>> penjualan;
	if(penjualan >= minpenjualan){
		komisi = (int)(minpenjualan * 10/100);
		cout <<"-komisi 10% :"<<komisi<<endl;
    }
	else {
		 cout <<"-tidak mendapatkan komisi 					karena penjualan kurang dari " << 						minpenjualan <<endl;
    }
    if(penjualan > minpenjualan) {
    	int komisibonus = (int)((penjualan-					minpenjualan)* 10/100);	 
    	komisi += komisibonus;
    	cout <<"-komisi bonus 15% : "<<komisi << 		endl;
    }
    cout <<"-total komisi : " <<komisi;
		 
	return 0;
}