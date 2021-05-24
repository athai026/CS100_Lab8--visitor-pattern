#ifndef __POW_HPP__
#define __POW_HPP__

#include "op.hpp"
#include <cmath>

class Pow : public Base {
    public:
        Pow(Base* left, Base* right) : Base() {
            l_value = left->evaluate();
            r_value = right->evaluate();
            l_string = left->stringify();
            r_string = right->stringify();
        }
        virtual double evaluate() {
        	product = 1.0;

    		if (r_value == 0) {
        		return product;
    		}
   		else if (l_value == 0) {
        		if (r_value <= 0) {
            			throw "Undefined error";
        		}	
        		else {
            			product = 0.0;
            			return product;
        		}
    		}
    		else {
        		for (int i = 0; i < fabs(r_value); ++i) {
            			product *= l_value;
        		}

        		if (r_value < 0) {
            			return (1 / product);
        		}
        		else {
            			return product;
        		}
    		}
	}
        virtual std::string stringify() {
            return ("(" + l_string + "**" + r_string + ")");
        }

    private:
        double l_value, r_value, product;
        std::string l_string, r_string;
        Base* left;
        Base* right;
};

#endif //__POW_HPP__
