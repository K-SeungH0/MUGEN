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
			int c = ifs.get();
			switch (c)
			{
			case '[':
				getline(ifs, group);
				group = group.substr(0, group.length() - 1);

				mDataSet.insert(make_pair(group, map<string, vector<string>>()));
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
			default:
				getline(ifs, group);
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