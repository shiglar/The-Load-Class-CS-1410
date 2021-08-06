#include "tube.h"
#include <iomanip>

/**
 * @brief - Implement static constant
 */
const double Tube::kPi = 3.14159;

/**
 * @brief - Set circumference parameter to circumference data member
 *  If circumference is less than kMinSize throw exception
 *  Else if circumference is greater than kMaxSize throw exception
 * @param circumference - double type
 */
void Tube::set_circumference(double circumference) {
    if(circumference < kMinSize) {
        throw std::out_of_range("Circumference is too small.");
    } else if((circumference + length_) > kMaxSize) {
        throw std::out_of_range("Circumference is too great.");
    } else {
        circumference_ = circumference;
    }
}

/**
 * @brief - Non-default constructor
 *  Set parameters to data members
 * @param address - Address object
 * @param weight - double type
 * @param length - double type
 * @param circumference - double type
 */
Tube::Tube(Address &address, double weight, double length,
           double circumference) : ShippingItem(address, weight, length) {
    set_circumference(circumference);
}

/**
 * @brief - Calculate Volume of a Tube
 *  volume = Pi(C/2Pi)(C/2Pi)l
 * @return - volume, double type
 */
double Tube::Volume() const {
    return (kPi*(circumference_/(2*kPi)))*(circumference_/(2*kPi))*length_;
}

/**
 * @brief - Display Tube information
 * @param out - ostream object
 */
void Tube::Display(std::ostream &out) const {
    out << std::fixed << std::setprecision(1)
        << "Tube: " << weight_ << " lbs. "
        << length_ << " x " << circumference_;
}
