#pragma once
#include"kmp.h"

void find_num(char *t) {
	int cut = 0;
	for (int i = 0; i < strlen(t); i++) {
		if (t[i] >= '0' && t[i] <= '9')cut++;
	}
	printf("�����������һ���У�%d\n", cut);
}  //1   ---- ����

int find_space(char *t) {
	int cut = 0;
	for (int i = 0; i < strlen(t); i++) {
		if (t[i] == ' ')cut++;
	}
	printf("������¿ո�һ���У�%d\n", cut);
	return cut;
} // 2 ------  ����

void find_letter(char *t) {
	int cut = 0;
	for (int i = 0; i < strlen(t); i++) {
		if ((t[i] >= 'a' && t[i] <= 'z' )|| (t[i] >= 'A' && t[i] <= 'Z'))cut++;
	}
	printf("���������ĸһ���У�%d\n", cut);
}   // 3  ----  �����

void find_word(char *t) {
	int cut = 0, temp = 0;
	for (int i = 0; i < strlen(t); i++) {
		if (temp == 0 && ((t[i] >= 'a' && t[i] <= 'z') || (t[i] >= 'A' && t[i] <= 'Z'))) {
			cut++;
			temp = 1;
		}
		if (t[i] == ' ' || t[i] == '\n')temp = 0;
	}
	printf("�����������һ���У�%d\n", cut);
} // 4   -----   �����

void out_find(char *t) {
	find_num(t);
	find_letter(t);
	find_space(t);
	find_word(t);
} // 5   ---  ����  �����

int find_string(char *p, char *t) {
	int *next = kmp(t);
	int lenp = strlen(p), lent = strlen(t);
	int cut = 0, i = 0, j = 0;
	while (i < lenp) {
		if (j == -1 || p[i] == t[j]) { i++; j++; }
		else j = next[j];
		if (j == lent) {
			cut++; i++; j = 0;
		}
	}
	return cut;
} // 6   ---- ����