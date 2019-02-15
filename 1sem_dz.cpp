#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include<cctype>
using namespace std;

struct Statistics{
	int count;
	string word;
};

const char signs[4] = {'.' , ',', '!', '?'};


void PrintNFirstWords(const vector<Statistics>& s, int& n){
	for (auto& item : s){
		if (n != 0){
			cout << item.count << ": " << item.word << endl;
			n--;
		}
	}
}




string Prepare(const string& s){
	string str = s;
	transform(s.begin(), s.end(), str.begin(), ::tolower);
	for (auto& item : signs){
		if (str[str.size() - 1] == item) {
			str.pop_back();
		}
	}
	return str;
}


int main(){
	vector<Statistics> stat;
	Statistics st;
	int n;
	cin >> n;
	map<string,int> dict;
	ifstream text("text.txt");
	if (text.is_open()){
		string word;
		while(!text.eof()){
			text >> word;
			if (text.eof()){
				break;
			}
			word = Prepare(word);
			dict[word]++;
		}
		text.close();
	}
	for (auto& item : dict){
		st.word = item.first;
		st.count = item.second;
		stat.push_back(st);
	}
	sort(stat.begin(), stat.end(), [](const Statistics& lhs, const Statistics& rhs){
		return lhs.count>rhs.count;
		});
	PrintNFirstWords(stat,n);
	return 0;
}



