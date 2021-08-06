#include "flat.h"
#include <iomanip>

/**
 * @brief - Set length parameter to length data member
 * @param length - double type
 */
void Flat::set_length(double length) {
    if(length < kMinSize) {
        throw std::out_of_range("Length is too small.");
    } else if(length > 15) {
        throw std::out_of_range("Length is too great.");
    } else {
        length_ = length;
    }
}

/**
 * @brief - Set height parameter to height data member
 * @param height - double type
 */
void Flat::set_height(double height) {
    if(height < kMinSize) {
        throw std::out_of_range("Height is too small.");
    } else if(height > 12) {
        throw std::out_of_range("Height is too great.");
    } else {
        height_ = height;
    }
}

/**
 * @brief - Set thickness paramter to thickness data member
 * @param thickness - double type
 */
void Flat::set_thickness(double thickness) {
    if(thickness < kMinSize) {
        throw std::out_of_range("Thickness is too small.");
    } else if(thickness > .75) {
        throw std::out_of_range("Thickness is too great.");
    } else {
        thickness_ = thickness;
    }
}

/**
 * @brief - Non-default constructor
 *  Call base class with address, weight, and length
 *  Call Flat length, height, and thickness setters
 * @param address - Address object
 * @param weight - double type
 * @param length - double type
 * @param height - double type
 * @param thickness - double type
 */
Flat::Flat(Address &address, double weight, double length,
double height, double thickness) : ShippingItem(address, weight, length) {
    Flat::set_length(length);
    set_height(height);
    set_thickness(thickness);
}

/**
 * @brief - Calculate the volume of the flat item
 * @return - volume, double type
 */
double Flat::Volume() const {
    return length_ * height_ * thickness_;
}

/**
 * @brief - Display Flat information
 * @param out - ostream object
 */
void Flat::Display(std::ostream &out) const {
    out << std::fixed << std::setprecision(1)
        << "Flat: " << weight_ << " lbs. "
        << length_ << " x " << height_ << " x "
        << thickness_;
}