/*!
 * Copyrignt (c) airfox 2012
 *
 * \brief Double dispath demo.
 *  game object definition.
 *
 * \author airfox
 */

#ifndef UCB_RSC_H
#define UCB_RSC_H

class RscOper;
class GameObject
{
public:
    virtual ~GameObject() {}

    virtual int Play(GameObject &other) = 0;

    virtual RscOper *GetOper() = 0;
};

class Rock : public GameObject
{
public:
    ~Rock() {}

    int Play(GameObject &other);

    RscOper *GetOper();
};

class Scissors : public GameObject
{
public:
    ~Scissors() {}

    int Play(GameObject &other);

    RscOper *GetOper();
};

class Cloth : public GameObject
{
public:
    ~Cloth() {}

    int Play(GameObject &other);

    RscOper *GetOper();
};

#endif // UCB_RSC_H
