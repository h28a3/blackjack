#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

extern int deck[13]; //山札記録用変数

int initialization(void);
int betting(int);
int sum_card(vector<int> a);
int draw();
void show_card(vector<int>);
