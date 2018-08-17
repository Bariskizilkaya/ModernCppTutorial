#ifndef dersler_H // eski ve ta��nabilir usul header korumas�. Derleyici header dosyas�n� defalarca 
#define dersler_H // dahil etmesini �nler. B�y�k projelerde �nemli sorun te�kil ediyor.

#ifdef _MSC_VER
#pragma once
#endif
/*
 Ana dersler bu dosyada.

 Kaynaklar�m�n aras�nda
 en.cppreferance: https://en.cppreference.com/w/cpp/language // Cidden m�kemmel bir kaynak
 isocpp: https://isocpp.org/
 Derek Banas: http://www.newthinktank.com/ . Derek Banas thank you.
*/
/*
Her seferinde std::cout yazmak zor geldi�inden bir tak�m makrolar tan�mlad�m.
*/

ia ilkadim(int argc, char** argv)
{   //unutmay�n biz art�k moderniz(auto) ;)

	std::cout << "Selam Millet. T�rk�e karakterler: �������" << std::endl;

	/*
	Sadece eskiden nas�l yap�l�yordu bu i�ler g�stermek �zere yap�yorum.
	Art�k python argparse gibi k�t�phaneler kullan�l�yor.

	Ayr�ca c/c++ ifadelerini be�enmezseniz �ni�lemci ile kendinize g�re
	de�i�tirin ama pek sevilen bir�ey de�ildir.
	Ak�ll� �ekillendiriciler �n i�lemci ile �al��m�yor.
	*/
	if (argc != 1) ekranayaz << "komut sisteminde ba��ms�z de�i�ken var." << yenisat�r bitti

		//hadi biraz d�ng� �al��t�ral�m.
		for (size_t i = 0; i < argc; i++) basla
			std::cout << i << ". eleman= " << argv[i] << std::endl;
	bitir
}

ia temelVeriyap�lar�() {
	int g_irandNum = 0;
	const double giveMyPI = 3.142;
	bool yak�l��l�m� = true; //modern cpp t�rk�e karakter kullanabiliyorum.
	char ilkharf = 'M';
	std::string biryaz� = "64 bit architecture...";

	//modern c++ ile gelen literaller.
	int d = 42;
	int o = 052;
	int x = 0x2a;
	int X = 0X2A;
	int b = 0b101010; // C++14

	unsigned long long l1 = 18446744073709550592ull; // C++11
	unsigned long long l2 = 18'446'744'073'709'550'592llu; // C++14
	unsigned long long l3 = 1844'6744'0737'0955'0592uLL; // C++14
	unsigned long long l4 = 184467'440737'0'95505'92LLU; // C++14
														 //eski halleri yorumda. cstdint k�t�phanesinde mevcut.
														 /*
														 signed char        int8_t;
														 short              int16_t;
														 int                int32_t;
														 long long          int64_t;
														 unsigned char      uint8_t;
														 unsigned short     uint16_t;
														 unsigned int       uint32_t;
														 unsigned long long uint64_t;
														 */
	uint16_t u16age = 44; //unsigned short int
	int16_t yar��ap = 200;
	int32_t g�nler = 7;
	long b�y�ktamsay�klar = 65241652; // :)
	float rasyonelsay� = 2.728; //float32
	double dahaRasyonelsay� = 5.96846549565496; // float iki kat�
	long double �ooookB�y�k = 398652165.72686521465216; // hem virg�lden �nce hem virg�lden sonra �ok b�y�k.

	auto neolacak = true; // otomatik bool t�r�ne d�n��t�.
	decltype(g�nler) neolacak2 = 777; // g�nler de�i�keninin tipinde tan�mlad�m.

									  // std::cout fonksiyonu formatl� yaz�m yapm�yor.
									  // printf unicode desteklemiyor.
	printf("ilkharf=%c u16age=%d yar��ap=%5d �ooookB�y�k=%.3f biryaz�=%s \n", ilkharf, u16age, yar��ap, �ooookB�y�k, "asdfg");

	// ka� byte istersen o kadar g�sterir.
	std::cout << "sizeof(neolacak2)= " << sizeof(neolacak2) << std::endl;

	//S�sl� parantezleri istedi�iniz gibi kullan�n. Sonu�lar�n� ileride anlataca��m.
	{
		// limits k�t�phanesinde hepsi var.
		std::cout << "min bool= " << std::numeric_limits<bool>::min() << std::endl;
		std::cout << "max bool= " << std::numeric_limits<bool>::max() << std::endl << std::endl;

		std::cout << "min uint16_t= " << std::numeric_limits<uint16_t>::min() << std::endl;
		std::cout << "max uint16_t= " << std::numeric_limits<uint16_t>::max() << std::endl << std::endl;

		std::cout << "min int16_t= " << std::numeric_limits<int16_t>::min() << std::endl;
		std::cout << "max int16_t= " << std::numeric_limits<int16_t>::max() << std::endl << std::endl;

		std::cout << "min int32_t= " << std::numeric_limits<int32_t>::min() << std::endl;
		std::cout << "max int32_t= " << std::numeric_limits<int32_t>::max() << std::endl << std::endl;
	}

	float32 fbig1 = 1.1111111111, fbig2 = fbig1, fbigsum = fbig1 + fbig2;
	printf(" hassasiyetle float yazd�rma= %.10f \n", fbigsum);

	float64 f64big1 = 1.11111111111111111111, f64big2 = 1.1111111111, f64bigsum = f64big1 + f64big2;
	printf(" hassasiyetle float yazd�rma= %.20f \n", f64bigsum);


}

ia string��lemleri() {
	std::string biryaz�("hele dur orada!"); //string tipi standart k�t�phanede bulunuyor.
	fmt::printf("biryaz�= %s \n", biryaz�); //fmt k�t�phanesi unicode destekler.

											//auto sorgu("1 say�s�n� gir"); // auto std::string objesi yerine char* tipine d�n��t�r�yor.
	string sorgu("1 say�s�n� gir="), sNum1, sNum2;
	ekranayaz << sorgu;
	std::getline(std::cin, sNum1); // string olarak almay� garanti eder. belirlenen ak�mdan bir sat�r okur.
	ekranayaz << "2 say�s�n� gir=";
	std::getline(std::cin, sNum2);
	ekranayaz << yenisat�r;

	// stoi == string to integer ;). tahmin etmek zor de�il.
	auto nNum1 = std::stoi(sNum1),
		nNum2 = std::stoi(sNum2);

	yenisat�ryaz;

	// kusura kalmazsan�z biraz matematik.
	printf("%d + %d= %d \n", nNum1, nNum2, nNum1 + nNum2);
	printf("%d - %d= %d \n", nNum1, nNum2, nNum1 - nNum2);
	printf("%d * %d= %d \n", nNum1, nNum2, nNum1 * nNum2);
	printf("%d / %d= %f \n", nNum1, nNum2, (float)nNum1 / (float)nNum2);
	printf("%d %% %d= %d \n", nNum1, nNum2, nNum1 % nNum2);

	{
		//ilk problem
		// km=mil*1.60934
		// kullan�dan mili al�p km �evirecek.

		std::string inputmil;
		double cMil, cKm;
		ekranayaz << "  --- Mil -> Km --- " << yenisat�r;
		ekranayaz << "Mil: " << yenisat�r;
		getline(std::cin, inputmil);
		cMil = std::stod(inputmil);
		ekranayaz << "Km: " << cMil * 1.60934 << yenisat�r;
	}


}

ia karar��lemleri() {
	std::string ya� = "0";
	std::cout << "Ya��n� yaz= " << std::endl;
	getline(std::cin, ya�);
	auto iya� = std::stoi(ya�);

	if (iya� >= 1 and iya� <= 10) ekranayaz << "�nemli do�um g�n�" << yenisat�r;
	else if (iya� >= 10 and iya� <= 20) ekranayaz << "daha az �nemli do�um g�n�" << yenisat�r;
	else if (iya� >= 20 and iya� <= 50) ekranayaz << "�nemli olmayan do�um g�n�" << yenisat�r;
	else if (iya� >= 50) ekranayaz << "olmasa da olur \n";
	else ekranayaz << "D'oh \n";
}

ia dizi��lemleri() {
	/*
	Diziler boyutu tan�mlan�rken verilir ve de�i�mez
	fakat i�indeki veriler de�i�tirilebilir(const de�ilse)
	Her eleman�n tipi ayn�d�r.

	Asl�nda dizi bir pointer tipidir. *(arrNum2+index*sizeof(decltype(arrNum2[0])))
	gibi bir eri�im sa�lanabilir ama tavsiye edilmez. Derleyici arrNum3[index]
	kullan�m�nda bir tak�m kontroller yapabilir.

	STL array tipiyle dizi i�in gerekli i�lemleri toplam��t�r.
	*/
	int arrNum[10] = { 1 };
	int arrNum2[] = { 1,2,3 };
	int arrNum3[5] = { 8,9 };

	std::cout << "1. value : " << arrNum3[0] << yenisat�r;
	arrNum3[0] = 5;
	std::cout << "1. value : " << arrNum3[0] << yenisat�r;
	//std::cout << "1. value : " << arrNum3[7] << yenisat�r; //hata vermez ama hatad�r.
	std::cout << "1. value : " << *(arrNum3 + 0 * sizeof(int)) << yenisat�r;
	//sizeof(arrNum3)/ sizeof(int) // dizi tipi her zaman int olmaz.
	std::cout << "Array size:" << sizeof(arrNum3) / sizeof(*arrNum3) << "\n"; //ilk eleman�n�n boyutunu kontrol eder.
	std::cout << "Array size(decltype):" << sizeof(arrNum3) / sizeof(decltype(arrNum3[0])) << "\n"; //ilk eleman�n�n tipinin boyutunu kontrol eder. Sanki daha iyi.

																									/*
																									* Modern c++ �zelliklerini kullanabilmemizi sa�lar.
																									* Otomatik parallele�tirme yapabilmeyi m�mk�n k�lar.
																									* array.at() fonksiyonuyla s�n�r kontrol� ger�ekle�tirebilir. Daha g�venli.
																									*/

																									//iterat�rler ve stl �zerinde daha sonra �zerine konu�aca��z.
	{
		typedef std::array<int, 5> defalarca;
		defalarca arr;
		arr.fill(3);
		arr[2] = 8;
		arr.at(4) = -2; // "bound check" s�n�r kontrol�. G�venli eri�im
		arr[3] = 5;
		// arr.assign() // b�yle bir fonksiyon yok.
		defalarca::pointer ptr = arr.data();
		std::cout << "arr.data():  " << *ptr << std::endl;
		defalarca::iterator it = arr.begin(); // normal iterat�r
		std::cout << "const_iterator arr.begin(): " << *it << std::endl;
		defalarca::const_iterator it2 = arr.cbegin() + 2; // 2. eleman. constant iterat�r
		std::cout << "const_iterator arr.begin()+2: " << *it2 << std::endl;

		// iterat�rlerde azaltmaya girerseniz hata al�rs�n�z.
		// xutils k�t�phanesi i�inde azaltma i�lemi yasaklanm��t�r.
		// tersten eri�im i�in ..._reverse_iterat�rleri kullan�n.
		for (defalarca::const_reverse_iterator it3 = arr.rbegin(); it3 != arr.rend(); ++it3)
			std::cout << "rbegin ve rend: " << *it3 << std::endl;
		// crbegin ve crend constant reverse iterat�r.
		// yani tersten eri�im.
	}
	{
		std::array<int, 3> a1{ { 1, 2, 3 } }; // double-braces required in C++11 (not in C++14)
		std::array<int, 3> a2 = { 1, 2, 3 };  // never required after =
		std::array<std::string, 2> a3 = { std::string("a"), "b" };

		// container operations are supported
		std::sort(a1.begin(), a1.end());
		std::reverse_copy(a2.begin(), a2.end(),
			std::ostream_iterator<int>(std::cout, " "));

		std::cout << '\n';

		// ranged for loop is supported
		for (const auto& s : a3)
			std::cout << s << ' ';
	}

	// �ok Boyutlu Diziler.
	int64_t eski[2 * 3 * 2] = {
		000,001, 010,011, 020,021, // [0*(3*2) + blok*3 + i�*2]
		100,101, 110,111, 121,122, // [1*(3*2) + blok*3 + i�*2]
	};

	int64_t klasik[2][3][2] = {
		{ { 000,001 },{ 010,011 },{ 020,021 } }, // [0][][]
	{ { 100,101 },{ 110,111 },{ 121,122 } }, // [1][][]
	};

	// dizilerin aslen pointer oldu�unun kan�t�d�r.
	std::cout << std::endl << " ---Hepsi Ayn� De�er--- \n";
	std::cout << "eski[9]: " << eski[9] << std::endl; // sat�r*(3*2) + blok*3 + i�*2
	std::cout << "klasik[1][1][1]: " << klasik[1][1][1] << std::endl;
	// Birka� kez adres eri�imine ba�vuruldu�undan i�lemleri yava�latt��� d���n�l�yor.
	// Yeni derleyiciler bunun �stesinden geldi�ini duydum.
	std::cout << "*(klasik[1][1] + 1): " << *(klasik[1][1] + 1) << std::endl;
	std::cout << "*(*(klasik[1] + 1) + 1): " << *(*(klasik[1] + 1) + 1) << std::endl;
	std::cout << "*(*(*(klasik + 1) + 1) + 1): " << *(*(*(klasik + 1) + 1) + 1) << std::endl;

}

