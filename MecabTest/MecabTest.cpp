// MecabTest.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <mecab.h>
#include <fstream>
#include <sstream>

using namespace std;


int main(int argc, char **argv)
{
	//テキストファイルを取得
	ifstream str("C:/Users/Fate/Desktop/test1.txt");
	//存在しなければ終了
	if (!str) return 1;
	str.seekg(0, fstream::end);
	unsigned long eofPos = str.tellg();

	str.clear();

	str.seekg(0, fstream::beg);
	unsigned long begPos = str.tellg();

	unsigned long size = eofPos - begPos;

	char *input = new char[size];
	cout << "input=" << input << endl;
	while (str.getline(input, size-1)) {
		MeCab::Tagger *tagger = MeCab::createTagger("");
		const char *result = tagger->parse(input);
		cout << "input start" << endl;
		
		cout << result << endl;
		cout << "result end" << endl;
	}


    return 0;
}

