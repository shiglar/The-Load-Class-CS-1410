#ifndef TUBE_H
#define TUBE_H

#include "shipping_item.h"

class Tube : public ShippingItem {
private:
    //Private data member
    double circumference_;

public:
    //Static constant
    static const double kPi;
    //Constructors and destructor
    Tube() : circumference_(12) {};
    Tube(Address &address, double weight, double length,
         double circumference);
    ~Tube() {};
    //Getter
    double get_circumference() const {return circumference_;};
    //Setter
    void set_circumference(double circumference);
    //Other methods
    double Volume() const;
    double Girth() const {return circumference_;};
    void Display(std::ostream &out) const;
};

#endif