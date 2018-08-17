#include "stdafx.h"
#ifndef regexTan�m�_H // eski ve ta��nabilir usul header korumas�. Derleyici header dosyas�n� defalarca 
#define regexTan�m�_H // dahil etmesini �nler. B�y�k projelerde �nemli sorun te�kil ediyor.

#ifdef _MSC_VER
#pragma once
#endif
static void PrintMatches(std::string str, std::regex reg) {
	std::smatch matches;
	std::cout << std::boolalpha;
	while (std::regex_search(str,matches,reg))
	{
		ekranayaz << "e�le�me haz�r: " << matches.ready() << std::endl;
		ekranayaz << "e�le�me yok : " << matches.empty() << std::endl;
		ekranayaz << "e�le�me say�s� : " << matches.size() << std::endl;
		ekranayaz << "matches.str(1) : " << matches.str(1) << std::endl;
		str = matches.suffix().str();
		ekranayaz << "matchler elenmi� hali : " << str << std::endl;
	}
	yenisat�ryaz;
}

void PrintMatches2(std::string str, std::regex reg) {
	std::sregex_iterator currentMatch(str.begin(), str.end(), reg);// ilk e�le�meyi tutar.
	std::sregex_iterator lastMatch; // ba�ka varsa onlar� tutar.

	// sonuncuya e�it ise d��ng�den ��kar. demekki daha yoktur.
	while (currentMatch != lastMatch) {
		std::smatch match = *currentMatch;
		std::cout << match.str() << std::endl;
		currentMatch++;
	}
	yenisat�ryaz;
}

static void PrintMatches3(std::string str, std::regex reg) {
	auto words_begin = std::sregex_iterator(str.begin(), str.end(), reg);
	auto words_end = std::sregex_iterator();
	std::cout << "Bulundu:  " << std::distance(words_begin, words_end) << " words\n";

	const int N = 6;
	std::cout << N << "den uzun kelimelerin karakterleri:\n";
	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
		std::smatch match = *i;
		std::string match_str = match.str();
		if (match_str.size() > N) {
			std::cout << "  " << match_str << '\n';
		}
	}






}

static void regex1() {
	auto regexilk = []() {
		std::string str = "The ape was at the apex";
		std::smatch matches; // string match
		/* ape ve apex yakalamak istiyorsam
		* "(" ile ba�lar yani "(ape" ile ba�lar.
		* "[]" e�le�ecek karakterler demektir.
		* "^" not ifadesidir.
		* "[^ ]" not ifadesinden sonra bir bo�luk koyuyorumki bo�luk olmayanlar� e�le�tirsin.
		* "?" match i�in zorunlu de�ildir. bu i�aret konmaz ise e�le�me yok diye geri d�ner.
		* "[^ ]?)" bo�luk olmas�n ama �art de�il, bo�lukta olabilir.
		* "(ape[^ ]?)" ape ile ba�la, bo�luk olmas�n ama �art de�il, bo�lukta olabilir ve ")" ile i�lemi bitir.
		*/
		std::regex reg("(ape[^ ]?)"); 
		PrintMatches(str,reg);
	};

	auto regexikinci = []() {
		std::string str2 = "I picked the pickle";
		// Match (+) 1 or more of anything not a space
		/*
		* "(pick" pick ile ba�la
		* "+" bir veya daha fazla
		* "([^ ]+)" bir veya daha fazla bo�luk istemiyorum.
		* "([^ ]+)?)"  bir veya daha fazla bo�luk istemiyorum ve �art olmas� ama �art de�il, �art da olabilir.

		*/
		std::regex reg2("(pick([^ ]+)?)");
		PrintMatches2(str2, reg2);
	};
	
	/*
	regexilk();
	regexikinci();
	*/

}


#endif  // HEADER_FILE
