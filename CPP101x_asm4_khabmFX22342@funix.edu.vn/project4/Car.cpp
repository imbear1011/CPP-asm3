#include "Car.h"

bool Car::kiemTraSoNguyen(string str)
{
	for (int i = 0; i < str.length(); i++) {
		if (!isdigit(str.at(i))) {
			return false;
		}
	};
	return true;
}

bool Car::DangNhap()
{
	cout << "TIEN HANH DANG NHAP" << endl;
	cout << "NHAP MA SO CA NHAN, MANG 08 SO: " << endl;
	nhapMang(mangNguoiDungNhap);
	system("cls");
	cout << "MANG NHAP VAO TRUOC KHI SAP XEP: ";
	//in mang truoc khi sap xep
	for (int i = 0; i < 8; i++) {
		cout << mangNguoiDungNhap[i] << " ";
	}
	cout << endl;
	bubbleSort(mangNguoiDungNhap, 8);//sap xep mang
	cout << "---> MANG NHAP VAO SAU KHI SAP XEP: ";
	//in mang sau khi sap xep
	for (int i = 0; i < 8; i++) {
		cout << mangNguoiDungNhap[i] << " ";
	}
	cout << endl;
	////////////////////
	cout << "MA SO CA NHAN TRUOC KHI SAP XEP: ";
	//in ma so ca nhan truoc khi sap xep
	for (int i = 0; i < 8; i++) {
		cout << mscn[i] << " ";
	}
	cout << endl;
	selectionSort(mscn, 8);//sap xep ma so ca nhan
	cout << "---> MA SO CA NHAN SAU KHI SAP XEP: ";
	//in ma so ca nhan sau khi sap xep
	for (int i = 0; i < 8; i++) {
		cout << mscn[i] << " ";
	}
	cout << endl;
	//kiem tra ma so ca nhan
	for (int i = 0; i < 8; i++) {
		if (mscn[i] != mangNguoiDungNhap[i]) {
			cout << "Ma so sai, chao tam biet " << endl;
			return false;
		}
	}
	system("pause");
	system("cls");
	cout << "Dang nhap thanh cong!" << endl;
	return true;
}

int Car::bubbleSort(int a[], int n)
{
	int biendem = 0;//bien dem so buoc thuc hien
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (*(a + j) < *(a + (j - 1))) {
				biendem++;
				int tg = *(a + j);
				*(a + j) = *(a + (j - 1));
				*(a + (j - 1)) = tg;
			}
		}
	}
	return biendem;
}

int Car::selectionSort(int a[], int n)
{
	int biendem = 0;//biem dem so buoc thuc hien
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (*(a + j) < *(a + min)) {
				biendem++;
				min = j;
			}
		}
		int tg = *(a + min);
		*(a + min) = *(a + i);
		*(a + i) = tg;

	}
	return biendem;
}

void Car::nhapMang(int arr[])
{
	//n la so phan tu cua mang
	string phantu;
	for (int i = 0; i < 8; i++) {
		do {
			cout << "SO THU " << i + 1 << ": ";
			cin >> phantu;
			//kiem tra neu phan tu nhap vao la 1 so nguyen thi them phan tu vao mang
			if (kiemTraSoNguyen(phantu)) {
				arr[i] = stoi(phantu);
			}
			else {
				cout << "Nhap sai, moi nhap lai!!!" << endl;
			}
		} while (!kiemTraSoNguyen(phantu));

	}
}

void Car::nhapMangVanToc(int arr[]) {
	cout << "CAI DAT VAN TOC CANH BAO KHOANG CACH AN TOAN VOI 3 MUC VAN TOC" << endl;
	string phantu;
	for (int i = 0; i < 3; i++) {
		do {
			cout << "VAN TOC MUC " << i + 1 << ": ";
			cin >> phantu;
			if (kiemTraSoNguyen(phantu)) {
				arr[i] = stoi(phantu);
			}
			else {
				cout << "Nhap sai, moi nhap lai!!!" << endl;
			}
		} while (!kiemTraSoNguyen(phantu));

	}
}

void Car::writeMscn(string filename)
{
	fstream file(filename, ios::binary | ios::out | ios::in);
	file.write((char*)&mscn, sizeof(int) * 8);
	file.close();
	//os.write((char*)&safe_distance, sizeof(int) * 3);
}

void Car::readMscn(string filename)
{
	fstream file(filename, ios::binary | ios::out | ios::in);
	file.read((char*)&mscn, sizeof(int) * 8);
	file.close();
	//is.read((char*)&safe_distance, sizeof(int) * 3);
}

void Car::writeSafe_distance(string filename)
{
	fstream file(filename, ios::binary | ios::out | ios::in);
	file.seekp(RECORD_SIZE);
	file.write((char*)&safe_distance, sizeof(int) * 3);
	file.close();
}

void Car::readSafe_distance(string filename)
{
	fstream file(filename, ios::binary | ios::out | ios::in);
	file.seekg(RECORD_SIZE);
	file.read((char*)&safe_distance, sizeof(int) * 3);
	file.close();
}

void Car::setMscn()
{
	cout << "Cai dat ma so ca nhan:" << endl;
	nhapMang(mscn);
	cout << "Cai dat thanh cong" << endl;

}

void Car::setCacMucVanToc()
{
	nhapMangVanToc(mangNguoiDungNhap);//Nguoi dung nhap cac muc van toc
	selectionSort(mangNguoiDungNhap, 3);//Sap cac muc van toc nhap vao theo thu tu tang dan
	//kiem tra cac muc van toc nguoi dung cai dat lai neu khac vs cac muc van toc cu thi luu lai
	for (int i = 0; i < 3; i++) {
		if (safe_distance[i] != mangNguoiDungNhap[i]) {
			safe_distance[i] = mangNguoiDungNhap[i];
		}
	}
	cout << "Cai dat thanh cong" << endl;
}

