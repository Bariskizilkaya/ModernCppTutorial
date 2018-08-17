#pragma once
/*
<h1>Operator overload nedir ve nas�l yap�l�r? </h1>

* Operator denilen �ey asl�nda bir fonksiyondur. Yeni bir operator tan�mlarken girdisi ve ��kt�s� belli olan
fonksiyonlar tan�mlan�r. 
* c++ temel t�rler(int, float, double, char,...) t�rlerini kullanabilmek �zere haz�r operatorleri vard�r.
E�erki yeni bir t�r tan�mlarsak derleyici bu t�r ile operatorleri e�le�tiremez. O zaman bu operatorleri
programc� tan�mlamal�d�r. Hemen hemen t�m programlama dillerinde �zellikle oops destekli dillerde yap�lan
temel i�lemlerden biridir.
* T�m operatorler a��r� y�klenemez. https://en.cppreference.com/w/cpp/language/operators
* Matematiksel, mant�ksal, kar��la�t�rma I/O ve haf�zaya eri�im([],->,*(pointer dereferance)) ile ilgli operatorler a��r� y�klenebilir.
* A��r� y�kleme sorucunda operator �a�r�ld���nda tan�mlanan operator fonksiyonu �al��t�r�l�r ve sonu� al�n�r.

* operatorleri a��r� �ekilleri https://en.cppreference.com/w/cpp/language/operators i�inde tan�ml�d�r.
* burada yapaca��m �eyler e�itim ama�l�d�r. Daha sonra ayr�nt�l� anlataca�m.
*/

class kutucuk
{
	// operator a��r� y�klemesi yapmak �zere kullan�yorum.
private:
	double length, width, breadth;
	std::string name;
public:
	kutucuk() : length{ 1 }, width{ 1 }, breadth{ 0 }, name{ "" } {
	}
	kutucuk(double l, double w, double b) : length{ l }, width{ w }, breadth{ b } {
	}
	kutucuk(double l, double w, double b, std::string n) : length{ l }, width{ w }, breadth{ b }, name{ n } {
	}
	double getVolume(void) { // i�indeki void parametre almayaca��n� belirtiyor.
		return length * breadth * width;
	}
	// C# set-get kar��l���
	void setLength(double len) {
		length = len;
	}
	double getLength() {
		return length;
	}
	void setBreadth(double bre) {
		breadth = bre;
	}
	double getBreadth() {
		return breadth;
	}
	void setWidth(double wi) {
		width = wi;
	}
	double getWidth() {
		return width;
	}
	
	// ++a operat�r�n� a��r� y�kleme
	kutucuk& operator ++() {
		// ++a operat�r� �nce artt�rma sonra atama yapar.
		++length; ++width; ++breadth; return *this;
	}
	// a++ operat�r�n� a��r� y�kleme
	kutucuk operator ++(int) {
		// a++ operat�r� �nce atama sonra artt�rma yapar.
		kutucuk temp(*this); //kopyala
		operator++(); // pre-increment(++a) // Bu operat�r �nceden tan�mlanm��t�. Derleyici fonksiyonu tan�r.
		return temp; // eski de�eri g�nder.
	}

	// c string g�stericisi
	operator const char*() {
		std::ostringstream oss;
		oss << "kutucuk: " <<
			length << "," <<
			width << "," <<
			breadth;
		name= oss.str();
		return name.c_str();
	}

	kutucuk operator +(const kutucuk& kutu2) {
		/*
		kutucuk kutu1, kutu2;
		auto toplam=kutu1 + kutu2;
		buradaki i�lemde ilk parametre varsay�lan olarak kutu1 oldu�undan ikinci parametreyi yazmaya ihtiya� yok.
		*/
		kutucuk kutu;
		kutu.length = length + kutu2.length;
		kutu.width = width + kutu2.width;
		kutu.breadth = breadth + kutu2.breadth;
		return kutu;
	}
	double operator [](int say�) { // kutu[say�]. parametremiz say�.
		return say� == 0 ? length : say� == 1 ? width : say� == 2 ? breadth : 0;
	}
	bool operator == (const kutucuk& kutu2) {// toplam operat�r�yle ayn� kural ge�erli
		return (length == kutu2.length) && (width == kutu2.width) && (breadth == kutu2.breadth);
	}
	bool operator < (const kutucuk& kutu2) {
		auto hacim1 = this->getVolume();
		auto hacim2 = kutu2.length*kutu2.width*kutu2.breadth;
		return hacim1 < hacim2; // true yada false diye kendisi art�k belirleyebilir.
	}
	bool operator > (const kutucuk& kutu2) {
		auto hacim1 = this->getVolume();
		auto hacim2 = kutu2.length*kutu2.width*kutu2.breadth;
		return hacim1 > hacim2; // true yada false diye kendisi art�k belirleyebilir.
	}
	void operator = (const kutucuk& copyKutu2) { // asl�nda hatal�. sonra �zerinde duraca��m.
		length = copyKutu2.length;
		width = copyKutu2.width;
		breadth = copyKutu2.breadth;
	}
	// "<<" operator�n� a��r� y�klemedi�im i�in parantez olmadan derlenmez. 



	~kutucuk()=default; // varsay�lan y�k�c�y� otomatik olu�turur.
};
