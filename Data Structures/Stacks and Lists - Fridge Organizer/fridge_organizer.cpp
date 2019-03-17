#include <iostream>
#include <list> 
#include <stack>
#include "fridge_organizer.hpp"
using namespace std;

// parametric constructor for FridgeOrganizer
FridgeOrganizer::FridgeOrganizer(unsigned int n_stack_number, unsigned int n_stack_capacity) {
	if (n_stack_number >= 2) 		
		stack_number = n_stack_number;		
	else 
		stack_number = 2;
	usable_stacks = stack_number - 1;
	stack_capacity = n_stack_capacity;
}

// destructor for FridgeOrganizer
FridgeOrganizer::~FridgeOrganizer() {
	for (list<stack<MealPortion*>*>::iterator i = stacks.begin(); i != stacks.end(); ++i) {
		stack<MealPortion*>* cur_stack = *i; int cur_stack_size = cur_stack->size();
		for (int index = 0; index < cur_stack_size; ++index) {
			delete cur_stack->top();
			cur_stack->pop();
		}
		delete *i;
	}		
}

// display all meal stacks in the fridge
void FridgeOrganizer::print_stacks() {
	cout << endl << "-= START OF CURRENT FRIDGE ORGANIZER STATE =-" << endl;
	// use iterator to iterate through list elements
	int cur_stack_index = 0;
	for (list<stack<MealPortion*>*>::iterator i = stacks.begin(); i != stacks.end(); ++i, ++cur_stack_index) {
		cout << "STACK " << cur_stack_index << endl;
		// iterate through stack elements
		stack<MealPortion*> cur_stack = **i; int cur_stack_size = cur_stack.size();
		for (int cur_element_index = 0; cur_element_index < cur_stack_size; ++cur_element_index) {
			cout << "| ELEMENT " << cur_element_index << ": " << cur_stack.top()->name << ", " << cur_stack.top()->expiry << " |" << endl;
			cur_stack.pop();
		}
	}
	cout << "-= END OF CURRENT FRIDGE ORGANIZER STATE =-" << endl << endl;
}	

int FridgeOrganizer::number_of_portions() {
	//initialize portion count to 0
	int portionCount = 0;
	//use list iterator to iterate through list elements; see print function
	for (list<stack<MealPortion*>*>::iterator i = stacks.begin(); i != stacks.end(); i++)
	{
		//add current stack size to portion count
		stack<MealPortion*> curStack = **i;
		for (int curIndex = 0; curIndex < curStack.size(); curIndex++)
		{
			portionCount++;
		}
	}
	//return final portion count
	return portionCount;
}	

bool FridgeOrganizer::add_meal_portion(string n_name, string n_expiry) {
	//create a new meal portion object on the heap
	MealPortion* addMeal = new MealPortion(n_name, n_expiry);
	//grab a pointer to the last stack from the back
	stack<MealPortion*>* temp = stacks.back();
	//if the stacks list is not empty and there is space in the current stack
	if (!stacks.empty() && temp->size() < stack_capacity - 1) //Leave one free space
	{
		//insert the new meal into the current stack
		temp->push(addMeal);
	}
	// else if there is space for a new stack
	else if (stacks.size() < stack_number)
	{
		//create a new stack with new stack<MealPortion*>
		stack<MealPortion*>* newStack = new stack<MealPortion*>;
		//add the meal portion to that stack
		newStack->push(addMeal);
		//add the new stack to the stacks list
		stacks.push_back(newStack);
		
	}
	//else there is no more space for new stacks
	else
	{
		//return false
		return false;
	}
	//return true if addition was successful
	return true;
}	

FridgeOrganizer::MealPortion FridgeOrganizer::remove_meal_portion() {
	//create a temporary MealPortion("EMPTY", "N/A") object called m
	MealPortion m = MealPortion("EMPTY", "N/A");
	//if the stacks list is empty
	if (stacks.empty())
	{
		//return corresponding m value
		return m;
	}
	//grab a pointer to the stack at the back of the list
	stack<MealPortion*>* temp = stacks.back();
	//set m's value to match the value of top element of that stack
	m = *(temp->top());
	//free memory for the top element and pop it from the stack
	delete temp->top();
	temp->pop();
	//if the current stack is empty
	if (temp->empty())
	{
		//free its memory and remove it from the list
		delete stacks.back();
		stacks.pop_back();
	}

	//return corresponding m value
	return m;
}

