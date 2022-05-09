#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;
//設定班別最大數
const int MAX_CLASS = 3;
//設定每班最大人數
const int MAX_STUDENT = 10;
struct Student{
	string name;
	int id;
};
istream& operator>>(istream& in, Student &s){
	in >> s.name >> s.id;
	return in;
}
ostream& operator<<(ostream& out, const Student &s){
	out << setw(8) << s.name << " [" << s.id << "] ";
	return out;
}
class Class{
private:
	Student stu[MAX_STUDENT];
	int stu_no;
public:
	Class():stu_no(0){}
	bool insert_stu(const Student &s){
		if(stu_no == MAX_STUDENT){
			cout << "此班級已額滿\n";
			return false;
		}else{
			stu[stu_no++] = s;
			return true;
		}
	}
	int getCurStu_no() const {
		return stu_no;
	}
	friend ostream& operator<<(ostream &out, const Class &foo){
		for(int i = 0; i<foo.stu_no; ++i){
			out << i+1 << " : " << foo.stu[i] << endl;
		}
		return out;
	}
};
class Course{
private:
	Class classes[MAX_CLASS];
public:
	Course(){}
	bool add_stu(int c, Student &s){
		if(c<1 || c>MAX_CLASS){
			cout << "查無此班級\n";
			return false;
		}else{
			return classes[c-1].insert_stu(s)?true:false;
		}
	}
	friend ostream& operator<<(ostream &out, const Course &foo){
		 int total_stu = 0;
		 for(int i = 0; i<MAX_CLASS; ++i){
			 total_stu += foo.classes[i].getCurStu_no();
			 out << "第" << i+1 << "班 : \n" << foo.classes[i] << endl;
		 }
		 out << "修課總人數 : " << total_stu << endl;
		 return out;
	}
};
int main(array<System::String ^> ^args)
{
    Course   foo ;  // 課程物件
    int      c ;    // 班別
    Student  s ;    // 學生
    // 輸入班別與學生資料到課程物件內, 鍵入 0 結束輸入
    cout << "> 輸入班別, 姓名, 學號 : \n" ;
    while ( 1 ) {
        cin >> c ;
        if ( c == 0 ) break ;
        cin >> s ;
        foo.add_stu(c,s) ;
    }
    // 列印全部修課班別學生
    cout << "\n" << foo << endl ;
	system("pause");
    return 0 ;
}