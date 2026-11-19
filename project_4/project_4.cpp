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
    while (str2[i]!='\0') {
        str1[i]=str2[i];
        i++;
    }
    str1[i]='\0';
 }

 unsigned int distance( char const *str1, char const *str2 ) {//returns edit distance between the strings
    if (str1 [0]=='\0' && str2[0]!='\0') {//if str1 is empty and str2 isnt, then the distance is the length of str2
        int count {};
        while (str2[count]!='\0') count++;
        return count;
    }
    else if (str2 [0]=='\0' && str1[0]!='\0') {//if str2 is empty and str1 isnt, then the distane is the lenth of str1
        int count {};
        while (str1[count]!='\0') count++;
        return count;
    }
    else if (str2 [0]=='\0' && str1 [0]=='\0') return 0;
    else if (str1[0]==str2[0]){//if the first character of boths strings are the same, then the idstance is equal to distance between all subsequent letters
        return distance (str1+1, str2+1);
    }
    else {
        if (length (str1)==length(str2)) {//if you need to swap only 2 letters, then edit distance is 1
            std::size_t i {};
            int count {};
            while (str1[i]!='\0') {
                if (str1[i]!=str2[i]) count++;
                i++;
            }
            if (count==2) return 1;
        }
        return 1 + std::min({distance (str1+1, str2+1), distance (str1+1, str2), distance (str1, str2+1)});
    }
 }

 std::size_t is_sorted( char *array[], std::size_t capacity ) {//if the words are sorted, return cap. if not, return first unsorted index
    std::size_t i {};
    while (*array[i]!='\0') {
        if (compare (array[i], array[i+1])>0 || length (array[i])>length (array[i+1])) return i+1;
        i++;
    }
    return capacity;
 }

 void insert( char *array[], std::size_t capacity ) {//assumes all sorted except for last word, and inserts last word where its supposed to be
    //currently does not deal with different length strings unless the character array specifies enough space
    char *temp {new char [length (array[capacity-1] + 1)] {}};//temporary value with same space as word at end of array, allocates space for null character too
    assign (temp, array [capacity-1]);//assigns temp value to same word as word at end of array
    std::size_t i {capacity-1};
    for (; i>0 && compare (array[i-1], temp) > 0; i--) {//while index>0 and array[i-1] is less than temp
        if (compare (array[i-1], temp)>0) {
            assign (array[i], array[i-1]);//inserts 
        }
    }
    assign (array[i], temp);
 }

 void insertion_sort( char *array[], std::size_t capacity ) {
    if (capacity==1) return;
    else {
        insert (array, capacity-1);
    }
 }

 std::size_t remove_duplicates( char *array[], std::size_t capacity ) {//supposed to swtich the addresses or assign the words?
    std::size_t unique {1};//starts at 1 cause 1st entry is automatically unique
    for (std::size_t i {0}; i<capacity; i++) {
        if (compare (array[unique-1], array [i])!=0 && i!=0) {//on the first round, i and unique iwll be same so dont consider
            array [unique]=array[i];
            unique++;
        }
    }
    return unique;
 }

 std::size_t find ( char *array[], std::size_t capacity, char const *str ) {
    for (std::size_t i {}; i<capacity; i++) {//returns index of string where value is
        if (compare (array[i], str)==0) return i;
    }
    std::size_t max_index {};
    unsigned int max_d {distance (array [0], str)};
    for (std::size_t i {}; i<capacity; i++) {//returns index with smallest distance if it cant find string
        if (distance (array[i], str)<max_d) {
            max_d=distance (array[i], str);
            max_index=i;
        }
    }
    return max_index;
 }

void free_word_array( char** word_array ) {
    delete [] word_array [0];
    delete [] word_array;
}

