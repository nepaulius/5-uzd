#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <regex>
#include <bits/stdc++.h>
#include <locale>

 void URL_www(std::string tekastas)
 {
  std::string w="www.";
  std::vector<size_t> positions;

size_t pos = tekastas.find(w, 0);
while(pos != std::string::npos)
{
    positions.push_back(pos);
    pos = tekastas.find(w,pos+1);
}

std::string sum;
for(int i=0;i<positions.size();i++)
{
        if(tekastas[positions[i]-1]==' ')
        {
            for(int j=positions[i];j<tekastas.size();j++)
        {
            if(!isspace(tekastas[j]))
            sum+=tekastas[j];
            else break;

        }
sum+=" ";
}
}
for(int i=0;i<sum.size();i++)
    if (sum[i]==',')
      sum.erase(i);

std::cout<<sum<<std::endl;
 }
void  URL_http(std::string tekastas)
{


  std::string w="http";
  std::vector<size_t> positions;

size_t pos = tekastas.find(w, 0);
while(pos != std::string::npos)
{
    positions.push_back(pos);
    pos = tekastas.find(w,pos+1);
}

std::string sum;
for(int i=0;i<positions.size();i++)
{

        for(int j=positions[i];j<tekastas.size();j++)
        {
            if(!isspace(tekastas[j]))
            sum+=tekastas[j];
            else break;

        }
sum+=" ";
}
for(int i=0;i<sum.size();i++)
    if (sum[i]==',')
      sum.erase(i);
std::cout<<sum<<std::endl;
 }
void Vieta(std::vector<std::string> geri)
{
    int counter=0;
    std::string word2;
    std::string sLine;
    std::string plius;
    std::ifstream in("my_data.txt");

    std::vector<std::string> line;


while(std::getline(in,sLine))
{
     for (int i = 0; i < sLine.size(); i++)
    {

    transform(sLine.begin(),sLine.end(),sLine.begin(),::tolower);
       if(iswpunct(sLine[i]) || isdigit(sLine[i]))
        {
            sLine.erase(i, 1);
            i--;
        }
    }
     line.push_back(sLine);
}
std::string pvz;

for(int i=0;i<line.size();i++)
{
    std::istringstream b(line[i]);
    while ( b >>pvz)
    {
        for(int j=0;j<geri.size();j++)
        {
            if(geri[j]==pvz)
            {
                std::cout<<geri[j]<<" yra eiluteje : "<<i+1<<std::endl;
            }
        }
    }

}

}
int main()
{

setlocale(LC_ALL, "Lithuanian");

 std::string str;
  std::string tmp;
  std::ifstream in("my_data.txt");

while ( std::getline(in, tmp) )
{
    str += tmp + "\n";
}

    transform(str.begin(),str.end(),str.begin(),::tolower);
    str.insert(0,1,' ');
std::cout<<"Link'ai tekste : "<<std::endl;
    URL_www(str);
    URL_http(str);
std::cout<<std::endl;
    std::string word;

    for (int i = 0; i < str.size(); i++)
    {
       if(iswpunct(str[i]) || isdigit(str[i]))
        {
            str.erase(i, 1);
            i--;
        }
    }


    std::istringstream iss(str);
    std::map<std::string, std::size_t> occurrences;

    while (iss >> word)
    {
        ++occurrences[word];
    }

std::vector <std::string> geri;
    for (std::map<std::string, std::size_t>::iterator it = occurrences.begin();
         it != occurrences.end(); ++it)
    {
        if(it->second>1)
        {
            std::cout << "Zodis: " << it->first << "\t pasikartoja : " << it->second<<" kartus"<< std::endl;
            geri.push_back(it->first);
        }


    }
std::cout<<std::endl;

Vieta(geri);


  in.close();

    return 0;
}

