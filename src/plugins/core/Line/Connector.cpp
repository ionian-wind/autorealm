#include <Pluma/Connector.hpp>
#include "polylinetool.h"

PLUMA_CONNECTOR
bool connect(pluma::Host& host){
    host.add( new LineToolProvider() );
    return true;
}
