#include <iostream>
#include <string>
using namespace std;
int main()
{
	int Id[10] = { 0 };
	string Name[10] = { "Muhammad Waleed", "Abdul Hanan", "Abdullah Arshad", "Muhammad Shujat", "Asad Javed" };
	string Gen[10] = { "Male", "Male", "Male", "Male", "Male" };
	int Sem[10] = { 1, 2, 1, 1, 2 };
	float GPA[10] = { 4.0, 3.9, 3.9, 4.0, 3.6 };
	string Dep[10] = { "Computer Science", "Information Technology", "Electrical Engeneering", "Civil Engeneering", "Information Technology" };
	string Extra[10] = { "None", "Society Member", "Sports Man", "InternetGeek", "None" };
	string DOB[10] = { "01-12-2003", "09-03-2002", "16-06-2002", "24-01-2001", "30-08-2002" };
	int Select = 0;
	int Id_check = 0;
	int Index_Id = 0;
	string Search_Name;
	int Search_Sem = 0;
	string Search_Dep;
	for (; Index_Id < 5; Index_Id++)
	{
		Id[Index_Id] = Index_Id + 1;
	}
	cout << "\n\n----------------------------- Welcome to UCP Student's Database System -----------------------------\n\n";
	while (true)
	{
		cout << "Please enter the number corresponding to your choice from the menu.\n";
		cout << "1. Display all students information.\n";
		cout << "2. Update student information.\n";
		cout << "3. Add new student.\n";
		cout << "4. Search student by name.\n";
		cout << "5. Search students by semester and department.\n";
		cout << "6. Exit.\n\n";
		cout << "Enter your choice: ";
		cin >> Select;
		cout << endl;
		if (Select == 1)
		{
			cout << "| ID | Name | Date of Birth | Gender | Semester | Department | GPA | Extracurricular |\n\n";
			for (int i = 0; i < 10; i++)
			{
				if (Id[i] != 0)
				{
					cout << "| " << Id[i] << " | " << Name[i] << " | " << DOB[i] << " | " << Gen[i] << " | " << Sem[i] << " | " << Dep[i] << " | " << GPA[i] << " | " << Extra[i] << " |\n";
				}
			}
			cout << endl;
		}
		else if (Select == 2)
		{
			bool found = true;
			cout << "Enter student ID: ";
			cin >> Id_check;
			for (int i = 0; i < 10; i++)
			{
				if (Id_check == Id[i])
				{
					cout << "Enter student name: ";
					cin.ignore();
					getline(cin, Name[i]);
					cout << "Enter date of birth (Format DD-MM-YYYY): ";
					cin >> DOB[i];
					cout << "Enter gender: ";
					cin >> Gen[i];
					cout << "Enter semester: ";
					cin >> Sem[i];
					cout << "Enter department: ";
					cin.ignore();
					getline(cin, Dep[i]);
					cout << "Enter GPA: ";
					cin >> GPA[i];
					cout << "Enter extracurricular: ";
					cin.ignore();
					getline(cin, Extra[i]);
					cout << "\nStudent information updated.\n\n";
					found = false;
				}
			}
			if (found)
			{
				cout << "This Student does not exists in the database, Please add first to update information.\n\n";
			}
		}
		else if (Select == 3)
		{
			bool found = true;
			cout << "Enter student ID: ";
			cin >> Id_check;
			for (int i = 0; i < 10; i++)
			{
				if (Id_check == Id[i])
				{
					cout << "This student profile already exsists in the database, Please try with different id.\n\n";
					found = false;
					break;
				}
			}
			if (found)
			{
				Id[Index_Id] = Id_check;
				cout << "Enter student name: ";
				cin.ignore();
				getline(cin, Name[Index_Id]);
				cout << "Enter date of birth (Format DD-MM-YYYY): ";
				cin >> DOB[Index_Id];
				cout << "Enter gender: ";
				cin >> Gen[Index_Id];
				cout << "Enter semester: ";
				cin >> Sem[Index_Id];
				cout << "Enter department: ";
				cin.ignore();
				getline(cin, Dep[Index_Id]);
				cout << "Enter GPA: ";
				cin >> GPA[Index_Id];
				cout << "Enter extracurricular: ";
				cin.ignore();
				getline(cin, Extra[Index_Id]);
				Index_Id++;
				cout << "\nStudent profile added.\n\n";
			}
		}
		else if (Select == 4)
		{
			bool notfound = true;
			cout << "Enter student's full name to find: ";
			cin.ignore();
			getline(cin, Search_Name);
			for (int i = 0; i < 10; i++)
			{
				if (Search_Name == Name[i])
				{
					cout << "\n| ID | Name | Date of Birth | Gender | Semester | Department | GPA | Extracurricular |\n\n";
					cout << "| " << Id[i] << " | " << Name[i] << " | " << DOB[i] << " | " << Gen[i] << " | " << Sem[i] << " | " << Dep[i] << " | " << GPA[i] << " | " << Extra[i] << " |\n";
					notfound = false;
				}
			}
			cout << endl;
			if (notfound)
			{
				cout << "The student " << Search_Name << " not found in the database.\n\n";
			}
		}
		else if (Select == 5)
		{
			bool notfound = true;
			bool printed = true;
			cout << "Enter semester: ";
			cin >> Search_Sem;
			cout << "Enter Department: ";
			cin.ignore();
			getline(cin, Search_Dep);
			for (int i = 0; i < 10; i++)
			{
				if (Search_Sem == Sem[i] && Search_Dep == Dep[i])
				{
					if (printed)
					{
						cout << "\n| ID | Name | Date of Birth | Gender | Semester | Department | GPA | Extracurricular |\n\n";
						printed = false;
					}
					cout << "| " << Id[i] << " | " << Name[i] << " | " << DOB[i] << " | " << Gen[i] << " | " << Sem[i] << " | " << Dep[i] << " | " << GPA[i] << " | " << Extra[i] << " |\n";
					notfound = false;
				}
			}
			cout << endl;
			if (notfound)
			{
				cout << "No students found in Semester " << Search_Sem << " and Department " << Search_Dep << ".\n\n";
			}
		}
		else if (Select == 6)
		{
			cout << "Exiting the system...\n\n";
			break;
		}
	}
	return 0;
}
