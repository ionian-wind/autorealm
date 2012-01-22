#include "form.h"

#include <GL/gl.h>

Form::Form()
:m_closed(false)
{
	//ctor
}

void Form::setBorder(Color val)
{
	m_border = val;
}

Color Form::getBorder()
{
	return m_border;
}

void Form::setFiller(Color val)
{
	m_filler = val;
}

Color Form::getFiller()
{
	return m_filler;
}

void Form::Draw(void)
{
	glColor4d(m_filler.getRed(),m_filler.getGreen(),m_filler.getBlue(),m_filler.getAlpha());
	if(m_closed)
	{
		glBegin(GL_POLYGON);
		{
			for(std::list<D3Point>::iterator it=m_points.begin();it!=m_points.end();++it)
				glVertex3d(it->m_x,it->m_y,it->m_z);
		}
		glEnd();
	}
	glColor4d(m_border.getRed(),m_border.getGreen(),m_border.getBlue(),m_border.getAlpha());
	glBegin(m_closed?GL_LINE_LOOP:GL_LINE_STRIP);
	{
		for(std::list<D3Point>::iterator it=m_points.begin();it!=m_points.end();++it)
			glVertex3d(it->m_x,it->m_y,it->m_z);
	}
	glEnd();

}

void Form::AddPoint(D3Point pt)
{
	m_points.push_back(pt);
}

void Form::Close(bool close)
{
	m_closed=close;
}