FridgeOrganizer::MealPortion FridgeOrganizer::find_meal_portion_by_expiry() {
	//create a temporary MealPortion("EMPTY", "N/A") object called min
	MealPortion min = MealPortion("EMPTY", "N/A");
	//if the stacks list is empty
	if (stacks.empty())
	{
		//return min value
		return min;
	}
	//use list iterator to go through list elements; see print function
	for (list<stack<MealPortion*>*>::iterator i = stacks.begin(); i != stacks.end(); i++)
	{
		//create a local copy of the current stack; also, store its size as a variable
		stack<MealPortion*> temp = **i;
		int stackSize = temp.size();
		//iterate through the copy of the current stack using index value
		for (int curElement = 0; curElement < stackSize; curElement++)
		{
			//grab a pointer to the top of the stack
			MealPortion* mealTemp = temp.top();
			//if the stack top's expiry date is less than min->expiry
			if (mealTemp->expiry < min.expiry)
			{
				//copy the stack top's value into min
				min = *mealTemp;
			}
			//pop the top element from the stack; do not free its memory
			temp.pop();
		}	stackSize--;
		
	}
	//return corresponding min value
	return min;	
}


// test FridgeOrganizer constructor and basic item insertion
bool FridgeOrganizerTest::test1() {
	FridgeOrganizer fridge1(1,2);
	fridge1.add_meal_portion("Portion1", "18-07-01");
	fridge1.add_meal_portion("Portion2", "18-07-03");
	ASSERT_TRUE(fridge1.number_of_portions() == 2);	
	fridge1.add_meal_portion("Portion3", "18-08-03");
	fridge1.add_meal_portion("Portion4", "18-08-05");
	ASSERT_TRUE(fridge1.number_of_portions() == 2);				
}

// test stack growth and shrinking with LIFO removal
bool FridgeOrganizerTest::test2() {
	FridgeOrganizer fridge(6,4);
	fridge.add_meal_portion("Portion1", "18-07-01");
	fridge.add_meal_portion("Portion2", "18-07-03");
	fridge.add_meal_portion("Portion3", "18-08-03");
	fridge.add_meal_portion("Portion4", "18-08-05");
	fridge.add_meal_portion("Portion5", "18-08-15");
	fridge.add_meal_portion("Portion6", "18-08-25");
	ASSERT_TRUE(fridge.number_of_portions() == 6);		
	ASSERT_TRUE(fridge.remove_meal_portion().expiry == "18-08-25");
	ASSERT_TRUE(fridge.remove_meal_portion().expiry == "18-08-15");
	ASSERT_TRUE(fridge.remove_meal_portion().name == "Portion4");
	ASSERT_TRUE(fridge.remove_meal_portion().name == "Portion3");
	ASSERT_TRUE(fridge.number_of_portions() == 2);	
	fridge.remove_meal_portion();
	fridge.remove_meal_portion();
	fridge.remove_meal_portion();
	fridge.remove_meal_portion();
	ASSERT_TRUE(fridge.number_of_portions() == 0);		
}

// test find meal portion by earliest expiry date
bool FridgeOrganizerTest::test3() {
	FridgeOrganizer fridge(7,4);
	fridge.add_meal_portion("Portion1", "18-07-01");
	fridge.add_meal_portion("Portion2", "18-07-03");
	fridge.add_meal_portion("Portion3", "18-06-03");
	fridge.add_meal_portion("Portion4", "18-08-05");
	fridge.add_meal_portion("Portion5", "18-08-15");
	fridge.add_meal_portion("Portion6", "18-05-25");
	//fridge.print_stacks();
	ASSERT_TRUE(fridge.find_meal_portion_by_expiry().expiry == "18-05-25")
	fridge.remove_meal_portion();
	ASSERT_TRUE(fridge.find_meal_portion_by_expiry().expiry == "18-06-03")
	fridge.remove_meal_portion();
	fridge.remove_meal_portion();
	fridge.remove_meal_portion();
	//fridge.find_meal_portion_by_expiry().print();
	ASSERT_TRUE(fridge.find_meal_portion_by_expiry().expiry == "18-07-01")
}

void FridgeOrganizerTest::runTests() {
	cout << endl << "-= TEST 1: Test FridgeOrganizer constructor and basic item insertion";
	cout << (test1() ? " PASSED =-" : " FAILED =-") << endl;
	cout << endl << "-= TEST 2: Test stack growth and shrinking with LIFO removal";
	cout << (test2() ? " PASSED =-" : " FAILED =-") << endl;
	cout << endl << "-= TEST 3: Test find meal portion by earliest expiry date";
	cout << (test3() ? " PASSED =-" : " FAILED =-") << endl;
}

int main() {
	FridgeOrganizerTest fridge_test;
	fridge_test.runTests();	
	getchar();
	return 0;
}

