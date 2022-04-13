#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

enum Spec { KOMPUTERNINAUKY, INFORMATIKA, MATEMATIKAIEKONOMIKA, FIZUKAIINFORMATIKA, TRUDOVENAVCHANNA };

string spec_str[] = { "Computer Science", "Informatics", "Mathematics and Economics", "Physics and Informatics", "Handicraft" };

struct Student
{
	string last_name;
	int cource;
	Spec speci;
	int fizuka;
	int matematika;
	union {
		int prog;
		int chuselni_metody;
		int peda;
	};
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
int Mid(Student* s, const int N);
int Kil(Student* s, const int N);

int main() {
	int N;
	cout << "Insert N: "; cin >> N;
	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);
	Mid(s, N);
	Kil(s, N);
}
void Create(Student* s, const int N) {
	int speci;
	for (int i = 0; i < N; i++)
	{
		cout << "Student № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " Last Name: "; getline(cin, s[i].last_name);
		cout << " Cource : "; cin >> s[i].cource;
		cout << " Speciality (0 - Computer Science, 1 - Informatics, 2 - Mathematics and Economics, 3 - Physics and Informatics, 4 - Handicraft): ";
		cin >> speci;
		s[i].speci = Spec(speci);
		switch (s[i].speci) {
		case KOMPUTERNINAUKY:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Programming : "; cin >> s[i].prog;
			break;
		case INFORMATIKA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Numerical Methods : "; cin >> s[i].chuselni_metody;
			break;
		case MATEMATIKAIEKONOMIKA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Pedagogy : "; cin >> s[i].peda;
			break;
		case FIZUKAIINFORMATIKA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Pedagogy : "; cin >> s[i].peda;
			break;
		case TRUDOVENAVCHANNA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Pedagogy : "; cin >> s[i].peda;
			break;
		}
		cout << endl;
	}
}
void Print(Student* s, const int N)
{
	cout << "=============================================================================" << endl;
	cout << "| № | Last Name | Course | Speciality | Phy | Math | Prog | Num Met | Ped |" << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(10) << left << s[i].last_name << "| " << setw(6) << right << s[i].cource << " " << "| " << setw(10) << left << spec_str[s[i].speci];
		switch (s[i].speci) {
		case KOMPUTERNINAUKY:
			cout << "| " << setw(3) << right << s[i].fizuka << "|" << " " << setw(3) << right
				<< s[i].matematika << "|" << " " << setw(3) << right << s[i].prog << " |"
				<< " " << setw(3) << right << " |" << " " << setw(3) << right << " |" << endl;
			break;
		case INFORMATIKA:
			cout << "| " << setw(3) << right << s[i].fizuka << "|" << " " << setw(3) << right
				<< s[i].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< s[i].chuselni_metody << " |" << setw(3) << right << "|" << endl;
			break;
		case MATEMATIKAIEKONOMIKA:
			cout << "| " << setw(3) << right << s[i].fizuka << "|" << " " << setw(3) << right
				<< s[i].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< " |" << " " << setw(3) << right << s[i].peda << " |" << endl;
			break;
		case FIZUKAIINFORMATIKA:
			cout << "| " << setw(3) << right << s[i].fizuka << "|" << " " << setw(3) << right
				<< s[i].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< " |" << " " << setw(3) << right << s[i].peda << " |" << endl;
			break;
		case TRUDOVENAVCHANNA:
			cout << "| " << setw(3) << right << s[i].fizuka << "|" << " " << setw(3) << right
				<< s[i].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< " |" << " " << setw(3) << right << s[i].peda << " |" << endl;
			break;
		}
	}
	cout << "=============================================================================" << endl;
	cout << endl;
}

int Mid(Student* s, const int n)
{
	int ser = 0, serd = 0;
	int k;
	int z = 0;
	k = n;
	for (int i = 0;i < n;i++) {
		if (s[i].fizuka < z) {
			k - 1;
		}
		ser = ser + s[i].fizuka;
	}

	serd = ser / k;
	cout << "Ser fiz " << serd << endl;
	ser = 0;
	k = n;

	for (int i = 0;i < n;i++) {
		if (s[i].matematika == z) {
			k - 1;
		}
		ser = ser + s[i].matematika;
	}

	serd = ser / k;
	cout << "Ser math " << serd << endl;
	ser = 0;
	k = n;

	for (int i = 0;i < n;i++) {
		if (s[i].prog == z) {
			k - 1;
		}
		ser = ser + s[i].prog;
	}

	serd = ser / k;
	cout << "Ser prog " << serd << endl;
	ser = 0;
	k = n;

	for (int i = 0;i < n;i++) {
		if (s[i].chuselni_metody == z) {
			k - 1;
		}
		ser = ser + s[i].chuselni_metody;
	}

	serd = ser / k;
	cout << "Ser num " << serd << endl;
	ser = 0;
	k = n;

	for (int i = 0;i < n;i++) {
		if (s[i].peda == z) {
			k - 1;
		}
		ser = ser + s[i].peda;
	}

	serd = ser / k;
	cout << "Ser pedagog " << serd << endl;

	return 0;
}

int Kil(Student* s, const int n) {
	int q = 0;
	for (int i = 0; i < n;i++) {
		if (s[i].fizuka == 4 || s[i].fizuka == 5) {
			q++;
		}
	}
	cout << "Kilk stud " << q;
	return 0;
}