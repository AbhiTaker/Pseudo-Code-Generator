#include<bits/stdc++.h>

using namespace std;
set<string>  data_type, condition, loop;
set<char> useless, bracket;
map<string, string> condmap;

void intialize()
{
    /* store the appropriate keyword in appropriate set*/
    data_type = {"int", "float", "string", "char", "double"};
    useless = {'<', '>' , ';' , ',', ' '};
    bracket = {'(', ')', '{', '}'}
    condition = {"if"};
    loop = {"for", "while", "do"};
    condmap = {{">"," greater "}, {"<", " less than "}, {"!=", " not equal "}, {"==", " equals "}, {">=", " greater than or equal to "}, {"<=", "less than or equal to"}};
}

void func_cin(string line) {

	int i = 0;
	while(i<line.size() && line[i]==' ') //Covering up the spaces
            i++;
    i = i + 3; // covering up 'cin' i.e 3 words;
    cout << "Input ";
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
 	cout << endl;



}

void func_cout(string line) {
	int i = 0;
	while(i<line.size() && line[i]==' ') //Covering up the spaces
            i++;
    i = i + 4; // covering up 'cin' i.e 3 words;
    cout << "Prints ";
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
        cout<< "temp " <<temp<<" "; //to be changed
 		//cout<<mymap[temp]<<" "<<temp<<" ";

 	}
 	cout << endl;
}
void func_return(string line) {
	int i = 0;
	while(i<line.size() && line[i]==' ') //Covering up the spaces
            i++;
    cout << "Returns "	
    i = i + 6; //covering up return
    while(i < line.size() && useless.find(line[i])!=useless.end())
 			i++;
 	temp = line[i];
 	cout << temp << "\n";
 	break;
}

void func_dt(string line) {

}
void func_cond(string line) {

	int i = 0;
	while(i<line.size() && line[i]==' ') //Covering up the spaces
            i++;
    while(i < line.size() && bracket.find(line[i]) != bracket.end())
    	i++;
    if(i>=line.size())
            break;
    
    

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
		func_cout(line);
	}
	else if(word == "return") {
		func_return(line);
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
