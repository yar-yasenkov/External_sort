// external_sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>



	

	void Simple_Merging_Sort(char *name){
	int  k, i, j, kol, tmp;
	char a1[4];
	char a2[4];
	char buff[16];
	char a1str[16] ;
	char a2str[16] ;
	char cNewLine = '\n';
	FILE *f, *f1, *f2;
	kol = 0;
	if ((f = fopen(name, "r")) == NULL)
		printf("\nИсходный файл не может быть прочитан...");
	else {
		while (!feof(f)) {
			fgets(buff,16,f); //fscanf(f, "%d", &a1);
			++kol;
		}
		fclose(f);
	}
	k = 1;
	while (k < kol)
	{
		f = fopen(name, "r");
		f1 = fopen("smsort_1", "w");
		f2 = fopen("smsort_2", "w");
		if (!feof(f))
		{
			fgets(a1str, 16, f);
			strncpy(a1,a1str,4);
		}
		while (!feof(f)){
			for (i = 0; i < k && !feof(f); i++){
				fwrite(a1str,1,strlen(a1str),f1);//fputs(a1str, f1);//fprintf(f1, "%d ", a1);
				fwrite(&cNewLine, 1, 1, f);
				fgets(a1str, 16, f);//fscanf(f, "%d", &a1);

			}
			for (j = 0; j < k && !feof(f); j++){
				fwrite(a1str, 1, strlen(a1str), f2); //fputs(a1str, f2);//fprintf(f2, "%d ", a1);
				fwrite(&cNewLine, 1, 1, f);
				fgets(a1str, 16, f);//fscanf(f, "%d", &a1);

				
			}
		}
		fclose(f2);
		fclose(f1);
		fclose(f);

		f = fopen(name, "w");
		f1 = fopen("smsort_1", "r");
		f2 = fopen("smsort_2", "r");
		if (!feof(f1))
		{
			fgets(a1str, 16, f1);//fscanf(f1, "%d", &a1);
		    strncpy(a1, a1str, 4); 
		}
		if (!feof(f2))
		{
			fgets(a2str, 16, f2);//fscanf(f2, "%d", &a2);
			strncpy(a2, a2str, 4);
		}
		
		while (!feof(f1) && !feof(f2))
		{
			i = 0;
			j = 0;
			while (i < k && j < k && !feof(f1) && !feof(f2)) {

				if (strcmp(a1,a2) < 0) {
					fwrite(a1str, 1, strlen(a1str), f);//fputs(a1str, f);//fprintf(f, "%d ", a1);
					fwrite(&cNewLine, 1, 1, f);
					fgets(a1str, 16, f1);//fscanf(f1, "%d", &a1);
					strncpy(a1, a1str, 4);//a1 = surname(a1str);
					i++;
					}
				else {
					fwrite(a2str, 1, strlen(a2str), f);//fputs(a2str, f);//fprintf(f, "%d ", a2);
					fwrite(&cNewLine, 1, 1, f);
					fgets(a2str, 16, f2);//fscanf(f2, "%d", &a2);
					strncpy(a2, a2str, 4);//a2 = surname(a2str);
					j++;
					}
			}
			while (i < k && !feof(f1)) {
				fwrite(a1str, 1, strlen(a1str), f);//fputs(a1str, f);//fprintf(f, "%d ", a1);
				fwrite(&cNewLine, 1, 1, f);
				fgets(a1str, 16, f1);//fscanf(f1, "%d", &a1);
				strncpy(a1, a1str, 4); //a1 = surname(a1str);
				i++;
			}
			while (j < k && !feof(f2)) {
				fwrite(a2str, 1, strlen(a2str), f); //fputs(a2str, f);//fprintf(f, "%d ", a2);
				fwrite(&cNewLine, 1, 1, f);
				fgets(a2str, 16, f2);//fscanf(f2, "%d", &a2);
				strncpy(a2, a2str, 4); //a2 = surname(a2str);
				j++;
			}
		}
		while (!feof(f1)) {
			fwrite(a1str, 1, strlen(a1str), f);//fputs(a1str, f); //fprintf(f, "%d ", a1);
			fwrite(&cNewLine, 1, 1, f);
			fgets(a1str, 16, f1);//fscanf(f1, "%d", &a1);
			strncpy(a1, a1str, 4); //a1 = surname(a1str);
		}
		while (!feof(f2)) {
			fwrite(a2str, 1, strlen(a2str), f); //fputs(a2str, f);//fprintf(f, "%d ", a2);
			fwrite(&cNewLine, 1, 1, f);
			fgets(a2str, 16, f2);//fscanf(f2, "%d", &a2);
			strncpy(a2, a2str, 4); //a2 = surname(a2str);
		}
		fclose(f2);
		fclose(f1);
		fclose(f);
		k *= 2;
	}
	remove("smsort_1");
	remove("smsort_2");
}



int _tmain(int argc, _TCHAR* argv[])
{
	Simple_Merging_Sort("spisok.txt");
	
	return 0;
}

