#include "stdafx.h"
#include "customHeaders.h"
#include "stdheaders.h"
// Dikkat! bu header dosyas� functionalStyle.h i�inde dahil edildi. Sak�n b�yle bir�ey yapmay�n. E�itim ama�l�d�r.
#include "functionalStyle.h"

#ifndef Yararl�Fonksiyonlar_H // eski ve ta��nabilir usul header korumas�. Derleyici header dosyas�n� defalarca 
#define Yararl�Fonksiyonlar_H // dahil etmesini �nler. B�y�k projelerde �nemli sorun te�kil ediyor.

#ifdef _MSC_VER
#pragma once
#endif


/*
namespace functionalStyle::Yararl�Fonksiyonlar {
// Lambda fonksiyonlar� i�ine "[]" statik tan�ml� ba�ka bir fonksiyon alamaz.
inline auto printAll = [](auto data) -> void { // d�n�� tipi "void" olarak belirledim. art�k derleme hatas� yok.
for (auto d : data)
std::cout << d << " ";
yenisat�ryaz;
};
inline auto GenerateRandVec = [](int numOfNums, int min, int max) {
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

inline auto StringToVector = [](std::string theString, char separator) {
std::vector<std::string> vecsWords;
std::stringstream ss(theString);
std::string sIndivStr;
while (getline(ss, sIndivStr, separator))
vecsWords.push_back(sIndivStr);
return vecsWords;
};

inline std::vector<int> Range(int start, int max, int step) {
int i = start;
std::vector<int> range;
while (i <= max) {
range.push_back(i);
i += step;
}
return range;
};

inline bool IsPrime (int num) {
for (auto n : Range(2, num - 1, 1))
if ((num % n) == 0)
return false;
return true;
};
inline auto GetPrimes = [](int maxNum) {
std::vector<int> vecPrimes;
for (auto x : Range(2, maxNum, 1))
if (IsPrime(x))
vecPrimes.push_back(x);
return vecPrimes;
};

inline auto strMatches(std::string str, std::string substr) {
std::vector<int> matchingIndexes;
auto index = str.find(substr, 0);
while (index != std::string::npos) {
matchingIndexes.push_back(index);
index = str.find(substr, index + 1);
}
return matchingIndexes;
};
inline auto strReplace = [=](std::string str, std::string substr, std::string newstr) {
// lambda kural� olarak strMatches fonksiyonunu bu [strMatches] ile lambda fonksiyonunun i�ine kopyalad�m.
std::vector<int> matched = strMatches(str, substr); // e�er e�le�me olmazsa .size 0 g�nderecek.
if (matched.size() != 0) {
auto sizeDiff = matched.size() - substr.size();
auto looped = 0;
for (auto index : matched)
str.replace(index + looped * sizeDiff, substr.size(), newstr); looped;
}
return str;
};

}
*/

int GetRandom(int);

static std::string GetTime() {
	auto nowTime = std::chrono::system_clock::now();
	std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);
	char str[26];
	ctime_s(str, sizeof str, &sleepTime); // tavsiye edilen fonksiyon.
	return std::string(str);

	// return std::ctime(reinterpret_cast< const time_t* >((&sleepTime))); //ctime eski ve g�venli olmayan bir fonksiyon.
}

static void foo()
{
	std::cout << "foo()" << std::endl;
}

