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

template<>
inline int FileManager::GetData<int>(string group, string key)
{
	if (mDataSet.find(group) == mDataSet.end()
		|| mDataSet[group].find(key) == mDataSet[group].end()
		|| mDataSet[group][key].empty())
	{
		return 0;
	}

	return stoi(mDataSet[group][key][0]);
}

template<>
inline float FileManager::GetData<float>(string group, string key)
{
	if (mDataSet.find(group) == mDataSet.end()
		|| mDataSet[group].find(key) == mDataSet[group].end()
		|| mDataSet[group][key].empty())
	{
		return 0;
	}

	return stof(mDataSet[group][key][0]);
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