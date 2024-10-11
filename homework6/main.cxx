#include <iostream>
#include <string>

int checksum(std::string input) {
  int sum = 0;
  for (int i=0; i< static_cast<int>(input.size()); i++) {
    sum += input[i];
  }
  return sum;
}

int calckey(int sum, char char1_arg1, std::size_t filename_len){
  return (sum ^ char1_arg1 * 3) << (filename_len & 0x1f);
}

int main(int arg_count, char *arg_list[]) 
{
  if (arg_count == 3) {
    std::string filename{arg_list[0]};
    auto char1_arg1{*(arg_list[1])}; 
    auto filename_len{filename.size()};
    auto int_number_arg2{std::atoi(arg_list[2])};
    std::string arg1{arg_list[1]};

  int sum = checksum(arg_list[1]);
  int key = calckey(sum, char1_arg1, filename_len);

  if (key == int_number_arg2) {
    std::cout << "Correct!" << std::endl;
  } else {
    std::cout << "Wrong!" << std::endl;
  }
  }
}

//var2 = filename
//var3 = stores the first character of arg1=MNXB11, thus it is M
//var4 = length of the filename 
//var5 = arg2=23553, the std::atoi converts 23553 which is currently stored as a string to an integer
//var6 = sum of the ASCII values of MNXB11 (each letter has a ASCII number corresponding to it), renamed to sum
//var7 = index that goes through MNXB11, not needed anymore
//var8 = is again the MNXB11, saved as string

