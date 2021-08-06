#include "shipping_item.h"
#include <string>
#include <ostream>

/**
 * @brief - Implement static constants
 */
const double ShippingItem::kMaxWeight = 70;
const double ShippingItem::kMaxSize = 108;
const double ShippingItem::kMinSize = .007;

/**
 * @brief - Set address parameter to address data member
 * @param address - Address object
 */
void ShippingItem::set_address(Address &address) {
    address_ = address;
}

/**
 * @brief - Set weight parameter to weight data member
 *  Throw exception if parameter is greater than kMaxWeight
 *  or less than 0
 * @param weight - double type
 */
void ShippingItem::set_weight(double weight) {
    if(weight < 0) {
        throw std::out_of_range("Weight is too small.");
    } else if(weight > kMaxWeight) {
        throw std::out_of_range("Weight is too great.");
    } else {
        weight_ = weight;
    }
}

/**
 * @brief - Set length parameter to length data member
 * Throw exception if parameter is greater than kMinSize
 * or less than min size
 * @param length - double type
 */
void ShippingItem::set_length(double length) {
    if(length < kMinSize) {
        throw std::out_of_range("Length is too small.");
    } else if(length > kMaxSize) {
        throw std::out_of_range("Length is too great.");
    } else {
        length_ = length;
    }
}

/**
 * @brief - Set delivered parameter to delivered data member
 * @param delivered - boolean type
 */
void ShippingItem::set_delivered(bool delivered) {
    delivered_ = delivered;
}

/**
 * @brief - Default constructor
 */
ShippingItem::ShippingItem() {
    address_.name = "unknown";
    weight_ = 2;
    length_ = 12;
    delivered_ = false;
}

/**
 * @brief - Non-default constructor
 *  Set parameters to data members
 * @param address - Address object
 * @param weight - double type
 * @param length - double type
 */
ShippingItem::ShippingItem(Address address, double weight,
                           double length) {
    set_address(address);
    set_weight(weight);
    set_length(length);
    set_delivered(false);
}

/**
 * @brief - Set the delivered data member to true
 */
void ShippingItem::MarkDelivered() {
    delivered_ = true;
}
