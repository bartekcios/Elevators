#ifndef CPASSENGER_H
#define CPASSENGER_H

#include "ienums.h"

class CPassenger
{
public:
    enum STATUS
    {
        S_INVALID,
        S_WAITING,
        S_IN_ELEVATOR,
        S_ON_DESTINATION_FLOOR,
    };

    CPassenger(int a_iID);
    ~CPassenger();

    const int m_iID;
    STATUS m_eStatus;
    IEnums::FLOOR m_iFloorFrom;
    IEnums::FLOOR m_iFloorTo;
};

#endif // CPASSENGER_H
