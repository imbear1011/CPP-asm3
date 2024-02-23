#include <iostream>
#include <string>
#include <sstream> 
#include<cctype>
#include <fstream>
#include "Car.h"
using namespace std;

//khai bao ham
void copyArray(int source[], int destination[]);
int sizeBinaryFile(const string& filename); 

int main() {
	Car car;
	//Mo file ASM04.dat
	fstream file("ASM04.dat", ios::binary | ios::app);
	file.close();

	//Kiem tra neu file AMS04.dat chua luu MSCN thi cai dat mscn
	if (sizeBinaryFile("ASM04.dat") == 0) {
		cout << "Ma so ca nhan chua duoc cai dat." << endl;
		car.setMscn();//Cai dat mscn
		car.writeMscn("ASM04.dat");//Ghi MSCN vao file nhi phan
		system("cls");
	}
	else {
		car.readMscn("ASM04.dat");//Doc MSCN tu file nhi phan
	}

	if (car.DangNhap()) {
		string str;
		do {
			cout << "XIN CHAO ";
			for (int i = 0; i < 8; i++) {
				cout << car.mscn[i];
			}
			cout << endl;
			cout << "Ban muon dat lai ma so ca nhan khong? (chon y hoac n)" << endl;
			cin >> str;
			if (str == "y" || str == "Y") {
				car.setMscn();//Cai dat lai mscn
				car.writeMscn("ASM04.dat");//Ghi MSCN vao file nhi phan
			}
			else if (str == "n" || str == "N") {
				break;
			}
			else
			{
				cout << "Ky tu nhap vao khong hop le. Hay nhap lai!" << endl;
			}
			system("pause");
			system("cls");
		} while (str != "n" && str != "N");

		do {
			//Kiem tra neu file AMS04.dat chua luu Safe_distance thi tien hanh cai dat
			if (sizeBinaryFile("ASM04.dat") <= sizeof(int)*8) {
				cout << "Chua cai dat day van toc an toan." << endl;
				car.setCacMucVanToc();//Cai dat Safe_distance
				car.writeSafe_distance("ASM04.dat");//Ghi Safe_distance vao file nhi phan
			}
			else
			{
				car.readSafe_distance("ASM04.dat");//Doc Safe_distance tu file nhi phan
				cout << "VAN TOC CANH BAO KHOANG CACH AN TOAN VOI 3 MUC VAN TOC DA DUOC CAI DAT LA:" << endl;
				for (int i = 0; i < 3; i++) {
					cout << "VAN TOC MUC " << i + 1 << ": " << car.safe_distance[i] << endl;
				}
			}
			cout << "Ban muon dat lai van toc canh bao khoang cach an toan khong? (chon y hoac n)" << endl;
			cin >> str;
			if (str == "y" || str == "Y") {
				car.setCacMucVanToc();//Cai dat lai Safe_distance
				car.writeSafe_distance("ASM04.dat");//Ghi Safe_distance vao file nhi phan
			}
			else if (str == "n" || str == "N") {
				break;
			}
			else
			{
				cout << "Ky tu nhap vao khong hop le. Hay nhap lai!" << endl;
			}
			system("pause");
			system("cls");
		} while (str != "n" && str != "N");

		car.xulyCheDoLai();
	}
	
	//So sanh thuat toan
	int mangNhap[8];
	cout << "Nhap mang so sanh thuat toan:" << endl;
	car.nhapMang(mangNhap);//nhap mang 8 phan tu

	int mang1[8];
	int mang2[8];
	copyArray(mangNhap, mang1);
	copyArray(mangNhap, mang2);

	int biendem1 = car.bubbleSort(mang1, 8);
	int biendem2 = car.selectionSort(mang2, 8);

	cout << "---> MANG NHAP VAO SAU KHI SAP XEP: ";
	for (int i = 0; i < 8; i++) {
		cout << mang1[i] << " ";
	}
	cout << endl;

	cout << "Thuat toan bubbleSort co " << biendem1 << " buoc thuc hien" << endl;
	cout << "Thuat toan selectionSort co " << biendem2 << " buoc thuc hien" << endl;
	if (biendem1 < biendem2) {
		cout << "Thuat toan selectionSort phuc tap hon thuat toan bubbleSort" << endl;
	}
	else
	{
		cout << "Thuat toan bubbleSort phuc tap hon thuat toan selectionSort" << endl;
	}
	return 0;
}

void copyArray(int source[], int destination[]) {
	for (int i = 0; i < sizeof(source); i++) {
		destination[i] = source[i];
	}
}

int sizeBinaryFile(const string& filename) {
	ifstream file(filename, ios::binary | ios::ate);
	if (file.is_open()) {
		// Lấy kích thước tệp
		streampos fileSize = file.tellg();
		file.close();
		return fileSize;
	}
	else {
		cout << "Khong the mo file." << std::endl;
		return false;
	}
}
