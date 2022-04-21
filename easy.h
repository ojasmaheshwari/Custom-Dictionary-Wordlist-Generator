#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;

// Easy C++ - Saves time while making complex programs

int random(int ll, int ul){
	srand(time(0));
	int a = rand()%((ul - ll) - 1) + ll;
	return a;
}
string input(string prompt){
	string a;
	std::cout << prompt;
	getline(std::cin, a);
	return a;
}

string removeSubString(string mainstr, string toRemove){
	size_t pos = mainstr.find(toRemove);
	if (pos != std::string::npos){
		mainstr.erase(pos, toRemove.length());
		return mainstr;
	} else {
		return "false";
	}
}
string removeAllSubString(string mainstr, string toRemove){
	size_t pos = std::string::npos;
	while ((pos = mainstr.find(toRemove)) != std::string::npos){
		mainstr.erase(pos, toRemove.length());
	}
	if (mainstr.find(toRemove) != std::string::npos){
		return "false";
	} else {
		return mainstr;
	}
}
bool writeFile(string filename, string data){
	ofstream file (filename, ios::app);
	if (file.is_open()){
		file << data;
		file.close();
		return true;
	} else {
		return false;
	}
}
string readfile(string filename){
	string data;
	string line;
	ifstream file (filename, ios::in);
	if (file.is_open()){
		while (getline(file, line)){
			data.append(line+"\n");
		}
		data.pop_back();
		return data;
	} else {
		string error = "false";
		return error;
	}
}
vector<string> splitString(string mainstr, char delimeter){
	vector<string> v;
	string temp = "";
	for (int j = 0; j < mainstr.length(); ++j){
		if (mainstr[j] == delimeter){
			v.push_back(temp);
			temp = "";
		} else {
			temp = temp + mainstr[j];
		}
	}
	v.push_back(temp);

	return v;
}
void printVector(vector<string> vec){
	cout << "{";
	for (int l = 0; l < vec.size(); ++l){
		cout << vec[l] << ", ";
	}
	cout << "\b\b}";
}

int getFileSizeInBytes(string filename){
	ifstream in_file(filename, ios::binary);
	in_file.seekg(0, ios::end);
	int file_size = in_file.tellg();
	return file_size;
}

template <typename T> T searchVector(T toBeSearched, vector<T> vec){
	for (int i = 0; i < vec.size(); ++i){
		if (vec[i] == toBeSearched){
			return i;
		}
	}
	return false;
}