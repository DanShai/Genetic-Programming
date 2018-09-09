/**
 * @author dan
 * @version 1.0
 *
 */
#ifndef OPERATIONSDEFINITION_H
#define OPERATIONSDEFINITION_H
#include "Operations.h"

#pragma once

static int O_add(std::vector<int> data)
{
    return data[0] + data[1];
}
static int O_sub(std::vector<int> data)
{
    return data[0] - data[1];
}

static int O_mul(std::vector<int> data)
{
    return data[0] * data[1];
}
static int O_div(std::vector<int> data)
{
    if (data[1] != 0)
        return (data[0] / data[1]);
    else
        return 1000000;
}

static int O_if(std::vector<int> data)
{
    if (data[0] == 0)
        return data[2];
    else
        return data[1];
}
static int O_lt(std::vector<int> data)
{
    if (data[0] < data[1])
        return 1;
    else
        return 0;
}
static int O_gt(std::vector<int> data)
{
    if (data[0] > data[1])
        return 1;
    else
        return 0;
}

static int O_and(std::vector<int> data)
{
    return data[0] & data[1];
}
static int O_or(std::vector<int> data)
{
    return data[0] | data[1];
}

static int O_xor(std::vector<int> data)
{
    return data[0] ^ data[1];
}

class OperationsDefinition
{
    /**
	 * OperationsDefinition class define various arithmetic
	 * and boolean operations used by the Gene class to generate
	 * the solution for the given problem
	 *
	 *
	 */

  public:
    OperationsDefinition();
    virtual ~OperationsDefinition();
    std::vector<Operations *> getBasicOperationsTable();
    std::vector<Operations *> getBooleanOperationsTable();
    std::vector<Operations *> getAllOperationsTable();

  private:
    std::vector<Operations *> basicOpsTable;
    std::vector<Operations *> booleanOpsTable;
    std::vector<Operations *> allOpsTable;
};

#endif /* OPERATIONSDEFINITION_H */
#endif	/* OPERATIONSDEFINITION_H */
