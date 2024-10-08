#include <iostream>
#include <string>
int main(int arg_count, char *arg_list[]) {
  if (arg_count == 3) {
    std::string var2{arg_list[0]};
    auto var3{*(arg_list[1])};
    auto var4{var2.size()};
    auto var5{std::atoi(arg_list[2])};
    auto var6{0};
    auto var7{0};
    std::string var8{arg_list[1]};
    while (true) {
      var6 += var8[var7++];
      if (var7 >= static_cast<int>(var8.size())) {
        break;
      }
    }
    if ((var6 ^ var3 * 3) << (var4 & 0x1f) == var5) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}
