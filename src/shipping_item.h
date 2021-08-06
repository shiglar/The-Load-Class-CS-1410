#ifndef SHIPPING_ITEM_H
#define SHIPPING_ITEM_H

#include <string>
#include <ostream>

struct Address {
    std::string name;
    std::string street_address;
    std::string city;
    std::string state;
    std::string zip;
};

class ShippingItem {
protected:
    //Protected data members
    Address address_;
    double weight_;
    double length_;
    bool delivered_;
public:
    //Static constants
    static const double kMaxWeight;
    static const double kMaxSize;
    static const double kMinSize;
    //Constructors and destructor
    ShippingItem();
    ShippingItem(Address address, double weight, double length);
    ~ShippingItem() {};
    //Getters
    //Return matching data members
    Address get_address() const {return address_;};
    double get_weight() const {return weight_;};
    double get_length() const {return length_;};
    bool get_delivered() const {return delivered_;};
    //Setters
    void set_address(Address &address);
    void set_weight(double weight);
    virtual void set_length(double length);
    void set_delivered(bool delivered);
    //Other methods
    void MarkDelivered();
    virtual double Volume() const = 0;
    virtual void Display(std::ostream &out) const = 0;
};

#endif