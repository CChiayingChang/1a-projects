#include <iostream>
int main ();
void pattern (unsigned int n);
unsigned int log10 ( unsigned int n);
unsigned int count (unsigned int n, unsigned int bit);

int main () {
    unsigned int n {};
    std::cout<<"Please enter a positive integer ";
    std::cin>>n;

    pattern (n);

    log10 (n);

    return 0;
}

 unsigned int log10 (unsigned int n) {//assert that argument!=0
    unsigned int m {0};
    while (std::pow(10, m)<n) {
        m+=1;
    }
    if (std::pow(10, m) > n) m-=1;
   std::cout<<"The largest value of m for 10^m <= n is "<<m<<std::endl;//not working-->when larger numbers, returns too small
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
    std::cout<<std::endl;
}