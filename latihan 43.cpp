#include <windows.h>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// ID untuk menu
#define ID_FILE_EXIT 1
#define ID_RECORD_CREATE 2
#define ID_RECORD_READ 3
#define ID_RECORD_UPDATE 4
#define ID_RECORD_DELETE 5

// struktur untuk menyimpan data
struct Record{
	int id;
	std::string name;
};
//Data
std::vector<Record> records;
int nextId =1;

//fungsi untuk menampilkan data
std::string displayRecords(){
	std::ostringstream oss;
	if(records.empty()){
		oss<< "No records available.";
	}else{
		oss << "ID\tname\n";
		for (const auto& record :records){
			oss <<record.id <<"\t"<< record.name<<"\n";
		}
	}
	return oss.str();
}

//fungsi utama untuk membuat window
LRESULT CALLBACK Windowproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	switch (uMsg){
		case WM_CREATE:{
			HMENU hMenu = CreateMenu();
			
			HMENU hFileMenu = CreateMenu();
			AppendMenu(hFileMenu, MF_STRING, ID_FILE_EXIT, "Exit");
			
			HMENU hRecordMenu =CreateMenu();
			AppendMenu(hRecordMenu, MF_STRING, ID_RECORD_CREATE, "Create");
			AppendMenu(hRecordMenu, MF_STRING, ID_RECORD_READ, "Read");
			AppendMenu(hRecordMenu, MF_STRING, ID_RECORD_UPDATE, "Update");
			AppendMenu(hRecordMenu, MF_STRING, ID_RECORD_DELETE,"Delete");
			
			AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "File");
			AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hRecordMenu, "Record");
			
			SetMenu(hWnd, hMenu);
		}
		break ;
		case WM_COMMAND: {
			switch (LOWORD(wParam)){
				case ID_FILE_EXIT:
					PostQuitMessage(0);
					break;
					
				
				case ID_RECORD_CREATE: {
					char buffer[100]= "Enter Name:";
					MessageBox(hWnd, "Creating Record. Enter Name id Dialog Box.","Create Record",MB_OK);
					records.push_back({nextId++, buffer});
					MessageBox(hWnd, "Record Created Succesfully!", "Success",MB_OK);
					
				}
				break;
				
				case ID_RECORD_READ:{
					std::string data= displayRecords();
					MessageBox(hWnd, data.c_str(),"ALL Records", MB_OK);
					
				}
				break;
				
				case ID_RECORD_UPDATE:{
					MessageBox(hWnd,"Update Not Yet Implemented!","Update",MB_OK);
					
				}
				break;
				
				case ID_RECORD_DELETE:{
					MessageBox(hWnd,"Delete Not Yet Implemented!", "Delete",MB_OK);
					}
					break;
				}
				
			}
					
					case WM_DESTROY:
						PostQuitMessage(0);
						break;
						
					default:
						return DefWindowProc(hWnd, uMsg, wParam, lParam);
						
				}
				return 0;
			}
			int WINAPI WinMain(HINSTANCE Hinstance,HINSTANCE hPrevInstance, LPSTR lpCmdLine,int nCmdShow){
				const char CLASS_NAME[]="CRUDAppClass";
				
				WNDCLASS wc= {};
				wc.lpfnWndProc = Windowproc;
				wc.hInstance = Hinstance;
				wc.lpszClassName = CLASS_NAME;
				
				if (!RegisterClass(&wc)){
					return 0;
				}
				
				HWND hwnd = CreateWindowEx(
				0,
				CLASS_NAME,
				"Aplikasi Penjualan Barang di Swalayan",
				WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, CW_USEDEFAULT,600,600,
				NULL,NULL, Hinstance, NULL
				);
				
				if (hwnd==NULL){
					return 0;
				}
				
				ShowWindow(hwnd, nCmdShow);
				
				MSG msg = {};
				while (GetMessage(&msg,NULL,0,0)){
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				return 0;	
		}