ia vector��lemleri() {
	/*
	* Vector tipi c++ dilinin itibar�n�n simgesidir. :)
	* Gelmi� ge�mi� en h�zl� veri yap�s�d�r(tabi kullanabilene).
	* Array tipinin �zerine in�a edilmi�tir. �stenirse array gibi davranabilir.
	* Stack yap�s�yla �al���r.
	* Boyutu her 1 eleman geldik�e kendi kendine geni�leyebilir. Ayarlan�rsa n elemanda bir geni�ler.
	b�ylece haf�zay� sil ve yeniden daha geni�lemi� olarak doldur d�ng�s�n�n i�lem y�k� azalm�� olur.
	*/
	std::vector<int> vecNums(2); // iki elemanl� tek boyutlu dizi olarak ba�lad�.
	vecNums[0] = 2;
	vecNums.at(1) = 4; // yine s�n�r kontrol� ile atama yap�labilir.
	vecNums.push_back(8); // dizi olarak ba�lamas�na ra�men geni�ledi.
	std::cout << "Son eleman: " << vecNums[vecNums.size() - 1] << std::endl;

	std::for_each(vecNums.begin(), vecNums.end(),
		[](auto& i) { std::cout << i << std::endl; });

	//std::vector<auto> au; // error
	std::vector<int> dolduri�ini(8);
	std::iota(dolduri�ini.begin(), dolduri�ini.end(), 0); // std::for_each(dolduri�ini.begin(), dolduri�ini.end(), [](auto& i) {++i}); // kar��l���
														  // ba�lang�� elemandan ba�layarak son elemana kadar doldur.
														  // doldurma �ekli ba�lang�� 0 sonras�nda +1 artt�rarak doldur.
	std::cout << "iota: " << std::endl;
	std::for_each(dolduri�ini.begin(), dolduri�ini.end(),
		[](auto& i) { std::cout << i << std::endl; });

	/* Yukar�dakinin e�iti
	for (size_t i = 0; i < dolduri�ini.size(); i++) {
	std::cout << dolduri�ini.at(i) << std::endl;
	}
	for (auto i : dolduri�ini) std::cout << dolduri�ini.at(i) << std::endl;
	*/

	// t�m vekt�rdeki �ift say�lar� kontrol et. biraz daha fonksiyonel yakla��m.
	std::for_each(dolduri�ini.begin(), dolduri�ini.end(),
		[](auto& i) { if (not (i % 2)) std::cout << i << std::endl;   });

	// c�mleyi bo�luklarla ay�raca��z.
	std::string cumle = "arap ihsan efendi";
	char bosluk = ' ';
	auto kelimeler = functionalStyle::StringToVector(cumle, bosluk); // i�indeki di�er ifadelere sonra de�inece�im.

	for (size_t i = 0; i < kelimeler.size(); ++i) { //size_t c dilinden geliyor ve bir tak�m avantajlar� var.
		std::cout << kelimeler.at(i) << std::endl;
	}

	{
		using std::vector;
		using std::string;
		//klasik uygulama. Hesap makinesi
		// input: 1 - 5
		// output: -4
		auto num1 = 0.0, num2 = 0.0; // 5(num1) - 9(num2)
		string strCalc = std::string(" "); // girdinin olaca�� string
		vector<string> vecCalc; // girdi ayr��t�r�lacak ve i�ine eklenecek.
		auto bosluk = ' '; // bo�luk g�r�nce ayr��t�r�lacak.

		std::cout << "Hesaplamak istedi�iniz ifade nedir? (bo�luk b�rakaraj yaz�n. Exp: 4 * 7)" << std::endl;
		getline(std::cin, strCalc);

		std::stringstream ss(strCalc); // ayr��t�rmaya yar�yor.
		string ayr�ld�; // anl�k ayr�lan ifade

		while (getline(ss, ayr�ld�, bosluk)) {
			vecCalc.push_back(ayr�ld�);
		}

		num1 = std::stod(vecCalc[0]);
		num2 = std::stod(vecCalc[2]);

		auto operate = vecCalc[1];

		// iyi de�il. �imdilik i�imizi g�r�yor.
		if (operate == "+")
		{
			ekranayaz << num1 + num2 << std::endl;
		}
		else if (operate == "-")
		{
			ekranayaz << num1 - num2 << std::endl;
		}
		else if (operate == "*")
		{
			ekranayaz << num1 * num2 << std::endl;
		}
		else if (operate == "/")
		{
			ekranayaz << num1 / num2 << std::endl;
		}
		else
		{
			std::cout << "l�tfen do�ru girin. +,-,*,/" << std::endl;
		}

	}

}

ia pointlerFonksiyonlar() {
	/*
	* ��aret�iler nesneye direkt eri�mek yerine adresini tutar ve istendi�inden adresten veriyi al�r.
	* pointer->|adres|->veri
	* B�y�k miktarda verilerin defalarca kopyalamak yerine haf�zada ba�lad��� noktay� i�aret etmek ak�ll�cad�r.
	*
	* C dilinden gelen i�aret�ilere ek olarak c++ referans objesini kullan�r.
	* Referans yani ba�vuru objesi nesneye fiziksel olarak eri�mek yerine daha h�zl� bir y�ntem kullan�r.
	* �imdilik referanslar�n kullan��l� oldu�unu bilin yeter. Hadi ba�layal�m.
	*
	* Fonksiyonlar birden fazla tekrarlanan kal�plar� gruplamakta kullan�l�r.
	* Program �al��maya ba�lad���nda veriler gibi fonksiyonlarda haf�za da yer kaplar ancak
	g�m�l� sistem programc�s�ysan�z dikkat edersiniz. Y�r�t�lebilir dosya boyutunu i�indeki veri ve fonksiyonlar etki eder.
	* Yine b�y�k fonksiyonlar� kullanmak �zere yada geri �a��r�m fonksiyonu yazmak �zere pointer alabilir.
	fakat Modern C++ <function> objesi ve lambda fonksiyonlar� sayesinde i�leri basitle�tirmi�tir.
	*/

	{
		// pointer kullan�m�
		int say� = 1;
		std::cout << "ram �zerindeki adresi(yeri): " << &say� << std::endl;
		int* point = &say�;
		std::cout << "pointer: " << *point << std::endl;
		*point = 5;
		std::cout << "pointer changed: " << *point << std::endl;

		// dizi pointer kullan�m�
		int arr[] = { 1,2,3,4 };
		int* Parr = arr;
		std::cout << "1.eleman: " << *Parr << " ,adres: " << Parr << std::endl;
		Parr += 2;
		std::cout << "3.eleman: " << *Parr << " ,adres: " << Parr << std::endl;
		Parr--;
		std::cout << "2.eleman: " << *Parr << " ,adres: " << Parr << std::endl;
		Parr++;
		std::cout << "3.eleman: " << *Parr << " ,adres: " << Parr << std::endl;

		// referans kullan�m�
		int program = 45;
		int& refp = program;
		std::cout << "refp: " << refp << std::endl; // s�ylemi�tim bu bir pointer de�il.

													// fonksiyon atamalar�
		assignByValue(say�);
		std::cout << "assignByValue: " << say� << std::endl; // Parantezlerin ba�lang�c� y���n�n ba�lad���,
															 // parantezin sonu y���n�n ya�am s�resinin bitti�i yerdir. 

		std::cout << "returnByValue: " << returnByValue(say�) << std::endl; // fonksiyon d���na ��kt�. return de�eri d��ar� att�.

		assignByPointer(&say�);
		std::cout << "assignByPointer: " << say� << std::endl; // fonksiyon d���na ��kt�. y���n olarak ge�memi�ti.

		assignByRef(say�);
		std::cout << "assignByRef: " << say� << std::endl; // fonksiyon d���na ��kt�. de�er gibi g�r�n�yor ama de�il. 
														   // i�te referans�n g�c�.

	}
	yenisat�ryaz;
	{
		// fonksiyon i�aret�isi
		// basit�e
		void(*fun_ptr)(int) = &yazacak;
		(*fun_ptr)(10);

		//biraz daha ileri ta��lay�m.
		int arr[] = { 2, 5, 7, 90, 70 };
		int n = sizeof(arr) / sizeof(arr[0]);
		int x = 7;
		printf("D�nen index %d \n", search(arr, n, sizeof(int), &x, compare));


		std::vector<int> range = RangePython(1, 10, 2);
		for (auto& i : range) std::cout << "range: " << i << ", ";
		yenisat�ryaz;
		// YADA
		// Eski C dili.
		myFuncPoint ptrFunc = RangePython;
		yazacakFunc(1, 10, 2, ptrFunc);

		// C++ �ekli
		auto lambda = [](int x) { cout << x * 50 << endl; return x * 100; };
		f(lambda); //pass lambda


	}
	yenisat�ryaz;
	{
		// y�ll�k %1 para art���na g�re 10 sene sonra ne kadar paran olur?
		double paramVar = 0.0; double kar = 0.0; //varsay�lan de�erleri verdim.
		ekranayaz << "Ba�lang��ta ne kadar paran var? : "; std::cin >> paramVar; yenisat�ryaz;
		ekranayaz << "Ne kadar k�r�n var? : "; std::cin >> kar; yenisat�ryaz;
		kar *= .01; // y�zdeli�e g�re hesaplanmas�n� sa�lad�m.
		for (auto& i : RangePython(1, 10, 1))
			paramVar += paramVar * kar;
		std::cout << "10 y�l sonra elde edece�in miktar: " << paramVar << yenisat�r;

		std::cin.get();
	}
}

ia �zeldurumlarVED�ng�ler() {
	// lambda fonksiyonlar�n�n normal fonksiyonardan nerdeyse fark� yok.
	// kullan�m� olduk�a basit ve de�i�ken de�eri gibi kullan�labiliyor.
	auto loop = []() {
		/*
		* G�rev �am a�ac� !
				 #			->
				###			->
			   #####		->
			  #######		->
			 #########		->
				 #			->
		* Ger�ekle�tirmek istedi�imiz �ekil budur.
		* Biraz bekleyece�im deneyin.
		*/
		std::cout << "��genin uzunlu�u ka� olsun?: ";
		auto boy = 0, bosluk = 0, hash = 1, stumpboslu�u = 0;
		std::cin >> boy;
		bosluk = boy - 1;
		stumpboslu�u = boy - 1;

		while (boy != 0) /* boy<0 daha iyi olabilir */ {
			for (auto i : RangePython(1, bosluk, 1))
				std::cout << " ";
			for (auto i : RangePython(1, hash, 1))
				std::cout << "#";
			yenisat�ryaz;
			--bosluk;
			hash += 2;
			--boy;
		}
		for (auto i : RangePython(1, stumpboslu�u, 1))
			std::cout << " ";
		std::cout << "#";
		std::cin.get();

	};

	auto �zelDurum = []() {
		double num1, num2 = 0; // modern c++ ;)
		ekranayaz << "say� bir: " << yenisat�r;
		std::cin >> num1;
		ekranayaz << "say� iki: " << yenisat�r;
		std::cin >> num2;

		try {
			if (num2 == 0)
				throw("s�f�r ile b�l�m hatas�"); // �al��ma zaman� hatas� g�nderir. derleme zaman� hatas�n� g�rece�iz.
			else
			{
				printf("%.1f/%.1f=%.2f", num1, num2, num1 / num2);
			}
		}
		catch (const std::string exp) /* Hatay� throw ile g�ndermi�tik ve catch ile yakalad�k. Bir yere ka�m�yor :) */ {
			// hatan�n ne oldu�unu biz bilmiyorsak; sadece ekrana yazar�z.
			std::cout << "hata: " << exp << std::endl;
		}
		std::cin.get();
	};

	auto �zelDurum2 = []() {
		double num1, num2 = 0; // modern c++ ;)
		ekranayaz << "say� bir: " << yenisat�r;
		std::cin >> num1;
		ekranayaz << "say� iki: " << yenisat�r;
		std::cin >> num2;

		try {
			std::cout << "Hata g�nderiyoruz..." << yenisat�r;
			throw std::runtime_error("hatalar olu�tu aman���n!");
			std::cout << "Ekrana hata gelecek mi? Catch kullan.";
		}
		catch (std::exception& exp) {
			// hatan�n ne oldu�u biz bilmeden hatay� yakalad�k.
			std::cout << "hata yakaland�. yuppii : " << exp.what() << std::endl;
		}
		catch (...) {
			// hatan�n ne oldu�unu bilgisayardaki veri taban� da bilmiyorsa...
			std::cout << "varsay�lan hata yakalay�c�. Her �eyi yakalar." << std::endl;
		}
		std::cin.get();
	};

	auto rastgele = []() {
		srand(time(NULL));
		auto tahminEdilecek = std::rand() % 11; // max=10
		auto tahmin = 0;
		// do-while fark� sorgusuz blo�un i�indekini bir kere yapar.
		do
		{
			std::cout << "akl�mdakini tahmin et." << std::endl;
			std::cin >> tahmin;
			if (tahmin > tahminEdilecek) std::cout << "b�y�k oldu" << std::endl;
			if (tahmin < tahminEdilecek) std::cout << "k���k oldu" << std::endl;
		} while (tahminEdilecek != tahmin);
		/*
		// Yukar�dakinin ayn�s�
		while (true)
		{
			std::cout << "akl�mdakini tahmin et." << std::endl;
			std::cin >> tahmin;
			if (tahmin > tahminEdilecek) std::cout << "b�y�k oldu" << std::endl;
			if (tahmin < tahminEdilecek) std::cout << "k���k oldu" << std::endl;
			if (tahminEdilecek == tahmin) break; // d�ng�den ��kmak �zere gerekli.
		}
		*/


		std::cout << "Tebrikler tahmin ettiniz." << std::endl;
		std::cin.get();
	};

	//loop();
	�zelDurum();
	�zelDurum2();
	rastgele();
}

