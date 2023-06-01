const uint8_t heart[] 
{
  0b00000000,
  0b01100110,
  0b11111111,
  0b11111111,
  0b11111111,
  0b01111110,
  0b00111100,
  0b00011000,
};

class LedMatrix
{
  
  
public:
  static void configure()
  {
    matrix.begin();
    matrix.clear();     
  }

  static void show()
  {
    matrix.drawBitmap(heart);    
  }
};