#ifndef TemplateStyle_H // eski ve ta��nabilir usul header korumas�. Derleyici header dosyas�n� defalarca 
#define TemplateStyle_H // dahil etmesini �nler. B�y�k projelerde �nemli sorun te�kil ediyor.

#ifdef _MSC_VER
#pragma once
#endif

#include "stdafx.h"

#ifdef USE_EXPORT_KEYWORD // derleyici destekliyor mu? sorgusu soruluyor. vc++2017 son versiyon desteklemiyor.
export
#endif
// template fonksiyonlar� header bildirimleri. genelde ayn� dosyadaysa sorun yok.
template<class T> extern T Add(T, T);
template<class T> extern T Max(T, T);
template <typename T> extern std::vector<T> fibUret(T max);



// Template Class tan�m�
template <typename T, typename U>
class Person {
public:
	T height;
	U weight;
	static int numOfPeople;
	Person(T h, U w) {
		height = h, weight = w;
		numOfPeople++;
	}
	void GetData() { std::cout << "Height : " << height << " and Weight : " << weight << "\n"; }
};
template<typename T, typename U> int Person<T, U>::numOfPeople;



#endif  // HEADER_FILE