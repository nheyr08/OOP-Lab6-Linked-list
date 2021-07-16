#include<iostream>
#include<fstream>
#include<string>
#include"LinkedList.h"

using namespace std;


int main() {
	ifstream File;
	File.open("input.txt");

	if (!File.is_open()) {
		cout << "Can't open input.txt" << endl;
		return 0;
	}
	std::cout << "reading file!" << endl;
	int TestCase = 0;
	File >> TestCase;

	while (TestCase) {

		LinkedList List;
		int num_op = 0;
		File >> num_op;
		for (int i = 0; i < num_op; i++) {
			char op;
			int data;
			int index;

			File >> op;

			switch (op)
			{
			case 'b':
				File >> data;
				List.Push_back(data);
				break;
			case 'f':
				File >> data;
				List.Push_front(data);
				break;
			case 'i':
				File >> index;
				File >> data;
				List.Insert(index, data);
				break;
			case 'd':
				File >> index;
				List.Delete(index);
				break;
			case 'r':
				List.Reverse();
				break;
			default:
				break;
			}
		}

		List.Print();

		cout << endl;
		TestCase--;
	}

	system("pause");
	return 0;
}