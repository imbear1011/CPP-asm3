--->CHỨC NĂNG CHƯƠNG TRÌNH:

_ĐĂNG NHẬP:
	+Đưa ra thông báo nhập mã số cá nhân.
	+Đối với lần đầu tiên đăng nhập (tương đương với việc chưa có dữ liệu cài đặt trong file
	hoặc tương đương với việc mảng mscn[8] chưa được thay đổi giá trị mặc định), chưa có 
	mã số cá nhân (được cài đặt trong file hoặc trong mảng mscn[8]) thì cần đưa ra thông báo
	người dùng biết mã số cá nhân chưa cài đặt và yêu cầu người dùng nhập vào cài đặt mã số cá nhân, 
	sau đó ghi mã số cá nhân vừa nhập vào file nhị phân hoặc vào mảng mscn[8]. 
	+Đối với lần thứ 2 trở đi (tức trường hợp có mã số cá nhân ghi trong file hoặc mảng mscn[8]
	đã được cài đặt giá trị) thì tiến hành login và so sánh với mã số cá nhân nhập vào.
	+Mã số cá nhân là một chuỗi gồm 8 số nguyên bất kỳ. 
	Người dùng cần nhập vào 1 mảng 8 số nguyên và sau đó cần:
	->Sắp xếp tăng dần mảng mã số nhập vào bằng thuật toán sủi bọt
	->Sắp xếp tăng dần mảng mã số cá nhân có sẵn bằng thuật toán selection sort
	+So sánh 2 mảng vừa sắp xếp, kiểm tra nếu mảng không trùng với mã số cá nhân đã được cài đặt 
	thì dừng chương trình và đưa ra thông báo chào tạm biệt.

_CÀI ĐẶT CÁC GIẢI VẬN TỐC ĐỂ THÔNG BÁO KHOẢNG CÁCH AN TOÀN:
	+Yêu cầu người dùng nhập vào 3 mức vận tốc cài đặt. Sắp xếp mảng dữ liệu đó tăng dần.
	+Đối với lần đầu tiên cài đặt (tương ứng với chưa có file, mảng safe_distance[3] 
	chưa được thay đổi giá trị ban đầu) thì tiến hành thông báo cho người dùng biết dữ liệu chưa được 
	cài đặt và yêu cầu người dùng nhập vào cài đặt. Cập nhật xuống file hoặc cập nhật dữ liệu cho mảng 
	safe_distance[3] với dữ liệu nhập vào từ người dùng.
	+Sau khi cài đặt thành công, hỏi người dùng có cần cài đặt lại không (y/n). 
	Nếu người dùng chọn ‘y’ thì tiến hành cho người dùng cài đặt lại và cập nhật dữ liệu vào file. 
	Nếu người dùng chọn ‘n’ thì tiến hành bước tiếp theo là sử dụng cần số 
	Dựa theo thông tin trên, tiến hành kiểm tra vận tốc hiện tại với các vận tốc được cài 
	đặt và đưa ra thông báo:
	->Tốc độ lưu hành nhỏ hơn <Mức 1> km/h phải giữ khoảng cách tối thiểu là 20m
	->Tốc độ lưu hành trong khoảng <Mức 1 ~ Mức 2> phải giữ khoảng cách tối thiểu là 55m
	->Tốc độ lưu hành trong khoảng <Mức 2 ~ Mức 3> phải giữ khoảng cách tối thiểu là 70 mét
	->Tốc độ lưu hành trên <Mức 3> phải giữ khoảng cách tối thiểu là 100 mét

_LỰA CHỌN HÀNH TRÌNH HỘP SỐ:
	+Đưa ra lựa chọn hành trình hộp số để điều khiển xe:
	1. P  Sử dụng để chuyển số sang số P, đỗ và dừng xe
	2. R Sử dụng để chuyển số sang số R, lùi xe
	3. N Sử dụng để chuyển số sang số N, tạm dừng xe
	4. D Sử dụng để chuyển số sang số D, tiến xe
	5. POWER OFF để tắt máy dừng hoạt động

_HIỂN THỊ THÔNG BÁO KHI KHI CHỌN HÀNH TRÌNH P HOẶC N:
	+Khi vận tốc xe thỏa mãn = 0, thì dừng xe thành công. Xe chỉ có thể sang số P/N khi đã dừng hẳn
	+Khi vận tốc xe chưa về 0 (tức là xe chưa dừng hẳn) thì đưa ra thông báo cần dừng xe để thực hiện

_HIỂN THỊ THÔNG BÁO KHI LỰA CHỌN HÀNH TRÌNH R HOẶC D:
	+Hiển thị menu hoạt động:
	1. TANG TOC
	2. GIAM TOC
	3. PHANH
	4. TRO VE MENU
	+Thực hiện tăng tốc lên mỗi 5 km/h sau mỗi lần lựa chọn tăng tốc và giảm mỗi 5 km/h sau mỗi lần lựa chọn giảm tốc 
	và khi lựa chọn Phanh lập tức đưa tốc độ về 0 km/h
	+Nếu tốc độ > 60 km/h (với D hoặc 20km/h với R) đưa ra cảnh báo tốc độ cao cho lái xe
	+Việc chuyển số qua lại giữa số R và số D khi vận tốc = 0.

_TẮT MÁY KHI NGƯỜI DỤNG CHỌN POWER OFF VÀ ĐƯA RA THÔNG BÁO CHÀO TẠM BIỆT.

_CHỨC NĂNG BỔ SUNG:
	+Kiểm tra lựa chọn nhập vào là số hay là ký tự: Tại đây bất kỳ thao tác nhập vào như lựa chọn menu, 
	cài đặt giá trị là một số hay một ký tự thì cần phải kiểm tra nhập vào đó là một số hay một ký tự. 
	Hợp lệ thì thực thi tiếp, không hợp lệ thì yêu cầu nhập lại
	+So sánh số bước thực hiện (hay còn gọi là độ phức tạp) của hai thuật toán bubbleSort và selectionSort

--->NGƯỜI THỰC HIỆN: BÙI MINH KHA (khabmFX22342)

---> IDE: Visual Studio 2022

--->
bool kiemTraSoNguyen(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (!isdigit(str.at(i)) ) {
			return false;
		}
	};
	return true;
}
Sử dụng hàm isdigit() và vòng lặp for duyệt qua từng kí tự trong chuỗi để kiểm tra số nguyên.

--->Thuật toán bubbleSort:
int bubbleSort(int a[], int n) {
	int biendem = 0;//bien dem so buoc thuc hien
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (*(a+j) < *(a+(j - 1))) {
				biendem++;
				int tg = *(a+j);
				*(a+j) = *(a+(j - 1));
				*(a+(j - 1)) = tg;
			}
		}
	}
	return biendem;
}

--->Thuật toán selectionSort:
int selectionSort(int a[], int n) {
	int biendem = 0;//biem dem so buoc thuc hien
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (*(a + j) < *(a + min)) { 
				biendem++;
				min = j; 
			}
		}
		int tg = *(a+min);
		*(a+min) = *(a+i);
		*(a+i) = tg;

	}
	return biendem;
}