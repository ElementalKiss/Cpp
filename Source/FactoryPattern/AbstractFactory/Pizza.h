#pragma once
#include "common.h"

class Pizza
{
public:
	Pizza(void);
	~Pizza(void);

	// method
	void prepare() { cout<< "Pizza:prepare" << endl; }
	void bake() { cout<< "Pizza:bake" << endl; }
	void cut() { cout<< "Pizza:cut" << endl; }
	void box() { cout<< "Pizza:box" << endl; }	
};

// empty class
class CheesePizza : public Pizza { };
class PepperoniPizza : public Pizza { };
class ClamPizza : public Pizza { };
class VeggiePizza : public Pizza { };
