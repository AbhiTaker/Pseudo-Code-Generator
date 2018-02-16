#include<bits/stdc++.h>

using namespace std;
set<string>  data_type, condition, loop;
set<char> useless, bracket;
map<string, string> map_variable, keyword,condmap;

void intialize()
{
    /* store the appropriate keyword in appropriate set*/
    data_type = {"int", "float", "string", "char", "double"};
    useless = {'<', '>' , ';' , ',', ' ', '"' };
    condition = {"if"};
    loop = {"for", "while", "do"};
    keyword = { {"int", "Integer"}, {"char", "Character"}, {"string", "String"}, {"float", "Float"}  };
    condmap = {{">"," greater "}, {"<", " less than "}, {"!=", " not equal "}, {"==", " equals "}, {">=", " greater than or equal to "}, {"<=", "less than or equal to"}};
    bracket = {'(', ')', '{', '}'};
}

void func_cin(string line) {

	int i = 0;
	while(i<line.size() && useless.find(line[i])!=useless.end()) //Covering up the spaces
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
        cout<< map_variable[temp]<<" " <<temp<<" ";
 		//cout<<mymap[temp]<<" "<<temp<<" ";

 	}
 	cout<<"\n";



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
        cout<< map_variable[temp]<<" "<<temp<<" "; //to be changed
 		//cout<<mymap[temp]<<" "<<temp<<" ";

 	}
 	cout << endl;
}

void func_return(string line) {
	int i = 0;
	while(i<line.size() && line[i]==' ') //Covering up the spaces
            i++;
    cout << "Returns " ;
    i = i + 6; //covering up return
    string temp;
    while(i < line.size() && useless.find(line[i])!=useless.end())
 			i++;
 	temp = line[i];
 	cout << temp << "\n";
}

void func_dt(string line)
{
    int i = 0;
	while(i<line.size() && useless.find(line[i])!=useless.end()) //Covering up the spaces
            i++;

    string Data_type="";
    while(i<line.size() && !(useless.find(line[i])!=useless.end()))
    {
        Data_type += line[i];
        i++;
    }
    int ctr = 0;
    vector<string> var_name;

    while(i < line.size())
    {
        string temp = "";
       while(i<line.size() && useless.find(line[i])!=useless.end())
            i++;

        if(i>=line.size())
            break;
        int detect_function = 0;
        while(i<line.size() && !(useless.find(line[i])!=useless.end()))
        {
            if(line[i]=='(')
            {
                detect_function = 1;
                break;
            }
            temp += line[i];
            i++;
        }
        if(detect_function)
        {
            cout<<"Declare Function "<<temp<<"\n";
            break;
        }

        map_variable[temp] = keyword[Data_type];
        var_name.push_back(temp);
    }

    if(!var_name.empty())
    {
        cout<<"Declare "<<var_name.size()<<" variable ";
        for(auto value: var_name)
            cout<<value<<" ";
        cout<<"\n";
    }

    //cout<<"This is data type : "<<Data_type<<"\n";

}

void func_cond(string line) {

	int i = 0;
	while(i<line.size() && line[i]==' ') //Covering up the spaces
            i++;
    while(i < line.size() && bracket.find(line[i]) != bracket.end())
    	i++;



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
		func_dt(line);
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
