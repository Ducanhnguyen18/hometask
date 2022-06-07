#include<iostream>
#include<fstream>
#include<map>
#include<string>

int main()
{
try
{
std::string file_name = "input.txt";
std::fstream fs;
fs.open(file_name, std::fstream::in);
std::string word;
std::map<std::string, int> words;
while (!fs.eof())
{
fs >> word;
words[word]++;
}
try {
std::string file_name_2 = "output.txt";
std::fstream fout;
fout.open(file_name_2, std::fstream::out);
std::map<std::string, int>::iterator it;
for (it = words.begin(); it != words.end(); it++)
{
    if(it->second > 1)
    {
        fout << it->first << " " << "[" << it->second << "]" << std::endl;
    }
}
fs.close();
fout.close();
}
catch (const std::exception& ex)
{
    std::cout <<"Error open out file" << ex.what() << std::endl;
    }
    }
    catch (const std::exception &ex)
    {
    std::cout << "Error open file" << ex.what();
    return -1;
    }

    return 0;
    }
