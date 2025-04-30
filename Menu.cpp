#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>

#include "Menu.h" //this includes the header file "Menu.h"
#include  "Utils.h" // this includes the header file "Utils.h"
#include "constants.h"//this includes the header file "constants.h"

using namespace std;//using standard namespace 

//this line defines namespace seneca
namespace seneca {

	//starting the namespace block 

	//this is a helper function to initialize the on=bject in a safe empty state 
	void MenuItem::setSafeEmpty()
	{
		menuContent = nullptr; //this ensures that there are no any dangling pointers 
		menuIndentCount = 0;
		menuIndentCharSize = 0;
		menuObjectCount = -1; // here, -1 signifies an invalid menu item 
	}

	// this is a constructor 
	// this initializes  MenuItem with teh given content, indentation and row number 
	MenuItem::MenuItem(const char* content, unsigned indentCount, unsigned indentSize, int objectCount)
	{
		//starting if...else loop 
		// this ensures input values are within allowed ranges 
		if (content == nullptr || *content == '\0' ||
			indentCount > 4 || indentSize > 4 ||
			(objectCount > (int)MaximumNumberOfMenuItems && objectCount != -1))
		{
			setSafeEmpty(); //this sets object to a safe empty state if invalid input is given
		}
		else
		{
			//this skips leading empty spaces 
			const char* ptr = content;
			while (*ptr != '\0' && isspace(*ptr))
			{
				++ptr;
			}

			//if content is just spaces , it automatically sets it to empty
			if (*ptr == '\0')
			{
				setSafeEmpty();
			}
			else
			{
				//this copies content into a new memory location 
				ut.alocpy(menuContent, content);
				menuIndentCount = indentCount;
				menuIndentCharSize = indentSize;
				menuObjectCount = objectCount;
			}
		}
	}

	// Destructor 
	// this frees the dynamically allocated memory used by menuContent 
	MenuItem::~MenuItem()
	{
		delete[] menuContent;
	}

	//this checks if the menu item is valid .i.e. if it has content or not
	MenuItem::operator bool() const
	{
		return menuContent != nullptr;
	}

	//this displays the menu item with proper indentation 
	std::ostream& MenuItem::display(std::ostream& ostr) const
	{
		//starting an if condition 
		if (!*this) // if it is invalid , it returns without output
		{
			return ostr;
		}

		//Adding indentation spaces 
		for (unsigned i = 0; i < menuIndentCount * menuIndentCharSize; i++)
		{
			ostr << ' ';
		}
		
		//starting an if condition 
		//this displays menu number if applicable 
		if (menuObjectCount >= 0)
		{
			//gives extra space for alignment 
			if (menuObjectCount < 10) ostr << ' ';
			ostr << menuObjectCount << "- ";
		}

		//This prints the menu content (this ignores the leading spaces)
		const char* ptr = menuContent;
		while (std::isspace(*ptr)) ++ptr;
		ostr << ptr;

		return ostr;
	}

	//this is a constructor 
	//this creates a menu with title, exit option, and indentation 
	Menu::Menu(const char* title, const char* exitOption, unsigned indent, unsigned indentSize) :
		menuIndent(indent), menuIndentSize(indentSize),
		menuItemCount(0), 
		menuTitle(title, indent, indentSize, -1), // Menu title (this is non selectable)
		menuExitOption(exitOption, indent, indentSize, 0),//this is an exit option (this one is always last)
		menuEntryPrompt("> ", indent, indentSize, -1) //this line gives a user input prompt 
	{
		//this sets all the menu items to nullptr 
		for (unsigned i = 0; i < MaximumNumberOfMenuItems; i++)
		{
			menuItems[i] = nullptr;
		}
	}

	Menu& Menu::operator<<(const char* content)
		//this is an <<operator overload for menu that adds a new item to the menu using the << operator 
	{
		//starting of an if condition
		if (menuItemCount < MaximumNumberOfMenuItems)
			//this  adds items only if there's some space left 
		{
			menuItems[menuItemCount] = new MenuItem(content, menuIndent, menuIndentSize, menuItemCount + 1);
			++menuItemCount;//this increases count by 1
		}

		return *this;
	}


	//this is a destructor 
	//this deletes all the dynamically allocated menu items 
	Menu::~Menu()
	{
		for (unsigned i = 0; i < menuItemCount; i++)
		{
			delete menuItems[i];
			menuItems[i] = nullptr;
		}
	}

	//this displays the menu and lets the user select an option 
	size_t Menu::select() const
	{
		
		if (menuTitle)
		{
			menuTitle.display(cout);
			cout << endl;
		}

		//this shows all the menu items 
		for (unsigned i = 0; i < menuItemCount; i++)
		{
			if (menuItems[i])
			{
				menuItems[i]->display(cout);
				cout << endl;
			}
		}


		//this shows exit option 
		menuExitOption.display(cout);
		cout << endl;

		//this shows prompt for input 
		menuEntryPrompt.display(std::cout);

		
		//this gets user input and returns it 
		int selection = ut.getInt(0, menuItemCount);
		return selection;
	}


	 //this ooutputs the menu to an ostream (screen or file)
	size_t operator<<(std::ostream& ostr, const Menu& m)
	{

		//starting of an if lese condition
		if (&ostr == &cout)
			//if printing to the console, it shows menu and gets user input 
		{
			return m.select();
		}
		else
			//otherwise , print menu text(for file input)

		{
			//this prints title if it is valid 
			if (m.menuTitle)
			{
				m.menuTitle.display(ostr);
				ostr << endl;
			}


			//this prints all menu items 
			for (unsigned i = 0; i < m.menuItemCount; i++)
			{
				if (m.menuItems[i])
				{
					m.menuItems[i]->display(ostr);
					ostr << endl;
				}
			}

			if (m.menuExitOption) //this prints the exit option 
			{
				m.menuExitOption.display(ostr);
				ostr << endl;
			}

			return 0;
			//there is no any selection needed for file output 
		}
	}
}