ia stringMath() {
	char cString[] = { 'A','B','C','D','E','\0' }; // \0 "null" karakteri olmazsa program hata verip kapan�r.
	// cstring ifadelerini i�lemek zordur.
	std::cout << "Array size: " << sizeof(cString) << std::endl;

	// Modern c++ string ifadesini art�k daha derinlemesine i�leyece�im.
	auto string�fadesi = []() {
		std::vector<std::string> vecStr(10);
		std::string str("Benim ad�m string");
		vecStr[0] = str;

		//unutmay�n index '0''dan ba�l�yor.
		std::cout << "front: " << str.front() << ", back: " << str.back() << std::endl; //front= 'B' , Back= 'g' 
		std::cout << "Uzunluk: " << str.length() << std::endl;
		std::string str2(str); // kopyalad�k.
		vecStr[1] = str2;
		std::string str3(str2, 4); // 4. indexten itibaren kopyad�k.
		vecStr[2] = str3;
		std::string str4(5, 't'); // t 5 kez tekrarland�.
		vecStr[3] = str4;
		vecStr[4] = str4.append(" demi�tim."); // standart k�t�phane ile
		str += "str ekleniyor."; // operat�r desteklerse.
		str.append(str, 10, 13); // 10. indexten itibaren 13 tane.
		vecStr[5] = str;
		str.erase(13, str.length() - 1); // 13. indexten itibaren "str.length() - 1" tane siliniyor.
		vecStr[6] = str;
		str.erase(str.begin() + 5, str.end() - 3);
		vecStr[7] = str;

		auto bul = str.find("string");
		if (bul != std::string::npos) // npos evrenselle�tirilmi� son string ifadesidir. 32 ve 64 bitte farkl� say�lar� ifade eder.
			std::cout << "1st index" << bul << std::endl;

		std::cout << "substr: " << str.substr(6, 6) << std::endl; // 6. indexten itibaren 6 tane
		std::reverse(str.begin(), str.end());
		std::cout << "reversed: " << str << std::endl;

		//transform	  inputBa�lang��, inputBiti�, outputBa�lang��, i�lem . �eklinde �al���r.
		std::transform(str.begin(), str.end(), str.begin(), ::toupper); // varsay�lan namespace std oldu�undan tan�d�.
		std::cout << "toupper: " << str << std::endl;
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
		std::cout << "tolower: " << str << std::endl;

		// string i�inden c dilinin string ifadesini ��karmak i�in.
		std::cout << "cstr: " << str.c_str() << std::endl;

		/*
		Ascii karakterlerin say�sal kar��l�klar�...
		* a-z : 97-122
		* A-Z : 65-90
		*/

		char c = 'G';
		int ii = c;
		// eski hali (int)'c' . c++ dilinde static_cast derleme zaman�nda tip g�venli�i sa�lad���ndan tavsiye ederim. 
		std::cout << "c ascii code: " << static_cast<int>('c') << std::endl;
		// say�lar� string ifadelerine �evirmek istiyoruz.
		std::string numstr = std::to_string(5 - 8);
		std::cout << "say� -> string d�n���m�: " << numstr << std::endl;


		auto i = 0;
		for (auto v : vecStr) {
			ekranayaz << i << ". " << v << yenisat�r; ++i;
		}

		std::cin.get();
	};

	auto c�mleyi�ifrele = []() {
		std::string normal, gizli = "";

		std::cout << "�ifrelemek istedi�iniz ingilizce ifadeyi girin." << std::endl;
	std:cin >> normal;

		// �ifrele. asl�nda ascii kodlar�n� yazd�r�yor.
		/*
		Ascii karakterlerin say�sal kar��l�klar�...
		* a-z : 97-122 // �� basamakl� da olabiliyor. Geri �evrilemez.
		* A-Z : 65-90 // iki basamakl� say�lar oldu�u kesin. i�imize yarayacak ;)
		en az 23 ��kar�l�rsa edinecelecek maximum say� 123 - 23= 99 olur ve iki basamakl�d�r.
		*/
		auto kodla = [](auto& normal) {
			std::string gizli = "";
			for (auto ch : normal)
				// iki basamakl� sa� oldu�unu garanti ediyoruz.
				gizli.append(std::to_string(static_cast<int>(ch - 23))); //gizli.append(std::to_string(static_cast<int>(ch))); // 
			std::cout << "�ifre: " << gizli << std::endl;
			return gizli;
		};
		gizli = kodla(normal);

		auto kod��z = [](auto& gizli) {
			// eski haline d�nd�r.
			std::string normal = "";
			for (size_t i = 0; i < gizli.length(); i += 2)
			{
				std::string sCharCode = "";
				// int ifadesiylede yap�labilir ama uzun c�mlelerde string ile 
				// ta�ma hatas� ya�amay�z.
				sCharCode += gizli[i];
				sCharCode += gizli[i + 1]; // �� basamakl� say� ise sistem �al��maz. iki basamakl� olmak zorunda.

				int nCharCode = std::stoi(sCharCode);
				// �ifrelemeyi tersine �evirebilmek �zere 23 ��karm��t�k. fakat as�l karakterleri
				// elde edebilmek i�in ayn� say� tekrar eklenmeli.
				char chCharCode = nCharCode + 23; //char chCharCode = nCharCode;
				normal += chCharCode;
			}
			std::cout << "Orjinal: " << normal << std::endl;
			return normal;
		};
		normal = kod��z(gizli);





		std::cin.get(); // ekran hemen kapanmas�n istiyorum.
	};

	auto matematik = []() {
		// c dilindeki matematik ifadeleri aynen kullan�labilir.
		// fazladan ileri matematik ifadeleri eklenmi�tir.
		// ileri g�sterece�im parallel hesaplamaya uygun ifadelerdir.

		std::cout << "abs(-10) = " << std::abs(-10) << "\n";

		std::cout << "max(5,4) = " << std::max(5, 4) << "\n";

		std::cout << "min(5,4) = " << std::min(5, 4) << "\n";

		std::cout << "fmax(5.3,4.3) = " << std::fmax(5.3, 4.3) << "\n";

		std::cout << "fmin(5.3,4.3) = " << std::fmin(5.3, 4.3) << "\n";

		// e ^ x
		std::cout << "exp(1) = " << std::exp(1) << "\n";

		// 2 ^ x
		std::cout << "exp2(1) = " << std::exp2(1) << "\n";

		// e * e * e ~= 20 so log(20.079) ~= 3
		std::cout << "log(20.079) = " << std::log(20.079) << "\n";

		// 10 * 10 * 10 = 1000, so log10(1000) = 3
		std::cout << "log10(1000) = " << std::log10(1000)
			<< "\n";

		// 2 * 2 * 2 = 8
		std::cout << "log2(8) = " << std::log2(8)
			<< "\n";

		// 2 ^ 3
		std::cout << "pow(2,3) = " << std::pow(2, 3)
			<< "\n";

		// Returns what times itself equals the provided value
		std::cout << "sqrt(100) = " << std::sqrt(100)
			<< "\n";

		// What cubed equals the provided
		std::cout << "cbrt(1000) = " << std::cbrt(1000)
			<< "\n";

		// Hypotenuse : SQRT(A^2 + B^2)
		std::cout << "hypot(2,3) = " << std::hypot(2, 3)
			<< "\n";

		std::cout << "ceil(10.45) = " << std::ceil(10.45)
			<< "\n";

		std::cout << "floor(10.45) = " << std::floor(10.45)
			<< "\n";

		std::cout << "round(10.45) = " << std::round(10.45)
			<< "\n";

		// Dahas� da var; sin, cos, tan, asin, acos, atan, atan2,
		// sinh, cosh, tanh, asinh, acosh, atanh


	};
	//string�fadesi();
	//c�mleyi�ifrele();
	matematik();

}

static std::string operator*(const std::string& s, size_t n)
{
	std::string result;
	result.reserve(s.size()*n);
	for (size_t i = 0; i < n; ++i) {
		result += s;
	}
	return result;
}
ia Alistirmalar() {
	// bo�luk ve �zel karakterleri silmek �zere kullan�lan trim fonksiyonu c++ stl i�inde yok. Hadi yapal�m.
	auto trimKarakter = [](std::string str) {
		std::string boslukKarakterleri(" \t\f\v\n\r"); // bosluk ve string formatlama karakterleri var.
		const auto& last = str.find_last_not_of(boslukKarakterleri);
		str.erase(last + 1); // 
		const auto& first = str.find_first_not_of(boslukKarakterleri);
		str.erase(0, first);
		return str;
	};
	std::string asd("   Cat runner gets the skinner   ");
	std::cout << "trimden �nce(size):" << asd.size() << std::endl;
	const std::string& trimed = trimKarakter(asd);
	std::cout << "trimden sonra(size):" << trimed.size() << std::endl;
	std::cout << "trimed: " << trimed << std::endl;
	yenisat�ryaz;

	// python benzeri string �arpma i�lemini nas�l yapaca��z?
	// burada operator a��r� y�klemesi yapt���m�zdan yukar�da static olarak tan�mlanmal�.
	std::cout << (std::string("=+") * 5) << std::endl;

	// string i�inde istenen ifade var m�, yok mu?(find substring matches)
	auto strMatches = [](std::string str, std::string substr) {
		std::vector<int> matchingIndexes;
		int index = str.find(substr, 0);
		while (index != std::string::npos) {
			matchingIndexes.push_back(index);
			index = str.find(substr, index + 1);
		}
		return matchingIndexes;
	};
	std::string strTest = " direkte leylek yuvas� var.";
	std::string substrTest = "lek";
	std::vector<int> matched = strMatches(strTest, substrTest);
	for (auto& v : matched) std::cout << v << std::endl;
	yenisat�ryaz;
	// bulunan t�m e�le�meleri istenen string ile de�i� toku� et.
	// std i�ineki index bazl� hesaplama yap�yor ve kullan�m� rahat de�il.
	auto strReplace = [strMatches](std::string str, std::string substr, std::string newstr) {
		// lambda kural� olarak strMatches fonksiyonunu bu [strMatches] ile lambda fonksiyonunun i�ine kopyalad�m.
		std::vector<int> matched = strMatches(str, substr); // e�er e�le�me olmazsa .size 0 g�nderecek.
		if (matched.size() != 0) {
			int sizeDiff = matched.size() - substr.size();
			auto looped = 0;
			for (auto index : matched)
				str.replace(index + looped * sizeDiff, substr.size(), newstr); looped;
		}
		return str;
	};
	std::string degistokus = "lak";
	std::cout << "strReplace: " << strReplace(strTest, substrTest, degistokus) << std::endl;
	yenisat�ryaz;

	auto isFonksiyonlar� = []() {
		char harf = 'k';
		char say� = '5';
		char bosluk = ' ';

		std::cout << "Is k a letter or number " <<
			isalnum(harf) << "\n";
		std::cout << "Is k a letter " <<
			isalpha(harf) << "\n";
		std::cout << "Is k uppercase " <<
			isupper(harf) << "\n";
		std::cout << "Is k lowercase " <<
			islower(harf) << "\n";
		std::cout << "Is 5 a number " <<
			isdigit(say�) << "\n";
		std::cout << "Is space a space " <<
			isspace(bosluk) << "\n";
	};
	isFonksiyonlar�();

	// rastgele say�lardan olu�an vekt�r olu�tural�m.
	auto GenerateRandVec = [](int numOfNums, int min, int max) {
		std::vector<int> vecValues;
		// Seed the random number generator
		srand(time(NULL));
		int i = 0, randVal = 0;
		while (i < numOfNums) {
			randVal = min + std::rand() % ((max + 1) - min);
			vecValues.push_back(randVal);
			i++;
		}
		return vecValues;
	};
	std::vector<int> vecVals = GenerateRandVec(10, 5, 50);
	for (auto x : vecVals)
		std::cout << x << "\n";
	yenisat�ryaz;

	// range fonksiyonunu �nceden yapm��t�m ama hadi bir daha yapal�m fakat asal say� �reteci olsun ;)
	auto Range = [](int start, int max, int step) {
		int i = start;
		std::vector<int> range;
		while (i <= max) {
			range.push_back(i);
			i += step;
		}
		return range;
	};
	auto IsPrime = [Range](int num) {
		for (auto n : Range(2, num - 1, 1)) {
			if ((num % n) == 0)
				return false;
		}
		return true;
	};
	auto GetPrimes = [Range, IsPrime](int maxNum) {
		std::vector<int> vecPrimes;
		for (auto x : Range(2, maxNum, 1)) {
			if (IsPrime(x))
				vecPrimes.push_back(x);
		}
		return vecPrimes;
	};
	int num = 0;
	std::cout << "Number to Check : ";
	std::cin >> num;
	std::cout.setf(std::ios::boolalpha);// Shows bool values as true or false
	std::cout << "Is " << num << " Prime: " << IsPrime(num) << "\n";
	std::cout << "Generate Primes up to ";
	int maxPrime;
	std::cin >> maxPrime;
	std::vector<int> primeList = GetPrimes(maxPrime);
	for (auto x : primeList)
		std::cout << x << "\n";
	yenisat�ryaz;
	std::cin.clear(); // kontrol bayraklar�n� siler ve yoluna devam eder.
	// io operasyonlar�n� ayr�nt�s�yla anlatmad�m ama e�erki �ok fazla cin kullan�rsan�z 
	// bir s�re sonra ihmal edilir. Bu sorununun �stesinden gelmek i�in clear kullanabilirsiniz.

	// algebratik fonksiyon ��z�c�
	// denklem �rne�i; x + 4 = 9 -> x i�in ��z
	// x daima 1. dereceden olacak. 
	auto StringToVector = [](std::string theString, char separator) {
		std::vector<std::string> vecsWords;
		std::stringstream ss(theString);
		std::string sIndivStr;
		while (getline(ss, sIndivStr, separator))
			vecsWords.push_back(sIndivStr);
		return vecsWords;
	};
	auto SolveForX = [StringToVector](std::string equation) {
		std::vector<std::string> vecEquation =
			StringToVector(equation, ' ');
		// Convert strings to int
		int num1 = std::stoi(vecEquation[2]);
		int num2 = std::stoi(vecEquation[4]);
		int xVal = num2 - num1;
		std::cout << "x = " << xVal << "\n";
	};
	std::cout << "Enter an equation to solve ";
	std::string equation = "";
	// io operasyonlar�n� ayr�nt�s�yla anlatmad�m ama e�erki �ok fazla cin kullan�rsan�z 
	// bir s�re sonra ihmal edilir. Bu sorununun �stesinden gelmek i�in �zellikle getline kullanmak �zere ignore kullanabilirsiniz.
	// std::cin.ignore(256,' ');   // 256 karakter umursama taki bo�luk karakteri gelene kadar.
	cin.ignore(); // eski girdileri umursamadan yoluna devam eder. 
	getline(std::cin, equation); // cin.getline(equation,50); // sadece 50 karakter alacak.
	//std::cin >> equation;
	SolveForX(equation);

}

