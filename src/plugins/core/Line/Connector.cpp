#include <Pluma/Connector.hpp>
#include "linetool.h"

PLUMA_CONNECTOR
bool connect(pluma::Host& host){
    host.add( new LineToolProvider() );
    return true;
}
