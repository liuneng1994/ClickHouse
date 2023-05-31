#pragma once
#include <Columns/IColumn.h>
#include <Core/Block.h>
#include <Interpreters/ActionsDAG.h>

namespace DB
{
class IFilter
{
public:
    virtual ~IFilter() = default;
    virtual ColumnPtr execute(Block input) = 0;
    virtual Block getArguments() = 0;

protected:
    ActionsDAGPtr conditions;
};

class Filter : public IFilter
{
public:
    ActionsDAGPtr getMixMaxFilter(std::unordered_set<String> inputs);
    ActionsDAGPtr getDictFilter(std::unordered_set<String> inputs);
    ColumnPtr execute(Block input) override;
};

class RowGroupFilter : public IFilter
{
};

class PageFilter : public IFilter
{
};

class PageDictFilter : public PageFilter
{
};

}
