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
				throw "������� ����� �����������";
				return false;
			}
			throw "������������ ����� ��������� ������";
			return false;
		}
		return false;
	};

	bool isHeadEnglishWord() {
		if (isHeadEnglishLetter()) {
			if (isEnglishWord())
				return true;
			throw "���������� ����� ������ ���� �������� ���������";
		}
		throw "���������� ����� ������ ���������� � ��������� ����� ���������� ��������";
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
		if (*str_ >= '�' && *str_ <= '�') {
			translation_ += *str_;
			str_++;
			return true;
		}
		return false;
	};
public:
	// �����������
	BNF(char*& st) : str_(st),translation_(""),word_(""){
		isTrueString();
	};
	// ������ � ����������� �����
	string word() {
		if (word_ != "")
			return word_;
		else return "-1";
	};
	// ������ � ��������
	string translation() {
		if (translation_ != "")
			return translation_;
		else return "-1";
	};
	// ���������� ��������
	~BNF() {
		if (word_ != "")
			word_ = "";
		if (translation_ != "")
			translation_ = "";
	};
};

#endif
