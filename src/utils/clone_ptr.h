#include <memory>

template<typename T>
class clone_ptr
{
	std::unique_ptr<T> m_instance;
public:
	clone_ptr(void)throw()=default;
	clone_ptr(T const& other)throw()
	{
		m_instance.reset(other.clone());
	}
	clone_ptr(clone_ptr<T> const& other)
	{
		m_instance.reset(other.m_instance->clone());
	}
	T* operator->(void)
	{
		return m_instance;
	}
	T* operator->(void)const
	{
		return m_instance.get();
	}
	clone_ptr<T>& operator=(clone_ptr<T> const& other)
	{
		m_instance.reset(other.m_instance.get()->clone());
		return *this;
	}
};
