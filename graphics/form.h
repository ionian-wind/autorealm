#ifndef FORM_H
#define FORM_H

#include <list>

#include "object.h"
#include "color.h"

class Form : public Object
{
public:
    Form();
    void Draw(void);
    Color getFiller();
    void setFiller(Color val);
    Color getBorder();
    void setBorder(Color val);

    void AddPoint(D3Point pt);
    void Close(bool close=true);
protected:
private:
    std::list<D3Point> m_points;
    Color m_filler;
    Color m_border;
    bool m_closed;
};

#endif // FORM_H
