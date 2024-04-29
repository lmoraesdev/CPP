#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <stdint.h>

// Base class
class Base {
    public:
        virtual ~Base(void);
};

// Inherited classes
class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
