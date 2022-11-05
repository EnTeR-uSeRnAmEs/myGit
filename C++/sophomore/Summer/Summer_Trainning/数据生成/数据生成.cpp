#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <sstream>
#include <cstring>
#include <windows.h>
#include "score.h"
#include "SelectSort.h"
#include "QuickSort.cpp" 
#include "InsertionSort_Shell.cpp"
#include "InsertionSort_Binary.cpp"
#include "InsertionSort.cpp"
#include "BubbleSort.cpp"


using namespace std;

template <typename T> void GetMemory(T *&data, T *&data0, int amount){	//给data分配amount个空间 (data是存储随机数的数组首地址、amount是数据数量） 																								
	if(data != NULL) delete [] data;
	if(data0 != NULL) delete [] data0;				//若data不为NULL，即有堆空间资源，则先释放原有堆空间资源							
	data = new T[amount];
	data0 = new T[amount];
}

template <typename T> void FreeMemory(T *&data, T *&data0){		//将data的空间释放 
	if(data != NULL) delete [] data;	
	if(data0 != NULL) delete [] data0;
	data = NULL;	
	data0 = NULL;									
}

double UniformRand(int amount, int type_choice){			        //产生均匀分布随机数 
	if(type_choice == 3) return rand() * 94 / RAND_MAX;	        	//type_choice: 1-整型、2-浮点、3-字符、4-均匀分布、5-正态分布 
	else return -amount + rand() * 1.0 * (amount * 2) / RAND_MAX;	
}

double GaussRand(int type_choice){	               // 产生正态分布数据（mena:均值、数学期望，variance方差） 
	static double u, v;
	static int phase = 0;
	double z, mean = rand() * 1.0, variance = (rand() % 49 + 1) * 1.0;

	if(phase == 0){
		u = (rand() + 1.0) / (RAND_MAX + 1.0);	// 避免u或v为0时参与对数log计算
		v = (rand() + 1.0) / (RAND_MAX + 1.0);
		z = sqrt(-2.0 * log(u))* sin(2.0 * M_PI * v);
	}
	else{
		z = sqrt(-2.0 * log(u)) * cos(2.0 * M_PI * v);
	}
	phase = 1 - phase;
	if(type_choice == 3) return 47 + z*sqrt(rand() % 300);
	else return mean + z*sqrt(variance);
}


template <typename T> void crepeatdata(T *data, int amount, int type_choice);
template <typename T> void wf(FILE *fp, T *data, string fname, char num, int amount, int type_choice, int choice, int n);
template <typename T> void createdata(T *data, int amount, int type_choice, int choice){                 //生成数据 （choice是数据构型选项、type_choice是数据类型选项） 
	int rand0, r1;	
	double r2;																			 			   //type_choice: 1-整型、2-浮点、3-字符、4-均匀分布、5-正态分布 
	static int n1 = 1, n2 = 1, n3 = 1, n4 = 1, n6 = 1;
	string fname, num;
	char r3;																		   
	FILE *fp;
	
	rand0 = rand() % (2 * amount) - amount;    //设置初随机数 
	if(type_choice == 3){
		if(choice == 1){
			if(amount == 94) r3 = '!';
			else r3 = rand() % (94 - amount) + '!';
		}
		if(choice == 2){
			if(amount == 94) r3 = '!' + 94;
			else r3 = 94 - (rand() % (94 - amount))+ '!';
		}
	}
	else {
		r2 = rand0 * 1.0;
	}

	if(choice == 1){                         //顺序 
		for(int i = 0; i < amount; i++){
			if(type_choice == 1){
				rand0 = rand0 + rand() % 10 + 1;		
		    	data[i] = rand0;		    	
			}
			if(type_choice == 2) {
				r2 = r2 + (rand() % 10000) * 0.001 + 0.001;
				data[i] = r2;
			}					
			if(type_choice == 3){
				data[i] = r3;
				r3 = r3 + 1;	
			}
		}
	wf(fp, data, fname, num, amount, type_choice, choice, n1);
	n1++;			
	}
	else if(choice == 2){                    //逆序 
		for(int i = 0; i < amount; i++){
			if(type_choice == 1) {
				rand0 = rand0 - rand() % 10 - 1;
		    	data[i] = rand0 ;
			}
		    if(type_choice == 2) {
				r2 = r2 - (rand() % 10000) * 0.001 - 0.001;
				data[i] = r2;
			}		
			if(type_choice == 3){
				data[i] = r3;
				r3 = r3 - 1;				
			}
		}
		wf(fp, data, fname, num, amount, type_choice, choice, n2);
		n2++;
	}
	else if(choice == 3){                    //均匀分布
		for(int i = 0; i < amount; i++){
			if(type_choice == 1 || type_choice == 2) {
		    	data[i] = (T)UniformRand(amount, type_choice);
			}	
			if(type_choice == 3){
				rand0 = UniformRand(amount, type_choice);
				r3 = rand0 + '!';
				data[i] = r3;			
			}
		}
		wf(fp, data, fname, num, amount, type_choice, choice, n3);
		n3++;
	}
	else if(choice == 4){                    //正态分布
		for(int i = 0; i < amount; i++){
			if(type_choice == 1 || type_choice == 2) {
		    	data[i] = (T)GaussRand(type_choice);
			}	
			if(type_choice == 3){
				rand0 = GaussRand(type_choice);
				r3 = rand0 + '!';
				data[i] = r3;			
			}
		}
		wf(fp, data, fname, num, amount, type_choice, choice, n4);
		n4++;
	}
	else if(choice == 6){                         //大量重复数据 
		crepeatdata(data, amount, type_choice);
		wf(fp, data, fname, num, amount, type_choice, choice, n6);
		n6++;
	}
}

