#include "Shape.h"

// define window class
class Window 
{
public:
  // Upper left (x1, y1), lower right (x2, y2)
  Window(int x1, int y1, int x2, int y2){
    shape = new Rectangle(x2-x1, y2-y1);
  }

  Window(int x, int y, int r){
    shape = new Circle(r);
  }

  ~Window(){
    delete shape;
  }

  double GetDisplayArea() const 
  {
    return shape->GetArea();
  }
  
  // other stuff: drawing, etc
  // skipped: no implementation for now

  // your code here

private:
  Shape* shape;
};



