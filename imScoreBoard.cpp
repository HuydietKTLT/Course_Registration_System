#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Student {
	string No;
	string ID;
	string FName;
	string LName;
	string gender;
	string date_of_birth;
	string social_ID;
	double fMark;
	double midMark;
	double oMark;
	double toMark;
	Student* pNext;
	
};
void import_scoreboard_toCourse(Student* &pHead){
	string schoolYear;
	cout<<"Enter School Year: ";
	cin>>schoolYear;
	string semester;
	cout<<"Enter Semester: "; 
	cin>>semester;
	string course;
	cout<<"Enter Course: ";
	cin>>course;
	string file=schoolYear+"/"+semester+"/"+course+".txt";
	string scoreboard="scoreboard/"+file;
	fstream inF;
	inF.open(file,ios::in);
	if(inF.fail()){
		cout<<"FiLe does not exist!";
	}
	else{
		cout<<"Enter 0: =Get File ScoreBoard= \t Enter 1: =Edit ScoreBoard=\n";
		int option;
		cin>>option;
		if(option==0){
			fstream F;
			F.open("import_scoreboard.txt",ios::app);
			while(!inF.eof()){
				string s;
				getline(inF,s);
				if(inF.eof()) 	F<<s<<" "<<0<<" "<<0<<" "<<0<<" "<<0;
				else	F<<s<<" "<<0<<" "<<0<<" "<<0<<" "<<0<<"\n";		
			}
			F.close();
			string done="no";
			while(done!="yes") {
				cout<<"Enter yes to Done!\n";
				cin>>done;
			}
			fstream iF;
			iF.open("import_scoreboard.txt",ios::in);
			pHead=new Student();		
			Student* pCur1=new Student();
			pHead=pCur1;
			string s;
			getline(iF,s,',');
			pCur1->No=s;
			getline(iF,s,',');
			pCur1->ID=s;
			getline(iF,s,',');
			pCur1->FName=s;
			getline(iF,s,',');
			pCur1->LName=s;
			getline(iF,s,',');
			pCur1->gender=s;
			getline(iF,s,',');
			pCur1->date_of_birth=s;
			getline(iF,s,',');
			pCur1->social_ID=s;
			double t;
			iF>>t;
			pCur1->midMark=t;
			iF>>t;
			pCur1->fMark=t;
			iF>>t;
			pCur1->oMark=t;
			pCur1->toMark=(pCur1->fMark+pCur1->midMark)/2.0+pCur1->oMark;
			getline(iF,s);
			pCur1->pNext=new Student();
			pHead=pCur1;
			pCur1=pCur1->pNext;
		while(!iF.eof()){
			string s;
			getline(iF,s,',');
			pCur1->No=s;
			getline(iF,s,',');
			pCur1->ID=s;
			getline(iF,s,',');
			pCur1->FName=s;
			getline(iF,s,',');
			pCur1->LName=s;
			getline(iF,s,',');
			pCur1->gender=s;
			getline(iF,s,',');
			pCur1->date_of_birth=s;
			getline(iF,s,',');
			pCur1->social_ID=s;
			double t;
			iF>>t;
			pCur1->midMark=t;
			iF>>t;
			pCur1->fMark=t;
			iF>>t;
			pCur1->oMark=t;
			pCur1->toMark=(pCur1->fMark+pCur1->midMark)/2.0+pCur1->oMark;
			getline(iF,s);
			pCur1->pNext=new Student();
			pCur1=pCur1->pNext;
		}
		pCur1=NULL;
		fstream enterF;
		enterF.open(scoreboard,ios::out|ios::trunc);
		Student* pCur2=new Student();
		pCur2=pHead;
		while(pCur2!=NULL&&pCur2->No!=""){
		enterF<<pCur2->No<<","<<pCur2->ID<<","<<pCur2->FName<<","<<pCur2->LName<<","<<pCur2->gender<<","<<pCur2->date_of_birth<<","<<pCur2->social_ID<<","<<pCur2->midMark<<" "<<pCur2->fMark<<" "<<pCur2->oMark<<" "<<pCur2->toMark;	
		if(pCur2->pNext!=NULL) enterF<<"\n";
		pCur2=pCur2->pNext;
		}
		}
		if (option==1){
			fstream outF;
			outF.open(scoreboard,ios::in);
			if(!outF.fail()){
				inF.close();
				outF.close();
			}
			else{
			fstream newF;
			newF.open(scoreboard,ios::app);
			while(!inF.eof()){
				string s;
				getline(inF,s);
				if(inF.eof()) 	newF<<s<<" "<<0<<" "<<0<<" "<<0<<" "<<0;
				else	newF<<s<<" "<<0<<" "<<0<<" "<<0<<" "<<0<<"\n";		
			}
			newF.close();
			inF.close();
			outF.close();	
			}
			fstream inF;
			inF.open(scoreboard,ios::in);
			pHead=new Student();		
			Student* pCur=new Student();
			pHead=pCur;
			string s;
			getline(inF,s,',');
			pCur->No=s;
			getline(inF,s,',');
			pCur->ID=s;
			getline(inF,s,',');
			pCur->FName=s;
			getline(inF,s,',');
			pCur->LName=s;
			getline(inF,s,',');
			pCur->gender=s;
			getline(inF,s,',');
			pCur->date_of_birth=s;
			getline(inF,s,',');
			pCur->social_ID=s;
			double t;
			inF>>t;
			pCur->midMark=t;
			inF>>t;
			pCur->fMark=t;
			inF>>t;
			pCur->oMark=t;
			inF>>t;
			pCur->toMark=t;
			getline(inF,s);
			pCur->pNext=new Student();
			pHead=pCur;
			pCur=pCur->pNext;
		while(!inF.eof()){
			string s;
			getline(inF,s,',');
			pCur->No=s;
			getline(inF,s,',');
			pCur->ID=s;
			getline(inF,s,',');
			pCur->FName=s;
			getline(inF,s,',');
			pCur->LName=s;
			getline(inF,s,',');
			pCur->gender=s;
			getline(inF,s,',');
			pCur->date_of_birth=s;
			getline(inF,s,',');
			pCur->social_ID=s;
			double t;
			inF>>t;
			pCur->midMark=t;
			inF>>t;
			pCur->fMark=t;
			inF>>t;
			pCur->oMark=t;
			inF>>t;
			pCur->toMark=t;
			getline(inF,s);
			pCur->pNext=new Student();
			pCur=pCur->pNext;
		}
		pCur=NULL;
		inF.close();
	string ID="1";	
	while(ID!="0"){
	cout<<"Enter ID student to edit:";
	cin>>ID;	
	Student* pCur3=new Student();
	pCur3=pHead;
	while(pCur3!=NULL&&pCur3->No!=""){
		if(ID==pCur3->ID){
		cout<<pCur3->No<<","<<pCur3->ID<<","<<pCur3->FName<<" "<<pCur3->LName<<","<<pCur3->gender<<","<<pCur3->date_of_birth<<","<<pCur3->midMark<<","<<pCur3->fMark<<","<<pCur3->oMark<<","<<pCur3->toMark<<"\n";
		cout<<"Course grades are not available: ";
		if(pCur3->midMark==0) cout<<"=Middle Mark=\t";
		if(pCur3->fMark==0) cout<<"=Final Mark=\t"; 
		if(pCur3->oMark==0) cout<<"=Other Mark=\n"; 
		if(pCur3->toMark!=0) cout<<"Scores are full!!\n";
		cout<<"\tAre you edit course mark ?\n \t1.Middle Mark\t2.Final Mark\t3.Other Mark\t 4.Skip\n";
		int choose;
		string get;
		cin>>choose;
		while(choose==1||choose==2||choose==3){
		switch(choose){
			case 1: 
			cout<<"Enter Middle Mark: ";
			cin>>pCur3->midMark;
			break;
			case 2:
			cout<<"Enter Final Mark: "; 
			cin>>pCur3->fMark;
			break;
			case 3:
			cout<<"Enter Other Mark: "; 
			cin>>pCur3->oMark;	
			break;
			default: cout<<"\n"; break;			
		}
		if(pCur3->midMark!=0&&pCur3->fMark!=0&&pCur3->oMark!=0) {
			pCur3->toMark=(pCur3->fMark+pCur3->midMark)/2.0+pCur3->oMark;
		}
		cout<<"Course grades are not available: ";
		if(pCur3->midMark==0) cout<<"=Middle Mark=\t"; 
		if(pCur3->fMark==0) cout<<"=Final Mark=\t"; 
		if(pCur3->oMark==0) cout<<"=Other Mark=\n"; 
		cout<<"\tAre you enter course mark ?\n \t1.Middle Mark\t2.Final Mark\t3.Other Mark\t 4.Skip\n";
		cin>>choose;
		}
		}
		pCur3=pCur3->pNext;
		cout<<"press 'yes' to stop enter course mark, otherwise press another!\n";
		string end;
		cin>>end;
		if(end=="yes") break;	
	}
	}
	fstream enterF;
	enterF.open(scoreboard,ios::out|ios::trunc);
	Student* pCur1=new Student();
	pCur1=pHead;
	while(pCur1!=NULL&&pCur1->No!=""){
	enterF<<pCur1->No<<","<<pCur1->ID<<","<<pCur1->FName<<","<<pCur1->LName<<","<<pCur1->gender<<","<<pCur1->date_of_birth<<","<<pCur1->social_ID<<","<<pCur1->midMark<<" "<<pCur1->fMark<<" "<<pCur1->oMark<<" "<<pCur1->toMark;	
	if(pCur1->pNext!=NULL) enterF<<"\n";
	pCur1=pCur1->pNext;
	}
	enterF.close();
	}
}
}
void view_scoreboard_toCourse(Student*&pHead){
	string schoolYear;
	cout<<"Enter School Year: ";
	cin>>schoolYear;
	string semester;
	cout<<"Enter Semester: "; 
	cin>>semester;
	string course;
	cout<<"Enter Course: ";
	cin>>course;
	string scoreboard="scoreboard/"+schoolYear+"/"+semester+"/"+course+".txt";
	fstream inF;
	inF.open(scoreboard,ios::in);
	if(inF.fail()){
		cout<<"Course does not exist!";
	}
	else{
			pHead=new Student();		
			Student* pCur=new Student();
			pHead=pCur;
			string s;
			getline(inF,s,',');
			pCur->No=s;
			getline(inF,s,',');
			pCur->ID=s;
			getline(inF,s,',');
			pCur->FName=s;
			getline(inF,s,',');
			pCur->LName=s;
			getline(inF,s,',');
			pCur->gender=s;
			getline(inF,s,',');
			pCur->date_of_birth=s;
			getline(inF,s,',');
			pCur->social_ID=s;
			double t;
			inF>>t;
			pCur->midMark=t;
			inF>>t;
			pCur->fMark=t;
			inF>>t;
			pCur->oMark=t;
			inF>>t;
			pCur->toMark=t;
			getline(inF,s);
			pCur->pNext=new Student();
			pHead=pCur;
			pCur=pCur->pNext;
		while(!inF.eof()){
			string s;
			getline(inF,s,',');
			pCur->No=s;
			getline(inF,s,',');
			pCur->ID=s;
			getline(inF,s,',');
			pCur->FName=s;
			getline(inF,s,',');
			pCur->LName=s;
			getline(inF,s,',');
			pCur->gender=s;
			getline(inF,s,',');
			pCur->date_of_birth=s;
			getline(inF,s,',');
			pCur->social_ID=s;
			double t;
			inF>>t;
			pCur->midMark=t;
			inF>>t;
			pCur->fMark=t;
			inF>>t;
			pCur->oMark=t;
			inF>>t;
			pCur->toMark=t;
			getline(inF,s);
			pCur->pNext=new Student();
			pCur=pCur->pNext;
		}
		pCur=NULL;
		while(pHead->pNext!=NULL&&pHead->No!=""){
				cout<<pHead->No<<","<<pHead->ID<<","<<pHead->FName<<" "<<pHead->LName<<","<<pHead->gender<<","<<pHead->date_of_birth<<","<<pHead->midMark<<","<<pHead->fMark<<","<<pHead->oMark<<","<<pHead->toMark<<"\n";
				pHead=pHead->pNext;
				}	
		}
	}	
int main(){
	Student* head;
	import_scoreboard_toCourse(head);
	view_scoreboard_toCourse(head);
	return 0;
}
	
