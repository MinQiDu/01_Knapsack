#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <queue>
#include <set>

using namespace std;

/*生成不超過背包容量的隨機解*/
void initial(int item, int capacity, int weight[], queue<string> &L, set<string> &L_set)
{
    string S;
    while (true)
    {
        S = "";
        int cap_sum = 0;
        for (int i = 0; i < item; i++) /*生成初始隨機解*/
        {
            int bit = rand() % 2;
            S += '0' + bit;
            cap_sum += bit * weight[i]; /*cap_sum = 加總此解的總容量*/
        }

        if (cap_sum <= capacity) /*check有無超出背包容量capacity*/
        {
            L.push(S); /*若沒超過則push此解進L*/
            L_set.insert(S);
            return;
        }
    }
}

/*微調解生成相異且不超過背包容量的解*/
string tweak(int item, string S, int capacity, int weight[], int tweak_c)
{
    for (int t = 0; t < tweak_c; t++)
    {
        string temp = S;
        int rd_bit = rand() % 10; /*隨機選取0~9之一數*/
        if (temp[rd_bit] == '0')  /*對string S的此bit進行更動，0變1，1變0*/
        {
            temp[rd_bit] = '1';
        }
        else
        {
            temp[rd_bit] = '0';
        }

        int cap_sum = 0; /*check微調後是否有超過背包容量*/
        for (int i = 0; i < item; i++)
        {
            int item_take = temp[i] - '0';
            cap_sum += item_take * weight[i];
        }

        if (cap_sum <= capacity)
        {
            return temp; /*若無超過背包容量，則return此微調解*/
        }
    }
    return S; /*若嘗試tweak_c次依然沒有找到吳超過背包容量的解，則return原S*/
}

/*計算解sol的profit總和*/
int p_count(int item, string sol, int profit[])
{
    int p_sum = 0;
    for (int i = 0; i < item; i++)
    {
        p_sum += (sol[i] - '0') * profit[i];
    }
    return p_sum;
}

/*使用tabu search解0/1 knapsack problem*/
void tabu_ks(int item, int capacity, int profit[], int weight[], int tabu_size, int tweak_c, queue<string> &L, set<string> &L_set, int itr)
{
    initial(item, capacity, weight, L, L_set); /*生成初始值S，push in L*/
    string S = L.front();
    string best = S; /*當前最佳解best*/
    int best_profit = p_count(item, S, profit);
    int itr_count = 0; /*紀錄iteration次數*/

    while (itr_count < itr) /*iteration跑1000次*/
    {
        if (L.size() > tabu_size)
        {
            L_set.erase(L.front());
            L.pop();
        }

        string R = tweak(item, S, capacity, weight, tweak_c); /*R為S微調後的解*/

        if (L_set.find(R) == L_set.end()) /*如果R解不存在tabu list L 中，則S = R且L.push(R)*/
        {
            S = R;
            L.push(R);
            L_set.insert(R);
        }

        int new_profit = p_count(item, R, profit);

        if (new_profit > best_profit) /*不管R有無存在tabu list，如果R解所得的profit(R, profit)比當前best解的profit(best, profit)高，則best解更新為R解*/
        {
            best = R;
            best_profit = new_profit;
        }

        itr_count++;
    }

    cout << "max profit:" << best_profit << endl; /*output*/
    cout << "solution:" << best << endl;
}

int main()
{
    srand(time(NULL));
    int item = 10;                                             /*物品數量*/
    int capacity = 165;                                        /*背包容量*/
    int profit[10] = {92, 57, 49, 68, 60, 43, 67, 84, 87, 72}; /*物品價值*/
    int weight[10] = {23, 31, 29, 44, 53, 38, 63, 85, 89, 82}; /*物品容量*/
    int itr = 1000;                                            /*iteration counts*/
    int tabu_size = 10;                                        /*tabu list，大小10*/
    int tweak_c = 20;                                          /*tweak counts*/
    queue<string> L;                                           /*FIFO tabu list L*/
    set<string> L_set;                                         /*tabu set紀錄tabu list內容*/

    tabu_ks(item, capacity, profit, weight, tabu_size, tweak_c, L, L_set, itr);
    return 0;
}