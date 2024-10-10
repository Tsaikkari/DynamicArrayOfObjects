#include <iostream>

using namespace std;

class Student {
public:
	string Name;
	int Age;
	char Gender;
	float Grade;
};

Student* enterStudents(Student* students, int start_pos, int size) {
	for (int i = start_pos; i < size; i++) {
		cout << "STUDENT " << i + 1 << endl;

		Student s;
		cout << "Name: ";
		cin >> s.Name;
		cout << "Age: ";
		cin >> s.Age;
		cout << "Gender: ";
		cin >> s.Gender;
		cout << "Grade: ";
		cin >> s.Grade;

		students[i] = s;
	}

	return students;
}

void printStudents(Student* students, int size) {
	for (int i = 0; i < size; i++) {
		cout << "STUDENT " << i + 1 << endl;
		cout << students[i].Name << "\t";
		cout << students[i].Age << "\t";
		cout << students[i].Gender << "\t";
		cout << students[i].Grade << "\n";
	}
}

void validateInput(int size, int newSize = 100) {
	if (size < 0 || newSize < 0) throw "Negative number given";
	if (newSize <= size) throw "Array size is not valid";
}

void printByGender(Student* students, Student* femaleStudents, Student* maleStudents, int size, char gender) {
	int pos = 0;

	if (gender == 'f') {
		for (int i = 0; i < size; i++) {
			if (students[i].Gender == 'f') {
				femaleStudents[pos] = students[i];
				pos++;
			}
		}

		printStudents(femaleStudents, pos);
		delete[] femaleStudents;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (students[i].Gender == 'm') {
				maleStudents[pos] = students[i];
				pos++;
			}
		}

		printStudents(maleStudents, pos);
		delete[] maleStudents;
	}
}

int main()
{
	try {
		int size;
		cout << "Number of students: " << endl;
		cin >> size;
		validateInput(size);

		Student* students = new Student[size];
		enterStudents(students, 0, size);
		cout << "All students: " << endl;
		printStudents(students, size);

		Student* femaleStudents = new Student[size];
		Student* maleStudents = new Student[size];

		cout << "Female students: " << endl;
		printByGender(students, femaleStudents, maleStudents, size, 'f');

		char choice;
		cout << "Do you want to add more students? y/n ";
		cin >> choice;

		if (choice == 'n' || choice == 'N') {
			delete[] students;
			return 0;
		}

		int newSize;
		cout << "Enter new amount of students: ";
		cin >> newSize;
		validateInput(size, newSize);

		Student* newStudents = new Student[newSize];

		for (int i = 0; i < size; i++) {
			newStudents[i] = students[i];
		}

		delete[] students;

		students = newStudents;

		enterStudents(students, size, newSize);
		cout << "All students: " << endl;
		printStudents(students, newSize);

		Student* renewFStudents = new Student[newSize];
		Student* renewMStudents = new Student[newSize];
		cout << "Male students: " << endl;
		printByGender(students, renewFStudents, renewMStudents, newSize, 'm');

		delete[] students;
	}
	catch (const char* txtException) {
		cout << "Exception: " << txtException << endl;
	}
	catch (...) {
		cout << "Exception happened";
	}

	return 0;
}