static void bar(int x)
{
	std::cout << "bar()" << std::endl;
}
static void task1(string msg)
{
	cout << "task1 says: " << msg;
}
static void printThread(int son = 20) {
	auto arr = RangePython(1, son, 1);
	auto theadid = std::this_thread::get_id();
	for (auto& d : arr)
		std::cout << theadid << ": " << d << ", ";
	yenisat�ryaz;
}
static void ExecuteThread(int id) {
	/* //generateRandom.h i�inde mevcut
	auto GetRandom = [](int max) {
	srand(time(NULL));
	return rand() % max;
	};*/

	// �imdiki zaman saniye cinsinden
	auto now = std::chrono::system_clock::now();

	// i�lem yap�labilir ve anla��l�r zaman tipine d�n��t�r�r.
	std::time_t sleepTime = std::chrono::system_clock::to_time_t(now);

	// bilgisayar zaman�n� y�resel anla��labilir zamana d�n��t�r�r.
	tm myLocalTime;
	localtime_s(&myLocalTime, &sleepTime);
	// tm myLocalTime = *localtime(&sleepTime); // eski ve g�vensiz.

	// t�m zaman� yazd�r�r.
	char str1[26];
	ctime_s(str1, sizeof str1, &sleepTime); // tavsiye edilen fonksiyon.
	std::cout << "Thread " << id << " Sleep Time : " << str1 << "\n";

	// Zaman� birimlerine ay�r�r.
	std::cout << "Ay : " << myLocalTime.tm_mon << "\n";
	std::cout << "G�n : " << myLocalTime.tm_mday << "\n";
	std::cout << "Y�l : " << myLocalTime.tm_year + 1900 << "\n";
	std::cout << "Saat : " << myLocalTime.tm_hour << "\n";
	std::cout << "Dakika : " << myLocalTime.tm_min << "\n";
	std::cout << "Saniye : " << myLocalTime.tm_sec << "\n\n";

	// thread en fazla 3 saniyeli�ine durur.
	std::this_thread::sleep_for(std::chrono::seconds(GetRandom(3)));
	now = std::chrono::system_clock::now();
	sleepTime = std::chrono::system_clock::to_time_t(now);
	char str2[26];
	ctime_s(str2, sizeof str2, &sleepTime); // tavsiye edilen fonksiyon.
	std::cout << "Thread " << id << " Awake Time : " << str2 << "\n";
}

static std::mutex acctLock;
static double HesaptakiPara = 100;
static void GetMoney(int id, double paraCekme) {
	std::lock_guard<std::mutex> HesaptakiParaLock(acctLock); // otomatik eri�im korumas�.
	// HesaptakiParaLock.lock();
	std::this_thread::sleep_for(std::chrono::seconds(3));

	std::cout << paraCekme << " tl para �ekiyorsunuz. " << GetTime() << std::endl;

	if (HesaptakiPara - paraCekme >= 0)
	{
		HesaptakiPara -= paraCekme;
		std::cout << "Hesaptaki para: " << HesaptakiPara << std::endl;
	}
	else
	{
		std::cout << "hesab�n�zda yeteri kadar para bulunmuyor. \n �uan da bulunan miktar: " << HesaptakiPara
			<< std::endl;
	}
	//HesaptakiParaLock.unlock();
}

static void FindPrimes(unsigned int start, unsigned int end, std::vector<unsigned int>& vect) {
	// Cycle through numbers while ignoring evens
	for (unsigned int x = start; x <= end; x += 2) {
		for (unsigned int y = 2; y < x; y++) {
			if ((x % y) == 0) break;
			else if ((y + 1) == x) vect.push_back(x);
		}
	}
}


//static std::mutex vectLock; // global olsa iyi olur
static std::vector<unsigned int> primeVect;
static void FindPrimesWithLock(unsigned int start, unsigned int end) {
	// allocate at refered vector
	// Cycle through numbers while ignoring evens
	for (unsigned int x = start; x <= end; x += 2) {
		for (unsigned int y = 2; y < x; y++) {
			if ((x % y) == 0) break;
			else if ((y + 1) == x) {
				std::lock_guard<std::mutex> mulock(); // lock to senkronize
				primeVect.push_back(x);
			}
		}
	}
}

static void FindPrimesWithThreads(unsigned int start, unsigned int end, const unsigned int numThreads=2) {
	std::vector<std::thread> threadVect(numThreads);
	//std::thread threadVect[numThreads];

	// farkl� asal say�lar� hesaplamak �zere hesaplamay� threadlere payla�t�r�yorum.
	// 10 thread var ve 1-100 aras� asal say� elde etmek istersem
	// ilk thread 1-9, ikinci thread 10-19, ... aras�n� al�r.
	unsigned int threadSpread = end / numThreads;
	unsigned int newEnd = start + threadSpread - 1;

	// her threadin hesaplayaca�� aral��� veriyorum.
	for (unsigned int x = 0; x < numThreads; ++x) {
		threadVect.emplace_back(FindPrimesWithLock, start, newEnd); // fonksiyonu ve parametrelerini al�r sonucu vekt�re kaydedir.
		//threadVect[x] = std::thread(FindPrimesWithLock, start, newEnd);
		start += threadSpread;
		newEnd += threadSpread;
	}

	// threadler ana thread ile uyumlu hale geliyor.
	for (auto& t : threadVect)
		if(t.joinable()) // yeni versiyonda bu fonksiyon kullan�lmaz ise _INVALID_ARGUMENT exception yolluyor.
			t.join();
}



#endif  // HEADER_FILE