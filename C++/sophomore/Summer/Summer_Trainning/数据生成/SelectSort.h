#ifndef SELECT_SORT_H
#define SELECT_SORT_H
#include<bits/stdc++.h>
using namespace std;

template <typename T> void select(T begin, T end){	// 选择排序
	auto temp = *begin;
	int i, j, min = 0, amount = end - begin + 1;;
	for(i = 1; i < amount; i++){						
		for(j = i; j < amount; j++){
			if(*(begin + j) < *(begin + min)) min = j;	
		}										
		if(min != i-1){								
			temp = *(begin + min);
			*(begin + min) = *(begin + i - 1);
			*(begin + i - 1) = temp;
		}
		min = i;
	}
}


template <typename T>
void exchange(T a, T b)
{
    auto tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

/*template <typename T> void selectc(T begin, T end, int &cs, int &fz){	// 选择排序
	auto temp = *begin;
	int i, j, min = 0, amount = end - begin + 1;;
	for(i = 1; i < amount; i++){						
		for(j = i; j < amount; j++){
			if(*(begin + j) < *(begin + min)) min = j;
			cs++;		
		}										
		if(min != i-1){								
			temp = *(begin + min);
			*(begin + min) = *(begin + i - 1);
			*(begin + i - 1) = temp;
			fz++;
		}
		min = i;
	}
}*/

template <typename T> void selectc(T begin, T end, long long &cs, long long &fz){	// 选择排序
	auto temp = *begin;
	int i, j, min = 0, amount = end - begin + 1;;
	for(i = 1; i < amount; i++){						
		for(j = i; j < amount; j++){
			if(*(begin + j) < *(begin + min)) min = j;
			cs++;		
		}										
		if(min != i-1){								
			temp = *(begin + min);
			*(begin + min) = *(begin + i - 1);
			*(begin + i - 1) = temp;
			fz+=3;
		}
		min = i;
	}
}

template <typename T> void select2(T begin, T end){	// 选择排序（双向优化） 
	auto temp = *begin;
	auto maxz = *begin;
	int i, j, min = 0, amount = end - begin + 1, num, max = amount - 1;
	if(amount % 2 == 0) num = amount / 2;
	else num = (amount - 1) / 2;
	for(i = 1; i <= num; i++){						
		for(j = i; j < amount + 1 - i; j++){
			if(*(begin + j) < *(begin + min)) min = j;
			if(*(begin + amount - 1 - j) > *(begin + max)) max = amount - 1 - j;		
		}	
		maxz = *(begin + max);			                           //记录最大值				
		if(min != i-1){								
			temp = *(begin + min);
			*(begin + min) = *(begin + i-1);
			*(begin + i-1) = temp;
		}
		if(*(begin + min) == maxz) max = min;
		if(max != amount - i){								
			temp = *(begin + max);
			*(begin + max) = *(begin + amount - i);
			*(begin + amount - i) = temp;
		}
		min = i;
		max = amount - i - 1;
	}
}

/*template <typename T> void select2c(T begin, T end, long long &cs, long long &fz){	// 选择排序（双向优化） 
	auto temp = *begin;
	auto maxz = *begin;
	int i, j, min = 0, amount = end - begin + 1, num, max = amount - 1;
	if(amount % 2 == 0) num = amount / 2;
	else num = (amount - 1) / 2;
	for(i = 1; i <= num; i++){						
		for(j = i; j < amount + 1 - i; j++){
			if(*(begin + j) < *(begin + min)) min = j;
			if(*(begin + amount - 1 - j) > *(begin + max)) max = amount - 1 - j;
			cs += 2;		
		}	
		maxz = *(begin + max);			                           //记录最大值				
		if(min != i-1){								
			temp = *(begin + min);
			*(begin + min) = *(begin + i-1);
			*(begin + i-1) = temp;
			fz++;
		}
		if(*(begin + min) == maxz) max = min;
		if(max != amount - i){								
			temp = *(begin + max);
			*(begin + max) = *(begin + amount - i);
			*(begin + amount - i) = temp;
			fz++;
		}
		min = i;
		max = amount - i - 1;
	}
}*/

template <typename T> void select2c(T begin, T end, long long &cs, long long &fz){	// 选择排序（双向优化） 
	auto temp = *begin;
	auto maxz = *begin;
	int i, j, min = 0, amount = end - begin + 1, num, max = amount - 1;
	if(amount % 2 == 0) num = amount / 2;
	else num = (amount - 1) / 2;
	for(i = 1; i <= num; i++){						
		for(j = i; j < amount + 1 - i; j++){
			if(*(begin + j) < *(begin + min)) min = j;
			if(*(begin + amount - 1 - j) > *(begin + max)) max = amount - 1 - j;
			cs += 2;		
		}	
		maxz = *(begin + max);			                           //记录最大值				
		if(min != i-1){								
			temp = *(begin + min);
			*(begin + min) = *(begin + i-1);
			*(begin + i-1) = temp;
			fz+=3;
		}
		if(*(begin + min) == maxz) max = min;
		if(max != amount - i){								
			temp = *(begin + max);
			*(begin + max) = *(begin + amount - i);
			*(begin + amount - i) = temp;
			fz+=3;
		}
		min = i;
		max = amount - i - 1;
	}
}


template <typename T> void copydata(T *data, T *&data0, int amount){   //复制数据 
	data0 = new T[amount];
	for(int i = 0; i < amount; i++){
		data0[i] = data[i];
	} 
}
	


template <typename T> void ReSet(T *data, T *data0, int amount){   	// 用于恢复"原始数据"，以保证不同的排序算法处理完全相同的数据
	for(int i = 0; i < amount; i++)
		data[i] = data0[i];
}


template <typename T> bool Check(T *data, int amount){				// 仅检验数组元素是否满足升序（并未进行严格的正确性检查）
	for(int i = 1; i < amount; i++)
		if(data[i-1] > data[i])
			return false;
	return true;
}

double gettime(int restart);

#endif
