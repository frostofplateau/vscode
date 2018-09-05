#ifdef __cplusplus
class Circle
{
public:
    Circle();
    Circle(double);
    double getArea();
    void setRadius();
    double getRadius();
private:
    double radius;
};
#endif