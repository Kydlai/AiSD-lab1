#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <limits>

void clear_input_buffer();
void input_manager();
void error_message();
std::set<int> check_int_input(std::string& s);
bool repeat_request();
void first_method();
void second_method();
template<typename T>
void printset(std::set<T> data_set);
template<typename T>
std::set<T> combining_sets(std::set<T>& set_a, std::set<T>& set_b);
template<typename T>
std::set<T> difference_sets(std::set<T>& set_a, std::set<T>& set_b);
template<typename T>
bool equals_sets(std::set<T>& set_a, std::set<T>& set_b);
#endif