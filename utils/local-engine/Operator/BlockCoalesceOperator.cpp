#include "BlockCoalesceOperator.h"
namespace local_engine
{
void BlockCoalesceOperator::mergeBlock(DB::Block & block)
{
    block_buffer.add(block);
}
bool BlockCoalesceOperator::isFull()
{
    return block_buffer.size() >= buf_size;
}
DB::Block BlockCoalesceOperator::releaseBlock()
{
    return block_buffer.releaseColumns();
}
}

