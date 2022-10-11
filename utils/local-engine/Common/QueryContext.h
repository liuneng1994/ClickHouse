#pragma once
#include <Interpreters/Context_fwd.h>

namespace local_engine
{
DB::ContextPtr initializeQuery();

void shutdownQuery();
}
