// ConsoleApplication12.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include"HuffmanTree.h"

int main()
{
	HuffmanTree huff;
	char x;
	while (true) {
		huff.showMenu();
		cin.clear();
		cin >> x;
		switch (x)
		{
		case 'I': {
			int x;
			cout << "1.设计哈夫曼编码。2.哈夫曼编码译码测试" << endl;
			cin >> x;
			switch (x)
			{
			case 1: {
				cout << "请输入字符集大小：";
				int n;
				cin >> n;
				char ch[8];
				double weight[8];
				cout << "请依次输入字符和权值" << endl;
				for (int i = 0; i < n; i++) {
					cin >> ch[i];
					cin >> weight[i];
				}
				huff.Initialize(n, ch, weight);
				break;
			}
			case 2: {
				int size = 27;
				char ch[] = { ' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
				double weight[] = { 186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1 };
				huff.Initialize(size, ch, weight);
				break;
			}
			default:
				break;
			}
			break;
		}
		case 'E': {
			string code;
			if (!huff.isEmpty()) {
				huff.read("ToBeTran.txt", code);
				string encode = huff.Encode(code);
				//要编码的字符串
				huff.save("CodeFile.txt", encode);
				cout << "已对ToBeTran.txt完成编码，并存入工程根目录下文件CodeFile.txt" << endl;
			}
			else {
				cout << "哈夫曼树未初始化" << endl;
			}
			break;
		}
		case 'D': {
			string code;
			if (!huff.isEmpty()) {
				huff.read("CodeFile.txt", code);
				string decode = huff.Decode(code);
				//要译码的字符串
				cout << decode << endl;
				huff.save("Textfile.txt", decode);
				cout << "已对CodeFile.txt译码，并存入工程根目录下文件Textfile.txt" << endl;
			}
			else {
				cout << "哈夫曼树未初始化" << endl;
			}
			break;
		}
		case 'P': {
			huff.print();
			cout << endl;
			break;
		}
		case 'Q': {
			exit(0);
		}
		default:
			break;
		}
	}
	system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
