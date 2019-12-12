#pragma once
#include"find.h"
#include"kmp.h"

int date_seat(int k, int e, char *p) {
	int len = strlen(p);
	if (k >= len)return 0;
	if (e >= len)p[k - 1] = '\0';
	for (int i = e , j = k - 1; i < len; i++) {
		p[j++] = p[i];
		p[j + 1] = '\0';
	}
	return 1;
}  // 7 、熊功博
/*
	*删除区间结尾 大于主串删除k到结尾区间	
*/

int add_string(int k, char *p, char *t) {
	int len = strlen(p) ,i = strlen(t);
	if (k > len)return 0;
	for (int  j = k; j < len; j++)t[i++] = p[j];
	t[i] = '\0';
	for (int i = 0; i < strlen(t); i++) {
		p[k++] = t[i];
	}
	p[k] = '\0';
	return 1;
} //8   --- 王珂

int date_string(char *p, char *t) {
	if (!find_string(p, t))return 0;
	int *next = kmp(t), i = 0, j = 0;
	int lenp = strlen(p), lent = strlen(t);
	int cut = 0;
	while (i < lenp) {
		if (j == -1 || p[i] == t[j]) { i++; j++; }
		else j = next[j];
		if (j == lent) {
			date_seat(i - lent + 1, i, p);
			lenp = strlen(p);
			i = i - lent + 1; j = 0;
		}
	}
	return 1;
} // 9  --- 南亦婷