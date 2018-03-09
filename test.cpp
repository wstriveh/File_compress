#define  _CRT_SECURE_NO_WARNINGS
#ifndef __TEST_CPP__
#define __TEST_CPP__
#include <iostream>
using namespace std;

#include "Huffman.hpp"
#include "File_Compress.h"
#include "TimeCheck.h"

void test()
{
	string filename = "E:\\VC2013文件\\项目\\file_compression\\file_compression\\压缩文件.txt";
	cout << "压缩时间:";
	MyTimer timer;
	timer.Start();

	FileCompress fc;
	fc.CompressHuffCode(filename.c_str());

	timer.Stop();
	timer.showTime();

}

void untest()
{
	string filename = "E:\\VC2013文件\\项目\\file_compression\\file_compression\\压缩文件.huff";
	cout << "解压时间:";
	MyTimer timer;
	timer.Start();

	FileCompress unfc;
	unfc.UnCompressHuffCode(filename.c_str());

	timer.Stop();
	timer.showTime();

}

int main()
{

	test();
	untest();

	system("pause");
	return 0;
}
#endif
