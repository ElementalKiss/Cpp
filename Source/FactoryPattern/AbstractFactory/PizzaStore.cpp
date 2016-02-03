#include "PizzaStore.h"


PizzaStore::PizzaStore(void)
{
	cout<<"PizzaStore::PizzaStore(void)"<<endl;
}

PizzaStore::~PizzaStore(void)
{
	cout<<"PizzaStore::~PizzaStore(void)"<<endl;
}

Pizza* PizzaStore::orderPizza(const string pizzaType)
{
	cout<< "Order Pizza!!!!!" << endl;
	Pizza* pizza = createPizza(pizzaType);

	if (pizza)
	{
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();
	}

	return pizza;
}

NYPizzaStore::NYPizzaStore(void)
{
	cout<<"NYPizzaStore::NYPizzaStore(void)"<<endl;
}

NYPizzaStore::~NYPizzaStore(void)
{
	cout<<"NYPizzaStore::~NYPizzaStore(void)"<<endl;
}

Pizza* NYPizzaStore::createPizza(const string pizzaType)
{
	Pizza* pizza = nullptr;

	if (pizzaType.compare("cheese") == 0) 
	{
		pizza = new CheesePizza();
		cout<< "NYStyle SimplePizzaFactory:create new CheesePizza." << endl;
	}
	else if (pizzaType.compare("pepperoni") == 0)
	{
		pizza = new PepperoniPizza();
		cout<< "NYStyle SimplePizzaFactory:create new PepperoniPizza." << endl;
	}
	else if (pizzaType.compare("clam") == 0)
	{
		pizza = new ClamPizza();
		cout<< "NYStyle SimplePizzaFactory:create new ClamPizza." << endl;
	}
	else if (pizzaType.compare("veggie") == 0)
	{
		pizza = new VeggiePizza();
		cout<< "NYStyle SimplePizzaFactory:create new VeggiePizza." << endl;
	}
	else
	{
		cout<< "NYStyle SimplePizzaFactory:no name." << endl;
		pizza = nullptr;
	}

	return pizza;
}

ChicagoPizzaStore::ChicagoPizzaStore(void)
{
	cout<<"ChicagoPizzaStore::ChicagoPizzaStore(void)"<<endl;
}

ChicagoPizzaStore::~ChicagoPizzaStore(void)
{
	cout<<"ChicagoPizzaStore::~ChicagoPizzaStore(void)"<<endl;
}

Pizza* ChicagoPizzaStore::createPizza(const string pizzaType)
{
	Pizza* pizza = nullptr;

	if (pizzaType.compare("cheese") == 0) 
	{
		pizza = new CheesePizza();
		cout<< "ChicagoStyle SimplePizzaFactory:create new CheesePizza." << endl;
	}
	else if (pizzaType.compare("pepperoni") == 0)
	{
		pizza = new PepperoniPizza();
		cout<< "ChicagoStyle SimplePizzaFactory:create new PepperoniPizza." << endl;
	}
	else if (pizzaType.compare("clam") == 0)
	{
		pizza = new ClamPizza();
		cout<< "ChicagoStyle SimplePizzaFactory:create new ClamPizza." << endl;
	}
	else if (pizzaType.compare("veggie") == 0)
	{
		pizza = new VeggiePizza();
		cout<< "ChicagoStyle SimplePizzaFactory:create new VeggiePizza." << endl;
	}
	else
	{
		cout<< "ChicagoStyle SimplePizzaFactory:no name." << endl;
		pizza = nullptr;
	}

	return pizza;
}