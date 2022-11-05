#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <time.h>
#include <cstdio>
using namespace std;

template <typename T> struct score{    //建立分数结构体 
	char Id[9];
	T Chinese;
	T Math;
	T English;
	T Physics;
	T Chemistry;
	T Total;
	score *next;
	
	/*bool operator< (const score &s){                                     // 重载6个关系运算符函数
		if(Total < s.Total) return true;
		else if(Total == s.Total && Math < s.Math) return true;
		else if(Total == s.Total && Math == s.Math && Physics < s.Physics) return true;
		else if(Total == s.Total && Math == s.Math && Physics == s.Physics && Chemistry < s.Chemistry) return true;
		else if(Total == s.Total && Math == s.Math && Physics == s.Physics && Chemistry == s.Chemistry && English <  s.English) return true;
		else if(Total == s.Total && Math == s.Math && Physics == s.Physics && Chemistry == s.Chemistry && English ==  s.English && Chinese <  s.Chinese) return true;
		else return false;	 
	}	
	bool operator<=(const score &s){                                   	// 使得两个结构体变量之间可以直接进行比较
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


double GaussRand(){	               // 产生正态分布数据（mena:均值、数学期望，variance方差） 
	static double u, v;
	static int phase = 0;
	double z, mean = 77 * 1.0, variance = (rand() % 30 + 1) * 1.0;

	if(phase == 0){
		u = (rand() + 1.0) / (RAND_MAX + 1.0);	// 避免u或v为0时参与对数log计算
		v = (rand() + 1.0) / (RAND_MAX + 1.0);
		z = sqrt(-2.0 * log(u))* sin(2.0 * M_PI * v);
	}
	else{
		z = sqrt(-2.0 * log(u)) * cos(2.0 * M_PI * v);
	}
	phase = 1 - phase;
	return mean + z*sqrt(variance);
}



