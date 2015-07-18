#ifndef CPASSENGER_H
#define CPASSENGER_H


class CPassenger
{
public:
    enum STATUS
    {
        INVALID,
        WAITING,
        IN_ELEVATOR,
        ON_DESTINATION_FLOOR,
    };

    CPassenger(int a_iID);
    ~CPassenger();

    const int m_iID;
    STATUS m_eStatus;
    //FLOOR m_iFloorFrom = INVALID;
    //FLOOR m_iFloorTo = INVALID;
};

#endif // CPASSENGER_H
