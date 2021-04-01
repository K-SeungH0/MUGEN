// Singleton.h
#pragma once

template <typename T>
class Singleton
{
protected:
	static T* instance;

	Singleton() {};
	~Singleton() {};

public:
	static T* Getsingleton();
	void ReleaseSingleton();
};

template <typename T>
T* Singleton<T>::instance = nullptr;

template<typename T>
inline T* Singleton<T>::Getsingleton()
{
	if (instance == nullptr)
	{
		instance = new T;
	}
	return instance;
}

template<typename T>
inline void Singleton<T>::ReleaseSingleton()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}
