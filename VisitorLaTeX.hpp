#ifndef __VISITOR_LATEX_HPP__
#define __VISITOR_LATEX_HPP__

#include "visitor.hpp"
#include "iterator.hpp"

class VisitorLaTeX : public Visitor {
    public:
        void visit_op(Op* node) {
            //output << "{";
            //output << node->stringify();
            //output << "}";
            std::cout << "{";
            std::cout << node->stringify();
            std::cout << "}";
        }

        void visit_sub_begin(Sub* node) {
            //output << "{(";
            std::cout << "{(";
        }
        void visit_sub_middle(Sub* node) {
            //output << "-";
            std::cout << "-";
        }
        void visit_sub_end(Sub* node) {
            //output << ")}";
            std::cout << ")}";
        }

        std::string PrintLaTeX(Base* ptr) {
            //output << "$";
            std::cout << "$";
            for(Iterator it(ptr); !it.is_done(); it.next()) {
                it.current_node()->accept(this, it.current_index());
            }
            //output << "$";
            std::cout << "$";
            return "done";
        }
};

#endif //__VISITOR_LATEX_HPP__
