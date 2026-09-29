#include <iostream>
int main ();
void pattern (unsigned int n);
unsigned int log10 (unsigned int n);
unsigned int count (unsigned int n, unsigned int bit);

int main () {
    unsigned int n {};
    std::cout<<"Please enter a positive integer ";
    std::cin>>n;

    pattern (n);

    return 0;
}


void pattern (unsigned int n) {
    for (int row {1}; row<=n+1; row++) {
        for (unsigned int i {0}; i<row-1; i++) {
            std::cout<<" ";
        }

        for (unsigned int i {1}; i<=2*n+1-(2*(row-1)); i++) {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }

    for (unsigned int row {n}; row>0; row--) {
        for (unsigned int i {0}; i<row-1; i++) {
            std::cout<<" ";
        }

        for (unsigned int i {1}; i<=2*n+1-(2*(row-1)); i++) {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
}