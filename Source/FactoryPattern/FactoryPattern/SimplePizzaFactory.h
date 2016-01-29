#pragma once
#include "common.h"
#include "Pizza.h"

class SimplePizzaFactory
{
public:
	SimplePizzaFactory(void);
	~SimplePizzaFactory(void);
	
	Pizza* createPizza(const string pizzaType);
};

