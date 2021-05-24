#ifndef __RAND_HPP__
#define __RAND_HPP__

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include "base.hpp"

class Rand : public Base {
    public: 
        Rand() : Base() {}
        virtual double evaluate() {
            random = rand() % 100;
            return random;
        }
        virtual std:: string stringify() {
            std::ostringstream ss;
            ss << std::setprecision(8) << std::noshowpoint << random;
            return ss.str();
        }

    private: 
        double random;
};

#endif //__RAND_HPP__
