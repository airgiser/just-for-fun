/*!
 * Copyright (c) airfox 2012
 *
 * \brief Operation definition.
 * \author airfox<airgis@163.com>
 */

#ifndef UCB_RSC_OPER_H
#define UCB_RSC_OPER_H

class Rock;
class Scissors;
class Cloth;
class RscOper
{
public:
    virtual ~RscOper() {}

    virtual int PlayWith(Rock &other) = 0;
    virtual int PlayWith(Scissors &other) = 0;
    virtual int PlayWith(Cloth &other) = 0;
};

class RockOper : public RscOper
{
public:
    ~RockOper() {}

    int PlayWith(Rock &other);
    int PlayWith(Scissors &other);
    int PlayWith(Cloth &other);
};

class ScissorsOper : public RscOper
{
public:
    ~ScissorsOper() {}

    int PlayWith(Rock &other);
    int PlayWith(Scissors &other);
    int PlayWith(Cloth &other);
};

class ClothOper : public RscOper
{
public:
    ~ClothOper() {}

    int PlayWith(Rock &other);
    int PlayWith(Scissors &other);
    int PlayWith(Cloth &other);
};

#endif // UCB_RSC_OPER_H