template <typename T> void crepeatdata(T *data, int amount, int type_choice){        //生成大量重复数据 
	int index0 = 0;
	int index = rand() % ((amount + 3) / 2) ;
	if(index > amount) index = amount;
	int r1;
	double r2;
	char r3;
	
	while(index0 != amount){
		if(type_choice == 1) r1 = rand() % (2 * amount) - amount;
		if(type_choice == 2) r2 = (rand() % (2000 * amount) * 0.001 - amount) * 1.0;
		if(type_choice == 3) r3 = rand() % 94 + '!';
		for(int i = index0; i < index; i++){
			if(type_choice == 1) data[i] = r1;
			if(type_choice == 2) data[i] = r2;
			if(type_choice == 3) data[i] = r3;
		}
		index0 = index;
		index = index0 + rand() % ((amount + 3) / 2) + amount / 8;
		if(index > amount) {
			index = amount;
		}
	}
}
	
	
static int n5z = 1, n5f = 1;
template <typename T> void wfscore(FILE *fp, T *data, string fname, char num, int amount, int type_choice, int choice, int n);
template <typename T> void createscore(T *data, int amount, int type_choice, int choice){       //生成结构体 
	static int n5 = 1;
	string fname;
	string num;																		   
	FILE *fp;
	cscore(data, amount);
	if(type_choice == 1) n5 = n5z;
	else n5 = n5f;
	wfscore(fp, data, fname, num, amount, type_choice, choice, n5);
}
	

template <typename T> void wf(FILE *fp, T *data, string fname, string num, int amount, int type_choice, int choice, int n){   //存入文件 
	stringstream ss;
	ss << n;
	ss >> num;
	if(choice == 1) fname = "顺序数据"; 
	if(choice == 2) fname = "逆序数据";
	if(choice == 3) fname = "均匀分布数据";
	if(choice == 4) fname = "正态分布数据";
	if(choice == 5) fname = "结构体数据";
	if(choice == 6) fname = "重复数据";
	if(type_choice == 1) fname += "（整型）"; 
	if(type_choice == 2) fname += "（浮点型）";
	if(type_choice == 3) fname += "（字符型）";
	fname += num;
	fname += ".txt";
	const char *p = fname.data();
	fp = fopen(p, "w+");
	if(choice != 5){
		for(int i = 0; i < amount; i++){
			if(type_choice == 1){                             //整型输出方式 
				if(i == amount-1 || (i + 1) % 18 == 0) fprintf(fp, "%d\n", data[i]);
				else fprintf(fp, "%d ", data[i]);
			}
			if(type_choice == 2){                             //浮点型输出方式 
				if(i == amount-1 || (i + 1) % 11 == 0)  fprintf(fp, "%0.3f\n", data[i]);
				else fprintf(fp, "%0.3f ", data[i]);
			}
			if(type_choice == 3){                            //字符输出方式 
				if(i == amount-1 || (i + 1) % 75 == 0) fprintf(fp, "%c\n", data[i]);
				else fprintf(fp, "%c ", data[i]);
			}
		}
	}
	fclose(fp);	
} 

