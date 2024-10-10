#include <iostream>
#include <string>

int main(int arg_count, char *arg_list[]) 
{
  if (arg_count == 3) {
    std::string filename{arg_list[0]};
    auto char1_arg1{*(arg_list[1])}; 
    auto filename_len{filename.size()};
    auto int_number_arg2{std::atoi(arg_list[2])};
    auto var6{0};
    auto var7{0};
    std::string arg1{arg_list[1]};

//var2 = filename
//var3 = stores the first character of arg1=MNXB11, thus it is M
//var4 = length of the filename 
//var5 = arg2=23553, the std::atoi converts 23553 which is currently stored as a string to an integer
//var8 = is again the MNXB11, saved as string??



    while (true) {
      var6 += arg1[var7++];
      if (var7 >= static_cast<int>(arg1.size())) {
        break;
      }
    }
    if ((var6 ^ char1_arg1 * 3) << (filename_len & 0x1f) == int_number_arg2) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}
