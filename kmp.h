#pragma once
#include<string.h>
#include<stdio.h>
int next[1000];

int *kmp(char *t) {

	int j = 0, k = -1, len = strlen(t);
	next[0] = -1;
	while (j < len - 1) {
		if (k == -1 || t[k] == t[j])next[++j] = ++k;
		else k = next[k];
	}
	return next;
} 