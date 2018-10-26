#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

bool strCompare(std::string i, std::string j) { return (i.compare(j)==0); }

int main() {
  int x;
  std::vector<std::string> trials, duplicates;

  while(true){
    std::cin >> x;
    if (x == 0)
      break;

    for(int i = 1; i < x; i++) {
      trials.push_back(std::to_string(i)+std::to_string(x-i));
    }

    std::vector<std::string> trials_c(trials);

    std::vector<std::string>::iterator it;
    it = std::unique(trials.begin(), trials.end(), strCompare);
    trials.resize(std::distance(trials.begin(), it));

    std::set_difference(trials_c.begin(), trials_c.end(), trials.begin(), trials.end(), std::inserter(duplicates, duplicates.begin()));

    it = std::unique(duplicates.begin(), duplicates.end(), strCompare);
    duplicates.resize(std::distance(duplicates.begin(), it));

    unsigned int size = duplicates.size();
    if(size == 0) {
      std::cout << "ok" << std::endl;
    } else {
      std::cout << "no ";
      for(unsigned int i = 0; i < size; i++)
        std::cout << duplicates[i] << " ";
      std::cout << std::endl;
    }

    trials.clear();
    trials_c.clear();
    duplicates.clear();
  }

  return 0;
}
