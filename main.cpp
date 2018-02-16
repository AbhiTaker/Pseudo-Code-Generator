#include<bits/stdc++.h>

using namespace std;
set<string> data_type, condition, loop;

void intialize()
{
    /* store the appropriate keyword in appropriate set*/
    data_type = {"int", "float", "string", "char", "double"};
    condition = {"if"};
    loop = {"for", "while"};
}

int check(string word)
{

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

       cout<<word<<"\n";

    }

    inFile.close();

    return 0;
}
