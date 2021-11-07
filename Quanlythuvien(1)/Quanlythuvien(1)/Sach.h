#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"DoHoa.h"
#include <conio.h>
using namespace std;

struct datetime {
	int ngay;
	int thang;
	int nam;
};
typedef struct datetime DATETIME;

struct sach {
	int ma;
	string ten;
	string nxb;
	int gia;
	int nam;
	int page;
	DATETIME ngay;
	int status;
};
typedef struct sach SACH;

//khai báo cấu trúc 1 nnode sách
struct node {
	SACH data;
	struct node* next;
};
typedef struct node NODE;

struct list {
	NODE* head;
	NODE* tail;
};
typedef struct list LIST;
//Hàm khởi tạo danh sách liên kết đơn các sách
void InitList(LIST& l);
//hàm khởi tạo node
NODE* getNode(SACH s);
void AddHead(LIST& l, NODE* p);
void AddTail(LIST& l, NODE* p);
void doc_file_datetime(ifstream& filein, DATETIME& a);
void doc_1_quyen_sach(ifstream& filein, SACH& s);
void xuat(SACH s);
void xuat_tat_ca_sach(list l);
void doc_all_sach(ifstream& filein, LIST& l, NODE* p);
void nhap_thong_tin_sach(LIST& l,NODE* p, NODE* q,ifstream& filein);
bool kiem_tra(NODE* p, LIST& l,SACH& s);
void giai_phong(LIST& l);
void quanly_sach();
void xoa(LIST& l,int& n);
void ghi_sau_xoa(NODE* p, ofstream &fileout,LIST& l);
void sap_xep(NODE* p, LIST& l);
void Hoan_vi_2sach(LIST& l, NODE* p, NODE* q);
void ghi_11_quyen_sach(ofstream& fileout, SACH& s);
void xuatmenu();
bool kiem_tra_masach(LIST& l, NODE* p, int& n);
void cap_nhat_tinh_trang_sach_muon(LIST& l, NODE* p, int& n);
void cap_nhat_tinh_trang_sach_tra(LIST& l, NODE* p, int& n);
bool kiem_tra_sach_xoa(LIST& l, NODE* p, int& n);
bool kiem_tra_sach_xoa_tinh_trang(LIST& l, NODE* p, int& n);