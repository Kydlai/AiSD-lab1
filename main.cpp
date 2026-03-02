#include "main.h"

using namespace std;

void clear_input_buffer(){
    cin.clear();  
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void input_manager(){
    cout << "\nВыберите какой пункт задания вы хотите испытать?\n";
    cout << "1: Вводится текст из строчных латинских букв, за которым следует точка.\n   Напечатать первые вхождения букв в текст, сохраняя их взаимный исходный порядок.\n";
    cout << "2: Вводятся два конечных множества X и У, состоящие из целых чисел.\n   Определить выполняется ли равенство: (AUB)\\B=A.\n";
    int n;
    clear_input_buffer();
    cin >> n;
    switch (n)
    {
        case 1:
            first_method();
            break;
        case 2:
            second_method();
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
    clear_input_buffer();
    cin >> c;
    return c == 'Y' || c == 'y';
}

template<typename T>
void printset(set<T> data_set){
    typename set<T>::iterator it;
    for(it = data_set.begin(); it != data_set.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void first_method(){
    cout << "Пункт 1\n";
    cout << "Введите текст:\n";
    
    char c;
    set<char> data_set;
    vector<pair<char, int>> first_met;
    int str_pos = 0;
    clear_input_buffer();
    while(cin >> c){
        if(!(c >= 'a' && c <= 'z' || c == ' ' || c == '.')){
            //error_message();
            return;
        }
        else if(c != '.' && c != ' '){
            if(!data_set.count(c))
                first_met.push_back(make_pair(c, str_pos));
            data_set.insert(c);
        }
        else if(c != ' ')
            break;
        str_pos++;
    }
    for(auto i : first_met)
        cout << i.first << ": позиция " << i.second << endl; 
    
    return;
}

void second_method(){
    set<int> set_a, set_b;

    cout << "Пункт 2\n";
    cout << "(AUB)\\B=A\n";
    string s1, s2;
    try{
        cout << "Введите множество A\n";
        clear_input_buffer();
        getline(cin, s1);
        set_a = check_int_input(s1);

        cout << "Введите множество B\n";
        getline(cin, s2);
        set_b = check_int_input(s2);
    } catch (const exception& e) {
        error_message();
        return;
    }

    cout << "Множество A: ";
    printset(set_a);
    cout << "Множество B: ";
    printset(set_b);
    cout << "Множество AUB: ";
    set<int> comb_set = combining_sets(set_a, set_b);
    printset(comb_set);
    cout << "Множество (AUB)\\B: ";
    set<int> diff_set = difference_sets(set_a, set_b);
    printset(diff_set);
    cout << "Равенство (AUB)\\B=A " << (equals_sets(set_a, diff_set) ? "" : "не ") << "выполняется\n";

}

set<int> check_int_input(string& s){
    set<int> result;
    s += ' ';
    string temp_num = "";
    for(auto c : s){
        if(c >= '0' && c <= '9')
            temp_num += c;
        else if(c == ' ' || c == '\t'|| c == '\n'){
            if(temp_num.size() > 0)
                result.insert(stoi(temp_num));
            temp_num = "";
        }
        else{
            throw runtime_error("");          
            break;
        }
    }
    return result;
}

template<typename T>
set<T> combining_sets(set<T>& set_a, set<T>& set_b){
    set<T> result;
    for(const auto& el : set_a)
        result.insert(el);
    for(const auto& el : set_b)
        result.insert(el);
    return result;
    
}

template<typename T>
set<T> difference_sets(set<T>& set_a, set<T>& set_b){
    set<T> result;
    typename set<T>::iterator it;
    for(it = set_a.begin(); it != set_a.end(); ++it)
        if(!set_b.count(*it))
            result.insert(*it);
    return result;
}

template<typename T>
bool equals_sets(set<T>& set_a, set<T>& set_b){
    return equal(set_a.begin(), set_a.end(), set_b.begin(), set_b.end());
}


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