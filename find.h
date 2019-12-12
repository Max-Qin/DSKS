#pragma once
#include"kmp.h"

void find_num(char *t) {
	int cut = 0;
	for (int i = 0; i < strlen(t); i++) {
		if (t[i] >= '0' && t[i] <= '9')cut++;
	}
	printf("这个文章数字一共有：%d\n", cut);
}  //1   ---- 艾鹏

int find_space(char *t) {
	int cut = 0;
	for (int i = 0; i < strlen(t); i++) {
		if (t[i] == ' ')cut++;
	}
	printf("这个文章空格一共有：%d\n", cut);
	return cut;
} // 2 ------  艾鹏

void find_letter(char *t) {
	int cut = 0;
	for (int i = 0; i < strlen(t); i++) {
		if ((t[i] >= 'a' && t[i] <= 'z' )|| (t[i] >= 'A' && t[i] <= 'Z'))cut++;
	}
	printf("这个文章字母一共有：%d\n", cut);
}   // 3  ----  姜淇淞

void find_word(char *t) {
	int cut = 0, temp = 0;
	for (int i = 0; i < strlen(t); i++) {
		if (temp == 0 && ((t[i] >= 'a' && t[i] <= 'z') || (t[i] >= 'A' && t[i] <= 'Z'))) {
			cut++;
			temp = 1;
		}
		if (t[i] == ' ' || t[i] == '\n')temp = 0;
	}
	printf("这个文章字数一共有：%d\n", cut);
} // 4   -----   姜淇淞

void out_find(char *t) {
	find_num(t);
	find_letter(t);
	find_space(t);
	find_word(t);
} // 5   ---  艾鹏  姜淇淞

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
} // 6   ---- 胡苗