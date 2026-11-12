#include <iostream>
#include "p_4_header.hpp"

 std::size_t length( char const *a ) {//returns length of string
    int i {};
    while (a [i]!='\0') {
        i++;
    }
    return i;
 }

 int compare( char const *str1, char const *str2 ) {//if string 1 comes first in alphabet, return -. else return +. if same return 0
    int i {};
    while (1) {
        if (str1[i]=='\0' && str2[i]=='\0') return 0;
        else if (str1[i]=='\0' && str2[i]!='\0') return -1;
        else if (str1[i]!='\0' && str2[i]=='\0') return 1;
        else if (str1[i]<str2[i]) return -1;
        else if (str2[i]<str1[i]) return 1;
        else i++;
    }
 }

 void assign( char *str1, char const *str2 ) {//all characters of str1 become same as str2, up to and including null character
    int i {};
    while (str2[i]>='\0') {
        str1[i]=str2[i];
        i++;
    }
 }

 unsigned int distance( char const *str1, char const *str2 ) {//returns edit distance between the strings
    return 0;
 }

 std::size_t is_sorted( char *array[], std::size_t capacity ) {
    return 0;
 }

 void insert( char *array[], std::size_t capacity ) {
 }

 void insertion_sort( char *array[], std::size_t capacity ) {
 }

 std::size_t remove_duplicates( char *array[], std::size_t capacity ) {
    return 0;
 }

 std::size_t find( char *array[], std::size_t capacity, char const *str ) {
    return 0;
 }

void read_words_from_file(char const *filename, char **&word_array, std::size_t &num_words, std::size_t max_length) {

}

void free_word_array( char** word_array ) {

}

