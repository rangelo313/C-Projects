//Robert Cimarelli, section 8
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class StudentClass
{
public:
	StudentClass(string l, string f, string course, int fxam);
	StudentClass();
	string getFirstName() const; // done 
	string getLastName() const; // done
	string getCourse() const;
	int getFinalexam() const;
	
	char getLetterGrade();
	//virtual char getLetterGrade();
	virtual double Compute() = 0;
protected:
	string firstname;
	string lastname; //20 characters
	string course;
	char letter;
	int finalexam;
	double finalgrade;
private:
	
};

class HistoryStudent : public StudentClass
{
public:
	HistoryStudent(string lastname, string firstname, int t, int w, int f);
	~HistoryStudent();
	virtual double Compute();
private:
	int termpaper, midterm;
};

class MathStudent : public StudentClass
{
public:
	MathStudent(string last, string first, int q1, int q2, int q3, int q4, int q5, int test1, int test2, int finalexam);
	~MathStudent();
	
	virtual double Compute();

private:
	int q1, q2, q3, q4, q5, test1, test2;

};

class EnglishStudent : public StudentClass
{
public:
	EnglishStudent(string lastname, string firstname, int, int, int, int);
	~EnglishStudent();
	virtual double Compute();


private:
	int attendance, project, midterm;
	
};
class StudentList
{
public:
	StudentList();		// starts out empty
	~StudentList();		// cleanup (destructor)

	bool ImportFile(const char* filename);
	bool CreateReportFile(const char* filename);
	void ShowList() const;
	void SortArray();
	

private:
	StudentClass**students;
	int size;
};