// external_sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
	void Simple_Merging_Sort(char *name){
	int  k, i, j, kol, tmp;
	string buf,a1str, a2str;
	char buff[16];
	char cNewLine = '\n';
	//FILE *f, *f1, *f2;
	
	
	kol = 0;
	ifstream f(name);
	if ((f.is_open()) == 0)
		printf("\n�������� ���� �� ����� ���� ��������...");
	else {
		while (!f.eof()) {
			getline(f, buf);
			++kol;
		}
		f.close();
	}
	k = 1;
	while (k < kol)
	{
		ofstream f1, f2;
		f.open(name, ios::in);
		f1.open("smsort_1.txt", ios::out);
		f2.open("smsort_2.txt", ios::out);
		if (!f.eof())
		{
			getline(f, a1str);
		}
		while (!f.eof()){
			for (i = 0; i < k && !f.eof(); ++i){
				f1 << a1str << endl;
				getline(f, a1str);

			}
			for (j = 0; j < k && !f.eof() ; ++j){
				f2 << a1str << endl;
				getline(f, a1str);
				
			
			}
		}
		f2.close();
		f1.close();
		f.close();
		
		ofstream f_(name, ios::out);
		ifstream f1_("smsort_1.txt", ios::in);
		ifstream f2_("smsort_2.txt", ios::in);
		if (!f1_.eof())
		{
			getline(f1_, a1str);
		}
		if (!f2_.eof())
		{
			getline(f2_, a2str);
		}
		
		while (!f1_.eof() && !f2_.eof())
		{
			i = 0;
			j = 0;
			while (i < k && j < k && !f1_.eof() && !f2_.eof()) {

				if (a1str.compare(a2str) < 0) {
					f_ << a1str << endl;	    
					getline(f1_, a1str);			
					++i;
					}
				else {
					f_ << a2str << endl;
					getline(f2_, a2str);
					++j;
					}
			}
			while (i < k && !f1_.eof()) {
				f_ << a1str << endl;
				getline(f1_, a1str);
				++i;
			}
			while (j < k && !f2_.eof()) {
				f_ << a2str << endl;
				getline(f2_, a2str);
				++j;
			}
		}
		while (!f1_.eof()) {
			f_ << a1str << endl;
			getline(f1_, a1str);
		}
		while (!f2_.eof()) {
			f_ << a2str << endl;
			getline(f2_, a2str);
		}
		f2_.close();
		f1_.close();
		f_.close();
		k *= 2;
	}
	//remove("smsort_1");
	//remove("smsort_2");
}



int _tmain(int argc, _TCHAR* argv[])
{
	Simple_Merging_Sort("spisok.txt");
	return 0;
}

