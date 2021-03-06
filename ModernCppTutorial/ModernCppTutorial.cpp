// ModernCppTutorial.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//
/*
* Disclimer: I am not stealing any information.
I am combining, extending and translating tutorials and referances. I am giving my resourses inside functions.
*/

/* map python map fonksiyonu
template <typename Iter, typename F>
void map(Iter begin, Iter end, F f) {
for (; begin != end; ++begin)
*begin = f(*begin);
}
*/
/*
Kullanılmayan static fonksiyonlar otomatik olarak siliniyor.
Visual c++ derleyicisine has işlemlerden birkaında daha derin kullanılmayan kod analizi gerçekleştiriliyor.
* Linker aşamasında kullanılmayan semboller, gereksiz ifadeler elenebiliyor ama derleme süresi uzuyor.
https://docs.microsoft.com/en-us/previous-versions/visualstudio/visual-studio-2010/bxwfs976(v=vs.100)

* manuel olarak elemek isterseniz böyle bir ifade sadece visual c++ için geçerli.
https://docs.microsoft.com/en-us/cpp/cpp/selectany

* Gcc derleme aşamasında birkaç ek derleme seçeneğiyle bu sorunu çözebiliyor.
https://sourceware.org/binutils/docs-2.21/ld/Options.html#Options

*/

#include "stdafx.h"
// Ana çalışma dosyası.

// unutmayın 64 bit mimarisine göre derliyorum.
int main(int argc, char** argv)
{
	std::setlocale(LC_ALL, "Turkish"); // Konsolda Türkçe karakter için şart.
	// bilisayarınız yavaş ise visual studio ilk başta yazım yanlışı var hatası çıkarır ama zamanla kaybolur.
	temelDerslerMain(argc, argv); // Güzel düzenledim zannımca.



	std::cin.get(); // system("PAUSE"); // her işletim sisteminde farklı komut uygulanabilir.
					//std::getchar();
    return 0;
}

