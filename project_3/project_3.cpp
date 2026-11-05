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
    for (int i{0}; i<cap; i++) {
        double multiply {1};
        for (int k {0}; k<i; k++) {
            multiply*=ratio;
        }
        array [i]=a*multiply;
    }
    return array;
}

double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1) {
    assert (cap0+cap1>=1);
    double *array {new double [cap0+cap1-1] {0}};
    for (int i {0}; i<cap0; i++) {
        for (int j {0}; j<cap1; j++) {
            array [i+j]+=array0[i]*array1[j];
        }
    }
    return array;
}

std::size_t shift_duplicates( int array[], std::size_t capacity ) {
    int unique {};
    std::size_t end {capacity};
    int *a_temp {new int [capacity] {0}};
    for (int i {0}; i<capacity; i++) {
        int count {i};
        bool unique_or_not {true};
        for (int k {i-1}; k>=0; k--) {
            if (array[i]==array[k]) {
                unique_or_not=false;
                break;
            }
        }
        if (unique_or_not) {
            unique++;
            a_temp[unique-1]=array[i];
        } else {
            end--;
            a_temp[end]=array[i];
        }
    }

    for (int i{0}; i<capacity; i++) {
        array[i]=a_temp[i];
    }

    return unique;
}

void deallocate( double *&ptr, bool is_array, std::size_t capacity ) {
    if (is_array) {
        for (int i {0}; i<capacity; i++) {
            ptr[i]=0;
        }
        delete [] ptr;
    }
    else {
        *ptr=0;
        delete ptr;
    }
    ptr=nullptr;
}