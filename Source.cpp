#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//++++++++++++++++Structure Example+++++++++++++++++

const int row = 5;
const int col = 6;

ifstream inname, ingrade;
ofstream output;

//++++++++++++++Student record with Structure example+++++++++++++++
struct studentsrecord
{
	string name;
	int grade[col];
	int total;
	double average;
	char lettergrade;
};

//+++++++++++++++++++++++Read Data+++++++++++++++++++++++
void read(studentsrecord strecord[row])
{
	inname.open("inputname.txt");
	ingrade.open("inputgrade.txt");

	int r, c;

	for (r = 0; r < row; r++)
	{
		getline(inname, strecord[r].name);
		for (c = 0; c < col; c++)
		{
			ingrade >> strecord[r].grade[c];
		}
		for (r = 0; r < row; r++)
		{
			cout << strecord[r].name << "\t";
			cout << endl;
		}
	}
}

//+++++++++++++++++++++++Total+++++++++++++++++++++++++++++++
void total(studentsrecord strecord[row])
{
	int r, c;
	for (r = 0; r < row; r++)
		strecord[r].total = 0;

	for (r = 0; r < col; r++)
	{
		for (c = 0; c < col; c++)
			strecord[r].total = strecord[r].total + strecord[r].grade[c];
		strecord[r].average = static_cast <double>(strecord[r].total) / 5;
	}
}

//++++++++++++++++++++++Calculate Average++++++++++++++++++++++
void average(studentsrecord strecord[row])
{
	int r, c;
	for (r = 0; r < row; r++)
		strecord[r].average = 0.0;
	for (r = 0; r < row; r++)
	{
		for (c = 0; c < col; c++)
			strecord[r].total = strecord[r].total + strecord[r].grade[c];
		strecord[r].average = static_cast <double>(strecord[r].total) / 5;
	}
}

//++++++++++++++++++++++Find Letter Grade+++++++++++++++++++++++
void lettergrade(studentsrecord strecord[row])
{
	int r;
	for (r = 0; r < row; r++)
		strecord[r].lettergrade = '  ';

	for (r = 0; r < row; r++)
	{
		if (strecord[r].average >= 90)
			strecord[r].lettergrade = 'A';
		else if (strecord[r].average >= 80)
			strecord[r].lettergrade = 'B';
		else if (strecord[r].average >= 70)
			strecord[r].lettergrade = 'C';
		else if (strecord[r].average >= 60)
			strecord[r].lettergrade = 'D';
		else
			strecord[r].lettergrade = 'F';
	}
}

void display(studentsrecord strecord[row])
{
	output.open("Result.txt", ios::app);
		int r, c;

		output << fixed << showpoint << setprecision(2);
		for (r = 0; r < row; r++)
		{
			output << left << setw(17) << strecord[r].name;
			for (c = 0; c < col; c++)
				output << right << setw(5) << strecord[r].grade[c];
			output << setw(7) << strecord[r].total << setw(7) << strecord[r].average << setw(7) << strecord[r].lettergrade << endl;

		}
}
//+++++++++++++++++++++++++++++++++++++Main Program+++++++++++++++++++++++++++++++++++++++
int main()
{
	studentsrecord strecord[row];

	read(&strecord[row]);
	total(&strecord[row]);
	average(&strecord[row]);
	lettergrade(&strecord[row]);
	display(&strecord[row]);

	inname.close();
	ingrade.close();
	output.close();






	system("pause");
	return 0;
}