#ifndef __VISITOR_LATEX_HPP__
#define __VISITOR_LATEX_HPP__

#include "visitor.hpp"
#include <iostream>

class VisitorLaTeX : public Visitor {
    public:
        void visit_sub_begin(Sub* node) {
            std::cout << "{(";
        }
        void visit_sub_middle(Sub* node) {
            std::cout << "-";
        }
        void visit_sub_end(Sub* node) {
            std::cout << ")}";
        }
};

#endif //__VISITOR_LATEX_HPP__
