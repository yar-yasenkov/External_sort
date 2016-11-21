// natural_merge_sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


/*int comp(string st1, string st2)
{
	static int counter = 0;
	++counter;
	std::cout << counter << endl;
	if (st1 < st2)
		return -1;
	if (st1 > st2)
		return 1;
	if (st1 == st2)
		return 0;
}*/

bool End_Range(ifstream& f){//îïðåäåëåíèå êîíöà áëîêà
	streamoff i;
	string tmp;
	i = f.tellg();
	getline(f, tmp);
	if (tmp != "-") {
		f.seekg(i);
	}
	return tmp == "-" ? true : false;
}

void Natural_Merging_Sort(char *name){
	int s1, s2, mark;
	static int k = 0;
	string a1str, a2str;
	ifstream f0(name);
	int numberstr = 0;
	while (!f0.eof())
	{
		string tmp;
		getline(f0, tmp);
		++numberstr;
	}
	s1 = s2 = 1;
	while (s1 > 0 && s2 > 0){
		mark = 1;
		s1 = 0;
		s2 = 0;
		ifstream f(name);
		ofstream f1("nmsort_1.txt");
		ofstream f2("nmsort_2.txt");
		getline(f, a1str);
		if (!f.eof()) {
			f1 << a1str << endl;
		}
		if (!f.eof()){
			getline(f, a2str);
		}
		while ((s1+s2 < numberstr) && (a1str !="") && (a2str != "")){
			if (a2str < a1str) 
			{
				switch (mark) {
				case 1:{f1 << "-" << endl; mark = 2; ++s1; break; }
				case 2:{f2 << "-" << endl; mark = 1; ++s2; break; }
				}
			}
			if (mark == 1) 
			{ 
				f1 << a2str << endl;
				++s1; 
			}
			else 
			{ 
				f2 << a2str << endl;
				++s2; 
			}
			a1str = a2str;
			getline(f, a2str);
		}
		if (s2 > 0 && mark == 2) 
		{ 
			f2 << "-" << endl; 
		}
		if (s1 > 0 && mark == 1) 
		{ 
			f1 << "-" << endl; 
		}
		f2.close();
		f1.close();
		f.close();

		
		ofstream f_(name);
		ifstream f1_("nmsort_1.txt");
		ifstream f2_("nmsort_2.txt");
		if (!f1_.eof()) getline(f1_, a1str);
		if (!f2_.eof()) getline(f2_, a2str);
		bool file1, file2;
		while (!f1_.eof() && !f2_.eof()){
			file1 = file2 = false;
			while (!file1 && !file2) {
				if (a1str <= a2str) 
				{
					f_ << a1str << endl;
					file1 = End_Range(f1_);
					getline(f1_, a1str);
				}
				else {
					f_ << a2str << endl;
					file2 = End_Range(f2_);
					getline(f2_, a2str);
				}
			}
			while (!file1) {
				f_ << a1str << endl;
				file1 = End_Range(f1_);
				getline(f1_, a1str);
			}
			while (!file2) {
				f_ << a2str << endl;
				file2 = End_Range(f2_);
				getline(f2_, a2str);
			}
		}
		file1 = file2 = false;
		while (!file1 && !f1_.eof()) {
			f_ << a1str << endl;
			file1 = End_Range(f1_);
			getline(f1_, a1str);
		}
		while (!file2 && !f2_.eof()) {
			f_ << a2str << endl;
			file2 = End_Range(f2_);
			getline(f2_, a2str);
		}
		f2_.close();
		f1_.close();
		f_.close();
	}
}


