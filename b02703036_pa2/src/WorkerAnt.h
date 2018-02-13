// **************************************************************************
//  File       [WorkerAnt.h]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The header file of worker ant]
//  Modify     [Yun-Kuan Lin]
// **************************************************************************

#ifndef _WORKERANT_H
#define _WORKERANT_H
using namespace std;

typedef struct 
{
    int x;
    int y;
    int weight;
    int distance;
    int back;
}Food;
class work{
	public:
		work();//constructor
		int origin(Food);//calculate the distance from origin to food
		int dist(int, int, Food*);//calculate the distance between from food a to food b
		void DPWorkerAnt(int, int, Food*);//solve the problem by using DP
		void GDWorkerAnt(int, int, Food*);//solve the problem by using GD
};

#endif
