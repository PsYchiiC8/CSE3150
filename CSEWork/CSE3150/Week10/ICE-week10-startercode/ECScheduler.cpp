// implement a task scheduler based on the Singleton pattern

#include <set>

class ECScheduler
{
public:
  static ECScheduler& Instance() {
    static ECScheduler inst;
    
    return inst;

    // if (pInst == NULL) {
    //   pInst = new ECScheduler;
    // }
    // return *pInst;
  }

  void StartTask(int id) {
    tids.insert(id);
  }

  void StopTask(int id) {
    tids.erase(id);
  }

  int GetNumRunTasks() const {
    return tids.size();
  }
  
private:
  ECScheduler() {}

  // static ECScheduler *pInst;
  std::set<int> tids;
};
