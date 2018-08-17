#include "stdafx.h"
#include "customHeaders.h"
#include "stdheaders.h"
#ifndef Associative_H // eski ve ta��nabilir usul header korumas�. Derleyici header dosyas�n� defalarca 
#define Associative_H // dahil etmesini �nler. B�y�k projelerde �nemli sorun te�kil ediyor.

#ifdef _MSC_VER
#pragma once
#endif
/*
Sequential veri tiplerinden fark� bu veriler s�ral� verilerdir. S�ral� olmas� aramay� kolayla�t�r�yor
ama veri ilave etmeyi zorla�t�r�yor ��nk� tekrar ve tekrar s�ralanmas� gerekiyor.
veri yap�lar�n�n �e�itli durumlardaki performanslar�ni internette kar��la�t�r�lm��t�. l�tfen bak�n�z.
l�tfen https://en.cppreference.com sayfas�ndan ayr�nt�lar�na bak�n. Bu yap�lar� anlatmaya kalkarsam �ok zaman
ge�iririz.
*/

static void setTan�m�() {
	/*
	set tipi matematikteki k�me sistemidir. elemanlar� otomatik s�ralar. ayn� eleman�n ikincisini tutmaz.
	*/
	std::set<int> set1{ 5,4,3,2,1,1 };
	std::cout << "Size : " << set1.size() << std::endl;

	// de�er ekle
	set1.insert(0);
	std::cout << "Size insert(0) sonras� : " << set1.size() << std::endl;
	set1.insert(5); // ayn� eleman�n ikincisini eklemeye �al���yorum ama eklemez.
	std::cout << "Size insert(5) sonras� : " << set1.size() << std::endl; // boyut de�i�ti mi? hay�r.

	// std::cout << set1[0] << "\n"; // forward_list gibi �al��maz. iterat�r kullanabiliriz.

	// iterator kullanabiliriz.
	std::set<int>::iterator it = set1.begin();
	it++;

	std::cout << "2nd : " << *it << "\n";

	// 5 de�erini sil
	set1.erase(5);

	// son eleman� sil
	it = set1.end();
	std::advance(it, -2);
	set1.erase(it, set1.end());

	// birden fazla de�er kaydet.
	std::vector<int> arr{ 6,7,8,9 };
	set1.insert(arr.begin(), arr.end());

	// find konum yani iterat�r bilgisini yollar. Sonra iterat�r ile de�er �ekilebilir.
	auto val = set1.find(6);
	std::cout << "Found : " << *val << "\n";

	// haf�zadaki 8. konumu verir.
	auto eight = set1.lower_bound(8);
	std::cout << "8 : " << *eight << "\n";

	// haf�zadaki 8+1. konumu verir.
	auto nine = set1.upper_bound(8);
	std::cout << "9 : " << *nine << "\n";

	// set1 ve set2 de�i� toku� et.
	std::set<int> set2{ 10,11 };
	set1.swap(set2); // art�k { 10, 11 } oldu.

	// bo� mu? kontrol et.
	if (!set1.empty()) {
		printAll(set1);
	}

}

static void multisetTan�m�() {
	// ----- MULTISET -----
	// elemanlar� s�ralar, ayn� eleman�n ikincisini saklar ve di�er t�m �zellikleri set ile ayn�d�r.
	std::multiset<int> mset1{ 1,1,2,3,4 };

	// eleman ekle.
	mset1.insert(4);
	mset1.insert(0);

	if (!mset1.empty()) {
		printAll(mset1);
	}

}

static void mapTan�m�() {
	// ----- MAP -----
	// Key<->value ikilisi �eklinde saklama yapar. Ayn� elemandan ikincisini kutmaz. Elemandan kast�m anahtar.
	// python dictionary kar��l���d�r.
	/*
	pair map eleman�n�n liste olmayan halidir. Asl�nda basit bir struct yap�d�r. Kullan��l�d�r.
		tempate<class Anahtar, class Deger>
		struct pair{
			Anahtar anahtar;
			Deger deger;
		};
	map ise bir pair listesidir ama ayn� elemandan ikincisini tutmad���ndan pair setidir.
	*/
	std::map<int, std::string> map1;

	// anahtarlar� ekle. not: Simpsons... :)
	map1.insert(std::pair <int, std::string>(1, "Bart"));
	map1.insert(std::pair <int, std::string>(2, "Lisa"));
	map1.insert(std::pair <int, std::string>(3, "Marge"));
	map1.insert(std::pair <int, std::string>(4, "Homer"));
	map1.insert(std::pair <int, std::string>(5, "Kristy"));

	// index de�il anahtar�, de�eri yazd�r. anahtar first, de�er second oluyor.
	auto match = map1.find(1); // iterator yollar.
	std::cout << match->second << "\n";

	// 1. eleman
	auto bart = map1.lower_bound(1);
	std::cout << "LB : " << bart->second << "\n";

	// 1(+1). eleman
	auto lisa = map1.upper_bound(1);
	std::cout << "UB : " << lisa->second << "\n";

	// Print elements with an iterator
	std::map<int, std::string>::iterator it2;
	for (it2 = map1.begin(); it2 != map1.end(); ++it2) {
		std::cout << "Key : " << it2->first << "\n"; // anahtar
		std::cout << "Value : " << it2->second << "\n"; // de�er
	}
	std::cout << "\n";
}

