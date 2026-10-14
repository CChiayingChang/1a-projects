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

    //pattern (n);

    std::cout<<"The largest value of m for 10^m<=n is "<<log10 (n)<<std::endl;

    int howmany {};
    std::cout<<"Do you want to count the numbers of 1's or 0's in "<<n<<"? ";
    std::cin>>howmany;
    std::cout<<"The tally is "<<count (n, howmany)<<std::endl;

    int b0 {}, b1{};
    std::cout<<"Which bytes do you want to swap? ";
    std::cin>>b0;
    std::cin>>b1;
    std::cout<<"Your new number is "<< swap_bytes (n, b0, b1)<<std::endl;

    return 0;
}

void pattern (unsigned int n) {
    for (unsigned int row {1}; row<=n+1; row++) {//top half of patterm
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
}

unsigned int log10 (unsigned int n) {
    assert (n!=0);
    unsigned int m {0};
    while (n>=10) {
        n/=10;
        m++;
    }
   return m;
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

unsigned int swap_bytes (unsigned int n, unsigned int b0, unsigned int b1) {//swap one of the 4 bytes by using bit shift operators//use pass-by reference??
    assert (b0>=0 && b0<=3);
    assert (b1>=0 && b1<=3);
    if (b0==b1) {
        return n;
    }
    unsigned int mask {0b11111111};
    unsigned int one= n>>(b0*8);//if you choose 0 for example 0x8=0 so it doesnt shift-->that way it overlaps with mask
    one=mask&one;//extracts only the byte that you moved to the end
    one=one<<(b1*8);//moves the part over to the spot of the other bit
    unsigned int two= n>>(b1*8);
    two=mask & two;
    two=two<<(b0*8);
    n =n & (~(mask<<(b0*8)));//clears the spot where b0 used to be and turns it to all 0
    n = n&(~(mask<<(b1*8)));
    n=n| one;
    n=n|two;

    return n;
}