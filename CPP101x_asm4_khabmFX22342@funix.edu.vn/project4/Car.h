#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
class Car {
public:
	//thuoc tinh
	int mscn[8];
	int mangNguoiDungNhap[8];
	int safe_distance[3];
	int vantoc = 0;
	static const size_t RECORD_SIZE = sizeof(int) * 8;
	//phuong thuc
	bool kiemTraSoNguyen(string str);
	bool DangNhap();
	int bubbleSort(int a[], int n);
	int selectionSort(int a[], int n);
	void nhapMang(int arr[]);
	void nhapMangVanToc(int arr[]);
	int selectMenu1();
	int selectMenu2();
	void xulyTocDo(int s);
	void xulyCheDoLai();
	void writeMscn(string filename);
	void readMscn(string filename);
	void writeSafe_distance(string filename);
	void readSafe_distance(string filename);
	void setMscn();
	void setCacMucVanToc();
};