void menu(int choice, int type_choice);
template <typename T> void pxscore(T *data, T *data0, int k, int type_choice, int j, int mm, int i, string check[20][20], double t[20][20], long long cs[20][20], long long fz[20][20]);
template <typename T> void px(T *data, T *data0, int k, int type_choice, int j, int mm, int i, string check[20][20], double t[20][20], long long cs[20][20], long long fz[20][20]);
void cmpsort(){
	int amount = 0, type_choice = 0;
	string lx[] = {"", "(顺序)", "(逆序)", "(均匀分布)", "(正态分布)", "(结构体)", "(重复)"};
	string tyna[] = {"", "int", "double"};
	string selects[] = {"选择排序", "选择排序(双向优化)"};
	string quicks[] = {"快速排序", "快速排序(Comprehensive)", "快速排序(Insertion)", "快速排序(Middle)", "快速排序(Three)"};
	string insertions[] = {"插入排序", "插入排序(Shell)", "插入排序(Binary)"};
	string bubbles[] = {"冒泡排序", "冒泡排序(Cocktail)", "冒泡排序(Comb)"};
	string *arr[] = {selects, quicks, insertions, bubbles};
	double t[20][20]; 
	long long cs[20][20], fz[20][20];  
	string check[20][20]; 
	string f1c[] = {"selectc", "select2c"};		       	     
	string f1[] = {"select", "select2"}; 
	string f2c[] = {"quickc", "quick2c", "quick3c", "quick4c", "quick5c"};		       	     
	string f2[] = {"quick", "quick2", "quick3", "quick4", "quick5"}; 
	string f3c[] = {"intsertionc", "select2c", "3"};		       	     
	string f3[] = {"select", "select2", "3"}; 
	string f4c[] = {"intsertionc", "select2c", "3"};		       	     
	string f4[] = {"select", "select2", "3"}; 
	int m = sizeof(arr) / sizeof(*arr);                              
	int m1 = sizeof(f1) / sizeof(string);			                            //循环次数
	int m2 = sizeof(f2) / sizeof(string);
	int m3 = sizeof(f3) / sizeof(string);
	int m4 = sizeof(f4) / sizeof(string);
	
	cout << "请选择数据类型（1-整型、2-浮点型、0-返回）:";
	cin >> type_choice;
	if(type_choice == 0){
		menu(0, 0);
		return;
	}
	cout << "请等待..." << endl; 
	for(int i = 1; i < 2; i++){                                                 //i为排序方法 
		int mm; string name;
		if(i == 0){
			mm = m1;
			name = "SelectSort.xlsx";
		}
		if(i == 1){
			mm = m2;
			name = "QuickSort.xlsx";
		}
		if(i == 2){
			mm = m3;
			name = "InsertionSort.xlsx";
		}
		if(i == 3){
			mm = m4;
			name = "BubbleSort.xlsx";
		}
		const char *p = name.data();
		FILE *fp = NULL;
		fp = fopen(p, "w+");
		for(int j = 1; j < 7; j++){		                                     //j为数据结构 
			if(j == 5){
				if(type_choice == 1){
					for(int k = 1; k < 8; k++){                                //k为数据数量 
						score<int> *data = NULL; score<int> *data0 = NULL;
						pxscore(data, data0, k, type_choice, j, mm, i, check, t, cs, fz);
					}	
				}
				else if(type_choice == 2){
					for(int k = 1; k < 8; k++){                               
						score<double> *data = NULL; score<double> *data0 = NULL;
						pxscore(data, data0, k, type_choice, j, mm, i, check, t, cs, fz);
					}	
				}
			}
			else{
				if(type_choice == 1){
					for(int k = 1; k < 8; k++){
						int *data = NULL; int *data0 = NULL;
						px(data, data0, k, type_choice, j, mm, i, check, t, cs, fz);
					}	
				}
				else if(type_choice == 2){
					for(int k = 1; k < 8; k++){ 
						double *data = NULL; double *data0 = NULL;
						px(data, data0, k, type_choice, j, mm, i, check, t, cs, fz);
					}
				}
			}
			string typ = "数据类型:";
			string stru = lx[j];
			fprintf(fp, "%s\t%s%s\t%s\t%s\n", typ.c_str(), tyna[type_choice].c_str(), stru.c_str(), "——", "时间");
			fprintf(fp, "%s\t", "数据数量");
			for(int kk = 0; kk < mm; kk++){
				fprintf(fp, "%s\t", arr[i][kk].c_str());
			}
			fprintf(fp, "\n");
			for(int k = 1; k < 8; k++){
				int amount = pow(2, k-1)* 1024;
				fprintf(fp, "%d\t", amount);
				for(int kk = 0; kk < mm; kk++){
					fprintf(fp, "%0.3f\t", t[kk][k]);
				}
				for(int kk = 0; kk < mm; kk++){
					fprintf(fp, "%s:\t", arr[i][kk].c_str());
					fprintf(fp, "%s\t", check[kk][k].c_str());
				}
				fprintf(fp, "\n");
			}
			fprintf(fp, "\n");
			fprintf(fp, "%s\t%s%s\t%s\t%s\n", typ.c_str(), tyna[type_choice].c_str(), stru.c_str(), "——", "比较次数");                    //输入比较次数 
			fprintf(fp, "%s\t", "数据数量");
			for(int kk = 0; kk < mm; kk++){
				fprintf(fp, "%s\t", arr[i][kk].c_str());
			}
			fprintf(fp, "\n");
			for(int k = 1; k < 8; k++){
				int amount = pow(2, k-1)* 1024;
				fprintf(fp, "%d\t", amount);
				for(int kk = 0; kk < mm; kk++){
					fprintf(fp, "%lld\t", cs[kk][k]);
				}
				for(int kk = 0; kk < mm; kk++){
					fprintf(fp, "%s:\t", arr[i][kk].c_str());
					fprintf(fp, "%s\t", check[kk][k].c_str());
				}
				fprintf(fp, "\n");
			}
			fprintf(fp, "\n");
			fprintf(fp, "%s\t%s%s\t%s\t%s\n", typ.c_str(), tyna[type_choice].c_str(), stru.c_str(), "——", "赋值次数");                    //输入赋值次数 
			fprintf(fp, "%s\t", "数据数量");
			for(int kk = 0; kk < mm; kk++){
				fprintf(fp, "%s\t", arr[i][kk].c_str());
			}
			fprintf(fp, "\n");
			for(int k = 1; k < 8; k++){
				int amount = pow(2, k-1)* 1024;
				fprintf(fp, "%d\t", amount);
				for(int kk = 0; kk < mm; kk++){
					fprintf(fp, "%lld\t", fz[kk][k]);
				}
				for(int kk = 0; kk < mm; kk++){
					fprintf(fp, "%s:\t", arr[i][kk].c_str());
					fprintf(fp, "%s\t", check[kk][k].c_str());
				}
				fprintf(fp, "\n");
			}
			fprintf(fp, "\n");	
		}
		fclose(fp);
		cout << "\t\t\t\t输入任意键，返回" << endl;
		cin >> amount; return;
	}
}


