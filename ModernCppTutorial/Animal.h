#include "stdafx.h"
// static �yeler linker hatalar�ndan sak�nmak i�in cpp dosyalar�nda tan�mlan�r. "pragma one" gibi komutlar da hatay� engellemez.
// en iyisi class,struct, vb. yap�lar�n kal�b�n� header dosyas�na, g�vdelerini .cpp dosyalar�na yazmakt�r.
// https://stackoverflow.com/questions/8479480/link-error-when-declaring-public-static-variables-in-c
#ifndef ANIMAL_H // eski ve ta��nabilir usul header korumas�. Derleyici header dosyas�n� defalarca 
#define ANIMAL_H // dahil etmesini �nler. B�y�k projelerde �nemli sorun te�kil ediyor.

#ifdef _MSC_VER
#pragma once // visual c++ �zel header korumas�
#endif  // _MSC_VER
class Animal
{
protected: // d��ar�dan g�r�lemez. public aktar�mda public kal�r.
private: // d��ar�dan g�r�lemez. public aktar�mda private kal�r. Class varsay�lan olarak "privatedir."
	std::string name;
	double height;
	double weight;
	static int numOfAnimals; // her yeni nesne olu�umunda ba�a sarmaz. b�ylece ka� tane nesne olu�tu�unu sayabiliriz.
public: // nesne olu�turulduktan sonra nesne ile d��ar�dan g�r�lebilir. public aktar�mda public kal�r.
		// modern c++ baz� durumlarda otomatik yap�c� ve y�k�c� fonksiyonlar� tan�mlayabilir ama �ok s�n�rl�d�r.
	Animal() { SetAll("bilinmeyen", 0, 0); ekranayaz << "Animal() created: " << this->name << yenisat�r; } // Class olu�turucu. class haf�zada nas�l yer ay�r�r, nas�l tan�mlan�r gibi bilgileri ifade eder.
	Animal(std::string sname, double sheight, double sweight)
	{
		SetAll(sname, sheight, sweight); ekranayaz << "Animal(std::string, double, double) created: " << 
			this->name << yenisat�r;
	} // Olu�turucu ve y�k�c� a��r� y�klenebilir. Burada varsay�lan olu�turucuyu derleyici olu�turacakt�r.
	~Animal() { ekranayaz << "~Animal() destroyed: " << this->name << yenisat�r; }// Class y�k�c�. class haf�zadan nas�l kald�r�l�r, nas�l referanslar ve ilgili veriler silinir gibi bilgileri ifade eder.
	// D��ar�dan g�r�lebilecek fonksiyon yaz�yorum. Fonksiyon g�vdesi class i�inde yaz�abilir.
	std::string GetName() { return name; } // private �yelere direk eri�im yasakt�r ama b�yle eri�im yasak de�ildir. C# al�nt�s�
	// this i�aret�isi class i�indeki de�i�kenleri ve fonksiyonlar� i�aret eder.
	void SetName(std::string sname) { this->name=sname; }
	double GetHeight() { return height; } // get fonksiyonlar� public oldu�undan this i�aret�isine ihtiyac� yok.
	void SetHeight(double sheight) { this->height = sheight; }
	double GetWeight() { return weight; }
	void SetWeight(double sweight) { this->weight = sweight; }
	// static �ye class d���nda tan�mlan�r.
	void SetAll(std::string sname, double sheight, double sweight) {
		this->name = sname; this->height = sheight; this->weight = sweight;
		++Animal::numOfAnimals;
	} // fonksiyon tan�t�c�s�. 
	static int GetNumOfAnimals() { return numOfAnimals; }
	std::stringstream ToString() {
		std::stringstream ss;
		ss << GetName() << " is " << GetHeight() << " cm uzunluk ve " << GetWeight() << " kg a��rl���nda ";
		return ss;
	} // st
	inline void PrintAll(bool newline = false) {
		auto ss = this->ToString();
		std::string str;
		while (std::getline(ss, str)) {
			std::cout << str;
		}
		if (newline) yenisat�ryaz;
	}
};
// int Animal::numOfAnimals = 0; // de�erin verilmesini .cpp i�inde yap�n.

#endif  // HEADER_FILE