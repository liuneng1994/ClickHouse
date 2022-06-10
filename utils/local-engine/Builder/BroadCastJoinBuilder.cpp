#include "BroadCastJoinBuilder.h"

using namespace DB;

namespace local_engine
{
void BroadCastJoinBuilder::buildJoinIfNotExist(
    const std::string & key,
    std::unique_ptr<ReadBufferFromJavaInputStream> read_buffer,
    const DB::Names & key_names_,
    DB::ASTTableJoin::Kind kind_,
    DB::ASTTableJoin::Strictness strictness_,
    const DB::ColumnsDescription & columns_)
{
    {
        std::lock_guard join_lock(join_lock_mutex);
        if (!storage_join_lock.contains(key))
        {
            storage_join_lock.emplace(key, std::make_shared<std::mutex>());
        }
    }
    if (!storage_join_map.contains(key))
    {
        std::lock_guard build_lock(*storage_join_lock.at(key));
        if (!storage_join_lock.contains(key))
        {
            storage_join_map.emplace(key, std::make_shared<StorageJoinFromReadBuffer>(std::move(read_buffer),
                                                                                     StorageID("default", key),
                                                                                     key_names_,
                                                                                     true,
                                                                                     SizeLimits(),
                                                                                     kind_,
                                                                                     strictness_,
                                                                                     columns_,
                                                                                     ConstraintsDescription(),
                                                                                     key,
                                                                                     true));
        }
    }
}
std::shared_ptr<StorageJoinFromReadBuffer> BroadCastJoinBuilder::getJoin(const std::string & key)
{
    if (storage_join_map.contains(key))
    {
        return storage_join_map.at(key);
    }
    else
    {
        return std::shared_ptr<StorageJoinFromReadBuffer>();
    }
}

}
