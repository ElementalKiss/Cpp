#include <iostream>
#include <map>

using namespace std;

class Widget
{
public:
	Widget() : m_weight(0) { };
	Widget(double weight) : m_weight(weight) { };
	Widget& operator=(double weight) { 
		this->m_weight = weight; 
		return *this; 
	};

private:
	double m_weight;
};

template<typename MapType, typename KeyArgType, typename ValueArgType>

typename MapType::iterator 
	efficientAddOrUpdate(MapType& m, const KeyArgType& k, const ValueArgType& v)
{
	typename MapType::iterator lb = m.lower_bound(k);

	if (lb != m.end() && !(m.key_comp()(k,lb->first))) {
		lb->second = v;
		return lb;
	}
	else {
		typedef typename MapType::value_type MVT;
		return m.insert(lb, MVT(k,v));
	}
}

int main(int argc, const char* argv[])
{
	map<int, Widget> mW;

	mW[1] = 1.5;
	
	// goto insert
	efficientAddOrUpdate(mW, 2, 1.6);
	// goto []
	efficientAddOrUpdate(mW, 1, 1.2);

	return 0;
}