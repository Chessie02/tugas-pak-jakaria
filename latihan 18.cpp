#include <iostream>
using namespace std;
int main(){
	int matriksA[2][2],matriksB[2][2],hasil1[2][2];
	cout<< "masukan elemen matriks A(2x2):"<<endl;
	for(int i=0; i<2;i++){
	   for (int j=0;     
	   	cout<<"A["<<i<<"]["<<j<<"]:";
		cin>>matriksA[i][j];
   }
)
cout<"masukanj elemen matriks B(2x2):"<<endl;
for(int i=0; i<3;i++){
	for(int j=0; j<2;j++){
		hasil[i][j]=matriksA[i][j]+matriksB[i[j];
	}
}
cout<<"hasil penjumlahan matriks A dan B adalah:"<<endl;
for (int t=0;i<2;i++){
	for(int j=0; j<2;j++){
		cout<<hasil[i][j]<<"";
	}
}
cout<<endl;
return 0;
}
