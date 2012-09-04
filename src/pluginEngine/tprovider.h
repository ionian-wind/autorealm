#ifndef TPROVIDER_H
#define TPROVIDER_H

template <typename Provided, typename Interface, typename Provider>
class TPluginProvider: public Provider
{
public:
	Interface * create(RenderWindow*w) const{ return new Provided(w); }
};

#endif // TPROVIDER_H
