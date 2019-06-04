# 5-uzd
___
**1 dalis**
Panaudodamas std::map nustačiau, kiek kartų žodžiai pasikarotja tekste :
```cpp
std::map <std::string,std::vector<int> > vieta;
...

std::istringstream b(sLine);
    while ( b >>tmp)
    {
        vieta[tmp].push_back(count);
    }
    count++;
}
```

![](https://user-images.githubusercontent.com/45967745/58862804-2c7ded00-86ba-11e9-9676-f1fbf8639412.png)

Lentelė:

| Žodis/Teksto eilutė | 1 | 2 | 3 | 4 | 
|---------------------|---|---|---|---|
| ir                  |   | + | + |   |
| iš                  | + | + |   |   |
| komandos            |   | + | + |   |


___
**2 dalis**
Programa ieško URL link'ų tekste :
```cpp
void URL(std::string tekastas)
 {

    transform(tekastas.begin(),tekastas.end(),tekastas.begin(),::tolower);
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
```
![](https://user-images.githubusercontent.com/45967745/58862911-67802080-86ba-11e9-8054-b75089bc0792.png)