template <typename T> void pxscore(T *data, T *data0, int k, int type_choice, int j, int mm, int i, string check[20][20], double t[20][20], long long cs[20][20], long long fz[20][20]){  //排序score 
	void (*f1c[])(T *begin, T *end, long long &cs, long long &fz) = {selectc, select2c};		       	       // 函数指针数组（元素为一系列函数的入口地址）
	void (*f1[])(T *begin, T *end) = {select, select2};
	void (*f2c[])(T *begin, T *end, long long &cs, long long &fz) = {QuickSortc, QuickSort_comprehensivec, QuickSort_Insertionc, QuickSort_middlec, QuickSort_threec};		       	       
	void (*f2[])(T *begin, T *end) = {QuickSort, QuickSort_comprehensive, QuickSort_Insertion, QuickSort_middle, QuickSort_three};
	void (*f3c[])(T *begin, T *end, long long &cs, long long &fz) = {InsertionSortc, InsertionSort_Shellc, InsertionSort_Binaryc};		       	       
	void (*f3[])(T *begin, T *end) = {InsertionSort, InsertionSort_Shell, InsertionSort_Binary};
	void (*f4c[])(T *begin, T *end, long long &cs, long long &fz) = {BubbleSortc, BubbleSort_Cocktailc, BubbleSort_Combc};		       	       
	void (*f4[])(T *begin, T *end) = {BubbleSort, BubbleSort_Cocktail, BubbleSort_Comb};
	void (**f[])(T *begin, T *end) = {f1, f2, f3, f4};
	void (**fc[])(T *begin, T *end, long long &cs, long long &fz) = {f1c, f2c, f3c, f4c};
	
	int amount = pow(2, k-1)* 1024;
	GetMemory(data, data0, amount);
	createscore(data, amount, type_choice, j);
	copydata(data, data0, amount);
	for(int kk = 0; kk < mm; kk++){
		ReSet(data, data0, amount);
		gettime(1);	
		f[i][kk](data, data + amount -1);
		t[kk][k] = gettime(0);
		if(Check(data, amount) == true) check[kk][k] = "正确";             //检验排序是否正确 
		else check[kk][k] = "错误";
	}
	for(int kk = 0; kk < mm; kk++){
		long long cs2 = 0, fz2 = 0;
		ReSet(data, data0, amount);
		gettime(1);	
		fc[i][kk](data, data + amount -1, cs2, fz2);
		cs[kk][k] = cs2;
		fz[kk][k] = fz2;
	}
	FreeMemory(data, data0);
}

