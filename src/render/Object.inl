template <typename KIND>
Object<KIND>::Object(void)
:m_owner(NULL)
{
}

template <typename KIND>
Object<KIND>::Object(Group *owner)
:m_owner(owner)
{
}

template <typename KIND>
void Object<KIND>::move(const Point<> & distance)
{
	for_each(m_children.begin(),
			m_children.end(),
			std::mem_fun(std::bind1st(KIND::move,distance)));
}

template <typename KIND>
void Object<KIND>::rotate(short degree)
{
	for_each(m_children.begin(),
			m_children.end(),
			std::mem_fun(std::bind1st(KIND::rotate,degree)));
}

template <typename KIND>
void Object<KIND>::rotate(float radian)
{
	for_each(m_children.begin(),
			m_children.end(),
			std::mem_fun(std::bind1st(KIND::rotate,radian)));
}

template <typename KIND>
void Object<KIND>::resize(unsigned char widthPercent, unsigned char heightPercent)
{
//	for(typename std::vector<KIND>::iterator it=m_children.begin();it!=m_children.end();++it)
//		it->resize(widthPercent,heightPercent);
//	for_each(m_children.begin(),
//			m_children.end(),
//			std::mem_fun(
//				std::bind1st(
//					std::bind1st(resize,
//									widthPercent),
//								heightPercent))
//			);
}
