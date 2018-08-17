#ifndef stdheaders_H // eski ve ta��nabilir usul header korumas�. Derleyici header dosyas�n� defalarca 
#define stdheaders_H // dahil etmesini �nler. B�y�k projelerde �nemli sorun te�kil ediyor.

#ifdef _MSC_VER
#pragma once
#endif

#include "targetver.h"

// eski c dili k�t�phaneleri
#include <cstdio>
#include <tchar.h>
#include <wchar.h>
#include <clocale>
#include <ctime>

//#include <Windows.h> // windows c api

// her t�rl� girdi ��kt� ve string
#include <iostream>
#include <cstdlib>
#include <string>
#include <string_view>
#include <sstream>
#include <fstream> // File I/O

// integer t�rleri ve s�n�rlar�
#include <cstdint>
#include <limits>

// �e�itli fonksiyonlar ve algoritmalar
#include <functional>
#include <algorithm>
#include <iterator>

// Sequential containers
#include <array>
#include <vector>
#include <tuple>
#include <list>
#include <deque>
#include <forward_list>

// Associative container 
#include <map>
#include <set>
#include <stack>
#include <queue>

// rastgele say�lar ve matematik
#include <random>
#include <chrono>
#include <cmath> // math.h ayn� ifade.
#include <numeric>

// thread ve ara�lar�
#include <thread>
#include <mutex>
#include <future>

// ara ara�lar
#include <utility>
#include <memory>

// regular expression
#include <regex>


using std::cout;
using std::endl;
using std::cin;
using std::getline;

using namespace std::string_literals;
using std::string;
using std::array;
using std::vector;
using std::tuple;


#endif  // HEADER_FILE