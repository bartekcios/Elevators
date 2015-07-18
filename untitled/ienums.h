#ifndef IENUMS
#define IENUMS
class IEnums
{
public:
    enum FLOOR
    {
        INVALID      = -1,
        GROUND_FLOOR = 0,
        FIRST_FLOOR  = 1,
        SECOND_FLOOR = 2,
        THIRD_FLOOR  = 3,
        FOURTH_FLOOR = 4,
        FIFTH_FLOOR  = 5,
        SIXTH_FLOOR  = 6,
        SEVENTH_FLOOR= 7,
        EIGHTH_FLOOR = 8,
        NINTH_FLOOR  = 9,
        TENTH_FLOOR  = 10,
        MAX_FLOORS   = 11
    };

    enum STATUS
    {
        S_INVALID,
        S_IN_MOVE,
        S_WAITS_FOR_PASSENGERS,
        S_LOADING_UNLOADING_PASSENGERS,
    };

    enum REQUEST_ANSWER
    {
        RA_INVALID,
        RA_ACCEPTED,
        RA_REJECTED,
        RA_IN_PROGRESS
    };

    enum MESSAGE
    {
        M_INVALID,
        M_CHANGE_IMAGE_POSITION,
        M_GET_STATUS,
        M_SET_STATUS,
        M_GET_TIME_TO_FREE
    };
};



#endif // IENUMS

