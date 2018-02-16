#include<bits/stdc++.h>

using namespace std;
set<string> data_type, condition, loop;

void intialize()
{
    /* store the appropriate keyword in appropriate set*/
    data_type = {"int", "float", "string", "char", "double"};
    condition = {"if"};
    loop = {"for", "while", "do"};
}

void check(string word, string line)
{

	if(word == "cin") {
		func_cin(line);
	}
	else if(word == "cout") {
		func_cout(line);
	}
	else if(word == "return") {
		fumc_return(line);
	}
	else if(data_type.find(word) != data_type.end()) {
		func_dt(line);
	}
	else if(condition.find(word) != condition.end()) {
		fumc_cond(line);
	}
	else if(loop.find(word) != loop.end()) {
		func_loop(line);
	}
	else {
		cerr("Expand your code ;) ");   
	}


}

void func_cin(string line) {

	int i = 0;
	while(i<line.size() && line[i]==' ') //Covering up the spaces
            i++;
    i = i + 3; // covering up 'cin' i.e 3 words;
    int flag = 0;
    cout << "Enter ";
    string temp = "";
 	while(i < line.size()) {
 		while(line[i] == ' ')
 			i++;
 		temp += line[i];
 		if(temp == ">>") {
 			temp = "";
 			if(flag == 1) 
 				cout << "and ";
 			if(flag == 0)
 				flag = 1;
 		}
 		else if(temp == map.find(line[i])) { //map to be made
 			cout << map[line[i]] << line[i]; //This is to be edited.
 			temp = "";
 		}

 	}


   
}

void func_cout(string line) {
	int i = 0;
	while(i<line.size() && line[i]==' ') //Covering up the spaces
            i++;
    i = i + 4; // covering up 'cout' i.e 4 words;
    int flag = 0;
    cout << "Print ";
    string temp = "";
    while(i < line.size()) {
 		while(line[i] == ' ')
 			i++;
 		temp += line[i];
 		if(temp == "<<") {
 			temp = "";
 			if(flag == 1) 
 				cout << "and ";
 			if(flag == 0)
 				flag = 1;
 		}
 		else if(temp == map.find(line[i])) { //map to be made
 			cout << map[line[i]] << line[i]; //This is to be edited.
 			temp = "";
 		}
	
}
void func_return(string line) {
	
}
void func_dt(string line) {
	
}
void func_cond(string line) {
	
}

void func_loop(string s) {
	
}

int main()
{
    ifstream inFile("test.cpp");
    intialize();
    string line;
    int i = 0;

    while (inFile)
    {
       getline(inFile, line);
       i = 0;
       string word = "";
        while(i<line.size() && line[i]==' ')
            i++;

       while(i<line.size() && line[i]!=' ')
        {
            word += line[i];
            i++;
        }
        check(word, line);

       cout<<word<<"\n";

    }

    inFile.close();

    return 0;
}
