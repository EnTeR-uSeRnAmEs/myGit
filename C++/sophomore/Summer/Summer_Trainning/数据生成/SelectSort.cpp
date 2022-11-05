#include <iostream>
#include <ctime>
using namespace std;

/*template <typename T> void select(T *data, int amount, int &cmpn, int &fzn){	// 选择排序
	T temp;
	int i, j, min = 0;
	for(i = 1; i < amount; i++){						
		for(j = i; j < amount; j++){
			if(data[j] < data[min]) min = j;	
			cmpn ++;		
		}										
		if(min != i-1){								
			temp = data[min];
			data[min] = data[i-1];
			data[i-1] = temp;
			fzn++;
		}
		min = i;
	}
}*/

/*template <typename T> void select(T *data, int amount){	// 选择排序
	T temp;
	int i, j, min = 0;
	for(i = 1; i < amount; i++){						
		for(j = i; j < amount; j++){
			if(data[j] < data[min]) min = j;			
		}										
		if(min != i-1){								
			temp = data[min];
			data[min] = data[i-1];
			data[i-1] = temp;
		}
		min = i;
	}
}*/


/*template <typename T> void select2(T *data, int amount, int &cmpn, int &fzn){	// 选择排序（双向优化） 
	T temp;
	int i, j, min = 0, max = amount - 1, num, maxz;
	if(amount % 2 == 0) num = amount / 2;
	else num = (amount - 1) / 2;
	for(i = 1; i <= num; i++){						
		for(j = i; j < amount + 1 - i; j++){
			if(data[j] < data[min]) min = j;
			if(data[amount - 1 - j] > data[max]) max = amount - 1 - j;	
			cmpn += 2;		
		}	
		maxz = 	data[max];			                           //记录最大值					
		if(min != i-1){								
			temp = data[min];
			data[min] = data[i-1];
			data[i-1] = temp;
			fzn++;
		}
		if(data[min] == maxz) max = min;
		if(max != amount - i){								
			temp = data[max];
			data[max] = data[amount - i];
			data[amount - i] = temp;
			fzn++;	
		}
		min = i;
		max = amount - i - 1;
	}
}*/




double gettime(int restart){				// 参数带默认值，非零表示重新计时，否则累计计时
	const double c = 1.0 / CLOCKS_PER_SEC;
	static clock_t t ;           			// 静态局部变量。第一次调用时，确定计时起点
	if(restart) t = clock();				// 根据实参决定是否重新确定计时起点
	return c * (clock() - t);					// 从上一计时点到现在所经历的时间
}

/*int main(){
	
	system("pause");
	return 0;
} */





