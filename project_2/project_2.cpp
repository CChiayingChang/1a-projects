#include <iostream>
#include <cassert>
int main ();
void pattern (unsigned int n);
unsigned int log10 ( unsigned int n);
unsigned int count (unsigned int n, unsigned int bit);
unsigned int swap_bytes (unsigned int n, unsigned int b0, unsigned int b1);

int main () {
    unsigned int n {};
    std::cout<<"Please enter a positive integer: ";
    std::cin>>n;

    pattern (n);

    log10 (n);

    int howmany {};
    std::cout<<"Do you want to count the numbers of 1's or 0's in "<<n<<"? ";
    std::cin>>howmany;
    std::cout<<"The tally is "<<count (n, howmany)<<std::endl;

    swap_bytes (n, 0, 1);

    return 0;
}

void pattern (unsigned int n) {
    for (int row {1}; row<=n+1; row++) {//top half of patterm
        for (unsigned int i {0}; i<row-1; i++) {
            std::cout<<" ";
        }

        for (unsigned int i {1}; i<=2*n+1-(2*(row-1)); i++) {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }

    for (unsigned int row {n}; row>0; row--) {//lower half of pattern
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

unsigned int log10 (unsigned int n) {
    assert (n!=0);
    unsigned int m {0};
    while (std::pow(10, m)<n) {
        m+=1;
    }
    if (std::pow(10, m) > n) m-=1;
   std::cout<<"The largest value of m for 10^m <= " <<n<<" is "<<m<<std::endl;
   return 0;
}

unsigned int count (unsigned int n, unsigned int bit) {//counts the number of 1's or 0's in n
    assert (bit==1 || bit==0);
    int tally {0};

    if (bit==0) {
        for (unsigned int mask {1U<<31}; mask>0; mask>>=1) {//counts the numbers of 0's
            if ((n & mask)==0) tally+=1;
        }
    }

    if (bit==1) {
        for (unsigned int mask {1U<<31}; mask>0; mask>>=1) {//counts the numbers of 1's
            if ((n & mask) !=0) tally+=1;
        }
    }

    return tally;
}

unsigned int swap_bytes (unsigned int n, unsigned int b0, unsigned int b1) {//swap one of the 4 bytes by using bit shift operators
    assert (b0>=1 && b0<=3);
    assert (b1>=1 && b1<=3);
    return 0;
}