#include "stdafx.h"
#include "TemplateStyle.h"
/*
Template ile fonksiyon g�vdelerini farkl� veri tipleri i�in kullanabiliriz.
*/


template<class T>
T Add(T var1, T var2) {
	return var1 + var2;
}

template <typename T>
T Max(T var1, T var2) {
	return var1 < var2 ? var2 : var1;
}

// --- generate fibonacci ---
template <typename T>
std::vector<T> fibUret(T max) {
	// Belki de gelmi� ge�mi� en k�t� ��z�m ama yazmas� h�zl� ve anla��l�r :)
	std::function<T(T)> fibonacci;
	fibonacci = [&fibonacci](T n) {
		return n < 2 ? n : fibonacci(n - 1) + fibonacci(n - 2);
	};

	std::vector<T> fibVec;
	T i = 0;
	while (i<max) {
		fibVec.push_back(fibonacci(i));
		++i;
	}
	return fibVec;

}