#include <iostream>
using namespace std;

// base class
class ECLife
{
public:
  virtual ~ECLife() {}
  void Die() {}
};

// derived class
class ECCat : public ECLife
{
public:
  void Mew() { cout<< "MEWWWWWW";}
};

// derived class 2
class ECDog : public ECLife
{
public:
  void Bark() { cout << "BARKKKKK\n"; }
};

// test code
int main()
{
  ECLife *pl1 = new ECCat;
  ECLife *pl2 = new ECDog;
  ECLife *pl3 = new ECCat;

  // How to tell what kind of life it is?
  // How to tell if say pl1 and pl2 point to the same kind of life?
  ECDog *pt1 = dynamic_cast<ECDog *>(pl2);
  if( pt1 == NULL )
  {
    cout << "NOT A DOG!\n";
  }

  else
  {
    cout << "DOG\n";
    pt1->Bark(); 
  }

  const type_info &x = typeid( *pl1 );
  cout << "pl1 type: " << x.name() << endl;

  int n = 1;
  double y = 10;
  cout << "type x: " << typeid(n).name() << ", type y:" << typeid(y).name() << endl; 

  delete pl1;
  delete pl2;
  delete pl3; 
}

