#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

struct data_mahasiswa
{
	char npm[9] ;
	char nama[20] ;
	int nilai ;
};
int main()
{
	data_mahasiswa data_mhs;
	cout<<"input data mahasiswa\n";
	cout<<"---------------------\n";
	cout<<"npm :";
	cin>>data_mhs.npm;
	cout<<"nama:";
	cin>>data_mhs.nama;
	cout<<"nilai :";
    cin>>data_mhs.nilai;
    cout<<"--------------------------\n";
    cout<<"data yang telah anda input\n";
    cout<<"--------------------------\n";
    cout<<"npm:"<<data_mhs.npm<<endl;
    cout<<"nama:"<<data_mhs.nama<<endl;
    cout<<"nilai:"<<data_mhs.nilai<<endl;
    cout<<"--------------------------\n";
    return 0;
}
