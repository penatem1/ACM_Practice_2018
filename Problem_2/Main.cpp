#include <iostream>
#include <vector>

int collatz(int x) {
  return ((x&0b1)==0)?x>>1:3*x+1;
}

int main(int argc, char* argv[]) {
  int a, b, maxTimes = 0, curTimes, t;
  std::vector<int> outputs;

  while(true) {
    std::cin >> a;
    std::cin >> b;
    if (a == 0 && b == 0)
      break;

    for(int i = a; i <=b; i++) {
      t = i;
      curTimes = 0;
      while(t != 1) {
        t = collatz(t);
        curTimes++;
      }

      if(curTimes >= maxTimes) {
        if(curTimes > maxTimes) {
          outputs.clear();
          maxTimes = curTimes;
        }
        outputs.push_back(i);
      }
    }

    unsigned int out_size = outputs.size();
    for(unsigned int i = 0; i < out_size; i++)
      std::cout << outputs[i] << " ";
    std::cout << std::endl;

      maxTimes = 0;
  }

  return 0;
}
