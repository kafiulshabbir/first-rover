class ServoMotor
{
public:
  static void configure()
  {
    myservo.attach(pins::servo);    
  }
  static void setAngle(int angle)
  {
    myservo.write(angle);
  }
};