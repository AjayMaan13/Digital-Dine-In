#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "constants.h"
#include "Food.h"
#include "Drink.h"
#include "Billable.h"
#include "Menu.h"
#include "Utils.h"
#include "Ordering.h"

// using namespaces here
using namespace std;
using namespace seneca;

int flag = 0; // used in ms4 but not in use now
namespace seneca {

   // Constructor here
   Ordering::Ordering(const char* drinkFile, const char* foodFile) {
      drinkCount = countRecords(drinkFile);
      foodCount = countRecords(foodFile);
      // ifstream used to get drink and food data
      ifstream din(drinkFile), fin(foodFile); // fstream
      if (din && fin) { // if
         drinks = new Drink[drinkCount];
         foods = new Food[foodCount];
         // loop to read data ->
         for (size_t i = 0; i < drinkCount && din; ++i) drinks[i].read(din);
         for (size_t i = 0; i < foodCount && fin; ++i) foods[i].read(fin);
         // check if any looping fails or not
         if (din.fail() || fin.fail()) { // delete every dynamic memory
            delete[] drinks;
            delete[] foods;
            drinks = nullptr;
            foods = nullptr;
         }
      }
   }

   // Destructor
   Ordering::~Ordering() { // delete 
      delete[] drinks;
      delete[] foods;
      for (size_t i = 0; i < billItemCount; ++i) delete billItems[i]; // delete bill Items
   }


   // count the number of records
   size_t Ordering::countRecords(const char* file) const {
      size_t count = 0;
      ifstream fin(file);
      char ch;

      // get fin until its newline to check the count of records or lines
      while (fin.get(ch)) { if (ch == '\n') ++count; }
      return count;
   }

   // One line functions here to get data
   Ordering::operator bool() const { return drinks && foods; }
   size_t Ordering::noOfBillItems() const { return billItemCount; }
   bool Ordering::hasUnsavedBill() const { return billItemCount > 0; }


   // LIst food is done here -> 
   void Ordering::listFoods() const {
      cout << "List Of Avaiable Meals\n========================================\n";
      for (size_t i = 0; i < foodCount; ++i) foods[i].print(); // loop to print each food
      cout << "========================================\n";
   }
   void Ordering::listDrinks() const {
      cout << "List Of Avaiable Drinks\n========================================\n"; // loop to print each drink
      for (size_t i = 0; i < drinkCount; ++i) drinks[i].print();
      cout << "========================================\n";
   }

   // Order food is here 
   void Ordering::orderFood() {
      seneca::Menu menu("Food Menu", "Back to Order", 2); // exit option used her
      for (size_t i = 0; i < foodCount; ++i) menu << foods[i].getName(); // loop to get name and output it
      int sel = menu.select(); // variable decleration
      if (sel > 0 && billItemCount < MaximumNumberOfBillItems) { // check if condition
         Billable* ordered = new Food(foods[sel - 1]);
         if (ordered->order()) billItems[billItemCount++] = ordered; // if
         else delete ordered;
      }
   }


   // Order drink function to order Drink
   void Ordering::orderDrink() {
      Menu menu("Drink Menu", "Back to Order", 2); // exit option used too
      for (size_t i = 0; i < drinkCount; ++i) menu << drinks[i].getName(); // loop
      int sel = menu.select(); // variable



      // if conditon
      if (sel > 0 && billItemCount < MaximumNumberOfBillItems) {
         Billable* ordered = new Drink(drinks[sel - 1]); // new Drink
         if (ordered->order()) billItems[billItemCount++] = ordered;
         else delete ordered;
      }
   }

   // PrintBillTitle
   void Ordering::printBillTitle(ostream& os) const {
      os << "Bill # ";
      if (billNumber < 10) os << "00";
      else if (billNumber < 100) os << "0";
      os << billNumber << " =============================" << endl;
   }

   // Print totals here
    void Ordering::printTotals(ostream& os, double total) const {
      // Variable Decleratioon
        double tax = total * Tax;
        double grandTotal = total + tax;
         // set indentation
        int totalIndent = 6, grandTotalIndent = 10;

        if (total > 9.99) { totalIndent++; }
        if (grandTotal > 9.99) { grandTotalIndent++; }
        // output settings
        os.setf(ios::fixed);
        os.precision(2);
        os << "                     Total:"
        << setw(36 - 21 - totalIndent) << ""
        << total << endl;
        os << "                     Tax:"
        << setw(36 - 21 - 4) << ""
        << tax << endl;
        os << "                     Total+Tax:"
        << setw(36 - 21 - grandTotalIndent) << ""
        << grandTotal << endl;
        os << "========================================" << endl;
        // done of print
    }


   void Ordering::printBill(ostream& os) const {
      double total = 0;
      //cout << "before title" << endl;
      printBillTitle(os);
      for (size_t i = 0; i < billItemCount; i++) {
        //cout << "before print of billitems" << endl;
       
        if(billItems[i] != nullptr){billItems[i]->print(os);}
        //cout << "Flag: " << flag << endl;
        //if (flag == 2 || flag == 4)
        //{
          //  os << endl;
            
        //}
        //flag ++;

        //cout<< "inside loop after print func, Loop"<< i +1  << endl;
        total += billItems[i]->price();
      }
      //cout << "outside loop, before totals"<< endl;
      printTotals(os, total);
      //cout << "after totals" << endl;
   }

   // reset Bill done here ->
   void Ordering::resetBill() {
      char filename[64];
      Utils utils; // new utils
      utils.makeBillFileName(filename, billNumber);
      ofstream fout(filename);
      printBill(fout); // print bill
      fout.close();
      cout << "Saved bill number " << billNumber << endl;
      ++billNumber;
      cout << "Starting bill number " << billNumber << endl;
      for (size_t i = 0; i < billItemCount; ++i) delete billItems[i]; // billItems
      billItemCount = 0;
   }
}
