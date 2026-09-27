#include <iostream>
int main ();
void pattern (unsigned int n);
unsigned int log10 (unsigned int n);
unsigned int count (unsigned int n, unsigned int bit);

int main () {
    unsigned int n;
    std::cout<<"Please enter a positive integer ";
    std::cin>>n;

    pattern (n);

    return 0;
}


void pattern (unsigned int n) {
    for (int row {1}; row<=n+1; row++) {
        for (unsigned int i {0}; i<row; i++) {
            std::cout<<" ";
        }

        for (unsigned int i {2*n+1}; i>=row; i--) {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
    // for (int m {1}; m<=2*n+1; m++) {
    //     for (unsigned int i {2*n+1}; i>m; i--) {
    //         std::cout<<" ";
    //     }
    //     for (unsigned int i {0}; i<=m; i++) {
    //         std::cout<<"*";
    //     }
    //     std::cout<<std::endl;
    // }
}