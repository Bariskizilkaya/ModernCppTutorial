#pragma once
// ----------------- PointlerFonksiyonlar -----------------
/*
https://en.cppreference.com/w/cpp/language/storage_duration
auto - automatic storage duration. (until C++11)
register - automatic storage duration. Also hints to the compiler to place the object in the processor's register. (deprecated) (until C++17)
static - static or thread storage duration and internal linkage. ***
extern - static or thread storage duration and external linkage. ***
thread_local - thread storage duration. (since C++11)
*/

static void assignByValue(int say�) { say� = 11; }
static int returnByValue(int say�) { say� = 15; return say�; } // return kullan�lmazsa uyar� vermeden derleme duruyor. D�zeltilecektir.
static void assignByPointer(int* say�) { *say� = 22; }
static void assignByRef(int& say�) { say� = 33; }
static void yazacak(int a) { printf("Value of a is %d\n", a); }
static bool compare(const void * a, const void * b) { return (*(int*)a == *(int*)b); }
static int search(void *arr, int arr_size, int ele_size, void *x, bool compare(const void *, const void *)) {
	char *ptr = (char *)arr;
	int i;
	for (i = 0; i<arr_size; i++)
		if (compare(ptr + i * ele_size, x)) return i; // overflow hatas� ��kmas� muhtemel. pointer kullanmak tehlikeli. derleyici uyard�.
	// eleman bulunmaz ise.
	return -1;
}
// Eski C dili.
// Yapabilece�imizin kan�t�d�r.
static std::vector<int> RangePython(int begin = 0, int end = 10, int stepper = 1)
{
	int i = begin;
	std::vector<int> range;
	while (i <= end) {
		range.push_back(i);
		i += stepper;
	}
	return range;
}
typedef std::vector<int>(*myFuncPoint)(int, int, int);
static void yazacakFunc(int be, int e, int st, myFuncPoint funp) {
	// ana fonksiyonda varsay�lan parametre ekledikten sonra yeniden varsay�lan parametre vermeyi desteklemiyor.
	auto temp = (*funp)(be, e, st);
	for (auto& i : temp)
		printf("De�er: %d\n", i);
}
// C++ �ekli
template<typename Functor>
static void f(Functor functor)
{
	cout << functor(10) << endl;
}