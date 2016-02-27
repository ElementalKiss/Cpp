#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <typeinfo>

namespace MH_UTIL
{
	namespace STL
	{
		void test();

		template <class T>
		void print_container_console(const T& container) 
		{
			cout << "==============================" << endl;
			cout << "[INFO] Container Size = " << container.size() << endl;
			cout << "[INFO] Container Type = " << typeid(T).name() << endl;

			long long count = 1;
			for (auto value : container) {
				cout << "Container[" << count++ << "] = " << value << endl;
			}
		}

		template <class T1, class T2>
		void print_container_console(const T1& container, const T2 msg) 
		{
			cout << "==============================" << endl;
			cout << "[INFO] Container Size = " << container.size() << endl;
			cout << "[INFO] Container Type = " << typeid(T1).name() << endl;
			cout << "[INFO] Msg = " << msg << endl;

			long long count = 1;
			for (auto value : container) {
				cout << "Container[" << count++ << "] = " << value << endl;
			}
		}
		
		template <class T1, class T2>
		void erase_element(T1& container, const T2 value) 
		{
			container.erase(std::remove(container.begin(), container.end(), value), container.end());
		}

		template <class T1, class... T2>
		void simple_init_push_back(T1& container, const T2... args)
		{
			T1 vec = { args... };
			container = std::move(vec);
		}
	};


	namespace SMART_PTR
	{
		// counter pointer
		template <class T>
		class CounterPtr
		{
		public:
			explicit CounterPtr(T* p = 0) 
				: m_ptr(p), m_count(new long(1)) 
			{ }

			CounterPtr(const CounterPtr<T>& p) : m_ptr(p.m_ptr), m_count(p.m_count) 
			{
				(*m_count)++;
			}

			~CounterPtr() { dispose(); }

			CounterPtr<T>& operator= (const CounterPtr<T>& p) 
			{
				if (this != &p) {
					dispose();
					m_ptr = p.m_ptr;
					m_count = p.m_count;
					(*m_count)++;
				}
				return *this;
			}

			T& operator*() const  { return *m_ptr; }
			T* operator->() const  { return m_ptr; }

		private:
			void dispose() 
			{
				--(*m_count);
				if (*m_count == 0) {
					delete m_count;
					delete m_ptr;
				}
			}

		public:
			inline int getCount() { return *m_count; }

		private:
			T* m_ptr;
			long* m_count;
		};
	};
};