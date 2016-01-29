#include "SimplePizzaFactory.h"


SimplePizzaFactory::SimplePizzaFactory(void)
{
	cout<<"SimplePizzaFactory::SimplePizzaFactory(void)"<<endl;
}

SimplePizzaFactory::~SimplePizzaFactory(void)
{
	cout<<"SimplePizzaFactory::~SimplePizzaFactory(void)"<<endl;
}

Pizza* SimplePizzaFactory::createPizza(const string pizzaType)
{
	Pizza* pizza = nullptr;

	if (pizzaType.compare("cheese") == 0) 
	{
		pizza = new CheesePizza();
		cout<< "SimplePizzaFactory:create new CheesePizza." << endl;
	}
	else if (pizzaType.compare("pepperoni") == 0)
	{
		pizza = new PepperoniPizza();
		cout<< "SimplePizzaFactory:create new PepperoniPizza." << endl;
	}
	else if (pizzaType.compare("clam") == 0)
	{
		pizza = new ClamPizza();
		cout<< "SimplePizzaFactory:create new ClamPizza." << endl;
	}
	else if (pizzaType.compare("veggie") == 0)
	{
		pizza = new VeggiePizza();
		cout<< "SimplePizzaFactory:create new VeggiePizza." << endl;
	}
	else
	{
		cout<< "SimplePizzaFactory:no name." << endl;
		pizza = nullptr;
	}

	return pizza;
}