#include <iostream>
#include <string>

//compute the checksum
int checksum(std::string input) {
  int sum = 0;
  for (int i=0; i< static_cast<int>(input.size()); i++) {
    sum += input[i];
  }
  return sum;
}

//compute the key
int calckey(int sum, char char1_arg1, std::size_t filename_len){
  return (sum ^ char1_arg1 * 3) << (filename_len & 0x1f);
}

//How to use the program
void usage(){
  std::cout << "Wrong input, expected 3 arguments." << std::endl;
  std::cout << "How to use: ./<program_name> <arg1> <key>" << std::endl;
}

//Print the checksum and key
void results(int sum, int key, int int_number_arg2) {
  std::cout << "Calculated checksum:" << sum << std::endl;
  std::cout << "Expected Key:" << key << std::endl;
  std::cout << "Your key input:" << int_number_arg2 << std::endl;
}

int main(int arg_count, char *arg_list[]) 
{
  if (arg_count !=3) {
    usage();
    return 1;
  }
  
  if (arg_count == 3) {
    std::string filename{arg_list[0]};
    auto char1_arg1{*(arg_list[1])}; 
    auto filename_len{filename.size()};
    auto int_number_arg2{std::atoi(arg_list[2])};
    std::string arg1{arg_list[1]};
  
  int sum = checksum(arg_list[1]);
  int key = calckey(sum, char1_arg1, filename_len);

  results(sum, key, int_number_arg2);

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

