#pragma once
#include "common.h"
#include "SimplePizzaFactory.h"

class PizzaStore
{
public:
	PizzaStore(void);
	~PizzaStore(void);
	
	PizzaStore(const SimplePizzaFactory fac);

	Pizza* orderPizza(const string pizzaType);

private:
	SimplePizzaFactory factory;	
};

