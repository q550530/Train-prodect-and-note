# 學習筆記
 
**C/C++ 使用者自建型別**
1. enum 列舉
2. struct 結構
3. class 類別
4. typedef 重新定義型態名稱
5. union 共用結構
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
* typedef 重新定義型態名稱
```
typeof struct [structName] {
 char name[16];
 int age;
 struct [structName] *ptr;
} PERSON;

int main () {
 PERSON person1 = {"Amy", 20 };
 person.age = 21;
}
```
*  union 共用結構
```
union data{
 char c;
 int num;
 double fnum;
};
union data a, b;
```
Note:  
電腦架構早期記憶體空間比較不足，因此需要使用共用結構讓各變數共用一塊記憶體，union 所需的記憶體空間大小由最大的成員變數決定，例如上述 union 的大小為 8 位元組 (upper bound double)。
struct 是每個成員變數都配置一段空間，union 則是共用一段記憶體空間。另外，union 需注意記憶體內的排列方式，如 little-endian 方法排列，int 會放在 double 的 byte 3~0 的位置，從而改變 double 讀取時的值。

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
