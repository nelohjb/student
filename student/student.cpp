// student.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Student.h"
#include "DataBase.h"
using namespace std;

// 菜单
void add(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);
void query(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);
void display(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);
void edit(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);
void Delete(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);
void count(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);
void addTxt(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college);

void(*menu[])(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college)
	{	add, query, display, edit, Delete, count, addTxt	};






int main()
{
	DataBase<Pupil> pupil("e://Pupil.dat");
	DataBase<Middle> middle("e://Middle.dat");
	DataBase<College> college("e://College.dat");
	int choice;
	do {
		choice = -1;
		cout << "----------------------------------\n";
		cout << "\t[0] 退出系统\n\t[1] 添加\n\t[2] 查询\n\t[3] 显示\n\t[4] 编辑\n\t[5] 删除\n\t[6] 统计\n\t[7] 从文件中添加\n";
		cout << "----------------------------------\n";
		cout << "->请输入： ";
		cin >> choice;
		if (choice >= 1 && choice <= 7) {
			menu[choice - 1](pupil, middle, college);
			system("pause");
		}
		system("cls");
		//输入字符出错后程序可以继续
		cin.clear();
		cin.ignore();
	} while (choice != 0);
    return 0;
}













void add(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {
	int choice;
	long ID = -1;
	char name[10];
	char sex[6];
	int age, Class;
	float CH, MA, EN;
	float GE, HI;
	char address[30], major[16], phoneNumber[20];

	cout << "输入添加的学生类别： [1].小学生  [2].中学生  [3].大学生" << endl;
	cin.clear();
	cin.ignore();
	cin >> choice;
	if (choice == 0) {
		return;
	}
	else if (choice == 1) {
		while (ID != 0) {
			cout << "->请输入学生的学号 (输0终止)： ";
			cin.clear(); 
			cin.ignore();
			cin >> ID;
			if (ID != 0) {
				if (!pupil.query(ID) && !middle.query(ID) && !college.query(ID)) {
					cout << "->请依次输入学生的姓名：";
					cin >> name;
					cout << setw(24) << right << "性别：";
					cin >> sex;
					cout << setw(24) << right << "年龄：";
					cin >> age;
					cout << setw(24) << right << "班级：";
					cin >> Class;
					cout << setw(24) << right << "语文成绩：";
					cin >> CH;
					cout << setw(24) << right << "数学成绩：";
					cin >> MA;
					cout << setw(24) << right << "英语成绩：";
					cin >> EN;

					Pupil newStudent(ID, name, sex, age, Class, CH, MA, EN);
					pupil.insert(newStudent);
					cout << ID << " 添加成功！" << endl;
				}
				else {
					cout << ID << "已存在!" << endl;
				}
			}
		}
	}
	else if (choice == 2) {
		while (ID != 0) {
			cout << "->请输入学生的学号 (输0终止)： ";
			cin.clear();
			cin.ignore();
			cin >> ID;
			if (ID != 0){
				if (!pupil.query(ID) && !middle.query(ID) && !college.query(ID)) {
					cout << "->请依次输入学生的姓名：";
					cin >> name;
					cout << setw(24) << right << "性别：";
					cin >> sex;
					cout << setw(24) << right << "年龄：";
					cin >> age;
					cout << setw(24) << right << "班级：";
					cin >> Class;
					cout << setw(24) << right << "语文成绩：";
					cin >> CH;
					cout << setw(24) << right << "数学成绩：";
					cin >> MA;
					cout << setw(24) << right << "英语成绩：";
					cin >> EN;
					cout << setw(24) << right << "地理成绩：";
					cin >> GE;
					cout << setw(24) << right << "历史成绩：";
					cin >> HI;
					cout << setw(24) << right << "家庭住址：";
					cin >> address;

					Middle newStudent(ID, name, sex, age, Class, CH, MA, EN, GE, HI, address);
					middle.insert(newStudent);
					cout << ID << " 添加成功！" << endl;
				}
				else {
					cout << ID << "已存在!" << endl;
				}
			}
		}
	}
	else if (choice == 3) {
		while (ID != 0) {
			cout << "->请输入学生的学号 (输0终止)： ";
			cin.clear();
			cin.ignore();
			cin >> ID;
			if (ID != 0) {
				if (!pupil.query(ID) && !middle.query(ID) && !college.query(ID)) {
					cout << "->请依次输入学生的姓名：";
					cin >> name;
					cout << setw(24) << right << "性别：";
					cin >> sex;
					cout << setw(24) << right << "年龄：";
					cin >> age;
					cout << setw(24) << right << "班级：";
					cin >> Class;
					cout << setw(24) << right << "专业：";
					cin >> major;
					cout << setw(24) << right << "家庭地址：";
					cin >> address;
					cout << setw(24) << right << "联系方式：";
					cin >> phoneNumber;

					College newStudent(ID, name, sex, age, Class, major, address, phoneNumber);
					college.insert(newStudent);
					cout << ID << " 添加成功！" << endl;
				}
				else {
					cout << ID << "已存在!" << endl;
				}
			}
		}
	}
}

void query(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {
	long ID = -1;
	Student* stu = NULL;

	while (ID) {
		cout << "请输入要查询的学号(输0退出)： ";
		cin.clear();
		cin.ignore();
		cin >> ID;
		if (ID != 0) {
			if (stu = pupil.query(ID))
				stu->showData();
			else if (stu = middle.query(ID))
				stu->showData();
			else if (stu = college.query(ID))
				stu->showData();
			else
				cout << "没有查到！" << endl;
		}
	}
}

void display(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {

	if (!pupil.isEmpty()) {
		Pupil::showTitle();
		pupil.showAllData();
	}
	if (!middle.isEmpty()) {
		Middle::showTitle();
		middle.showAllData();
	}
	if (!college.isEmpty()) {
		College::showTitle();
		college.showAllData();
	}
	cout << "------------------------------------------------------------------" << endl;
}

void edit(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {
	long ID = -1;
	Student* stu;

	while (ID) {
		cout << "请输入要编辑的学号(输0退出)： ";
		cin.clear();
		cin.ignore();
		cin >> ID;
		if (ID != 0) {
			if (stu = pupil.query(ID));
			else if (stu = middle.query(ID));
			else if (stu = college.query(ID));
			else {
				cout << "没有查到！" << endl;
				continue;
			}
			stu->showData();
			cout << "修改学号请直接输入,否则输入0继续修改基本信息：";
			cin >> ID;
			if (ID) {
				if (pupil.query(ID)|| middle.query(ID)|| college.query(ID)) {
					cout << "该学号已存在！" << endl;
				}
				else {
					stu->setID(ID);
					cout << "修改成功！" << endl;
					stu->showData();
				}
			}
			else
				stu->editAll();
		}
	}
}

void Delete(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {
	long ID = -1;
	Student* stu = NULL;

	while (ID) {
		cout << "请输入要删除的学号(输0退出)： ";
		cin.clear();
		cin.ignore();
		cin >> ID;
		if (ID != 0) {
			if (stu=pupil.query(ID)) {
				stu->showData();
				pupil.Delete(ID);
				cout << "删除成功！" << endl;
			}
			else if (stu = middle.query(ID)) {
				stu->showData();
				middle.Delete(ID);
				cout << "删除成功！" << endl;
			}
			else if (stu = college.query(ID)) {
				stu->showData();
				college.Delete(ID);
				cout << "删除成功！" << endl;
			}
			else
				cout << "记录为空！" << endl;
		}
	}
}

void count(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {
	int choice = -1;
	int maleNum, femaleNum;
	int pupilNum = 0, middleNum = 0, collegeNum = 0;
	int *pAge = NULL, *mAge = NULL, *cAge = NULL;


	display(pupil, middle, college);
	cout << "学生总人数：" << pupil.calStuNum() + middle.calStuNum() + college.calStuNum() << endl << endl;


	while (choice) {
		cout << "----------------------------------\n";
		cout << "\t[0] 退出\n\t[1] 按性别统计\n\t[2] 按年龄统计\n";
		cout << "----------------------------------\n";
		cout << "->请输入： ";
		cin.clear();
		cin.ignore();
		cin >> choice;
		if (choice) {
			switch (choice) {
			case 1:
				//男生
				cout << "-----------------------------------------------------  男生  -----" << endl;
				if (pupil.hadGender("男")) {
					Pupil::showTitle();
					pupilNum = pupil.showGender("男");
				}
				if (middle.hadGender("男")) {
					Middle::showTitle();
					middleNum = middle.showGender("男");
				}
				if (college.hadGender("男")) {
					College::showTitle();
					collegeNum = college.showGender("男");
				}
				cout << "----------------------" << endl;
				maleNum = pupilNum + middleNum + collegeNum;
				cout << "男生总数为：" << maleNum << endl;
				cout << "------------------------------------------------------------------" << endl;
				pupilNum = middleNum = collegeNum = 0;
				//女生
				cout << "-----------------------------------------------------  女生  -----" << endl;
				if (pupil.hadGender("女")) {
					Pupil::showTitle();
					pupilNum = pupil.showGender("女");
				}
				if (middle.hadGender("女")) {
					Middle::showTitle();
					middleNum = middle.showGender("女");
				}
				if (college.hadGender("女")) {
					College::showTitle();
					collegeNum = college.showGender("女");
				}
				cout << "----------------------" << endl;
				femaleNum = pupilNum + middleNum + collegeNum;
				cout << "女生总数为：" << femaleNum << endl;
				cout << "------------------------------------------------------------------" << endl;
				break;
			case 2:
				pAge = pupil.showAge();
				mAge = middle.showAge();
				cAge = college.showAge();
				for (int i = 0; i < 30; i++) {
					if (pAge[i] || mAge[i] || cAge[i]) {
						cout << right << setw(4) << i + 1 << "岁：" << setw(4) << pAge[i] + mAge[i] + cAge[i] << "人，其中小学生"
							<< setw(4) << pAge[i] << "人，中学生" << setw(4) << mAge[i] << "人，大学生"
							<< setw(4) << cAge[i] << "人" << endl;
					}
				}
				break;
			}
		}
	}
}

void addTxt(DataBase<Pupil>& pupil, DataBase<Middle>& middle, DataBase<College>& college) {
	string filePath;
	ifstream file;
	int choice = -1;
	long longID = -1;

	char ID[20];
	char name[10];
	char sex[6];
	char age[6];
	char Class[10];
	char CH[10];
	char MA[10];
	char EN[10];

	char GE[10];
	char HI[10];
	char address[40];

	char major[16];
	char phoneNumber[20];

	cout << "输入添加的学生类别： [1].小学生  [2].中学生  [3].大学生" << endl;
	cin.clear(); 
	cin.ignore();
	cin >> choice;
	if (choice == 0) {
		return;
	}
	else {
		cout << "请输入文件的路径（注意文件格式）： ";
		cin >> filePath;
		file.open(filePath);

		if (file.is_open()) {

			if (choice == 1) {
				do {
					file >> ID >> name >> sex >> age >> Class >> CH >> MA >> EN;
					if (longID=atol(ID)) {
						Pupil temp(longID, name, sex, atoi(age), atoi(Class), atof(CH), atof(MA), atof(EN));
						if (!pupil.query(longID) && !middle.query(longID) && !college.query(longID)) {
							pupil.insert(temp);
							temp.showData();
						}
					}
				} while (!file.eof());
			}
			else if (choice == 2) {
				do {
					file >> ID >> name >> sex >> age >> Class >> CH >> MA >> EN >> GE >> HI >> address;
					if (longID = atol(ID)) {
						Middle temp(longID, name, sex, atoi(age), atoi(Class), atof(CH), atof(MA), atof(EN), atof(GE), atof(HI), address);
						if (!pupil.query(longID) && !middle.query(longID) && !college.query(longID)) {
							middle.insert(temp);
							temp.showData();
						}
					}
				} while (!file.eof());
			}
			else if (choice == 3) {
				do {
					file >> ID >> name >> sex >> age >> Class >> CH >> MA >> EN >> major >> address >> phoneNumber;
					if (longID = atol(ID)) {
						College temp(longID, name, sex, atoi(age), atoi(Class), major, address, phoneNumber);
						if (!pupil.query(longID) && !middle.query(longID) && !college.query(longID)) {
							college.insert(temp);
							temp.showData();
						}
					}
				} while (!file.eof());
			}
		}
		else {
			cerr << "无法打开！" << endl;
		}
	}
}

