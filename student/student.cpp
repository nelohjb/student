// student.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "Student.h"
#include "DataBase.h"
using namespace std;

void add(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);
void query(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);
void display(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);
void edit(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);
void Delete(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);
void count(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);

int main()
{

	DataBase<Pupil> pupil("e://PupilStudent.dat");
	DataBase<Middle> middle("e://MiddleStudent.dat");
	DataBase<College> college("e://CollegeStudent.dat");

	void(*menu[])(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college)
	{ add, query, display, edit, Delete, count };

	char choice = 'X';

	while (choice != '0') {
		cout << "----------------------------------\n";
		cout << "\t0. 退出系统\n\t1. 添加\n\t2. 查询\n\t3. 显示\n\t4. 编辑\n\t5. 删除\n\t6.统计\n";
		cout << "----------------------------------\n";
		cout << "->请输入： ";

		cin >> choice;
		if(choice!='0')
			menu[choice];
	}
    return 0;
}


void add(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {
	int choice;

	long ID;
	string name;
	char sex[3];
	int age, Class;
	float CH, MA, EN;
	float GE, HI;
	string address, major, phoneNumber;

	cout << "输入添加的学生类别： (1.小学生  2.中学生  3.大学生)" << endl;
	cin >> choice;
	if (choice == 0) {
		return;
	}
	else if (choice == 1) {
		cout << "->请依次输入学生的学号、姓名、性别、年龄、班级和语文、数学、英语成绩 (输0终止): ";
		cin >> ID;
		while (ID != 0) {
			cin >> ID;
			if (!pupil.query(ID) && !middle.query(ID) && !college.query(ID)) {
				cin >> name >> sex >> age >> Class >> CH >> MA >> EN;
				Pupil temp(ID, name, sex, age, Class, CH, MA, EN);
				pupil.insert(temp);
				cout << ID << " 添加成功！" << endl;
			}
			else {
				cout << "已存在!" << endl;
			}
		}
	}
	else if (choice == 2) {
		cout << "->请依次输入学生的学号、姓名、性别、年龄、班级和语文、数学、英语、地理、历史成绩和家庭住址 (输0终止): " << endl;
		cin >> ID;
		while (ID != 0) {
			cin >> ID;
			if (!pupil.query(ID) && !middle.query(ID) && !college.query(ID)) {
				cin >> name >> sex >> age >> Class >> CH >> MA >> EN >> GE >> HI >> address;
				Middle temp(ID, name, sex, age, Class, CH, MA, EN, GE, HI, address);
				middle.insert(temp);
				cout << ID << " 添加成功！" << endl;
			}
			else {
				cout << "已存在!" << endl;
			}
		}
	}
	else if (choice == 3) {
		cout << "->请依次输入学生的学号、姓名、性别、年龄、班级和语文、数学、英语成绩和专业、家庭地址、联系方式 (输0终止): ";
		cin >> ID;
		while (ID != 0) {
			cin >> ID;
			if (!pupil.query(ID) && !middle.query(ID) && !college.query(ID)) {
				cin >> name >> sex >> age >> Class >> CH >> MA >> EN >> major >> address >> phoneNumber;
				College temp(ID, name, sex, age, Class, CH, MA, EN, major, address, phoneNumber);
				college.insert(temp);
				cout << ID << " 添加成功！" << endl;
			}
			else {
				cout << "已存在!" << endl;
			}
		}
	}
}

void query(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {
	long ID = -1;
	while (ID) {
		cout << "请输入要查询的学号(输0退出)： ";
		cin >> ID;
		if (ID != 0) {
			if (pupil.query(ID))
				pupil.query(ID)->showData();
			else if (middle.query(ID))
				middle.query(ID)->showData();
			else if (college.query(ID))
				college.query(ID)->showData();
			else
				cout << "没有查到！" << endl;
		}
	}
}

void display(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {
	cout << "--------------- 小学生\n";
	pupil.showAllData();
	cout << "--------------- 中学生\n";
	middle.showAllData();
	cout << "--------------- 大学生\n";
	college.showAllData();
	cout << "----------------------" << endl;
}

void edit(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {

}

void Delete(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {

}


void count(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {

}

