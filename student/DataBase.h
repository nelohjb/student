#pragma once
#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <fstream>
using namespace std;

template<class T>
class DataBase
{
public:
	DataBase(string fileName);
	~DataBase();
	T* query(long ID);
	void insert(T& data);
	bool Delete(long ID);
	void showAllData();
	void saveMap();
private:
	fstream file;
	string fileName;
	long fileLen;			//�ļ�����
	long size;				//��¼��С
	typedef map<long, T> maptype;
	maptype dataMap;		//������ʱ�洢���ڴ��еĵط�
};





template<class T>
DataBase<T>::DataBase(string fileName) {

}

template<class T>
DataBase<T>::~DataBase() {
	saveMap();
}

template<class T>
T* DataBase<T>::query(long ID) {

}

template<class T>
void DataBase<T>::insert(T& data) {

}

template<class T>
bool DataBase<T>::Delete(long ID) {

}

template<class T>
void DataBase<T>::showAllData() {

}

template<class T>
void DataBase<T>::saveMap() {

}




#endif