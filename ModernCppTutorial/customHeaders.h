#ifndef customHeaders_H // eski ve ta��nabilir usul header korumas�. Derleyici header dosyas�n� defalarca 
#define customHeaders_H // dahil etmesini �nler. B�y�k projelerde �nemli sorun te�kil ediyor.

#ifdef _MSC_VER
#pragma once
#endif
#include <fmt/printf.h>
/*
The two int variables are defined in the header file. This means that every source file which includes the header will contain their definition (header inclusion is purely textual). The of course leads to multiple definition errors.
You have several options to fix this.
Make the variables static (static int WIDTH = 1024;). They will still exist in each source file, but their definitions will not be visible outside of the source file.
Turn their definitions into declarations by using extern (extern int WIDTH;) and put the definition into one source file: int WIDTH = 1024;.
Probably the best option: make the variables const (const int WIDTH = 1024;). This makes them static implicitly, and also allows them to be used as compile-time constants, allowing the compiler to use their value directly instead of issuing code to read it from the variable etc.
*/

// Sak�n define ile say� ile niteleme yapmay�n
// #define 2 ' //yanl�����
#define ekranayaz std::cout //eski ama hala i�e yar�yor.
#define yenisat�r std::endl // "\n" ayn� i�i g�rse de her sistemde farkl� olabilir. program� evrenselle�tirmek �zere kullan�yorum.
#define yenisat�ryaz ekranayaz << yenisat�r
#define fonksiyonuyaz(fonk) std::cout << "---"<< fonk <<" fonksiyonu ---" << std::endl
#define boolyaz(ifade) std::boolalpha << ifade << std::noboolalpha
#define strend std::string::npos

// bool found = (std::find(my_list.begin(), my_list.end(), my_var) != my_list.end()); // python "in" kar��l���
// stl veri yap�lar�yla �al���l�r.
#define varm�(data,aranan) (std::find(data.begin(), data.end(), aranan) != data.end())
#define ThreadSleep(sec) std::this_thread::sleep_for(std::chrono::seconds(sec));

// Yararl� fonksiyonlar.
template<typename T>
inline auto printAll (T data) -> void { // d�n�� tipi "void" olarak belirledim. art�k derleme hatas� yok.
	for (auto& d : data)
		std::cout << d << " ";
	yenisat�ryaz;
};

template<typename T>
void JoinAll(T threadVect) {
	for (auto& t : threadVect)
		if (t.joinable()) // yeni versiyonda bu fonksiyon kullan�lmaz ise _INVALID_ARGUMENT exception yolluyor.
			t.join();
}

// begin ve end stl i�inde tan�ml� �zel adlard�r. B�yle �zel adlar� kullanmak
// derleme hatas�na sebep olur.
#define basla {
#define bitir }
#define bitti ;
#define inn :

// mant�ksal operatorler
#define and &&
#define or ||
#define not !

// art�r <-> azalt
#define increase ++
#define decrease --

// d�ng� ifadeleri
#define looper while(true)
#define foreverer loop

// typedef olacak tipler
#define ia inline auto //typedef aksine # define sat�r d��� nitelemeye izin verir.
#define isa inline static auto
#define iea inline extern auto

// typedef olacak constexpr tipler
#define ceia constexpr inline auto
#define ceisa constexpr inline static auto
#define ceiea constexpr inline extern auto

// rasyonel say� tipleri
#define float32 float 
#define float32_t float
#define lfloat32 long float
#define lfloat32_t long float
#define lfloat long float
#define lfloat_t long float

#define float64 double 
#define float64_t double
#define lfloat64 long float
#define lfloat64_t long float

using intVec = std::vector<int32_t>;


// i�te benim tan�mlad���m ba�l�k dosyalar�
// ba�l�k dosyalar�na istedi�inizi yazabilirsiniz. basit�e dahil edilecektir.
// main dosyas� sadele�ti.
#include "PointlerFonksiyonlar.h" // include i�lemi text baz�nda olduk�a basit bir i�lemdir. Bende konfig�rasyonu basit tuttum.
#include "functionalStyle.h"
using functionalStyle::MultBy2;
using functionalStyle::DoMath;
using functionalStyle::MultBy3;
using functionalStyle::IsItOdd;
using functionalStyle::ChangeList;
using functionalStyle::GetHAndTList;
using functionalStyle::GetNumberOfMatches;
#include "pipeStyle.h"
#include "initialize_twister.h"
#include "generateRandom.h"

// classlar
#include "Animal.h"
#include "Dog.h"
#include "kutucuk.h"
#include "polyTemplateClass.h"
// #include "threadBasic.h"

// Templates
#include "TemplateStyle.h"

// di�er derslerin kodlar�
#include "Associative.h"
#include "regexTan�m�.h"

#include "dersler.h"


#endif  // HEADER_FILE