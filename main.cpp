#include<iostream>
#include<sstream>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main() {

	map<string,vector<string>> dictres;
	string line;
	string word;

	set<string> res;
	while(getline(cin,line),line!="#"){
		stringstream s(line);
		while(s>>word){
			if(word.size()==1){
				res.insert(word);
				continue;
			}
			string aux=word;
			transform(word.begin(),word.end(),word.begin(),::toupper);
			sort(word.begin(),word.end());
			dictres[word].push_back(aux);
		}
	}
	for(auto t=dictres.begin();t!=dictres.end();t++){
		if(t->second.size()==1)
			res.insert(t->second[0]);
	}

	for(auto x:res)
		cout<<x<<endl;


	return EXIT_SUCCESS;
}

