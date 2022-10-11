#include "QueryContext.h"
#include <Interpreters/Context.h>
#include <Parser/SerializedPlanParser.h>
#include <Common/CurrentMemoryTracker.h>
#include <Common/CurrentThread.h>
#include <Common/ThreadStatus.h>

using namespace DB;

namespace CurrentMemoryTracker
{
extern thread_local std::function<void(Int64)> before_alloc;
extern thread_local std::function<void(Int64)> before_free;
}

namespace local_engine
{

thread_local std::shared_ptr<CurrentThread::QueryScope> query_scope;
thread_local std::shared_ptr<ThreadStatus> thread_status;

DB::ContextPtr initializeQuery()
{
    auto query_context = Context::createCopy(SerializedPlanParser::global_context);
    query_context->makeQueryContext();
    if (!thread_status)
    {
        thread_status = std::make_shared<ThreadStatus>();
    }
    if (!query_scope)
    {
        query_scope = std::make_shared<CurrentThread::QueryScope>(query_context);
    }
    CurrentMemoryTracker::before_alloc = [](Int64 size) -> void { std::cout << "alloc memory: " + std::to_string(size) << std::endl; };
    CurrentMemoryTracker::before_free = [](Int64 size) -> void { std::cout << "free memory: " + std::to_string(size)<< std::endl; };
    return query_context;
}

void shutdownQuery()
{
    query_scope.reset();
    thread_status.reset();
}

}
