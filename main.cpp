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
#include <functional>

typedef std::pair<std::string,std::vector<int>> pair;


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
std::vector<pair> vec;
std::copy(vieta.begin(),
			vieta.end(),
			std::back_inserter<std::vector<pair>>(vec));


			std::sort(vec.begin(), vec.end(),
			[](const pair& l, const pair& r) {
				if (l.second.size() != r.second.size())
					return l.second.size() < r.second.size();

				return l.first < r.first;
			});


			for (auto &pair: vec) {
                    if(pair.second.size()>1)
                    {
                    std::cout << "zodis " << pair.first << " pasikartoja " << pair.second.size() <<" kartus ir yra " ;
        pair.second.erase(std::unique(pair.second.begin(), pair.second.end()), pair.second.end());
                    for( int n : pair.second )
                    {

                        std::cout << n+1 <<" " ;
                    }
        std::cout << "eilutese"<<std::endl ;
                    }

	}

    URL(str);

    in.close();


    return 0;
}