ia yinelemeliVEas�r�Y�klemeli() {
	// yinelemeli fonksiyonlar�ndaki en b�y�k tehlike "stack overflow" yani ayr�lan haf�zan�n yetmemesidir.
	// hata ay�klamas� zordur.
	// genelde yava� �al���r fakat bazen tek ��z�m yoludur. Yeni ��kan programlama dillerinde olduk�a h�land�r�lm�� bir i�lemdir.
	// lambda fonksiyonlar� yinelemeli kullanmak �zere �nceen std::functional olarak tan�mlanmal� ve ykalama listesine referans olarak eklenmelidir.

	/*
	 Neden bu kadar �ok lambda kulland�m? https://stackoverflow.com/q/13722426/341970
	 Lambda fonksiyonlar normal fonksiyonlardan daha iyi optimize edilir.
	 Kendileri birer nesne olarak g�r�l�r ve inline yapmak daha da kolayla��r. �a�r� y���nlar� azal�r ve program h�zlan�r.
	*/
	std::cout << "--- yinelemeliVEas�r�Y�klemeli fonksiyonu ---" << std::endl;
	auto counter = []() {
		std::function<void(int)> count = [&count](int c) {
			if (c == 0)
				return;
			// else demeye gerek g�rmedim.
			cout << "hello" << c << endl;
			count(--c);
			cout << c << endl;
			return;
		};
		std::cout << "--- counter fonksiyonu ---" << std::endl;
		count(5);
	};

	auto somefunc = []() {
		auto doubler = [](int a)->int {
			return a * a;
		};

		auto inc = [](int a)->int {
			return ++a;
		};
		std::function<int(int, int)> sum; // lambda de�eri yakalama listesine girmesi i�in bir de�i�ken olarak tan�mlanmal�d�r. yoksa yinelemeli lambda fonksiyonu derlenemez.
		sum = [doubler, inc, &sum](int a, int b)->int {
			return a > b ? 0 :
				doubler(a) + sum(inc(a), b); // if-elseden daha az kod �retiliyor. Daha h�zl� olmas� muhtemel.
		};
		std::cout << "--- somefunc fonksiyonu ---" << std::endl;
		std::cout << sum(1, 10) << std::endl; // 385
		std::cout << sum(25, 7) << std::endl; // 0
	};

	auto sumrec = []() {
		std::cout << "--- sumrec fonksiyonu ---" << std::endl;

		vector<int> v(10);
		std::iota(v.begin(), v.end(), 3);
		std::function<int(int)> sum2;
		sum2 = [&v, &sum2](int x)->int {
			return v.back() + sum2(v.back() - 1);
		};
		for (auto&& i : v) std::cout << i << ", ";
		yenisat�ryaz;
	};

	auto morerec = []() {
		std::cout << "--- morerec fonksiyonu ---" << std::endl;
		int n = 4;
		std::function<int(int)> factorial;
		factorial = [&factorial](int n) {
			return n > 1 ? (n * factorial(n - 1)) : 1;
		};
		cout << "Factorial of " << n << " = " << factorial(n) << std::endl;

		std::function<int(int)> sumto;
		sumto = [&sumto](int n) {
			return n > 1 ? n + sumto(n - 1) : 1;
		};
		cout << "sumto of " << n << " = " << sumto(n) << std::endl;
		/* n=1 -> 1
		 n=2 -> 2
		 n=3 -> 6
		 n=4 -> 10 */

		 // template konusuna gelince bu fonksiyon �zerinde tekrar duraca��m.
		std::function<int(int)> fibonacci;
		fibonacci = [&fibonacci](int n) {
			return n < 2 ? n : fibonacci(n - 1) + fibonacci(n - 2);
		};
		cout << "fibonacci of " << n << " = " << fibonacci(n) << std::endl;

		std::function<bool(int)> isPrime;
		isPrime = [&isPrime](int p) { // ikinci parametreyi 
			std::function<bool(int, int)> Prime;
			Prime = [&Prime](int kontroledilen, int kontrolbaslang�c� = 3) {
				return kontrolbaslang�c� * kontrolbaslang�c� > kontroledilen ? true : // asl�nda karek�k�nden k���k olmas�n� kpntrol ediyoruz.
					kontroledilen % kontrolbaslang�c� == 0 ? false : // tam b�l�m ifadesini temsil ediyor.
					Prime(kontroledilen, kontrolbaslang�c� + 2); // 2 d���nda �ift say� yoktur.
			/*if (kontrolbaslang�c� * kontrolbaslang�c� > kontroledilen) return true;
			else if (kontroledilen % kontrolbaslang�c� == 0) return false;
			return Prime(kontroledilen, kontrolbaslang�c� + 2); */
			};
			return p == 2 ? true : Prime(p, 3);
			/*if (p == 2) return true; // sadece 2 say�s� asald�r.
			return Prime(p,3);*/
		};
		/*
		std::boolalpha	 -> false -> 0
		std::noboolalpha -> true  -> 1
		*/
		int primex = 47;
		cout << "is prime? " << primex << " = " << std::boolalpha << isPrime(primex) << std::noboolalpha << std::endl;
	};

	auto sortrec = []() {
		/*
		* c++ stream i�lemlerinde varsay�lan �ekilde haf�zay� s�n�rlar.
		* performans sebeplerinden e�er stdout ��kt� haf�zas� dolarsa c++ otomatik olarak "std::cout.flush();" komutunu �al��t�r�r.
		* sorunun �stesinden gelmek �zere stdout buffering(haf�zaya almak) i�lemini durdurmak gerekir.
		* "setvbuf" c++ stream bufferlar�n� ayarlamaya yarayan fonksiyondur. http://www.cplusplus.com/reference/cstdio/setvbuf/
		* dosya okumakurken, ekrana yazd�r�rken ve kullan�c�dan veri al�rken buffering i�leminde kullan�l�r.
		* _IONBF = buffering yok demektir.
		*/
		/*
		* http://www.cplusplus.com/reference/cstdio/setvbuf/
		FILE *pFile;
		pFile=fopen ("myfile.txt","w");
		setvbuf ( pFile , NULL , _IOFBF , 1024 ); // 1024 byte pe�in pe�in ayr�ld�.
		 // File operations here
		fclose (pFile);

		*/
		std::setvbuf(stdout, NULL, _IONBF, 0); // performans sebeplerinden �t�r� gerekmedik�e uygulanan bir y�ntem de�ildir.
		// son al��t�rma; bubble sort
		/*
		// Iterative Bubble Sort
		bubbleSort(arr[], n)
		{
		//for (i = 0; i < n-1; i++) // i�te buradaki d�ng� fadesini kald�r�p yinelemeli fonksiyon haline getirmemiz gerekiyor.

		// Last i elements are already in place
		for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1])
		swap(arr[j], arr[j+1]);
		}
		*/
		std::cout << "--- sortrec fonksiyonu ---" << std::endl;
		auto bubbleSort = [](std::vector<int>& vec) { // e�erki fonksiyon ...(n-1) ifadesiyle gidiyorsa kullan�m� basitle�tirmek �zere  b�yle bir y�nteme ba�vurulabilir.
			auto swapedCount = 0; // T�m dizi tarand� ve swap i�lemine gerek kalmad�ysa, dizi s�ralanm�� ise d�ng� devam etmesin.
			std::function<void(std::vector<int>&, int)> bubbleSort_n;
			bubbleSort_n = [&swapedCount, &bubbleSort_n](std::vector<int>& vec, int n) {
				if (n == 1)	return; // temel durum ifadesi
				const auto& loopMax = n - 1;
				for (auto&& i = 0; i < loopMax; ++i) { // bubble sort i�in bir ge�i�. en b�y�k eleman s�ras�na girdi. bu ge�i�ten sonra recursif olacak.
					auto& ilk = vec.at(i);
					auto& sonraki = vec.at(i + 1);
					if (ilk > sonraki) {
						std::swap(ilk, sonraki);
						swapedCount = 0;
					}
					else { // swap(de�i�-toku�) i�lemi ger�ekle�mez ise s�ralama bitmi� demektir.
						++swapedCount;
						if (swapedCount == loopMax) return;
					}
				}
				bubbleSort_n(vec, n - 1); // son eleman
			};
			bubbleSort_n(vec, vec.size());
		};
		auto printArray = [](auto vec) -> void { // d�n�� tipi "void" olarak belirledim. art�k derleme hatas� yok.
			for (int v : vec)
				printf("%d ", v);
			printf("\n");
		};
		std::vector<int> vec(10); //vec= { 64, 34, 25, 12, 22, 11, 90 };
		size_t min = 10;
		size_t max = 100;
		//srand(static_cast <unsigned> (time(0))); // eski versiyon
		// https://en.cppreference.com/w/cpp/numeric/random
		// modern c++ ile rastgele say� �retmek. Yeni versiyonla birden fazla da��l�mda beslemede y�ksek h�zl� rastgele say� �retebiliyoruz.

		// b�t�n kodlar� Uret.h i�inde toplad�m.
		//std::random_device rd; // 
		//std::default_random_engine er(rd());
		//std::uniform_int_distribution<int> dis(min, max);
		//std::generate(vec.begin(), vec.end(), [&min,&max,&er,&dis]() {
		//	//std::mt19937 rng;
		//	//rng.seed(std::random_device()());
		//	////rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
		//	//std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
		//	//
		//  //min + std::rand() % ((max + 1) - min);
		//  //
		//	//return min + static_cast <int> (std::rand()) / (static_cast <int> (RAND_MAX / (min - max))); // min <= randomNumber => max say� �retir.
		//	//random_number = std::experimental::randint(min, max); // deneysel y�ntem.
		//	//
		//	// tam olarak istenilen rastgelelik sa�lanm�yor.
		//	//static std::default_random_engine e;
		//	//static std::uniform_int_distribution<int> dis(min, max); // min <-> max
		//	//return dis(e)%rand();
		//	//
		//	//auto e = initialize_twister(); // initialize_twister.h i�indeki fonksiyon
		//	//std::uniform_int_distribution<int> dis(min, max);
		//	//return dis(e);
		//	return dis(er);
		//});
		rastgeleUret<int>(vec, 10, min, max);

		// "type safety" olarak bilinen ilkeyi atlam�� oluyoruz.
		// c++ standart k�t�phanesi bizi bu yanl��tan kurtar�yor. std::array
		// int n = sizeof(vec) / sizeof(vec[0]); // Hemen hemen t�m kaynaklarda bu �ekilde boyut bulmaya �al���yor ama yanl��.
		bubbleSort(vec);
		printf("Sorted array : \n");
		printArray(vec);
	};

	auto vectorGuzelYaz = []() {
		fonksiyonuyaz("vectorGuzelYaz");
		/* Yinelemeli de�il ama g�zel �al��ma
		// ----- PROBLEM PRINT ARRAY HORIZONTALLY -----
		Example:
			------------------
			|  0  |  1  |  2  | -> indexes
			------------------
			| 10  |  8  |  2  | -> values
			------------------
		*/
		auto PrintHorzVector = [](std::vector<int>& theVec) {
			int dashes = std::ceil(theVec.size() * 6);
			for (int n = 0; n < dashes; n++)
				std::cout << "-";
			yenisat�ryaz;

			for (int n = 0; n < theVec.size(); n++)
				printf("| %2d  ", n);
			std::cout << "|\n";

			for (int n = 0; n < dashes; n++)
				std::cout << "-";
			yenisat�ryaz;

			for (int n = 0; n < theVec.size(); n++)
				printf("| %2d  ", theVec[n]);
			std::cout << "|\n";

			for (int n = 0; n < dashes; n++)
				std::cout << "-";
			yenisat�ryaz;
		};

		std::vector<int> theVec(12);  //{ 10,8,2,5,9,11,6,14 };
		size_t min = 0; size_t max = 20;
		rastgeleUret<int>(theVec, 12, min, max);

		PrintHorzVector(theVec);
	};

	// hepsini test et.
	counter();
	somefunc();
	sumrec();
	morerec();
	sortrec();
	vectorGuzelYaz();
}