static void multimapTan�m�() {
	// ----- MULTIMAP -----
	// Ayn� map gibi �al���r ama ayn� elemandan ikincisini saklar. Elemandan kast�m anahtar.
	std::multimap<int, std::string> mmap1;
	mmap1.insert(std::pair <int, std::string>(1, "Bart"));
	mmap1.insert(std::pair <int, std::string>(1, "Lisa")); // �enmli olan anahtar.
	mmap1.insert(std::pair <int, std::string>(2, "Lisa"));
	mmap1.insert(std::pair <int, std::string>(3, "Marge"));
	std::map<int, std::string>::iterator it3;
	for (it3 = mmap1.begin(); it3 != mmap1.end(); ++it3) {
		std::cout << "Key : " << it3->first << "\n";
		std::cout << "Value : " << it3->second << "\n";
	}
	std::cout << "\n";
}

// ----- CONTAINER ADAPTERS -----
// Zaten var olan veri t�rleri i�in davran�� aray�z� sunar. Kendileri de veri t�r� gibi kullan�labilir.
static void stackTan�m�() {
	// ----- STACK -----
	// LIFO(Last in First out) format�nda veri aray�z�d�r.
	std::stack<std::string> custs;
	custs.push("George");
	custs.push("Louise");
	custs.push("Florence");

	int size = custs.size(); // eleman say�s�

	// bo� mu? kontrol et.
	if (!custs.empty()) {
		for (int i = 0; i < size; ++i) {
			std::cout << "top: "<< custs.top() << "\n"; // son eleman� verir ama silmez.
			custs.pop(); // son eleman� ��kar.
		}
	}
	std::cout << "\n";
}

static void queueTan�m�() {
	// ----- QUEUE -----
	// FIFO(First in First out) format�nda veri aray�z�d�r.

	// futurama :)
	std::queue<std::string> cast;
	cast.push("Zoidberg");
	cast.push("Bender");
	cast.push("Leela");
	int size2 = cast.size(); // eleman say�s�

	// bo� mu? kontrol et.
	if (!cast.empty()) {
		for (int i = 0; i < size2; i++) {
			std::cout << cast.front() << "\n"; // ilk eleman� verir ama silmez.
			cast.pop(); // ilk eleman� ��kar.
		}
	}
	std::cout << "\n";
}

static void priorityQueue(){
	/* 
	B�y�kten k����e s�ralayan "queue" verisidir.
	s�ralama i�lemini eleman ekleme s�ras�nda de�il.
	her yeri istendi�inde yeni maximumumu bularak yapar.
	*/
	std::priority_queue<int> nums;
	nums.push(4);
	nums.push(8);
	nums.push(5);
	auto size3 = nums.size();

	if (!nums.empty()) {
		for (int i = 0; i < size3; i++) {
			std::cout << nums.top() << "\n"; // ilk eleman� verir ama silmez.
			nums.pop(); // ilk eleman� ��kar.
		}
	}
	std::cout << "\n";
}

// ----- ENUMS -----
// program�n okunurlu�unu artt�rmak �zere "integer" verilerini derleme s�ras�nda otomatik olu�turan yap�d�r.
static void enums() {
	
	enum color {red, green, blue}; // varsay�lan ba�lama noktas� "0" d�r. red=0, green=1, blue=2
	enum rediculus {r=2, e=0, d=-5, c, l, s, u=7, u1, u2};
	enum day { Mon = 1, Tues, Wed, Thur, Fri = 5 }; // istenilen noktadan ba�layabilir ve devam ettirilebilir.

	enum day tuesday = Tues; // 2

	std::cout << "Tuesday is the " << tuesday << "nd day of the week\n";

	// Cycle through days
	for (int i = Mon; i <= Fri; i++)
		std::cout << i << "\n";
	std::cout << "\n";
}

#endif  // HEADER_FILE