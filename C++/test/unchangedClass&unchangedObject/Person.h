#ifdef __cplusplus
#include"Date.h"
class Person
{
public:
    Person(int id, int year, int month, int day);
    int getId();
    Date* getBirthDate();
private:
    int id;
    Date* birthDate;
};
#endif