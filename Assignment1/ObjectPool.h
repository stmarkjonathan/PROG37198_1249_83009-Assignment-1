#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

#include "StandardIncludes.h"


#include <vector>

template<class T>
class ObjectPool
{

public:

	ObjectPool() { }
	virtual ~ObjectPool()
	{
		for (unsigned int count = 0; count < m_all.size(); count++)
		{
			cout << "Deleting pool object: " << typeid(T).name() << endl;
			delete m_all[count];
		}

		m_all.clear();
		m_available.clear();

	}

	T* GetResource()
	{
		if (m_available.empty())
		{
			cout << "Creating new pool object: " << typeid(T).name() << endl;
			T* resource = new T();
			m_all.push_back(resource);
			return resource;
		}
		else
		{
			cout << "Reusing existing pool object: " << typeid(T).name() << endl;
			T* resource = m_available[0];
			m_available.erase(m_available.begin());
			return resource;
		}
	}

	void ReleaseResource(T* _object)
	{
		//_object->Reset();
		m_available.push_back(_object);
	}

private:

	std::vector<T*> m_available;
	std::vector<T*> m_all;
};

#endif OBJECTPOOL_H