// **************************************************************************
//  File       [main.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The main program of 2015 Spring Algorithm PA1]
//  Modify     [Yun-Kuan Lin]
// **************************************************************************

#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "../lib/tm_usage.h"
#include "WorkerAnt.h"

using namespace std;


void help_message() {
    cout << "usage: WorkerAnt -[GD|DP] <input_file> <output_file>" << endl;
    cout << "options:" << endl;
    cout << "   GD  - Greedy" << endl;
    cout << "   DP  - Dynamic Programming" << endl;
}

int main(int argc, char* argv[])
{
    if(argc != 4) {
       help_message();
       return 0;
    }
    CommonNs::TmUsage tmusg;
    CommonNs::TmStat stat;

    //////////// read the input file /////////////
    fstream fin(argv[2]);
    fstream fout;
    fout.open(argv[3],ios::out);
    int cap, n, i;
    fin >> cap;
    fin >> n;
    
    Food food[n+2]; 
    food[0].x = 0;
    food[0].y = 0;
    food[0].weight = 0;
    food[0].distance = 0;
    food[0].back = -1;
    food[n+1].x = 0;
    food[n+1].y = 0;
    food[n+1].weight = 0;
    food[n+1].distance = 0;
    food[n+1].back = -2;
    for( i = 1; i <= n; i++){
        int a, b, c;
        fin >> a >> b >> c;
        food[i].x = a;
        food[i].y = b;
        food[i].weight = c;
        food[i].distance = 2147483640;
        food[i].back = -1;
        
    }
    
    //////////// find the solution to pick up the food ////
    work keepworking;
    tmusg.periodStart();

    if(strcmp(argv[1], "-GD") == 0) {
       // greedy 
        keepworking.GDWorkerAnt(cap, n, food);
    }
    else if(strcmp(argv[1], "-DP") == 0) {
      // dynamic programming  
        keepworking.DPWorkerAnt(cap, n, food);
    }
    else {
        help_message();
        return 0;
    }

    tmusg.getPeriodUsage(stat);

    //////////// write the output file ///////////


    cout <<"# run time = " << (stat.uTime + stat.sTime) / 1000000.0 << "sec" << endl;
    cout <<"# memory =" << stat.vmPeak / 1000.0 << "MB" << endl;
    vector<int> v;
    v.push_back(n);
    int t = n;
    while(n > 0 && food[n].back > 0){
        if(food[n].back > 0){
            v.push_back(food[n].back);
            n = food[n].back;
          }
        }
    for (int l = v.size(); l >= 0; l--){
        if(v[l]!=0)
            fout << v[l] << endl;
            }
    
    fout<<food[t].distance<< endl;
    fin.close();
    fout.close();
    return 0;

}


