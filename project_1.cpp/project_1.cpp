#include <iostream>
#include <cmath>

int main ();
int main () {
    double finalmax {}, midtermmax {}, p1max {}, p2max {}, p3max {}, p4max {}, p5max {};
    double final {}, midterm {}, p1 {}, p2 {}, p3 {}, p4 {}, p5 {};
    
    while ((finalmax<=0) || (std::round (finalmax) != finalmax)) {
        std::cout<<"Please enter the maximum grade for your final exam: ";
        std::cin>>finalmax;
    }
    do {
        std::cout<<"Please enter the grade you achieved on the final exam: ";
        std::cin>>final;
    } while (final<0 || final>finalmax);

    while (midtermmax<=0 || std::round (midtermmax) != midtermmax) {
        std::cout<<"Please enter the maximum grade for your midterm exam: ";
        std::cin>>midtermmax;
    }
    do {
        std::cout<<"Please enter the grade you achieved on the midterm exam: ";
        std::cin>>midterm;
    } while (midterm<0 || midterm>midtermmax);

    while (p1max<=0 || std::round (p1max) != p1max) {
        std::cout<<"Please enter the maximum grade for your first project: ";
        std::cin>>p1max;
    }
    do {
        std::cout<<"Please enter the grade you achieved on your first project: ";
        std::cin>>p1;
    } while (p1<0 || p1>p1max);

   while (p2max<=0 || std::round (p2max) != p2max) {
        std::cout<<"Please enter the maximum grade for your second project: ";
        std::cin>>p2max;
    }
    do {
        std::cout<<"Please enter the grade you achieved on your second project: ";
        std::cin>>p2;
    } while (p2<0 || p2>p2max);

    while (p3max<=0 || std::round (p3max) != p3max) {
        std::cout<<"Please enter the maximum grade for your third project: ";
        std::cin>>p3max;
    }
    do {
        std::cout<<"Please enter the grade you achieved on your third project: ";
        std::cin>>p3;
    } while (p3<0 || p3>p3max);

    while (p4max<=0 || std::round (p4max) != p4max) {
        std::cout<<"Please enter the maximum grade for your fourth project: ";
        std::cin>>p4max;
    }
    do {
        std::cout<<"Please enter the grade you achieved on your fourth project ";
        std::cin>>p4;
    } while (p4<0 || p4>p4max);

    while (p5max<=0 || std::round (p5max) != p5max) {
        std::cout<<"Please enter the maximum grade for your fifth project: ";
        std::cin>>p5max;
    }
    do {
        std::cout<<"Please enter the grade you achieved on your fifth project ";
        std::cin>>p5;
    } while (p5<0 || p5>p5max);

    //make the grades out of 100
    double final_100 {final/finalmax*100};
    double midterm_100 {midterm/midtermmax*100};
    if (midterm_100<final_100) midterm_100=final_100;
    double p1_100 {p1/p1max*100};
    if (p1_100<final_100) p1_100=final_100;
    double p2_100 {p2/p2max*100};
    if (p2_100<final_100) p2_100=final_100;
    double p3_100 {p3/p3max*100};
    if (p3_100<final_100) p3_100=final_100;
    double p4_100 {p4/p4max*100};
    if (p4_100<final_100) p4_100=final_100;
    double p5_100 {p5/p5max*100};
    if (p5_100<final_100) p5_100=final_100;

    double exam_100 {(3./4.)*final_100+(1./4.)*midterm_100};
    double project_total {0.2*p1_100 + 0.2*p2_100 + 0.2*p3_100 + 0.2*p4_100 + 0.2*p5_100};
    double final_grade {};
    if (exam_100<=40) final_grade=exam_100;
    else if (exam_100>=60) final_grade=(2./3.)*exam_100 + (1./3.)*project_total;
    else {
        final_grade = project_total*(1./3.)*((exam_100-40)/20) + exam_100*(1-(1./3.)*((exam_100 - 40)/20));
    }
    final_grade = std::round (final_grade + 1e-12);

    std::cout<<"Final grade: "<<final_grade<<std::endl;

    return 0;
}