template <typename T> void px(T *data, T *data0, int k, int type_choice, int j, int mm, int i, string check[20][20], double t[20][20], long long cs[20][20], long long fz[20][20]){   //排序 
	void (*f1c[])(T *begin, T *end, long long &cs, long long &fz) = {selectc, select2c};		       	       // 函数指针数组（元素为一系列函数的入口地址）
	void (*f1[])(T *begin, T *end) = {select, select2};
	void (*f2c[])(T *begin, T *end, long long &cs, long long &fz) = {QuickSortc, QuickSort_comprehensivec, QuickSort_Insertionc, QuickSort_middlec, QuickSort_threec};		       	       
	void (*f2[])(T *begin, T *end) = {QuickSort, QuickSort_comprehensive, QuickSort_Insertion, QuickSort_middle, QuickSort_three};
	void (*f3c[])(T *begin, T *end, long long &cs, long long &fz) = {InsertionSortc, InsertionSort_Shellc, InsertionSort_Binaryc};		       	       
	void (*f3[])(T *begin, T *end) = {InsertionSort, InsertionSort_Shell, InsertionSort_Binary};		       	       
	void (*f4c[])(T *begin, T *end, long long &cs, long long &fz) = {BubbleSortc, BubbleSort_Cocktailc, BubbleSort_Combc};		       	       
	void (*f4[])(T *begin, T *end) = {BubbleSort, BubbleSort_Cocktail, BubbleSort_Comb};
	void (**f[])(T *begin, T *end) = {f1, f2, f3, f4};
	void (**fc[])(T *begin, T *end, long long &cs, long long &fz) = {f1c, f2c, f3c, f4c};
	int amount = pow(2, k-1)* 1024;
	GetMemory(data, data0, amount);
	createdata(data, amount, type_choice, j);
	copydata(data, data0, amount);
	for(int kk = 0; kk < mm; kk++){
		ReSet(data, data0, amount);
		gettime(1);	
		f[i][kk](data, data + amount -1);
		t[kk][k] = gettime(0);
		if(Check(data, amount) == true) check[kk][k] = "正确";           //检验排序是否正确 
		else check[kk][k] = "错误";
	}
	for(int kk = 0; kk < mm; kk++){
		long long cs2 = 0, fz2 = 0;
		ReSet(data, data0, amount);
		gettime(1);	
		fc[i][kk](data, data + amount -1, cs2, fz2);
		cs[kk][k] = cs2;
		fz[kk][k] = fz2;
	}
	FreeMemory(data, data0);
}


