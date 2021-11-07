#include"DoHoa.h"
#include"xylyacc.h"
#include"Sach.h"
#include"Phieumuon.h"
#include<iomanip>

int main()
{
	resizeConsole(1000, 600);
	char a[100], p[100];
	int i = 0;
	bool menuchinh = true;
	Admin ad;
	int choose;
	char s[10]="";
	mo_file(ad);
	while (i < 3) {
		Dang_Nhap(a, p);
		if (Dang_Nhap_Thanh_Cong(a, p, ad)) {
			while (menuchinh == true) {
				system("cls");
				textcolor(242);
				cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl;
				cout << "* Lua chon chuc nang:                                                                                                                *" << endl;
				cout << "* 1.Quan ly phieu muon                                                                                                               *" << endl;
				cout << "* 2.Quan ly sach                                                                                                                     *" << endl;
				cout << "* 0.De thoat                                                                                                                         *" << endl;
				cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * **" << endl;
				textcolor(7);
				cout << "\n\n\n\n";
				cout << "Nhap vao lua chon: ";
				cin >> choose;
				switch (choose) {
				case 1:
					system("cls");
					quanly_sach();
					break;
				case 2:
					system("cls");
					quanly_phieumuon();
					break;
				case 0:
					menuchinh = false;
					break;
				default:
					textcolor(12);
					cout << "Vui long nhap lai";
					textcolor(7);
					cout << endl;
					system("pause");
				}
			}
			return 0;
		}
		else
		{
			system("cls");
			gotoxy(45, 11);
			textcolor(11);
			cout << "\t\tTai khoan hoac mat khau sai";
			textcolor(7);
			if (i == 2) {
				return 0;
			}
			i++;
		}
	}
	system("pause");
	return 0;
}