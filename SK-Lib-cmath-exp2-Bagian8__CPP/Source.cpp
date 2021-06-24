#pragma warning(disable:4996)
#pragma fenv_access (on)

#include <iostream>
#include <cmath>
#include <cerrno>
#include <cstring>
#include <cfenv>
#include <conio.h>

/*  Source by CPPReference
    Modified For Learn by Rizky Khapidsyah
    I.D.E : VS2019 */

int main() {
    std::cout << "exp2(4) = " << std::exp2(4) << '\n'
        << "exp2(0.5) = " << std::exp2(0.5) << '\n'
        << "exp2(-4) = " << std::exp2(-4) << '\n';
    // special values
    std::cout << "exp2(-0) = " << std::exp2(-0.0) << '\n' << "exp2(-Inf) = " << std::exp2(-INFINITY) << '\n';
    // error handling
    errno = 0;
    std::feclearexcept(FE_ALL_EXCEPT);
    std::cout << "exp2(1024) = " << std::exp2(1024) << '\n';

    if (errno == ERANGE) {
        std::cout << "    errno == ERANGE: " << std::strerror(errno) << '\n';
    }
        
    if (std::fetestexcept(FE_OVERFLOW)) {
        std::cout << "    FE_OVERFLOW raised\n";
    }
        
    _getch();
    return 0;
}