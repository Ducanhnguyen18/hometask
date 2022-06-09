#include <iostream>
 #include <string>
 #include <sstream>
 #include <fstream>
 #include <vector>
 using namespace std;

 struct word {
 	int count;
 	string data;
 };

 void add(string s, vector<word>& words) {
 	bool appear = false;
 	for (int i = 0; i < words.size(); i++) {
 		if (words[i].data == s) {
 			appear = true;
 			words[i].count++;
 			break;
 		}
 	}
 	if (!appear) {
 		word tmp;
 		tmp.data = s;
 		tmp.count = 1;
 		words.push_back(tmp);
 	}
 }

 void split(string s, vector<word>& words) {
 	stringstream stringStream(s);
 	string line;
 	while (getline(stringStream, line))
 	{
 		size_t prev = 0, pos;
 		while ((pos = line.find_first_of(" ';',.", prev)) != string::npos)
 		{
 			if (pos > prev)
 				add(line.substr(prev, pos - prev),words);
 			prev = pos + 1;
 		}
 		if (prev < line.length()) add(line.substr(prev, string::npos), words);
 	}

 }

 void readFile(string& text) {
 	ifstream infile("input.txt");

 	while (!infile.eof()) {
 		string line;
 		getline(infile, line);
 		text += line;
 	}
 	infile.close();
 }

 void writeFile(vector<word>& words) {
 	ofstream outfile("output.txt");
 	for (int i = 0; i < words.size(); i++) {
 		if (words[i].count > 1)
 		outfile << words[i].data << " [" << words[i].count << "]" << endl;
 	}
 	outfile.close();
 }

 int main() {
 	string text = "";
 	vector<word> words;
 	readFile(text);
 	split(text, words);
 	writeFile(words);
 }