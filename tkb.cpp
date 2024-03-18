#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<fstream> 
#include<string>
using namespace std;
//tao 3 struct
struct Sang
{
	char mon[20];
};

struct Chieu
{
	char mon[20];
};

struct TKB
{
	struct Sang S[5] = { " ", " ", " ", " ", " " };// 2 member 
	struct Chieu C[5] = { " ", " ", " ", " ", " " };
};
//xoa dong trong cau lenh fgets
void xoadong(char arr[]) {
	size_t len = strlen(arr);
	if (arr[len - 1] == '\n') arr[len - 1] = '\0';
}
//tao 1 ham nhap tkb
void Nhap(struct TKB* tkb) {
	int s, c;
	for (int i = 2; i < 8; i++)
	{
		do
		{
			cout << "\nNhap so mon hoc Sang(1->5)\nThu " << i << ": ";
			cin >> s;
			getchar();
			if (s<0 || s>5) cout << "\nMoi nhap lai!";
		} while (s<0 || s>5);
		for (int j = 0; j < s; j++)
		{
			cout << "Nhap mon " << j + 1 << " :";
			fflush(stdin);
			fgets(tkb[i - 2].S[j].mon, sizeof(tkb[i - 2].S[j].mon), stdin); xoadong(tkb[i - 2].S[j].mon);
		}
		do
		{
			cout << "\nNhap so mon hoc Chieu(1->5)\nThu " << i << ": ";
			cin >> c;
			getchar();
			if (c<0 || c>5) cout << "\nMoi nhap lai!";
		} while (c<0 || c>5);
		for (int j = 0; j < c; j++)
		{
			cout << "Nhap mon " << j + 1 << " :";
			fflush(stdin);
			fgets(tkb[i - 2].C[j].mon, sizeof(tkb[i - 2].C[j].mon), stdin); xoadong(tkb[i - 2].C[j].mon);
		}
		system("cls");
		// vi la chu nhat nen k the de thu 8 duoc, nen toi se lam 1 th rieng
		if (i == 7) {
			do
			{
				cout << "\nNhap so mon hoc Sang CN(1->5): ";
				cin >> s;
				getchar();
				if (s<0 || s>5) cout << "\nMoi nhap lai!";
			} while (s<0 || s>5);
			for (int j = 0; j < s; j++)
			{
				cout << "Nhap mon " << j + 1 << " :";
				fflush(stdin);
				fgets(tkb[i - 1].S[j].mon, sizeof(tkb[i - 1].S[j].mon), stdin); xoadong(tkb[i - 1].S[j].mon);
			}
			do
			{
				cout << "\nNhap so mon hoc Chieu CN(1->5): ";
				cin >> c;
				getchar();
				if (c<0 || c>5) cout << "\nMoi nhap lai!";
			} while (c<0 || c>5);
			for (int j = 0; j < c; j++)
			{
				cout << "Nhap mon " << j + 1 << " :";
				fflush(stdin);
				fgets(tkb[i - 1].C[j].mon, sizeof(tkb[i - 1].C[j].mon), stdin); xoadong(tkb[i - 1].C[j].mon);
			}
			system("cls");
		}
	}
}

void Xuat(struct TKB tkb[]) {
	cout << setfill('-') << setw(30) << "-" << "THOI KHOA BIEU" << setw(30) << "-";
	cout << setfill(' ') << "\nSANG:\n" << setw(15) << left << "Thu 2" << setw(15) << left << "Thu 3" << setw(15) << left << "Thu 4" << setw(15) << left << "Thu 5" << setw(15) << left << "Thu 6" << setw(15) << left << "Thu 7" << "Chu Nhat\n";
	//2 de cho no dep 
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << setw(15) << left << tkb[j].S[i].mon;
		}
		cout << "\n";
	}
	cout << setfill(' ') << "\nCHIEU:\n" << setw(15) << left << "Thu 2" << setw(15) << left << "Thu 3" << setw(15) << left << "Thu 4" << setw(15) << left << "Thu 5" << setw(15) << left << "Thu 6" << setw(15) << left << "Thu 7" << "Chu Nhat\n";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << setw(15) << left << tkb[j].C[i].mon;
		}
		cout << "\n";
	}
}

