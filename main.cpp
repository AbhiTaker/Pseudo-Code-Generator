#include<bits/stdc++.h>

using namespace std;

int check(string word)
{

}
int main()
{
    ifstream inFile("test.cpp");
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
