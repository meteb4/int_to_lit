#include <iostream>
#include <string>

std::string getUnit(char userChar)
{
    std::string REF[] = {
        "sifir",
        "bir",
        "iki",
        "uc",
        "dort",
        "bes",
        "alti",
        "yedi",
        "sekiz",
        "dokuz"};
    return REF[std::stoi(&userChar)];
}

std::string getTens(char userChar)
{
    std::string REF[] = {
        "",
        "on",
        "yirmi",
        "otuz",
        "kirk",
        "elli",
        "altmis",
        "yetmis",
        "seksen",
        "doksan"};
    return REF[std::stoi(&userChar)];
}

std::string getHundred(char userChar)
{
    std::string hd = "yuz";
    if (userChar == '0')
        return "";
    else if (userChar == '1')
        return hd;
    return getUnit(userChar) + ' ' + hd;
}

std::string FORMAT(int offSet, std::string userInput, std::string progress)
{
    for (int i = offSet; i < userInput.length(); i += 3)
    {
        progress = progress + ' ' + getHundred(userInput[i]) + ' ' + getTens(userInput[i + 1]) + ' ' + getUnit(userInput[i + 2]);
    };
    return progress;
}

int main()
{
    std::string tmp;
    std::cin >> tmp;
    std::string res = "";

    // Permet de controller les 3 premiers chiffres de la chaine
    if (tmp.length() % 3 != 0)
    {
        switch (tmp.length() % 3)
        {
        case 1:
            res = res + ' ' + getUnit(tmp[0]) + "bin";
            res = FORMAT(1, tmp, res);
            break;
        case 2:

            res = res + ' ' + getTens(tmp[0]) + ' ' + getUnit(tmp[1]) + "bin";
            res = FORMAT(2, tmp, res);
            // do the rest, modulo 3
            break;

        default:
            break;
        }
    }

    else
    {
        for (int i = 0; i < tmp.length(); i += 3)
        {
            res = res + ' ' + getHundred(tmp[i]) + ' ' + getTens(tmp[i + 1]) + ' ' + getUnit(tmp[i + 2]);
        };
    }

    std::cout << res;
    return 0;
}

// 12 345

// std::string REF[] = {
//         "",
//         "on",
//         "yirmi",
//         "otuz",
//         "kirk",
//         "elli",
//         "altmis",
//         "yetmis",
//         "seksen",
//         "doksan"};