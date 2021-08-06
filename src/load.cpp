#include "load.h"
#include "shipping_item.h"
#include "carton.h"
#include "flat.h"
#include "tube.h"
#include <fstream>
#include <iostream>

/**
 * @brief - Fill the shipment depending on specified types from
 *  the input file.
 *  Gather information for each type and pass the new object to
 *  the shipping_items_ vector.
 * @param filename - input file, string type
 */
void Load::FillLoad(std::string filename) {
    index_ = 0;
    std::ifstream input(filename);
    if(input.fail()) {
        std::cout << "File not found. Shutting down...\n";
        return;
    }

    std::string obj_type;
    while(input >> obj_type) {
        Address a1;
        input.ignore();
        std::getline(input, a1.name);
        std::getline(input, a1.street_address);
        std::getline(input, a1.city);
        std::getline(input, a1.state);
        std::getline(input, a1.zip);
        if(obj_type == "C") {
            //Get Carton parameter elements
            double weight, side1, side2, side3;
            input >> weight >> side1 >> side2 >> side3;
            auto c1 = new Carton(a1, weight, side1, side2, side3);
            shipping_items_.push_back(c1);
            //Increment Count, Weight, and Volume
            count_++;
            total_weight_ += c1->get_weight();
            total_volume_ += c1->Volume();
        } else if(obj_type == "F") {
            //Get Flat parameter elements
            double weight, length, height, thickness;
            input >> weight >> length >> height >> thickness;
            auto f1 = new Flat(a1, weight, length, height, thickness);
            shipping_items_.push_back(f1);
            //Increment Count, Weight, and Volume
            count_++;
            total_weight_ += f1->get_weight();
            total_volume_ += f1->Volume();
        } else if(obj_type == "T") {
            //Get Tube parameter elements
            double weight, length, circumference;
            input >> weight >> length >> circumference;
            auto t1 = new Tube(a1, weight, length, circumference);
            shipping_items_.push_back(t1);
            //Increment Count, Weight, and Volume
            count_++;
            total_weight_ += t1->get_weight();
            total_volume_ += t1->Volume();
        } else {
            std::cout << "Something went wrong. Shutting down...";
        }
    }
    input.close();
}

/**
 * @brief - Destructor to delete dynamic memory in
 *  the shipping_items_ vector.
 */
Load::~Load() {
    for(auto* &item_ptr : shipping_items_) {
        delete item_ptr;
        item_ptr = NULL;
    }
}

/**
 * @brief - Display the next delivery depending on the
 *  count_ data member value
 * @param out - ostream object
 */
void Load::DisplayNextDelivery(std::ofstream &out) const {
    Address a1 = shipping_items_[index_]->get_address();
    out << a1.name << "\n" << a1.street_address << "\n"
        << a1.city << ", " << a1.state << " " << a1.zip << "\n";
    shipping_items_[index_]->Display(out);
    out << "\n";
}

/**
 * @brief - Marks item as delivered
 *  Changes to the next item
 */
void Load::ItemDelivered() {
   shipping_items_[index_]->MarkDelivered();
   index_++;
}

/**
 * @brief - Leaves delivered to false
 *  Moves to the next item for delivery
 */
void Load::NotDeliverable() {
    index_++;
}

/**
 * @brief - Calculate how many items were delivered
 *  Use range loop and if get_delivered is true, increment
 *  how_many_delivered int variable
 * @return - int type
 */
int Load::HowManyDelivered() const {
    int how_many_delivered = 0;
    for(auto item : shipping_items_) {
        if(item->get_delivered()) {
            how_many_delivered++;
        }
    }
    return how_many_delivered;
}

/**
 * @brief - Calculate how many items were not delivered
 *  Use range loop and if get_delivered is false, increment
 *  how_many_not_delivered int variable
 * @return - int type
 */
int Load::HowManyNotDelivered() const {
    int how_many_not_delivered = 0;
    for(auto item : shipping_items_) {
        if(!item->get_delivered()) {
            how_many_not_delivered++;
        }
    }
    return how_many_not_delivered;
}