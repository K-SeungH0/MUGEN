#pragma once

template <typename T>
class Singleton
{
protected:
	static T* lpInstance;

	Singleton() {};
	~Singleton() {};

public:
	static T* GetLpInstance();
	void ReleaseSingleton();
};

template <typename T>
T* Singleton<T>::lpInstance = nullptr;

template<typename T>
inline T* Singleton<T>::GetLpInstance()
{
	if (lpInstance == nullptr)
	{
		lpInstance = new T;
	}
	return lpInstance;
}

template<typename T>
inline void Singleton<T>::ReleaseSingleton()
{
	if (lpInstance)
	{
		lpInstance->Release();
		delete lpInstance;
		lpInstance = nullptr;
	}
}
