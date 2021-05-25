#ifndef __VISITOR_LATEX_HPP__
#define __VISITOR_LATEX_HPP__

#include "visitor.hpp"
#include "iterator.hpp"
#include "op.hpp"
#include "sub.hpp"

class VisitorLaTeX : public Visitor {
    public:
        void visit_op(Op* node) {
            output << "{";
            output << node->stringify();
            output << "}";
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
