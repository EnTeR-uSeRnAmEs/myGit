#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <time.h>

using namespace std;

template <typename T> struct score{    //���������ṹ�� 
	char Id[9];
	T Chinese;
	T Math;
	T English;
	T Physics;
	T Chemistry;
	T Total;
	score *next;
	
	bool operator< (const score &s){                                     // ����6����ϵ���������
		return Total <  s.Total;
	}	
	bool operator<=(const score &s){                                   	// ʹ�������ṹ�����֮�����ֱ�ӽ��бȽ�
		return Total <= s.Total;	
	}   
	bool operator> (const score &s){ 
		return Total >  s.Total;
	}	
	bool operator>=(const score &s){ 
		return Total >= s.Total;	
	}
	bool operator==(const score &s){
		return Total == s.Total;
	}
	bool operator!=(const score &s){ 
		return Total != s.Total;
	}
};

double GaussRand();

template <typename T> void cscore(T *data, int amount){     //����score�ṹ������ 
	for(int i = 0; i < amount; i++){
		sprintf(data[i].Id, "%08d", i+1);	                //"%08d":������Ϊ8��ǰ�油0������ 
		data[i].Chinese   = (int(GaussRand()  * 10000) / 1000) * 0.1;	
	 	data[i].Math      = (int(GaussRand()  * 10000) / 1000) * 0.1;
		data[i].English   = (int(GaussRand()  * 10000) / 1000) * 0.1;
		data[i].Physics   = (int(GaussRand()  * 10000) / 1000) * 0.1;
		data[i].Chemistry = (int(GaussRand()  * 10000) / 1000) * 0.1;
		data[i].Total = data[i].Chinese + data[i].Math + data[i].English + data[i].Physics + data[i].Chemistry;
		data[i].Total = (int(data[i].Total  * 10000) / 1000) * 0.1;
	}
}


template <typename T> void showscore(T *data, int amount, int type_choice){
		cout << "\tѧ��\t\t����\t��ѧ\tӢ��\t����\t��ѧ\t�ܷ�" << endl;
		if(type_choice == 1){
			for(int i = 0; i < amount; i++){
				printf("\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", data[i].Id, data[i].Chinese, data[i].Math, 
				data[i].English, data[i].Physics, data[i].Chemistry, data[i].Total);
			} 
		}
		if(type_choice == 2){
			for(int i = 0; i < amount; i++){
				printf("\t%s\t%0.1f\t%0.1f\t%0.1f\t%0.1f\t%0.1f\t%0.1f\n", data[i].Id, data[i].Chinese, data[i].Math, 
				data[i].English, data[i].Physics, data[i].Chemistry, data[i].Total);
			} 
		}	
}
/*int main(){
	score *data;
	data = new score[5];
	srand(time(0));
	rand();
	for(int i=0;i<5;i++){
		data[i].Total  = data[i].Chinese   = rand() % 150 + rand() % 9 * 0.1;	// ��0.5��ȡ����С������"��������"
		data[i].Total += data[i].Math      = rand() % 150 + rand() % 9 * 0.1;
		data[i].Total += data[i].English   = rand() % 150 + rand() % 9 * 0.1;
		data[i].Total += data[i].Physics   = rand() % 150 + rand() % 9 * 0.1;
		data[i].Total += data[i].Chemistry = rand() % 150 + rand() % 9 * 0.1;
	}
	data[1].Total =10;data[1].Chemistry=data[1].English=data[1].Math=100;data[1].Physics = 100;
	data[2].Total =10;data[2].Chemistry=data[2].English=data[2].Math=100;data[2].Physics = 100;
	data[1].Chinese =0;data[2].Chinese=11;
	//cout<<data[1].Total<<" "<<data[2].Total<<endl;
	if(data[1] > data[2]) cout << "1>2"<<endl;
	system("pause");
	return 0;
}*/
