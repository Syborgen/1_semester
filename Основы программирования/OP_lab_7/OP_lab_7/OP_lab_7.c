#include <stdio.h> 
#include <locale.h> 
#include <stdlib.h>
#include "windows.h"
#include <math.h>
#include <conio.h>
#include <string.h>
#define N 100
#define L 65
int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE *filer;
	FILE *filew;
	struct start
	{
		char name1[N+1];
		char name2[N + 1];
		int p1929;
		int p1937;
		int p1956;
	} s[N];
	int i=0,k=-1,a=8,u=0;
	int o[N],q[N],min=10000,res,b,n=-1;
	char linija1[N] = "--------------------------------------------------------------------";
	char linija2[N] = "-----------------------------------------------------------------";
	while (a < 1 || a>2) {
		printf("���� � �����(read.txt) ��� �������?(1-����, 2-�������)\n");
		do {                                               //�������� �� ���� ������ �����
			res = scanf("%d", &a);                   //�������� �� ���� ������ �����
			while (getchar() != '\n');                  //�������� �� ���� ������ �����
			if (res != 1) printf("������� �����\n");
		} while (res != 1);
	}
	if (a == 1) {//                                            ������ � �����
		filer = fopen("read.txt", "r");//��������� 1
		if (filer == NULL)
		{
			printf("���� �� ������");
			_getch();
			exit(0);
		}
		while (fscanf(filer, "%s%s%d%d%d", &s[u].name1, &s[u].name2, &s[u].p1929, &s[u].p1937, &s[u].p1956) != EOF) {
			n++;
			u++;
		}
		fclose(filer);//��������� 1
		if (s[0].p1929 == -858993460) {
			printf("���� ������!");
			_getch();
			exit(0);
		}
	}
	else {//                                                 ������ � ����������
		printf("������� ������\n");
		do {
			n++;
			printf("������� ���:");
			scanf("%s", &s[n].name1);
			printf("������� ������� ���������('���_����' ��� '���_��_�'):");
			scanf("%s", &s[n].name2);
			printf("������� ���������� �� 1929:");
			do {                                               //�������� �� ���� ������ �����
				res = scanf("%d", &s[n].p1929);                   //�������� �� ���� ������ �����
				while (getchar() != '\n');                  //�������� �� ���� ������ �����
				if (res != 1) printf("������� �����\n");
			} while (res != 1);
			printf("������� ���������� �� 1937:");
			do {                                               //�������� �� ���� ������ �����
				res = scanf("%d", &s[n].p1937);                   //�������� �� ���� ������ �����
				while (getchar() != '\n');                  //�������� �� ���� ������ �����
				if (res != 1) printf("������� �����\n");
			} while (res != 1);
			printf("������� ���������� �� 1956:");
			do {                                               //�������� �� ���� ������ �����
				res = scanf("%d", &s[n].p1956);                   //�������� �� ���� ������ �����
				while (getchar() != '\n');                  //�������� �� ���� ������ �����
				if (res != 1) printf("������� �����\n");
			} while (res != 1);
			printf("������ �������� ��� 1 ������?(1-�� , 2-���)\n");
			do {                                               //�������� �� ���� ������ �����
				res = scanf("%d", &b);                   //�������� �� ���� ������ �����
				while (getchar() != '\n');                  //�������� �� ���� ������ �����
				if (res != 1) printf("������� �����\n");
			} while (res != 1);
		} while (b == 1);
		
	}////////////////////////////////////////////////////////////////////////////////////////////////////////
	//����� ������� � ����������
	printf("%s\n", linija1);
	printf("|           ���             |������� ���������| 1929 | 1937 | 1956 |\n");
	printf("%s\n", linija1);
	//���������� �������
	for (i = 0; i <= n; i++) {
		printf("|%-27s|%-17s|%-6d|%-6d|%-6d|\n", s[i].name1,  s[i].name2,  s[i].p1929,  s[i].p1937,  s[i].p1956);
		printf("%s\n", linija1);
		if (strstr(s[i].name2,"���_����")== s[i].name2 && ((s[i].p1956 - s[i].p1929) > 0) && ((s[i].p1956 - s[i].p1929) < min)) {
			min = s[i].p1956 - s[i].p1929;
			o[i] = s[i].p1956 * 100 / s[i].p1929 - 100;//������� ��������
			q[i]= s[i].p1937 * 100 / s[i].p1929 - 100;
			k = i;
		}
	}
	printf("��� � ���������� ���������� ��������� 1929-1956(�������� � ����� rezult.txt)\n");
	printf("%s\n", linija2);
	printf("|           ���             |������� 1929-1937|������� 1929-1956|\n");
	printf("%s\n", linija2);
	printf("|%-27s|%-17d|%-17d|\n", s[k].name1,q[k], o[k]);
	printf("%s\n", linija2);
	filew = fopen("rezult.txt","w");//��������� 2
	if (filew == NULL)
	{
		printf("���� �� ������");
		_getch();
		exit(0);
	}
	fprintf(filew, "%s\n", linija2);
	fprintf(filew, "|           ���             |������� 1929-1937|������� 1929-1956|\n");
	fprintf(filew, "%s\n", linija2);
	fprintf(filew,"|%-27s|%-17d|%-17d|\n", s[k].name1, q[k], o[k]);
	fprintf(filew,"%s\n", linija2);
	fclose(filew);//��������� 2
	_getch();
	return 0;
}
