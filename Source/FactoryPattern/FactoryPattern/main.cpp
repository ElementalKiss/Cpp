#include "common.h"
#include "PizzaStore.h"
#include "Pizza.h"

int main(int argc, const char* argv[])
{
	PizzaStore PopuraPizzaStore;

	shared_ptr<Pizza>newChesePizza(PopuraPizzaStore.orderPizza("cheese"));
	shared_ptr<Pizza>newPepperoniPizza(PopuraPizzaStore.orderPizza("pepperoni"));
	shared_ptr<Pizza>newClamPizza(PopuraPizzaStore.orderPizza("clam"));
	shared_ptr<Pizza>newVeggiePizza(PopuraPizzaStore.orderPizza("veggie"));
	shared_ptr<Pizza>newKokoPizza(PopuraPizzaStore.orderPizza("koko?"));

	return 0;
}