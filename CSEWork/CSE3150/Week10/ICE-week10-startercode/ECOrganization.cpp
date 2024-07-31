// Code for modeling a university's various units: department, office,
// college, etc
#include <vector>

// Generic interface. 
class ECUnit
{
public:
  virtual ~ECUnit() {}
  
	virtual double GetBudget() const = 0;
};

// Department
class ECDepartment : public ECUnit
{
public:
	ECDepartment(int b) : budget(b) {}
	double GetBudget() const { return budget; }

private:
  int budget;
};

// Office
class ECOffice : public ECUnit
{
public:
  ECOffice(int b) : budget(b) {}
  double GetBudget() const { return budget; }

private:
  int budget;
};

// Composite
class ECCompositeUnit : public ECUnit
{
public:
  ECCompositeUnit()  {}
  ~ECCompositeUnit()
  {
    for (auto x : listu)
      delete x;
  }
  
  double GetBudget() const 
  { 
    int res = 0;
    for (auto x : listu){
      res += x->GetBudget();
    }
    return res;
  }
  void AddChild(ECUnit *pUnit)
  {
    listu.push_back(pUnit);
  }

private:
  // your code here
  std::vector<ECUnit*> listu;
};

