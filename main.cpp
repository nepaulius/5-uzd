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
#include <set>
#include <cstdlib>

 void URL(std::string tekastas)
 {

    transform(tekastas.begin(),tekastas.end(),tekastas.begin(),::tolower);

    tekastas.erase(std::remove_if(tekastas.begin(),
                             tekastas.end(),
                             [](char c)
                             { return c==','||c=='('|| c==')';}),
              tekastas.end());


    std::string word;
    std::set<std::string> Linkai;
    std::istringstream iss(tekastas);

    std::cout<<std::endl;
    std::cout<<"Link'ai tekste : "<<std::endl;
            while (iss>>word){
            if(std::regex_match(word, std::regex("[(http(s)?):\\/\\/(www\\.)?a-zA-Z0-9@:%._\\+~#=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%_\\+.~#?&//=]*)")) )
           {
                Linkai.insert(word);
           }
        }
 for(std::set<std::string>::iterator it = Linkai.begin(); it != Linkai.end(); ++it) {
        std::cout << *(it) << std::endl;
    }


 }

int main()
{
 system ("chcp 1257");

std::ifstream in("my_data.txt");


   if(!in.good()) {
    std::cout << "Nepavyko atidaryti failo" << std::endl;
    }


std::map <std::string,std::vector<int> > vieta;
std::string sLine;
std::string tmp;
std::string str;
std::string laikin;

int count=0;
while (std::getline(in,sLine))
{
    str += sLine + "\n";
for (int i = 0; i < sLine.size(); i++)
    {

    transform(sLine.begin(),sLine.end(),sLine.begin(),::tolower);
       if(iswpunct(sLine[i]) || isdigit(sLine[i]))
        {
            sLine.erase(i, 1);
            i--;
        }
    }
    std::istringstream b(sLine);
    while ( b >>tmp)
    {
        vieta[tmp].push_back(count);
    }
    count++;
}

 for( const auto& pair : vieta )
    {
        if(pair.second.size()>1)
        {
        std::cout <<"Zodis : "<< pair.first << " pasikartoja : "<<pair.second.size()<<" kartus ir yra " ;
        for( int n : pair.second ) std::cout << n+1 <<" " ;
        std::cout << "eilutese"<<std::endl ;
        }
    }

    URL(str);

    in.close();


    return 0;
}

