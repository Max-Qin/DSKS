#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"find.h"
#include"change.h"
#include"kmp.h"
#define pr(...) printf(__VA_ARGS__)   
char wzwz[10];  //保存文件地址

//文章可以包含除换行以外的所有字符
void menu(char wz[]) {
	pr("请选择需要的操作：\n");
	pr("------------------------------菜---------------------单-------------------\n");
	pr("1、查看文章的数字、字母、空格、字数。\t2、查看文章里面是否包含某字符串\n");
	pr("3、将文章第i~j位置的字符串删除      \t4、将文章里面的某个字符串删除 \n");
	pr("5、再文章第k个位置后面加入一个子串   \t6、统计文章里面某个子串的数量\n");
	pr("7、保存文件                        \t8、退出 \n");
	pr("--------------------------------------------------------------------------\n");
	int one;         //功能选择
	char cz[1000];   //用于保存子串
	int end = 1;     //选择退出
	int i, j;        // 用于输入选择
	while (end) {
		pr("请选择：");
		scanf("%d", &one);
		getchar();    //防止gets吃掉回车

		switch (one) {
		case 1: out_find(wz); break;

		case 2:pr("请输入需要找的串：");
			gets_s(cz); 
			if(find_string(wz, cz))pr("包含%s\n",cz);
			else pr("不包含%s\n",cz); break;

		case 3: pr("请输入删除的区间：");
			scanf("%d%d",&i, &j);
			if (date_seat(i, j, wz))pr("删除成功！\n%s\n", wz);
			else pr("位置错误"); break;

		case 4:pr("请输入要删除的字符串：");
			gets_s(cz);
			date_string(wz, cz);
			pr("OK\n%s\n", wz);
			break;

		case 5:
			pr("请输入开始位置k，加入子串：");
			scanf("%d%s", &i, cz);
			if (add_string(i, wz, cz))pr("插入成功\n%s\n",wz);
			else pr("位置错误\n"); break;

		case 6:pr("请输入字符串:");
			gets_s(cz);
			pr("包含%d个\n",find_string(wz, cz));
			break;

		case 8: end = 0; break;

		case 7: if (strlen(wzwz) == 0) {
				FILE *file = fopen("d:\\wenzhang.txt", "w");  //默认保存到D盘 文件名为wenzhang.txt
				fprintf(file, "%s", wz);
				fclose(file);
			}
			else {
				FILE *file = fopen(wzwz, "w");          //打开文件并更新文件
				fprintf(file, "%s", wz);
				fclose(file);
			}
			pr("已保存\n"); break;

		pr("输入错误\n"); // one < 1  || one > 8
		}

		pr("已完成\n\n");
	}
}   // 

int main() {
	int one;
	char wz[1000];
	pr("1、输入文章：\n2、打开文件目录：\n");
	scanf("%d", &one);
	getchar();
	if (one == 1)gets_s(wz);
	else if(one == 2) {
		pr("请输入打开文件的路径：");
		scanf("%s", wzwz);
		int wzlen = 0;
		FILE *file;
		file = fopen(wzwz, "r");
		if (file == NULL) { pr("位置错误\n"); exit(0); }
		while (!feof(file)) {
			fgets(wz + wzlen, 100, file);// 只能读取一行字符串可包含空格不能包含换行；若改为分行读取会不便于字符串的匹配
			wzlen = strlen(wz);
		}
		puts(wz);
		fclose(file);
	}             //获取文章wz
	else { pr("格式错误\n"); return 0; }
	menu(wz);
	return 0;
}   