ia lambdaDerinlemesine() {
	// Burada Lambda fonksiyonlar� ve biraz stl ile c++ fonksiyonel programlamaya de�inece�im.
	// L�tfen algorithm k�t�phanesini kullan�n.
	// Lambda fonksiyonlar�n� stl ve fonksiyonel programlamada olduk�a �nemli yeri vard�r.
	// Lambda fonksiyonlar� i�ine "[]" statik tan�ml� ba�ka bir fonksiyon alamaz.
	/*
	 * Lambda fonksiyonlar� tan�t�m�
	 auto lambdaFonksiyonu = [lambda oldu�unu ifade eder](parametre listesi) -> (d�n�� tipi)
	 { <kodlar buraya yaz�l�r.>
	 };
	 ** <Yakalama Kurallar� "[]">
	 * lambda fonksiyonu "[]" ifadesiyle ba�lar. e�er lambda d���ndan bir de�eri yakalamak istiyorsan�z [var1,var2] diye i�ine yazmal�s�n�z.
	 * "[=]" i�ine yaz�lan "=" ifadesi d���ndaki t�m verileri i�ine kopyalar.
	 * "[&]" i�ine yaz�lan "&" ifadesi d���ndaki t�m verileri i�ine referans olarak al�r.
	 * "[var1,&]" i�ine yaz�lan "&" ifadesi d���ndaki t�m verileri i�ine referans olarak al�r -> fakat var1 de�erini kopyalar.
	 * "[&var1,=]" i�ine yaz�lan "&" ifadesi d���ndaki t�m verileri i�ine kopyalar -> fakat var1 de�erini referans olarak al�r.
	 * C++17 ifadeleriyle art�k oop ifadelerindeki "this" i�aret�isi de i�ine al�nabilir.
	 ** </Yakalama Kurallar� "[]">
	 *
	 ** "()" ifadesi normal fonksiyonlar gibi her t�rl� parametreyi tan�mlamakta kullan�l�r.
	 * Lambda fonksiyonlar� "Template" ile kullan�lmaz. Template yerine k�s�tl�da olsa parametre t�rleri "auto" s�zc��� kullan�labilir.
	 *
	 ** "-> ()" ok ifadesinden sonra d�n�� tipi belirtilir. fakat genelde gerekli de�ildir. C++17 d�n�� tipini bir�ok durumda derleme zaman�nda belirleyebilir.
	 *
	 ** "{}" kodlar s�sl� parantez i�ine yaz�l�r.
	 *
	 ** Lambda fonksiyonlar� static, extern, inline, ...const, [[noreturn]], vb. fonksiyonlar�n ald��� tak�lar� alabilir.
	 *
	 ** Lambda fonksiyonlar�n� tipi "std::function<d�n�� tipi(parametre tip listesi)>"
	 *
	 ** Lambda fonksiyonlar� derleyici nezlinde birer nesne t�r�ndedir. �ok daha iyi optimize etmesi muhtemeldir.
	 * Fakat uzun ifadeler i�in yinede normal fonksiyonlar� kullanman�z� tavsiye ederim. B�ylece meta programlama kullanabilirsiniz ve
	 derleme zaman� �zelliklerinden daha fazla yararlan�rs�n�z.
	 *
	*/
	auto asc = [](auto ilk, auto sonraki) { return ilk < sonraki; }; // ascending , artan
	auto desc = [](auto ilk, auto sonraki) { return ilk > sonraki; }; // descending , azalan

	auto s�rala = [=]() {
		fonksiyonuyaz("<s�rala>");
		auto theVec = rastgeleUret<int>(12, 20, 50);
		ekranayaz << "before sort:"; /* => */ printAll(theVec);
		std::sort(theVec.begin(), theVec.end(), asc);
		ekranayaz << "after sort:"; /* => */ printAll(theVec);
		yenisat�ryaz;
		fonksiyonuyaz("</s�rala>");
	};

	auto copyIf = [=]() {
		fonksiyonuyaz("<copyIf>");
		// ba�lang�� noktas�, biti� noktas�, copyalanacak ba�lang�� noktas� ve kopyalama �art� lambda
		auto theVec = rastgeleUret<int>(12, 20, 50);
		std::vector<decltype(theVec)::value_type> evenNums; // value_type == int
		ekranayaz << "before copy_if:"; /* => */ printAll(theVec);
		std::copy_if(theVec.begin(), theVec.end(), std::back_inserter(evenNums), [](auto even) {return !(even % 2); });
		ekranayaz << "after copy_if:"; /* => */ printAll(evenNums);
		yenisat�ryaz;
		fonksiyonuyaz("</copyIf>");
	};

	auto fOrEaCh = []() {
		auto theVec = rastgeleUret<int>(12, 20, 50);
		auto sum = 0;
		ekranayaz << "before copy_if:"; /* => */ printAll(theVec);
		std::for_each(theVec.begin(), theVec.end(), [&sum](auto x) {return sum += x; });
		ekranayaz << "sum: " << sum;
		yenisat�ryaz;
	};

	auto bolunenleriTopla = []() {
		yenisat�ryaz;
		fonksiyonuyaz("<bolunenleriTopla>");

		auto theVec = rastgeleUret<int>(15, 20, 50);
		std::vector<decltype(theVec)::value_type> bolunenler; // value_type == int
		// Girilen N say�s�na b�l�nenlerin listesini ��kart
		ekranayaz << "bolen ile b�l�nenlerin listesi: ";
		auto bolen = 1;
		std::cin >> bolen;
		yenisat�ryaz;
		ekranayaz << "theVec: "; /* => */ printAll(theVec);
		std::copy_if(theVec.begin(), theVec.end(), std::back_inserter(bolunenler), [bolen](auto say�) {return !(say� % bolen); });
		ekranayaz << "bolunenler: "; /* => */ printAll(bolunenler);
		yenisat�ryaz;
		// bolunenler listesindeki elemanlar�n toplam�
		auto sum = 0;
		std::for_each(bolunenler.begin(), bolunenler.end(), [&sum](auto x) {return sum += x; });
		ekranayaz << "sum: " << sum;
		yenisat�ryaz;

		fonksiyonuyaz("</bolunenleriTopla>");
	};

	auto doubler = []() {
		fonksiyonuyaz("<doubler>");
		auto theVec = rastgeleUret<int>(12, 10, 100);
		std::vector<decltype(theVec)::value_type> doubleee;
		std::cout << "iki ile �arp�lmadan �nce: "; printAll(theVec);
		std::for_each(theVec.begin(), theVec.end(), [&](auto& vec) {doubleee.push_back(vec); });
		std::cout << "iki ile �arp�ld�ktan sonra: "; printAll(doubleee);
		fonksiyonuyaz("</doubler>");
	};

	auto vectorleriTopla = []() {
		/*
		for_each, for_each_n, apply, transform benzerdir ama farklar� vard�r.
		Bu fonksiyon kullan�m� garip gelebilir.
		girdinin ba�lang�c�, girdinin biti�i, ��kt� ba�lang�c� ve fonksiyon
		yada
		1. girdinin ba�lang�c�, 1. girdinin biti�i, 2. girdinin ba�lang�c�, ��kt� ba�lang�c� ve fonksiyon

		*/
		fonksiyonuyaz("<vectorleriTopla>");
		auto vec1 = rastgeleUret<int>(5, 10, 100);
		std::vector<decltype(vec1)::value_type> vec2 = { 1,2,3,4,5 };
		std::vector<decltype(vec1)::value_type> sumdepola(vec1.capacity());
		std::transform(vec1.begin(), vec1.end(), vec2.begin(), sumdepola.begin(),
			[](auto x1, auto x2) { return x1 + x2; });
		std::cout << "sum: "; printAll(sumdepola);
		fonksiyonuyaz("</vectorleriTopla>");
	};

	s�rala();
	copyIf();
	fOrEaCh();
	bolunenleriTopla();
	doubler();
	vectorleriTopla();
	auto fibgene = fibUret<int>(10);
	std::cout << "generated fibonacci series: "; printAll(fibgene);

	std::cin.get();
}

ia oops() {
	/*
		�� farkl� �ok bilinen temel programlama �ekli vard�r. imperative, functional, oops
		Bu programlama stillerinden hi�birinin bilgisayar i�in fark� yoktur, hepsi derlendi�inde ikili koda derlenir.
		Sadece baz� problemlerin ��z�m�nde baz� programlama tarzlar� kolayl�k sa�lar.
		* C++ �� tarzda programlamay� destekler. Yeni versiyonlar geldik�e fonksiyonel programlama ��eleri artmaktad�r.
	* oop = object oriented programing
	bu �ekildeki programlamada nesne i�ine gerekli t�m de�i�kenler ve bu de�i�kenlerin davran��lar�n�
	belirleyen fonksiyonlar yaz�l�r. Gerekli veriler ve fonksiyonlar tek �at� alt�nda topland���ndan kullan�m�
	kolayla��r. Nesne tasar�m� ile hem haf�za hemde i�lev organizasyonu kolayla��r.
	Polimorphizm, inheritance, class, object, vb. kavramlar bu tarz�n ��eleridir.

	G�n�m�ze kadar oops tabanl� diller reva�tayd� fakat veri i�lemede fonksiyonel tarz�n kullan�m�n�n daha kolay
	oldu�u g�r�ld�. �ok �ekirdekli i�lemciler fonksiyonel tarz ile programlamak daha anla��l�rd�r.
	*/
	auto basitClass = []() {
		// buradaki de�i�kenler, fonksiyonlar ve tan�mlar "Classlar" filtresindedir.
		// Animal.h ve Animal.cpp dosyas�na bak�n
		Animal animal1; // varsay�lan olu�turucu �al��acak.
		animal1.PrintAll(true); // "", 0, 0 yaz�rmas� bekliyorum.
		animal1.SetName("maymum");
		animal1.SetHeight(50);
		animal1.SetWeight(20);
		animal1.PrintAll(true); // ayarlanm�� haliyle 

		Animal animal2("fil", 200, 800);
		auto numAnimals = Animal::GetNumOfAnimals();
		std::cout << "Ka� tane Animal var? " << numAnimals << std::endl;

		// Dog olu�turucu
		Dog kopek("at�l kurt", 38, 15, "wooof"); // dog ayn� zamanda Animal class�n� olu�turur.
		kopek.PrintAll(true);
		//Dog olu�tuktan sonra acaba ka� tane Animal olu�tu.
		numAnimals = Animal::GetNumOfAnimals();
		std::cout << "Ka� tane Animal var? " << numAnimals << std::endl;

		// t�m classlar y�k�c�lar taraf�ndan olu�turulmaz s�ras�n�n tersi ile y�k�l�r.
		// y�k�lma s�ras�: ~dog(at�l kurt), ~animal(at�l kurt), ~animal(fil), ~animal(maymum)
	};

	auto sava�Meydan� = []() {
		class savasc� {
		private:
			int attkMax;
			int blockMax;
		public:
			std::string name;
			int can;
			savasc�(std::string name, int can, int attkMax, int blockMax) {
				this->name = name; this->can = can;
				this->attkMax = attkMax; this->blockMax = blockMax;
			}
			int boostRand() {
				// ufak bir eklenti.
				// matematiksel �art sa�lan�rsa blok ve atak artacak.
				auto& a = this->attkMax;
				auto& b = this->blockMax;
				auto norm2 = std::sqrt(std::pow(a, 2) + std::pow(b, 2));
				auto sart = norm2 > 35; // berbat bir ��z�m
				return sart ? std::rand() % static_cast<uint64_t>(std::ceil(norm2)) : 0;
			}

			// The attack and block amount will be random
			int Attack() {
				return std::rand() % this->attkMax;
			}
			int Block() {
				return std::rand() % this->blockMax;
			}
		};

		class CenkMeydani {
		public:
			// sava� sava���lar�n can� "can < 0" �art� sa�lanana kadar devam edecek.
			static void Fight(savasc�& savasc�1, savasc�& savasc�2) {
				while (true) {
					// string kar��la�t�rma sonucu ayn� ��kt���nda "null" yani 0 verir ama asmde ...==0 daha fazla kod �retiyor.
					if (!CenkMeydani::GetAttackResult(savasc�1, savasc�2).compare("Oyun Sonu")) {
						std::cout << "--- Oyun Sonu ---\n"; break;
					}
					if (!CenkMeydani::GetAttackResult(savasc�2, savasc�1).compare("Oyun Sonu")) {
						std::cout << "--- Oyun Sonu ---\n"; break;
					}
				}
			}

			static std::string GetAttackResult(savasc�& savasc�A, savasc�& savasc�B) {
				// Get random attack & block amounts and calculate damage
				auto savasc�Aboost = savasc�A.boostRand(); int savasc�AAttkAmt = savasc�A.Attack() + savasc�Aboost;
				auto savasc�Bboost = savasc�B.boostRand(); int savasc�BBlockAmt = savasc�B.Block() + savasc�Bboost;
				int damage2savasc�B = ceil(savasc�AAttkAmt - savasc�BBlockAmt);

				// Change can total if > 0 and output changes
				damage2savasc�B = (damage2savasc�B <= 0) ? 0 : damage2savasc�B;
				savasc�B.can = savasc�B.can - damage2savasc�B;
				printf("%s sald�r�r %s %d hasar al�r.\n", savasc�A.name.c_str(), savasc�B.name.c_str(), damage2savasc�B);
				printf("%s -> %d can�\n", savasc�B.name.c_str(), savasc�B.can);
				printf("%s ald��� boost %d\n", savasc�A.name.c_str(), savasc�Aboost);

				// "can < 0" �art� bir kez sa�land� m� "Oyun Sonu" d�n���yle biter.
				if (savasc�B.can <= 0) {
					printf("%s �ld� %s kazand�\n", savasc�B.name.c_str(), savasc�A.name.c_str());
					return "Oyun Sonu";
				}
				else { return "Yeniden Sava�"; /* Gerek yok ama hi�bir �ey d�nmemesi hataya sebep olabilir. */ }
			}
		};

		srand(time(NULL)); // Rastgelelik sa�lan�yor.
		// Sava���lar�n isimleri ve �zellikleri verilir.
		savasc� Batman("Batman", 100, 35, 15);
		savasc� Superman("Superman", 125, 25, 10);
		// Sava� bitene kadar devam eder.
		CenkMeydani::Fight(Batman, Superman);

	};

	auto structYap�s� = []() {
		struct shape // struct, class ile �ok benzer. veriler varsay�lan olarak "public" tir.
		{ // Teknik ayr�nt�lar�n� en.cppreferance sitesinden okuyabilirsiniz.
			double lenght, witdh;
			shape(double le = 1, double wi = 1) : lenght{ le }, witdh{ wi } // fonksiyon g�vdesine gerek kalmad�.
			{}
			double area() { return lenght * witdh; }
		private: // private olabiliyor. 
			int id;
		};
		struct circle : shape // varsay�lan olarak "public" dir.
		{
			circle(double wi) { this->witdh = wi; }
			double area() { return std::_Pi * std::pow((witdh / 2.0), 2.0); }
		};

		shape �ekil(10, 20);
		std::cout << "�ekil alan�: " << �ekil.area() << std::endl;
		shape dikd�rtgen{ 15,22 };
		std::cout << "dikd�rtgen alan�: " << dikd�rtgen.area() << std::endl;

		circle daire(5);
		std::cout << "daire alan�: " << daire.area() << std::endl;
	};

	auto friendClass = []() {
		class musteri {
		private:
			friend class veriCek; // "private" olsa da friend oldu�undan eri�im sa�lanabilir.
			std::string name; // "private" oldu�u i�in eri�im sa�lanamaz.
		public:
			musteri(std::string sname) : name{ sname } {}
		};

		class veriCek
		{
		public:
			static std::string GetName(musteri& must) { return must.name; }
		};

		musteri m{ "selami" };
		veriCek v;
		std::cout << "Name: " << v.GetName(m) << std::endl;
	};

	auto Polimorphizm = []() {
		/*
		�ok bi�imlilik java ve C# dillerinde daha iyi ifade edilse de c++ a�a�� kal�r yan� yok.
		Temel kelime "virtual" kelimesidir.

		*/
		class shape
		{
		protected:
			double height, witdh;
		public:
			shape() = default; // bu kelime "shape daire()" �eklindeki bo� kullan�mda derleyicinin yap�c�y� otomatik olu�turmas�n� sa�lar.
			shape(double he) : height{ he }, witdh{ he } {}
			shape(double he, double wi) : height{ he }, witdh{ wi } {}
			// virtual kelimesiyle art�k shape::area() yada using shape::area ullanmak pek gerekli de�il.
			// pratikte tekrar tekrar fonksiyonu tan�mlayabilmemizi sa�lar.
			// virtual kelimesiyle tan�mlanan fonksiyonlar binary i�inde "V table" ile kaydedilir.
			// sadece taban(base) class i�ine yaz�lmas� yeterlidir.
			virtual double area() { return height * witdh; }
		};
		class circle : public shape
		{
		public:
			circle(double rad) : shape(rad) {}
			double area() { return std::_Pi * std::pow(witdh / 2, 2); }
		};

		auto GetTheShape = [](shape& sh) { std::cout << "area: " << sh.area() << std::endl; };
		//Polimorphizm ba�l�yor dikkaaat!
		shape kare(10, 10);
		GetTheShape(kare);
		circle daire(15);
		GetTheShape(daire);


	};

	auto fullVirtualPolimorphizm = []() {
		// Te�ekk�r ederim. �ok iyi bir �rnek
		// http://www.newthinktank.com/2018/04/c-tutorial-11-2/
		// override kullanman�z� tavsiye ederim.
		class Shape {
		public:
			// java ve c# interface kelimesinin kar��l��� olarak "full virtual class" olu�turulur ve
			// fonksiyon g�vdeleri sorunsuz dekilde tekrardan yaz�labilir yoksa linker hatalar� alabilirsiniz.
			virtual double Area() = 0; // tam anlam�yla sanal bir s�n�f.
		};

		class Circle : public Shape {
		protected:
			double width;
		public:
			Circle(double w) : width{ w } {}
			// Override Area()
			// override ile temel s�n�f�n virtual oldu�unu kontrol eder.
			double Area() override { return 3.14159 * std::pow((width / 2), 2); }
		};

		class Rectangle : public Shape {
		protected:
			double height, width;
		public:
			Rectangle(double h, double w) : height{ h }, width{ w } {}
			// Override Area()
			// override ile temel s�n�f�n virtual oldu�unu kontrol eder.
			double Area() override final { return height * width; }
		};

		class Square : public Rectangle {
		public:
			Square(double h, double w) : Rectangle(h, w) {}
			/* // Rectangle temel s�n�f olmad���ndan derleme hatas�
			double Area() override{
			return height * 2;
			}
			*/
		};

		// do�ru Area() otomatik kullan�l�r.
		auto ShowArea = [](Shape& shape) { std::cout << "Area : " << shape.Area() << "\n"; };

		Rectangle rectangle(10, 5);
		Circle circle(10);
		ShowArea(rectangle);
		ShowArea(circle);

		Square square(10, 10);
		ShowArea(square);

	};

	basitClass();
	sava�Meydan�();
	structYap�s�();
	friendClass();
	Polimorphizm();
	fullVirtualPolimorphizm();

}

