#include "common.h"
#include "PizzaStore.h"
#include "Pizza.h"

int main(int argc, const char* argv[])
{
	const size_t STORE_COUNT = 2;
	shared_ptr<PizzaStore> somePizzaStore[STORE_COUNT];

	somePizzaStore[0] = shared_ptr<NYPizzaStore>(new NYPizzaStore());
	somePizzaStore[1] = shared_ptr<ChicagoPizzaStore>(new ChicagoPizzaStore());
	
	for (size_t i = 0 ; i < STORE_COUNT; i++ )
	{
		cout<<"================================================================="<<endl;
		shared_ptr<Pizza>newChesePizza(somePizzaStore[i]->orderPizza("cheese"));
		shared_ptr<Pizza>newPepperoniPizza(somePizzaStore[i]->orderPizza("pepperoni"));
		shared_ptr<Pizza>newClamPizza(somePizzaStore[i]->orderPizza("clam"));
		shared_ptr<Pizza>newVeggiePizza(somePizzaStore[i]->orderPizza("veggie"));
		shared_ptr<Pizza>newKokoPizza(somePizzaStore[i]->orderPizza("koko?"));
	}

	return 0;
}