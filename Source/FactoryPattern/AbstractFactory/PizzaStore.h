#pragma once
#include "common.h"
#include "Pizza.h"

// base class
class PizzaStore
{
public:
	PizzaStore(void);
	virtual ~PizzaStore(void);
	
	Pizza* orderPizza(const string pizzaType);

	// virtual
	virtual Pizza* createPizza(const string pizzaType) = 0;

private:
};

// derived class
class NYPizzaStore : public PizzaStore
{
public:
	NYPizzaStore();
	~NYPizzaStore();

	virtual Pizza* createPizza(const string pizzaType) override;
private:
};

class ChicagoPizzaStore : public PizzaStore
{
public:
	ChicagoPizzaStore();
	~ChicagoPizzaStore();

	virtual Pizza* createPizza(const string pizzaType) override;
private:
};