template <typename T> void wfscore(FILE *fp, T *data, string fname, string num, int amount, int type_choice, int choice, int n){         //score存入文件 
	stringstream ss;
	ss << n;
	ss >> num;
	fname = "结构体数据";
	if(type_choice == 1) fname += "（整型）"; 
	if(type_choice == 2) fname += "（浮点型）";
	fname += num;
	fname += ".txt";
	const char *p = fname.data();
	fp = fopen(p, "w+");
	fprintf(fp, "\t学号\t\t语文\t数学\t英语\t物理\t化学\t总分\n");
	if(type_choice == 1){
		for(int i = 0; i < amount; i++){
			fprintf(fp, "\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", data[i].Id, data[i].Chinese, data[i].Math, 
			data[i].English, data[i].Physics, data[i].Chemistry, data[i].Total);
		} 
		n5z++;
	}
	if(type_choice == 2){
		for(int i = 0; i < amount; i++){
			fprintf(fp, "\t%s\t%0.1f\t%0.1f\t%0.1f\t%0.1f\t%0.1f\t%0.1f\n", data[i].Id, data[i].Chinese, data[i].Math, 
			data[i].English, data[i].Physics, data[i].Chemistry, data[i].Total);
		} 
		n5f++;
	}
	fclose(fp);		
}
	

template <typename T> void showdata(T *data, int amount, int type_choice, int choice){      //输出数据 
	if(choice != 5){
		for(int i = 0; i < amount; i++){
			if(type_choice == 1 || type_choice == 3){          //整型、字符输出方式 
				if(i != amount-1) cout << data[i] << " ";
				else cout << data[i] << endl;
			}
			if(type_choice == 2){                             //浮点型输出方式 
				if(i == amount-1)  printf("%0.3f\n", data[i]);
				else printf("%0.3f ", data[i]);
			}	
		}
	}
}


void exits() {       //退出
	cout << endl;
	cout << endl;
	cout << "\t\t\t\t谢谢使用" << endl;
	Sleep(1200);
	exit(0);
}


static int is_showdata = 0, choice2 = 0, type_choice2 = 0, amount2 = 0;
void menu(int choice, int type_choice);
template <typename T> void sortall(T *data, T *data0, int amount2, int choice2, int type_choice2);
template <typename T> void amount(T *data, T *data0, int choice, int type_choice){                //选择数据数量 
	int amount;
	static T *dataq1;	
	if(choice == 8) {
		sortall(dataq1, dataq1, amount2, choice2, type_choice2);return;
	}
	if(type_choice == 3 && (choice == 1 || choice == 2)) cout << "请输入数据数量（1 ~ 94, 0-返回）：";
	else cout << "请输入数据数量（0-返回）：";
	cin >> amount;
	if(amount == 0) menu(choice, 0);
	else{
		if(type_choice == 3 && (choice == 1 || choice == 2)){
			if(amount > 94){
				cout << "数据过大，请重新输入！" << endl;
				Sleep(1000);
				menu(choice, type_choice); 
				return;
			}
			if(amount < 0){
				cout << "数据过小，请重新输入！" << endl;
				Sleep(1000);
				menu(choice, type_choice);
				return;
			}
		}		
		GetMemory(data, data0, amount);
		createdata(data0, amount, type_choice, choice);
		if(is_showdata == 1)
		showdata(data0, amount, type_choice, choice);
		cout << "\t数据生成成功！" << endl;
		choice2 = choice;
		type_choice2 = type_choice;
		amount2 = amount;
		dataq1 = data0;
		cout << "\t\t\t\t输入任意键，返回" << endl;
		cin >> amount; return;
	}
}


