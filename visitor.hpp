#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

#include <iostream>
#include <string>
#include <sstream>

class Op;
class Rand;
class Add;
class Sub;
class Mult;
class Div;
class Pow;

class Visitor{
    public:
        std::ostringstream output;
        std::stringstream output;      
        virtual ~Visitor() = default;

        // Nodes with no children are visited only once (index = 0)
        virtual void visit_op(Op* node) = 0;
        // Nodes with no children are visited only once (index = 0)
        virtual void visit_rand(Rand* node) = 0;

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
        virtual void visit_add_begin(Add* node) = 0;
	virtual void visit_add_middle(Add* node) = 0;
	virtual void visit_add_end(Add* node) = 0;
	virtual void visit_sub_begin(Sub* node) = 0;
        virtual void visit_sub_middle(Sub* node) = 0;
        virtual void visit_sub_end(Sub* node) = 0;
        virtual void visit_div_begin(Div* node) = 0;
        virtual void visit_div_middle(Div* node) = 0;
        virtual void visit_div_end(Div* node) = 0;
};

#endif //__VISITOR_HPP__
