#pragma once
#include "Singleton.h"
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

class FileManager : public Singleton<FileManager>
{
private:
	map<string, map<string, vector<string>>> mDataSet;

public:
	bool ReadFile(string path);

	template<typename T>
	T GetData(string group, string key);
};

template<typename T>
inline T FileManager::GetData(string group, string key)
{
	if (mDataSet.find(group) == mDataSet.end()
		|| mDataSet[group].find(key) == mDataSet[group].end()
		|| mDataSet[group][key].empty())
	{
		return T();
	}

	if (typeid(T) == typeid(int))
	{
		return (T)stoi(mDataSet[group][key][0]);
	}
	else if (typeid(T) == typeid(float))
	{
		return (T)stof(mDataSet[group][key][0]);
	}

	return T();
}

template<>
inline string FileManager::GetData<string>(string group, string key)
{
	if (mDataSet.find(group) == mDataSet.end()
		|| mDataSet[group].find(key) == mDataSet[group].end()
		|| mDataSet[group][key].empty())
	{
		return "";
	}

	return mDataSet[group][key][0];
}

template<>
inline vector<string> FileManager::GetData<vector<string>>(string group, string key)
{
	if (mDataSet.find(group) == mDataSet.end()
		|| mDataSet[group].find(key) == mDataSet[group].end()
		|| mDataSet[group][key].empty())
	{
		return vector<string>();
	}

	return mDataSet[group][key];
}

template<>
inline vector<int> FileManager::GetData<vector<int>>(string group, string key)
{
	vector<int> data;
	if (mDataSet.find(group) == mDataSet.end()
		|| mDataSet[group].find(key) == mDataSet[group].end()
		|| mDataSet[group][key].empty())
	{
		return data;
	}

	for (string str : mDataSet[group][key])
	{
		data.push_back(stoi(str));
	}

	return data;
}

template<>
inline vector<float> FileManager::GetData<vector<float>>(string group, string key)
{
	vector<float> data;
	if (mDataSet.find(group) == mDataSet.end()
		|| mDataSet[group].find(key) == mDataSet[group].end()
		|| mDataSet[group][key].empty())
	{
		return data;
	}

	for (string str : mDataSet[group][key])
	{
		data.push_back(stof(str));
	}

	return data;
}