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
	while (!file.eof())
	{
		string get_studentID;
		getline(file, get_studentID, ',');
		pCur->student_ID = std::stoi(get_studentID);
		getline(file, pCur->first_name, ',');
		getline(file, pCur->last_name,',');
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
	while (!file.eof())
	{
		getline(file,pCur->semester_name,',');
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
		while(Cur_Semester->semester_name.compare(Semester)!=0){
			Cur_Semester=Cur_Semester->pNext;
		}
		Course* Cur_course=nullptr;
		string Course;
		cout<<"Enter Course: "; cin>>Course;
		Cur_course=Cur_Semester->course;
			while(Cur_course->course_name.compare(Course)!=0){
				Cur_course=Cur_course->pNext;
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
void Menu_Score_Board(SchoolYear* &list_year,string year){
	int option;
	cout<<"Enter 0: =Get File ScoreBoard= \t Enter 1: =Enter by keyboard=\tEnter 2: = View Score = \t =Enter other. Quit=\n";
	cin>>option;
	while(option==0||option==1||option==2)	{
		SchoolYear* pCur= NULL;
		pCur=list_year;
		if (option==0){
			string yes;
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
			while(Cur_Semester->semester_name.compare(Semester)!=0){
				Cur_Semester=Cur_Semester->pNext;
			}
			Course* Cur_course=nullptr;
			string Course;
			cout<<"Enter Course: "; cin>>Course;
			Cur_course=Cur_Semester->course;
			while(Cur_course->course_name.compare(Course)!=0){
				Cur_course=Cur_course->pNext;
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
			}
			else{
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
			while(Cur_Semester->semester_name.compare(Semester)!=0){
				Cur_Semester=Cur_Semester->pNext;
			}
			Course* Cur_course=nullptr;
			string Course;
			cout<<"Enter Course: "; cin>>Course;
			Cur_course=Cur_Semester->course;
			while(Cur_course->course_name.compare(Course)!=0){
				Cur_course=Cur_course->pNext;
			}
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
	}
	else if(option==2){
		view_scoreboard_toCourse(list_year,year);
	}
	cout<<"Enter 0: =Get File ScoreBoard= \t Enter 1: =Enter by keyboard=\tEnter 2: = View Score = \t =Enter other. Quit=\n";
	cin>>option;
	}
}
int main(){
	SchoolYear * head;
	Class* clas;
	load_input(head);
	string year;
	cin>>year;
	import_scoreboard_toCourse(head,year);
	view_scoreboard_toCourse(head,year);
	return 0;
}
	
	