int Car::selectMenu1()
{
	string selection;
	int luaChonHopLe = 0;
	do
	{
		cout << "XIN MOI LUA CHON:" << endl;
		cout << "1. P" << endl;
		cout << "2. R" << endl;
		cout << "3. N" << endl;
		cout << "4. D" << endl;
		cout << "5. POWER OFF" << endl;
		cout << ">> ";

		cin >> selection;

		system("cls");
		//kiểm tra lựa chọn hợp lệ 
		if (kiemTraSoNguyen(selection)) {
			luaChonHopLe = stoi(selection);//chuyen kieu string sang int roi gan cho bien luaChonHopLe
			if (luaChonHopLe < 1 || luaChonHopLe > 5) {
				cout << "Nhap sai! Moi nhap lai tu 1 den 5" << endl;
			}
		}
		else {
			cout << "Nhap sai! Moi nhap lai" << endl;
		}
	} while (luaChonHopLe < 1 || luaChonHopLe > 5 || !kiemTraSoNguyen(selection));
	return luaChonHopLe;
}

int Car::selectMenu2()
{
	string selection;
	int luaChonHopLe = 0;

	cout << "MOI LUA CHON:" << endl;
	cout << "1. TANG TOC" << endl;
	cout << "2. GIAM TOC" << endl;
	cout << "3. PHANH" << endl;
	cout << "4. TRO VE MENU" << endl;
	cout << ">> ";
	cin >> selection;
	system("cls");
	//kiểm tra lựa chọn hợp lệ 
	if (kiemTraSoNguyen(selection)) {
		luaChonHopLe = stoi(selection);//chuyen kieu string sang int roi gan cho bien luaChonHopLe
		if (luaChonHopLe < 1 || luaChonHopLe > 4) {
			cout << "Nhap sai! Moi nhap lai tu 1 den 4" << endl;
		}
	}
	else {
		cout << "Nhap sai! Moi nhap lai" << endl;
	}
	//xử lý tốc độ theo lựa chọn
	xulyTocDo(luaChonHopLe);
	return luaChonHopLe;
}

void Car::xulyTocDo(int select)
{
	switch (select) {
	case 1:
		vantoc += 5;
		break;
	case 2:
		vantoc -= 5;
		if (vantoc < 0)
			vantoc = 0;
		else
			vantoc = vantoc;
		break;
	case 3:
		vantoc = 0;
		break;
	case 4:
		break;
	default:
		selectMenu2();
		break;
	}
}

void Car::xulyCheDoLai()
{
	int taySo = 0;
	int taySoDaChon = 0;
	int luaChonChanGa = 0;
	do {
		taySo = selectMenu1(); //lua chon tay so
		switch (taySo)
		{
		case 1:
		case 3:
			//v = 0 thì có thể chuyển số tùy ý
			if (vantoc == 0) {
				//Thực hiện chuyển số N/P
				if (taySo == 1) {
					cout << "DA VE SO P." << endl;
				}
				else {
					cout << "DA VE SO N." << endl;
				}
				cout << "CHU Y SU DUNG PHANH TAY DE DAM BAO AN TOAN." << endl;
				taySoDaChon = taySo;//luu tay so da chon de kiem tra dieu kien truoc khi chuyen so
			}
			//v != 0 thì không thể chuyển số
			else {
				cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC LA 0 KM/H" << endl;
			}

			break;
		case 2:
		case 4:
			//v = 0 thì có thể chuyển số tùy ý
			if (vantoc == 0) {
				vantoc = 7;
			}
			else {
				//khong chuyen so
				if (taySoDaChon == taySo) {
					vantoc = vantoc;
				}
				else {//v != 0 thì phải phanh rồi mới được chuyển số
					cout << "Khong the chuyen so. Hay phanh truoc khi chuyen so." << endl;

					//break;
					continue;

				}
			}
			//Thực hiện chuyển số R/D
			do {
				if (taySo == 2) {
					cout << "DA VE SO R." << endl;
				}
				else {
					cout << "DA VE SO D." << endl;
				}
				cout << "--- TOC DO HIEN TAI: " << vantoc << "km/h" << endl;

				if (vantoc <= safe_distance[0]) {//van toc < muc 1
					cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 20M" << endl;;
				}
				else if (vantoc > safe_distance[0] && vantoc <= safe_distance[1]) {//muc 1 < van toc <= muc 2
					cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 55M" << endl;;
				}
				else if (vantoc > safe_distance[1] && vantoc <= safe_distance[2]) {//muc 2 < van toc <= muc 3
					cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 70M" << endl;;
				}
				else //van toc > muc 3
				{
					cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU LA 100M" << endl;;
				}
				if (taySo == 2 && vantoc > 20) {
					cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
				}
				else if (taySo == 4 && vantoc > 60) {
					cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
				}
				luaChonChanGa = selectMenu2();//lựa chọn tốc độ sau khi chuyển số R/D

			} while (luaChonChanGa != 4);//vẫn tiếp tục lựa chọn tốc độ cho đến khi người dùng chọn trở về MENU
			taySoDaChon = taySo;//luu tay so da chon de kiem tra dieu kien truoc khi chuyen so

			break;
		case 5:
			cout << "POWER OFF" << endl;
			cout << "CHAO TAM BIET" << endl;
			//exit(0);
			break;
		default:

			break;
		}
	} while (taySo != 5);
}


