<<<<<<< HEAD
#include "imScore.h"
void load_student_InCourse(Student*& pHead, string schoolYear_name, string semester_name, string course_name)
{
	ifstream file;
	file.open(schoolYear_name + "\\" + semester_name + "\\" + course_name + ".txt");
	if (!file.is_open())
	{
		ifstream file;
		file.open(schoolYear_name + "\\" + semester_name + "\\" + course_name + ".txt",ios::app);	
	}
	Student* pCur = nullptr;
	pHead = new Student();
	pCur = pHead;
	string get_studentID;
	getline(file, get_studentID, ',');
	pCur->student_ID = std::stoi(get_studentID);
	getline(file, pCur->first_name, ',');
	getline(file, pCur->last_name,',');
	getline(file,pCur->gender,',');
	getline(file,pCur->date_of_birth,',');
	getline(file,pCur->social_ID,',');
	string get_score;
	getline(file,get_score,',');
	pCur->midMark=atof(get_score.c_str());
	getline(file,get_score,',');
	pCur->fMark=atof(get_score.c_str());
	getline(file,get_score,',');
	pCur->oMark=atof(get_score.c_str());
	getline(file,get_score,',');
	pCur->toMark=atof(get_score.c_str());
	getline(file,get_studentID);
	if(!file.eof()){
		pCur->pNext = new Student();	
		pCur = pCur->pNext;
		} 
	else{
		pCur->pNext =nullptr;	
		}
	while (!file.eof())
	{
		string get_studentID;
		getline(file, get_studentID, ',');
		pCur->student_ID = std::stoi(get_studentID);
		getline(file, pCur->first_name, ',');
		getline(file, pCur->last_name,',');
		getline(file,pCur->gender,',');
		getline(file,pCur->date_of_birth,',');
		getline(file,pCur->social_ID,',');
		string get_score;
		getline(file,get_score,',');
		pCur->midMark=atof(get_score.c_str());
		getline(file,get_score,',');
		pCur->fMark=atof(get_score.c_str());
		getline(file,get_score,',');
		pCur->oMark=atof(get_score.c_str());
		getline(file,get_score,',');
		pCur->toMark=atof(get_score.c_str());
		getline(file,get_studentID);
		if(!file.eof()){
		pCur->pNext = new Student();	
		pCur = pCur->pNext;
		} 
		else{
		pCur->pNext =nullptr;	
		}
	}
	file.close();
}
void load_course(Course*& pHead, string schoolYear_name, string semester_name)
{
	ifstream file;
	file.open(schoolYear_name +"\\"+semester_name+"\\courseList.txt");
	pHead=new Course();
	Course* pCur = nullptr;
	pCur=pHead;
	getline(file,pCur->id, ',');
	getline(file, pCur->course_name, ',');
	getline(file, pCur->class_name, ',');
	getline(file, pCur->teacher_name, ',');
	string get_numberCredit;
	getline(file, get_numberCredit, ',');
	pCur->number_credits = std::stoi(get_numberCredit);
	string get_numberStudent;
	getline(file, get_numberStudent, ',');
	pCur->number_students = std::stoi(get_numberStudent);
	getline(file, pCur->day_of_week, ',');
	getline(file, pCur->sessions, ',');
	getline(file,pCur->check_course,',');
	getline(file, get_numberCredit);
	if(!file.eof()){
		pCur->pNext = new Course();	
		pCur = pCur->pNext;
		} 
	else{
		pCur->pNext =nullptr;	
		}
	while (!file.eof())
	{
		getline(file,pCur->id, ',');
		getline(file, pCur->course_name, ',');
		getline(file, pCur->class_name, ',');
		getline(file, pCur->teacher_name, ',');
		string get_numberCredit;
		getline(file, get_numberCredit, ',');
		pCur->number_credits = std::stoi(get_numberCredit);
		string get_numberStudent;
		getline(file, get_numberStudent, ',');
		pCur->number_students = std::stoi(get_numberStudent);
		getline(file, pCur->day_of_week, ',');
		getline(file, pCur->sessions, ',');
		getline(file,pCur->check_course,',');
		getline(file, get_numberCredit);
		if(!file.eof()){
		pCur->pNext = new Course();	
		pCur = pCur->pNext;
		} 
		else{
		pCur->pNext =nullptr;	
		}
	}
	file.close();
}
void load_semester(Semester*& pHead, string schoolYear_name){
	ifstream file;
	file.open(schoolYear_name + "\\semesterList.txt");
	if (!file.is_open())
	{
		cout << "Khong mo duoc file semesterList.txt";
		return;
	}
	Semester* pCur = nullptr;
	pHead=new Semester();
	pCur=pHead;
	getline(file,pCur->semester_name,',');
	getline(file,pCur->check_semester,',');
	string tmp;
	getline(file,tmp);
	if (!file.eof())
	{
		pCur->pNext = new Semester();	
		pCur=pCur->pNext; 	
		}
	else
		{
		pCur->pNext=nullptr;
		}
	while (!file.eof())
	{
		getline(file,pCur->semester_name,',');
		getline(file,pCur->check_semester,',');
		getline(file,tmp);
		if (!file.eof())
		{
		pCur->pNext = new Semester();	
		pCur=pCur->pNext; 	
		}
		else
		{
		pCur->pNext=nullptr;
		}
	} 
	file.close();
}
void load_schoolYear(SchoolYear*& pHead)
{
	ifstream file;
	file.open("schoolYearList.txt");
	if (!file.is_open())
	{
		cout << "Khong mo duoc file schoolYearList.txt";
		return;
	};
	SchoolYear* pCur = nullptr;
	while (!file.eof())
	{
		if (pHead == nullptr)
		{
			pHead = new SchoolYear();
			pCur=pHead;
		}
		else
		{
			pCur = new SchoolYear();
		}
		file >> pCur->year_name;
		pCur->pNext =nullptr;
		pCur = pCur->pNext;
	}
	file.close();
}
bool check_pass_Semester(Semester* & pHead_semester){
	Course* currCourse=pHead_semester->course;
	while(currCourse!=NULL){
		if(currCourse->check_course!="O") return false;  
		currCourse=currCourse->pNext;
	}		
	return true; 
}
void load_input(SchoolYear*& pHead_schoolYear){
	pHead_schoolYear = nullptr;
	load_schoolYear(pHead_schoolYear);
	SchoolYear* pCur = nullptr;
	pCur=pHead_schoolYear;
	while (pCur != nullptr)
	{
		Semester* pHead_Semester=nullptr;
		load_semester(pHead_Semester, pCur->year_name);
		pCur->semester=pHead_Semester;
		Semester* currSemester=pCur->semester;
		while(currSemester!=nullptr){
		Course* pHead_Course=nullptr;	
		load_course(pHead_Course, pCur->year_name, currSemester->semester_name);
		currSemester->course=pHead_Course;
		Course* currCourse=currSemester->course;
		while(currCourse!=nullptr){
		Student* pHead_Student = nullptr;
		load_student_InCourse(pHead_Student, pCur->year_name, currSemester->semester_name, currCourse->id);
		currCourse->student=pHead_Student;
		currCourse=currCourse->pNext;
		}
		currSemester=currSemester->pNext;
		}
		pCur = pCur->pNext;
	}
=======
#include "lib.h"
void import_score_of_course (Course *&z)
{
    cout << "Course information: " << endl;
    cout << z->id << "  " << z->course_name << endl;
    cout << z->class_name << endl;
    cout << "Now we import score for each students : " << endl << endl;
    Student *s = z->student; // from now just use branch Student of this Course
    while (s != nullptr) {
        cout << "Student id: " << s->student_ID << "\t" << s->last_name << " " << s->first_name << endl;
        cout << "Midterm mark:"; cin >> s->score.mid_mark;
        cout << "Final mark:"; cin >> s->score.final_mark;
        cout << "Other mark:"; cin >> s->score.other_mark;

        // just assume the logic math calculate, staff can fix it
        s->score.total_mark = (s->score.final_mark*2 + s->score.mid_mark) / 3 + s->score.other_mark;
        cout << "Total mark is: " << s->score.total_mark;
        s = s->pNext;
    }
>>>>>>> 9e9c6cd01ffd683805f975e040d58497fc298825
}
void view_scoreboard_toCourse(SchoolYear* &list_year,string year){
	SchoolYear* pCur= NULL;
	pCur= list_year;
	while(pCur!=nullptr){
		if(pCur->year_name.compare(year)==0){
			break;
		}
		pCur=pCur->pNext;
		}
		Semester* Cur_Semester=nullptr;
		string Semester;
		cout<<"Enter Semester: "; cin>>Semester;
		Cur_Semester=pCur->semester;
		while(Cur_Semester->semester_name.compare(Semester)!=0&&check_pass_Semester(Cur_Semester)){
			Cur_Semester=Cur_Semester->pNext;
		}
		if (Cur_Semester->semester_name.compare(Semester)!=0){
				cout<<Cur_Semester->semester_name<<" is not over yet\n";
				return; 
		}
		Course* Cur_course=nullptr;
		string Course;
		cout<<"Enter Course: "; cin>>Course;
		Cur_course=Cur_Semester->course;
		bool flag=false;
<<<<<<< HEAD
		while(Cur_course->course_name.compare(Course)!=0&&){
=======
		while(Cur_course->course_name.compare(Course)!=0){
>>>>>>> 9e9c6cd01ffd683805f975e040d58497fc298825
				Cur_course=Cur_course->pNext;
				if(Cur_course==nullptr){
					flag=true;
					break;
				}
		}
		if(flag){
			return;
		}
		Student* studentF=nullptr;
		studentF=Cur_course->student;
		cout<<setw(12)<<left<<"ID"<<setw(16)<<left<<"Name"<<setw(16)<<left<<"Middle Score"<<setw(15)<<left<<"Final Score"<<setw(15)<<left<<"Other Score\tTotal Score\n";
		cout<<setfill('-');
		cout<<setw(80)<<'-'<<endl;
		cout << setfill(' ');
		while(studentF!=nullptr){
			cout<<setw(12)<<left<<studentF->student_ID<<setw(8)<<left<<studentF->first_name<<setw(10)<<left<<studentF->last_name<<setw(15)<<left<<studentF->midMark<<setw(15)<<left<<studentF->fMark<<setw(15)<<left<<studentF->oMark<<setw(15)<<left<<studentF->toMark<<endl;
			studentF=studentF->pNext;
		}
}
void import_scoreboard_toCourse(SchoolYear* &list_year,string year){
	int option;
	cout<<"Enter 0: =Get File ScoreBoard= \t Enter 1: =Enter by keyboard=\tEnter 2: = View Score = \t =Enter other. Quit=\n";
	cin>>option;
	while(option==0||option==1||option==2)	{
		SchoolYear* pCur= NULL;
		pCur=list_year;
		string yes;
		if (option==0){
			do{
			while(pCur!=nullptr){
			if(pCur->year_name.compare(year)==0){
			break;
			}
			pCur=pCur->pNext;
			}
			Semester* Cur_Semester=nullptr;
			string Semester;
			cout<<"Enter Semester: "; cin>>Semester;
			Cur_Semester=pCur->semester;
			bool flag=false;
			while(Cur_Semester->semester_name.compare(Semester)!=0&&check_pass_Semester(Cur_Semester)){
				Cur_Semester=Cur_Semester->pNext;
				if(Cur_Semester==nullptr){
				flag=true;
				break;
			}
			}
			if(flag){
				break;
			}
			if (Cur_Semester->semester_name.compare(Semester)!=0){
				cout<<Cur_Semester->semester_name<<" is not over yet\n";
				option=0;
				continue;
			}
			Course* Cur_course=nullptr;
			string Course;
			cout<<"Enter Course: "; cin>>Course;
			Cur_course=Cur_Semester->course;
			while(Cur_course->course_name.compare(Course)!=0){
				Cur_course=Cur_course->pNext;
				if(Cur_course==nullptr){
					flag=true;
					break;
			}
			}
			if(flag){
				break;
			}
			fstream F;
			F.open("import_scoreboard.txt",ios::app);
			Student* studentF=nullptr;
			studentF=Cur_course->student;
			while(studentF!=nullptr){
			F<<studentF->student_ID<<","<<studentF->first_name<<","<<studentF->last_name<<",x,x,x,";
			if(studentF->pNext!=nullptr) F<<"\n";
			studentF=studentF->pNext;
			}
			F.close();
			cout<<"Created a file containing the information of the course: "<<pCur->semester->course->course_name<<" , Please enter your score into the file (enter 0 = agree): ";
			cin>>yes;
			if(yes!="0") remove("import_scoreboard.txt");
			else{
			fstream outF;
			outF.open("import_scoreboard.txt",ios::in);
			string tmp;
			Student* score=Cur_course->student;
			while(!outF.eof()){
			getline(outF,tmp,',');
			getline(outF,tmp,',');
			getline(outF,tmp,',');
			string get_mid_score;
			getline(outF,get_mid_score,',');
			score->midMark= atof(get_mid_score.c_str());
			string get_final_score;	
			getline(outF,get_final_score,',');
			score->fMark=atof(get_final_score.c_str());
			string get_other_score;
			getline(outF,get_other_score,',');
			score->oMark=atof(get_other_score.c_str());
			getline(outF,tmp);
			if(score->oMark<=10&&score->midMark<=10&&score->fMark<=10){
				score->toMark=(score->fMark+score->midMark)/2.0+score->oMark;
				score=score->pNext;
				Cur_course->check_course="O";
			}
			else{
				cout<<"Course score entry failed!\n";
				yes="0";
				remove("import_scoreboard.txt");
				break;
			}
			}
			outF.close();
			remove("import_scoreboard.txt");
			}
			}
		while(yes!="0");
	}
	else if(option==1){
		while(pCur!=nullptr){
		if(pCur->year_name.compare(year)==0){
			break;
			}
			pCur=pCur->pNext;
			}
			Semester* Cur_Semester=nullptr;
			string Semester;
			cout<<"Enter Semester: "; cin>>Semester;
			Cur_Semester=pCur->semester;
			while(Cur_Semester->semester_name.compare(Semester)!=0&&check_pass_Semester(Cur_Semester)){
				Cur_Semester=Cur_Semester->pNext;
			}
			if (Cur_Semester->semester_name.compare(Semester)!=0){
				cout<<Cur_Semester->semester_name<<" is not over yet\n";
				option=1;
				continue;
			}
			if(Cur_Semester==nullptr){
				option=1;
				continue;
			}
			Course* Cur_course=nullptr;
			string Course;
			cout<<"Enter Course: "; cin>>Course;
			Cur_course=Cur_Semester->course;
			while(Cur_course->course_name.compare(Course)!=0){
				Cur_course=Cur_course->pNext;
			}
			if(Cur_course==nullptr){
				option=1;
				continue;
			}
<<<<<<< HEAD
		Student* studentF=nullptr;
		studentF=Cur_course->student;
		while(studentF!=nullptr){
			cout<<"ID: "<<studentF->student_ID<<" Name: "<<studentF->first_name<<" "<<studentF->last_name<<" \n";
			cout<<"Enter Middle Score: "; cin>>studentF->midMark;
			cout<<"Enter Final Score: "; cin>>studentF->fMark;
			cout<<"Enter other Score: "; cin>>studentF->oMark;
			studentF->toMark =(studentF->fMark+studentF->midMark)/2.0+studentF->oMark;
			studentF=studentF->pNext;
		}
=======
		import_score_of_course (Cur_course);
>>>>>>> 9e9c6cd01ffd683805f975e040d58497fc298825
		Cur_course->check_course="O";	
	}
	else if(option==2){
		 view_scoreboard_toCourse(list_year,year);
	}
	cout<<"Enter 0: =Get File ScoreBoard= \t Enter 1: =Enter by keyboard=\tEnter 2: = View Score = \t =Enter other. Quit=\n";
	cin>>option;
	}
}
void print_student_InCourse(Student* pHead, string schoolYear_name, string semester_name, string course_id)
{
	ofstream file;
	file.open(schoolYear_name + "\\" + semester_name + "\\" + course_id + ".txt");
	while (pHead != nullptr)
	{
		file << pHead->student_ID << ","
			<< pHead->first_name << ","
			<< pHead->last_name << ","
			<< pHead->gender << ","
			<< pHead->date_of_birth << ","
			<< pHead->social_ID << ","
			<< pHead->midMark << ","
			<< pHead->fMark << ","
			<< pHead->oMark << ","
			<< pHead->toMark<<",";
			if(pHead->pNext!=nullptr){
				file<<"\n";
			}
		pHead = pHead->pNext;
	}
	file.close();
}
void print_course(Course* pHead, string schoolYear_name, string semester_name)
{
	ofstream file;
	file.open(schoolYear_name + "\\" + semester_name + "\\" + "courseList.txt");
	while (pHead != nullptr)
	{
		file
			<< pHead->id << ","
			<< pHead->course_name << ","
			<< pHead->class_name << ","
			<< pHead->teacher_name << ","
			<< pHead->number_credits << ","
			<< pHead->number_students << ","
			<< pHead->day_of_week << ","
			<< pHead->sessions<<","
			<<pHead->check_course<<",";
			if(pHead->pNext!=nullptr){
				file<<"\n";
			}
	pHead = pHead->pNext;
	}
	file.close();
}
void print_Semester(Semester* pHead_Semester, string schoolYear_name)
{
	ofstream file;
	file.open(schoolYear_name + "\\" + "semesterList.txt");
	while (pHead_Semester != nullptr)
	{
		file << pHead_Semester->semester_name<<","<<pHead_Semester->check_semester<<",";
		if(pHead_Semester->pNext!=nullptr){
			file<<"\n";
		}
		pHead_Semester=pHead_Semester->pNext;
	}
	file.close();
}

void print_output(SchoolYear* pHead_schoolYear)
{
	////-------------------------------------------PRINTTT TO FILE------------------------------------------
	//Print schoolYear to schoolYearList.txt

	ofstream file;
	file.open("schoolYearlist.txt");
	SchoolYear* pTemp1 = pHead_schoolYear;
	while (pHead_schoolYear != nullptr)
	{
		if (pHead_schoolYear->pNext != nullptr)
			file << pHead_schoolYear->year_name << endl;
		else
			file << pHead_schoolYear->year_name;
		pHead_schoolYear = pHead_schoolYear->pNext;
	}
	file.close();
	pHead_schoolYear = pTemp1;
	while (pHead_schoolYear != nullptr)
	{
		Semester* pCur_semester = pHead_schoolYear->semester;
		print_Semester(pCur_semester, pHead_schoolYear->year_name);
		while (pCur_semester != nullptr)
		{
			Course* pCur_course = pCur_semester->course;
			print_course(pCur_course, pHead_schoolYear->year_name, pCur_semester->semester_name);
			while (pCur_course != nullptr)
			{
				Student* pCur_student = pCur_course->student;
				print_student_InCourse(pCur_student, pHead_schoolYear->year_name, pCur_semester->semester_name, pCur_course->id);
				pCur_course = pCur_course->pNext;
			}
			pCur_semester = pCur_semester->pNext;
		}
		pHead_schoolYear = pHead_schoolYear->pNext;
	}
	file.close();
	}
int main(){
	SchoolYear * head;
	Class* clas;
	load_input(head);
	string year;
	cin>>year;
	import_scoreboard_toCourse(head,year);
	print_output(head);
	return 0;
}


	