void Sua(struct TKB* tkb) {
	char thu[10], tgian[10];
	int n, len, x;
	do
	{
		cout << "Nhap thu (2/3/4/5/6/7/CN) can sua: ";
		fflush(stdin);
		fgets(thu, sizeof(thu), stdin); xoadong(thu);
		len = strlen(thu);//thu 2    (5 kt)    
		if (len != 8) n = thu[len - 1] - '0' - 2;// n= 2 -'0'(convert qua so nguyen) -2=0
		else n = len - 2;//    chu nhat (8 kt)  n=6; 
		if (n<0 || n>6) cout << "Moi ban nhap lai!\n";
	} while (n<0 || n>6);


	for (int i = 0; i < 7; i++)
	{
		if (n == i) {                         // n==i (0==0) sua dung theo thu can sua
			do
			{
				cout << "Nhap buoi hoc can sua (Sang/Chieu): ";
				fflush(stdin);
				fgets(tgian, sizeof(tgian), stdin); xoadong(tgian);
				if (strncmp(tgian, "Sang", 4) != 0 && strncmp(tgian, "Chieu", 5) != 0) cout << "Moi ban nhap lai!\n";
			} while (strncmp(tgian, "Sang", 4) != 0 && strncmp(tgian, "Chieu", 5) != 0); 
			len = strlen(tgian);
			if (len == 4) {
				do
				{
					cout << "Nhap thu tu mon can sua(1->5): ";
					cin >> x;
					getchar();
					if (x<1 || x>5) cout << "Moi ban nhap lai!\n";
				} while (x<1 || x>5);
				for (int j = 0; j < 5; j++)
				{
					if (x - 1 == j) {
						cout << "Mon ban dau: " << tkb[i].S[j].mon;
						cout << "\nSua: ";
						fflush(stdin);
						fgets(tkb[i].S[j].mon, sizeof(tkb[i].S[j].mon), stdin); xoadong(tkb[i].S[j].mon);
						break;
					}
				}
			}
			else {
				do
				{
					cout << "Nhap thu tu mon can sua(1->5): ";
					cin >> x;
					getchar();
					if (x<1 || x>5) cout << "Moi ban nhap lai!\n";
				} while (x<1 || x>5);
				for (int j = 0; j < 5; j++)
				{
					if (x - 1 == j) {
						cout << "Mon ban dau: " << tkb[i].C[j].mon;
						cout << "\nSua: ";
						fflush(stdin);
						fgets(tkb[i].C[j].mon, sizeof(tkb[i].C[j].mon), stdin); xoadong(tkb[i].C[j].mon);
						break;
					}
				}
			}
			break;
		}
	}
}

void Xem(struct TKB tkb[]) {
	char thu[10];
	int n, len;
	do
	{
		cout << "Nhap thu (2/3/4/5/6/7/CN) can xem: ";
		fflush(stdin);
		fgets(thu, sizeof(thu), stdin); xoadong(thu);
		len = strlen(thu);
		if (len != 8) n = thu[len - 1] - '0' - 2;
		else n = len - 2;
		if (n<0 || n>6) cout << "Moi ban nhap lai!\n";
	} while (n<0 || n>6);
	for (int i = 0; i < 7; i++)
	{
		if (n == i) {
			cout << setw(15) << right << " " << "Sang\t" << "Chieu\n";
			for (int j = 0; j < 5; j++)
			{
				cout << setw(15) << right << " " << tkb[i].S[j].mon << "\t" << tkb[i].C[j].mon << "\n";
			}
			break;
		}
	}
}

void luufile(struct TKB* tkb) {
	fstream f;
	f.open("tkb.txt", ios::out);// mo de ghi file du lieu ra
	f << setfill('-') << setw(30) << "-" << "THOI KHOA BIEU" << setw(30) << "-";
	f << setfill(' ') << "\nSANG:\n" << setw(10) << left << "Thu 2" << setw(10) << left << "Thu 3" << setw(10) << left << "Thu 4" << setw(10) << left << "Thu 5" << setw(10) << left << "Thu 6" << setw(10) << left << "Thu 7" << "Chu Nhat\n";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			f << setw(10) << left << tkb[j].S[i].mon;
		}
		f << "\n";
	}
	f << setfill(' ') << "\nCHIEU:\n" << setw(10) << left << "Thu 2" << setw(10) << left << "Thu 3" << setw(10) << left << "Thu 4" << setw(10) << left << "Thu 5" << setw(10) << left << "Thu 6" << setw(10) << left << "Thu 7" << "Chu Nhat\n";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			f << setw(10) << left << tkb[j].C[i].mon;
		}
		f << "\n";
	}
	f.close();
}

//cai nay de lam cho dep
void tt() {
	char a;
	cout << "Nhan phim bat ki de tiep tuc!";
	a = getchar();
}
//check thong tin account, pass
bool check(char name[], char pass[], char name1[], char pass1[]) {
	int len, len1;
	len = strlen(name);
	len1 = strlen(pass);
	if (strcmp(name, name1) != 0 || strcmp(pass, pass1) != 0 || len == 0 || len1 == 0) return false;
	return true;
}

