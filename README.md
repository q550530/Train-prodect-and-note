# 學習筆記
 
**C/C++ 使用者自建型別**
1. enum 列舉
2. struct 結構
3. class 類別
 * enum 列舉
```
#define empty 0
#define occupied 1
=>
enum STATUS{
	empty = 1,        
	occupied,
	a = 5,
	b   
};
```
* struct 結構

```
struct STU{
 int iNum;
 string sName

};
```
* class 類別
```
class CComplex{
private:
      double real;
      double image;
public:
     ...
};

CComplex cpxA(2.3, 4.5);
```
---------------------------- 
**STL 標準樣板函示庫**
1. 容器 container
   (1) stack 、queue、linked list
   (2) tree、graph
2. 迭代器 iterator
3. 演算法  algorithm
4. 函式物件  object function

**第一個容器 vector**
向量容器 : 實作 堆疊(stack)
#include <vector>
特性:
   1) LIFO (Last In First Out)
   2) 因為新增(push) 刪除(pop) 都在同一端
應用:
   老鼠走迷宮

-----------------------------
 
 **Overloading 負載/多載 : 多重函式的使用**
1. 在C語言，函式名稱是不能重複的；會有不同的使用時機點，但是功能是一樣的
 ex: 
 ```
  int getSum1(int, int);
  float getSum2(float, float);
 ```
  2.C++ 改進，允許函式名稱可以重複，只要函示特徵不同即可
           函式特徵有兩個：
   * 參數型別不同
   * 參數個數不同
 ```
 int getSum(int, int);
 float getSum(float, float);       
 int getSum(int, int, int);  
 ```
-----------------------------
**Template 樣板**
 
 *函式樣版
 ```
template<class T>
T getSum(T a, T b){
     return a+b;
}

 
getSum(2, 3);
getSum(2.1f, 3.4f);
 
 ```
 
 *類別樣板
 ```
template <class T, int SIZE = 10>
class STACK{
private:
	T data[SIZE];
	int iTop;
public:
	STACK<T, SIZE>():iTop(-1){}
	
};
```