template <typename T> void amountscore(T *data, T *data0, int choice, int type_choice){    //score选择数量 
	int amount;
	static T *dataq = NULL; 
	if(choice == 8) {
		sortscore(dataq, dataq, amount2, choice2, type_choice2);return;
	}
	cout << "请输入数据数量（0-返回）：";
	cin >> amount;
	if(amount == 0) menu(choice, 0);
	GetMemory(data, data0, amount);
	createscore(data0, amount, type_choice, choice);
	if(is_showdata == 1)
	showscore(data0, amount, type_choice); 
	cout << "\t数据生成成功！" << endl;
	choice2 = choice;
	type_choice2 = type_choice;
	amount2 = amount;
	dataq = data0;
	cout << "\t\t\t\t输入任意键，返回" << endl;
	cin >> amount; return;
}


void ctype_choice(int choice, int type_choice){                                 //选择数据类型 
	if(choice == 5) cout << "请选择数据类型（1-整型、2-浮点型、0-返回）:"; 
	else if(choice == 8){
		if(choice2 == 5){
			if(type_choice2 == 1) {
				score<int> *data = NULL; score<int> *data0 = NULL;
				amountscore(data, data0, choice, type_choice2);
			}	
			if(type_choice2 == 2) {
				score<double> *data = NULL; score<double> *data0 = NULL;
				amountscore(data, data0, choice, type_choice2);
			}
		}
		else{
			if(type_choice2 == 1) {
				int *data = NULL; int *data0 = NULL;
				amount(data, data0, choice, type_choice2);
			}
			if(type_choice2 == 2) {
				double *data = NULL; double *data0 = NULL;
				amount(data, data0, choice, type_choice2);
			}	
			if(type_choice2 == 3) {
				char *data = NULL; char *data0 = NULL;
				amount(data, data0, choice, type_choice2);
			}
		}
		return;
	}	
	else cout << "请选择数据类型（1-整型、2-浮点型、3-字符型、0-返回）:"; 
	if(choice == 5){
		cin >> type_choice;
		if(type_choice == 0){
			menu(0, 0);
			return;
		}
		if(type_choice == 1) {
			score<int> *data = NULL; score<int> *data0 = NULL;
			amountscore(data, data0, choice, type_choice);
		}
		if(type_choice == 2) {
			score<double> *data = NULL; score<double> *data0 = NULL;
			amountscore(data, data0, choice, type_choice);
		}		
	}
	else{
		if(type_choice == 0){
			cin >> type_choice;
			if(type_choice == 0){
				menu(0, 0);
				return;
			}
			if(type_choice == 1) {
				int *data = NULL; int *data0 = NULL;
				amount(data, data0, choice, type_choice);
			}
			if(type_choice == 2) {
				double *data = NULL; double *data0 = NULL;
				amount(data, data0, choice, type_choice);
			}	
			if(type_choice == 3) {
				char *data = NULL; char *data0 = NULL;
				amount(data, data0, choice, type_choice);
			}
		}
	 	else{
	 		cout << type_choice << endl;
	 		if(type_choice == 1) {
				int *data = NULL; int *data0 = NULL;
				amount(data, data0, choice, type_choice);
			}
			if(type_choice == 2) {
				double *data = NULL; double *data0 = NULL;
				amount(data, data0, choice, type_choice);
			}
			if(type_choice == 3) {
				char *data = NULL; char *data0 = NULL;
				amount(data, data0, choice, type_choice);
			}
		}
	}
		
} 

template <typename T> void sortall(T *data, T *data0, int amount2, int choice2, int type_choice2){                       //一键排序 
	int amount = 0;
	string lx[] = {"", "顺序", "逆序", "均匀分布", "正态分布", "结构体", "重复"};
	string tyna[] = {"", "int", "double", "char"};
	string selects[] = {"选择排序", "选择排序(双向优化)"};
	string *arr[] = {selects};
	void (*f1c[])(T *begin, T *end, long long &cs, long long &fz) = {selectc, select2c};		              	       // 函数指针数组（元素为一系列函数的入口地址）
	void (*f1[])(T *begin, T *end) = {select, select2};
	double t[100];
	int m1c = sizeof(f1c) / sizeof(*f1c);                                   //循环次数 
	int m1 = sizeof(f1) / sizeof(*f1);
	copydata(data, data0, amount2);
	/*for(int i = 0; i < amount2; i++){
		dataq[i] = data[i];
	} */
	for(int i = 0; i < m1; i++){
		long long fz = 0, cs = 0;
		ReSet(data, data0, amount2);
		gettime(1);	
		f1c[i](data, data + amount2 - 1, cs, fz);
		t[i] = gettime(0);
		if(is_showdata == 1)
		showdata(data, amount2, type_choice2, choice2);cout<<t[i]<<" "<<cs<<" "<<fz<<" ";
		if(Check(data, amount2) == true) cout<<"正确"<<endl;
		cout<<endl;
	}
	cout << "\t\t\t\t输入任意键，返回" << endl;
	cin >> amount; return;
}


