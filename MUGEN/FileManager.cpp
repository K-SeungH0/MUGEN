#include "Mugen.h"
#include "FileManager.h"

bool FileManager::ReadFile(string path)
{
	mDataSet.clear();

	ifstream ifs;
	string group, line;
	string key;
	string data;
	try
	{
		ifs.open(path, ios_base::in);
		while (!ifs.eof())
		{
			switch (ifs.peek())
			{
			case '[':
				
				getline(ifs, group);
				group = group.substr(1, group.length() - 2);
				if (mDataSet.find(group) == mDataSet.end()) mDataSet.insert(make_pair(group, map<string, vector<string>>()));
				break;
			case '#':
			case '\n':
			case '\0':
				getline(ifs, group);
				break;
			default:
				getline(ifs, line);
				while (line.length() > 0)
				{
					stringstream sStream(line);
					int index = 0;
					while (getline(sStream, data, ' '))
					{
						if (index++ == 0)
						{
							key = data;
							if (mDataSet[group].find(key) == mDataSet[group].end())
								mDataSet[group].insert(make_pair(key, vector<string>()));
						}
						else
						{
							mDataSet[group][key].push_back(data);
						}
					}
					getline(ifs, line);
				}
				break;
			}
		}
		ifs.close();
	}
	catch (exception e)
	{
		try
		{
			ifs.close();
		}
		catch (exception ee) {}
		return false;
	}

    return true;
}