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
        std::stringstream output;
        virtual ~Visitor() = default;

        // Nodes with no children are visited only once (index = 0)
        virtual void visit_rand(Rand* node) = 0;

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
};

#endif //__VISITOR_HPP__
