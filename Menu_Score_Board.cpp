#include "menuScore.h"
#include "lib.h"
#include "password.h"
#include "staff.h"

void view_scoreboard_toCourse(SchoolYear* list_year) {
	SchoolYear* pCur = list_year;

	Semester* Cur_Semester = nullptr;
	string Semester;
	cout << "Enter Semester: "; cin >> Semester;
	Cur_Semester = pCur->semester;
	while (Cur_Semester->semester_name != Semester) {
		Cur_Semester = Cur_Semester->pNext;
		if (Cur_Semester == nullptr)
		{
			cout << Semester << " is not over yet\n";
			return;
		}
	}
	if (Cur_Semester->semester_name != Semester) {
		cout << Semester << " is not over yet\n";
		return;
	}
	Course* Cur_course = nullptr;
	string Course;
	cout << "Enter Course: "; cin >> Course;
	Cur_course = Cur_Semester->course;
	while (Cur_course->id != Course) {
		Cur_course = Cur_course->pNext;
		if (Cur_course == nullptr) {
			cout << Course << " is not over yet\n";
			return;
		}
	}
	Student* studentF = nullptr;
	studentF = Cur_course->student;
	cout << left
		<< setw(13)
		<< "Student ID| "
		<< left
		<< setw(13)
		<< "First Name| "
		<< left
		<< setw(13)
		<< "Last Name|"
		<< left
		<< setw(13)
		<< "Gender| "
		<< left
		<< setw(13)
		<< "Date of birth| "
		<< left
		<< setw(13)
		<< "Social ID| "
		<< left
		<< setw(9)
		<< "Total mark| "
		<< left
		<< setw(9)
		<< "Final mark|"
		<< left
		<< setw(13)
		<< "Midterm mark|"
		<< left
		<< setw(13)
		<< "Other mark|" << endl;
	cout << setfill('-');
	cout << setw(80) << '-' << endl;
	cout << setfill(' ');
	while (studentF != nullptr) {
		cout
			<< left
			<< setw(13)
			<< studentF->student_ID << " "
			<< left
			<< setw(13)
			<< studentF->first_name << " "
			<< left
			<< setw(13)
			<< studentF->last_name << " "
			<< left
			<< setw(13)
			<< studentF->gender << " "
			<< left
			<< setw(13)
			<< studentF->date_of_birth << " "
			<< left
			<< setw(13)
			<< studentF->social_ID << " "
			<< left
			<< setw(9)
			<< studentF->score.total_mark << " "
			<< left
			<< setw(9)
			<< studentF->score.final_mark << " "
			<< left
			<< setw(13)
			<< studentF->score.mid_mark << " "
			<< left
			<< setw(13)
			<< studentF->score.other_mark << endl;
		studentF = studentF->pNext;
	}
}

void import_score_of_course(Course* z)
{
	cout << "Course information: " << endl;
	cout << z->id << "  " << z->course_name << endl;
	cout << z->class_name << endl;
	cout << "Now we import score for each students : " << endl << endl;
	Student* s = z->student; // from now just use branch Student of this Course
	while (s != nullptr) {
		cout << "Student id: " << s->student_ID << " " << s->first_name << " " << s->last_name << " " << s->gender << " " << s->date_of_birth << " " << s->social_ID << endl;
		cout << "Midterm mark:"; cin >> s->score.mid_mark;
		cout << "Final mark:"; cin >> s->score.final_mark;
		cout << "Other mark:"; cin >> s->score.other_mark;

		// just assume the logic math calculate, staff can fix it
		s->score.total_mark = (s->score.final_mark * 2 + s->score.mid_mark) / 3 + s->score.other_mark;
		cout << "Total mark is: " << s->score.total_mark;
		s = s->pNext;
	}
}

