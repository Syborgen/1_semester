#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#define K 12
#define L 68
int N, c = 0;
char st[L] = "------------------------------------------------------------------";
struct tab {
	char name[K];
	float y1;
	float y2;
	float y3;
	float y4;
}a;
FILE *fv;
FILE *fv1;
void fileInput()
{
	int n2,k=0;
	n2 = 1;
	char s1[K];
	char s2[K];
	char s3[K];
	char s4[K];
	if ((fv = fopen("tab.txt", "w")) != NULL) {
		while (n2 != 2) {
			printf("Год:");
			if (k != 0) gets(a.name);
			gets(a.name);
			fwrite(a.name, sizeof(a.name), 1, fv);
			k += 1;
			printf("Грузооборот:");
			gets(s1);
			fwrite(s1, sizeof(a.y1) + 1, 1, fv);
			printf("Перевезено грузов:");
			gets(s2);
			fwrite(s2, sizeof(a.y2) + 1, 1, fv);
			printf("Пассажирооборот:");
			gets(s3);
			fwrite(s3, sizeof(a.y3) + 1, 1, fv);
			printf("Перевезено пассажиров:");
			gets(s4);
			fwrite(s4, sizeof(a.y4) + 1, 1, fv);
			do {
				printf("Введите:\n 1 - для продолжения.\n 2 - для остановки\n");
				scanf("%d", &n2);
				if (n2 < 1 || n2>2)
					printf("Вы ошиблись повторите ввод\n");
				fflush(stdin);
			} while (n2 < 1 || n2>2);
			if (n2 == 1)
				continue;
		}
		fclose(fv);
	}
}
void output() {
	int uk, i;
	char s1[K];
	char s2[K];
	char s3[K];
	char s4[K];
	if ((fv = fopen("tab.txt", "r")) != NULL) {
		
		printf("%s\n|  Год       |Грузооборот | Перевезено | Пассажиро- | Перевезено |\n", st);
		printf("|            |            |   грузов   |   оборот   | пассажиров |\n%s\n", st);
		fseek(fv, 0, SEEK_END);
		uk = ftell(fv);
		i = 0;
		while (i < uk) {
			fseek(fv, i, SEEK_SET);
			fread(a.name, sizeof(a.name), 1, fv);
			fread(s1, sizeof(a.y1)+1, 1, fv);
			fseek(fv, ftell(fv) , SEEK_SET);
			fread(s2, sizeof(a.y2)+1, 1, fv);
			fseek(fv, ftell(fv) , SEEK_SET);
			fread(s3, sizeof(a.y3)+1, 1, fv);
			fseek(fv, ftell(fv) , SEEK_SET);
			fread(s4, sizeof(a.y4)+1, 1, fv);
			printf("|%12s|%12s|%12s|%12s|%12s|\n%s\n", a.name, s1, s2, s3, s4, st);
			i += sizeof(a) + 4;
		}
		fclose(fv);
	}
}
void search() {
	N = 0;
	float min = 1000;
	int i = 0;
	int uk;
	char s1[K];
	char s2[K];
	char s3[K];
	char s4[K];
	char s[K];
	if ((fv = fopen("tab.txt", "r")) != NULL) {
		if ((fv1 = fopen("res.txt", "w")) != NULL) {
			printf("Перевезено не более 40 млн.т. грузов\n");
			printf("%s\n|  Год       |Грузооборот | Перевезено | Пассажиро- | Перевезено |\n", st);
			printf("|            |            |   грузов   |   оборот   | пассажиров |\n%s\n", st);
			fseek(fv, 0, SEEK_END);
			uk = ftell(fv);
			while (i < uk) {
				fseek(fv, i, SEEK_SET);
				fread(a.name, sizeof(a.name), 1, fv);
				fread(s1, sizeof(a.y1)+1, 1, fv);
				a.y1 = atof(s1);
				fseek(fv, ftell(fv), SEEK_SET);
				fread(s2, sizeof(a.y2)+1, 1, fv);
				a.y2 = atof(s2);
				fseek(fv, ftell(fv), SEEK_SET);
				fread(s3, sizeof(a.y3)+1, 1, fv);
				a.y3 = atof(s3);
				fseek(fv, ftell(fv), SEEK_SET);
				fread(s4, sizeof(a.y4)+1, 1, fv);
				a.y4 = atof(s4);
				if (a.y3 < min) {
					min = a.y3;
					strcpy(s, a.name);
				}
				if (a.y2 <= 40) {
					printf("|%12s|%12s|%12s|%12s|%12s|\n%s\n", a.name, s1, s2, s3, s4, st);
				}
				if (a.y4 > 2) {
					N++;
					fwrite(a.name, sizeof(a.name), 1, fv1);
					fwrite(s1, sizeof(a.y1) + 1, 1, fv1);
					fwrite(s2, sizeof(a.y2) + 1, 1, fv1);
					fwrite(s3, sizeof(a.y3) + 1, 1, fv1);
					fwrite(s4, sizeof(a.y4) + 1, 1, fv1);
				}
				i += sizeof(a) + 4;
			}
			c = 1;
			fclose(fv1);
		}
		printf("В %s году пассажирооборот был минимальным\n", s);
		fclose(fv);
	}
}
void Sort() {
	if (c != 1)
		printf("Невозможно выполнить сортировку\n");
	else {
		int i = 0, pos, j;
		char s1[K], s11[K];
		char s2[K], s22[K];
		char s3[K], s33[K];
		char s4[K], s44[K];
		struct tab b;
		if ((fv1 = fopen("res.txt", "r+")) != NULL) {
			fseek(fv1, 0, SEEK_END);
			while (i < ((sizeof(a) + 4)*(N - 1))) {
				fseek(fv1, i, SEEK_SET);
				fread(a.name, sizeof(a.name), 1, fv1);
				fread(s1, sizeof(a.y1)+1, 1, fv1);
				fseek(fv1, ftell(fv1), SEEK_SET);
				fread(s2, sizeof(a.y2)+1, 1, fv1);
				fseek(fv1, ftell(fv1), SEEK_SET);
				fread(s3, sizeof(a.y3)+1, 1, fv1);
				fseek(fv1, ftell(fv1), SEEK_SET);
				fread(s4, sizeof(a.y4)+1, 1, fv1);
				if (a.y4 > 2) {
					j = i + sizeof(a) + 4;
					while (j <= ((sizeof(a) + 4)*N)) {
						fseek(fv1, j, SEEK_SET);
						fread(b.name, sizeof(b.name), 1, fv1);
						fread(s11, sizeof(b.y1)+1, 1, fv1);
						fseek(fv1, ftell(fv1), SEEK_SET);
						fread(s22, sizeof(b.y2)+1, 1, fv1);
						fseek(fv1, ftell(fv1), SEEK_SET);
						fread(s33, sizeof(b.y3)+1, 1, fv1);
						fseek(fv1, ftell(fv1), SEEK_SET);
						fread(s44, sizeof(b.y4)+1, 1, fv1);
						if (strcmp(s4, s44) < 0) {
							pos = i;
							fseek(fv1, pos, SEEK_SET);
							fwrite(b.name, sizeof(b.name), 1, fv1);
							fwrite(s11, sizeof(b.y1) + 1, 1, fv1);
							fwrite(s22, sizeof(b.y2) + 1, 1, fv1);
							fwrite(s33, sizeof(b.y3) + 1, 1, fv1);
							fwrite(s44, sizeof(b.y4) + 1, 1, fv1);
							pos = j;
							fseek(fv1, pos, SEEK_SET);
							fwrite(a.name, sizeof(a.name), 1, fv1);
							fwrite(s1, sizeof(a.y1) + 1, 1, fv1);
							fwrite(s2, sizeof(a.y2) + 1, 1, fv1);
							fwrite(s3, sizeof(a.y3) + 1, 1, fv1);
							fwrite(s4, sizeof(a.y4) + 1, 1, fv1);
							strcpy(s1, s11);
							strcpy(s2, s22);
							strcpy(s3, s33);
							strcpy(s4, s44);
							strcpy(a.name, b.name);
						}
						j += sizeof(a) + 4;
					}
				}
				i += sizeof(a) + 4;
			}
			fclose(fv1);
		}
	}
}
void output1() {
	N = 0;
	int uk, i;
	char s1[K];
	char s2[K];
	char s3[K];
	char s4[K];
	if ((fv1 = fopen("res.txt", "r")) != NULL) {
		printf("Перевезено более 2 млн. пссажиров\n");
		printf("%s\n|  Год       |Грузооборот | Перевезено | Пассажиро- | Перевезено |\n", st);
		printf("|            |            |   грузов   |   оборот   | пассажиров |\n%s\n", st);
		fseek(fv1, 0, SEEK_END);
		uk = ftell(fv1);
		i = 0;
		while (i < uk) {
			N++;
			fseek(fv1, i, SEEK_SET);
			fread(a.name, sizeof(a.name), 1, fv1);
			fread(s1, sizeof(a.y1)+1, 1, fv1);
			fseek(fv1, ftell(fv1), SEEK_SET);
			fread(s2, sizeof(a.y2)+1, 1, fv1);
			fseek(fv1, ftell(fv1), SEEK_SET);
			fread(s3, sizeof(a.y3)+1, 1, fv1);
			fseek(fv1, ftell(fv1), SEEK_SET);
			fread(s4, sizeof(a.y4)+1, 1, fv1);
			printf("|%12s|%12s|%12s|%12s|%12s|\n%s\n", a.name, s1, s2, s3, s4, st);
			i += sizeof(a) + 4;
		}
		fclose(fv1);
	}

}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color F0");
	setlocale(LC_ALL, "rus");
	printf("Введите данные\n");
	fileInput();
	output();
	search();
	Sort();
	output1();
	_getch();
	return 0;
}