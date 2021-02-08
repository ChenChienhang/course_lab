// Students'healthManagementSystem.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "StudentSeqlist.h"

int main()
{
	StudentSeqlist studentlist;
	int flag = 0;
	//表新建操作
	int choice;
	while (true) {
		studentlist.showMenu();
		cin.clear();//清除缓存影响
		cin >> choice;
		switch (choice) {
		case 1: {
			if (flag == 1) {
				cout << "已存在表，请进行插入操作" << endl;
				break;
			}
			else {
				string flag1;
				//继续新建表标志
				cout << "开始新建列表" << endl;
				do {
					
					cout << endl;
					Student temp;
					cin >> temp;
					studentlist.insert(temp);
					cout << "是否继续新建信息：Y or N?：";
					cin >> flag1;
				} while (flag1=="Y"||flag1=="y");
			}
			break;
		}
		case 2: {
			string flag;
			do {
				cout << endl;
				Student temp;
				cin >> temp;
				studentlist.insert(temp);
				cout << "是否继续新建信息：Y or N?：";
				cin >> flag;
			} while (flag=="y"||flag=="y");
			break;
		}
		case 3: {
			string i;
			cout << "请输入要删除学生的学号：";
			cin >> i;
			if (studentlist.remove(studentlist.search(i))) {
				cout << "删除成功" << endl;
			}
			else {
				cout << "删除失败" << endl;
			}
			break;
		}
		case 4:
			cout << "请确认将record.txt置于工程目录下" << endl;
			system("pause");
			if (studentlist.readTxt()) {
				cout << "读取成功" << endl;
			}
			else {
				cout << "读取失败" << endl;
			}
			break;
		case 5:
			studentlist.writeTxt();
			cout << "已成功保存到工程根目录下record.txt"<<endl;
			break;
		case 6: {
			string num;
			cout << "请输入学号：";
			cin >> num;
			int i = studentlist.search(num);
			if (i== -1) {
				cout << "找不到该学生" << endl;
			}else{
				studentlist.output(i);
			}
			
			break;
		}
		case 7: {
			int length = studentlist.getLength();
			for (int i = 0; i < length; i++) {
				studentlist.output(i);
			}
			break;
		}		
		case 8:
			exit(0);
		}
		cout << endl;
		system("pause");
	}
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