template <typename T> void sortscore(T *data, T *data0, int amount2, int choice2, int type_choice2){             //一键排序 
	int amount = 0;
	string lx[] = {"", "顺序", "逆序", "均匀分布", "正态分布", "结构体", "重复"};
	string tyna[] = {"", "int", "double", "char"};
	string selects[] = {"选择排序", "选择排序(双向优化)"};
	string *arr[] = {selects};
	void (*f1c[])(T *begin, T *end, long long &cs, long long &fz) = {selectc, select2c};
	void (*f1[])(T *begin, T *end) = {select, select2};		              	       // 函数指针数组（元素为一系列函数的入口地址）
	double t[100];
	int m1c = sizeof(f1c) / sizeof(*f1c);                                            //循环次数 
	int m1 = sizeof(f1) / sizeof(*f1);
	T *dataq0 = new T[amount2];
	for(int i = 0; i < amount2; i++){
		dataq0[i] = data[i];		
	} 
	for(int i = 0; i < m1; i++){
		long long cs = 0, fz = 0;
		ReSet(data, dataq0, amount2);
		gettime(1);	
		f1c[i](data, data + amount2 - 1, cs, fz);
		t[i] = gettime(0);
		if(is_showdata == 1)
		showscore(data, amount2, type_choice2);cout<<t[i]<<" "<<cs<<" "<<fz<<" "; 
		if(Check(data, amount2) == true) cout<<"正确"<<endl;
		cout<<endl;
	}
	cout << "\t\t\t\t输入任意键，返回" << endl;
	cin >> amount; return;
}


void menu(int choice, int type_choice){                        //显示主菜单 
	system("cls");
	cout << "            ~~~~~~~~~~~~~~~~~~ 欢迎来到数据生成系统 ~~~~~~~~~~~~~~~~~~              " << endl
		<< endl
		<< "---------" << "                     1--生成顺序数据                  " << "---------" << endl
		<< "---------" << "                     2--生成逆序数据                  " << "---------" << endl
		<< "---------" << "                     3--生成均匀分布数据              " << "---------" << endl
		<< "---------" << "                     4--生成正态分布数据              " << "---------" << endl
		<< "---------" << "                     5--生成结构体数据                " << "---------" << endl
		<< "---------" << "                     6--生成大量重复数据              " << "---------" << endl;
	if(is_showdata == 0) cout
		<< "---------" << "                     7--开启数据显示                  " << "---------" << endl;
	else cout
		<< "---------" << "                     7--关闭数据显示                  " << "---------" << endl;
	cout<< "---------" << "                     8--一键排序                      " << "---------" << endl
		<< "---------" << "                     9--比较排序                      " << "---------" << endl
		<< "---------" << "                     10--退出系统                     " << "---------" << endl
		<< endl
		<< "请输入您想要进行的操作：";
		if(choice == 0) {
			cin >> choice;
			if(choice == 10){
				exits();
			}
			else if(choice == 9) cmpsort();
			else if(choice == 7){
				if(is_showdata == 0){
					cout << "\t数据显示已开启!" << endl;
					is_showdata = 1;
					Sleep(1000); 
				}
				else{
					cout << "\t数据显示已关闭!" << endl;
					is_showdata = 0;
					Sleep(1000); 
				}
			}
			else ctype_choice(choice, type_choice);
		}
		else {
			cout << choice << endl;
			ctype_choice(choice, type_choice);		
		}

}


int main(){	
	srand(time(0));
	rand();
	while(true){
		int choice = 0;
		int type_choice = 0;
		menu(choice, type_choice);
	}
	system("pause");
	return 0;
}
