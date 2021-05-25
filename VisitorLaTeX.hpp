#ifndef __VISITOR_LATEX_HPP__
#define __VISITOR_LATEX_HPP__

#include "visitor.hpp"
#include "iterator.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "rand.hpp"

class VisitorLaTeX : public Visitor {
    public:
        void visit_rand(Rand* node) {
        output << "{";
            output << node->stringify();
            output << "}";
        }
        void visit_op(Op* node) {
            output << "{";
            output << node->stringify();
            output << "}";
        }
	void visit_mult_begin(Mult* node) {
            output << "{(";
        }
        void visit_mult_middle(Mult* node) {
            output << "\\cdot";
        }
        void visit_mult_end(Mult* node) {
            output << ")}";
        }
        void visit_sub_begin(Sub* node) {
            output << "{(";
        }
        void visit_sub_middle(Sub* node) {
            output << "-";
        }
        void visit_sub_end(Sub* node) {
            output << ")}";
        }
        void visit_div_begin(Div* node) {
            output << "{\\frac";
        }
        void visit_div_middle(Div* node) {
            output << "";
        }
        void visit_div_end(Div* node) {
            output << "}";
        }
        std::string PrintLaTeX(Base* ptr) {
            output << "$";
            for(Iterator it(ptr); !it.is_done(); it.next()) {
                it.current_node()->accept(this, it.current_index());
            }
            output << "$";
            return output.str();
        }
};

#endif //__VISITOR_LATEX_HPP__
