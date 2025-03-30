typedef enum {
    ERROR = -1,
    ARMSTRONG = 1,
    NOT_ARMSTRONG = 0,
} NumberStatus;

NumberStatus check_armstrong(int number, int* sum);