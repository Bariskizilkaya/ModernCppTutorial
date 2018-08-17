#pragma once
#include "Animal.h"
class Dog : public Animal // Animal s�n�f�n�n t�m �zelliklerini ald�.
{
private:
	std::string sound{"hav"};
public:
	// Bu a�amada Animal class�n i�indeki istenen fonksiyonlar� a��r� y�klemek �zere kullan�l�r. Yoksa Linker hatalar� ile kar��la��l�r.
	// Asl�nda bu sorun c++ virtual fonksiyonlar� ile ��z�l�r.
	// virtual fonksiyonlar java ve C# interface durumunun dengidir.
	using Animal::SetAll;
	using Animal::ToString;
	Dog() { std::cout << "Dog() olu�tu: " << GetName() << std::endl; }
	// ": Animal(sname,sheight,sweight)" ile kopyalama olmadan class de�i�kenlerinin de�erleri atanabilir.
	Dog(std::string sname , double sheight, double sweight, std::string ssound) : Animal(sname, sheight, sweight)
	{
		std::cout << "Dog SetAll(std::string, double, double, std::string) olu�tu: " << 
			GetName() << std::endl; SetSound(ssound);
	} // Vc++ cpp dosyas�nda tan�mlamaya yard�mc� oluyor.
	~Dog() { std::cout << "~Dog() y�k�ld�: " << GetName() << std::endl; }

	std::string GetSound() { return sound; }
	void SetSound(std::string ssound) { this->sound = ssound; }
	void SetAll(std::string sname, double sheight, double sweight, std::string ssound) { 
		Animal::SetAll(sname, sheight, sweight); // Ya using ... kullan�n yada a��k a��k Animal s�n�f�n�n fonksiyonunu kulland���n�z� belirtin.
		SetSound(ssound); // fazladan eklenen �ye sound ve sound ayarland�.
						  // Ayn� zamanda static sayac�m�z �al���yor.
	}
	void SesC�kart() { std::cout << "Dog: " << GetName() << " says " << GetSound() << std::endl; }
	std::stringstream ToString() {
		auto ss = Animal::ToString();
		ss << " Sound: " << GetSound();
		return ss;
	}
	// printAll bir daha tanmlamaya gerek g�rmedim. Yeterince iyi.
};

