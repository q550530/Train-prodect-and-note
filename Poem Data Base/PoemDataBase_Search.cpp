#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;
struct Poem{
	string poet;
	string title;
	string content;
};

istream& operator>>(istream &in, Poem &p){
	string curString;
	in >> p.poet >> p.title >> p.content;
	//    王維       鹿柴      空山不見人
	while(in >> curString){  
		p.content += " " + curString;
	}
	return in;
}
ostream& operator<<(ostream &out, const Poem &p){
	out << p.poet << setw(p.content.size()-p.poet.size()) << p.title << '\n' 
		<< p.content;
	return out;
}
ofstream& operator<<(ofstream &out, const Poem &p){
	out << p.poet << setw(p.content.size()-p.poet.size()) << p.title << '\n' 
		<< p.content;
	return out;
}
class Tang_Poem{
private:
	vector<Poem> five;
	vector<Poem> seven;
public:
	Tang_Poem(const char* poem5, const char* poem7){
		ifstream fin5(poem5), fin7(poem7);
		string line;
		Poem poem;
		istringstream poem_entry;
	
		
		while(getline(fin5, line)){
			poem_entry.str(line);  
			poem_entry >> poem;
			five.push_back(poem);
			poem_entry.clear();
		}
		
		while(getline(fin7, line)){
			poem_entry.str(line);
			poem_entry >> poem;
			seven.push_back(poem);
			poem_entry.clear();
		}
	}
	vector<Poem> search_poet(const string poet) const {
		vector<Poem> poems;
		for(int i = 0; i<five.size(); ++i){
			if(five[i].poet == poet){
				poems.push_back(five[i]);
			}
		}
		for(int i = 0; i<seven.size(); ++i){
			if(seven[i].poet == poet){
				poems.push_back(seven[i]);
			}
		}
		return poems;
	}
	vector<Poem> search_Keyword(const string k) const {
		vector<Poem> poems;
		for(int i = 0; i<five.size(); ++i){
			if(five[i].content.find(k) != string::npos){
				poems.push_back(five[i]);
			}
		}
		for(int i = 0; i<seven.size(); ++i){
			if(seven[i].content.find(k) != string::npos){
				poems.push_back(seven[i]);
			}
		}
		return poems;
	}
};
int main(array<System::String ^> ^args)
{
    // 唐詩資料庫物件
    Tang_Poem  poem_db( "five_poem.db" , "seven_poem.db" ) ;
    
    string          poet  ;   // 詩人
    vector<Poem>  poems ;   // 詩
    int i ;
    while ( 1 ) {
        cout << "> 輸入keyword : " ;
        cin >> poet ;
        // 找尋詩人在唐詩資料庫內中的所有詩
        poems = poem_db.search_Keyword( poet ) ;
		ofstream fout("TestResult.txt");
		for ( i = 0 ; i < poems.size() ; ++i ) {
            cout << "\n" << poems[i] << "\n" ;
			fout << "\n" << poems[i] << "\n" ;
		}
        cout << endl ;
        
    }
	system("pause");
    return 0 ;
}