ia overloadFileIO() {
	auto overload = []() {
		/*
		<h1> Operator overload, File I/O i�lemleri </h1>

		* "Overload" yani a��r� y�kleme nedir ve nas�l yap�l�r? Overload ile Override kar��t�r�lmamal�d�r.
		* "Override" ayn� girdi, ��kt� ve fonksiyon isimle tekrardan yazmak manas�na gelir.
		Derleyici hata yada uyar� mesaj� verebilir. Bu y�zden Modern C++ ile virtual,overload,final kelimeleri gelmi�tir.
		* A��r� y�kleme i�lemi, ismi ayn� olan fonksiyonlar� veya operatorleri farkl� giri� ��k��larla farkl�
		g�revlerde kullanmak �zere yeniden yazmakt�r. Fazladan tan�mlay�c� kelimeye ihtiya� duymadan
		derleyici uygun fonksiyonu se�erek kullanabilir.
		*/
		kutucuk kutu1(5, 5, 5), kutu2(10, 10, 10);
		auto pre = ++kutu1;
		std::cout << "pre-increment before: " << pre << std::endl; //operator const char*() sayesinde
		std::cout << "pre-increment after: " << kutu1 << std::endl; //operator const char*() sayesinde
		auto post = kutu1++;
		std::cout << "post-increment before: " << post << std::endl; //operator const char*() sayesinde
		std::cout << "post-increment after: " << kutu1 << std::endl; //operator const char*() sayesinde

		kutu2.operator++(); // ayn�s�.
		std::cout << "operator const char*() sayesinde" << kutu2.operator const char *() << std::endl;

		std::cout << "kutu1 + kutu2= " << kutu1 + kutu2 << std::endl;
		std::cout << "kutu2.lenght" << kutu2[0] << std::endl; // operator fonksiyonuna dikkat!
		std::cout.setf(std::ios::boolalpha); // bool veri yazd�rs�n.
		// "<<" operator�n� a��r� y�klemedi�im i�in parantez olmadan derlenmez. 
		std::cout << "kutular e�it mi?" << (kutu1 == kutu2) << std::endl;
		std::cout << "kutu1 k���k m�?" << (kutu1 < kutu2) << std::endl;
		std::cout << "kutu1 b�y�k m�?" << (kutu1 > kutu2) << std::endl;

		kutucuk kutu3 = kutu1;
		std::cout << "kutu3 atan� m�? " << kutu3 << std::endl;
	};

	auto fileIO = []() {
		/*
		<h1> File I/O == Dosya sistemi Giri�/��k�� </h1>

		* Dosya sisteminden kast�m sadece klas�rler ve ofis dosyalar�n�z de�il t�m giri� ve ��k��lar.
		* Dosya sistemi disklere ve di�er bellek t�rlerine ve t�m giri� ��k��lar� y�neten bir birimdir.
		* Her i�letim sisteminde farkl� bir dosya sistemi kullan�l�yor. Windows ntfs, Linux exfat(1,2,3,4)
		* Dosya giri� ve ��k�� h�z� i�letim sistemine ve bilgisayara ba�l�d�r, programlama diline de�il.
		programlama dili i�letim sistemine komutu verir ve sonucu al�r.
		* Usb ve monitor giri� ��k���da ayn� komutlarla sa�lanabilir fakat windows i�letim sisteminde win32api yada .net
		kullan�lmas� tavsiye ederim.

		* Tabi amac�m bu temel Modern c++ sonras�nda Qt anlatmak olacak ve Qt ile genelde ba�ka frame ihtiyac� duyulmuyor.
		* Qt ile giri� ��k�� i�lemi daha kolay.

		* T�rk�e karakter kaydetmek ve okumak uzun i� o y�zden �imdilik es ge�ece�im.

		*/

		const std::string& dosyaAd� = "birDosya.txt";
		/*
		* dosya ��k���n�n manas� ram yada ba�ka bir bellekten verilerin al�n�p
		dosyan�n olu�turulup i�ine veri kaydedilmesidir.*/
		std::ofstream writeToFile; // dosya ��k�� ak�m�
		std::string txtToFile;

		writeToFile.open(dosyaAd�, std::ios::out | std::ios::trunc); // ��k�� ve e�er veri varsa �zerine yaz.
		if (writeToFile.is_open()) {
			writeToFile << "Merhaba Dosya" << std::endl <<
				"G�n�n hay�r olsun." << std::endl <<
				"Yazd�klar�n Burada:\n";
			std::cout << "Dosya haz�r, yazmaya ba�layabilirsin." << std::endl;
			std::getline(std::cin, txtToFile);
			writeToFile << txtToFile;
			writeToFile.close();
		}
		else {
			std::cout << "dosya a��lamad�." << std::endl;
		}


		/* *dosya giri�i dosyadaki verilerin al�nmas� ve ram yada ba�ka bir belle�e kaydedilmesidir.*/
		std::ifstream readFromFile; // dosya giri� ak�m�
		std::string fileToText;

		readFromFile.open(dosyaAd�, std::ios::in);
		if (readFromFile.is_open()) {
			while (readFromFile.good()) { //good yani i�ler iyi gittii s�rece, 
				getline(readFromFile, txtToFile);
				std::cout << txtToFile << std::endl;
				// challenge from derek banas :)
				std::vector<std::string> c�mle = functionalStyle::StringToVector(txtToFile, ' ');
				auto sat�rdakiKelime = c�mle.size();
				std::cout << "Sat�rdaki kelime say�s�: " << sat�rdakiKelime << std::endl;
				auto karakterSayac� = 0;
				for (auto kelime : c�mle)
					for (auto karakter : kelime)
						++karakterSayac�;
				auto ortKelimeUzunluk = karakterSayac� / sat�rdakiKelime;
				std::cout << "Sat�rdaki ortalama kelime uzunlu�u: " << ortKelimeUzunluk << std::endl;

			}
			readFromFile.close();
		}




	};

	overload();
	fileIO();
}

ia ileriFonksiyonlar() {
	/*
	<h1> fonksiyonel programlama, fonksiyon parametreleri, vector fonksiyonlar� </h1>

	* Asl�nda bu zamana kadar hep fonksiyonlar� kuland�k. ancak daha ileri konular� g�rece�iz.
	* fonksiyonel prograglamlama idiomunu daha �nceden oops i�inde anlatm��t�m. l�tfen inceleyin.
	* c dilindeki fonksiyon i�aret�ilerinin aksine c++da fonksiyon objesi bulunuyor. std::function<...(...)>
	*/
	// fonksiyonlar.cpp
	auto fonksiyonel = []() {
		// 1. You can store functions as variables
		auto times2 = MultBy2;
		std::cout << "5 * 2 = " << times2(5) << "\n";

		// 2. Pass a function into a function
		std::cout << "6 * 2 = " << DoMath(times2, 6) << "\n";

		// 3. You can store functions in a vector
		// Create a vector using the function parameters
		// and then load the functions into the vector
		std::vector<std::function<double(double)>> funcs(2);
		funcs[0] = MultBy2;
		funcs[1] = MultBy3;
		std::cout << "2 * 10 = " << funcs[0](10) << "\n";

		// 4. ----- PROBLEM -----
		// Create a function that receives a list and a function
		// The function passed will return True or False if a list
		// value is odd.
		// The surrounding function will return a list of odd
		// numbers
		std::vector<int> listOfNums{ 1,2,3,4,5 };
		std::vector<int> oddList = ChangeList(listOfNums, IsItOdd);
		std::cout << "List of Odds\n";
		for (auto i : oddList) {
			std::cout << i << "\n";
		}
		// ----- 4. END OF PROBLEM -----

		// ----- 5. PROBLEM -----
		// Rastgele toplamda 100 tane karakter listesindeki karakterleri �ret ve ka� tane �retildi�ini say.!
		std::vector<char> possibleValues{ 'H', 'T' };
		auto N = 100;
		std::vector<char> hAndTList = GetHAndTList(possibleValues, N);
		const auto& HeadNumbers = GetNumberOfMatches(hAndTList, 'H'); // Tekrar tekrar kodun �al��t�r�lmas� ho�uma gitmiyor.
		const auto& TailNumbers = N - HeadNumbers;
		std::cout << "Number of Heads : " << HeadNumbers << "\n";
		std::cout << "Number of Tails : " << TailNumbers << "\n";
		// ----- 5. END OF PROBLEM -----
	};
	fonksiyonel();
}

