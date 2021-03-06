#include <iostream>

class Singleton {
public:
  static Singleton* Instance();
protected:
  Singleton() { calc_ = 0; }
private:
  friend std::ostream& operator<<(std::ostream&, const Singleton&);
  static Singleton* instance_;
  int calc_;
};

Singleton* Singleton::instance_ = 0;

Singleton* Singleton::Instance() {
  if (instance_ == 0) {
    instance_ = new Singleton();
  }
  return instance_;
}

std::ostream& operator<<(std::ostream& os, const Singleton& instance) {
  std::cout << instance.calc_;
  return os;
}

int main() {
  std::cout << *Singleton::Instance();
  return 0;
}
