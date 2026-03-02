#include <iostream>
#include <vector>
#include <set>
#include <string>

#include "main.h"

using namespace std;

set <char> data_set;

void input_manager(){
    cout << "Выберите какой пункт задания вы хотите испытать?\n";
    cout << "1: Вводится текст из строчных латинских букв, за которым следует точка.\nНапечатать первые вхождения букв в текст, сохраняя их взаимный исходный порядок.\n";
    cout << "2: Вводятся два конечных множества X и У, состоящие из целых чисел.\nОпределить выполняется ли равенство: (AUB)\\B=A.\n";
    int n;
    cin >> n;
    switch (n)
    {
        case 1:
            first_method();
            break;
        case 2:
            //second_method();
            break;
        default:
            error_message();
            break;
    }
    return;
}

void error_message(){
    cout << "Во вводе допущена ошибка\nЖелаете попробовать еще раз [Y/N]?\n";
    char c;
    cin >> c;
    if(c == 'Y' || c == 'y')
        input_manager();
    return;
}

/*vector<int> check_int_input(string& s){
    vector<int> result;
    string temp_num = "";
    for(auto c : s){
        if(c >= '0' && c <= '9')
            temp_num += c;
        else if(c == ' ' || c == '\t'|| c == '\n')
            continue;
        else{
            error_message();
            throw runtime_error("");
        }

    }
}*/

void first_method(){
    cout << "Пункт 1\n";
    cout << "Введите текст:\n";
    
    char c;
    while(cin >> c){
        if(!(c >= 'a' && c <= 'z' || c == ' ' || c == '\n' || c == '.')){
            //cout << endl << "#" <<  c << "#" << endl;
            error_message();
        } else if(c != '.' && c != ' ' && c != '\n')
            data_set.insert(c);
        else
            break;
    }
    return;
}

/*void second_method(){
    cout << "Пункт 2\n";
    cout << "(AUB)\\B=A\nВведите множество A\n";
    string s1, s2;
    getline(cin, s1);

}*/






int main() {
    char c;

    input_manager();
    

    return 0;
}