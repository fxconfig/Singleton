#pragma once

#ifndef __PETER_SINGLETON__
#define __PETER_SINGLETON__
#include <mutex>

class SingletonBase {
private:
	static SingletonBase* p_SingletonBase;
	static std::mutex mtx_SingletonBase;

protected:
	SingletonBase() {};
public:
	static SingletonBase* getInstance() {
		if (NULL == p_SingletonBase) {
			std::lock_guard<std::mutex> lock(mtx_SingletonBase);
			if (NULL == p_SingletonBase)
				p_SingletonBase = new SingletonBase();
		}
		return p_SingletonBase;
	}
};
std::mutex SingletonBase::mtx_SingletonBase;
SingletonBase* SingletonBase::p_SingletonBase = NULL;

#endif
