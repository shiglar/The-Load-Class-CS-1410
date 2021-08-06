#ifndef FLAT_H
#define FLAT_H

#include "shipping_item.h"

class Flat : public ShippingItem {
private:
    //Private data members
    double height_;
    double thickness_;

public:
    //Constructors and destructor
    Flat() : height_(8), thickness_(.4) {};
    Flat(Address &address, double weight, double length,
         double height, double thickness);
    ~Flat() {};
    //Getters
    double get_height() const {return height_;};
    double get_thickness() const {return thickness_;};
    //Setters
    void set_length(double length);
    void set_height(double height);
    void set_thickness(double thickness);
    //Other methods
    double Volume() const;
    void Display(std::ostream &out) const;
};

#endif