void Menu_Score_Board(SchoolYear* list_year)
{
	int option;
	cout << "Enter 0: =Get File ScoreBoard= \t Enter 1: =Enter by keyboard=\tEnter 2: = View Score = \t =Enter other. Quit=\n";
	cin >> option;
	while (option == 0 || option == 1 || option == 2) {
		SchoolYear* pCur = list_year;
		string yes;
		if (option == 0) {
			do {
				Semester* Cur_Semester = nullptr;
				string Semester;
				cout << "Enter Semester: "; cin >> Semester;
				Cur_Semester = pCur->semester;
				bool flag = false;
				while (Cur_Semester->semester_name.compare(Semester) != 0) {
					Cur_Semester = Cur_Semester->pNext;
					if (Cur_Semester == nullptr) {
						flag = true;
						break;
					}
				}
				if (flag) {
					break;
				}
				if (Cur_Semester->semester_name.compare(Semester) != 0) {
					cout << Cur_Semester->semester_name << " is not over yet\n";
					option = 0;
					continue;
				}
				Course* Cur_course = nullptr;
				string Course;
				cout << "Enter Course: "; cin >> Course;
				Cur_course = Cur_Semester->course;
				while (Cur_course->id.compare(Course) != 0) {
					Cur_course = Cur_course->pNext;
					if (Cur_course == nullptr) {
						flag = true;
						break;
					}
				}
				if (flag) {
					break;
				}
				fstream F;
				F.open("import_scoreboard.txt", ios::app);
				Student* studentF = nullptr;
				studentF = Cur_course->student;
				while (studentF != nullptr) {
					F << studentF->student_ID << "," << studentF->first_name << "," << studentF->last_name << "," << studentF->gender << "," << studentF->date_of_birth << "," << studentF->social_ID << ","
						<< studentF->score.total_mark << "," << studentF->score.final_mark << "," << studentF->score.mid_mark << "," << studentF->score.other_mark;
					if (studentF->pNext != nullptr)
						F << "\n";
					studentF = studentF->pNext;
				}
				F.close();
				cout << "Created a file containing the information of the course: " << Cur_course->id << " , Please enter your score into the file (enter 0 = agree): ";
				cin >> yes;
				if (yes != "0") remove("import_scoreboard.txt");
				else {
					fstream outF;
					outF.open("import_scoreboard.txt", ios::in);
					string tmp;
					Student* score = Cur_course->student;
					while (!outF.eof()) {
						getline(outF, tmp, ',');
						getline(outF, tmp, ',');
						getline(outF, tmp, ',');
						getline(outF, tmp, ',');
						getline(outF, tmp, ',');
						getline(outF, tmp, ',');
						getline(outF, tmp, ',');

						string get_final_score;
						getline(outF, get_final_score, ',');
						score->score.final_mark = stof(get_final_score);

						string get_mid_score;
						getline(outF, get_mid_score, ',');
						score->score.mid_mark = stof(get_mid_score);

						string get_other_score;
						getline(outF, get_other_score);
						score->score.other_mark = stof(get_other_score);

						if (score->score.mid_mark <= 10 && score->score.final_mark <= 10 && score->score.other_mark <= 10)
						{
							score->score.total_mark = (score->score.mid_mark + score->score.final_mark) / 2.0 + score->score.other_mark;
							score = score->pNext;
						}
						else {
							cout << "Course score entry failed!\n";
							yes = "0";
							remove("import_scoreboard.txt");
							break;
						}
					}
					outF.close();
					remove("import_scoreboard.txt");
				}
			} while (yes != "0");
		}
		else if (option == 1) {
			Semester* Cur_Semester = nullptr;
			string Semester;
			cout << "Enter Semester: "; cin >> Semester;
			Cur_Semester = pCur->semester;
			while (Cur_Semester->semester_name.compare(Semester) != 0) {
				Cur_Semester = Cur_Semester->pNext;
			}
			if (Cur_Semester->semester_name.compare(Semester) != 0) {
				cout << Cur_Semester->semester_name << " is not over yet\n";
				option = 1;
				continue;
			}
			if (Cur_Semester == nullptr) {
				option = 1;
				continue;
			}
			Course* Cur_course = nullptr;
			string Course;
			cout << "Enter Course: "; cin >> Course;
			Cur_course = Cur_Semester->course;
			while (Cur_course->id.compare(Course) != 0) {
				Cur_course = Cur_course->pNext;
			}
			if (Cur_course == nullptr) {
				option = 1;
				continue;
			}
			import_score_of_course(Cur_course);
		}
		else if (option == 2) {
			SchoolYear* current_schoolYear_print_score = currentSchoolYear(list_year);
			if (current_schoolYear_print_score != nullptr)
				view_scoreboard_toCourse(current_schoolYear_print_score);
		}
		cout << "Enter 0: =Get File ScoreBoard= \t Enter 1: =Enter by keyboard=\tEnter 2: = View Score = \t =Enter other. Quit=\n";
		cin >> option;
	}
}
