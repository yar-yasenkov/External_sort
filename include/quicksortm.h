// quicksortm.cpp : Defines the entry point for the console application.
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


class line
{
public:
	string surname;
	string name;
	short year;

};

struct line_stream
{
	line s;
	ifstream *f;
	line_stream(const line& s_, ifstream* f_) : s(s_), f(f_){}
};



bool operator < (const line& s1, const line& s2)
{
	return (s1.name < s2.name);
}

bool operator > (const line& s1, const line& s2)
{
	return (s1.name > s2.name);
}

istream& operator >> (istream &Stream, line &Str)
{
	Stream >> Str.surname >> Str.name >> Str.year;
	return Stream;
}

ostream& operator << (ostream &Stream, line &Str)
{
	Stream << Str.surname << " " << Str.name << " " << Str.year;
	return Stream;
}


bool operator < (const line_stream& ls1, const line_stream& ls2)
{
	return (ls1.s < ls2.s);
}

void sortlines(const char * input, const char * output, const size_t memory)
{
	ifstream fin(input);
	if (!fin.is_open()) throw("file_not_open");
	ofstream fout(output);
	short k = 0;
	while (!fin.eof())
	{
		vector<line> v;
		line s;
		ofstream ftemp(to_string(k + 1));
		for (unsigned long int size = 0; (size + 2 * sizeof(string)+s.name.capacity() + s.surname.capacity() + sizeof(short)) < memory * 1024 * 1024;)
		{
			if (!fin.eof() && (fin >> s) && (s.name != ""))
			{
				v.push_back(s);
			}
			size += 2 * sizeof(string)+s.name.capacity() + s.surname.capacity() + sizeof(short);
		}
		sort(v.begin(), v.end());
		for (auto iter = begin(v); iter != end(v); ++iter)
		{
			if (iter->name != "") ftemp << *iter << endl;
		}
		++k;
		ftemp.close();
	}
	fin.close();
	priority_queue<line_stream> pq;
	for (size_t i = 0; i < k; ++i)
	{
		ifstream* f_ = new ifstream(to_string(i + 1));
		line str;
		*f_ >> str;
		line_stream ls(str, f_);
		pq.push(ls);
	}
	while (!pq.empty())
	{
		line_stream ls = pq.top();
		pq.pop();
		if (ls.s.name != "") fout << ls.s << endl;
		if (!(*ls.f).eof() && (*ls.f >> ls.s))
		{
			pq.push(ls);
		}
		else
		{
			(*(ls.f)).close();
		}
	}
	for (size_t i = 0; i < k; ++i)
	{
		remove((to_string(i + 1)).c_str());
	}
	fout.close();
}

