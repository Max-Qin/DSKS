#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"find.h"
#include"change.h"
#include"kmp.h"
#define pr(...) printf(__VA_ARGS__)   
char wzwz[10];  //�����ļ���ַ

//���¿��԰�������������������ַ�
void menu(char wz[]) {
	pr("��ѡ����Ҫ�Ĳ�����\n");
	pr("------------------------------��---------------------��-------------------\n");
	pr("1���鿴���µ����֡���ĸ���ո�������\t2���鿴���������Ƿ����ĳ�ַ���\n");
	pr("3�������µ�i~jλ�õ��ַ���ɾ��      \t4�������������ĳ���ַ���ɾ�� \n");
	pr("5�������µ�k��λ�ú������һ���Ӵ�   \t6��ͳ����������ĳ���Ӵ�������\n");
	pr("7�������ļ�                        \t8���˳� \n");
	pr("--------------------------------------------------------------------------\n");
	int one;         //����ѡ��
	char cz[1000];   //���ڱ����Ӵ�
	int end = 1;     //ѡ���˳�
	int i, j;        // ��������ѡ��
	while (end) {
		pr("��ѡ��");
		scanf("%d", &one);
		getchar();    //��ֹgets�Ե��س�

		switch (one) {
		case 1: out_find(wz); break;

		case 2:pr("��������Ҫ�ҵĴ���");
			gets_s(cz); 
			if(find_string(wz, cz))pr("����%s\n",cz);
			else pr("������%s\n",cz); break;

		case 3: pr("������ɾ�������䣺");
			scanf("%d%d",&i, &j);
			if (date_seat(i, j, wz))pr("ɾ���ɹ���\n%s\n", wz);
			else pr("λ�ô���"); break;

		case 4:pr("������Ҫɾ�����ַ�����");
			gets_s(cz);
			date_string(wz, cz);
			pr("OK\n%s\n", wz);
			break;

		case 5:
			pr("�����뿪ʼλ��k�������Ӵ���");
			scanf("%d%s", &i, cz);
			if (add_string(i, wz, cz))pr("����ɹ�\n%s\n",wz);
			else pr("λ�ô���\n"); break;

		case 6:pr("�������ַ���:");
			gets_s(cz);
			pr("����%d��\n",find_string(wz, cz));
			break;

		case 8: end = 0; break;

		case 7: if (strlen(wzwz) == 0) {
				FILE *file = fopen("d:\\wenzhang.txt", "w");  //Ĭ�ϱ��浽D�� �ļ���Ϊwenzhang.txt
				fprintf(file, "%s", wz);
				fclose(file);
			}
			else {
				FILE *file = fopen(wzwz, "w");          //���ļ��������ļ�
				fprintf(file, "%s", wz);
				fclose(file);
			}
			pr("�ѱ���\n"); break;

		pr("�������\n"); // one < 1  || one > 8
		}

		pr("�����\n\n");
	}
}   //   ����   �����

int main() {
	int one;
	char wz[1000];
	pr("1���������£�\n2�����ļ�Ŀ¼��\n");
	scanf("%d", &one);
	getchar();
	if (one == 1)gets_s(wz);
	else if(one == 2) {
		pr("��������ļ���·����");
		scanf("%s", wzwz);
		int wzlen = 0;
		FILE *file;
		file = fopen(wzwz, "r");
		if (file == NULL) { pr("λ�ô���\n"); exit(0); }
		while (!feof(file)) {
			fgets(wz + wzlen, 100, file);// ֻ�ܶ�ȡһ���ַ����ɰ����ո��ܰ������У�����Ϊ���ж�ȡ�᲻�����ַ�����ƥ��
			wzlen = strlen(wz);
		}
		puts(wz);
		fclose(file);
	}             //��ȡ����wz
	else { pr("��ʽ����\n"); return 0; }
	menu(wz);
	return 0;
}   //  ����  �����