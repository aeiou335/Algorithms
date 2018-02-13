// **************************************************************************
//  File       [main.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of worker ant function]
//  Modify     [Yun-Kuan Lin]
// **************************************************************************

#include "WorkerAnt.h"
#include <iostream>
#include <cmath>

using namespace std;



work::work(){}

int work::origin(Food point){
	int distorigin = 0;
	distorigin = point.x + point.y;
	return distorigin;
}

int work::dist(int start, int end, Food *food){
	int total_distance = 0;
	for (int i = start; i < end; i++){
	   total_distance += abs(food[i].x - food[i+1].x) + abs(food[i].y - food[i+1].y);
	}
	return total_distance;
}

void work::DPWorkerAnt(int cap, int n, Food *food){
	 //d[i] = min{d[j] + origin[j + 1] + dist(j+1 , i) + origin[i]}
	for(int j = 1; j <= n; j++){
		int cur_cap = food[j].weight;
		int temp_dis;
		for (int target = j-1; cur_cap <= cap && target >= 0; target--){
			temp_dis = food[target].distance + origin(food[target+1]) + dist(target+1, j, food) + origin(food[j]);
			cur_cap += food[target].weight;
			if(temp_dis < food[j].distance){
				food[j].distance = temp_dis;
				food[j].back = target;
			}
			
		}
	}

}

void work::GDWorkerAnt(int cap, int n, Food *foodGD){
	int cur_gdcap = 0;
	int temp = 0;
  cur_gdcap += foodGD[1].weight;
	for (int k = 1; k <= n; k++){
		 cur_gdcap += foodGD[k+1].weight;
		 if (cur_gdcap > cap){
		 	foodGD[k].distance = foodGD[temp].distance + origin(foodGD[temp+1]) + dist(temp+1, k, foodGD) + origin(foodGD[k]);
		 	foodGD[k].back = temp;
		 	temp = k;
		 	cur_gdcap = foodGD[k+1].weight;
		 }
		 else if (k == n){
		 	foodGD[k].distance = foodGD[temp].distance + origin(foodGD[temp+1]) + dist(temp+1, k, foodGD) + origin(foodGD[k]);
		 	foodGD[k].back = temp;
		 }
		 else
		 	continue;

	}

}
