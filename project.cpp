#include <iostream>
using namespace std;
string names[21][5];
int status[21][5];
int patients_num_in_spec[21];
int menu() {
	cout << "Enter your choice:\n";
	cout << "1) Add new patient\n";
	cout << "2) Print all patients\n";
	cout << "3) Get next patient\n";
	cout << "4) Exit\n";
	int num;
	cin >> num;
	if (num >= 1 && num <= 4) {
		return num;
	}
	else {
		cout << "Invalid choice , Try again\n";
		return menu();
	}

}
void shift_right(int spec, string names_of_spec[], int status_of_spec[]) {
	int length = patients_num_in_spec[spec];
	for (int i = length - 1; i >= 0; --i) {
		status_of_spec[i + 1] = status_of_spec[i];
		names_of_spec[i + 1] = names_of_spec[i];
	}
	patients_num_in_spec[spec]++;
}
void add_patient() {
	string name;
	int spec, st;
	cout << "Enter specialization, name, status: ";
	cin >> spec >> name >> st;
	if (patients_num_in_spec[spec] >= 5) {
		cout << "Sorry we can't add more patients for this specialization\n\n";
	}
	else if (st) {
		shift_right(spec, names[spec], status[spec]);
		names[spec][0] = name;
		status[spec][0] = st;
	}
	else {
		names[spec][patients_num_in_spec[spec]] = name;
		status[spec][patients_num_in_spec[spec]] = st;
		patients_num_in_spec[spec]++;
	}
}
void printing_patients(int i, string names_sp[], int status_sp[]) {
	if (patients_num_in_spec[i] != 0) {
		cout << "There are " << patients_num_in_spec[i] << " patients in specialization " << i << endl;
		for (int j = 0; j < patients_num_in_spec[i]; ++j) {
			if (status_sp[j] == 0) {
				cout << names_sp[j] << " regular";
			}
			else {
				cout << names_sp[j] << " urgent";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}
void print_patient() {
	cout << "********************\n";
	for (int i = 0; i < 20; ++i) {
		printing_patients(i, names[i], status[i]);
	}
}
void shift_left(int spec, string names_of_spec[], int status_of_spec[]) {
	int length = patients_num_in_spec[spec];
	for (int i = 0; i < length; ++i) {
		status_of_spec[i] = status_of_spec[i + 1];
		names_of_spec[i] = names_of_spec[i + 1];
	}
	patients_num_in_spec[spec]--;
}
void get_next_patient() {
	int spec;
	cout << "Enter specialization: ";
	cin >> spec;
	if (patients_num_in_spec[spec] == 0) {
		cout << "No patients at the moment. Have rest, Dr\n";
	}
	else {
		cout << names[spec][0] << " , please go with the Dr\n";
		shift_left(spec, names[spec], status[spec]);
	}
}
void hospital_system() {
	while (true) {
		int num = menu();
		if (num == 1) {
			add_patient();
		}
		else if (num == 2) {
			print_patient();
		}
		else if (num == 3) {
			get_next_patient();
		}
		else {
			break;
		}
	}
}
int main()
{
	hospital_system();
}
