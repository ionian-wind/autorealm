#ifndef TPROVIDER_H
#define TPROVIDER_H

template <typename Provided, typename Interface, typename Provider>
class TProvider: public Provider
{
public:
	Interface * create(RenderWindow*w) const{ return new Provided(w); }
};

#include "tprovider.tpp"

#endif // TPROVIDER_H
