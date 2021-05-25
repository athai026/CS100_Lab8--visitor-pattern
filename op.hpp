#ifndef __OP_HPP__
#define __OP_HPP__

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include "base.hpp"

class Op : public Base {
    public:
        Op(double value) : Base() ,value(value) {}
        virtual double evaluate() { return value; }
        virtual std::string stringify() { 
            std::ostringstream ss;
            ss << std::setprecision(8) << std::noshowpoint << value;
            return ss.str();
        }
        virtual int number_of_children() {
            return 0;
        }
        virtual Base* get_child(int i) {
            return nullptr;
        }
        virtual void accept(Visitor* visitor, int index) {
           visitor->visit_op(this);
        } 
    private: 
        double value;
};

#endif //__OP_HPP__