template<typename type> // template ;)
type doubler(type num) { return num * 2; }
ia templateVeItarator() {
	fonksiyonuyaz("templateVeItarator");
	/*
	<h1> D��ar�dan dosya dahil etmek, �n i�lemci, "TEMPLATE"(iskelet), iterator,... </h1>

	* D��ar�dan header yada cpp dosyalar�n� dahil etmeyi zaten s�rekli yap�yoruz.
	#include <> yada #include "" ile ba�l�k dosyalar� derleme zaman�nda dahil ediliyor. Olduk�a basit.
	Program yap�m�n� par�alara ay�rabilmemizi sa�l�yor b�ylece kodlar daha anla��l�r oluyor.

	* �n i�lemci= derleme zaman�nda yap�lan i�lemleri yapan i�lemcidir.
	derleme zaman�nda kod kontrol� -> #ifdef-#endif, #ifndef-#endif
	derleme zaman� sabit ve fonksiyon tan�mlama yada ad de�i�tirme -> #define(pek sevilmiyor ve eskide kald�. constexpr yerini ald�.)
	derleme zaman� dosya dahil etmek -> #include
	derleme zaman�nda derleyiciye �zel komut iletmek -> #pragma(buradaki komutlar her derleyicide de�i�ebilir.)

	* Template(iskelet) yine derleme zaman� yap�lan bir tak�m i�lemlerdir. Fonksiyonlar� her defas�nda farkl�
	veri tiplerine uygun yazmaktan kurtar�r. Bir fonksiyon iskeleti haz�rlan�r ve istenilen veri tipleriyle
	kullan�l�r ve derleyici fonksiyonu kullan�lan her veri tipi i�in �retir. Derleme h�z�n� azalt�r ama
	kod yazma h�z�n� artt�r�r.

	* Iterator veri dizisi �zerinde dola�maya yarayan ara�t�r. Modern C++ ile varsay�lan bir �zellik olmu�tur.
	iteratorler stl i�indeki hemen hemen t�m "container" saklay�c�lar i�in standartt�r. Yani haf�zaya eri�imi
	t�m tutucular i�in standartla�t�rm�� oluyoruz.

	*/

	auto headerKorumas� = []() {
		fonksiyonuyaz("headerKorumas�");
		/*
		Header dosyalar�n� tan�mlarken �unlara dikkat edin!
		* .h, .hpp,.hxx gibi dosya t�rlerini include ile kullanmay�n. �n i�lemci dosya t�r�ne bakmadan dahil eder.
		* e�er projenizde iki ba�l�k dosyas� birbirleirne ba�l� ise ilkini ikincisine ikincisini ilkine
		dahil etmeyin. B�le bir davran�� program �al��sa bile ve Modern derleyici ile �al���yor olsan�z bile
		bile b�y�k sorunlara yol a�abilir. Sorunun ad� "cyclic referance" olarak ge�iyor.
		SORUNUN �RNE�� "Yararl�Fonksiyonlar.h" ve "functionalStyle.h" ARASINDA BEL�RTT�M.
		* ikinci sorunla ba� etmenin en iyi yollar�ndan biri "ba�l�k korumas�"d�r.
		*/
		// Animal class� Animal.h i�indedir
#include "Animal.h" // header korumas� derleme s�ras�nda birka� kez dahil etmeyi �nler.
#include "Animal.h"
#include "Animal.h"

		Animal spot = Animal();
		spot.SetName("spot");
		std::cout << "Lan! Animal " << spot.GetName() << " arabay� ne bi�im s�r�yorsun?" << std::endl;
	};

	auto defineTan�m� = []() {
		fonksiyonuyaz("defineTan�m�");
#define PI 3.14159265358979323846264338327950288L
#define Alan�(r) PI*std::pow(r,2)
		std::cout << "Dairenin alan�: " << Alan�(7) << std::endl;
	};

	auto templateDurumu = []() {
		fonksiyonuyaz("templateDurumu");
		/*
		fonksiyonlar.cpp dosyas�nda MultBy2 fonksiyonunu kulland�m.
		* Lambda fonksiyonlar� template ile kullan�lam�yor hala ama template yerine auto s�zc��� i� g�r�yor.
		*/
		// eski versiyon
		std::cout << "MultBy2<int>(5)= " << doubler<int>(5) << std::endl;
		std::cout << "MultBy2<double>(5)= " << doubler<double>(6.86) << std::endl;
		// yeni versiyon
		std::cout << "MultBy2(5)= " << doubler(8) << std::endl;
		std::cout << "MultBy2(5.5)= " << doubler(7.6) << std::endl;

		/* visual c++ yeni �ekil tan�mlamay� pek sevmiyor.
		 cpp i�inde tan�mlay�p header i�ine prototip yerle�tirirseniz lnk2001 hatas�n� veriyor yani linker hatas�
		��Z�M;
		class sorununun ��z�m�: https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
		1) header i�inde, ayn� dosyada yada class olarak tan�mlamak.
		2) header i�inde extern olarak tan�mlamak: https://isocpp.org/wiki/faq/templates#separate-template-fn-defn-from-decl
		sadece fonksiyon prototipinde extern tan�mlamak. extern ger�ekten i�e yar�yor.
		3) Modern c++ export kelimesi: https://isocpp.org/wiki/faq/templates#separate-template-fn-defn-from-decl-export-keyword
		derleyici destekelemek zorunda ve daha tam olarak standart bir kelime de�il.

		*/
		std::cout << " 5 + 7 = " << Add(5, 7) << std::endl;
		std::cout << " 5.7 + 7.5 = " << Add(5.7, 7.5) << std::endl;

		std::cout << " 4 < 6 " << Max(4, 6) << std::endl;
		std::cout << " 'B' < 'N' " << Max('B', 'N') << std::endl; // sadece python i�inde mi var :D
		std::cout << " Bana < Nine " << Max("Bana", "Nine") << std::endl; // sadece python i�inde mi var :D


	};

	auto templateClass = []() {
		fonksiyonuyaz("templateClass");
		Person<double, int> mikeTyson(5.83, 216);
		mikeTyson.GetData();
		std::cout << "Number of people : " << mikeTyson.numOfPeople << "\n";
	};

	auto Iteratorler = []() {
		fonksiyonuyaz("Iteratorler");
		/*
		* itarat�r bir saya�t�r. veri dizileri �zerinde gezinmemizi sa�lar. Tek fark� bazen biraz daha
		h�zl� eri�im sa�layabilir ve performans� artt�rabilir.
		* Fonksiyonel programlamada �ok i�e yarar.
		* c++ stl haz�r veri yap�lar� k�t�phanelerinde haz�r iterat�rler mevcuttur.
		daha �nceden s�k�a kulland�m. ileriki a�amalarda class tan�mlarken iterator tan�mlayaca��z
		ama �imdilik haz�rlar� kullanal�m.
		*/

		// deque "double ended que" yani std::list tek ileriye ba�l� liste ise deque hem ileri hem geriye ba�l� listedir.
		std::deque<int> nums = { 1,2,3,4 };
		nums.push_front(0);
		nums.push_back(5);
		printAll(nums);

		// B�yle eri�im m�mk�n fakat i�eri�ini bilmeyenler i�in performans sorunu olu�turabilir.
		std::cout << nums[0] << "\n";

		// ----- ITERATORS -----
		// itr num2 vekt�r� haf�zada nerede kay�tl�ysa oraya i�aret eder.
		std::vector<int> nums2 = { 1,2,3,4 };

		// veri ile ayn� tipte olmal�
		std::vector<int>::iterator itr;

		// vekt�r�n ba�lang�� ve biti� noktalar�na i�aret edebiliriz.
		for (itr = nums2.begin(); itr < nums2.end(); itr++) {
			std::cout << *itr << std::endl; // pointer oldu�unu s�ylemi�tim.
		}

		// vek�r�n ba�lang�� noktas� yani nums[0]
		std::vector<int>::iterator itr2 = nums2.begin();

		// 2 tane ilerle yani 2 tane ileriye i�aret et
		advance(itr2, 2);
		std::cout << *itr2 << yenisat�r;

		// 1 tane daha ilerler fakat d�n��te iterator tipini geri yollar. pythona �ok benziyor.
		auto itr3 = next(itr2, 1);
		std::cout << *itr3 << "\n";

		// 1 tane geri gider fakat d�n��te iterator tipini geri yollar. pythona �ok benziyor.
		auto itr4 = prev(itr2, 1);
		std::cout << *itr4 << "\n";

		// belli indexlerden itibaren birle�tirme yapabilirsin..
		std::vector<int> nums3 = { 1,4,5,6 };
		std::vector<int> nums4 = { 2,3 };
		auto itr5 = nums3.begin();
		advance(itr5, 2);

		// std::inserter(data, data-iterator) // data-iterator belirtilen konumda aktarmaya ba�lar.
		// iterator index gibi davranmaz.
		// copy( kopyalanacak.begin, kopyalanacak.end, inserter(kopyalanan, ka��nc�s�ndan itibaren) );
		copy(nums4.begin(), nums4.end(), std::inserter(nums3, itr5));
		copy(nums4.begin(), nums4.end(), std::inserter(nums3, std::next(nums3.begin()))); // 2.se�enek

		printAll(nums3);

	};

	headerKorumas�();
	defineTan�m�();
	templateDurumu();
	templateClass();
	Iteratorler();
}

ia SmartPointers_PolymorphicTemplates() {
	auto eskihaf�zaAy�r = []() {
		// c dilindeki haf�za ay�rma tekni�i. idare etmesi b�y�k projelerde zorla��yor.
		int amtToStore;
		std::cout << "How many numbers do you want to store : ";
		std::cin >> amtToStore;
		int * pNums;

		// int t�r�nde oldu�una emin ol.
		pNums = (int *)malloc(amtToStore * sizeof(int));

		// haf�za ayr�ld� m� kontrol et.
		if (pNums != NULL) {
			int i = 0;

			// depola
			while (i < amtToStore) {
				std::cout << "Enter a Number : ";
				std::cin >> pNums[i];
				i++;
			}
		}

		std::cout << "You entered these numbers\n";
		for (int i = 0; i < amtToStore; i++) {
			std::cout << pNums[i] << "\n";
		}

		delete pNums; // haf�zay� sil



	};

	auto yenihaf�zaAy�r = []() {
		/*
		* autoptr, scopeptr, uniqueptr, sharedptr, weakptr,... gibi �ok�a ak�ll� i�aret�i �zerine 20 senedir
		�al���yor. hemen hemen her framework kendi i�aret�i k�t�phanesini olu�turmu� durumda. stl olan� anlataca��m.
		* Temel �zelli�i RAII(resourse aqcusition is initialization) ile bir t�r otomatik haf�za silme sistemi.
		Bu �zelli�i sa�larken de olas� aksakl�klara ve haf�za a��klar�na kar�� koruma sa�lamak.
		*/
		int amtToStore;
		std::cout << "How many numbers do you want to store : ";
		std::cin >> amtToStore;
		// haf�za otomatik ayr�l�p parantez ��k���nda silinecektir.
		std::unique_ptr<int[]> pNums(new int[amtToStore]);

		// unique_ptr kopyalanamaz. sadece bir sahipli�e sahiptir.
		// std::unique_ptr<int[]> pNums2 = pNums;

		if (pNums != NULL) {
			int i = 0;
			// depola
			while (i < amtToStore) {
				std::cout << "Enter a Number : ";
				std::cin >> pNums[i];
				i++;
			}
		}

		std::cout << "You entered these numbers\n";
		for (int i = 0; i < amtToStore; i++) {
			std::cout << pNums[i] << "\n";
		}


	};

	auto cokBicimliTemplate = []() {
		// unique_ptr gerek kalmad��� "pizzaOrders" nesnesini siler
		std::vector<std::unique_ptr<Pizza>> pizzaOrders;

		// vector referanslar� emplace_back ile depolar.
		// derleme zaman�nda pizza �e�itlerini �ok bi�imlilik sayesinde olu�turur.
		// �nemli! en son dahil edilen yani en i�erdeki en son �a��r�l�r.
		pizzaOrders.emplace_back(new MeatNYStyle<LotsOfMeat<NYStyleCrust>>());
		pizzaOrders.emplace_back(new VeganDeepDish<Vegan<DeepDishCrust>>());

		// pizzalar servis edilir :)
		for (auto &pizza : pizzaOrders) {
			pizza->MakePizza();
		}

	};

	eskihaf�zaAy�r();
	yenihaf�zaAy�r();
	cokBicimliTemplate();

	std::cin.get();
}

