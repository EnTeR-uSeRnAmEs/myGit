#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <time.h>
#include <cstdio>
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
	
	/*bool operator< (const score &s){                                     // ����6����ϵ���������
		if(Total < s.Total) return true;
		else if(Total == s.Total && Math < s.Math) return true;
		else if(Total == s.Total && Math == s.Math && Physics < s.Physics) return true;
		else if(Total == s.Total && Math == s.Math && Physics == s.Physics && Chemistry < s.Chemistry) return true;
		else if(Total == s.Total && Math == s.Math && Physics == s.Physics && Chemistry == s.Chemistry && English <  s.English) return true;
		else if(Total == s.Total && Math == s.Math && Physics == s.Physics && Chemistry == s.Chemistry && English ==  s.English && Chinese <  s.Chinese) return true;
		else return false;	 
	}	
	bool operator<=(const score &s){                                   	// ʹ�������ṹ�����֮�����ֱ�ӽ��бȽ�
		if(operator< (s) == true || operator==(s) == true) return true;
		else return false;	
	}   
	bool operator> (const score &s){ 
		if(Total > s.Total) return true;
		else if(Total == s.Total && Math > s.Math) return true;
		else if(Total == s.Total && Math == s.Math && Physics > s.Physics) return true;
		else if(Total == s.Total && Math == s.Math && Physics == s.Physics && Chemistry > s.Chemistry) return true;
		else if(Total == s.Total && Math == s.Math && Physics == s.Physics && Chemistry == s.Chemistry && English >  s.English) return true;
		else if(Total == s.Total && Math == s.Math && Physics == s.Physics && Chemistry == s.Chemistry && English ==  s.English && Chinese >  s.Chinese) return true;
		else return false;
	}	
	bool operator>=(const score &s){ 
		if(operator> (s) == true || operator==(s) == true) return true;
		else return false;	
	}
	bool operator==(const score &s){
		if(Total == s.Total && Math == s.Math && Physics == s.Physics && Chemistry == s.Chemistry && English ==  s.English && Chinese ==  s.Chinese) return true;
		else return false;
	}
	bool operator!=(const score &s){ 
		if(Total != s.Total || Math != s.Math || Physics != s.Physics || Chemistry != s.Chemistry || English !=  s.English || Chinese !=  s.Chinese) return true;
		else return false;
	}*/
};


double GaussRand(){	               // ������̬�ֲ����ݣ�mena:��ֵ����ѧ������variance��� 
	static double u, v;
	static int phase = 0;
	double z, mean = 77 * 1.0, variance = (rand() % 30 + 1) * 1.0;

	if(phase == 0){
		u = (rand() + 1.0) / (RAND_MAX + 1.0);	// ����u��vΪ0ʱ�������log����
		v = (rand() + 1.0) / (RAND_MAX + 1.0);
		z = sqrt(-2.0 * log(u))* sin(2.0 * M_PI * v);
	}
	else{
		z = sqrt(-2.0 * log(u)) * cos(2.0 * M_PI * v);
	}
	phase = 1 - phase;
	return mean + z*sqrt(variance);
}



