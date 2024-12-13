#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <windows.h>
//ID untuk menu
#define ID_FILE_EXIT 1	//angka = no urut define = definisi secara constanta
#define ID_RECORD_CREATE 2	
#define ID_RECORD_READ 3
#define ID_RECORD_UPDATE 4
#define ID_RECORD_DELETE 5

//struct untuk menyimpan data
struct Record{
	int id;
	std::string name;
};

//Data
std::vector<Record> records;
int nextId = 1;

//fungsi untuk menampilkan data
std::string displayRecords(){
	std::ostringstream oss;
	if(records.empty()){
		oss << "No record available";
	} else {
		oss << "ID\tName\n";
		for (const auto& record : records){
			oss << record.id << "\t" << record.name << "\n";
		}
	}
return oss.str();
}

//Fungsi utama untuk membuat window
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

switch(uMsg){
	case WM_CREATE: {
		HMENU hMenu = CreateMenu();
		
		HMENU hFileMenu = CreateMenu();
		AppendMenu(hFileMenu,MF_STRING, ID_FILE_EXIT, "Exit");
		
		HMENU hRecordMenu = CreateMenu();
		AppendMenu(hRecordMenu, MF_STRING, ID_RECORD_CREATE, "Create");
		AppendMenu(hRecordMenu, MF_STRING, ID_RECORD_READ, "Read");
		AppendMenu(hRecordMenu, MF_STRING, ID_RECORD_UPDATE, "Update");
		AppendMenu(hRecordMenu, MF_STRING, ID_RECORD_DELETE, "Delete");
		
		AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "File");
		AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hRecordMenu, "Record");
		
		SetMenu(hwnd, hMenu);
	}
	break;
	
	case WM_COMMAND:{
		switch(LOWORD(wParam)){
			case ID_FILE_EXIT:
				PostQuitMessage(0);
				break;
		
			case ID_RECORD_CREATE: {
				char buffer[100] = "Enter Name: ";
				MessageBox(hwnd, "Creating Record. Enter Name In Dialog Box", "Create Record", MB_OK);
				records.push_back({nextId++, buffer});
				MessageBox(hwnd, "Creating Successfully!", "Success", MB_OK);
			}
				break;
			case ID_RECORD_READ:{
				std::string data = displayRecords();
				MessageBox(hwnd, data.c_str(), "All Records", MB_OK);
				}
				break;
			case ID_RECORD_UPDATE:{
				MessageBox(hwnd, "Update Not Yet Implemented", "Update", MB_OK);
			}
			break;
			case ID_RECORD_DELETE: {
				MessageBox(hwnd, "Delete Not Yet Implemented", "Delete", MB_OK);
			}
			break;
		}
		break;
			
			case WM_DESTROY:
				PostQuitMessage(0);
				break;
			
			default :
				return DefWindowProc(hwnd, uMsg, wParam, lParam);
				
	}
	
}
return 0;
}

int WINAPI WinMain(HINSTANCE hIntance, HINSTANCE hPrevIntance, LPSTR lpCmdLine, int nCmdShow){

const char CLASS_NAME[] = "CRUDAppClass";

WNDCLASS wc = {};
wc.lpfnWndProc = WindowProc;
wc.hInstance = hIntance;
wc.lpszClassName = CLASS_NAME;

if (!RegisterClass(&wc)) {
	return 0;
}

HWND hwnd = CreateWindowEx(
0,
CLASS_NAME,
"Aplikasi Penjualan Barang Di Swalayan",
WS_OVERLAPPEDWINDOW,
CW_USEDEFAULT, CW_USEDEFAULT, 600, 600,
NULL, NULL, hIntance, NULL
);

if(hwnd == NULL){
	return 0;
}

ShowWindow(hwnd, nCmdShow);

MSG msg = {};
while(GetMessage(&msg, NULL, 0, 0)){
	TranslateMessage(&msg);
	DispatchMessage(&msg);
}
return 0;
}
