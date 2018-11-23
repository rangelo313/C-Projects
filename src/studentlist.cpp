#include <iostream>
using namespace std;
#include "studentlist.h"

double HistoryStudent::Compute()
{
	int term, mid, finale;
	term = (termpaper / 100.0) * 25;
	mid = (midterm / 100.0) * 35;
	finale =(finalexam / 100.0) * 40; 
	finalgrade = ((finale + term + mid) / 100.0) * 100;

	if (finalgrade >= 89.5)
		letter = 'A';
	else if (finalgrade >= 79.5 && finalgrade < 89.5)
		letter = 'B';
	else if (finalgrade >= 69.5 && finalgrade < 79.5)
		letter = 'C';
	else if (finalgrade >= 59.5 && finalgrade < 69.5)
		letter = 'D';
	else
		letter = 'F';
	

	return finalgrade;
}

double EnglishStudent::Compute()
{

	double att, proj, midt, finale;
	att = (attendance / 100.0) * 10; // 9
	proj = (project / 100.0) * 30;// 27
	midt = (midterm / 100.0) * 30; //27
	finale = (finalexam / 100.0) * 30; // 27
	finalgrade = ((finale + midt + proj + att) / 100.0) * 100;

	if (finalgrade >= 89.5 && finalgrade <= 100)
		letter = 'A';
	else if (finalgrade >= 79.5 && finalgrade < 89.5)
		letter = 'B';
	else if (finalgrade >= 69.5 && finalgrade < 79.5)
		letter = 'C';
	else if (finalgrade >= 59.5 && finalgrade < 69.5)
		letter = 'D';
	else
		letter = 'F';
	return finalgrade;
}

double MathStudent::Compute()
{
	double quizaverage = ((q1 + q2 + q3 + q4 + q5) / 500.0) * 100; 
	quizaverage = (quizaverage/100.0) * 15; 
	int testone, testtwo, finale;
	testone = (test1 / 100.0) * 25;
	testtwo = (test2 / 100.0) * 25;
	finale = (finalexam / 100.0) * 35; 
	finalgrade = ((quizaverage + testone + testtwo + finale) / 100.0) * 100;
	if (finalgrade >= 89.5)
		letter = 'A';
	else if (finalgrade >= 79.5 && finalgrade < 89.5)
		letter = 'B';
	else if (finalgrade >= 69.5 && finalgrade < 79.5)
		letter = 'C';
	else if (finalgrade >= 59.5 && finalgrade < 69.5)
		letter = 'D';
	else 
		letter = 'F';
	return finalgrade;
}
StudentList::StudentList() 
{
	size = 0;	
}
StudentList::~StudentList()
{ 
	delete[]students;
}
bool StudentList::ImportFile(const char* filename)
{
	int grades[10]; 
	const char space = ' ';
	const char newline = '\n';
	int Newsize;
	string firstname;
	string lastname;
	string naem, thing;
	ifstream in;
	int counter = 0;
	in.open(filename);
	if (!in)
	{
		cout << "Invalid file. No data imported. " << endl;
		return false;
	}

	in >> Newsize; //4

	if (Newsize > 0) //grow
	{
		StudentClass **NewStudentClass = new StudentClass*[size + Newsize];
		for (int i = 0; i < size; i++)
		{
			NewStudentClass[i] = students[i];
		}
		if (size>0)
			delete[]students;
		students = NewStudentClass;
	}

	//StudentClass** ptr = new StudentClass*[Newsize];
	getline(in, thing, '\n');
	do {
		
		getline(in, lastname, ',');
		getline(in, naem, ' ');
		getline(in, firstname); 
		getline(in, naem, ' '); //Math 
		
		if (naem == "Math")
		{
			for (int i = 0; i < 7; i++)
			{
				getline(in, naem, ' ');

				grades[i] = stoi(naem);
			}
			getline(in, naem, '\n');
			grades[7] = stoi(naem);
			
			students[counter] = new MathStudent(lastname, firstname, grades[0], grades[1], grades[2], grades[3], grades[4], grades[5], grades[6], grades[7]);
		}
		if (naem == "History")
		{
			for (int i = 0; i < 2; i++) //3 grades 0...1...2
			{
				getline(in, naem, ' ');
				grades[i] = stoi(naem);
			}
			getline(in, naem, '\n');
			grades[2] = stoi(naem);
			students[counter] = new HistoryStudent(lastname, firstname, grades[0], grades[1], grades[2]);
		}
		if (naem == "English")
		{
			for (int i = 0; i < 3; i++) //3 grades
			{
				getline(in, naem, ' ');
				grades[i] = stoi(naem);
			}
			getline(in, naem, '\n');
			grades[3] = stoi(naem);
			students[counter] = new EnglishStudent(lastname, firstname, grades[0], grades[1], grades[2], grades[3]);
		}
		counter++;
	} while (counter < Newsize); //4
	
	size += Newsize;
	in.close();
	return true;
}
StudentClass::StudentClass()
{
	
}
StudentClass::StudentClass(string l, string f, string cs, int fexam)
{
	firstname = f;       
	lastname = l;    
	course = cs;
	finalexam = stoi(f);
}

