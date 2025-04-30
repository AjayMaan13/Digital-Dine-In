#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>

#include "constants.h" //this includes the header file "constants.h"

//this line defines namespace seneca
namespace seneca {

	//this declares the Menu class
	class Menu;

	class MenuItem {
		//this allows the Menu class and operator to access the private members 
		friend class Menu;
		friend size_t operator<<(std::ostream& ostr, const Menu& m);

		// this makes sure that all the members below this line are accessible only within the menu class and not outside of this class
	private:

		//this stores the menu items in text 
		char* menuContent; 

		//this stores number of identation levels 
		unsigned int menuIndentCount;

		//this stores size of each indentation space 
		unsigned int menuIndentCharSize;

		//this stores the number assigned to menu items 
		int menuObjectCount;

		
		void setSafeEmpty();
		//this sets object to a safe empty state 
		

		//this is a constructor 
		MenuItem(const char* content, unsigned indentCount, unsigned indentSize, int objectCount);
		// this initializes the menu item with text and formatting 
		
		
		// this is destructor 
		~MenuItem();
		//this cleans the dynamically allocated memory 

		//this deletes copy constructor  and copy assignment to prevent copying 
		MenuItem(const MenuItem& other) = delete;
		MenuItem& operator=(const MenuItem& other) = delete;

	   // this checks if the menu item contains valid text 
		operator bool() const;

	// this displays the menu item 
		std::ostream& display(std::ostream& ostr = std::cout) const;
	};

	class Menu {


	// this makes sure that all the members below this line are accessible only within the menu class and not outside of this class
	private:

		unsigned menuIndent; //number of indentations 

		unsigned menuIndentSize; // size of each indentation 

		unsigned menuItemCount; // total number of menu items 

		//this stores the menu title 
		MenuItem menuTitle;

		//this stores the exit option text 
		MenuItem menuExitOption;

		//this stores the menu prompt text 
		MenuItem menuEntryPrompt;


		//this is an array of menu items
		MenuItem* menuItems[MaximumNumberOfMenuItems];

		//this makes sure that all the members below this line are accessible outside the class
	public:

		// this is a constructor
		// this creates a menu with a title , exit option and indentation settings 
		Menu(const char* title, const char* exitOption = "Exit", unsigned indent = 0, unsigned indentSize = 3);


		Menu& operator<<(const char* content); //this adds a new item to the menu 

		//this is rule of five 

		//this is a destructor 
		~Menu();
		// this cleans up the dynamically allocated memory
	

		//this disables the copy and move operators 
		Menu(const Menu&) = delete;

		Menu& operator=(const Menu&) = delete;

		Menu(Menu&&) = delete;

		Menu& operator=(Menu&&) = delete;

		//this displays the menu and lets the user select an option from the menu 
		size_t select() const;

		friend size_t operator<<(std::ostream& ostr, const Menu& m);
		//here overloaded insertion operator is used for displaying the menu 
	};
}
#endif // !SENECA_MENU_H