void MENU(struct TKB tkb[], char name1[], char pass1[]) {
	int x = 0, y = 1, z = 0;
	char name[30], pass[20];
	do
	{
		cout << setfill('-') << setw(15) << "-" << "MENU" << setw(15) << "-" << "\n";
		cout << setfill(' ') << setw(10) << right << " " << "1-Dang nhap.\n";
		cout << setw(10) << right << " " << "0-Thoat.\n";
		cout << "Chon: ";
		cin >> x;
		getchar();
		system("cls");
		switch (x)
		{
		case 1:
			cout << "Username: ";
			fflush(stdin);
			fgets(name, sizeof(name), stdin); xoadong(name);
			cout << "Password: ";
			fflush(stdin);
			fgets(pass, sizeof(pass), stdin); xoadong(pass);
			if (check(name, pass, name1, pass1)) {
				system("cls");
				do
				{
					y = 0;
					cout << setfill('-') << setw(50) << "-" << "\n";
					cout << setfill(' ') << setw(10) << right << " " << "1-Nhap Thoi khoa bieu.\n";
					cout << setw(10) << right << " " << "0-Tro ve.\n";
					cout << "Chon: ";
					fflush(stdin);
					cin >> y; 
					getchar();
					system("cls");
					switch (y)
					{
					case 1:
						Nhap(tkb);
						do
						{
							cout << setfill('-') << setw(30) << "-" << "MENU" << setw(30) << "-" << "\n";
							cout << setfill(' ') << setw(15) << right << " " << "1-Xuat thong tin thoi khoa bieu.\n";
							cout << setw(15) << right << " " << "2-Sua thong tin thoi khoa bieu.\n";
							cout << setw(15) << right << " " << "3-Xem thoi khoa bieu theo thu (2/3/4/5/6/7/CN).\n";
							cout << setw(15) << right << " " << "4-Luu vao file tkb.txt .\n";
							cout << setw(15) << right << " " << "0-Tro ve.\n";
							cout << "Chon: ";
							cin >> z;
							getchar();
							system("cls");
							switch (z)
							{
							case 1:
								Xuat(tkb); tt();
								break;
							case 2:
								Sua(tkb);
								break;
							case 3:
								Xem(tkb);
								break;
							case 4:
								luufile(tkb);
								break;
							default:
								if (z != 0) {
									cout << "Moi Chon lai!\n"; tt();
								}
								else break;
								break;
							}
							if (z != 0) {
								tt();
								system("cls");
							}
							else system("cls");
						} while (z != 0);
						break;
					default:
						if (y != 0) {
							cout << "Moi Chon lai!\n";
						}
						else break;
						break;
					}
					if (y != 0) {
						tt();
						system("cls");
					}
					else system("cls");
				} while (y != 0);
			}
			else cout << "Ten dang nhap hoac mat khau khong dung!\n";
			break;
		default:
			if (x != 0) {
				cout << "Moi Chon lai!\n"; tt();
			}
			else break;
			break;
		}
		if (x != 0 && y != 0) {
			tt();
			system("cls");
		}
		else system("cls");
		y = 1;
	} while (x != 0);
}

void MENU1(struct TKB tkb[], char name2[], char pass2[]) {
	int x;
	char name[30], pass[20];
	string str;
	do
	{
		cout << setfill('-') << setw(15) << "-" << "MENU" << setw(15) << "-" << "\n";
		cout << setfill(' ') << setw(10) << right << " " << "1-Dang nhap.\n";
		cout << setw(10) << right << " " << "0-Thoat.\n";
		cout << "Chon: ";
		cin >> x;
		getchar();
		system("cls");
		switch (x)
		{
		case 1:
			cout << "Username: ";
			fflush(stdin);
			fgets(name, sizeof(name), stdin); xoadong(name);
			cout << "Password: ";
			fflush(stdin);
			fgets(pass, sizeof(pass), stdin); xoadong(pass);
			if (check(name, pass, name2, pass2)) {
				system("cls");
				fstream f;
				f.open("tkb.txt", ios::in);
				while (!f.eof())
				{
					getline(f, str);
					cout << str << "\n";
				}
				f.close();
			}
			else cout << "Ten dang nhap hoac mat khau khong dung!\n";
			break;
		default:
			if (x != 0) {
				cout << "Moi ban chon lai!\n"; tt();
			}
			else break;
			break;
		}
		if (x != 0) {
			tt();
			system("cls");
		}
		else system("cls");
	} while (x != 0);
}

int main() {
	struct TKB tkb[7];
	char name1[30] = "giao vien", pass1[20] = "gv123";
	char name2[30] = "hoc sinh", pass2[20] = "hs123";
	int n;
	system("cls");
	do
	{
		cout << setfill('-') << setw(10) << "-" << "User" << setw(10) << "-" << "\n";
		cout << setfill(' ') << setw(5) << " " << "1-->Giao Vien.\n";
		cout << setw(5) << " " << "2-->Hoc Sinh.\n";
		cout << setw(5) << " " << "0-->Thoat.\n";
		cout << "Chon: ";
		cin >> n;
		system("cls");
		switch (n)
		{
		case 1:
			MENU(tkb, name1, pass1);
			break;
		case 2:
			MENU1(tkb, name2, pass2);
			break;

		default:
			if (n != 0) {
				cout << "Moi ban chon lai!\n"; tt();
			}
			else break;
			break;
		}
		if (n != 0) {
			tt();
			system("cls");
		}
		else system("cls");
	} while (n != 0);
	return 0;
}