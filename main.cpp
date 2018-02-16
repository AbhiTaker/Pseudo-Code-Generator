#include<bits/stdc++.h>

using namespace std;
set<string>  data_type, condition, loop;
set<char> useless;

void intialize()
{
    /* store the appropriate keyword in appropriate set*/
    data_type = {"int", "float", "string", "char", "double"};
    useless = {'<', '>' , ';' , ',', ' '};
    condition = {"if"};
    loop = {"for", "while", "do"};
}

void func_cin(string line) {

	int i = 0;
	while(i<line.size() && line[i]==' ') //Covering up the spaces
            i++;
    i = i + 3; // covering up 'cin' i.e 3 words;
    int flag = 0;
    cout << "Enter ";
 	while(i < line.size())
    {
        string temp = "";
 		while(i < line.size() && useless.find(line[i])!=useless.end())
 			i++;

        if(i>=line.size())
            break;
 		while(i < line.size() && !(useless.find(line[i])!=useless.end()))
        {
            temp += line[i];
            i++;
        }
        cout<< "temp " <<temp<<" ";
 		//cout<<mymap[temp]<<" "<<temp<<" ";

 	}
 	cout<<"end\n";



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

void check(string word, string line)
{
    cout<<word<<"\n";
	if(word == "cin") {
		func_cin(line);
	}
	else if(word == "cout") {
		//func_cout(line);
	}
	else if(word == "return") {
		//func_return(line);
	}
	else if(data_type.find(word) != data_type.end()) {
		//func_dt(line);
	}
	else if(condition.find(word) != condition.end()) {
		//func_cond(line);
	}
	else if(loop.find(word) != loop.end()) {
		//func_loop(line);
	}
	else {
		//cout<<"Expand your code \n";
	}


}

int main()
{
    ifstream inFile("prog.cpp");
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

       //cout<<word<<"\n";

    }

    inFile.close();

    return 0;
}
