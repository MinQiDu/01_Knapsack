#使用tabu search解0/1 knapsack problem


## 1.基本說明 ##

-Using C++
-implement tabu search algorithm to solve 0/1 knapsack problem


## 2.主要功能 ##

-tabu_ks() 使用tabu search搜尋最佳解，避免陷入局部最佳解。
-initial() 生成不超過背包容量的隨機解
-tweak() 微調解生成相異且不超過背包容量的解
-p_count() 計算解sol的profit總和


## 3.Input ##

-物品數量 | item = 10
-背包容量 | capacity = 165
-物品價值 | profit = {92,57,49,68,60,43,67,84,87,72}
-物品容量 | weight = {23,31,29,44,53,38,63,85,89,82}
-tabu list大小 | tabu_size = 10
-tweak 次數 | tweak_c = 20
-迭帶次數 | itr = 1000


## 4.Output ##

-max profit:309
-solution:1111010000
-(執行結果截圖附在.zip檔中)


## 5.執行方式 ##

在 Windows cmd 或 PowerShell 中，輸入：
tabu_01knapsack.exe
