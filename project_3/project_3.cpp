#include <iostream>
#include <cassert>

int main ();
double *geometric( double a, double ratio, std::size_t cap );
double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1);
std::size_t shift_duplicates( int array[], std::size_t capacity );
void deallocate( double *&ptr, bool is_array, std::size_t capacity = 0 );

int main () {

    return 0;
}

double *geometric( double a, double ratio, std::size_t cap ) {
    double *array {new double [cap] {}};
    for (std::size_t i{0}; i<cap; i++) {
        double multiply {1};
        for (std::size_t k {0}; k<i; k++) {
            multiply*=ratio;
        }
        array [i]=a*multiply;
    }
    return array;
}

double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1) {
    assert (cap0+cap1>=1);
    double *array {new double [cap0+cap1-1] {0}};
    for (std::size_t i {0}; i<cap0; i++) {
        for (std::size_t j {0}; j<cap1; j++) {
            array [i+j]+=array0[i]*array1[j];
        }
    }
    return array;
}

std::size_t shift_duplicates( int array[], std::size_t capacity ) {
    std::size_t unique {};
    std::size_t start {0};
    for (std::size_t i{0}; i<capacity; i++) {
        bool unique_or_not {true};
        for (std::size_t k {i}; k>0; k--) {
            if (array[i]==array[k-1]) {
                unique_or_not=false;
                break;
            }
        }
        if (unique_or_not) {
            unique++;
            int temp_unique {array[i]};
            int temp_start {array[start]};
            array[start]=temp_unique;
            array[i]=temp_start;
            start++;
        }
    }
        return unique;
}

void deallocate( double *&ptr, bool is_array, std::size_t capacity ) {
    if (ptr!=nullptr) {
        if (is_array) {
            for (std::size_t i {0}; i<capacity; i++) {
                ptr[i]=0;
            }
            delete [] ptr;
        }
        else {
            *ptr=0;
            delete ptr;
        }
    }
    ptr=nullptr;
}