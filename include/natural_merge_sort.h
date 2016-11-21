// natural_merge_sort.cpp : Defines the entry point for the console application.
//
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

bool End_Range(ifstream& f){//определение конца блока
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
	//FILE  *f1, *f2;
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
		ifstream f(name);//f = fopen(name, "r");
		ofstream f1("nmsort_1.txt");//f1 = fopen("nmsort_1", "w");
		ofstream f2("nmsort_2.txt");//f2 = fopen("nmsort_2", "w");
		getline(f, a1str);//fscanf(f, "%d", &a1);
		if (!f.eof()) {
			f1 << a1str << endl;//fprintf(f1, "%d ", a1);
		}
		if (!f.eof()){
			getline(f, a2str);//fscanf(f, "%d", &a2);
		}
		while ((s1+s2 < numberstr) && (a1str !="") && (a2str != "")){
			if (a2str < a1str) 
			{
				switch (mark) {
				case 1:{f1 << "-" << endl;/*fprintf(f1, "' ");*/ mark = 2; ++s1; break; }
				case 2:{f2 << "-" << endl;/*fprintf(f2, "' ");*/ mark = 1; ++s2; break; }
				}
			}
			if (mark == 1) 
			{ 
				f1 << a2str << endl/*fprintf(f1, "%d ", a2)*/;
				++s1; 
			}
			else 
			{ 
				f2 << a2str << endl/*fprintf(f2, "%d ", a2)*/;
				++s2; 
			}
			a1str = a2str;
			getline(f, a2str);//fscanf(f, "%d", &a2);
			//k++;
		}
		if (s2 > 0 && mark == 2) 
		{ 
			f2 << "-" << endl/* fprintf(f2, "'")*/; 
		}
		if (s1 > 0 && mark == 1) 
		{ 
			f1 << "-" << endl/*fprintf(f1, "'")*/; 
		}
		f2.close();//fclose(f2);
		f1.close();// fclose(f1);
		f.close();// fclose(f);

		//cout << endl;
		//Print_File(name);
		//Print_File("nmsort_1");
		//Print_File("nmsort_2");
		//cout << endl;
	
		ofstream f_(name);
		ifstream f1_("nmsort_1.txt");// = fopen("nmsort_1", "r");
		ifstream f2_("nmsort_2.txt");// = fopen("nmsort_2", "r");
		if (!f1_.eof()) getline(f1_, a1str);//fscanf(f1, "%d", &a1);
		if (!f2_.eof()) getline(f2_, a2str);//fscanf(f2, "%d", &a2);
		bool file1, file2;
		while (!f1_.eof() && !f2_.eof()){
			file1 = file2 = false;
			while (!file1 && !file2) {
				if (a1str <= a2str) 
				{
					f_ << a1str << endl;//fprintf(f, "%d ", a1);
					file1 = End_Range(f1_);
					getline(f1_, a1str);//fscanf(f1, "%d", &a1);
				}
				else {
					f_ << a2str << endl;//fprintf(f, "%d ", a2);
					file2 = End_Range(f2_);
					getline(f2_, a2str);//fscanf(f2, "%d", &a2);
				}
			}
			while (!file1) {
				f_ << a1str << endl;//fprintf(f, "%d ", a1);
				file1 = End_Range(f1_);
				getline(f1_, a1str);// fscanf(f1, "%d", &a1);
			}
			while (!file2) {
				f_ << a2str << endl;//fprintf(f, "%d ", a2);
				file2 = End_Range(f2_);
				getline(f2_, a2str);//fscanf(f2, "%d", &a2);
			}
		}
		file1 = file2 = false;
		while (!file1 && !f1_.eof()) {
			f_ << a1str << endl;//fprintf(f, "%d ", a1);
			file1 = End_Range(f1_);
			getline(f1_, a1str);//fscanf(f1, "%d", &a1);
		}
		while (!file2 && !f2_.eof()) {
			f_ << a2str << endl;//fprintf(f, "%d ", a2);
			file2 = End_Range(f2_);
			getline(f2_, a2str);//fscanf(f2, "%d", &a2);
		}
		f2_.close();//fclose(f2);
		f1_.close();// fclose(f1);
		f_.close();// fclose(f);
	}
	//remove("nmsort_1");
	//remove("nmsort_2");
}
