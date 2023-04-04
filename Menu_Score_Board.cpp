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
		while(Cur_course->course_name.compare(Course)!=0){
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
		import_score_of_course (Cur_course);
		Cur_course->check_course="O";	
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
	
	
