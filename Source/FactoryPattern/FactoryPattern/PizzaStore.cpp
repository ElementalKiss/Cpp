#include "PizzaStore.h"


PizzaStore::PizzaStore(void)
{
	cout<<"PizzaStore::PizzaStore(void)"<<endl;
}

PizzaStore::~PizzaStore(void)
{
	cout<<"PizzaStore::~PizzaStore(void)"<<endl;
}

PizzaStore::PizzaStore(const SimplePizzaFactory fac)
{
	this->factory = fac;
}

Pizza* PizzaStore::orderPizza(const string pizzaType)
{
	cout<< "Order Pizza!!!!!" << endl;
	Pizza* pizza = factory.createPizza(pizzaType);

	if (pizza)
	{
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
	}

	return pizza;
}