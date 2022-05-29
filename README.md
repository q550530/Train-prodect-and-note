# 學習筆記
**指標** 

1.指標 (pointer)：一個指向某個儲存位址的變數
 ```
 int *ptr = &var;
 ```
其中  
  & : 取變數位址  
  ** : 表示為指標變數  

也可用於函數變為函式指標 (function pointer)，語法為  
```
void (*fptr)(type_a, type_b) = &func;
```
2. 基礎指標判讀  

指標判讀大原則為「從右讀到左」，例如：  
```
int a; // 一個整型數
int *a; // 一個指向整數的指標
int **a; // 一個指向指標的指標，它指向的指標是指向一個整型數
int a[10]; // 一個有10個整數型的陣列
int *a[10]; // 一個有10個指標的陣列，該指標是指向一個整數型的
int (*a)[10]; // 一個指向有10個整數型陣列的指標
int (*a)(int); // 一個指向函數的指標，該函數有一個整數型參數並返回一個整數
int (*a[10])(int); // 一個有10個指標的陣列，該指標指向一個函數，該函數有一個整數型參數並返回一個整數
```
3. 指標與其他關鍵字混用  
一樣右讀到左，例如： 
```
const int * foo; // 一個 pointer，指向 const int 變數。
int const * foo; // 一個 pointer，指向 const int 變數。
int * const foo; // 一個 const pointer，指向 int 變數。
int const * const foo; // 一個 const pointer，指向 const int 變數。
```


 ---------------------------- 
**bitwise operator**  
 邏輯上的運算子在 C 中的語法分別如下：  
AND （&）  
OR（|）  
NOT（!）  
XOR（^）// bit值不一樣為 1  
complement（~）  
shift (<<, >>)  

bitwise 的操作常與 "0x" 這種 16 進位表示法，方便轉換操作。  
 
* Normal operator  
``` 
unsigned long num_a = 0x00001111;
unsigned long num_b = 0x00000202;
unsigned long num_c;

num_c = num_a & (~num_b);
num_c = num_c | num_b;

cout<<(num_c); // 00001313
 ```
* mask method and bitwise opreator
 ```
a = a | 7    // 最右側 3 位設為 1，其餘不變。
a = a & (~7) // 最右側 3 位設為 0，其餘不變。
a = a ^ 7    // 最右側 3 位執行 NOT operator，其餘不變。
 ```
 
----------------------------- 
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
///用於結構時
typedef struct [structName] {
 char name[16];
 int age;
 struct [structName] *ptr;
} PERSON;

int main () {
 PERSON person1 = {"Amy", 20 };
 person.age = 21;
}

typedef void DRAWF( int, int ); //提供類型 DRAWF 給未傳回任何值的函式，並且接受兩個 int 引數
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
**Static**  
(1) 修飾檔案中的global variable：  

使這個變數只有在本檔案中才可以被使用，相同專案中的其他檔案看不到它的存在。  

Note：放在function前也有一樣的作用。 

(2) 修飾function中的local variable：  

此變數一旦經過初始化就會一直存在直到程式結束，跳出function時它也會保持當下的值  

ex. 可用來計算同一個function被呼叫的次數。

Note:只會被初始化一次，並且只有進入function中才看得到這個變數 

(3) 修飾class中的member variable和function：  

variable：會使同一個class的所有實體共用同一個member variable，或者說這個member variable在同一個class的所有實體擁有相同的值。  

一樣只會初始化一次，甚至不需要實體就可呼叫。  

function：static member function不屬於任何一個實體，也是不需要實體就可呼叫，但它只能操作static member variables而已。  



**volatile**  

由於嵌入式系統常處理 I/O、中斷、即時操作系統 (RTOS) 相關的問題，因此在嵌入式系統開發中 volatile 尤為重要。被 volatile 修飾的變數代表它可能會被不預期的更新，因此告知編譯器不對它涉及的地方做最佳化，並在每次操作它的時候都讀取該變數實體位址上最新的值，而不是讀取暫存器的值。  
  
volatile 常見的應用：  
1.修飾中斷處理程式中 (ISR) 中可能被修改的全域變數。
2.修飾多執行緒 (multi-threaded) 的全域變數。
3.設備的硬體暫存器 (如狀態暫存器)

note:  
一個參數既可以是const還可以是volatile，一個例子是只讀的狀態寄存器。它是volatile因為它可能被意想不到地改變，但它是const因為程序不應該試圖去修改它。
```
 const volatile unsigned int rt_clock;
```

rt_clock 通常是指系統時鐘，它經常被時鐘中斷進行更新。所以它是 volatile。因此在用的時候，要讓編譯器每次從記憶體裡面取值。而 rt_clock 通常只有一個寫者（時鐘中斷），其他地方對其的使用通常都是唯讀的。所以將其聲明為 const，表示這裏不應該修改這個變數。所以 volatile 和 const 是兩個不矛盾的東西，並且一個物件同時具備這兩種屬性也是有實際意義的。



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
**Override覆載 : 繼承關係**

1. Override發生在繼承關係間。	
```
class Shape
{  
    public void getShapeType()  
    {  
        return "Shape" ;
    }  
}  
  
class Triangle : Shape
{  
    public void getShapeType()  
    {  
        return "Triangle" ;  
    }  
}  
	
```
建立一個Class 命名為Shape，並且他有一個public function為getShapeType，此時再建立一個class命名為Triangle，並繼承Shape，這時候改寫從Shape繼承下來的function，如此一來，原本class Shape呼叫getShapeType()的時候會回傳字串"Shape"，而class Triangle繼承Shape並Override getShapeType()，因此變成回傳字串"Triangle"	
	
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
