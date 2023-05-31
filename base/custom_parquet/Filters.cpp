#include "Filters.h"
#include <Functions/IFunction.h>

static const std::unordered_set<String> MIN_MAX_SUPPORTED_FUNCTIONS = {"greater", "less", "greaterOrEquals", "lessOrEquals", "equals", "notEquals"};

DB::ActionsDAGPtr DB::Filter::getMixMaxFilter(std::unordered_set<String> inputs)
{

    for (const auto & node : conditions->getNodes())
    {
        if (node.type == ActionsDAG::ActionType::FUNCTION && MIN_MAX_SUPPORTED_FUNCTIONS.contains(node.function_base->getName()))
        {
            for (const auto & item : node.children)
            {
                if (item->type == ActionsDAG::ActionType::INPUT && inputs.contains(item->result_name))
                {
                    // TODO
                }
            }
        }
    }
    return DB::ActionsDAGPtr();
}
DB::ColumnPtr DB::Filter::execute(DB::Block input)
{
    return DB::ColumnPtr();
}
