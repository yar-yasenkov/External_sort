// generate_spisok.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <ctime>
#include <iostream>
using namespace std;

char randomletter() {
	static  bool seedset = false;
	if (!seedset) {
		srand(static_cast<unsigned> (time(NULL)));
		seedset = true;
	}
	char alph[] = "àáâãäåæçèêëìíîïğñòóôõö÷øùüûúışÿ";
	return alph[rand() % (sizeof(alph) / sizeof (alph[0]) - 1)];
}



char randombigletter() {
	static  bool seedset = false;
	if (!seedset) {
		srand(static_cast<unsigned> (time(NULL)));
		seedset = true;
	}
	char alph[] = "ÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙİŞß";
	return alph[rand() % (sizeof(alph) / sizeof (alph[0]) - 1)];
}


int _tmain(int argc, _TCHAR* argv[])
{
	
	ofstream fout;
	fout.open("spisok.txt");
	for (size_t k = 0; k < 200; ++k)
	{
		char st[16] = "\0";
		st[0] = randombigletter();
		for (int i = 1; i < 4; ++i)
		{
			st[i] = randomletter();
		}
		st[4] = ' ';
		//strcat_s(st, " ");
		st[5] = randombigletter();
		for (int i = 6; i < 10; ++i)
		{
			st[i] = randomletter();
		}
		//strcat_s(st, " ");
		st[10] = ' ';
		for (int i = 11; i < 15; ++i)
		{
			_itoa_s(1 + rand() % 9,&st[i],2,10);
		}
		st[15] = '\0';
		//cout << st << endl;
		fout << st;
		fout << endl;
	}
	fout.close();

	//pos = 1 + rand() % 30;
	//strcat_s(st, &alphbig[pos]);
	/*for (size_t i = 1; i < 7; ++i)
	{
		pos = 1 + rand() % 33;
		strcat_s(st, &alphbig[pos]);
	}
	strcat_s(st, " ");
	pos = 1 + rand() % 30;
	strcat_s(st, &alphbig[pos]);
	for (size_t i = 9; i < 15; ++i)
	{
		pos = 1 + rand() % 33;
		strcat_s(st, &alphbig[pos]);
	}
    strcat_s(st, '\0');*/
	//fout << st;// << endl;
	//for (int i = 0; i<10; i++) {
	//	fout << randomletter() << "  ";
	//}
	//system("pause");
	return 0;
}