bool StudentList::CreateReportFile(const char* filename)
{
	ofstream f;
	f.open(filename);

	f << "Student Grade Summary" << endl << "---------------------" << endl << endl;
	f << "English CLASS" << endl << endl;
	f << "Student                                   Final Final   Letter" << endl;
	f << "Name                                      Exam  Avg     Grade" << endl;
	f << "----------------------------------------------------------------------" << endl;
	for (int i = 0; i < size; i++)
	{
		if (students[i]->getCourse() == "English")
		{
			string name = students[i]->getLastName();
			name += " ";
			name += students[i]->getFirstName();
			f << setw(20) << left << name << "                      "
				<< setw(5) << students[i]->getFinalexam();
			f << setw(5) << setprecision(2) << fixed << students[i]->Compute() <<
				"    " << students[i]->getLetterGrade() << endl;
		}
	}

	f << endl << "HISTORY CLASS" << endl << endl;

	f << "Student                                   Final Final   Letter" << endl;
	f << "Name                                      Exam  Avg     Grade" << endl;
	f << "----------------------------------------------------------------------" << endl;
	for (int i = 0; i < size; i++)
	{
		if (students[i]->getCourse() == "History")
		{
			string name = students[i]->getLastName();
			name += " ";
			name += students[i]->getFirstName();
			f << setw(20) << left << name << "                      "
				<< setw(6) << students[i]->getFinalexam()
				<< setw(6) << setprecision(2) << fixed << students[i]->Compute() <<
				"  " << students[i]->getLetterGrade() << endl;

		}
	}
	f << endl << "MATH CLASS" << endl << endl;
	f << "Student                                   Final Final   Letter" << endl;
	f << "Name                                      Exam  Avg     Grade" << endl;
	f << "----------------------------------------------------------------------" << endl;
	for (int i = 0; i < size; i++)
	{
		if (students[i]->getCourse() == "Math")
		{
			string name = students[i]->getLastName();
			name += " ";
			name += students[i]->getFirstName();
			f << setw(20) << left << name << "                      "
				<< setw(5) << students[i]->getFinalexam()
				<< setw(5) << setprecision(2) << fixed << students[i]->Compute() <<
				"    " << students[i]->getLetterGrade() << endl;
		}
	}

	f << '\n' << "OVERALL GRADE DISTRIBUTION" << endl << endl;
	int a1 = 0, b2 = 0, c3 = 0, d4 = 0, f5 = 0;
	for (int i = 0; i < size; i++)
	{
		if (students[i]->getLetterGrade() == 'A')
			a1++;
		if (students[i]->getLetterGrade() == 'B')
			b2++;
		if (students[i]->getLetterGrade() == 'C')
			c3++;
		if (students[i]->getLetterGrade() == 'D')
			d4++;
		if (students[i]->getLetterGrade() == 'F')
			f5++;
	}
		f << "A:" << "   " <<  a1 << endl;
		f << "B:" << "   " << b2 << endl;
		f << "C:" << "   " <<  c3 << endl;
		f << "D:" << "   " << d4 << endl;
		f << "F:" << "   " << f5 << endl;
		f.close();
	return true;
}
	
void StudentList::ShowList() const
{
	const char space = ' ';
	cout << "Last                 First                    Course" << endl << endl;
	for (int i = 0; i < size; i++)
	{
		//cout << students[i]->getLastName() << "                " << students[i]->getFirstName() << "                " << students[i]->getCourse() << endl;
		cout << setw(20) << left << students[i]->getLastName() << " " << setw(20) << left << students[i]->getFirstName()
		<< "     " << setw(20) << left << students[i]->getCourse() << endl;
	}

} 
MathStudent::MathStudent(string last, string first, int q, int qp, int qt, int qf, int qfi, int t1, int t2, int fxam) 
{
	lastname = last;
	firstname = first;
	q1 = q;
	q2 = qp;
	q3 = qt;
	q4 = qf;
	q5 = qfi;
	test1 = t1; 
	test2 = t2;
	finalexam = fxam;
	course = "Math";
	Compute();
}
HistoryStudent::HistoryStudent(string lastn, string firstn, int t, int w, int f)
{
	lastname = lastn;
	firstname = firstn;
	termpaper = t;
	midterm = w;
	finalexam = f;
	course = "History";
	Compute(); // to initialize the letters and final

}
EnglishStudent::EnglishStudent(string lastn, string firstn, int t, int w, int f, int x)
{
	lastname = lastn;
	firstname = firstn;
	attendance = t;
	project = w;
	midterm = f;
	finalexam = x;
	course = "English";
	Compute();
}
string StudentClass::getFirstName() const
{
	return firstname;
}
string StudentClass::getLastName() const
{
	return lastname;
}
string StudentClass::getCourse() const
{
	return course; 
}
char StudentClass::getLetterGrade()
{
	return letter;
}
int StudentClass::getFinalexam() const
{
	return finalexam;
}


void StudentList::SortArray()
{
	
		for (unsigned int i = 0; i < size -1; i++) 
		{

			if (students[i]->getLastName() > students[i + 1]->getLastName()) 
			{
				swap(students[i], students[i+1]);
			} 
			if (students[i]->getLastName() == students[i + 1]->getLastName())
			{
				if (students[i]->getFirstName() > students[i + 1]->getFirstName())
				{
					swap(students[i], students[i + 1]);
				} 
			}
		}
		for (unsigned int i = 0; i < size - 1; i++)
		{

			if (students[i]->getLastName() > students[i + 1]->getLastName())
			{
				swap(students[i], students[i + 1]);
			}
			if (students[i]->getLastName() == students[i + 1]->getLastName())
			{
				if (students[i]->getFirstName() > students[i + 1]->getFirstName())
				{
					swap(students[i], students[i + 1]);
				} 
			}
		}
}
