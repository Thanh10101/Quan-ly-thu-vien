#include<iostream>
#include<fstream>//thư viện dùng file
#include <stdio.h>
#include <string.h>
#include"DoHoa.h"
#include<stdio.h>
#include<conio.h>
using namespace std;
struct admin
{
	char acc[100];
	char pass[100];
};
typedef struct admin Admin;
void doc_file(fstream& filein, Admin& ad);
void xuat(Admin ad);
void mo_file(Admin& ad);
void Dang_Nhap(char a[], char p[]);
bool Dang_Nhap_Thanh_Cong(char a[], char p[], Admin& ad);
