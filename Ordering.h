#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H

// inported libraries and .h files
#include <iostream>
#include "Food.h"
#include "Drink.h"
#include "Billable.h"
#include "constants.h"

namespace seneca { // seneca

   class Ordering { // Ordering class here
      Food* foods{}; // foods
      Drink* drinks{}; // drinks
      Billable* billItems[MaximumNumberOfBillItems]{}; // billItems here
      size_t foodCount{}; // food count
      size_t drinkCount{}; // drink
      size_t billItemCount{};
      size_t billNumber{1};
      // Private member functions here
      void printBillTitle(std::ostream& os) const;
      void printTotals(std::ostream& os, double total) const;
      size_t countRecords(const char* file) const;

   public:
   // public func
      Ordering(const char* drinkFile, const char* foodFile); // construcotr here
      ~Ordering();// destructor
      // boolean operator overload here _>
      operator bool() const;// book
      size_t noOfBillItems() const; // Returns number of bill items
      bool hasUnsavedBill() const; // shcekc if there is any unsaved bill

      // List all food items and Drink items
      void listFoods() const; // food
      void listDrinks() const; // drink


      // Order foods and drinks
      void orderFood(); // food
      void orderDrink(); // drink
      void printBill(std::ostream& os) const; // os stream print bill func
      void resetBill(); // reset bill is done here
      // all functions are done for
   };

}

#endif // !SENECA_ORDERING_H
