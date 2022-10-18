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

thread_local std::weak_ptr<CurrentThread::QueryScope> query_scope;
thread_local std::weak_ptr<ThreadStatus> thread_status;
std::unordered_map<int64_t, NativeAllocatorContextPtr> allocator_map;

int64_t initializeQuery(ReservationListenerWrapperPtr listener)
{
    auto query_context = Context::createCopy(SerializedPlanParser::global_context);
    query_context->makeQueryContext();
    auto allocator_context= std::make_shared<NativeAllocatorContext>();
    allocator_context->query_scope = std::make_shared<CurrentThread::QueryScope>(query_context);
    allocator_context->thread_status = std::make_shared<ThreadStatus>();
    allocator_context->query_context = query_context;
    query_scope = std::weak_ptr<CurrentThread::QueryScope>(allocator_context->query_scope);
    thread_status = std::weak_ptr<ThreadStatus>(allocator_context->thread_status);
    auto allocator_id = reinterpret_cast<int64_t>(allocator_context.get());
    allocator_map.emplace(allocator_id, allocator_context);
    CurrentMemoryTracker::before_alloc = [listener](Int64 size) -> void { listener->reserve(size); };
    CurrentMemoryTracker::before_free = [listener](Int64 size) -> void { listener->free(size); };
    return allocator_id;
}

void releaseAllocator(int64_t allocator_id)
{
    allocator_map.erase(allocator_id);
}

const std::unordered_map<int64_t, NativeAllocatorContextPtr> getAllocatorContextMap()
{
    return allocator_map;
}

int64_t allocatorMemoryUsage(int64_t allocator_id)
{
    return getAllocatorContextMap().at(allocator_id)->thread_status->memory_tracker.get();
}

}
