#ifndef _BNF_H
#define _BNF_H

#include <iostream>
using namespace std;
class BNF {
private:
	char*& str_;
	string translation_;
	string word_;

	bool isTrueString() {
		if (isHeadEnglishWord()) {
			if (*str_ == '-') {
				str_++;
				if (isRussianWord())
					return true;
				throw "Перевод задан некорректно";
				return false;
			}
			throw "Некорректная форма введенной строки";
			return false;
		}
		return false;
	};

	bool isHeadEnglishWord() {
		if (isHeadEnglishLetter()) {
			if (isEnglishWord())
				return true;
			throw "Английское слово должно быть написано латиницей";
		}
		throw "Английское слово должно начинаться с заглавной буквы латинского алфавита";
	};

	bool isEnglishWord() {
		if (isEnglishLetter()) {
			isEnglishWord();
			return true;
		}
		return false;
	};

	bool isEnglishLetter() {
		if (*str_ >= 'a' && *str_ <= 'z') {
			word_ += *str_;
			str_++;
			return true;
		}
		return false;
	};

	bool isRussianWord() {
		if (isRussianLetter()) {
			isRussianWord();
			return true;
		}
		return false;
	};

	bool isHeadEnglishLetter() {
		if (*str_ >= 'A' && *str_ <= 'Z') {
			word_ += *str_;
			str_++;
			return true;
		}
		return false;
	};

	bool isRussianLetter() {
		if (*str_ >= 'а' && *str_ <= 'я') {
			translation_ += *str_;
			str_++;
			return true;
		}
		return false;
	};
public:
	// Конструктор
	BNF(char*& st) : str_(st),translation_(""),word_(""){
		isTrueString();
	};
	// Доступ к английскому слову
	string word() {
		if (word_ != "")
			return word_;
		else return "-1";
	};
	// Доступ к переводу
	string translation() {
		if (translation_ != "")
			return translation_;
		else return "-1";
	};
	// Деструктор элемента
	~BNF() {
		if (word_ != "")
			word_ = "";
		if (translation_ != "")
			translation_ = "";
	};
};

#endif
