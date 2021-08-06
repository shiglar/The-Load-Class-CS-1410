#include <iostream>
#include <fstream>
#include "shipping_item.h"
#include "carton.h"
#include "flat.h"
#include "tube.h"
#include "load.h"

using namespace std;

int main() { 


  cout << "Part 2.2: Use the Carton Class in Main.cpp\n";

  // Create a Carton object using the new constructor.
  // When using this constructor, use try/catch blocks to handle
  // the exceptions.

  //Set the Address object values
  Address address1;
  address1.name = "John";
  address1.street_address = "14 12th St";
  address1.city = "Ogden";
  address1.state = "Utah";
  address1.zip = "84404";

  Carton carton1;

  //Try/catch block when calling Carton Non-Default constructor
  try {
      carton1 = Carton(address1, 5.73, 10.2, 4.5, 5.75);
  } catch (out_of_range &e) {
      cout << e.what() << "\n";
  }

  // Use the Carton object to call the getter and setter methods.
  // Print out the results to see that the methods are doing what is expected.
  // When calling the setters, use try/catch blocks to handle the exceptions.

  //Output Carton object values
  cout << "Carton 1\nLength: " << carton1.get_length()
        << "\nWidth: " << carton1.get_width()
        << "\nHeight: " << carton1.get_height() << "\n\n";

  //Try/catch block for calling Carton set_measurements method
  try {
      carton1.set_measurements(5.55, 8.7, 2.3);
  } catch (out_of_range &e) {
      cout << e.what() << "\n";
  }

  //Output new Carton object values
  cout << "Carton 1\nLength: " << carton1.get_length()
       << "\nWidth: " << carton1.get_width()
       << "\nHeight: " << carton1.get_height() << "\n\n";

  // Use the Carton object to call the Display method to print to cout.
  carton1.Display(cout);

  cout << "\n";

  cout << "\nPart 3.3: Use the Flat Class in Main.cpp\n";

  // Create Flat objects using the default and non-default constructors.
  // When using the non-constructor, use try/catch blocks to handle the
  // exceptions.
  Flat flat1;

  //Try/catch block for calling Flat Non-Default constructor
  Flat flat2;
  try {
    flat2 = Flat(address1, .55, 6.8, 4.33, .21);
  } catch (out_of_range &e) {
      cout << e.what() << "\n";
  }

  // Use the Flat objects to call the getter and setter methods.
  // Print out the results to see how these getters and setters are working.
  // When calling the setters, use try/catch blocks to handle the exceptions.

  //Try/catch block for calling Flat set_length method
  try {
      flat2.set_length(6.5);
  } catch (out_of_range &e) {
      cout << e.what() << "\n";
  }

  //Try/catch block for calling Flat set_height method
  try {
      flat2.set_height(4.44);
  } catch (out_of_range &e) {
      cout << e.what() << "\n";
  }

  //Try/catch block for calling Flat set_thickness method
  try {
      flat2.set_thickness(.29);
  } catch (out_of_range &e) {
        cout << e.what() << "\n";
  }

  //Output Flat values
  cout << "Flat Length: " << flat2.get_length() << "\n";
  cout << "Flat Height: " << flat2.get_height() << "\n";
  cout << "Flat Thickness: " << flat2.get_thickness() << "\n";

  cout << "\n";

  // Use the Flat objects to call the Volume and Display methods.
  // Print out the results to cout.

  //Output Flat Volume value
  cout << "Flat Volume: " << flat2.Volume() << "\n";
  //Output Flat using Display method
  flat2.Display(cout);

  cout << "\n";

  cout << "\nPart 4.3: Use the Tube Class in Main.cpp\n";

  // 1. Create Tube objects using the default and non-default constructors.
  // When using the non-constructor, use try/catch blocks to handle the
  // exceptions.
  Tube tube1;

  Tube tube2;
  //Try/catch block for calling Tube Non-default constructor
  try {
      tube2 = Tube(address1, 3.22, 7.8, 2.1);
  } catch (out_of_range e) {
      cout << e.what() << "\n";
  }

  // Use the Tube objects to call the getter and setter methods.
  // Print out the results to see how these getters and setters are working.
  // When calling the setters, use try/catch blocks to handle the exceptions.

  //Try/catch block for calling Tube set_circumference method
  try {
      tube1.set_circumference(4.65);
  } catch (out_of_range e) {
      cout << e.what() << "\n";
  }

  //Try/catch block for calling Tube set_length method
  try {
      tube1.set_length(18.43);
  } catch (out_of_range e) {
      cout << e.what() << "\n";
  }

  //Output Tube values
  cout << "Tube1 circumference: " << tube1.get_circumference() << "\n";
  cout << "Tube1 length: " << tube1.get_length() << "\n";
  cout << "Tube2 circumference: " << tube2.get_circumference() << "\n";
  cout << "Tube2 length: " << tube2.get_length() << "\n\n";

  // Use the Tube objects to call the Volume, Girth and Display methods.
  // Print out the results to cout.

  //Output Tube Volume value
  cout << "Tube2 Volume: " << tube2.Volume() << "\n";
  //Output Tube Girth value
  cout << "Tube2 Girth: " << tube2.Girth() << "\n";
  //Output using Tube Display method
  tube2.Display(cout);

  cout << "\n\nPart 5.3: Use the Load Class in Main.cpp\n";

  // 1. Create a Load object.
  Load load1;

  // 2. Use the Load object to call the getter methods.
  // Print out the results to see how these getters are working.
  // Do this right after the Load object is created and after it
  // is filled from the file.

//  //Output Load Total values
//  cout << "Total # of packages: " << load1.get_count() << "\n";
//  cout << "Total Weight: " << load1.get_total_weight() << "\n";
//  cout << "Total Volume: " << load1.get_total_volume() << "\n";

  //3. Use the Load object to call the FillLoad method.
  // Then call the DisplayNextDelivery, ItemDelivered, NotDeliverable,
  // HowManyDelivered, and HowManyNotDelivered methods multiple times
  // to see how these work when making deliveries.

  //Call FillLoad to get information from an input file
  //And fill ShippingItem vector
  load1.FillLoad("../../load_1.txt");

    //Output Load Total values
    cout << "Total # of packages: " << load1.get_count() << "\n";
    cout << "Total Weight: " << load1.get_total_weight() << "\n";
    cout << "Total Volume: " << load1.get_total_volume() << "\n";

  //Create an ofstream object
  ofstream output("../../next_delivery.txt");
  //Display next delivery on output file
  load1.DisplayNextDelivery(output);

  //Call ItemDelivered to set delivered to true
  load1.ItemDelivered();
  //Display next delivery on output file
  load1.DisplayNextDelivery(output);

  //Call ItemDelivered to set delivered to true
  load1.ItemDelivered();
  //Display next delivery on output file
  load1.DisplayNextDelivery(output);

  //Output how many packages have been delivered
  cout << "Packages Delivered: " << load1.HowManyDelivered() << "\n";
  //Output how many packages have not been delivered
  cout << "Packages Not Delivered: " << load1.HowManyNotDelivered() << "\n";

  //Close Output file
  output.close();


  return 0; 
}