#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
using namespace std;


vector<string> split(string s) {
	string temp;
	stringstream ss;
	ss.str(s);
	vector<string> v;
	while (ss >> temp) {
		v.push_back(temp);
	}

	return v;
}

bool cmp(pair<int, string>& a, pair<int, string>& b) {
	if (a.first == b.first)
		return a.second < b.second;

	return a.first > b.first;
}

int main() {
	ifstream in("new york times.txt");
	string s;
	int size;
	vector<string> v;
	if (in.is_open()) {
		in.seekg(0, ios::end);
		size = in.tellg();
		s.resize(size);
		in.seekg(0, ios::beg);
		in.read(&s[0], size);

		for (int i = 0; i < s.length(); i++)
			if (s[i] == ',' || s[i] == '.') { s[i] = ' '; }
	}

	v = split(s);
	sort(v.begin(), v.end());

	vector<pair<int, string>> r;
	int count = 1;
	for (vector<string>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		if (*iter == "a" || *iter == "an" || *iter == "the" || *iter == "at" || *iter == "by" || *iter == "in" || *iter == "of" || *iter == "to" ||* iter == "on" || *iter == "for" || *iter == "in" || *iter == "and" || *iter == "but" || *iter == "by" || *iter == "from" || *iter == "it" || *iter == "they" || *iter == "that" || *iter == "which" || *iter == "with" || *iter == "'" || *iter == "\"" || *iter == "[" || *iter == "(" || *iter == ")")
			continue;
		if ((iter + 1) == v.end())
		{
			break;
		}
		if (*iter == *(iter + 1))
		{
			count++;
		}
		else 
		{ 
			r.push_back(make_pair(count, *iter)); count = 1; 
		}
	}

	sort(r.begin(), r.end(), cmp);

	for (int i = 0; i < 10; i++)
		cout << "단어:" << r[i].second << " 등장수:" << r[i].first << endl;
}