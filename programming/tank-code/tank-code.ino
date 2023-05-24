#include "Wire.h"
// библиотека для работы со светодиодной матрицей
#include "TroykaLedMatrix.h"
#include <Servo.h>
Servo myservo;
 
// создаём объект matrix для работы с матрицей
TroykaLedMatrix matrix;


namespace pins
{
  const int servo = 3;

}
// массив картнки сердца


#include "ServoMotor.h"
#include "LedMatrix.h"

void setup()
{
  LedMatrix::configure();
  ServoMotor::configure();
}
 

void loop()
{
  ServoMotor::setAngle(95);
}