#include "easy.h"
#include <algorithm>
using namespace std;

// Global variables
string yellow = "\033[1;33m";
string green = "\033[1;32m";
string ASCII_COLOR_END = "\033[0m";
// ----------------

int main(int argc, char const* argv[]){
	system("clear");
	cout << "wOrDlIsT GeNeRaToR - OjAs\n";
	cout << "Press enter if unsure...\n";
	cout << "----------------------------\n";
	string first_name = input("Enter target's first name: ");
	string last_name = input("Enter target's last name: ");
	string dob = input("Enter target's Date-Of-Birth (dd-mm-yyyy): ");
	string nick_name = input("Enter target's nick name: ");
	string extra_info = input("Enter extra keywords about target, each separated by <space>: \n");
	string file_name = input("Enter file name to write data: ");

	cout << yellow << "[~] Generating Data About Target..." << ASCII_COLOR_END << endl;

	/* Tokenize Date, Month, Year into different containers */
	string void_dob = removeAllSubString(dob, "-");

	// ddmmyyyy
	// 01234567

	string date = void_dob.substr(0, 2);
	string month = void_dob.substr(2, 2);
	string year = void_dob.substr(4, 4);

	cout << green << "[+] Generated Data About Target!" << ASCII_COLOR_END << endl;

	cout << yellow << "[~] Generating name/symbol/number combinations..." << ASCII_COLOR_END << endl;

	// Captial words name style modification
	char frst_ltr = first_name[0];
	char cap_frst_ltr = toupper(frst_ltr);
	char last_frst_ltr = last_name[0];
	char cap_last_frst_ltr = toupper(last_frst_ltr);
	string First_name = cap_frst_ltr + first_name.substr(1);
	string Last_name = cap_last_frst_ltr + last_name.substr(1);

	writeFile(file_name, first_name+"\n");
	writeFile(file_name, first_name+"_"+last_name+"\n");
	writeFile(file_name, first_name+"123456"+"\n");
	writeFile(file_name, first_name+last_name+"\n");

	for (int k = 0; k < 10000; ++k){
		writeFile(file_name, first_name+to_string(k)+"\n");
		writeFile(file_name, First_name+to_string(k)+"\n");
		writeFile(file_name, first_name+"@"+to_string(k)+"\n");
		writeFile(file_name, First_name+"@"+to_string(k)+"\n");
		writeFile(file_name, first_name+"_"+to_string(k)+"\n");
		writeFile(file_name, First_name+"_"+to_string(k)+"\n");
		writeFile(file_name, first_name+"-"+to_string(k)+"\n");
		writeFile(file_name, First_name+"-"+to_string(k)+"\n");
		writeFile(file_name, First_name+"_"+last_name+to_string(k)+"\n");
		writeFile(file_name, First_name+"_"+Last_name+to_string(k)+"\n");
		writeFile(file_name, first_name+last_name+to_string(k)+"\n");
		writeFile(file_name, first_name+last_name+"@"+to_string(k)+"\n");
		writeFile(file_name, first_name+last_name+to_string(k)+"\n");
		writeFile(file_name, first_name+"_"+last_name+"@"+to_string(k)+"\n");
	}

	cout << green << "[+] Generated name/symbol/number combinations!" << ASCII_COLOR_END << endl;

	cout << yellow << "[~] Generating secondary passphrase combinations..." << ASCII_COLOR_END << endl;

	// Some arbitrary must combinations

	writeFile(file_name, first_name+void_dob+"\n");
	writeFile(file_name, first_name+"_"+void_dob+"\n");
	writeFile(file_name, first_name+"@"+void_dob+"\n");
	writeFile(file_name, void_dob+"\n");

	string void_dob_clone =  void_dob; // Reverse of void_dob
	reverse(void_dob_clone.begin(), void_dob_clone.end());

	writeFile(file_name, void_dob_clone+"\n");
	writeFile(file_name, first_name+"@"+void_dob_clone+"\n");

	cout << green << "[+] Generated secondary passphrase combinations!" << ASCII_COLOR_END << endl;

	cout << yellow << "[~] Generating nickname combinations..." << ASCII_COLOR_END << endl;

	char nick_frst_ltr = nick_name[0];
	char cap_nick_frst_ltr = toupper(nick_frst_ltr);
	string Nick_name = cap_nick_frst_ltr + nick_name.substr(1);
	for (int f = 0; f < 10000; ++f){
		writeFile(file_name, nick_name+to_string(f)+"\n");
		writeFile(file_name, Nick_name+to_string(f)+"\n");
		writeFile(file_name, nick_name+"@"+to_string(f)+"\n");
		writeFile(file_name, Nick_name+"@"+to_string(f)+"\n");
		writeFile(file_name, nick_name+"_"+to_string(f)+"\n");
		writeFile(file_name, Nick_name+"_"+to_string(f)+"\n");
		writeFile(file_name, nick_name+"-"+to_string(f)+"\n");
		writeFile(file_name, Nick_name+"-"+to_string(f)+"\n");
	}

	cout << green << "[+] Generated nickname combinations!" << ASCII_COLOR_END << endl;

	cout << yellow << "[~] Generating extra keyword formations..." << ASCII_COLOR_END << endl;

	vector<string> ex_vec = splitString(extra_info, ' ');
	for (int x = 0; x < ex_vec.size(); ++x){
		writeFile(file_name, first_name+ex_vec[x]+"\n");
		writeFile(file_name, ex_vec[x]+first_name+"\n");
		writeFile(file_name, first_name+"_"+ex_vec[x]+"\n");
	}

	cout << green << "[+] Generated extra keyword formations!" << ASCII_COLOR_END << endl;

	cout << green << "[✓] Generate completed successfully!" << ASCII_COLOR_END << endl;

	cout << yellow << "[!] Data written to file: " << file_name << "!" << " Size: " << to_string(getFileSizeInBytes(file_name)) << " bytes" << ASCII_COLOR_END << endl;
	return 0;
}
