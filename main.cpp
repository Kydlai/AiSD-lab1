#include <iostream>
#include <vector>
#include <set>
#include <string>

#include "main.h"

using namespace std;

set <char> data_set;

void input_manager(){
    cout << "\nВыберите какой пункт задания вы хотите испытать?\n";
    cout << "1: Вводится текст из строчных латинских букв, за которым следует точка.\n   Напечатать первые вхождения букв в текст, сохраняя их взаимный исходный порядок.\n";
    cout << "2: Вводятся два конечных множества X и У, состоящие из целых чисел.\n   Определить выполняется ли равенство: (AUB)\\B=A.\n";
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
    cout << "Во вводе допущена ошибка\n";
    if(repeat_request())
        input_manager();
    return;
}

bool repeat_request(){
    cout << "Желаете попробовать еще раз [Y/N]?\n";
    char c;
    cin >> c;
    return c == 'Y' || c == 'y';
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

void printset(){
    set<char>::iterator it;
    for(it = data_set.begin(); it != data_set.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

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
    printset();
    return;
}

/*void second_method(){
    cout << "Пункт 2\n";
    cout << "(AUB)\\B=A\nВведите множество A\n";
    string s1, s2;
    getline(cin, s1);

}*/






int main() {
    input_manager();
    while(true){
        if(repeat_request())
            input_manager();
        else
            break;
    }
    

    return 0;
}