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
___
**2 dalis**

Suskaičiavau, kuriose eilutese yra pasikartojantis žodis :

![](https://user-images.githubusercontent.com/45967745/58529704-955df480-81e4-11e9-8935-2135b29c3d66.png)

Lentelė:

| Žodis/Teksto eilutė | 1 | 2 | 3 | 4 | 
|---------------------|---|---|---|---|
| ir                  |   | + | + |   |
| iš                  | + | + |   |   |
| komandos            |   | + | + |   |


___
**3 dalis**
Programa ieško URL link'ų tekste :

![](https://user-images.githubusercontent.com/45967745/58530017-becb5000-81e5-11e9-8a88-a1e7adcee25c.png)

![](https://user-images.githubusercontent.com/45967745/58530034-d0acf300-81e5-11e9-8048-07c774c1bf76.png)

![](https://user-images.githubusercontent.com/45967745/58530058-ede1c180-81e5-11e9-89b1-3d92b5920db6.png)