ia threadVeZamanlama() {
	/*
	<h1> Threads, zamanlama, dinamik bellek, payla��lan kaynaklar�n korunmas� ve �rnekler </h1>

	* Thread denen�ey bilgisayar�n birden fazla �ekirde�ini kullanabilmemizi sa�lar.
	�imdiye kadar yapt���m�z yaz�l�mlar sadece bir �ekirde�i kullanabiliyordu. �o�unlukla performans
	ve daha ak�c� programlar yapmak �zere kullan�l�r.
	** Thread her sistemde farkl� �ekilde ba�lat�labilir yada her sistemin kendisine has �zellikleri olabilir.
	bunlar� a��klamak zorunda kal�rsam yada ara�t�r dersem l�tfen ara�t�r�n.

	* zamanlama yani s�re tutma, s�releri kar��la�t�rma ve program� veya threadi belli bir s�re uyutmak

	* payla��lan kaynaklar�n korunmas�. threadler ayn� anda ayn� veriye eri�meye �al��t���nda program bozulur.
	bu sorunun �stesinden gelmeye �al��aca��z.

	*/

	/*threadBasic * taskPtr = new threadBasic();
	std::thread th1(&threadBasic::ExecuteThread, taskPtr, "Thread1");
	th1.join();

	std::thread th2(&threadBasic::ExecuteThread, taskPtr, "Thread2");
	th2.join();

	delete taskPtr;*/

	auto veryBasicThread = []() {
		// fonksiyonlar Yararl�Fonksiyonlar.h ve generateRandom.h i�inde mevcut.
		fonksiyonuyaz("veryBasicThread");
		std::thread first(foo);     // yeni thread foo() fonksiyonunu �a��r�yor.
		std::thread second(bar, 0); // yeni thread bar(0) fonksiyonunu �a��r�yor.

		std::cout << "main, foo and bar �imdi y�r�t�l�yor...\n";

		// synchronize threads:
		first.join();                // ilki bitene kadar bekler
		second.join();               // ikincisi bitene kadar bekler

		std::cout << "foo and bar tamamland�.\n";

		// Di�er �rnek ve zamanlama fonksiyonlar�
		fonksiyonuyaz("zamanlama fonksiyonlar�");
		std::thread th1(task1, "hello thread");
		th1.join();
		std::thread th2(printThread, 15);
		th2.join();

	};

	auto Thread1 = []() {
		fonksiyonuyaz(" Thread1 -> ExecuteThread");
		std::thread th1(ExecuteThread, 1);
		th1.join();
		std::thread th2(ExecuteThread, 2);
		th2.join();
	};

	auto para�ek = []() {
		std::thread threads[10]; // thread dizisi olu�turdum.

		for (int i = 0; i < 10; ++i) {
			threads[i] = std::thread(GetMoney, i, 15);
		}

		for (int i = 0; i < 10; ++i)
			if (threads[i].joinable()) // yeni versiyonda bu fonksiyon kullan�lmaz ise _INVALID_ARGUMENT exception yolluyor.
				threads[i].join();

	};

	auto primeNums = []() {
		fonksiyonuyaz("primeNums");
		std::cout.flush();
		std::setvbuf(stdout, NULL, _IONBF, 0); // performans sebeplerinden �t�r� gerekmedik�e uygulanan bir y�ntem de�ildir.
		// ekrana �kan buffer s�n�r�n� ortadan kald�r�r ve yazma say�s� s�n�rlanmaz.
		auto primeNumsThreadYok = []() {
			fonksiyonuyaz("    primeNumsThreadYok");
			//std::vector<unsigned int> primeVect;

			// zaman� �l�mek istiyorum tic-toc
			int startTime = clock();
			std::vector<unsigned int> primeVect;
			FindPrimes(1, 100000, primeVect);
			for (auto i : primeVect)
				std::cout << i << "\n";

			// en sornunda ne kadar zaman ge�ti
			int endTime = clock();

			// saniye cinsine �evir
			std::cout << "Execution Time : " << (endTime - startTime) / double(CLOCKS_PER_SEC) << std::endl;
		};

		auto primeNumsThreadVar = []() {
			fonksiyonuyaz("primeNumsThreadVar");
			int startTime = clock();
			FindPrimesWithThreads(1, 100000, 3);
			int endTime = clock();

			for (auto i : primeVect)
				std::cout << i << "\n";

			std::cout << "Execution Time : " << (endTime - startTime) / double(CLOCKS_PER_SEC) << std::endl;
		};
	
		// h�z� anlamak i�in "release" versiyonunda �al��t�r�n.
		primeNumsThreadYok();
		primeNumsThreadVar();
	};

	

	//veryBasicThread();
	//Thread1();
	//para�ek();
	primeNums();
}

ia sequenceContainer() {
	/*
	<h1> T�m liste veri tipleri(list, deque, forward_list) </h1>

	vector en h�zl� ve en temel liste tipidir ama baz� problemlerde fark� liste tiplerine de ihtiya� vard�r.
	* list: vektor gibi ama daha fazla yer kapl�yor. olduk�a etkili
	* deque: vektor gibi ama hem ileri hem geri ba�l� liste
	* forward_list: sadece ileriye ba�l� liste ve baz� durumlarda �ok h�zl� �al��abiliyor ama s�n�rlar� var.
	* 
	*/
	auto ciftmi = [](auto say�) { return say� % 2 == 0;	};
	auto dequeTan�m� = []() {
		fonksiyonuyaz("dequeTan�m�");
		std::deque<int> deq1;
		deq1.assign({45,32});
		deq1.push_back(15);
		deq1.push_back(16);
		std::cout << "size deq1: " << deq1.size() << std::endl;
		std::cout << "deq1[0]: " << deq1[0] << std::endl;
		std::cout << "deq1[2]: " << deq1[2] << std::endl;

		auto itdeq1 = deq1.begin() + 1;
		deq1.insert(itdeq1, 3);
		int tempArr[5] = { 6,7,8,9,10 };
		deq1.insert(deq1.begin(), tempArr, tempArr + 5);
		std::cout << "size deq1: " << deq1.size() << std::endl;
		auto ee = deq1.end()-2;
		deq1.erase(ee);
		auto deqbegin = deq1.begin();
		deq1.erase(deqbegin, deqbegin + 2);// ilk iki eleman� sil
		deq1.pop_front();// ilk eleman� listeden at.
		deq1.pop_back();// son eleman� listeden at.
		std::deque<int> deq2(2, 50);// 2 eleman� 50 olan liste
		deq1.swap(deq2);// de�i� toku�
		
		printAll(deq1);

		deq1.clear();// her �eyi siler
	};
	auto listTan�m� = [ciftmi]() {
		fonksiyonuyaz("listTan�m�");
		// herhangi bir konumdan eklemede, nesneleri hareket ettirmede, nesnelere eri�mede en etkili elemand�r.
		//int arr[5]{1,2,3,4,5};
		std::array<int, 5> arr{1,2,3,4,5};
		std::list<int> ll;
		ll.assign({8,85,852,258});
		ll.insert(ll.begin(),arr.begin(),arr.end());
		ll.push_back(10);
		ll.push_back(77);
		std::cout << "size list: " << ll.size() << std::endl;
		// ekranayaz << "ll[0]" << ll[0] << std::endl; // b�yle eri�im yok ama...
		// iterat�rer i�imizi g�recektir.
		auto itll = ll.begin();
		std::advance(itll,3);
		std::cout << "3. eleman: " << *itll << std::endl;
		printAll(ll);

		auto itll2 = ll.begin(); // index 0
		ll.insert(itll2,44);
		ll.erase(ll.begin());
		printAll(ll);

		auto it1 = ll.begin();
		std::advance(it1,2); // index 2
		ll.erase(itll2,it1); // 0 ve 2 aras�n� silecek
		printAll(ll);
		ll.pop_front();
		ll.pop_back();

		ll.assign({ 85,47,14,41,417 });
		ll.sort();
		ll.reverse();
		ll.unique(); // ayn� de�erden birden fazla olanlar� siler ve bir tane b�rak�r.
		ekranayaz << "unique: "; printAll(ll);
		ll.remove(41); // bu index de�il de�er. verilen t�m de�erden ka� tane varsa hepsini siler.
		ll.remove_if(ciftmi); // ko�ullu silme. parametre t�r� fonksiyondur.

		std::list<int> list1 = { 5,9,0,1,3,3,3 }; list1.sort();
		std::list<int> list2 = { 8,7,2,6,4,4,4 }; list2.sort();
		list1.merge(list2); // s�ral� olmak zorunda
		list1.unique(); // ayn� elemanlar� sildi.

		ekranayaz << "ll: "; printAll(ll);
		ekranayaz << "list1: "; printAll(list1);
	};
	auto forwardListTan�m� = [ciftmi]() {
		fonksiyonuyaz("forwardListTan�m�");
		// bu listede geri diye bir�ey yok.
		std::forward_list<int> fl1;
		fl1.assign({5,2,14,5,5,5,59,8563});
		fl1.push_front(0);
		fl1.pop_front();
		ekranayaz << "front: " << fl1.front() << std::endl;
		auto itfl = fl1.begin();
		itfl = fl1.insert_after(itfl ,5); // i�lemden sonra iterat�r 5 olarak de�i�ir.
		itfl = fl1.erase_after(fl1.begin()); // ilk eleman silinir ve iterat�r 1 artar.
		fl1.emplace_front(6); // ilk yere 6 yerle�tirdi.
		fl1.remove(5); // 5 de�erini sil.
		fl1.remove_if(ciftmi);

		std::forward_list<int> fl2;
		fl2.assign({ 9,8,7,6,6 });
		fl2.unique(); // ayn� olanlar� sil.
		fl2.sort(); // s�rala
		fl2.reverse(); // tersine �evir.

		ekranayaz << "before merge: "; printAll(fl1);
		fl1.sort();
		fl2.sort();
		fl1.merge(fl2); // s�ral� olmak zorunda ikisini birle�tir.
		ekranayaz << "after merge: "; printAll(fl1);
		
		printAll(fl1);
		printAll(fl2);

		fl1.clear(); // ne varsa sil

	};
	dequeTan�m�();
	listTan�m�();
	forwardListTan�m�();
}

ia Associative(){
	/*
	<h1> Associative(ili�kisel) Saykalay�c�lar(Containers), Saykalay�(Container) arazy�zleri, enums </h1>

	* Associative Containers: 
		set, multiset, map, multimap
	* Container Adapters:
		stack, queue, priority_queue
	*/

	setTan�m�();
	multisetTan�m�();
	mapTan�m�();
	multimapTan�m�();
	stackTan�m�();
	queueTan�m�();
	priorityQueue();
	enums();
}

ia regularExpressions() {
	/*
	<h1> regular expressions: arama, ��kan sonu�lar� birle�tirme, iterat�rler ve di�erleri </h1>
	
	* regular expressions yani k�sa ad�yla regex perl programlama diliyle beraber hayat�m�za iyice girdi.
	string i�lemek �zere kullan�lan ufak bir programlama dili davran�yor.
	temel i�levi: string �zerinde arama ve e�l�tirmedir.(hemde �ok iyi)
	i�letim sistemlerinde dosyalar aras�nda gezinmeyi kola�la�t�r�r.
	�ok k�sa ifadelerle uzun uzun yaz�lacak programlar�n i�levlerini yerine getirebilir.
	bazen yava� olabilir ama ��renenen pi�man olmuyor :)

	* regex debug derlemede �al��m�yor. bu b�y�k bir sorun biliyorum ama yapabilece�im bir�ey yok.
	https://docs.microsoft.com/tr-tr/cpp/error-messages/tool-errors/linker-tools-error-lnk2038
	*/
	
	regex1();



}

// ceia customHeaders.h i�inde constexpr olarak belirlenmi�tir. Sonra �zerinde duraca��m.
ceia temelDerslerMain(int argc, char** argv) {
	constexpr auto hangib�l�m = 1; // sonradan global tan�mla
	switch (hangib�l�m) // yeni programlama dillerinde match durumu daha iyi ama �imdilik elimizde bu var. match test a�amas�nda...
	{
	case 1: ilkadim(argc, argv); break;
	case 2: temelVeriyap�lar�(); break;
	case 3: string��lemleri();  break;
	case 4: karar��lemleri();  break;
	case 5: dizi��lemleri(); break;
	case 6: vector��lemleri();  break;
	case 7: pointlerFonksiyonlar();  break;
	case 8: �zeldurumlarVED�ng�ler();  break;
	case 9: stringMath();  break;
	case 10: Alistirmalar();  break;
	case 11: yinelemeliVEas�r�Y�klemeli();  break;
	case 12: lambdaDerinlemesine();  break;
	case 13: oops(); break;
	case 14: overloadFileIO();  break;
	case 15: ileriFonksiyonlar();  break;
	case 16: templateVeItarator();  break;
	case 17: SmartPointers_PolymorphicTemplates(); break;
	case 18: threadVeZamanlama(); break;
	case 19: sequenceContainer();  break;
	case 20: Associative(); break;
	case 21: regularExpressions();  break;
	default: break;
	}


}
	/*
		* Tebrikler Temel Modern c++ bitmi�tir. Yeni �htiya� olan bir�ey olursa ekleyerek devam ederim.
		
		* Daha ayr�nt�l� bilgi i�in https://en.cppreference.com/w/cpp/language sitesine ba�vurabilirsiniz.
		* c++ dilinde �ok say�da farkl� derleyici ve k�t�phane bulunuyor ve hepsini indirip kulanam�yorsan�z
		https://godbolt.org/ sayfas� kodlar�n�z� assembly kodlar�na d�n��t�recektir.
		* Farkl� veri yap�lar�n� kar��la�t�rmak i�in http://quick-bench.com sitesini kullanabilirsiniz.
		* Bir ara derleyici, linker, assembler, LLVM, �ok kullan�lan ve populerle�en derleyicileri tan�taca��m.
		* Sonraki dersler c++QT5/QML ve c++Opencv diye gidecektir. Qt5/QML ingilizce de bile
		kaynak az oldu�undan ingilizce anlatabilirim.
		* Qt5 tam olarak c++ stl veri yap�lar�yla uygun de�ildir. Qt5 temel bilgisini http://zetcode.com/gui/qt5/
		sitesinden anlataca��m.
		* Qml i�in ilk tan�mda http://zetcode.com/gui/qtquick/ sitesinden yararlanaca��m.
		Sonra https://qmlbook.github.io/ yararlanaca��m. Qml ile guilerin tasarlanma ve �al��ma h�zlar�na �a��racaks�n�z.


		*** Beni takip etmeye devam edin :) ***
	*/

#endif  // HEADER_FILE