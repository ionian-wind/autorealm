#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T>
/** \brief A singleton template. Classic and so undocumented.
 */
class Singleton
{
    public:
        static T &GetInstance(void)
        {
        	if(!m_Instance)
				m_Instance=new T;
			return static_cast<T&>(*m_Instance);
		}
    protected:
        Singleton() {}
        virtual ~Singleton() {}
    private:
        static T *m_Instance;
};

template <class T>
T *Singleton<T>::m_Instance = 0;

#endif // SINGLETON_H

